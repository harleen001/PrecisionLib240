#include <iostream>
#include <string>
#include "Enum.h"

enum class MyEnum { A, B, C, D };

int main() {
    // Create strongly-typed enumeration
    EnumClass<MyEnum> myEnumClass = {
        { MyEnum::A, "Alpha" },
        { MyEnum::B, "Beta" },
        { MyEnum::C, "Charlie" },
        { MyEnum::D, "Delta" }
    };

    // Print all enum values and their corresponding names
    myEnumClass.printAll();

    // Retrieve enum value from name
    std::string name = "Charlie";
    try {
        MyEnum value = myEnumClass.getValue(name);
        std::cout << "Value corresponding to name '" << name << "' is: " << static_cast<int>(value) << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }

    // Retrieve enum name from value
    MyEnum value = MyEnum::B;
    try {
        std::string enumName = myEnumClass.getName(value);
        std::cout << "Name corresponding to value " << static_cast<int>(value) << " is: " << enumName << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
