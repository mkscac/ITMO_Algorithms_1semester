#include <iostream>
using namespace std;

struct Node {
    long long data = 0;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;
};


Node* insertNode(long long data) {
    Node* node = new Node;
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}


Node *sortedArray(long long mas[], long long left, long long right) { /// каждый раз берем mid массива
    if(left > right) {
        return nullptr;
    }

    long long mid = (left + right) / 2;
    Node *root = insertNode(mas[mid]);

    root->leftChild = sortedArray(mas, left, mid-1);
    root->rightChild = sortedArray(mas, mid+1, right);
    return root;
}


void preorderTraversal(Node *root) { /// вызвваем от ноды
    if(root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->leftChild);
        preorderTraversal(root->rightChild);
    }
}


int main() {
    long long n = 0, i = 0; cin >> n;

    long long mas[n];
    for(i = 0; i < n; i++) {
        cin >> mas[i];
    }

    Node *root = sortedArray(mas, 0, n-1);
    preorderTraversal(root);
}