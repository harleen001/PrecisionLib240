#ifndef CONSTEXPR_EXAMPLE_H
#define CONSTEXPR_EXAMPLE_H

class ConstexprExample {
public:
    // Function to calculate the factorial of a number at compile-time
    constexpr int factorial(int n) const {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }

    // Function to check if a number is prime at compile-time
    constexpr bool isPrime(int n) const {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

#endif // CONSTEXPR_EXAMPLE_H
