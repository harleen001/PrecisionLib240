#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>

template <typename... Types>
class Tuple;

// Base case: empty tuple
template <>
class Tuple<> {
public:
    Tuple() {}
};

// Recursive case: tuple with one or more elements
template <typename First, typename... Rest>
class Tuple<First, Rest...> : public Tuple<Rest...> {
private:
    First value;

public:
    // Constructor to initialize the value
    Tuple(First first, Rest... rest) : value(first), Tuple<Rest...>(rest...) {}

    // Get method to retrieve the value
    First get() const {
        return value;
    }
};

#endif // TUPLE_H
