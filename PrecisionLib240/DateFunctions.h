#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H

#include <ctime>

bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
    else if (month == 2) {
        if (isLeapYear(year))
            maxDays = 29;
        else
            maxDays = 28;
    }

    return day <= maxDays;
}

int getDaysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return 31;
}

int getDayOfWeek(int day, int month, int year) {
    struct tm time = {0, 0, 0, day, month - 1, year - 1900};
    mktime(&time);
    return time.tm_wday;
}

int calculateAge(int birthDay, int birthMonth, int birthYear, int currentDay, int currentMonth, int currentYear) {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
        age--;
    return age;
}

bool isWeekend(int day, int month, int year) {
    int dayOfWeek = getDayOfWeek(day, month, year);
    return dayOfWeek == 0 || dayOfWeek == 6; // Sunday or Saturday
}

bool isSameDate(int day1, int month1, int year1, int day2, int month2, int year2) {
    return (day1 == day2) && (month1 == month2) && (year1 == year2);
}

bool isFutureDate(int day, int month, int year) {
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    if (year > currentTime->tm_year + 1900)
        return true;
    else if (year == currentTime->tm_year + 1900) {
        if (month > currentTime->tm_mon + 1)
            return true;
        else if (month == currentTime->tm_mon + 1)
            return day > currentTime->tm_mday;
    }
    return false;
}

bool isPastDate(int day, int month, int year) {
    return !isFutureDate(day, month, year) && !isToday(day, month, year);
}

bool isToday(int day, int month, int year) {
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    return (day == currentTime->tm_mday) && (month == currentTime->tm_mon + 1) && (year == currentTime->tm_year + 1900);
}

#endif // DATE_FUNCTIONS_H
