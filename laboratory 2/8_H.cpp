#include <iostream>
using namespace std;

int main() {
    long long n = 0, i = 0; cin >> n;
    long long masMoney[n];

    for(i = 0; i < n; i++) {
        cin >> masMoney[i];
    }

    bool end = false;
    while(!end) { // сортируем массив, пока не закончились итерации прохода по массиву. Не знаем сколько раз
        end = true;

        for(i = 0; i < n - 1; i++) {
            long long a = masMoney[i];
            long long b = masMoney[i+1];
            if (a > b) {
                end = false;
                masMoney[i] = b + 1;
                masMoney[i+1] = a - 1;
                if ((a - 1 < 0) || (a - 1 == b)) { //нет денег у человека || при перестановке местами лучше не стало
                    cout << ":(";
                    return 0;
                }
            }
        }
    }


    for (i = 0; i < n; i++) {
        cout << masMoney[i] << " ";
    }
}