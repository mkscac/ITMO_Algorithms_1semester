#include <iostream>
#include <vector>
using namespace std;


struct Node {
    long long codeCity = 0;
    long long znachenie = 0; /// рейтинг или гонорар города
};


void siftUp(vector<Node> &mas, int i) {
    while((mas[i].znachenie > mas[(i-1)/2].znachenie) || ((mas[i].znachenie == mas[(i-1)/2].znachenie) && (mas[i].codeCity > mas[(i-1)/2].codeCity))){
        swap(mas[i], mas[(i-1)/2]);
        i = (i - 1)/2;
    }
}



void siftDown(vector<Node> &mas, int i) { ///итеративная реализация, i - элемент
    while((2 * i + 1) < mas.size()) {
        long long left = 2*i + 1, right = 2*i + 2, j = left;

        if(((right < mas.size()) && (mas[right].znachenie > mas[left].znachenie)) ||(mas[right].znachenie == mas[left].znachenie) && (mas[right].codeCity > mas[left].codeCity)) {
            j = right;
        }
        if((mas[right].znachenie != mas[left].znachenie) && (mas[i].znachenie >= mas[j].znachenie)) {
            break;
        }
        swap(mas[i], mas[j]);
        i = j;
    }
}


int extractMax(vector<Node> &mas) {
    long long max = mas[0].znachenie;
    mas[0] = mas[mas.size()-1];
    mas.pop_back();
    siftDown(mas, 0);
    return max;
}


void insert(vector<Node> &mas, long long code, long long key) {
    Node data;
    data.codeCity = code;
    data.znachenie = key;

    if(mas.size() == 0) {
        mas.push_back(data);
    } else {
        mas.push_back(data);
        siftUp(mas, mas.size()-1);
    }
}



int main() {
    long long n = 0, i = 0; cin >> n;
    vector<long long> call_CityCode; /// города, в которые звонили
    vector<long long> tour_CityCode; /// города, в которые едем на тур

    vector<Node> gonorarHeap;
    vector<Node> rejtHeap;


    for(i = 0; i < n; i++) { /// 2 макс кучи
        long long code = 0, rejt = 0, money = 0;
        cin >> code >> rejt >> money;

        insert(rejtHeap, code, rejt);
        insert(gonorarHeap, code, money);
    }


    long long countCall = 0; cin >> countCall; /// ответы на повышение гонорара
    vector<string> answerCall;
    for(i = 0; i < countCall; i++) {
        string el; cin >> el;
        answerCall.push_back(el);
    }



    long long indCall = 0;

    for(i = 0; i < n; i++) {
        if(rejtHeap[0].codeCity == gonorarHeap[0].codeCity) {
            tour_CityCode.push_back(rejtHeap[0].codeCity);
            extractMax(rejtHeap);
            extractMax(gonorarHeap);
        }
        else {
            if(countCall > 0) {
                if(answerCall[indCall] == "YES") {
                    call_CityCode.push_back(rejtHeap[0].codeCity);
                    tour_CityCode.push_back(rejtHeap[0].codeCity);
                    extractMax(rejtHeap);
                }
                else if(answerCall[indCall] == "NO") {
                    call_CityCode.push_back(rejtHeap[0].codeCity);
                    extractMax(rejtHeap);
                }
                indCall ++;
                countCall--;
            }
            else if(countCall == 0) {
                extractMax(rejtHeap);
            }
        }
    }


    /// вывод ответа
    for(i = 0; i < call_CityCode.size(); i++) {
        cout << call_CityCode[i] << " ";
    } cout << "\n";
    for(i = 0; i < tour_CityCode.size(); i++) {
        cout << tour_CityCode[i] << " ";
    }
}