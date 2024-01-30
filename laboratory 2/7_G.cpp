#include <iostream>
using namespace std;

void quicksort_2_stolbec(long long rejtingFilma[][2], int left, int right) { //быстрая сортировка
    int i = left, j = right, mid = (rejtingFilma[left][1] + rejtingFilma[right][1]) / 2;
    while(i <= j) {
        while(rejtingFilma[i][1] < mid) {
            i += 1;
        }
        while(rejtingFilma[j][1] > mid) {
            j -= 1;
        }
        if(i <= j) {
            swap(rejtingFilma[i][1], rejtingFilma[j][1]);
            swap(rejtingFilma[i][0], rejtingFilma[j][0]);
            i += 1;
            j -= 1;
        }
    }
    if(left < j) {
        quicksort_2_stolbec(rejtingFilma, left, j);
    }
    if(right > i) {
        quicksort_2_stolbec(rejtingFilma, i, right);
    }
}


void quicksort_1_stolbec(long long rejtingFilma[][2], int left, int right) { //быстрая сортировка
    int i = left, j = right, mid = (rejtingFilma[left][0] + rejtingFilma[right][0]) / 2;
    while(i <= j) {
        while(rejtingFilma[i][0] < mid) {
            i += 1;
        }
        while(rejtingFilma[j][0] > mid) {
            j -= 1;
        }
        if(i <= j) {
            swap(rejtingFilma[i][0], rejtingFilma[j][0]);
            swap(rejtingFilma[i][1], rejtingFilma[j][1]);
            i += 1;
            j -= 1;
        }
    }
    if(left < j) {
        quicksort_1_stolbec(rejtingFilma, left, j);
    }
    if(right > i) {
        quicksort_1_stolbec(rejtingFilma, i, right);
    }
}


int main() {
    int n = 0;
    cin >> n;

    long long mas[n][2];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> mas[i][j];
        }
    }

    quicksort_2_stolbec(mas, 0, n-1);
    quicksort_1_stolbec(mas, 0, n-1);


//    for(int i = 0; i < n; i++) { //пробный вывод массива
//        for(int j = 0; j < 2; j++) {
//
//            cout << mas[i][j] << " ";
//        }
//        cout << "\n";
//    }


    long long MaxSummaBallov = 0, summaZapomin = 0;
    for(int i = 0; i < n; i++) {
        summaZapomin += mas[i][0];
        MaxSummaBallov += mas[i][1] - summaZapomin;
    }
    cout << MaxSummaBallov;
}