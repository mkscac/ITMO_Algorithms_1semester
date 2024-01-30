#include <iostream>
using namespace std;

void siftDown(int mas[], int i, int n) { // итеративная реализация, i - элемент
    while((2 * i + 1) < n) {
        int left = 2*i + 1, right = 2*i + 2, j = left;

        if((right < n) && (mas[right] > mas[left])) {
            j = right;
        }
        if(mas[i] >= mas[j]) {
            break;
        }
        swap(mas[i], mas[j]);
        i = j;
    }
}


void siftUp(int mas[], int i) {
    while(mas[i] > mas[(i - 1) / 2]) {
        swap(mas[i], mas[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void heapCreate(int mas[], int n) { // создание дерева
    for(int i = 0; i < n; i++) {
        siftUp(mas, i);
    }
}


void heapSort(int mas[], int n) { // сортировка пирамидальная
    for(int i = n-1; i >= 0; i--) {
        swap(mas[0], mas[i]);
        siftDown(mas, 0, i);
    }
}



int main() {
    int n; cin >> n;

    int masZoloto[n];
    for(int i = 0; i < n; i++) {
        cin >> masZoloto[i];
    }


    heapCreate(masZoloto, n);

    heapSort(masZoloto, n);
    for(int i = 0; i < n; i++) {
        cout << masZoloto[i] << " ";
    }
}