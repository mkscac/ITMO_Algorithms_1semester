#include <iostream>
#include <vector>
using namespace std;


void siftUp(vector<long long> &mas, int i) {
    while((mas[i] < mas[(i - 1) / 2]) && (i > 0)) {
        swap(mas[i], mas[(i-1)/2]);
        i = (i-1)/2;
    }
}


void siftDown(vector<long long> &mas, int i) { ///итеративная реализация, i - элемент
    while((2 * i + 1) < mas.size()) {
        long long left = 2*i + 1, right = 2*i + 2, j = left;

        if((right < mas.size()) && (mas[right] < mas[left])) {
            j = right;
        }
        if(mas[i] <= mas[j]) {
            break;
        }
        swap(mas[i], mas[j]);
        i = j;
    }
}


int extractMin(vector<vector<long long>> &mas, long long numberHeap) {
    if(mas[numberHeap].size() == 0) {
        return -1;
    }

    long long min = mas[numberHeap][0];
    mas[numberHeap][0] = mas[numberHeap][mas[numberHeap].size()-1];
    mas[numberHeap].pop_back();
    siftDown(mas[numberHeap], 0);
    return min;
}


void insert(vector<vector<long long>> &mas, long long key, long long numberHeap) {
    if(mas[numberHeap].size() == 0) {
        mas[numberHeap].push_back(key);
    } else {
        mas[numberHeap].push_back(key);
        siftUp(mas[numberHeap], mas[numberHeap].size()-1);
    }
}


void merge(vector<vector<long long>> &mas, long long numberHeap1, long long numberHeap2) {
    int i = 0;
    vector<long long> data;

    for(i = 0; i < mas[numberHeap1].size(); i++) {
        data.push_back(mas[numberHeap1][i]);
        siftUp(data, data.size()-1);
    }
    for(i = 0; i < mas[numberHeap2].size(); i++) {
        data.push_back(mas[numberHeap2][i]);
        siftUp(data, data.size()-1);
    }

    mas.push_back(data);
}


void create(vector<vector<long long>> &mas) {
    vector<long long> data;
    mas.push_back(data);
}


void decreaseKey(vector<vector<long long>> &mas, long long numberHeap, long long deleteElement, long long zamenaElement) {
    for(int i = 0; i < mas[numberHeap].size(); i++) {
        if(mas[numberHeap][i] == deleteElement) {
            mas[numberHeap][i] = zamenaElement;
            siftUp(mas[numberHeap], i);
            break;
        }
    }
}



int main() {
    cin.tie(0);
    cout.tie(0);

    vector<vector<long long>> myHEAP; /// вектор векторов - двумерный массив

    string dataZnachen;
    while(cin >> dataZnachen) {

        if(dataZnachen == "create") {
            create(myHEAP);
        }
        else if(dataZnachen == "insert") {
            long long numbHeap = 0, element = 0; cin >> numbHeap >> element;
            insert(myHEAP, element, numbHeap);
        }
        else if(dataZnachen == "extract-min") {
            long long numbHeap; cin >> numbHeap;
            long long x = extractMin(myHEAP, numbHeap);
            if(x == -1) {
                cout << '*' << "\n";
            } else {
                cout << x << "\n";
            }
        }
        else if(dataZnachen == "merge") {
            long long numbHeap1 = 0, numbHeap2 = 0; cin >> numbHeap1 >> numbHeap2;
            merge(myHEAP, numbHeap1, numbHeap2);
        }
        else if(dataZnachen == "decrease-key") {
            long long numbHeap = 0, delElem = 0, element = 0;
            cin >> numbHeap >> delElem >> element;
            decreaseKey(myHEAP, numbHeap, delElem, element);
        }
    }
}