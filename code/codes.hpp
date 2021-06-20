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

vector<int> reverse_prefix_sum(vector<int> &nums)
{
    vector<int> res;
    auto i = nums.end() - 1;
    res.push_back(*i);

    for (i = i - 1; i >= nums.begin(); i--)
    {
        res.push_back(res.back() + *i);
    }

    return res;
}

vector<int> prefix_sum(vector<int> &nums)
{
    vector<int> res;
    auto i = nums.begin();
    res.push_back(*i);

    for (i = i + 1; i < nums.end(); i++)
    {
        res.push_back(res.back() + *i);
    }

    return res;
}
