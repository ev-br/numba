/*
 * Integer-width-parameterized BLAS/LAPACK wrappers.
 *
 * This file is not compiled on its own -- it is #include-d twice from
 * _lapack.c: once with NB_LAPACK_FINT/NB_LAPACK_SUF set for a 32-bit
 * ("LP64") Fortran integer, once for a 64-bit ("ILP64") one. Every
 * function/typedef defined in here that needs a stable, addressable name
 * (exported to Python, or referenced across the two instantiations within
 * the same translation unit) is redirected below to a NB_LAPACK_SUF-suffixed
 * name, so the two instantiations don't collide.
 *
 * Which width is actually correct is a property of the *scipy install*,
 * not of this build: scipy.linalg.cython_blas/cython_lapack are compiled
 * for exactly one ABI, LP64 or ILP64, recorded in
 * scipy.__config__.CONFIG['Build Dependencies']['blas']['cython blas
 * ilp64'] (see numba/np/linalg.py:_lapack_is_ilp64()). The raw function
 * pointer fetched from scipy's __pyx_capi__ (in the EMIT_GET_CBLAS_FUNC /
 * EMIT_GET_CLAPACK_FUNC getters, defined once in _lapack.c outside this
 * file and shared between both instantiations) already matches whichever
 * ABI scipy itself was built for; this file only decides how many bytes
 * the *caller* reads/writes through F_INT-typed locals and by-reference
 * arguments when invoking it. numba/np/linalg.py picks, once at import
 * time, which of the two suffixed symbol sets to bind to.
 */

#define F_INT NB_LAPACK_FINT

#define cast_from_X NB_CONCAT(cast_from_X, NB_LAPACK_SUF)
#define cdot_t NB_CONCAT(cdot_t, NB_LAPACK_SUF)
#define cgeev_t NB_CONCAT(cgeev_t, NB_LAPACK_SUF)
#define cgelsd_t NB_CONCAT(cgelsd_t, NB_LAPACK_SUF)
#define cgesdd_t NB_CONCAT(cgesdd_t, NB_LAPACK_SUF)
#define ddot_t NB_CONCAT(ddot_t, NB_LAPACK_SUF)
#define dxnrm2_t NB_CONCAT(dxnrm2_t, NB_LAPACK_SUF)
#define numba_ez_cgeev NB_CONCAT(numba_ez_cgeev, NB_LAPACK_SUF)
#define numba_ez_cgelsd NB_CONCAT(numba_ez_cgelsd, NB_LAPACK_SUF)
#define numba_ez_cgesdd NB_CONCAT(numba_ez_cgesdd, NB_LAPACK_SUF)
#define numba_ez_cheevd NB_CONCAT(numba_ez_cheevd, NB_LAPACK_SUF)
#define numba_ez_gelsd NB_CONCAT(numba_ez_gelsd, NB_LAPACK_SUF)
#define numba_ez_geqrf NB_CONCAT(numba_ez_geqrf, NB_LAPACK_SUF)
#define numba_ez_gesdd NB_CONCAT(numba_ez_gesdd, NB_LAPACK_SUF)
#define numba_ez_rgeev NB_CONCAT(numba_ez_rgeev, NB_LAPACK_SUF)
#define numba_ez_rgelsd NB_CONCAT(numba_ez_rgelsd, NB_LAPACK_SUF)
#define numba_ez_rgesdd NB_CONCAT(numba_ez_rgesdd, NB_LAPACK_SUF)
#define numba_ez_rsyevd NB_CONCAT(numba_ez_rsyevd, NB_LAPACK_SUF)
#define numba_ez_xxgetri NB_CONCAT(numba_ez_xxgetri, NB_LAPACK_SUF)
#define numba_ez_xxgqr NB_CONCAT(numba_ez_xxgqr, NB_LAPACK_SUF)
#define numba_ez_xxxevd NB_CONCAT(numba_ez_xxxevd, NB_LAPACK_SUF)
#define numba_raw_cgeev NB_CONCAT(numba_raw_cgeev, NB_LAPACK_SUF)
#define numba_raw_cgelsd NB_CONCAT(numba_raw_cgelsd, NB_LAPACK_SUF)
#define numba_raw_cgesdd NB_CONCAT(numba_raw_cgesdd, NB_LAPACK_SUF)
#define numba_raw_cheevd NB_CONCAT(numba_raw_cheevd, NB_LAPACK_SUF)
#define numba_raw_rgeev NB_CONCAT(numba_raw_rgeev, NB_LAPACK_SUF)
#define numba_raw_rgelsd NB_CONCAT(numba_raw_rgelsd, NB_LAPACK_SUF)
#define numba_raw_rgesdd NB_CONCAT(numba_raw_rgesdd, NB_LAPACK_SUF)
#define numba_raw_rsyevd NB_CONCAT(numba_raw_rsyevd, NB_LAPACK_SUF)
#define numba_raw_xgeqrf NB_CONCAT(numba_raw_xgeqrf, NB_LAPACK_SUF)
#define numba_raw_xxgetri NB_CONCAT(numba_raw_xxgetri, NB_LAPACK_SUF)
#define numba_raw_xxxgqr NB_CONCAT(numba_raw_xxxgqr, NB_LAPACK_SUF)
#define numba_xgesv NB_CONCAT(numba_xgesv, NB_LAPACK_SUF)
#define numba_xxdot NB_CONCAT(numba_xxdot, NB_LAPACK_SUF)
#define numba_xxgemm NB_CONCAT(numba_xxgemm, NB_LAPACK_SUF)
#define numba_xxgemv NB_CONCAT(numba_xxgemv, NB_LAPACK_SUF)
#define numba_xxgetrf NB_CONCAT(numba_xxgetrf, NB_LAPACK_SUF)
#define numba_xxnrm2 NB_CONCAT(numba_xxnrm2, NB_LAPACK_SUF)
#define numba_xxpotrf NB_CONCAT(numba_xxpotrf, NB_LAPACK_SUF)
#define rgeev_t NB_CONCAT(rgeev_t, NB_LAPACK_SUF)
#define rgelsd_t NB_CONCAT(rgelsd_t, NB_LAPACK_SUF)
#define rgesdd_t NB_CONCAT(rgesdd_t, NB_LAPACK_SUF)
#define sdot_t NB_CONCAT(sdot_t, NB_LAPACK_SUF)
#define sxnrm2_t NB_CONCAT(sxnrm2_t, NB_LAPACK_SUF)
#define xgeqrf_t NB_CONCAT(xgeqrf_t, NB_LAPACK_SUF)
#define xgesv_t NB_CONCAT(xgesv_t, NB_LAPACK_SUF)
#define xheevd_t NB_CONCAT(xheevd_t, NB_LAPACK_SUF)
#define xsyevd_t NB_CONCAT(xsyevd_t, NB_LAPACK_SUF)
#define xxgemm_t NB_CONCAT(xxgemm_t, NB_LAPACK_SUF)
#define xxgemv_t NB_CONCAT(xxgemv_t, NB_LAPACK_SUF)
#define xxgetrf_t NB_CONCAT(xxgetrf_t, NB_LAPACK_SUF)
#define xxgetri_t NB_CONCAT(xxgetri_t, NB_LAPACK_SUF)
#define xxpotrf_t NB_CONCAT(xxpotrf_t, NB_LAPACK_SUF)
#define xxxgqr_t NB_CONCAT(xxxgqr_t, NB_LAPACK_SUF)
#define zdot_t NB_CONCAT(zdot_t, NB_LAPACK_SUF)



