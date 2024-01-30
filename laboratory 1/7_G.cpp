#include <iostream>
#include <string>
using namespace std;

int main() {
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N = 0;
        cin >> N;
        int minGraniza = 15, maxGraniza = 30;
        string el;
        int znach = 0;

        for (int n = 0; n < N; n++) {
            cin >> el >> znach;

            if (el == ">=") {
                if(znach >= minGraniza && znach <= maxGraniza && minGraniza <= maxGraniza) {
                    minGraniza = znach;
                    cout << minGraniza;
                }
                if(znach < minGraniza && minGraniza <= maxGraniza) {
                    cout << minGraniza;
                }
                if(znach > maxGraniza && minGraniza <= maxGraniza) {
                    //cout << -1;
                    minGraniza = znach;
                }
                if(minGraniza > maxGraniza) {
                    cout << -1;
                }
            }

            if (el == "<=") {
                if (znach >= minGraniza && znach <= maxGraniza && minGraniza <= maxGraniza) {
                    maxGraniza = znach;
                    cout << minGraniza;
                }
                if (znach > maxGraniza && minGraniza <= maxGraniza) {
                    cout << minGraniza;
                }
                if (znach < minGraniza && minGraniza <= maxGraniza) {
                    //cout << -1;
                    maxGraniza = znach;
                }
                if(minGraniza > maxGraniza) {
                    cout << -1;
                }
            }
            cout << "\n";
        }
    }
}