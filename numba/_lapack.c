/*
 * This file contains wrappers of BLAS and LAPACK functions
 */
/*
 * BLAS calling helpers.  The helpers can be called without the GIL held.
 * The caller is responsible for checking arguments (especially dimensions).
 */

/* Fast getters caching the value of a function's address after
   the first call to import_cblas_function(). */

#define EMIT_GET_CBLAS_FUNC(name)                                 \
    static void *cblas_ ## name = NULL;                           \
    static void *get_cblas_ ## name(void) {                       \
        if (cblas_ ## name == NULL) {                             \
            PyGILState_STATE st = PyGILState_Ensure();            \
            const char *mod = "scipy.linalg.cython_blas";         \
            cblas_ ## name = import_cython_function(mod, # name); \
            PyGILState_Release(st);                               \
        }                                                         \
        return cblas_ ## name;                                    \
    }

EMIT_GET_CBLAS_FUNC(dgemm)
EMIT_GET_CBLAS_FUNC(sgemm)
EMIT_GET_CBLAS_FUNC(cgemm)
EMIT_GET_CBLAS_FUNC(zgemm)
EMIT_GET_CBLAS_FUNC(dgemv)
EMIT_GET_CBLAS_FUNC(sgemv)
EMIT_GET_CBLAS_FUNC(cgemv)
EMIT_GET_CBLAS_FUNC(zgemv)
EMIT_GET_CBLAS_FUNC(ddot)
EMIT_GET_CBLAS_FUNC(sdot)
EMIT_GET_CBLAS_FUNC(cdotu)
EMIT_GET_CBLAS_FUNC(zdotu)
EMIT_GET_CBLAS_FUNC(cdotc)
EMIT_GET_CBLAS_FUNC(zdotc)
EMIT_GET_CBLAS_FUNC(snrm2)
EMIT_GET_CBLAS_FUNC(dnrm2)
EMIT_GET_CBLAS_FUNC(scnrm2)
EMIT_GET_CBLAS_FUNC(dznrm2)


#undef EMIT_GET_CBLAS_FUNC

/*
 * NOTE: On return value convention.
 * For LAPACK wrapper development the following conventions are followed:
 * Publicly exposed wrapper functions must return:-
 * STATUS_ERROR  : For an unrecoverable error e.g. caught by xerbla, this is so
 *                 a Py_FatalError can be raised.
 * STATUS_SUCCESS: For successful execution
 * +n            : Where n is an integer for a routine specific error
 *                 (typically derived from an `info` argument).
 *
 * The caller is responsible for checking and handling the error status.
 */

/* return STATUS_SUCCESS if everything went ok */
#define STATUS_SUCCESS  (0)

/* return STATUS_ERROR if an unrecoverable error is encountered */
#define STATUS_ERROR  (-1)

/*
 * A union of all the types accepted by BLAS/LAPACK for use in cases where
 * stack based allocation is needed (typically for work space query args length
 * 1).
 */
typedef union all_dtypes_
{
    float  s;
    double d;
    npy_complex64 c;
    npy_complex128 z;
} all_dtypes;

/*
 * A checked PyMem_RawMalloc, ensures that the var is either NULL
 * and an exception is raised, or that the allocation was successful.
 * Returns zero on success for status checking.
 */
static int checked_PyMem_RawMalloc(void** var, size_t bytes)
{
    *var = NULL;
    *var = PyMem_RawMalloc(bytes);
    if (!(*var))
    {
        {
            PyGILState_STATE st = PyGILState_Ensure();

            PyErr_SetString(PyExc_MemoryError,
                            "Insufficient memory for buffer allocation\
                             required by LAPACK.");
            PyGILState_Release(st);
        }
        return 1;
    }
    return 0;
}

/*
 * Checks that the char kind is valid (one of [s,d,c,z]) for use in blas/lapack.
 * Returns zero on success for status checking.
 */
static int check_kind(char kind)
{
    switch (kind)
    {
        case 's':
        case 'd':
        case 'c':
        case 'z':
            break;
        default:
        {
            PyGILState_STATE st = PyGILState_Ensure();
            PyErr_SetString(PyExc_ValueError,
                            "invalid data type (kind) found");
            PyGILState_Release(st);
        }
        return 1;
    }
    return 0;
}

/*
 * Guard macro for ensuring a valid data "kind" is being used.
 * Place at the top of all routines with switches on "kind" that accept
 * one of [s,d,c,z].
 */
#define ENSURE_VALID_KIND(__KIND) \
if (check_kind( __KIND ))         \
{                                 \
    return STATUS_ERROR;          \
}                                 \

/*
 * Checks that the char kind is valid for the real domain (one of [s,d])
 * for use in blas/lapack.
 * Returns zero on success for status checking.
 */
static int check_real_kind(char kind)
{
    switch (kind)
    {
        case 's':
        case 'd':
            break;
        default:
        {
            PyGILState_STATE st = PyGILState_Ensure();
            PyErr_SetString(PyExc_ValueError,
                            "invalid data type (kind) found");
            PyGILState_Release(st);
        }
        return 1;
    }
    return 0;
}