typedef float (*sdot_t)(F_INT *n, void *dx, F_INT *incx, void *dy, F_INT *incy);
typedef double (*ddot_t)(F_INT *n, void *dx, F_INT *incx, void *dy, F_INT
                         *incy);
typedef npy_complex64 (*cdot_t)(F_INT *n, void *dx, F_INT *incx, void *dy,
                                F_INT *incy);
typedef npy_complex128 (*zdot_t)(F_INT *n, void *dx, F_INT *incx, void *dy,
                                 F_INT *incy);

typedef void (*xxgemv_t)(char *trans, F_INT *m, F_INT *n,
                         void *alpha, void *a, F_INT *lda,
                         void *x, F_INT *incx, void *beta,
                         void *y, F_INT *incy);

typedef void (*xxgemm_t)(char *transa, char *transb,
                         F_INT *m, F_INT *n, F_INT *k,
                         void *alpha, void *a, F_INT *lda,
                         void *b, F_INT *ldb, void *beta,
                         void *c, F_INT *ldc);

typedef float (*sxnrm2_t) (F_INT *n, void *x, F_INT *incx);
typedef double (*dxnrm2_t) (F_INT *n, void *x, F_INT *incx);

/* Vector * vector: result = dx * dy */
NUMBA_EXPORT_FUNC(int)
numba_xxdot(char kind, char conjugate, Py_ssize_t n, void *dx, void *dy,
            void *result)
{
    void *raw_func = NULL;
    F_INT _n;
    F_INT inc = 1;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_cblas_sdot();
            break;
        case 'd':
            raw_func = get_cblas_ddot();
            break;
        case 'c':
            raw_func = conjugate ? get_cblas_cdotc() : get_cblas_cdotu();
            break;
        case 'z':
            raw_func = conjugate ? get_cblas_zdotc() : get_cblas_zdotu();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;

    switch (kind)
    {
        case 's':
            *(float *) result = (*(sdot_t) raw_func)(&_n, dx, &inc, dy, &inc);;
            break;
        case 'd':
            *(double *) result = (*(ddot_t) raw_func)(&_n, dx, &inc, dy, &inc);;
            break;
        case 'c':
            *(npy_complex64 *) result = (*(cdot_t) raw_func)(&_n, dx, &inc, dy,\
                                        &inc);;
            break;
        case 'z':
            *(npy_complex128 *) result = (*(zdot_t) raw_func)(&_n, dx, &inc,\
                                         dy, &inc);;
            break;
    }

    return 0;
}

/* Matrix * vector: y = alpha * a * x + beta * y */
NUMBA_EXPORT_FUNC(int)
numba_xxgemv(char kind, char trans, Py_ssize_t m, Py_ssize_t n,
             void *alpha, void *a, Py_ssize_t lda,
             void *x, void *beta, void *y)
{
    void *raw_func = NULL;
    F_INT _m, _n;
    F_INT _lda;
    F_INT inc = 1;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_cblas_sgemv();
            break;
        case 'd':
            raw_func = get_cblas_dgemv();
            break;
        case 'c':
            raw_func = get_cblas_cgemv();
            break;
        case 'z':
            raw_func = get_cblas_zgemv();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _lda = (F_INT) lda;

    (*(xxgemv_t) raw_func)(&trans, &_m, &_n, alpha, a, &_lda,
                           x, &inc, beta, y, &inc);
    return 0;
}

/* Matrix * matrix: c = alpha * a * b + beta * c */
NUMBA_EXPORT_FUNC(int)
numba_xxgemm(char kind, char transa, char transb,
             Py_ssize_t m, Py_ssize_t n, Py_ssize_t k,
             void *alpha, void *a, Py_ssize_t lda,
             void *b, Py_ssize_t ldb, void *beta,
             void *c, Py_ssize_t ldc)
{
    void *raw_func = NULL;
    F_INT _m, _n, _k;
    F_INT _lda, _ldb, _ldc;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_cblas_sgemm();
            break;
        case 'd':
            raw_func = get_cblas_dgemm();
            break;
        case 'c':
            raw_func = get_cblas_cgemm();
            break;
        case 'z':
            raw_func = get_cblas_zgemm();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _k = (F_INT) k;
    _lda = (F_INT) lda;
    _ldb = (F_INT) ldb;
    _ldc = (F_INT) ldc;

    (*(xxgemm_t) raw_func)(&transa, &transb, &_m, &_n, &_k, alpha, a, &_lda,
                           b, &_ldb, beta, c, &_ldc);
    return 0;
}


/* L2-norms */
NUMBA_EXPORT_FUNC(F_INT)
numba_xxnrm2(char kind, Py_ssize_t n, void * x, Py_ssize_t incx, void * result)
{
    void *raw_func = NULL;
    F_INT _incx;
    F_INT _n;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_cblas_snrm2();
            break;
        case 'd':
            raw_func = get_cblas_dnrm2();
            break;
        case 'c':
            raw_func = get_cblas_scnrm2();
            break;
        case 'z':
            raw_func = get_cblas_dznrm2();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;
    _incx = (F_INT) incx;

    switch (kind)
    {
        case 's':
            *(float *) result = (*(sxnrm2_t) raw_func)(&_n, x, &_incx);;
            break;
        case 'd':
            *(double *) result = (*(dxnrm2_t) raw_func)(&_n, x, &_incx);;
            break;
        case 'c':
            *(float *) result = (*(sxnrm2_t) raw_func)(&_n, x, &_incx);;
            break;
        case 'z':
            *(double *) result = (*(dxnrm2_t) raw_func)(&_n, x, &_incx);;
            break;
    }

    return 0;
}



typedef void (*xxgetrf_t)(F_INT *m, F_INT *n, void *a, F_INT *lda, F_INT *ipiv,
                          F_INT *info);

typedef void (*xxgetri_t)(F_INT *n, void *a, F_INT *lda, F_INT *ipiv, void
                          *work, F_INT *lwork, F_INT *info);

