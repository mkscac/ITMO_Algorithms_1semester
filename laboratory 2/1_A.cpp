#include <iostream>
using namespace std;

int main() {
    int n = 0; cin >> n;
    int mas[n];
    for(int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    for(int j = 1; j < n; j++) {
        int key = mas[j];
        int i = j - 1;

        while(i >= 0 && mas[i] > key) {
            mas[i+1] = mas[i];
            i = i-1;
        }
        mas[i+1] = key;
    }


    for(int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}