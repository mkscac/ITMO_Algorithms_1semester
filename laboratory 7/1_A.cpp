#include <iostream>
#include <string>
using namespace std;


int main() {
    int n = 0, i; cin >> n;

    int mas[n];
    for(i = 0; i < n; i++) {
        mas[i] = 0;
    }


    for(i = 0; i < (pow(2,n)); i++) {
        int numb = i, j = n-1;

        while(numb != 0) {
            mas[j--] = numb % 2;
            numb = numb / 2;
        }


        cout << mas[0];
        for(int k = 1; k < n; k++) {
            if(mas[k-1] == 1) {
                if(mas[k] == 1)
                    cout << 0;

                else if(mas[k] == 0)
                    cout << 1;
            }
            else {
                cout << mas[k];
            }
        } cout << "\n";
    }
}