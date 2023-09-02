/**
 * @file polynomial_zeros.c
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

// Function for the polynomial 6x^3 + 32x^2 + 41x + 12
double f(double x) {
    return 6.0*pow(x, 3) + 32.0*pow(x, 2) + 41.0*x + 12.0;
}

// Derivative of the function, 18x^2 + 64x + 41
double f_prime(double x) {
    return 18.0*pow(x, 2) + 64.0*x + 41.0;
}

// Newton-Raphson Method
double newton_raphson(double x0, double tol, int max_iter) {
    double x = x0;
    double x_new;
    for (int i = 0; i < max_iter; i++) {
        x_new = x - f(x) / f_prime(x);
        if (fabs(x_new - x) < tol) {
            return x_new;
        }
        x = x_new;
    }
    return NAN; // Did not converge
}

int main() {
    // Initial guesses, you may need to change these
    double initial_guesses[3] = {-10.0, 0.0, 10.0};
    double zeros[3];
    double tol = 1e-6;
    int max_iter = 100;

    for (int i = 0; i < 3; i++) {
        zeros[i] = newton_raphson(initial_guesses[i], tol, max_iter);
        printf("Zero found at x = %lf\n", zeros[i]);
    }

    return 0;
}
