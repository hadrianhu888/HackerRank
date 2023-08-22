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

int main() {
    float Vin, Vout, Iout, fsw, rippleVoltage, rippleCurrent;
    float D, L, C;

    printf("Enter input voltage (Vin): ");
    scanf("%f", &Vin);

    printf("Enter output voltage (Vout): ");
    scanf("%f", &Vout);

    printf("Enter output current (Iout): ");
    scanf("%f", &Iout);

    printf("Enter switching frequency (fsw) in Hz: ");
    scanf("%f", &fsw);

    printf("Enter allowable inductor current ripple (as a fraction of Iout): ");
    scanf("%f", &rippleCurrent);

    D = (Vout - Vin) / Vout;

    L = (Vin * (1 - D)) / (rippleCurrent * Iout * fsw);

    C = D * (1 - D) / (rippleVoltage * Vout * fsw * Iout);

    printf("\nBoost Converter Component Values:\n");
    printf("Duty Cycle (D): %.2f\n", D);
    printf("Inductor Value (L): %.2e H\n", L);
    printf("Capacitor Value (C): %.2e F\n", C);

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

