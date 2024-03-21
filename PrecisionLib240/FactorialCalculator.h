// FactorialCalculator.h

#ifndef FACTORIAL_CALCULATOR_H
#define FACTORIAL_CALCULATOR_H

// Primary template for factorial computation
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

// Specialization of the factorial template for N = 0
template <>
struct Factorial<0> {
    static const int value = 1;
};

#endif // FACTORIAL_CALCULATOR_H
