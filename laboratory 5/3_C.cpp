#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long data = 0;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;
    Node *parent = nullptr;
};


void insert(Node *&root, Node *&insertNode) { /// корень поддерева + вставляемый элемент
    Node *index = root;

    while(index != nullptr) {
        if(insertNode->data > index->data) {
            if(index->rightChild != nullptr) {
                index = index->rightChild;
            }
            else {
                insertNode->parent = index;
                index->rightChild = insertNode;
                break;
            }
        }

        else if(insertNode->data < index->data) {
            if(index->leftChild != nullptr) {
                index = index->leftChild;
            }
            else {
                insertNode->parent = index;
                index->leftChild = insertNode;
                break;
            }
        }
    }

    if(index == nullptr) {
        root = new Node;
        root->data = insertNode->data;
    }
}


Node existsSearch(Node *&root, long long age) {
    Node *index = root;

    while(index != nullptr) {
        if(index->data != age) {
            if(age > index->data) {
                index = index->rightChild;
            }
            else if(age < index->data) {
                index = index->leftChild;
            }
        }
        else if(index->data == age) {
            return *index;
        }
    }
    if(index == nullptr) {
        Node *falseNode = new Node;
        falseNode->data = -1000000000;
        return *falseNode;
    }
}



Node minElement(Node *&root) {
    Node *index = root;

    if(index->leftChild == nullptr) {
        return *index;
    }
    return minElement(index->leftChild);
}



Node nextSearch_DEL(Node *&searchNode) {
    Node *index = searchNode;

    if(index->rightChild != nullptr) {
        return minElement(index->rightChild);
    }

    Node *elNode = index->parent;
    while(elNode != nullptr && index == elNode->rightChild) {
        index = elNode;
        elNode = elNode->parent;
    }
    return *elNode;
}



void pop(Node *&root, Node *&deleteNode) {
    Node *parent = deleteNode->parent;

    if((deleteNode->leftChild == nullptr) && (deleteNode->rightChild == nullptr)) { /// 1 случай - нет детей
        if(parent == nullptr) { /// только 1 элемент в дереве
            root = nullptr;
        }

        else {
            if((parent->leftChild != nullptr) && (parent->leftChild->data == deleteNode->data)) {
                parent->leftChild = nullptr;
            }
            else if((parent->rightChild != nullptr) && (parent->rightChild->data == deleteNode->data)) {
                parent->rightChild = nullptr;
            }
        }
    }


    else if((deleteNode->leftChild == nullptr) || (deleteNode->rightChild == nullptr)) { /// 2 случай - 1 ребенок

        if(root->data == deleteNode->data) { /// удаление корня
            if(root->leftChild == nullptr) {
                root = root->rightChild;
                root->parent = nullptr;
            }
            else if(root->rightChild == nullptr) {
                root = root->leftChild;
                root->parent = nullptr;
            }
        }


        else if(deleteNode->leftChild == nullptr) {
            if((parent->leftChild != nullptr) && (parent->leftChild->data == deleteNode->data)) {
                parent->leftChild = deleteNode->rightChild;
            }
            else {
                parent->rightChild = deleteNode->rightChild;
            }
            deleteNode->rightChild->parent = parent;
        }

        else if(deleteNode->rightChild == nullptr) {
            if((parent->leftChild != nullptr) && (parent->leftChild->data == deleteNode->data)) {
                parent->leftChild = deleteNode->leftChild;
            }
            else {
                parent->rightChild = deleteNode->leftChild;
            }
            deleteNode->leftChild->parent = parent;
            ///delete(deleteNode); //если не зайдет по памяти
        }
    }


    else { /// 3 случай - 2 ребенка
        if(parent == nullptr) { /// удаление корня
            Node *successor = new Node;
            *successor = nextSearch_DEL(deleteNode);

            root->data = successor->data;

            if(successor->parent->leftChild == successor) {
                successor->parent->leftChild = successor->rightChild;
                if(successor->rightChild != nullptr) {
                    successor->rightChild->parent = successor->parent;
                }
            }

            else if(successor->parent->rightChild == successor) {
                successor->parent->rightChild = successor->leftChild;
                if(successor->leftChild != nullptr) {
                    successor->leftChild->parent = successor->parent;
                }
            }
            root->parent = nullptr;
        }


        else if(parent != nullptr) {
            Node *successor = new Node;
            *successor = nextSearch_DEL(deleteNode);

            if((parent->leftChild != nullptr) && (parent->leftChild->data == deleteNode->data)) {
                parent->leftChild->data = successor->data;
            } else if((parent->rightChild != nullptr) && (parent->rightChild->data == deleteNode->data)) {
                parent->rightChild->data = successor->data;
            }


            if((successor->parent->leftChild != nullptr) && (successor->parent->leftChild->data == successor->data)) {
                successor->parent->leftChild = successor->rightChild;
                if(successor->rightChild != nullptr) {
                    successor->rightChild->parent = successor->parent;
                }
            }

            else if((successor->parent->rightChild != nullptr) && (successor->parent->rightChild->data == successor->data)) {
                successor->parent->rightChild = successor->rightChild;
                if(successor->rightChild != nullptr) {
                    successor->rightChild->parent = successor->parent;
                }
            }
        }
    }
}



int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    int n = 0, i = 0; cin >> n;
    Node *root = nullptr; /// корень дерева
    vector<long long> masMax;


    for(i = 0; i < n; i++) {
        int instruction = 0; long long numb = 0;
        cin >> instruction >> numb;

        if(instruction == 1) {
            if(existsSearch(root, numb).data == -1000000000) {
                Node *appendNode = new Node;
                appendNode->data = numb;
                insert(root, appendNode);

                masMax.push_back(numb);
            }
        }

        else if(instruction == -1) {
            Node *deleteNode = new Node;
            *deleteNode = existsSearch(root, numb);

            if(deleteNode->data != -1000000000) {
                pop(root, deleteNode);

                for(int j = 0; j < masMax.size()-1; j++) {
                    if(masMax[j] == numb) {
                        swap(masMax[j], masMax[masMax.size()-1]);
                        masMax.pop_back();
                        break;
                    }
                }
            }
        }

        else if(instruction == 0) {
            sort(masMax.begin(), masMax.end());
            cout << masMax[masMax.size()-numb] << "\n";
        }
    }
}