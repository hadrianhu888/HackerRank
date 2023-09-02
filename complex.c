/**
 * @file complex.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct complex
{
    double real;
    double imag;
} complex_t;

complex_t complex_new(double real, double imag);
void complex_print(complex_t c);
complex_t complex_add(complex_t c1, complex_t c2);
complex_t complex_sub(complex_t c1, complex_t c2);
complex_t complex_mul(complex_t c1, complex_t c2);
complex_t complex_div(complex_t c1, complex_t c2);
complex_t complex_conj(complex_t c);
double complex_abs(complex_t c);
complex_t complex_exp(complex_t c);
complex_t complex_log(complex_t c);
complex_t complex_pow(complex_t c1, complex_t c2);
complex_t complex_sqrt(complex_t c);
complex_t complex_sin(complex_t c);
complex_t complex_cos(complex_t c);
complex_t complex_tan(complex_t c);
complex_t complex_asin(complex_t c);
complex_t complex_acos(complex_t c);
complex_t complex_atan(complex_t c);
complex_t complex_sinh(complex_t c);
complex_t complex_cosh(complex_t c);
complex_t complex_tanh(complex_t c);
complex_t complex_asinh(complex_t c);
complex_t complex_acosh(complex_t c);
complex_t complex_atanh(complex_t c);

int main(int argc, char **argv);

complex_t complex_new(double real, double imag)
{
    complex_t c;
    c.real = real;
    c.imag = imag;
    return c;
}

void complex_print(complex_t c)
{
    if (c.imag < 0)
    {
        printf("%lf - %lfi\n", c.real, fabs(c.imag));
    }
    else
    {
        printf("%lf + %lfi\n", c.real, c.imag);
    }
}

complex_t complex_add(complex_t c1, complex_t c2)
{
    complex_t c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}

complex_t complex_sub(complex_t c1, complex_t c2)
{
    complex_t c;
    c.real = c1.real - c2.real;
    c.imag = c1.imag - c2.imag;
    return c;
}

complex_t complex_mul(complex_t c1, complex_t c2)
{
    complex_t c;
    c.real = c1.real * c2.real - c1.imag * c2.imag;
    c.imag = c1.real * c2.imag + c1.imag * c2.real;
    return c;
}

complex_t complex_div(complex_t c1, complex_t c2)
{
    complex_t c;
    c.real = (c1.real * c2.real + c1.imag * c2.imag) / (pow(c2.real, 2) + pow(c2.imag, 2));
    c.imag = (c1.imag * c2.real - c1.real * c2.imag) / (pow(c2.real, 2) + pow(c2.imag, 2));
    return c;
}

complex_t complex_conj(complex_t c)
{
    complex_t conj;
    conj.real = c.real;
    conj.imag = -c.imag;
    return conj;
}

double complex_abs(complex_t c)
{
    return sqrt(pow(c.real, 2) + pow(c.imag, 2));
}

complex_t complex_exp(complex_t c)
{
    complex_t exp_t;
    exp_t.real = exp(c.real) * cos(c.imag);
    exp_t.imag = exp(c.real) * sin(c.imag);
    return exp_t;
}

complex_t complex_log(complex_t c)
{
    complex_t log_t;
    log_t.real = log(complex_abs(c));
    log_t.imag = atan2(c.imag, c.real);
    return log_t;
}

complex_t complex_pow(complex_t c1, complex_t c2)
{
    complex_t pow_t;
    pow_t.real = pow(complex_abs(c1), c2.real) * exp(-c2.imag * atan2(c1.imag, c1.real));
    pow_t.imag = c2.real * atan2(c1.imag, c1.real) + c2.imag * log(complex_abs(c1));
    return pow_t;
}

complex_t complex_sqrt(complex_t c)
{
    complex_t sqrt_t;
    sqrt_t.real = sqrt((complex_abs(c) + c.real) / 2);
    sqrt_t.imag = sqrt((complex_abs(c) - c.real) / 2);
    return sqrt_t;
}

complex_t complex_sin(complex_t c)
{
    complex_t sin_t;
    sin_t.real = sin(c.real) * cosh(c.imag);
    sin_t.imag = cos(c.real) * sinh(c.imag);
    return sin_t;
}

complex_t complex_cos(complex_t c)
{
    complex_t cos_t;
    cos_t.real = cos(c.real) * cosh(c.imag);
    cos_t.imag = -sin(c.real) * sinh(c.imag);
    return cos_t;
}

complex_t complex_tan(complex_t c)
{
    complex_t tan_t;
    tan_t.real = sin(2 * c.real) / (cos(2 * c.real) + cosh(2 * c.imag));
    tan_t.imag = sinh(2 * c.imag) / (cos(2 * c.real) + cosh(2 * c.imag));
    return tan_t;
}

complex_t complex_asin(complex_t c)
{
    complex_t asin_t;
    asin_t.real = asin(c.real) * cosh(c.imag);
    asin_t.imag = -asin(c.imag) * sinh(c.real);
    return asin_t;
}

complex_t complex_acos(complex_t c)
{
    complex_t acos_t;
    acos_t.real = acos(c.real) * cosh(c.imag);
    acos_t.imag = -acos(c.imag) * sinh(c.real);
    return acos_t;
}

complex_t complex_atan(complex_t c)
{
    complex_t atan_t;
    atan_t.real = atan(c.real) * cosh(c.imag);
    atan_t.imag = -atan(c.imag) * sinh(c.real);
    return atan_t;
}

complex_t complex_sinh(complex_t c)
{
    complex_t sinh_t;
    sinh_t.real = sinh(c.real) * cos(c.imag);
    sinh_t.imag = cosh(c.real) * sin(c.imag);
    return sinh_t;
}

complex_t complex_cosh(complex_t c)
{
    complex_t cosh_t;
    cosh_t.real = cosh(c.real) * cos(c.imag);
    cosh_t.imag = sinh(c.real) * sin(c.imag);
    return cosh_t;
}

complex_t complex_tanh(complex_t c)
{
    complex_t tanh_t;
    tanh_t.real = sinh(2 * c.real) / (cosh(2 * c.real) + cos(2 * c.imag));
    tanh_t.imag = sin(2 * c.imag) / (cosh(2 * c.real) + cos(2 * c.imag));
    return tanh_t;
}

complex_t complex_asinh(complex_t c)
{
    complex_t asinh_t;
    asinh_t.real = asinh(c.real) * cos(c.imag);
    asinh_t.imag = asin(c.imag) * cosh(c.real);
    return asinh_t;
}

complex_t complex_acosh(complex_t c)
{
    complex_t acosh_t;
    acosh_t.real = acosh(c.real) * cos(c.imag);
    acosh_t.imag = acos(c.imag) * cosh(c.real);
    return acosh_t;
}

complex_t complex_atanh(complex_t c)
{
    complex_t atanh_t;
    atanh_t.real = atanh(c.real) * cos(c.imag);
    atanh_t.imag = atan(c.imag) * cosh(c.real);
    return atanh_t;
}

int main(int argc, char **argv)
{
    complex_t c1 = complex_new(1.0, 2.0);
    complex_t c2 = complex_new(3.0, 4.0);
    complex_t c3 = complex_add(c1, c2);
    complex_t c4 = complex_sub(c1, c2);
    complex_t c5 = complex_mul(c1, c2);
    complex_t c6 = complex_div(c1, c2);
    complex_t c7 = complex_conj(c1);
    double c8 = complex_abs(c1);
    complex_t c9 = complex_exp(c1);
    complex_t c10 = complex_log(c1);
    complex_t c11 = complex_pow(c1, c2);
    complex_t c12 = complex_sqrt(c1);
    complex_t c13 = complex_sin(c1);
    complex_t c14 = complex_cos(c1);
    complex_t c15 = complex_tan(c1);
    complex_t c16 = complex_asin(c1);
    complex_t c17 = complex_acos(c1);
    complex_t c18 = complex_atan(c1);
    complex_t c19 = complex_sinh(c1);
    complex_t c20 = complex_cosh(c1);
    complex_t c21 = complex_tanh(c1);
    complex_t c22 = complex_asinh(c1);
    complex_t c23 = complex_acosh(c1);
    complex_t c24 = complex_atanh(c1);
    complex_print(c1);
    complex_print(c2);
    complex_print(c3);
    complex_print(c4);
    complex_print(c5);
    complex_print(c6);
    complex_print(c7);
    printf("%lf\n", c8);
    complex_print(c9);
    complex_print(c10);
    complex_print(c11);
    complex_print(c12);
    complex_print(c13);
    complex_print(c14);
    complex_print(c15);
    complex_print(c16);
    complex_print(c17);
    complex_print(c18);
    complex_print(c19);
    complex_print(c20);
    complex_print(c21);
    complex_print(c22);
    complex_print(c23);
    complex_print(c24);
    return 0;
}

