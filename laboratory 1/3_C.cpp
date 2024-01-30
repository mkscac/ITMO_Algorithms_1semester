#include <iostream>
using  namespace std;

int main() {
    int konv = 0, orech = 0;
    cin >> konv >> orech;

    while(konv != orech) {
        if(konv > orech) {
            konv = konv - orech;
        }
        if(orech > konv) {
            orech = orech - konv;
        }
    }
    cout << konv;
}