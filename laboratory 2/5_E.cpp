#include <iostream>
using  namespace std;

void merge(long long mas[], int left, int mid, int right, long long &count) { //сливает массив
    /// ф-ция void не возвращает никакое значение, в отличие от int
    int it1 = 0, it2 = 0;
    long long result[right - left];


    while((left + it1 < mid) && (mid + it2 < right)) {
        if(mas[left + it1] <= mas[mid + it2]) {
            result[it1+it2] = mas[left + it1]; //из левого массива
            it1++;
        }
        else {
            result[it1+it2] = mas[mid + it2]; //из правого массива
            count += (mid-left) - it1;
            it2++;
        }
    }

    while(left + it1 < mid) { //доливаем левый хвост
        result[it1+it2] = mas[left + it1];
        it1++;

    }
    while(mid + it2 < right) { //доливаем правый хвост
        result[it1+it2] = mas[mid+it2];
        it2++;

    }

    for(int i = 0; i < it1+it2; i++) {
        mas[left+i] = result[i];
    }
}



void mergeSortRecursive(long long mas[], int left, int right, long long &count) {
    if(left + 1 >= right) { return;}

    int mid = (left + right) / 2;
    mergeSortRecursive(mas, left, mid, count);
    mergeSortRecursive(mas, mid, right, count);
    merge(mas, left, mid, right, count);
}


int main() {
    int n = 0; cin >> n;
    long long count = 0;
    long long mas[n];

    for(int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    mergeSortRecursive(mas, 0, n, count);
    cout << count;
}