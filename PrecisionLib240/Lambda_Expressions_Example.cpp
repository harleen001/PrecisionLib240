#include <iostream>
#include "Lambda_Expressions.h"

int main() {
    using namespace std;
    using namespace LambdaExpressions;

    double input = 5.0;

    // Using the doubleInput function
    double result = doubleInput(input);
    cout << "Result of doubling " << input << ": " << result << endl;

    // Using the squareInput function
    result = squareInput(input);
    cout << "Result of squaring " << input << ": " << result << endl;

    return 0;
}
