#include <iostream>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    string word; cin >> word;

    bool flag = true;

    for(int i = 0; i < n; i++) {
        if(i < (n-1-i)) {
            //cout << i << " " << (n-1)-i  << "\n";

            if(word[i] != word[(n-1)-i]) {
                if((word[i+1] == word[(n-1)-i]) || (word[(n-1)-i-1] == word[i])) {
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag == true) {
        cout << "YES";
    }
    if(flag == false) {
        cout << "NO";
    }
}