#include <iostream>
#include <queue>
using namespace std;


struct Node {
    long long data;
    Node *leftChild;
    Node *rightChild;
};



Node* insert(Node* root, Node* insertNode) {
    if(root == nullptr) {
        return insertNode;
    }
    else if (insertNode->data < root->data) {
        root->leftChild = insert(root->leftChild, insertNode);
    }
    else if (insertNode->data > root->data) {
        root->rightChild = insert(root->rightChild, insertNode);
    }
    return root;
}



void breadthTraversal(Node *root) {
    if(root == nullptr) {
        return;
    }

    queue<Node*> myQueue; ///приоритетная очередmь
    myQueue.push(root);

    while(!myQueue.empty()) {
        int levelSize = myQueue.size();
        Node *myRightNode = nullptr;

        for(int i = 0; i < levelSize; i++) {
            Node *current = myQueue.front();
            myQueue.pop();
            myRightNode = current;

            if(current->leftChild) {
                myQueue.push(current->leftChild);
            }
            if(current->rightChild) {
                myQueue.push(current->rightChild);
            }
        }

        if(myRightNode) {
            cout << myRightNode->data << " ";
        }
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long n = 0, i; cin >> n;
    Node *root = nullptr;


    for(i = 0; i < n; i++) {
        long long el; cin >> el;
        Node *appendNode = new Node;
        appendNode->data = el;
        root = insert(root, appendNode);
    }

    breadthTraversal(root);
}