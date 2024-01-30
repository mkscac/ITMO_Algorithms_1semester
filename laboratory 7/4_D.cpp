#include <iostream>
#include <string>
using namespace std;


int main() {
    long long n = 0, i; cin >> n;

    string message;
    for(i = 0; i < n; i++) {
        cin >> message;

        long long pozCurrent = 0, stepen = 0;
        long long positionError = 0;


        while(pozCurrent < message.length()) {
            long long summaXOR = 0, k = 0;
            bool flag = false;

            for(int j = pozCurrent; j < message.length(); j++) {
                if(k != pozCurrent+1) {
                    if(flag != false && message[j] == '1') {
                        summaXOR++; /// можно поменять на ++
                    }
                    k++;
                }
                else if(k == pozCurrent+1) {
                    j += (k-1);
                    k = 0;
                }
                flag = true;
            }

            //cout << pozCurrent << ": " << summaXOR % 2 << " " << message[pozCurrent] << " - ";

            if((summaXOR % 2 == 0) && (message[pozCurrent] == '1')) {
                positionError += pozCurrent+1;
            }
            else if((summaXOR % 2 == 1) && (message[pozCurrent] == '0')) {
                positionError += pozCurrent+1;
            }

            //cout << positionError << "\n";

            pozCurrent = pow(2, ++stepen)-1;
        }


        if(positionError != 0) {
            if(message[positionError-1] == '0') {
                message[positionError-1] = '1';
            } else {
                message[positionError-1] = '0';
            }
        }



        long long levelCOUT = 0, step = 0, s;
        for(s = 0; s <  message.length(); s++) {
            if(s != levelCOUT) {
                cout << message[s];
            }
            else if(levelCOUT < message.length()) {
                levelCOUT = pow(2, ++step)-1;
            }
        }
        cout << "\n";
    }
}



/*
1
0000101011011

1
11100010111010101011000101001

1
11010001

1
1101000100000001000000000000000100000000000000000000000000000001000
 */