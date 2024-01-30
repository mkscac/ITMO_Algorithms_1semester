#include <iostream>
#include <cmath>
using namespace std;


struct Node {
public:
    Node(int key, int numberDays) { //ячейка для эл-та. Число + ссылка
        this->key = key;
        this->numberDays = numberDays;
        next = nullptr;
    }
    int key;
    int numberDays;
    Node* next;
};


class Stack {
public:
    Node* HEAD = nullptr; // голова

    void push(int elem, int day) {
        Node* new_element = new Node(elem, day); // создаем новую ячейку для элемента
        new_element -> next = HEAD; // ссылка на след. эл-т = голова
        HEAD = new_element; // голова = новый элемент
    }

    int pop() {
        if(HEAD == nullptr) {
            return -1;
        }
        Node *temp;
        temp = HEAD;
        HEAD = temp -> next;
        int key = temp -> key;
        delete(temp);
        return key;
    }

    int vievNumbLastDay() {
        if(HEAD == nullptr) {
            return -1;
        }
        Node *temp;
        temp = HEAD;
        int day = temp -> numberDays;
        return day;
    }
};



int main() {
    cin.tie(0); //для ускорения работы
    cout.tie(0);

    Stack myStack;

    int n = 0, i = 0, j = 0, s = 0; cin >> n;

    int masDays[n];
    for(i = 0; i < n; i++) { //заполнение массива сложностью задач
        int el = 0; cin >> el;
        masDays[i] = el;
    }


    int masTask[n];
    for(j = 0; j < n; j++) { //заполняем сначала -1
        masTask[j] = -1;
    }


    for(i = n-1; i >= 0; i--) { // идем по номерам дня
        int numberDay = myStack.vievNumbLastDay();
        int elementHard = myStack.pop();

        while((masDays[i] >= elementHard) && (elementHard != -1)) { //если элемент в стеке меньше чем элемент в массиве
            numberDay = myStack.vievNumbLastDay();
            elementHard = myStack.pop();
        }

        if(elementHard > 0) { //если стек не пустой
            masTask[i] = numberDay - (i+1);
            myStack.push(elementHard, numberDay);
            myStack.push(masDays[i], i+1);
        } else {
            myStack.push(masDays[i], i+1);
        }
    }



    for(i = 0; i < n; i++) {
        cout << masTask[i] << " ";
    }
}