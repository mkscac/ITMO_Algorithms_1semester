#include <iostream>
using namespace std;

struct Node {
public:
    Node(int key, int indexNUMB) { //ячейка для эл-та. Число + ссылка + индекс
        this->key = key; // значение = длина доски
        this->indexNUMB = indexNUMB; //  индекс
        next = nullptr;
    }
    long long key;
    long long indexNUMB;
    Node* next;
};


class Stack {
public:
    Node* HEAD = nullptr; // голова

    void push(long long elem, long long ind) {
        Node* new_element = new Node(elem, ind); // создаем новую ячейку для элемента
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
        long long key = temp -> key;
        delete(temp);
        return key;
    }

    int viev_Index_Last_Day() {
        if(HEAD == nullptr) {
            return -1;
        }
        Node *temp;
        temp = HEAD;
        long long ind = temp -> indexNUMB;
        return ind;
    }


    int viev_Length_Last_Day() { // для просмотра длины доски - HEAD
        if(HEAD == nullptr) {
            return -1;
        }
        Node *temp;
        temp = HEAD;
        long long lenght = temp -> key;
        return lenght;
    }
};



int main() {
    cin.tie(0); //для ускорения работы
    cout.tie(0);

    Stack myStack;

    long long n = 0, i = 0; cin >> n;
    long long masBoardLength[n];
    for(i = 0; i < n; i++) {
        cin >> masBoardLength[i];
    }


    long long maxSquare = 0, currentSquare = 0, value = 0;
    i = 0;

    while(i < n) {
        if((myStack.viev_Index_Last_Day() == -1) || (masBoardLength[i] >= myStack.viev_Length_Last_Day())) { // пока стек пустой или i эл-т массива >= длины в стеке
            myStack.push(masBoardLength[i], i);
            i++;
        }
        else {
            value = myStack.viev_Length_Last_Day();
            myStack.pop();

            if(myStack.viev_Length_Last_Day() == -1) {
                currentSquare = i * value;
            } else {
                currentSquare = (i - myStack.viev_Index_Last_Day() - 1) * value;

            }

            if(maxSquare < currentSquare) {
                maxSquare = currentSquare;
            }
        }
    }



    while(myStack.viev_Length_Last_Day() != -1) { // пока элемент (длина) есть в стеке, он не пустой
        value = myStack.viev_Length_Last_Day();
        myStack.pop();

        if(myStack.viev_Length_Last_Day() == -1) {
            currentSquare = i * value;
        } else {
            currentSquare = (i - myStack.viev_Index_Last_Day() - 1) * value;
        }

        if(maxSquare < currentSquare) {
            maxSquare = currentSquare;
        }
    }

    cout << maxSquare;
    return 0;
}