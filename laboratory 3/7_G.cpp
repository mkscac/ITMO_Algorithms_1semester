#include <iostream>
using  namespace std;

void merge(long long mas[], int left, int mid, int right) { //сливает массив
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



void mergeSortRecursive(long long mas[], int left, int right) {
    if(left + 1 >= right) { return;}

    int mid = (left + right) / 2;
    mergeSortRecursive(mas, left, mid);
    mergeSortRecursive(mas, mid, right);
    merge(mas, left, mid, right);
}


int main() {
    int placeCount = 0, boyarCount = 0, i = 0, j = 0;
    cin >> placeCount >> boyarCount;

    long long masPlace[placeCount];
    for(i = 0; i < placeCount; i++) {
        cin >> masPlace[i];
    }

    mergeSortRecursive(masPlace, 0, placeCount); // сортировка координат


    long long left = 0, right = masPlace[placeCount-1] - masPlace[left], maxDistance = 0;
    while(left <= right) {
        long long mid = (left + right) / 2, pozPoslBoyar = masPlace[0], countBoyarPlace = 1; // mid - расстояние

        for(i = 0; i < placeCount; i++) {
            if(masPlace[i] - pozPoslBoyar >= mid) {
                countBoyarPlace ++;
                pozPoslBoyar = masPlace[i];
            }
        }

        if(countBoyarPlace >= boyarCount) {
            maxDistance = mid;
            left = mid+1; // если для всех бояр нашли место
        } else {
            right = mid-1; // если не для всех бояр нашли место
        }
    }
    cout << maxDistance;
}