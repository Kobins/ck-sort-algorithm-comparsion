#pragma once
#include "SortingAlgorithm.h"
class MergeSort : public SortingAlgorithm {
public:
    MergeSort() : SortingAlgorithm("MergeSort") {}

    virtual void sort(int* arr, int size) override {
        // 추가공간 할당
        int* extraSpace = new int[size];
        mergeSort(arr, extraSpace, 0, size - 1);
        delete[] extraSpace;
    }
private:

    void mergeSort(int* arr, int* extraSpace, int first, int last) {
        if (first < last) {
            int middle = (first + last) / 2;
            // 재귀호출해서 first >= last(size==1)일 때까지 분할

            mergeSort(arr, extraSpace, first, middle);
            mergeSort(arr, extraSpace, middle + 1, last);

            // 재귀호출들이 전부 반환되면, 분할된 두 부분배열을 병합 
            merge(arr, extraSpace, first, middle, last);
        }
    }
    void merge(int* arr, int* extraSpace, int first, int middle, int last) {
        // 함수 호출시 제공될 추가공간
        // 추가공간에 병합 후, 다시 그대로 원본배열에 복사할 예정
        int* sorted = extraSpace;

        // 반복할 용도로 사용할 변수들
        int first1 = first, last1 = middle;     // 왼쪽 부분배열
        int first2 = middle + 1, last2 = last;  // 오른쪽 부분배열
        int index = first; // 추가공간 index

        // 둘 중 하나 이상의 부분배열이 끝에 도달할때까지
        while (first1 <= last1 && first2 <= last2) {
            // 왼쪽과 오른쪽 부분배열 맨 앞 원소의 대소비교 후 추가공간에 삽입
            if (arr[first1] < arr[first2]) {
                sorted[index++] = arr[first1++];
            }
            else {
                sorted[index++] = arr[first2++];
            }
        }

        // 한 쪽이 먼저 다다랐을 경우, 나머지 부분배열 삽입
        while (first1 <= last1) {
            sorted[index++] = arr[first1++];
        }
        while (first2 <= last2) {
            sorted[index++] = arr[first2++];
        }
        // 추가공간 -> 원본배열 복사
        for (int i = first; i <= last; i++) {
            arr[i] = sorted[i];
        }
    }
};

