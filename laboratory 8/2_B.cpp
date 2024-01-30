#include <iostream>
using namespace std;


long long binarySearchRight(long long mas[], long long value, long long n) {
    long left = -1;
    long right = n;

    while(right - left > 1) {
        long mid = (left + right) / 2;
        if(mas[mid] <= value) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}


long long findPosled(long long mas[], long long n) {
    long long endingPosled[n];
    long long lengthMax = 0, i;

    endingPosled[0] = -100000000000;
    for(i = 1; i < n; i++) {
        endingPosled[i] = 100000000000;
    }


    for(i = 0; i < n; i++) {
        long long j = binarySearchRight(endingPosled, mas[i], n);

        if(endingPosled[j-1] < mas[i] && endingPosled[j] > mas[i]) {
            endingPosled[j] = mas[i];
            lengthMax = max(lengthMax, j);
        }
    }

    return lengthMax;
}


int main () {
    long long n, i; cin >> n;

    long long masElem[n];
    for(i = 0; i < n; i++) {
        cin >> masElem[i];
    }

    cout << findPosled(masElem, n);
}