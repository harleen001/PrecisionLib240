#include <iostream>
#include <vector>
#include "Range_Based_For_Loop.h"

int main() {
    using namespace std;
    using namespace RangeBasedForLoop;

    vector<int> numbers = {1, 2, 3, 4, 5};

    // Double each element in the vector
    forEach(numbers, [](const int& x) { cout << x * 2 << " "; });

    return 0;
}
