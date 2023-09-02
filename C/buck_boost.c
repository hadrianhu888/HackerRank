/**
 * @file buck_boost.c
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

    D = Vout / (Vout + Vin);

    L = (Vin * Vout) / (rippleCurrent * Iout * fsw * (Vout + Vin));

    C = D * (1 - D) * Vin * Vout / (rippleVoltage * Vout * fsw * Iout * (Vout + Vin));

    printf("\nBuck-Boost Converter Component Values:\n");
    printf("Duty Cycle (D): %.2f\n", D);
    printf("Inductor Value (L): %.2e H\n", L);
    printf("Capacitor Value (C): %.2e F\n", C);

    return 0;
}