typedef void (*xxpotrf_t)(char *uplo, F_INT *n, void *a, F_INT *lda, F_INT
                          *info);

typedef void (*rgeev_t)(char *jobvl, char *jobvr, F_INT *n, void *a, F_INT *lda,
                        void *wr, void *wi, void *vl, F_INT *ldvl, void *vr,
                        F_INT *ldvr, void *work, F_INT *lwork, F_INT *info);

typedef void (*cgeev_t)(char *jobvl, char *jobvr, F_INT *n, void *a, F_INT
                        *lda, void *w, void *vl, F_INT *ldvl, void *vr,
                        F_INT *ldvr, void *work, F_INT *lwork, void *rwork,
                        F_INT *info);

typedef void (*rgesdd_t)(char *jobz, F_INT *m, F_INT *n, void *a, F_INT *lda,
                         void *s, void *u, F_INT *ldu, void *vt, F_INT *ldvt,
                         void *work, F_INT *lwork, F_INT *iwork, F_INT *info);

typedef void (*cgesdd_t)(char *jobz, F_INT *m, F_INT *n, void *a, F_INT *lda,
                         void *s, void * u, F_INT *ldu, void * vt, F_INT *ldvt,
                         void *work, F_INT *lwork, void *rwork, F_INT *iwork,
                         F_INT *info);

typedef void (*xsyevd_t)(char *jobz, char *uplo, F_INT *n, void *a, F_INT *lda,
                         void *w, void *work, F_INT *lwork, F_INT *iwork,
                         F_INT *liwork, F_INT *info);

typedef void (*xheevd_t)(char *jobz, char *uplo, F_INT *n, void *a, F_INT *lda,
                         void *w, void *work, F_INT *lwork, void *rwork,
                         F_INT *lrwork, F_INT *iwork, F_INT *liwork,
                         F_INT *info);

typedef void (*xgeqrf_t)(F_INT *m, F_INT *n, void *a, F_INT *lda, void *tau,
                         void *work, F_INT *lwork, F_INT *info);

typedef void (*xxxgqr_t)(F_INT *m, F_INT *n, F_INT *k, void *a, F_INT *lda,
                         void *tau, void *work, F_INT *lwork, F_INT *info);

typedef void (*rgelsd_t)(F_INT *m, F_INT *n, F_INT *nrhs, void *a, F_INT *lda,
                         void *b, F_INT *ldb, void *s, void *rcond, F_INT *rank,
                         void *work, F_INT *lwork, F_INT *iwork, F_INT *info);

typedef void (*cgelsd_t)(F_INT *m, F_INT *n, F_INT *nrhs, void *a, F_INT *lda,
                         void *b, F_INT *ldb, void *s, void *rcond, F_INT *rank,
                         void *work, F_INT *lwork, void *rwork, F_INT *iwork,
                         F_INT *info);

typedef void (*xgesv_t)(F_INT *n, F_INT *nrhs, void *a, F_INT *lda, F_INT *ipiv,
                        void *b, F_INT *ldb, F_INT *info);



/*
 * kind_size()
 * gets the data size appropriate for a specified kind.
 *
 * Input:
 * kind - the kind, one of:
 *         (s, d, c, z) = (float, double, complex, double complex).
 *
 * Returns:
 * data_size - the appropriate data size.
 *
 */
/*
 * cast_from_X()
 * cast from a kind (s, d, c, z) = (float, double, complex, double complex)
 * to a Fortran integer.
 *
 * Parameters:
 * kind the kind of val
 * val  a pointer to the value to cast
 *
 * Returns:
 * A Fortran int from a cast of val (in complex case, takes the real part).
 *
 * Struct access via non c99 (python only) cmplx types, used for compatibility.
 */
static F_INT
cast_from_X(char kind, void *val)
{
    switch(kind)
    {
        case 's':
            return (F_INT)(*((float *) val));
        case 'd':
            return (F_INT)(*((double *) val));
        case 'c':
            return (F_INT)crealf(*((_complex_float_t *)val));
        case 'z':
            return (F_INT)creal(*((_complex_double_t *)val));
        default:
        {
            PyGILState_STATE st = PyGILState_Ensure();
            PyErr_SetString(PyExc_ValueError,
                            "invalid kind in cast");
            PyGILState_Release(st);
        }
    }
    return -1;
}


/* Compute LU decomposition of A
 * NOTE: ipiv is an array of Fortran integers allocated by the caller,
 * which is therefore expected to use the right dtype.
 */
NUMBA_EXPORT_FUNC(int)
numba_xxgetrf(char kind, Py_ssize_t m, Py_ssize_t n, void *a, Py_ssize_t lda,
              F_INT *ipiv)
{
    void *raw_func = NULL;
    F_INT _m, _n, _lda, info;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgetrf();
            break;
        case 'd':
            raw_func = get_clapack_dgetrf();
            break;
        case 'c':
            raw_func = get_clapack_cgetrf();
            break;
        case 'z':
            raw_func = get_clapack_zgetrf();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _lda = (F_INT) lda;

    (*(xxgetrf_t) raw_func)(&_m, &_n, a, &_lda, ipiv, &info);
    CATCH_LAPACK_INVALID_ARG("xxgetrf", info);

    return (int)info;
}

/* Compute the inverse of a matrix given its LU decomposition
 * Args are as per LAPACK.
 */
static int
numba_raw_xxgetri(char kind, F_INT n, void *a, F_INT lda,
                  F_INT *ipiv, void *work, F_INT *lwork, F_INT *info)
{
    void *raw_func = NULL;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgetri();
            break;
        case 'd':
            raw_func = get_clapack_dgetri();
            break;
        case 'c':
            raw_func = get_clapack_cgetri();
            break;
        case 'z':
            raw_func = get_clapack_zgetri();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    (*(xxgetri_t) raw_func)(&n, a, &lda, ipiv, work, lwork, info);

    return 0;
}

