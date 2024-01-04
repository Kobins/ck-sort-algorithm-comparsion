#pragma once

#include "Vector.h"
#include <memory>
#include <string>
#include <iostream>
using namespace std;

class SortingAlgorithm {
    string name;
protected:
    SortingAlgorithm(const string& name) : name(name) {}
public:
    // 배열 정렬
    virtual void sort(int* arr, int size) abstract;
    // Vector 내 배열에 대한 정렬 호출
    void sort(const Vector& vector) {
        sort(vector.getData(), vector.getSize());
    }
    // 정수 swap 함수
    inline void swap(int& n1, int& n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    // 출력용 알고리즘 이름
    const string& getName() const { return name; }
};

