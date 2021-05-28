#include <bits/stdc++.h>

template <class T>
void printvector(std::vector<T> v) {
    std::cout << "[";
    for_each(v.begin()+1, v.end()-1, [](T x){std::cout << x << ", ";});
    std::cout << v.back() << "]" << std::endl;
}

template <class InputIterator>
void prefix_sum(InputIterator first, InputIterator last) {
    while (++first != last) {
        *first += *(first-1);
    }
}
