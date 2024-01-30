#include <iostream>
using namespace std;


struct Node {
public:
    Node(int key) { //ячейка для эл-та. Число + ссылка
        this->key = key;
        next = nullptr;
    }
    int key;
    Node *next;
};


class List {
public:
    Node *HEAD = nullptr; // голова
    Node *TAIL = nullptr; // хвост - конец

    void push(int elem) {
        Node* new_element = new Node(elem); // создаем новую ячейку для элемента
        if(TAIL == nullptr) {
            HEAD = TAIL = new_element;
        } else {
            TAIL -> next = new_element; // ссылка на след. эл-т = хвост
            TAIL = new_element; // хвост = новый элемент
        }
    }


    int pop() {
        if(HEAD == nullptr) {
            return -1;
        }
        if(HEAD == TAIL) {
            TAIL = nullptr;
        }
        Node *temp;
        temp = HEAD;
        HEAD = HEAD -> next;

        int key = temp -> key;
        delete(temp);
        return key;
    }
};


int main() {
    cin.tie(0); //для ускорения работы
    cout.tie(0);

    List myStack;
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char index;
        cin >> index;

        if (index == '+') {
            int numb = 0;
            cin >> numb;
            myStack.push(numb);
        } else if (index == '-') {
            cout << myStack.pop() << "\n";
        }
    }
    return 0;
}