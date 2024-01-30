#include <iostream>
#include <vector>
using namespace std;


struct Node {
    long long ZP = 0;
    long long poslednTimeWork = 0;
};


void siftUp(vector<Node> &mas, int i) {
    while(mas[i].ZP < mas[(i - 1) / 2].ZP) {
        swap(mas[i], mas[(i-1)/2]);
        i = (i-1)/2;
    }
}


void siftDown(vector<Node> &mas, int i) { ///итеративная реализация, i - элемент
    while((2 * i + 1) < mas.size()) {
        long long left = 2*i + 1, right = 2*i + 2, j = left;

        if((right < mas.size()) && (mas[right].ZP < mas[left].ZP)) {
            j = right;
        }
        if(mas[i].ZP <= mas[j].ZP) {
            break;
        }
        swap(mas[i], mas[j]);
        i = j;
    }
}


int extractMin(vector<Node> &mas) {
    long long min = mas[0].ZP;
    mas[0] = mas[mas.size()-1];
    mas.pop_back();
    siftDown(mas, 0);
    return min;
}


void insert(vector<Node> &mas, long long key, long long time) {
    Node data;
    data.ZP = key;
    data.poslednTimeWork = time;

    if(mas.size() == 0) {
        mas.push_back(data);
    } else {
        mas.push_back(data);
        siftUp(mas, mas.size()-1);
    }
}




int main() {
    int chefCount = 0, zakazAll = 0, i = 0;
    cin >> chefCount >> zakazAll;

    long long result = 0;

    vector<Node> freeChef;
    vector<Node> workChef;


    for(i = 0; i < chefCount; i++) {
        long long zp = 0; cin >> zp;
        insert(freeChef, zp, 0);
    }



    for(i = 0; i < zakazAll; i++) {
        long long poluchZakaz = 0, timeCook = 0;
        cin >> poluchZakaz >> timeCook;


        if(workChef.size() > 0) {
            while((workChef[0].ZP <= poluchZakaz) && (workChef.size() > 0)) { /// переносим заказы в людей, которые свободные
                long long zp = workChef[0].poslednTimeWork;
                long long time = extractMin(workChef);
                insert(freeChef, zp, time);
            }
        }

        if(freeChef.size() > 0) { /// свободные люди - с ними вычисления
            if(freeChef[0].poslednTimeWork <= poluchZakaz) {
                long long time = freeChef[0].poslednTimeWork;
                long long zp = extractMin(freeChef);
                result += zp * timeCook;

                insert(workChef, poluchZakaz+timeCook, zp);
            }
        }
    }
    cout << result;
}