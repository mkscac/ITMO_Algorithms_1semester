#include <iostream>
using namespace std;


int main() {
    long long n = 0, i = 0; cin >> n;

    long long mas[n];
    for(i = 0; i < n; i++) {
        cin >> mas[i];
    }


    long long k = 0;
    for(i = 0; i < n; i++) {
        if(mas[0] > mas[i]) { // корень дерева НЕ должен быть больше всех остальных элементов
            k ++;
        }

        if((2*i+1 < n) && (2*i+2 < n)) { // не проверяем листья
            if((mas[2*i+1] < mas[i]) || (mas[2*i+2] < mas[i])) { // сыновья НЕ должны быть меньше родителей
                k++;
                break;
            }
        }
    }

    if(k > 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}