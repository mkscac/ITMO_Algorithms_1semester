#include <iostream>
using namespace std;

// Разбиение по Хоара
void quicksort(int mas[], int left, int right) {
    int i = left, j = right, mid = (mas[left] + mas[right]) / 2;
    while(i <= j) {
        while(mas[i] < mid) {
            i += 1;
        }
        while(mas[j] > mid) {
            j -= 1;
        }

        if(i <= j) {
            swap(mas[i], mas[j]);
            i += 1;
            j -= 1;
        }
    }

    if(left < j) {
        quicksort(mas, left, j);
    }
    if(right > i) {
        quicksort(mas, i, right);
    }
}


int main() {
   int n = 0; cin >> n;
   int mas[n];

   for(int i = 0; i < n; i++) {
       cin >> mas[i];
   }

   quicksort(mas, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}