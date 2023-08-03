#pragma once

#include <vector>

class QuickSort
{
public:
    std::vector<int>& vector;
    int left, right;
public:
    QuickSort(std::vector<int>&, int, int);
    bool sort(int&, int&);
    std::vector<int>& getData(int&, int&);
    ~QuickSort() = default;
};