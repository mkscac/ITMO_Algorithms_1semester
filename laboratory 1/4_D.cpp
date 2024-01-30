#include <iostream>
using namespace std;

int main() {
    int sezon = 0, seria = 0, estSeria = 0; cin >> sezon >> seria >> estSeria;
    int mas[seria][sezon];

    for(int i = 0; i < seria; i++) {
        for(int j = 0; j < sezon; j++) {
            mas[i][j] = 0;
        }
    }

    for(int p = 0; p < estSeria; p++){
        int ser, sez; cin >> ser >> sez;
        mas[ser-1][sez-1] = 1;
    }

    int count = 0;
    for(int i = 0; i < seria; i++) {
        for(int j = 0; j < sezon; j++) {
            if(mas[i][j] == 0) {
                count += 1;
            }
        }
    }

    cout << count << "\n";

    for(int i = 0; i < sezon; i++) {
        for (int j = 0; j < seria; j++) {
            if(mas[j][i] == 0) {
                cout << j+1 << " " << i+1 << "\n";
            }
        }
    }
}