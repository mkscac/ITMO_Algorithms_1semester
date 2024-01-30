#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


struct Node {
    long long numb = 0;
    long long basis = 0;
};


void siftUp(vector<Node> &mas, int i) {
    while(mas[i].numb < mas[(i - 1) / 2].numb) {
        swap(mas[i], mas[(i-1)/2]);
        i = (i-1)/2;
    }
}


void siftDown(vector<Node> &mas, int i) { ///итеративная реализация, i - элемент
    while((2 * i + 1) < mas.size()) {
        long long left = 2*i + 1, right = 2*i + 2, j = left;

        if((right < mas.size()) && (mas[right].numb < mas[left].numb)) {
            j = right;
        }
        if(mas[i].numb <= mas[j].numb) {
            break;
        }
        swap(mas[i], mas[j]);
        i = j;
    }
}


void insert(vector<Node> &mas, long long key, long long basis) {
    Node data;
    data.numb = key;
    data.basis = basis;

    if(mas.size() == 0) {
        mas.push_back(data);
    } else {
        mas.push_back(data);
        siftUp(mas, mas.size()-1);
    }
}


int extractMin(vector<Node> &mas) {
    long long min = mas[0].numb;
    mas[0] = mas[mas.size()-1];
    mas.pop_back();
    siftDown(mas, 0);
    return min;
}



int main() {
    cin.tie(0); ///для ускорения работы
    cout.tie(0);

    long long n = 0, i = 0; cin >> n;
    vector<Node> heapPrime;
    vector<bool> primeNumb(5000000, true);

    for(i = 2; i * i <= 5000000; i++) {
        if(primeNumb[i]) {
            for(int j = i * i; j <= 5000000; j += i)
                primeNumb[j] = false;
        }
    }


    for(i = 2; i <= 5000000; i++) {
        if((primeNumb[i]) && (heapPrime.size() < n)) {
            insert(heapPrime, i, i);
        }
    }

    vector<Node> dopHeap;

    long long countMnojit = 0;
    for(i = 0; i < n; i++) {
        long long basis = heapPrime[0].basis;
        long long value = extractMin(heapPrime);

        insert(dopHeap, basis, value);
        insert(heapPrime, (value*value), basis);

        countMnojit += int(log(value) / log(basis));
    }

    cout << countMnojit << "\n";


    for(i = 0; i < n; i++) {
        long long k = (long long)(log(dopHeap[0].basis) / log(dopHeap[0].numb));
        long long x = extractMin(dopHeap);
        while(k > 0) {
            cout << x << " ";
            k--;
        }
    }
}