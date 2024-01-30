#include <iostream>
#include <vector>
using namespace std;


struct Node {
    long long data = 0;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;
};


class Stack {
public:
    int Head; // голова
    int sizeStack; // размер
    Node** array;
} stack;


Node* newNode(long long data) {
    Node* temp = new Node();
    temp->data = data;
    temp->leftChild = temp->rightChild = NULL;
    return temp;
}


Stack* createStack(long long size) {
    Stack* stack = new Stack();
    stack->Head = -1;
    stack->sizeStack = size;
    stack->array = new Node*[stack->sizeStack * sizeof( Node* )];
    return stack;
}


void push(Stack *stack, Node* numb) {
    if(stack->Head == stack->sizeStack - 1)
        return;
    stack->array[++stack->Head] = numb;
}


Node* pop(Stack *stack) {
    if(stack->Head == -1) //isEmpty
        return NULL;
    return stack->array[ stack->Head-- ];
}


Node* peek(Stack* stack) {
    return stack->array[stack->Head];
}


Node* constructBinTree(long long pre[], long long size) {
    Stack* stack = createStack(size);

    Node* root = newNode(pre[0]);
    push(stack, root);

    int i;
    Node* temp;

    for (i = 1; i < size; ++i) {
        temp = NULL;
        while(!(stack->Head == -1) && pre[i] >= peek( stack )->data) {
            temp = pop( stack );
        }

        if(temp != NULL) {
            temp->rightChild = newNode( pre[i] );
            push( stack, temp->rightChild );
        } else {
            peek( stack )->leftChild = newNode( pre[i] );
            push( stack, peek( stack )->leftChild);
        }
    }
    return root;
}


vector <long long> myMas;
void inorderTraversal(Node *root) {
    if(root != nullptr) {
        inorderTraversal(root->leftChild);
        myMas.push_back(root->data);
        inorderTraversal(root->rightChild);
    }
}


void postorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    postorderTraversal(root->leftChild);
    postorderTraversal(root->rightChild);
    myMas.push_back(root->data);
}


int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long n = 0, i = 0; cin >> n;

    long long array_all[n];
    for(i = 0; i < n; i++) { ///preorder
        cin >> array_all[i];
    }
    Node *root = constructBinTree(array_all, n);


    inorderTraversal(root);
    int k = 0;
    for(i = 0; i < n; i++) { ///inorder
        long long el; cin >> el;
        if(el != myMas[i]) {
            k = 1;
            cout << "NO";
            break;
        }
    }
    myMas.clear();


    postorderTraversal(root);
    if(k == 0) {
        for(i = 0; i < n; i++) { ///postorder
            long long el; cin >> el;
            if(el != myMas[i]) {
                k = 1;
                cout << "NO";
                break;
            }
        }
    }


    if(k == 0) {
        cout << "YES";
    }
}