/*
 * Guard macro for ensuring a valid data "kind" is being used for the
 * real domain routines.
 * Place at the top of all routines with switches on "kind" that accept
 * one of [s,d].
 */
#define ENSURE_VALID_REAL_KIND(__KIND) \
if (check_real_kind( __KIND ))         \
{                                      \
    return STATUS_ERROR;               \
}                                      \


/*
 * Checks that the char kind is valid for the complex domain (one of [c,z])
 * for use in blas/lapack.
 * Returns zero on success for status checking.
 */
static int check_complex_kind(char kind)
{
    switch (kind)
    {
        case 'c':
        case 'z':
            break;
        default:
        {
            PyGILState_STATE st = PyGILState_Ensure();
            PyErr_SetString(PyExc_ValueError,
                            "invalid data type (kind) found");
            PyGILState_Release(st);
        }
        return 1;
    }
    return 0;
}

/*
 * Guard macro for ensuring a valid data "kind" is being used for the
 * real domain routines.
 * Place at the top of all routines with switches on "kind" that accept
 * one of [c,z].
 */
#define ENSURE_VALID_COMPLEX_KIND(__KIND) \
if (check_complex_kind( __KIND ))         \
{                                         \
    return STATUS_ERROR;                  \
}                                         \


/*
 * Checks that a function is found (i.e. not null)
 * Returns zero on success for status checking.
 */
static int check_func(void *func)
{
    if (func == NULL)
    {
        PyGILState_STATE st = PyGILState_Ensure();
        PyErr_SetString(PyExc_RuntimeError,
                        "Specified LAPACK function could not be found.");
        PyGILState_Release(st);
        return STATUS_ERROR;
    }
    return STATUS_SUCCESS;
}


/*
 * Guard macro for ensuring a valid function is found.
 */
#define ENSURE_VALID_FUNC(__FUNC)         \
if (check_func(__FUNC))                   \
{                                         \
    return STATUS_ERROR;                  \
}                                         \


/*
 * Define what a Fortran "int" is, some LAPACKs have 64 bit integer support
 * numba presently opts for a 32 bit C int.
 * This definition allows scope for later configuration time magic to adjust
 * the size of int at all the call sites.
 */
/*
 * LAPACK calling helpers.  The helpers can be called without the GIL held.
 * The caller is responsible for checking arguments (especially dimensions).
 */

/* Fast getters caching the value of a function's address after
   the first call to import_clapack_function(). */

#define EMIT_GET_CLAPACK_FUNC(name)                                 \
    static void *clapack_ ## name = NULL;                           \
    static void *get_clapack_ ## name(void) {                       \
        if (clapack_ ## name == NULL) {                             \
            PyGILState_STATE st = PyGILState_Ensure();              \
            const char *mod = "scipy.linalg.cython_lapack";         \
            clapack_ ## name = import_cython_function(mod, # name); \
            PyGILState_Release(st);                                 \
        }                                                           \
        return clapack_ ## name;                                    \
    }

/* Computes an LU factorization of a general M-by-N matrix A
 * using partial pivoting with row interchanges.
 */
EMIT_GET_CLAPACK_FUNC(sgetrf)
EMIT_GET_CLAPACK_FUNC(dgetrf)
EMIT_GET_CLAPACK_FUNC(cgetrf)
EMIT_GET_CLAPACK_FUNC(zgetrf)

/* Computes the inverse of a matrix using the LU factorization
 * computed by xGETRF.
 */
EMIT_GET_CLAPACK_FUNC(sgetri)
EMIT_GET_CLAPACK_FUNC(dgetri)
EMIT_GET_CLAPACK_FUNC(cgetri)
EMIT_GET_CLAPACK_FUNC(zgetri)

/* Compute Cholesky factorizations */
EMIT_GET_CLAPACK_FUNC(spotrf)
EMIT_GET_CLAPACK_FUNC(dpotrf)
EMIT_GET_CLAPACK_FUNC(cpotrf)
EMIT_GET_CLAPACK_FUNC(zpotrf)

/* Computes for an N-by-N real nonsymmetric matrix A, the
 * eigenvalues and, optionally, the left and/or right eigenvectors.
 */
EMIT_GET_CLAPACK_FUNC(sgeev)
EMIT_GET_CLAPACK_FUNC(dgeev)
EMIT_GET_CLAPACK_FUNC(cgeev)
EMIT_GET_CLAPACK_FUNC(zgeev)

/* Computes for an N-by-N Hermitian matrix A, the
 * eigenvalues and, optionally, the left and/or right eigenvectors.
 */
EMIT_GET_CLAPACK_FUNC(ssyevd)
EMIT_GET_CLAPACK_FUNC(dsyevd)
EMIT_GET_CLAPACK_FUNC(cheevd)
EMIT_GET_CLAPACK_FUNC(zheevd)