/* Compute the inverse of a matrix from the factorization provided by
 * xxgetrf. (see numba_xxgetrf() about ipiv)
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_xxgetri(char kind, Py_ssize_t n, void *a, Py_ssize_t lda,
                 F_INT *ipiv)
{
    F_INT _n, _lda;
    F_INT lwork = -1;
    F_INT info = 0;
    size_t base_size = -1;
    void * work = NULL;
    all_dtypes stack_slot;

    ENSURE_VALID_KIND(kind)

    _n = (F_INT)n;
    _lda = (F_INT)lda;

    base_size = kind_size(kind);

    work = &stack_slot;

    numba_raw_xxgetri(kind, _n, a, _lda, ipiv, work, &lwork, &info);
    CATCH_LAPACK_INVALID_ARG("xxgetri", info);

    lwork = cast_from_X(kind, work);

    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
    {
        return STATUS_ERROR;
    }

    numba_raw_xxgetri(kind, _n, a, _lda, ipiv, work, &lwork, &info);
    PyMem_RawFree(work);
    CATCH_LAPACK_INVALID_ARG("xxgetri", info);

    return (int)info;
}

/* Compute the Cholesky factorization of a matrix. */
NUMBA_EXPORT_FUNC(int)
numba_xxpotrf(char kind, char uplo, Py_ssize_t n, void *a, Py_ssize_t lda)
{
    void *raw_func = NULL;
    F_INT _n, _lda, info;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_spotrf();
            break;
        case 'd':
            raw_func = get_clapack_dpotrf();
            break;
        case 'c':
            raw_func = get_clapack_cpotrf();
            break;
        case 'z':
            raw_func = get_clapack_zpotrf();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;
    _lda = (F_INT) lda;

    (*(xxpotrf_t) raw_func)(&uplo, &_n, a, &_lda, &info);
    CATCH_LAPACK_INVALID_ARG("xxpotrf", info);
    return (int)info;
}


/* real space eigen systems info from dgeev/sgeev */
static int
numba_raw_rgeev(char kind, char jobvl, char jobvr,
                Py_ssize_t n, void *a, Py_ssize_t lda, void *wr, void *wi,
                void *vl, Py_ssize_t ldvl, void *vr, Py_ssize_t ldvr,
                void *work, Py_ssize_t lwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _n, _lda, _ldvl, _ldvr, _lwork;

    ENSURE_VALID_REAL_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgeev();
            break;
        case 'd':
            raw_func = get_clapack_dgeev();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _ldvl = (F_INT) ldvl;
    _ldvr = (F_INT) ldvr;
    _lwork = (F_INT) lwork;

    (*(rgeev_t) raw_func)(&jobvl, &jobvr, &_n, a, &_lda, wr, wi, vl, &_ldvl, vr,
                          &_ldvr, work, &_lwork, info);
    return 0;
}

/* Real space eigen systems info from dgeev/sgeev
 * as numba_raw_rgeev but the allocation and error handling is done for the user.
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_rgeev(char kind, char jobvl, char jobvr, Py_ssize_t n, void *a,
               Py_ssize_t lda, void *wr, void *wi, void *vl, Py_ssize_t ldvl,
               void *vr, Py_ssize_t ldvr)
{
    F_INT info = 0;
    F_INT lwork = -1;
    F_INT _n, _lda, _ldvl, _ldvr;
    size_t base_size = -1;
    void * work = NULL;
    all_dtypes stack_slot;

    ENSURE_VALID_REAL_KIND(kind)

    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _ldvl = (F_INT) ldvl;
    _ldvr = (F_INT) ldvr;

    base_size = kind_size(kind);

    work = &stack_slot;
    numba_raw_rgeev(kind, jobvl, jobvr, _n, a, _lda, wr, wi, vl, _ldvl,
                    vr, _ldvr, work, lwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_rgeev", info);

    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
    {
        return STATUS_ERROR;
    }
    numba_raw_rgeev(kind, jobvl, jobvr, _n, a, _lda, wr, wi, vl, _ldvl,
                    vr, _ldvr, work, lwork, &info);
    PyMem_RawFree(work);

    CATCH_LAPACK_INVALID_ARG("numba_raw_rgeev", info);

    return (int)info;
}

/* Complex space eigen systems info from cgeev/zgeev
 * Args are as per LAPACK.
 */
