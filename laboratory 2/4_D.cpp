#include <iostream>
using namespace std;

int main() {
    int n = 0; cin >> n;

    int mas[n], i = 0;
    for(i; i < n; i++) {
        mas[i] = i+1;
    }

    for(i = 2; i < n; i++) {
        int bufer = mas[i];
        int indexPerestanovka = i/2;
        mas[i] = mas[indexPerestanovka];
        mas[indexPerestanovka] = bufer;
        //swap(mas[i], mas[i/2]); //код в 1 строчку
    }

    for(i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}