/* Computes generalised SVD */
EMIT_GET_CLAPACK_FUNC(sgesdd)
EMIT_GET_CLAPACK_FUNC(dgesdd)
EMIT_GET_CLAPACK_FUNC(cgesdd)
EMIT_GET_CLAPACK_FUNC(zgesdd)

/* Computes QR decompositions */
EMIT_GET_CLAPACK_FUNC(sgeqrf)
EMIT_GET_CLAPACK_FUNC(dgeqrf)
EMIT_GET_CLAPACK_FUNC(cgeqrf)
EMIT_GET_CLAPACK_FUNC(zgeqrf)

/* Computes columns of Q from elementary reflectors produced by xgeqrf() (QR).
 */
EMIT_GET_CLAPACK_FUNC(sorgqr)
EMIT_GET_CLAPACK_FUNC(dorgqr)
EMIT_GET_CLAPACK_FUNC(cungqr)
EMIT_GET_CLAPACK_FUNC(zungqr)

/* Computes the minimum norm solution to linear least squares problems */
EMIT_GET_CLAPACK_FUNC(sgelsd)
EMIT_GET_CLAPACK_FUNC(dgelsd)
EMIT_GET_CLAPACK_FUNC(cgelsd)
EMIT_GET_CLAPACK_FUNC(zgelsd)

// Computes the solution to a system of linear equations
EMIT_GET_CLAPACK_FUNC(sgesv)
EMIT_GET_CLAPACK_FUNC(dgesv)
EMIT_GET_CLAPACK_FUNC(cgesv)
EMIT_GET_CLAPACK_FUNC(zgesv)


#undef EMIT_GET_CLAPACK_FUNC
static size_t kind_size(char kind)
{
    size_t data_size = 0;
    switch (kind)
    {
        case 's':
            data_size  = sizeof(float);
            break;
        case 'd':
            data_size  = sizeof(double);
            break;
        case 'c':
            data_size  = sizeof(npy_complex64);
            break;
        case 'z':
            data_size  = sizeof(npy_complex128);
            break;
    }
    return data_size;

}

/*
 * underlying_float_kind()
 * gets the underlying float kind for a given kind.
 *
 * Input:
 * kind - the kind, one of:
 *         (s, d, c, z) = (float, double, complex, double complex).
 *
 * Returns:
 * underlying_float_kind - the underlying float kind, one of:
 *         (s, d) = (float, double).
 *
 * This function essentially provides a map between the char kind
 * of a type and the char kind of the underlying float used in the
 * type. Essentially:
 * ---------------
 * Input -> Output
 * ---------------
 *     s -> s
 *     d -> d
 *     c -> s
 *     z -> d
 * ---------------
 *
 */
static char underlying_float_kind(char kind)
{
    switch(kind)
    {
        case 's':
        case 'c':
            return 's';
        case 'd':
        case 'z':
            return 'd';
        default:
        {
            PyGILState_STATE st = PyGILState_Ensure();
            PyErr_SetString(PyExc_ValueError,
                            "invalid kind in underlying_float_kind()");
            PyGILState_Release(st);
        }
    }
    return -1;
}

#define CATCH_LAPACK_INVALID_ARG(__routine, info)                      \
    do {                                                               \
        if (info < 0) {                                                \
            PyGILState_STATE st = PyGILState_Ensure();                 \
            PyErr_Format(PyExc_RuntimeError,                           \
                 "LAPACK Error: Routine " #__routine ". On input %d\n",\
                  -(int) info);                                        \
            PyGILState_Release(st);                                    \
            return STATUS_ERROR;                                       \
        }                                                              \
    } while(0)


/*
 * The BLAS/LAPACK wrapper functions and their supporting typedefs are
 * defined in _lapack_intwidth.h, included twice below: once producing
 * "_32"-suffixed symbols built around a 32-bit Fortran integer (LP64,
 * scipy's default), once producing "_64"-suffixed symbols built around a
 * 64-bit one (ILP64). See _lapack_intwidth.h for why this is safe to
 * share a single translation unit, and numba/np/linalg.py for how the
 * right suffix is selected at import time based on the installed scipy.
 */
#define NB_CONCAT_(a, b) a ## b
#define NB_CONCAT(a, b) NB_CONCAT_(a, b)

#define NB_LAPACK_FINT npy_int32
#define NB_LAPACK_SUF _32
#include "_lapack_intwidth.h"
#undef NB_LAPACK_FINT
#undef NB_LAPACK_SUF

#define NB_LAPACK_FINT npy_int64
#define NB_LAPACK_SUF _64
#include "_lapack_intwidth.h"
#undef NB_LAPACK_FINT
#undef NB_LAPACK_SUF

#undef NB_CONCAT
#undef NB_CONCAT_
/* undef defines and macros */
#undef STATUS_SUCCESS
#undef STATUS_ERROR
#undef ENSURE_VALID_KIND
#undef ENSURE_VALID_REAL_KIND
#undef ENSURE_VALID_COMPLEX_KIND
#undef ENSURE_VALID_FUNC
#undef F_INT
#undef EMIT_GET_CLAPACK_FUNC
#undef CATCH_LAPACK_INVALID_ARG
