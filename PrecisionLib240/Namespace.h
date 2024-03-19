#ifndef NAMESPACE_H
#define NAMESPACE_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

template<typename T>
class Namespace {
public:
    Namespace(std::initializer_list<std::pair<std::string, T>> initList) {
        for (const auto& pair : initList) {
            m_namespaceMap.insert(pair);
        }
    }

    T getValue(const std::string& name) const {
        auto it = m_namespaceMap.find(name);
        if (it != m_namespaceMap.end()) {
            return it->second;
        }
        throw std::invalid_argument("Invalid identifier");
    }

    std::vector<std::string> getAllIdentifiers() const {
        std::vector<std::string> identifiers;
        for (const auto& pair : m_namespaceMap) {
            identifiers.push_back(pair.first);
        }
        return identifiers;
    }

    void printAll() const {
        std::cout << "Namespace:\n";
        for (const auto& pair : m_namespaceMap) {
            std::cout << "  " << pair.first << " -> " << pair.second << '\n';
        }
    }

private:
    std::map<std::string, T> m_namespaceMap;
};

#endif // NAMESPACE_H
