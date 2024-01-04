#pragma once
#include "SortingAlgorithm.h"
class BubbleSort : public SortingAlgorithm {
public:
    BubbleSort() : SortingAlgorithm("BubbleSort") {}

    virtual void sort(int* arr, int size) override {
        bool sorted = false;
        for (int last = size - 1; last > 0 && sorted == false; --last) {
            sorted = true;
            for (int current = 0; current < last; ++current) {
                if (arr[current] > arr[current + 1]) {
                    swap(arr[current], arr[current + 1]);
                    sorted = false;
                }
            }
        }
    }
};

