#include <iostream>
using namespace std;

void quicksort(long long mas[], long long left, long long right) { //быстрая сортировка, по Хоара
    long long i = left, j = right, mid = (mas[left] + mas[right]) / 2;
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
    long long mas[n];

    for(int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    quicksort(mas, 0, n-1);
//    for(int i = 0; i < n; i++) {
//        cout << mas[i] << " ";
//    } cout << "\n";

    long long ploshad = 0;
    for(int i = n-1; i >= 0; i--) {
        if((i+1)-4 >= 0 && mas[i] != NULL) {
            if(mas[i] == mas[i-1]) { //4 == 3
                if(mas[i-2] == mas[i-3]) { ploshad += mas[i] * mas[i-2]; i -= 3; } //2 == 1
                else if(mas[i-2]-1 == mas[i-3]) { ploshad += mas[i] * mas[i-3]; i -= 3; } //2-(1) == 1
                else {
                    for(int j = i-2; j >= 0; j--) { //если стоят не рядом - заменяем на NULL использованные
                        if(mas[j] == mas[j-1]) { ploshad += mas[i] * mas[j-1]; i--; mas[j] = NULL; mas[j-1] = NULL; break; } //2 == 1
                        else if(mas[j]-1 == mas[j-1]) { ploshad += mas[i] * mas[j-1]; i--; mas[j] = NULL; mas[j-1] = NULL; break; } //2-(1) == 1
                    }
                }
            }

            else if(mas[i]-1 == mas[i-1]) { //4-(1) == 3
                if(mas[i-2] == mas[i-3]) { ploshad += mas[i-1] * mas[i-2]; i -= 3; } //2 == 1
                else if(mas[i-2]-1 == mas[i-3]) { ploshad += mas[i-1] * mas[i-3]; i -= 3; }// 2-(1) == 1
                else {
                    for(int j = i-2; j >= 0; j--) { //если стоят не рядом - заменяем на NULL использованные
                        if(mas[j] == mas[j-1]) { ploshad += mas[i-1] * mas[j-1]; i--; mas[j] = NULL; mas[j-1] = NULL; break; } //2 == 1
                        else if(mas[j]-1 == mas[j-1]) { ploshad += mas[i-1] * mas[j-1]; i--; mas[j] = NULL; mas[j-1] = NULL; break; } //2-(1) == 1
                    }
                }
            }
        }
    }
    cout << ploshad;
}