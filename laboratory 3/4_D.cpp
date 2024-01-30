#include <iostream>
#include <algorithm>
using namespace std;

int max1el(long long a, long long b, long long c) {
    long long mas[] = {a, b, c};
    sort(mas, mas+3);
    return mas[2];
}

int max2el(long long a, long long b, long long c) {
    long long mas[] = {a, b, c};
    sort(mas, mas+3);
    return mas[1];
}


void change(long long mas[], int n) {
    int elV = mas[0];
    for(int i = 0; i < n; i++) {
        mas[i] = mas[i+1];
    }
    mas[n-1] = elV;
}


int main() {
    int n = 0, rucksackN = 0, i = 0;
    cin >> n >> rucksackN;

    long long gold[n];
    for(i = 0; i < n; i++) {
        cin >> gold[i];
    }


    if(n > rucksackN) {
        long long rucksackMas[rucksackN];
        for(i = 0; i < rucksackN; i++) {
            rucksackMas[i] = gold[i];
        }

///        for(int j = 0; j < rucksackN; j++) { // проверка ответа
///            cout << rucksackMas[j] << " ";
///        } cout << "\n";


        for(i = rucksackN; i < n; i++) {
            long long elM1 = max1el(rucksackMas[0], rucksackMas[rucksackN-1], gold[i]);
            long long elM2 = max2el(rucksackMas[0], rucksackMas[rucksackN-1], gold[i]);
            change(rucksackMas, rucksackN);

            rucksackMas[rucksackN-2] = elM2;
            rucksackMas[rucksackN-1] = elM1;


///            cout << elM1 << " " << elM2 << " -- "; // проверка ответа
///            for(int j = 0; j < rucksackN; j++) {
///                cout << rucksackMas[j] << " ";
///            } cout << "\n";
        }
        for(int j = 0; j < rucksackN; j++) { // ОТВЕТ
            cout << rucksackMas[j] << " ";
        }


    } else { // Случай когда сокровищ <= максимальному количеству элементов в массиве
        long long rucksackMas[n];
        for(i = 0; i < n; i++) {
            rucksackMas[i] = gold[i];
        }

        for(int j = 0; j < n; j++) {
            cout << rucksackMas[j] << " ";
        }
    }
}