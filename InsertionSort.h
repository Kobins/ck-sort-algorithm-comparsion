#pragma once
#include "SortingAlgorithm.h"
class InsertionSort : public SortingAlgorithm {
public:
    InsertionSort() : SortingAlgorithm("InsertionSort") {}

    virtual void sort(int* arr, int size) override {
        for (int sorting = 1; sorting < size; sorting++) {
            int data = arr[sorting];
            int current = sorting;
            for (; (current > 0) && (arr[current - 1] > data); current--) {
                arr[current] = arr[current - 1];
            }
            arr[current] = data;
        }
    }
};

