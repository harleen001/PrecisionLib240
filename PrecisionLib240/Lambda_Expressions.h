#ifndef LAMBDA_EXPRESSIONS_H
#define LAMBDA_EXPRESSIONS_H

#include <functional>
#include <cmath> // Include cmath for sqrt function

namespace LambdaExpressions {
    // Function to double the input using a lambda expression
    double doubleInput(double input) {
        // Define the lambda function inline
        auto lambda = [](double x) { return 2 * x; };
        // Apply the lambda function to the input
        return lambda(input);
    }

    // Function to square the input using a lambda expression
    double squareInput(double input) {
        // Define the lambda function inline
        auto lambda = [](double x) { return x * x; };
        // Apply the lambda function to the input
        return lambda(input);
    }

    // Function to calculate the cube of the input using a lambda expression
    double cubeInput(double input) {
        // Define the lambda function inline
        auto lambda = [](double x) { return x * x * x; };
        // Apply the lambda function to the input
        return lambda(input);
    }

    // Function to calculate the square root of the input using a lambda expression
    double squareRootInput(double input) {
        // Define the lambda function inline
        auto lambda = [](double x) {
            if (x < 0) {
                throw std::invalid_argument("Cannot take square root of a negative number");
            }
            return sqrt(x);
        };
        // Apply the lambda function to the input
        return lambda(input);
    }
}

#endif // LAMBDA_EXPRESSIONS_H
