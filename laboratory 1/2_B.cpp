#include <iostream>
using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    int mas[n];
    for(int i = 0; i < n; i++) { //ввод данных массива
        int numb;
        cin >> numb;
        mas[i] = numb;
    }

    k = k % n; //остаток, чтобы не делать куча раз сдвиг, тк будет одинаково если кол-во элементов = сдвигу
    int count = 0;
    while(count != k) {
        if(k > 0) {
            int elL = mas[n-1];
            for(int i = n-1; i >= 0; i--) {
                mas[i] = mas[i-1];
            }
            mas[0] = elL;
            count += 1;
        }

        if(k < 0) {
            int elV = mas[0];
            for(int i = 0; i < n; i++) {
                mas[i] = mas[i+1];
            }
            mas[n-1] = elV;
            count -= 1;
        }
    }


    for(int i = 0; i < n; i++) { //вывод массива - проверка
        cout << mas[i] << " ";
    }
}