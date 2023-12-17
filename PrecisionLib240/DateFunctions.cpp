#include <iostream>
#include "DateFunctions.h" // Include the header file

int main() {
    // Check if a year is a leap year
    int year = 2024;
    if (isLeapYear(year)) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }

    // Check if a date is valid
    int day = 29, month = 2, testYear = 2023;
    if (isValidDate(day, month, testYear)) {
        std::cout << day << "/" << month << "/" << testYear << " is a valid date." << std::endl;
    } else {
        std::cout << day << "/" << month << "/" << testYear << " is not a valid date." << std::endl;
    }

    // Get the number of days in a month
    int daysInFebruary = getDaysInMonth(2, 2022);
    std::cout << "February 2022 has " << daysInFebruary << " days." << std::endl;

    // Get the day of the week for a given date
    int dayOfWeek = getDayOfWeek(11, 12, 2023);
    std::cout << "11th December 2023 is a ";
    switch (dayOfWeek) {
        case 0:
            std::cout << "Sunday." << std::endl;
            break;
        case 1:
            std::cout << "Monday." << std::endl;
            break;
        // ... (Other days of the week)
        default:
            std::cout << "Invalid day." << std::endl;
    }

    // Calculate age
    int birthDay = 15, birthMonth = 5, birthYear = 1995;
    int currentDay = 25, currentMonth = 8, currentYear = 2023;
    int age = calculateAge(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear);
    std::cout << "Age: " << age << std::endl;

    // Check if a date is a weekend
    bool isWeekendDate = isWeekend(18, 12, 2022);
    std::cout << "18th December 2022 is ";
    std::cout << (isWeekendDate ? "a weekend." : "not a weekend.") << std::endl;

    // Check if two dates are the same
    bool isSame = isSameDate(5, 10, 2022, 5, 10, 2022);
    std::cout << "Are both dates the same? ";
    std::cout << (isSame ? "Yes." : "No.") << std::endl;

    // Check if a date is in the future
    bool isFuture = isFutureDate(31, 12, 2025);
    std::cout << "Is 31st December 2025 a future date? ";
    std::cout << (isFuture ? "Yes." : "No.") << std::endl;

    // Check if a date is in the past
    bool isPast = isPastDate(15, 5, 2020);
    std::cout << "Is 15th May 2020 a past date? ";
    std::cout << (isPast ? "Yes." : "No.") << std::endl;

    // Check if a date is today
    bool isTodayDate = isToday(25, 8, 2023);
    std::cout << "Is today's date? ";
    std::cout << (isTodayDate ? "Yes." : "No.") << std::endl;

    return 0;
}
