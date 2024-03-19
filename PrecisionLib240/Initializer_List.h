#ifndef INITIALIZERLIST_H
#define INITIALIZERLIST_H

#include <initializer_list>

template <typename T>
class InitializerList {
public:
    InitializerList(std::initializer_list<T> list) : m_list(list) {}

    template <typename Container>
    void initialize(Container& container) {
        container.clear();
        for (const auto& elem : m_list) {
            container.insert(container.end(), elem);
        }
    }

    T* data() { return m_list.begin(); }
    size_t size() const { return m_list.size(); }

private:
    std::initializer_list<T> m_list;
};

#endif // INITIALIZERLIST_H