static int
numba_raw_cgeev(char kind, char jobvl, char jobvr,
                Py_ssize_t n, void *a, Py_ssize_t lda, void *w, void *vl,
                Py_ssize_t ldvl, void *vr, Py_ssize_t ldvr, void *work,
                Py_ssize_t lwork, void *rwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _n, _lda, _ldvl, _ldvr, _lwork;

    ENSURE_VALID_COMPLEX_KIND(kind)

    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _ldvl = (F_INT) ldvl;
    _ldvr = (F_INT) ldvr;
    _lwork = (F_INT) lwork;

    switch (kind)
    {
        case 'c':
            raw_func = get_clapack_cgeev();
            break;
        case 'z':
            raw_func = get_clapack_zgeev();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    (*(cgeev_t) raw_func)(&jobvl, &jobvr, &_n, a, &_lda, w, vl, &_ldvl, vr,
                          &_ldvr, work, &_lwork, rwork, info);
    return 0;
}


/* Complex space eigen systems info from cgeev/zgeev
 * as numba_raw_cgeev but the allocation and error handling is done for the user.
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_cgeev(char kind, char jobvl, char jobvr,  Py_ssize_t n, void *a,
               Py_ssize_t lda, void *w, void *vl, Py_ssize_t ldvl, void *vr,
               Py_ssize_t ldvr)
{
    F_INT info = 0;
    F_INT lwork = -1;
    F_INT _n, _lda, _ldvl, _ldvr;
    size_t base_size = -1;
    all_dtypes stack_slot, wk;
    void * work = NULL;
    void * rwork = (void *)&wk;

    ENSURE_VALID_COMPLEX_KIND(kind)

    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _ldvl = (F_INT) ldvl;
    _ldvr = (F_INT) ldvr;

    base_size = kind_size(kind);

    work = &stack_slot;
    numba_raw_cgeev(kind, jobvl, jobvr, n, a, lda, w, vl, ldvl,
                    vr, ldvr, work, lwork, rwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cgeev", info);

    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc((void**)&rwork, 2*n*base_size))
    {
        return STATUS_ERROR;
    }
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
    {
        PyMem_RawFree(rwork);
        return STATUS_ERROR;
    }
    numba_raw_cgeev(kind, jobvl, jobvr, _n, a, _lda, w, vl, _ldvl,
                    vr, _ldvr, work, lwork, rwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(rwork);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cgeev", info);

    return (int)info;
}

/* real space symmetric eigen systems info from ssyevd/dsyevd */
static int
numba_raw_rsyevd(char kind, char jobz, char uplo, Py_ssize_t n, void *a,
                 Py_ssize_t lda, void *w, void *work, Py_ssize_t lwork,
                 F_INT *iwork, Py_ssize_t liwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _n, _lda, _lwork, _liwork;

    ENSURE_VALID_REAL_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_ssyevd();
            break;
        case 'd':
            raw_func = get_clapack_dsyevd();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _lwork = (F_INT) lwork;
    _liwork = (F_INT) liwork;

    (*(xsyevd_t) raw_func)(&jobz, &uplo, &_n, a, &_lda, w, work, &_lwork, iwork, &_liwork, info);
    return 0;
}

/* Real space eigen systems info from dsyevd/ssyevd
 * as numba_raw_rsyevd but the allocation and error handling is done for the user.
 * Args are as per LAPACK.
 */
static int
numba_ez_rsyevd(char kind, char jobz, char uplo, Py_ssize_t n, void *a, Py_ssize_t lda, void *w)
{
    F_INT info = 0;
    F_INT lwork = -1, liwork=-1;
    F_INT _n, _lda;
    size_t base_size = -1;
    void *work = NULL;
    F_INT *iwork = NULL;
    all_dtypes stack_slot;
    F_INT stack_int = -1;

    ENSURE_VALID_REAL_KIND(kind)

    _n = (F_INT) n;
    _lda = (F_INT) lda;

    base_size = kind_size(kind);

    work = &stack_slot;
    iwork = &stack_int;
    numba_raw_rsyevd(kind, jobz, uplo, _n, a, _lda, w, work, lwork, iwork, liwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_rsyevd", info);

    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
    {
        return STATUS_ERROR;
    }
    liwork = *iwork;
    if (checked_PyMem_RawMalloc((void**)&iwork, base_size * liwork))
    {
        PyMem_RawFree(work);
        return STATUS_ERROR;
    }
    numba_raw_rsyevd(kind, jobz, uplo, _n, a, _lda, w, work, lwork, iwork, liwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(iwork);

    CATCH_LAPACK_INVALID_ARG("numba_raw_rsyevd", info);

    return (int)info;
}


/* complex space symmetric eigen systems info from cheevd/zheevd*/
static int
numba_raw_cheevd(char kind, char jobz, char uplo, Py_ssize_t n, void *a,
                 Py_ssize_t lda, void *w, void *work, Py_ssize_t lwork,
                 void *rwork, Py_ssize_t lrwork, F_INT *iwork,
                 Py_ssize_t liwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _n, _lda, _lwork, _lrwork, _liwork;

    ENSURE_VALID_COMPLEX_KIND(kind)

    switch (kind)
    {
        case 'c':
            raw_func = get_clapack_cheevd();
            break;
        case 'z':
            raw_func = get_clapack_zheevd();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _lwork = (F_INT) lwork;
    _lrwork = (F_INT) lrwork;
    _liwork = (F_INT) liwork;

    (*(xheevd_t) raw_func)(&jobz, &uplo, &_n, a, &_lda, w, work, &_lwork, rwork, &_lrwork, iwork, &_liwork, info);
    return 0;
}

/* complex space eigen systems info from cheevd/zheevd
 * as numba_raw_cheevd but the allocation and error handling is done for the user.
 * Args are as per LAPACK.
 */
static int
numba_ez_cheevd(char kind, char jobz, char uplo, Py_ssize_t n, void *a, Py_ssize_t lda, void *w)
{
    F_INT info = 0;
    F_INT lwork = -1, lrwork = -1, liwork=-1;
    F_INT _n, _lda;
    size_t base_size = -1, underlying_float_size = -1;
    void *work = NULL, *rwork = NULL;
    F_INT *iwork = NULL;
    all_dtypes stack_slot1, stack_slot2;
    char uf_kind;
    F_INT stack_int = -1;

    ENSURE_VALID_COMPLEX_KIND(kind)

    _n = (F_INT) n;
    _lda = (F_INT) lda;

    base_size = kind_size(kind);
    uf_kind = underlying_float_kind(kind);
    underlying_float_size = kind_size(uf_kind);

    work = &stack_slot1;
    rwork = &stack_slot2;
    iwork = &stack_int;
    numba_raw_cheevd(kind, jobz, uplo, _n, a, _lda, w, work, lwork, rwork, lrwork, iwork, liwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cheevd", info);

    lwork = cast_from_X(uf_kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
    {
        return STATUS_ERROR;
    }

    lrwork = cast_from_X(uf_kind, rwork);
    if (checked_PyMem_RawMalloc(&rwork, underlying_float_size * lrwork))
    {
        PyMem_RawFree(work);
        return STATUS_ERROR;
    }

    liwork = *iwork;
    if (checked_PyMem_RawMalloc((void**)&iwork, base_size * liwork))
    {
        PyMem_RawFree(work);
        PyMem_RawFree(rwork);
        return STATUS_ERROR;
    }
    numba_raw_cheevd(kind, jobz, uplo, _n, a, _lda, w, work, lwork, rwork, lrwork, iwork, liwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(rwork);
    PyMem_RawFree(iwork);

    CATCH_LAPACK_INVALID_ARG("numba_raw_cheevd", info);

    return (int)info;
}

/* Hermitian eigenvalue systems info from *syevd and *heevd.
 * This routine hides the type and general complexity involved with making the
 * calls. The work space computation and error handling etc is hidden.
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_xxxevd(char kind, char jobz, char uplo, Py_ssize_t n, void *a, Py_ssize_t lda, void *w)
{
    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
        case 'd':
            return numba_ez_rsyevd(kind, jobz, uplo, n, a, lda, w);
        case 'c':
        case 'z':
            return numba_ez_cheevd(kind, jobz, uplo, n, a, lda, w);
    }
    return STATUS_ERROR; /* unreachable */
}

/* Real space svd systems info from dgesdd/sgesdd
 * Args are as per LAPACK.
 */
static int
numba_raw_rgesdd(char kind, char jobz, Py_ssize_t m, Py_ssize_t n, void *a,
                 Py_ssize_t lda, void *s, void *u, Py_ssize_t ldu, void *vt,
                 Py_ssize_t ldvt, void *work, Py_ssize_t lwork,
                 F_INT *iwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _m, _n, _lda, _ldu, _ldvt, _lwork;

    ENSURE_VALID_REAL_KIND(kind)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _ldu = (F_INT) ldu;
    _ldvt = (F_INT) ldvt;
    _lwork = (F_INT) lwork;

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgesdd();
            break;
        case 'd':
            raw_func = get_clapack_dgesdd();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    (*(rgesdd_t) raw_func)(&jobz, &_m, &_n, a, &_lda, s, u, &_ldu, vt, &_ldvt,
                           work, &_lwork, iwork, info);
    return 0;
}

/* Real space svd info from dgesdd/sgesdd.
 * As numba_raw_rgesdd but the allocation and error handling is done for the
 * user.
 * Args are as per LAPACK.
 */
static int
numba_ez_rgesdd(char kind, char jobz, Py_ssize_t m, Py_ssize_t n, void *a,
                Py_ssize_t lda, void *s, void *u, Py_ssize_t ldu, void *vt,
                Py_ssize_t ldvt)
{
    F_INT info = 0;
    Py_ssize_t minmn = -1;
    Py_ssize_t lwork = -1;
    all_dtypes stack_slot, wk;
    size_t base_size = -1;
    F_INT *iwork = (F_INT *)&wk;
    void *work = NULL;

    ENSURE_VALID_REAL_KIND(kind)

    base_size = kind_size(kind);

    work = &stack_slot;

    /* Compute optimal work size (lwork) */
    numba_raw_rgesdd(kind, jobz, m, n, a, lda, s, u, ldu, vt, ldvt, work,
                     lwork, iwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_rgesdd", info);

    /* Allocate work array */
    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
        return -1;
    minmn = m > n ? n : m;
    if (checked_PyMem_RawMalloc((void**) &iwork, 8 * minmn * sizeof(F_INT)))
    {
        PyMem_RawFree(work);
        return STATUS_ERROR;
    }
    numba_raw_rgesdd(kind, jobz, m, n, a, lda, s, u ,ldu, vt, ldvt, work, lwork,
                     iwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(iwork);
    CATCH_LAPACK_INVALID_ARG("numba_raw_rgesdd", info);

    return (int)info;
}

/* Complex space svd systems info from cgesdd/zgesdd
 * Args are as per LAPACK.
 */
static int
numba_raw_cgesdd(char kind, char jobz, Py_ssize_t m, Py_ssize_t n, void *a,
                 Py_ssize_t lda, void *s, void *u, Py_ssize_t ldu, void *vt,
                 Py_ssize_t ldvt, void *work, Py_ssize_t lwork, void *rwork,
                 F_INT *iwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _m, _n, _lda, _ldu, _ldvt, _lwork;

    ENSURE_VALID_COMPLEX_KIND(kind)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _ldu = (F_INT) ldu;
    _ldvt = (F_INT) ldvt;
    _lwork = (F_INT) lwork;

    switch (kind)
    {
        case 'c':
            raw_func = get_clapack_cgesdd();
            break;
        case 'z':
            raw_func = get_clapack_zgesdd();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    (*(cgesdd_t) raw_func)(&jobz, &_m, &_n, a, &_lda, s, u, &_ldu, vt, &_ldvt,
                           work, &_lwork, rwork, iwork, info);
    return 0;
}

/* complex space svd info from cgesdd/zgesdd.
 * As numba_raw_cgesdd but the allocation and error handling is done for the
 * user.
 * Args are as per LAPACK.
 */
static int
numba_ez_cgesdd(char kind, char jobz, Py_ssize_t m, Py_ssize_t n, void *a,
                Py_ssize_t lda, void *s, void *u, Py_ssize_t ldu, void *vt,
                Py_ssize_t ldvt)
{
    F_INT info = 0;
    Py_ssize_t lwork = -1;
    Py_ssize_t lrwork = -1;
    Py_ssize_t minmn = -1;
    Py_ssize_t tmp1, tmp2;
    Py_ssize_t maxmn = -1;
    size_t real_base_size = -1;
    size_t complex_base_size = -1;
    all_dtypes stack_slot, wk1, wk2;
    void *work = NULL;
    void *rwork = (void *)&wk1;
    F_INT *iwork = (F_INT *)&wk2;

    ENSURE_VALID_COMPLEX_KIND(kind)

    switch (kind)
    {
        case 'c':
            real_base_size = sizeof(float);
            complex_base_size = sizeof(npy_complex64);
            break;
        case 'z':
            real_base_size = sizeof(double);
            complex_base_size = sizeof(npy_complex128);
            break;
        default:
        {
            PyGILState_STATE st = PyGILState_Ensure();
            PyErr_SetString(PyExc_ValueError,\
                            "Invalid kind in numba_ez_rgesdd");
            PyGILState_Release(st);
        }
        return STATUS_ERROR;
    }

    work = &stack_slot;

    /* Compute optimal work size (lwork) */
    numba_raw_cgesdd(kind, jobz, m, n, a, lda, s, u ,ldu, vt, ldvt, work, lwork,
                     rwork, iwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cgesdd", info);

    /* Allocate work array */
    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, complex_base_size * lwork))
        return STATUS_ERROR;

    minmn = m > n ? n : m;
    if (jobz == 'n')
    {
        lrwork = 7 * minmn;
    }
    else
    {
        maxmn = m > n ? m : n;
        tmp1 = 5 * minmn + 7;
        tmp2 = 2 * maxmn + 2 * minmn + 1;
        lrwork = minmn * (tmp1 > tmp2 ? tmp1: tmp2);
    }

    if (checked_PyMem_RawMalloc(&rwork,
                                real_base_size * (lrwork > 1 ? lrwork : 1)))
    {
        PyMem_RawFree(work);
        return STATUS_ERROR;
    }
    if (checked_PyMem_RawMalloc((void **) &iwork,
                                8 * minmn * sizeof(F_INT)))
    {
        PyMem_RawFree(work);
        PyMem_RawFree(rwork);
        return STATUS_ERROR;
    }
    numba_raw_cgesdd(kind, jobz, m, n, a, lda, s, u ,ldu, vt, ldvt, work, lwork,
                     rwork, iwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(rwork);
    PyMem_RawFree(iwork);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cgesdd", info);

    return (int)info;
}


/* SVD systems info from *gesdd.
 * This routine hides the type and general complexity involved with making the
 * calls to *gesdd. The work space computation and error handling etc is hidden.
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_gesdd(char kind, char jobz, Py_ssize_t m, Py_ssize_t n, void *a,
               Py_ssize_t lda, void *s, void *u, Py_ssize_t ldu, void *vt,
               Py_ssize_t ldvt)
{
    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
        case 'd':
            return numba_ez_rgesdd(kind, jobz, m, n, a, lda, s, u, ldu, vt,
                                   ldvt);
        case 'c':
        case 'z':
            return numba_ez_cgesdd(kind, jobz, m, n, a, lda, s, u, ldu, vt,
                                   ldvt);
    }
    return STATUS_ERROR; /* unreachable */
}


/*
 * Compute the QR factorization of a matrix.
 * Return -1 on internal error, 0 on success, > 0 on failure.
 */
static int
numba_raw_xgeqrf(char kind, Py_ssize_t m, Py_ssize_t n, void *a, Py_ssize_t
                 lda, void *tau, void *work, Py_ssize_t lwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _m, _n, _lda, _lwork;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgeqrf();
            break;
        case 'd':
            raw_func = get_clapack_dgeqrf();
            break;
        case 'c':
            raw_func = get_clapack_cgeqrf();
            break;
        case 'z':
            raw_func = get_clapack_zgeqrf();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _lda = (F_INT) lda;
    _lwork = (F_INT) lwork;

    (*(xgeqrf_t) raw_func)(&_m, &_n, a, &_lda, tau, work, &_lwork, info);
    return 0;
}

/*
 * Compute the QR factorization of a matrix.
 * This routine hides the type and general complexity involved with making the
 * xgeqrf calls. The work space computation and error handling etc is hidden.
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_geqrf(char kind, Py_ssize_t m, Py_ssize_t n, void *a, Py_ssize_t
               lda, void *tau)
{
    F_INT info = 0;
    Py_ssize_t lwork = -1;
    size_t base_size = -1;
    all_dtypes stack_slot;
    void *work = NULL;

    base_size = kind_size(kind);

    work = &stack_slot;

    /* Compute optimal work size (lwork) */
    numba_raw_xgeqrf(kind, m, n, a, lda, tau, work, lwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_xgeqrf", info);

    /* Allocate work array */
    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
        return STATUS_ERROR;

    numba_raw_xgeqrf(kind, m, n, a, lda, tau, work, lwork, &info);
    PyMem_RawFree(work);
    CATCH_LAPACK_INVALID_ARG("numba_raw_xgeqrf", info);

    return 0; /* info cannot be >0 */

}


/*
 * Compute the orthogonal Q matrix (in QR) from elementary relectors.
 */
static int
numba_raw_xxxgqr(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t k, void *a,
                 Py_ssize_t lda, void *tau, void * work, Py_ssize_t lwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _m, _n, _k, _lda, _lwork;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sorgqr();
            break;
        case 'd':
            raw_func = get_clapack_dorgqr();
            break;
        case 'c':
            raw_func = get_clapack_cungqr();
            break;
        case 'z':
            raw_func = get_clapack_zungqr();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _k = (F_INT) k;
    _lda = (F_INT) lda;
    _lwork = (F_INT) lwork;

    (*(xxxgqr_t) raw_func)(&_m, &_n, &_k, a, &_lda, tau, work, &_lwork, info);
    return 0;
}


/*
 * Compute the orthogonal Q matrix (in QR) from elementary reflectors.
 * This routine hides the type and general complexity involved with making the
 * x{or,un}qrf calls. The work space computation and error handling etc is
 * hidden. Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_xxgqr(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t k, void *a,
               Py_ssize_t lda, void *tau)
{
    F_INT info = 0;
    Py_ssize_t lwork = -1;
    size_t base_size = -1;
    all_dtypes stack_slot;
    void *work = NULL;

    work = &stack_slot;

    /* Compute optimal work size (lwork) */
    numba_raw_xxxgqr(kind, m, n, k, a, lda, tau, work, lwork, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_xxxgqr", info);

    base_size = kind_size(kind);

    /* Allocate work array */
    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
        return STATUS_ERROR;

    numba_raw_xxxgqr(kind, m, n, k, a, lda, tau, work, lwork, &info);
    PyMem_RawFree(work);
    CATCH_LAPACK_INVALID_ARG("numba_raw_xxxgqr", info);

    return 0;  /* info cannot be >0 */

}


/*
 * Compute the minimum-norm solution to a real linear least squares problem.
 */
static int
numba_raw_rgelsd(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t nrhs,
                 void *a, Py_ssize_t lda, void *b, Py_ssize_t ldb, void *S,
                 void * rcond, Py_ssize_t * rank, void * work,
                 Py_ssize_t lwork, F_INT *iwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _m, _n, _nrhs, _lda, _ldb, _rank, _lwork;

    ENSURE_VALID_REAL_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgelsd();
            break;
        case 'd':
            raw_func = get_clapack_dgelsd();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _nrhs = (F_INT) nrhs;
    _lda = (F_INT) lda;
    _ldb = (F_INT) ldb;
    _lwork = (F_INT) lwork;

    (*(rgelsd_t) raw_func)(&_m, &_n, &_nrhs, a, &_lda, b, &_ldb, S, rcond,
                           &_rank, work, &_lwork, iwork, info);
    *rank = (Py_ssize_t) _rank;
    return 0;
}

/*
 * Compute the minimum-norm solution to a real linear least squares problem.
 * This routine hides the type and general complexity involved with making the
 * {s,d}gelsd calls. The work space computation and error handling etc is
 * hidden. Args are as per LAPACK.
 */
static int
numba_ez_rgelsd(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t nrhs,
                void *a, Py_ssize_t lda, void *b, Py_ssize_t ldb, void *S,
                double rcond, Py_ssize_t * rank)
{
    F_INT info = 0;
    Py_ssize_t lwork = -1;
    size_t base_size = -1;
    all_dtypes stack_slot;
    void *work = NULL, *rcond_cast = NULL;
    F_INT *iwork = NULL;
    F_INT iwork_tmp;
    float tmpf;

    ENSURE_VALID_REAL_KIND(kind)

    base_size = kind_size(kind);

    work = &stack_slot;
    rcond_cast = work; /* stop checks on null ptr complaining */

    /* Compute optimal work size (lwork) */
    numba_raw_rgelsd(kind, m, n, nrhs, a, lda, b, ldb, S, rcond_cast, rank,
                     work, lwork, &iwork_tmp, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_rgelsd", info);

    /* Allocate work array */
    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
        return STATUS_ERROR;

    /* Allocate iwork array */
    if (checked_PyMem_RawMalloc((void **)&iwork, sizeof(F_INT) * iwork_tmp))
    {
        PyMem_RawFree(work);
        return STATUS_ERROR;
    }

    /* cast rcond to the right type */
    switch (kind)
    {
        case 's':
            tmpf = (float)rcond;
            rcond_cast = (void * )&tmpf;
            break;
        case 'd':
            rcond_cast = (void * )&rcond;
            break;
    }

    numba_raw_rgelsd(kind, m, n, nrhs, a, lda, b, ldb, S, rcond_cast, rank,
                     work, lwork, iwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(iwork);
    CATCH_LAPACK_INVALID_ARG("numba_raw_rgelsd", info);

    return (int)info;
}


/*
 * Compute the minimum-norm solution to a complex linear least squares problem.
 */
static int
numba_raw_cgelsd(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t nrhs,
                 void *a, Py_ssize_t lda, void *b, Py_ssize_t ldb, void *S,
                 void *rcond, Py_ssize_t * rank, void * work,
                 Py_ssize_t lwork, void * rwork, F_INT *iwork, F_INT *info)
{
    void *raw_func = NULL;
    F_INT _m, _n, _nrhs, _lda, _ldb, _rank, _lwork;

    ENSURE_VALID_COMPLEX_KIND(kind)

    switch (kind)
    {
        case 'c':
            raw_func = get_clapack_cgelsd();
            break;
        case 'z':
            raw_func = get_clapack_zgelsd();
            break;
    }
    ENSURE_VALID_FUNC(raw_func)

    _m = (F_INT) m;
    _n = (F_INT) n;
    _nrhs = (F_INT) nrhs;
    _lda = (F_INT) lda;
    _ldb = (F_INT) ldb;
    _lwork = (F_INT) lwork;

    (*(cgelsd_t) raw_func)(&_m, &_n, &_nrhs, a, &_lda, b, &_ldb, S, rcond,
                           &_rank, work, &_lwork, rwork, iwork, info);
    *rank = (Py_ssize_t) _rank;
    return 0;
}


/*
 * Compute the minimum-norm solution to a complex linear least squares problem.
 * This routine hides the type and general complexity involved with making the
 * {c,z}gelsd calls. The work space computation and error handling etc is
 * hidden. Args are as per LAPACK.
 */
static int
numba_ez_cgelsd(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t nrhs,
                void *a, Py_ssize_t lda, void *b, Py_ssize_t ldb, void *S,
                double rcond, Py_ssize_t * rank)
{
    F_INT info = 0;
    Py_ssize_t lwork = -1;
    size_t base_size = -1;
    all_dtypes stack_slot1, stack_slot2;
    size_t real_base_size = 0;
    void *work = NULL, *rwork = NULL, *rcond_cast = NULL;
    Py_ssize_t lrwork;
    F_INT *iwork = NULL;
    F_INT iwork_tmp;
    char real_kind = '-';
    float tmpf;

    ENSURE_VALID_COMPLEX_KIND(kind)

    base_size = kind_size(kind);

    work = &stack_slot1;
    rwork = &stack_slot2;
    rcond_cast = work; /* stop checks on null ptr complaining */

    /* Compute optimal work size */
    numba_raw_cgelsd(kind, m, n, nrhs, a, lda, b, ldb, S, rcond_cast, rank,
                     work, lwork, rwork, &iwork_tmp, &info);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cgelsd", info);

    /* Allocate work array */
    lwork = cast_from_X(kind, work);
    if (checked_PyMem_RawMalloc(&work, base_size * lwork))
        return STATUS_ERROR;

    /* Allocate iwork array */
    if (checked_PyMem_RawMalloc((void **)&iwork, sizeof(F_INT) * iwork_tmp))
    {
        PyMem_RawFree(work);
        return STATUS_ERROR;
    }

    switch (kind)
    {
        case 'c':
            real_kind = 's';
            tmpf = (float)rcond;
            rcond_cast = (void * )&tmpf;
            break;
        case 'z':
            real_kind = 'd';
            rcond_cast = (void * )&rcond;
            break;
    }

    real_base_size = kind_size(real_kind);

    lrwork = cast_from_X(real_kind, rwork);
    if (checked_PyMem_RawMalloc((void **)&rwork, real_base_size * lrwork))
    {
        PyMem_RawFree(work);
        PyMem_RawFree(iwork);
        return STATUS_ERROR;
    }

    numba_raw_cgelsd(kind, m, n, nrhs, a, lda, b, ldb, S, rcond_cast, rank,
                     work, lwork, rwork, iwork, &info);
    PyMem_RawFree(work);
    PyMem_RawFree(rwork);
    PyMem_RawFree(iwork);
    CATCH_LAPACK_INVALID_ARG("numba_raw_cgelsd", info);

    return (int)info;
}


/*
 * Compute the minimum-norm solution to a linear least squares problems.
 * This routine hides the type and general complexity involved with making the
 * calls to *gelsd. The work space computation and error handling etc is hidden.
 * Args are as per LAPACK.
 */
NUMBA_EXPORT_FUNC(int)
numba_ez_gelsd(char kind, Py_ssize_t m, Py_ssize_t n, Py_ssize_t nrhs,
               void *a, Py_ssize_t lda, void *b, Py_ssize_t ldb, void *S,
               double rcond, Py_ssize_t * rank)
{
    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
        case 'd':
            return numba_ez_rgelsd(kind, m, n, nrhs, a, lda, b, ldb, S, rcond,
                                   rank);
        case 'c':
        case 'z':
            return numba_ez_cgelsd(kind, m, n, nrhs, a, lda, b, ldb, S, rcond,
                                   rank);
    }
    return STATUS_ERROR; /* unreachable */
}


/*
 * Compute the solution to a system of linear equations
 */
NUMBA_EXPORT_FUNC(int)
numba_xgesv(char kind, Py_ssize_t n, Py_ssize_t nrhs, void *a, Py_ssize_t lda,
            F_INT *ipiv, void *b, Py_ssize_t ldb)
{
    void *raw_func = NULL;
    F_INT _n, _nrhs, _lda, _ldb, info;

    ENSURE_VALID_KIND(kind)

    switch (kind)
    {
        case 's':
            raw_func = get_clapack_sgesv();
            break;
        case 'd':
            raw_func = get_clapack_dgesv();
            break;
        case 'c':
            raw_func = get_clapack_cgesv();
            break;
        case 'z':
            raw_func = get_clapack_zgesv();
            break;
    }

    ENSURE_VALID_FUNC(raw_func)

    _n = (F_INT) n;
    _nrhs = (F_INT) nrhs;
    _lda = (F_INT) lda;
    _ldb = (F_INT) ldb;

    (*(xgesv_t) raw_func)(&_n, &_nrhs, a, &_lda, ipiv, b, &_ldb, &info);
    CATCH_LAPACK_INVALID_ARG("xgesv", info);

    return (int)info;
}


#undef F_INT

#undef cast_from_X
#undef cdot_t
#undef cgeev_t
#undef cgelsd_t
#undef cgesdd_t
#undef ddot_t
#undef dxnrm2_t
#undef numba_ez_cgeev
#undef numba_ez_cgelsd
#undef numba_ez_cgesdd
#undef numba_ez_cheevd
#undef numba_ez_gelsd
#undef numba_ez_geqrf
#undef numba_ez_gesdd
#undef numba_ez_rgeev
#undef numba_ez_rgelsd
#undef numba_ez_rgesdd
#undef numba_ez_rsyevd
#undef numba_ez_xxgetri
#undef numba_ez_xxgqr
#undef numba_ez_xxxevd
#undef numba_raw_cgeev
#undef numba_raw_cgelsd
#undef numba_raw_cgesdd
#undef numba_raw_cheevd
#undef numba_raw_rgeev
#undef numba_raw_rgelsd
#undef numba_raw_rgesdd
#undef numba_raw_rsyevd
#undef numba_raw_xgeqrf
#undef numba_raw_xxgetri
#undef numba_raw_xxxgqr
#undef numba_xgesv
#undef numba_xxdot
#undef numba_xxgemm
#undef numba_xxgemv
#undef numba_xxgetrf
#undef numba_xxnrm2
#undef numba_xxpotrf
#undef rgeev_t
#undef rgelsd_t
#undef rgesdd_t
#undef sdot_t
#undef sxnrm2_t
#undef xgeqrf_t
#undef xgesv_t
#undef xheevd_t
#undef xsyevd_t
#undef xxgemm_t
#undef xxgemv_t
#undef xxgetrf_t
#undef xxgetri_t
#undef xxpotrf_t
#undef xxxgqr_t
#undef zdot_t
