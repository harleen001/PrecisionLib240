#ifndef ENUMCLASS_H
#define ENUMCLASS_H

#include <iostream>
#include <map>
#include <stdexcept>

template<typename T>
class EnumClass {
public:
    EnumClass(std::initializer_list<std::pair<T, std::string>> initList) {
        for (const auto& pair : initList) {
            m_enumMap.insert(pair);
        }
    }

    T getValue(const std::string& name) const {
        auto it = m_enumMap.find(name);
        if (it != m_enumMap.end()) {
            return it->first;
        }
        throw std::invalid_argument("Invalid enumeration name");
    }

    std::string getName(const T& value) const {
        auto it = m_enumMap.begin();
        while (it != m_enumMap.end()) {
            if (it->first == value) {
                return it->second;
            }
            ++it;
        }
        throw std::invalid_argument("Invalid enumeration value");
    }

    void printAll() const {
        std::cout << "Enum Class:\n";
        for (const auto& pair : m_enumMap) {
            std::cout << "  " << pair.first << " -> " << pair.second << '\n';
        }
    }

private:
    std::map<T, std::string> m_enumMap;
};

#endif // ENUMCLASS_H
