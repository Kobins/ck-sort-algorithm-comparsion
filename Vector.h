#pragma once

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <memory>

using std::cout;
using std::endl;
using std::ostream;

class Vector {
    int* m_data;
    int m_size;
public:
    Vector(int size) : m_size(size) {
        m_data = new int[size];
        initRandomData();
    }
    ~Vector() {
        if (m_data) {
            delete[] m_data;
            m_data = nullptr;
        }
    }
    Vector(const Vector& copy) : m_size(copy.m_size) {
        m_data = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            m_data[i] = copy.m_data[i];
        }
    }
    Vector& operator=(const Vector& rhs) = delete;
    
    int* getData() const { return m_data; }
    int getSize() const { return m_size; }

    void initRandomData() {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = rand() % m_size;
        }
    }
    void initAscending() {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = i;
        }
    }
    void initDescending() {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = m_size - 1 - i;
        }
    }

    bool isSorted() {
        for (int i = 1; i < m_size; i++) {
            if (m_data[i - 1] > m_data[i]) {
                return false;
            }
        }
        return true;
    }

    void print() { print(m_data, m_size); }
    void print(int first, int last) { print(cout, m_data, first, last); }
    static void print(int* arr, int size) { print(cout, arr, 0, size - 1); }
    static void print(ostream& os, int* arr, int first, int last) {
        for (int i = first; i <= last; i++) {
            if (i != 0 && i % 50 == 0) {
                os << std::setw(10) << '[' << i << ']' << endl;
            }
            os << std::setw(5) << arr[i];
            /*if (i < last) {
                os << ", ";
            }*/
        }

    }
    friend ostream& operator<<(ostream& os, const Vector& v) {
        v.print(os, v.getData(), 0, v.getSize() - 1);
        return os;
    }

};

