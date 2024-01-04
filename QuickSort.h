#pragma once
#include "SortingAlgorithm.h"
class QuickSort : public SortingAlgorithm {
public:
    QuickSort() : SortingAlgorithm("QuickSort") {}

    virtual void sort(int* arr, int size) override {
        quickSort(arr, 0, size - 1);
    }
private:
    // 임의의 pivot을 고르고, 그 pivot보다 작은 값을 왼쪽으로, 큰 값을 오른쪽으로
    int partition(int* arr, int low, int high) {
        //swap(arr[low], arr[(low + high) / 2]);
        // pivot을 low로 설정
        int pivotItem = arr[low];
        int pivotIndex = low;
        // pivot을 제외한 low+1 부터 전부 체크
        for (int cur = low + 1; cur <= high; ++cur) {
            // pivot보다 작은 경우
            if (arr[cur] < pivotItem) {
                // 왼쪽으로 옮김
                pivotIndex++;
                swap(arr[cur], arr[pivotIndex]);
            }
        }
        // 루프가 끝나면 pivotIndex가 기준이 됨
        // low+1 ~ pivotIndex까지는 pivotItem보다 작은 배열
        // pivotIndex + 1 ~ high까지는 pivotItem보다 큰 배열
        swap(arr[low], arr[pivotIndex]);
        //Vector::print(arr, low, pivotIndex - 1); cout << '{' << arr[pivotIndex] << '}'; Vector::print(arr, pivotIndex + 1, high); cout << endl;
        return pivotIndex;
    }

    void quickSort(int* arr, int low, int high) {
        if (high > low) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
};

