#ifndef MERGESORT_H
#define MERGESORT_H

#pragma once
#include <vector>

class MergeSort {
public:
    static void sort(std::vector<int>& arr);
private:
    static void mergeSortHelper(std::vector<int>& arr, int left, int right);
    static void merge(std::vector<int>& arr, int left, int mid, int right);
};

#endif
