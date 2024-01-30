#include <iostream>
#include <vector>
using namespace std;


struct Node {
    long long key = 0;
    Node *leftChild = nullptr, *rightChild = nullptr;
    Node *parent = nullptr;
    int hight = 0;
};


int receivingHight(Node *currentNode) {
    if(currentNode == nullptr) {
        return -1;
    }
    else {
        return currentNode->hight;
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long n = 0, i = 0; cin >> n;

    vector<Node*> myTree;
    for(i = 0; i < n; i++) {
        Node *emptyNode = new Node;
        myTree.push_back(emptyNode);
    }


    for(i = 0; i < n; i++) {
        long long key, leftNumb, rightNumb;
        cin >> key >> leftNumb >> rightNumb;
        myTree[i]->key = key;

        if(rightNumb != 0) {
            myTree[i]->rightChild = myTree[rightNumb-1];
            myTree[i]->rightChild->parent = myTree[i];
        }
        if(leftNumb != 0) {
            myTree[i]->leftChild = myTree[leftNumb-1];
            myTree[i]->leftChild->parent = myTree[i];
        }


        if((leftNumb == 0) && (rightNumb == 0)) { /// у всех нод меняем высоты
            Node *temp =  myTree[i];

            while(temp->parent != nullptr) {
                int leftHight = receivingHight(temp->parent->leftChild);
                int rightHight = receivingHight(temp->parent->rightChild);

                if(max(leftHight, rightHight) >= receivingHight(temp->parent)) {
                    temp->parent->hight = max(leftHight, rightHight)+1;
                    temp = temp->parent;
                }
                else {
                    break;
                }
            }
        }
    }


    for(i = 0; i < n; i++) {
        cout << receivingHight(myTree[i]->rightChild) - receivingHight(myTree[i]->leftChild) << "\n";
    }
    return 0;
}