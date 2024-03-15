#ifndef RANGE_BASED_FOR_LOOP_H
#define RANGE_BASED_FOR_LOOP_H

#include <iostream>
#include <vector>

namespace RangeBasedForLoop {
    // Function to iterate over elements in a container and perform an action
    template<typename Container, typename Action>
    void forEach(const Container& container, Action action) {
        for (const auto& element : container) {
            action(element);
        }
    }
}

#endif // RANGE_BASED_FOR_LOOP_H
