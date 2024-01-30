#include <iostream>
using namespace std;

class Node {
public:
    long long key;
    Node* next;

    Node(long long numb) { // хранение элемента и ссылка на след эл-т, ячейка
        this->key = numb; // число
        this->next = nullptr; // ссылка на след эл-т
    }
};

class Stack {
    Node* HEAD;

public:
    Stack() {
        HEAD = nullptr;
    }

    void push(long long element) {
        Node* temp = new Node(element);

        temp->key = element;
        temp->next = HEAD; // ссылка на верхний указатель
        HEAD = temp;
    }

    bool isEmpty() {
        return HEAD == nullptr;
    }


    int peek() { // возврат верхнего элемента в стеке
        if (!isEmpty())
            return HEAD->key;
    }

    int pop() { // удаление элемента
        Node* temp;
        int element = 0;
        if (HEAD != nullptr) {
            temp = HEAD;
            element = HEAD -> key;
            HEAD = HEAD->next;
            free(temp);
        }
        return element;
    }
};


int main() {
    cin.tie(0); // ускорители кода
    cout.tie(0);

    Stack myStack;
    long long N = 0; cin >> N;

    //cout << endl;
    for(int i = 0; i < N; i++) {
        char index; cin >> index;

        if(index == '+') {
            long long numb; cin >> numb;
            myStack.push(numb);
        }
        else if(index == '-') {
            cout << myStack.pop() << "\n";
        }
    }
    return 0;
}