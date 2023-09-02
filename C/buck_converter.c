/**
 * @file buck_converter.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main() {
    // User-defined parameters
    float Vin, Vout, Iout, fsw, rippleVoltage, rippleCurrent;

    // Calculated parameters
    float D, L, C;

    // Prompting user for input parameters
    printf("Enter input voltage (Vin): ");
    scanf("%f", &Vin);

    printf("Enter output voltage (Vout): ");
    scanf("%f", &Vout);

    printf("Enter output current (Iout): ");
    scanf("%f", &Iout);

    printf("Enter switching frequency (fsw) in Hz: ");
    scanf("%f", &fsw);

    printf("Enter allowable output voltage ripple (as a fraction of Vout): ");
    scanf("%f", &rippleVoltage);

    printf("Enter allowable inductor current ripple (as a fraction of Iout): ");
    scanf("%f", &rippleCurrent);

    // Calculating duty cycle
    D = Vout / Vin;

    // Calculating inductor value (assuming continuous conduction mode)
    L = (Vout * (1 - D)) / (rippleCurrent * Iout * fsw);

    // Calculating capacitor value
    C = D * (1 - D) * Vout / (rippleVoltage * Vout * fsw * Iout);

    // Printing the results
    printf("\nBuck Converter Component Values:\n");
    printf("Duty Cycle (D): %.2f\n", D);
    printf("Inductor Value (L): %.2e H\n", L);
    printf("Capacitor Value (C): %.2e F\n", C);

    return 0;
}

