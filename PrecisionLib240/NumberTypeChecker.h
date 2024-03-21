// NumberTypeChecker.h

#ifndef NUMBER_TYPE_CHECKER_H
#define NUMBER_TYPE_CHECKER_H

// Primary template for checking if a number is even
template <int N>
struct IsEven {
    static constexpr bool value = (N % 2 == 0);
};

#endif // NUMBER_TYPE_CHECKER_H
