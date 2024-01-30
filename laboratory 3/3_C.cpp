#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int pozSimv = 0; // позиция просматриваемого символа

bool compare(const string &a, const string &b) {
    return a.substr(pozSimv) < b.substr(pozSimv);
}


int main() {
    int countMessage = 0, dlinaMessage = 0, bukvView = 0, i = 0;
    cin >> countMessage >> dlinaMessage >> bukvView;

    string Message[countMessage];
    for(i = 0; i < countMessage; i++) {
        cin >> Message[i];
    }

    pozSimv = dlinaMessage;

    for(i = 1; i <= bukvView; i++) {
        pozSimv --; // изменяется позиция просмотра символа
        sort(Message, Message + countMessage, compare);
    }


    for(i = 0; i < countMessage; i++) {
        cout << Message[i] << "\n";
    }
}