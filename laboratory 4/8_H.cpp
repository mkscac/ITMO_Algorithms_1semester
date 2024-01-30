#include <iostream>
#include <string>
using namespace std;

string mySum(string a, string b) {
    if((a[0] != '-') && (b[0] != '-')) { /// оба числа > 0
        if (a.size() < b.size()) { swap(a, b); }

        int j = a.size() - 1;
        for (int i = b.size() - 1; i >= 0; i--) {
            a[j] += (b[i] - '0');
            j--;
        }

        for (int i = a.size() - 1; i > 0; i--) {
            if (a[i] > '9') {
                int d = a[i] - '0';
                a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
                a[i] = (d % 10) + '0';
            }
        }

        if (a[0] > '9') {
            string k;
            k += a[0];
            a[0] = ((a[0] - '0') % 10) + '0';
            k[0] = ((k[0] - '0') / 10) + '0';
            a = k + a;
        }
        return a;
    }
    
    
    else if((a[0] == '-') && (b[0] == '-')) {
        if (a.size() < b.size()) { swap(a, b); }

        int j = a.size() - 1;
        for (int i = b.size() - 1; i > 0; i--) {
            a[j] += (b[i] - '0');
            j--;
        }

        for (int i = a.size() - 1; i > 1; i--) {
            if (a[i] > '9') {
                int d = a[i] - '0';
                a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
                a[i] = (d % 10) + '0';
            }
        }

        if(a[0] > '9') {
            string k;
            k += a[0];
            a[0] = ((a[0] - '0') % 10) + '0';
            k[0] = ((k[0] - '0') / 10) + '0';
            a = k + a;
        }
        return a;
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long n = 0, i = 0;
    cin >> n;

    string summaResult;
    bool flag = true;
    for(i = 0; i < n; i++) {
        if(flag) {
            cin >> summaResult;
            flag = false;
        } else {
            string element;
            cin >> element;
            summaResult = mySum(summaResult, element);
        }
    }
    cout << summaResult;
}