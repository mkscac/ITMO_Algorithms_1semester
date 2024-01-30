#include <iostream>
using namespace std;

int partition(int mas[], int left, int right) { //разделение для быстрой сортировки
    int mid = mas[(left + right) / 2];
    int i = left, j = right;
    while(i <= j) {
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }
        if (i >= j) {
            break;
        }
        //swap(mas[i++], mas[j--]);
        int bufer = mas[j];
        mas[j] = mas[i];
        mas[i] = bufer;
        i++; j--;
    }
    return j;
}

void quicksort(int mas[], int left, int right, int kolvo, int daysAll) { //быстрая сортировка
    int countMas = daysAll; //размер масиива
    if(left < right) {
        int q = partition(mas, left, right);

        if(left <= countMas - kolvo) { //ограничение на рекурсивный спуск
            quicksort(mas, left, q, kolvo, countMas);
        }

        if(right >= countMas - kolvo) { //ограничение на рекурсивный спуск
            quicksort(mas, q + 1, right, kolvo, countMas);
        }

    }
}


int main() {
    int daysAll = 0, kolvo = 0; cin >> daysAll >> kolvo;
    int A = 0, B = 0, C = 0, a1 = 0, a2 = 0; cin >> A >> B >> C >> a1 >> a2;

    int mas[daysAll];
    mas[0] = a1; mas[1] = a2;

    for(int i = 2; i < daysAll; i++) { //заполение массива по формуле
        mas[i] = mas[i-2]*A + mas[i-1]*B + C;
    }

    quicksort(mas, 0, daysAll-1, kolvo, daysAll);


    int result = 0, zap = 0, k = 0, i = 0;
    while(k != kolvo) {
        result = (result ^ mas[daysAll-i-1]);
        i++; k++;
    }
    cout << result;
}