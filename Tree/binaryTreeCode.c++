#include <iostream>
using namespace std;
struct node{
    int value;
    struct node *right;
    struct node *left;
};
typedef struct node * NodePointer;
NodePointer newNode(int number){
    NodePointer p = new struct node();
    p->value = number;
    p->left = NULL;
    p->right = NULL;
    return p;
};
void addNewNode(NodePointer *nodeP, int number){
    if(*nodeP == NULL){
        *nodeP = new struct node();
        (*nodeP)->value = number;
        (*nodeP)->left = NULL;
        (*nodeP)->right = NULL;
    }else{
        if((*nodeP)->value == number){
            cout << "O valor que esta tentando inserir ja esta na arvore!";
        }else if(number>(*nodeP)->value){
            addNewNode(&((*nodeP)->right), number);
        }else{
            addNewNode(&((*nodeP)->left), number);
        }
    }
};
int main(){
    NodePointer root=newNode(35);
    addNewNode(&root, 25);
    cout << root->value;
    NodePointer p = root->left;
    cout << "\t" << p->value;
    return 0;
}