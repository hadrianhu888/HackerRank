#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INPUTS 2
#define HIDDEN 2
#define OUTPUTS 1
#define LEARNING_RATE 0.5

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1 - x);
}

double relu(double x) {
    if(x < 0) {
        return 0;
    }
    return x;
}

double tanh(double x) {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double leaky_relu(double x) {
    if(x < 0) {
        return 0.01 * x;
    }
    return x;
}

double adams(double x) {
    return x / (1 + abs(x));
}

void forward_propagation(double inputs[], double weights_ih[INPUTS][HIDDEN], double weights_ho[HIDDEN][OUTPUTS], double bias_h[HIDDEN], double bias_o[OUTPUTS], double hidden[HIDDEN], double output[OUTPUTS]) {
    double sum = 0;
    for(int i = 0; i < HIDDEN; i++) {
        for(int j = 0; j < INPUTS; j++) {
            sum += weights_ih[j][i] * inputs[j];
        }
        sum += bias_h[i];
        hidden[i] = sigmoid(sum);
        sum = 0;
    }
    for(int i = 0; i < OUTPUTS; i++) {
        for(int j = 0; j < HIDDEN; j++) {
            sum += weights_ho[j][i] * hidden[j];
        }
        sum += bias_o[i];
        output[i] = sigmoid(sum);
        sum = 0;
    }
}

void backpropagation(double inputs[], double output[], double hidden[], double weights_ih[INPUTS][HIDDEN], double weights_ho[HIDDEN][OUTPUTS], double bias_h[HIDDEN], double bias_o[OUTPUTS], double target) {
    double error[OUTPUTS];
    double delta_output[OUTPUTS];
    double delta_hidden[HIDDEN];
    double delta_weights_ih[INPUTS][HIDDEN];
    double delta_weights_ho[HIDDEN][OUTPUTS];
    double delta_bias_h[HIDDEN];
    double delta_bias_o[OUTPUTS];
    double sum = 0;

    // Calculate error
    for(int i = 0; i < OUTPUTS; i++) {
        error[i] = 0.5 * pow((output[i] - target), 2);
        delta_output[i] = output[i] - target;
    }

    // Calculate delta for hidden layer
    for(int i = 0; i < HIDDEN; i++) {
        for(int j = 0; j < OUTPUTS; j++) {
            sum += weights_ho[i][j] * delta_output[j];
        }
        delta_hidden[i] = sum * sigmoid_derivative(hidden[i]);
        sum = 0;
    }

    // Calculate weight and bias updates
    for(int i = 0; i < INPUTS; i++) {
        for(int j = 0; j < HIDDEN; j++) {
            delta_weights_ih[i][j] = LEARNING_RATE * delta_hidden[j] * inputs[i];
        }
    }
    for(int i = 0; i < HIDDEN; i++) {
        for(int j = 0; j < OUTPUTS; j++) {
            delta_weights_ho[i][j] = LEARNING_RATE * delta_output[j] * hidden[i];
        }
    }
    for(int i = 0; i < HIDDEN; i++) {
        delta_bias_h[i] = LEARNING_RATE * delta_hidden[i];
    }
    for(int i = 0; i < OUTPUTS; i++) {
        delta_bias_o[i] = LEARNING_RATE * delta_output[i];
    }

    // Update weights and biases
    for(int i = 0; i < INPUTS; i++) {
        for(int j = 0; j < HIDDEN; j++) {
            weights_ih[i][j] -= delta_weights_ih[i][j];
        }
    }
    for(int i = 0; i < HIDDEN; i++) {
        for(int j = 0; j < OUTPUTS; j++) {
            weights_ho[i][j] -= delta_weights_ho[i][j];
        }
    }
    for(int i = 0; i < HIDDEN; i++) {
        bias_h[i] -= delta_bias_h[i];
    }
    for(int i = 0; i < OUTPUTS; i++) {
        bias_o[i] -= delta_bias_o[i];
    }
}

void print_results(double inputs[], double weights_ih[INPUTS][HIDDEN], double weights_ho[HIDDEN][OUTPUTS], double bias_h[HIDDEN], double bias_o[OUTPUTS], double hidden[HIDDEN], double output[OUTPUTS])
{
    printf("Inputs: ");
    for (int i = 0; i < INPUTS; i++)
    {
        printf("%f ", inputs[i]);
    }
    printf("\n");
    printf("Weights from input to hidden: \n");
    for (int i = 0; i < INPUTS; i++)
    {
        for (int j = 0; j < HIDDEN; j++)
        {
            printf("%f ", weights_ih[i][j]);
        }
        printf("\n");
    }
    printf("Weights from hidden to output: \n");
    for (int i = 0; i < HIDDEN; i++)
    {
        for (int j = 0; j < OUTPUTS; j++)
        {
            printf("%f ", weights_ho[i][j]);
        }
        printf("\n");
    }
    printf("Bias for hidden layer: ");
    for (int i = 0; i < HIDDEN; i++)
    {
        printf("%f ", bias_h[i]);
    }
    printf("\n");
    printf("Bias for output layer: ");
    for (int i = 0; i < OUTPUTS; i++)
    {
        printf("%f ", bias_o[i]);
    }
    printf("\n");
    printf("Hidden layer: ");
    for (int i = 0; i < HIDDEN; i++)
    {
        printf("%f ", hidden[i]);
    }
    printf("\n");
    printf("Output layer: ");
    for (int i = 0; i < OUTPUTS; i++)
    {
        printf("%f ", output[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    double inputs[INPUTS] = {0.05, 0.10};
    double weights_ih[INPUTS][HIDDEN] = {{0.15, 0.20}, {0.25, 0.30}};
    double weights_ho[HIDDEN][OUTPUTS] = {{0.40}, {0.50}};
    double bias_h[HIDDEN] = {0.35, 0.35};
    double bias_o[OUTPUTS] = {0.60};
    double hidden[HIDDEN];
    double output[OUTPUTS];
    double target = 0.01;

    forward_propagation(inputs, weights_ih, weights_ho, bias_h, bias_o, hidden, output);
    backpropagation(inputs, output, hidden, weights_ih, weights_ho, bias_h, bias_o, target);

    // You can add print statements to print the results.

    print_results(inputs, weights_ih, weights_ho, bias_h, bias_o, hidden, output);

    return 0;
}
