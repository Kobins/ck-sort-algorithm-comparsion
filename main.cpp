#include <iostream>

#include "Timer.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
    // 시간 측정 객체
    Timer timer;
    srand(time(NULL));

    Vector random1(3000); // 0 ~ size - 1 사이의 임의 수로 초기화됨
    Vector random2(5000);
    Vector random3(10000);

    cout << "rand 3000 unsorted: " << endl;
    cout << random1 << endl;
    cout << "rand 5000 unsorted: " << endl;
    cout << random2 << endl;
    cout << "rand 10000 unsorted: " << endl;
    cout << random3 << endl << endl;

    // 정렬 알고리즘 객체
    SortingAlgorithm* algorithms[] = {
        new SelectionSort,
        new BubbleSort,
        new InsertionSort,
        new MergeSort,
        new QuickSort,
    };
    const int algorithmCount = sizeof(algorithms) / sizeof(SortingAlgorithm*);

    // 표 형태의 결과 표기용 배열
    clock_t** result = new clock_t*[algorithmCount];

    // 정렬 알고리즘마다 반복
    for (int i = 0; i < algorithmCount; i++) {
        SortingAlgorithm& algorithm = *algorithms[i];
        result[i] = new clock_t[9];

        cout << "==============================" << endl;
        cout << algorithm.getName() << endl;
        cout << "==============================" << endl;

        Vector v1(random1); // 처음에 생성한 임의 수 배열을 복사
        Vector v2(random2); // 따라서 모든 정렬 알고리즘이 같은 임의 수 배열을 정렬
        Vector v3(random3);
        
        // 임의 배열 정렬 시간 측정
        timer.reset();
        algorithm.sort(v1);
        result[i][0] = timer.check();
        cout << "rand 3000\t" << timer << endl;
        cout << v1 << endl; // print result

        timer.reset();
        algorithm.sort(v2);
        result[i][1] = timer.check();
        cout << "rand 5000\t" << timer << endl;
        cout << v2 << endl;

        timer.reset();
        algorithm.sort(v3);
        result[i][2] = timer.check();
        cout << "rand 10000\t" << timer << endl;
        cout << v3 << endl;
        
        // 오름차순 정렬된 배열로 채움
        v1.initAscending();
        v2.initAscending();
        v3.initAscending();
        cout << "asc 3000\t[" << v1.getData()[0] << " .. " << v1.getData()[v1.getSize() - 1] << "]" << endl;
        cout << "asc 5000\t[" << v2.getData()[0] << " .. " << v2.getData()[v2.getSize() - 1] << "]" << endl;
        cout << "asc 10000\t[" << v3.getData()[0] << " .. " << v3.getData()[v3.getSize() - 1] << "]" << endl;

        // 오름차순 배열 정렬 시간 측정
        timer.reset();
        algorithm.sort(v1);
        result[i][3] = timer.check();
        cout << "asc 3000\t" << timer << endl;

        timer.reset();
        algorithm.sort(v2);
        result[i][4] = timer.check();
        cout << "asc 5000\t" << timer << endl;

        timer.reset();
        algorithm.sort(v3);
        result[i][5] = timer.check();
        cout << "asc 10000\t" << timer << endl;

        // 내림차순 정렬된 배열로 채움
        v1.initDescending();
        v2.initDescending();
        v3.initDescending();

        cout << "desc 3000\t[" << v1.getData()[0] << " .. " << v1.getData()[v1.getSize() - 1] << "]" << endl;
        cout << "desc 5000\t[" << v2.getData()[0] << " .. " << v2.getData()[v2.getSize() - 1] << "]" << endl;
        cout << "desc 10000\t[" << v3.getData()[0] << " .. " << v3.getData()[v3.getSize() - 1] << "]" << endl;

        // 내림차순 배열 정렬 시간 측정
        timer.reset();
        algorithm.sort(v1);
        result[i][6] = timer.check();
        cout << "desc 3000\t" << timer << endl;

        timer.reset();
        algorithm.sort(v2);
        result[i][7] = timer.check();

        timer.reset();
        algorithm.sort(v3);
        result[i][8] = timer.check();
        cout << "desc 10000\t" << timer << endl;
    }

    // 표 형태 결과 출력
    const char* rows[] = {
        "rand 3000",
        "rand 5000",
        "rand 10000",
        "asc 3000",
        "asc 5000",
        "asc 10000",
        "desc 3000",
        "desc 5000",
        "desc 10000",
    };
    cout << setw(11) << ' ';
    for (int x = 0; x < algorithmCount; x++) {
        cout << setw(20) << algorithms[x]->getName();
    }
    cout << endl;
    for (int i = 0; i < 9; i++) {
        cout << setw(11) << rows[i];
        for (int x = 0; x < algorithmCount; x++) {
            cout << setw(18) << result[x][i] << "ms";
        }
        cout << endl;
    }

    // 메모리 해제
    for (int i = 0; i < algorithmCount; i++) {
        delete algorithms[i];
        delete[] result[i];
    }
    delete[] result;

    return 0;
}