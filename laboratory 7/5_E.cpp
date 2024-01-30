#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Segment {
    double leftBorder = 0;
    double rightBorder = 0;
};


Segment *defineSegments(vector<char> letters, vector<double> probability, int m) {
    Segment* segment = new Segment[m];
    double l = 0;

    for(int i = 0; i < m; i++) {
        segment[letters[i]].leftBorder = l;
        segment[letters[i]].rightBorder = l + probability[i];
        l = segment[letters[i]].rightBorder;
    }
    return segment;
}


double arithmeticCoding(vector<char> letters, vector<double> probability, string s, int m) {
    Segment *segment = defineSegments(letters, probability, m);
    double left = 0, right = 1;

    for(long long i = 0; i < s.length(); i++) {
        char symb = s[i];

        double newRight = left + (right-left) * segment[symb].rightBorder;
        double newLeft = left + (right-left) * segment[symb].leftBorder;
        left = newLeft;
        right = newRight;
    }
    delete(segment);
    return left;
}



int main() {
    string message; cin >> message;
    int i = 0;

    int alphMas[26];
    for(i = 0; i < 26; i++) {
        alphMas[i] = 0;
    }

    for(i = 0; i < message.length(); i++) { /// заполняем количество букв в алфавите
        alphMas[(int)message[i]-97] += 1;
    }


    vector<double> probability;
    vector<char> letters;
    int m = 0;
    for(i = 0; i < 26; i++) { /// заполняем вероятности
        if(alphMas[i] != 0) {
            probability.push_back((double)alphMas[i] / (double)message.length());
            letters.push_back(char(i+97));
            m++;
        }
    }


    double ans = arithmeticCoding(letters, probability, message, m);
    cout << fixed << setprecision(6) << ans;


    /*
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);
    cout << arithmeticCoding(letters, probability, message, m);

    cout << setprecision(6) << fixed;
    cout << setprecision(6) << arithmeticCoding(letters, probability, message, m);
     */
}