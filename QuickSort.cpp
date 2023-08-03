#include "QuickSort.h"
#include <iostream>

QuickSort::QuickSort(std::vector<int>& v, int a, int b) : vector(v), left(a), right(b) {}

bool QuickSort::sort(int& left_bound, int& right_bound)
{
    if (left >= right)
    {
        return false;
    }
    left_bound = this->left;
    right_bound = this->right;
    int middle = vector[(right + left) / 2];
    do {
        while (vector[left_bound] < middle)
        {
            left_bound++;
        }
        while (vector[right_bound] > middle)
        {
            right_bound--;
        }
        if (left_bound <= right_bound)
        {
            std::swap(vector[left_bound], vector[right_bound]);
            left_bound++;
            right_bound--;
        }
    } while (left_bound <= right_bound);
    return true;
}

std::vector<int>& QuickSort::getData(int& l, int& r)
{
    l = left;
    r = right;
    return vector;
}