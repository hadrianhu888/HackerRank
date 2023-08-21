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
    float D, L, C, deltaI, deltaV;

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

    // Calculating inductor value (assuming discontinuous conduction mode)
    L = (Vout * (1 - D)) / (rippleCurrent * Iout * fsw * D);

    // Calculating capacitor value
    C = D * (1 - D) * Vout / (rippleVoltage * Vout * fsw * Iout);

    // Calcualting the capacitor value (assuming discontinuous conduction mode)
    C = (1 - D) * Vout / (rippleVoltage * Vout * fsw * Iout);

    // Calculate voltage ripple 
    deltaV = (1 - D) * Vout / (fsw * L);

    // Calculate current ripple
    deltaI = (1 - D) * Iout;

    // Printing the results

    // Printing the results
    printf("\nBuck Converter Component Values:\n");
    printf("Duty Cycle (D): %.2f\n", D);
    printf("Inductor Value (L): %.2e H\n", L);
    printf("Capacitor Value (C): %.2e F\n", C);

    return 0;
}

/**
 * @brief provide example of a realistic calculated example below 
 * 
 */

// Enter input voltage (Vin): 12
// Enter output voltage (Vout): 5
// Enter output current (Iout): 1
// Enter switching frequency (fsw) in Hz: 100000
// Enter allowable output voltage ripple (as a fraction of Vout): 0.05
// Enter allowable inductor current ripple (as a fraction of Iout): 0.2

// Buck Converter Component Values:
// Duty Cycle (D): 0.42
// Inductor Value (L): 1.68e-05 H
// Capacitor Value (C): 1.68e-05 F
