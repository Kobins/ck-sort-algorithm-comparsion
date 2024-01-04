#pragma once
#include "SortingAlgorithm.h"
class SelectionSort : public SortingAlgorithm {
public:
    SelectionSort() : SortingAlgorithm("SelectionSort") {}

    virtual void sort(int* arr, int size) override {
        for (int last = size - 1; last > 0; --last) {
            int largest = arr[0];
            for (int current = 1; current <= last; ++current) {
                if (arr[current] > arr[largest]) {
                    largest = current;
                }
            }
            swap(arr[last], arr[largest]);
        }
    }
};

