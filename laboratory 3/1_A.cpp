#include <iostream>
using namespace std;


struct Node {
public:
    Node(int key) { //ячейка для эл-та. Число + ссылка
        this->key = key;
        next = nullptr;
    }
    int key;
    Node* next;
};


class Stack {
public:
    Node* HEAD = nullptr; // голова

    void push(int elem) {
        Node* new_element = new Node(elem); // создаем новую ячейку для элемента
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
};


int main() {
    cin.tie(0); //для ускорения работы
    cout.tie(0);

    Stack myStack;
    long long N = 0; cin >> N;

    for(int i = 0; i < N; i++) {
        char index; cin >> index;

        if(index == '+') {
            int numb; cin >> numb;
            myStack.push(numb);
        } else if(index == '-') {
            cout << myStack.pop() << "\n";
        }
    }
    return 0;
