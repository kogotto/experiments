#pragma once

#include <vector>

template <typename Iter>
Iter removeEverySecondElementImpl(Iter first, Iter last) {
    if (first == last) {
        return first;
    }

    ++first;

    if (first == last) {
        return first;
    }

    Iter source = first;
    ++source;

    for (; source != last; ++source) {
        (*first++) = (*source);

        ++source;
        if (source == last) {
            break;
        }
    }
    return first;
}

template <typename T>
inline void removeEverySecondElement(std::vector<T>& vec) {
    vec.erase(
        removeEverySecondElementImpl(
            vec.begin(),
            vec.end()
        ),
        vec.end()
    );
}
