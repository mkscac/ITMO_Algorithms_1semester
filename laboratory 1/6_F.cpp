#include <iostream>
using namespace std;

int main() {
    long long n = 0; cin >> n;
    int mas[n];
    int summaAll = 0, summaDo = 0;

    for(int i = 0; i < n; i++) {
        int x = 0; cin >> x;
        mas[i] = x;
        summaAll += x;
    }

    for(int i = 0; i < n; i++) {
        summaAll -= mas[i];

        if(summaAll == summaDo) {
            cout << i;
            break;
        }
        summaDo += mas[i];

//        cout << i << " do " << summaDo << "\n";
//        cout << i << " all " << summaAll << "\n";
//        cout << "\n";

        if(i == n-1) {
            cout << -1;
        }
    }
