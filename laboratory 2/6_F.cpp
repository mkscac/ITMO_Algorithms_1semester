#include <iostream>
#include <cmath>
using namespace std;

void quicksort(long long rejtingFilma[][2], long long left, long long right) { //быстрая сортировка
    long long i = left, j = right, mid = (rejtingFilma[left][1] + rejtingFilma[right][1]) / 2;
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
        quicksort(rejtingFilma, left, j);
    }
    if(right > i) {
        quicksort(rejtingFilma, i, right);
    }
}


int main() {
    long long countKritikov = 0, filmAll = 0, filmRejt = 0, i = 0, j = 0;
    cin >> countKritikov >> filmAll >> filmRejt;

    int avtoritetKritik[countKritikov]; //авторитетность критиков
    for (i = 0; i < countKritikov; i++) {
        cin >> avtoritetKritik[i];
    }


    long long rejtingFilma[filmAll][2]; //итоговый рейтинг фильма
    for (i = 0; i < filmAll; i++) {
        rejtingFilma[i][0] = i;
    }


    for (i = 0; i < filmAll; i++) {
        long long summaRejt1 = 0;
        long long stepen = pow(10, 9) + 7; // избежать переполенения

        for (j = 0; j < countKritikov; j++) {
            long long rejt = 0; cin >> rejt;
            summaRejt1 += (rejt * avtoritetKritik[j]);
            summaRejt1 = summaRejt1 % stepen;
        }
        rejtingFilma[i][1] = summaRejt1;
    }


    quicksort(rejtingFilma, 0, filmAll - 1);


    for(i = 0; i < filmAll; i++) { //если одинаковый рейтинг - упорядочить номера фильмов
        for(j = i+1; j < filmAll; j++) {
            if((rejtingFilma[i][1] == rejtingFilma[j][1]) && (rejtingFilma[i][0] < rejtingFilma[j][0])) {
                swap(rejtingFilma[i][1], rejtingFilma[j][1]);
                swap(rejtingFilma[i][0], rejtingFilma[j][0]);
            }
        }
    }

    int k = 0;
    for(i = filmAll-1; i >= 0; i--) {
        if(k != filmRejt) {
            cout << rejtingFilma[i][0] + 1 << " ";
            k++;
        }
    }
}