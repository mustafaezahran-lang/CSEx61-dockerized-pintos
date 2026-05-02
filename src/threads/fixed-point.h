#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

/* Fixed-point format: 17.14 (17 integer bits, 14 fractional bits) */
#define F (1 << 14) // Scaling factor = 16384

/* Convert integer to fixed-point */
#define INT_TO_FP(n) ((n) * (F))

/* Convert fixed-point to integer (truncate toward zero) */
#define FP_TO_INT_ZERO(x) ((x) / (F))

/* Convert fixed-point to integer (round to nearest) */
#define FP_TO_INT_ROUND(x) \
    ((x) >= 0 ? ((x) + (F) / 2) / (F) : ((x) - (F) / 2) / (F))

/* Add two fixed-point numbers */
#define ADD_FP(x, y) ((x) + (y))

/* Subtract two fixed-point numbers */
#define SUB_FP(x, y) ((x) - (y))

/* Add fixed-point and integer */
#define ADD_FP_INT(x, n) ((x) + (n) * (F))

/* Subtract integer from fixed-point */
#define SUB_FP_INT(x, n) ((x) - (n) * (F))

/* Multiply two fixed-point numbers (use int64_t to avoid overflow) */
#define MULT_FP(x, y) (((int64_t)(x)) * (y) / (F))

/* Multiply fixed-point by integer */
#define MULT_FP_INT(x, n) ((x) * (n))

/* Divide two fixed-point numbers */
#define DIV_FP(x, y) ((((int64_t)(x)) * (F)) / (y))

/* Divide fixed-point by integer */
#define DIV_FP_INT(x, n) ((x) / (n))

#endif /* THREADS_FIXED_POINT_H */