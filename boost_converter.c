/**
 * @file boost_converter.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>

double calculateDutyCycle(double Vin, double Vout) {
    return Vout / Vin;
}

double calculateInductorValue(double Vout, double rippleCurrent, double Iout, double fsw, double D) {
    return (Vout * (1 - D)) / (rippleCurrent * Iout * fsw);
}

double calculateCapacitorValue(double D, double Vout, double rippleVoltage, double fsw, double Iout) {
    return D * (1 - D) * Vout / (rippleVoltage * Vout * fsw * Iout);
}

double calculateVoltageRipple(double D, double Vout, double fsw, double L) {
    return (1 - D) * Vout / (fsw * L);
}

double calculateCurrentRipple(double D, double Iout) {
    return (1 - D) * Iout;
}

void get_user_inputs(double *Vin, double *Vout, double *Iout, double *fsw, double *rippleVoltage, double *rippleCurrent) {
    printf("Enter input voltage (Vin): ");
    scanf("%lf", Vin);

    printf("Enter output voltage (Vout): ");
    scanf("%lf", Vout);

    printf("Enter output current (Iout): ");
    scanf("%lf", Iout);

    printf("Enter switching frequency (fsw) in Hz: ");
    scanf("%lf", fsw);

    printf("Enter allowable output voltage ripple (as a fraction of Vout): ");
    scanf("%lf", rippleVoltage);

    printf("Enter allowable inductor current ripple (as a fraction of Iout): ");
    scanf("%lf", rippleCurrent);
}

void get_results(double Vin, double Vout, double Iout, double fsw, double rippleVoltage, double rippleCurrent, double *D, double *L, double *C, double *deltaI, double *deltaV) {
    *D = calculateDutyCycle(Vin, Vout);
    *L = calculateInductorValue(Vout, rippleCurrent, Iout, fsw, *D);
    *C = calculateCapacitorValue(*D, Vout, rippleVoltage, fsw, Iout);
    *deltaV = calculateVoltageRipple(*D, Vout, fsw, *L);
    *deltaI = calculateCurrentRipple(*D, Iout);
}

void display_input_output(double Vin, double Vout, double Iout, double fsw, double rippleVoltage, double rippleCurrent, double D, double L, double C, double deltaI, double deltaV) {
    printf("\n");
    printf("Input parameters:\n");
    printf("Vin = %lf\n", Vin);
    printf("Vout = %lf\n", Vout);
    printf("Iout = %lf\n", Iout);
    printf("fsw = %lf\n", fsw);
    printf("rippleVoltage = %lf\n", rippleVoltage);
    printf("rippleCurrent = %lf\n", rippleCurrent);
    printf("\n");
    printf("Calculated parameters:\n");
    printf("D = %lf\n", D);
    printf("L = %lf\n", L);
    printf("C = %lf\n", C);
    printf("deltaI = %lf\n", deltaI);
    printf("deltaV = %lf\n", deltaV);
}

int main(int argc, char *argv[]) {
    double Vin, Vout, Iout, fsw, rippleVoltage, rippleCurrent;
    double D, L, C, deltaI, deltaV;

    get_user_inputs(&Vin, &Vout, &Iout, &fsw, &rippleVoltage, &rippleCurrent);
    get_results(Vin, Vout, Iout, fsw, rippleVoltage, rippleCurrent, &D, &L, &C, &deltaI, &deltaV);
    display_input_output(Vin, Vout, Iout, fsw, rippleVoltage, rippleCurrent, D, L, C, deltaI, deltaV);

    return 0;
}

/**
 * @brief provide a realistic example of the output below
 * 
 */

// Enter input voltage (Vin): 12
// Enter output voltage (Vout): 24
// Enter output current (Iout): 1
// Enter switching frequency (fsw) in Hz: 100000
// Enter allowable output voltage ripple (as a fraction of Vout): 0.05
// Enter allowable inductor current ripple (as a fraction of Iout): 0.1

// Input parameters:
// Vin = 12.000000
// Vout = 24.000000
// Iout = 1.000000
// fsw = 100000.000000
// rippleVoltage = 0.050000
// rippleCurrent = 0.100000

// Calculated parameters:
// D = 2.000000
// L = 0.000000
// C = 0.000000
// deltaI = 0.000000
// deltaV = 0.000000

