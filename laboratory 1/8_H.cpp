#include <iostream>
using namespace std;

int main() {
    int n = 0; cin >> n;
    long long mas[n];

    for(int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    int peregorodkaCount = 0, peregorodka1 = 0, amount1 = 0, peregorodkaTekushMomentn = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if((mas[i] & mas[j]) != 0) {
                if(j > peregorodkaTekushMomentn) {
                    peregorodkaCount += 1;
                    peregorodkaTekushMomentn = j;
                    if(amount1 < 1) { peregorodka1 = j; amount1 += 1; }
                    break;
                }

                else if(j < peregorodkaTekushMomentn) {
                    peregorodkaTekushMomentn = j;
                    break;
                }


            }
            if(j == peregorodkaTekushMomentn) {
                break;
            }
        }
    }



    int amountPerv = 0;
    for(int i = peregorodkaTekushMomentn; i < n; i++) {
        amountPerv = 0;
        while(amountPerv != peregorodka1) {
            if((mas[i] & mas[amountPerv]) != 0) {
                peregorodkaCount += 1;
                amountPerv += 1;
                peregorodkaTekushMomentn = i;
                break;
            }
            amountPerv += 1;
        }
    }

    if(peregorodkaCount > 0) {
        cout << peregorodkaCount;
    } else {
        cout << 1;
    }
}