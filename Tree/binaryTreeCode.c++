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
void searchNode(NodePointer aux, int number){
    if(aux==NULL){
        cout << "Empty tree!\n";
    }else if(number == aux->value){
        cout << "Number was found!!\n";
    }else if(number < aux->value){
        searchNode(aux->left, number);
    }else if(number > aux->value){
        searchNode(aux->right, number);
    }else{
        cout << "Number not found!\n";
    }
}
void listNodeInOrder(NodePointer p){
    if(p != NULL){
        listNodeInOrder(p->left);
        cout << "\t" << p->value;
        listNodeInOrder(p->right);
    }
}
void listNodeInPreOrder(NodePointer p){
    if(p != NULL){
        cout << "\t" << p->value;
        listNodeInOrder(p->left);
        listNodeInOrder(p->right);
    }
}
void listNodeInPostOrder(NodePointer p){
    if(p != NULL){
        listNodeInOrder(p->left);
        listNodeInOrder(p->right);
        cout << "\t" << p->value;
    }
}
int nodeTotal(NodePointer aux){
    if(aux == NULL) return 0;
    return(nodeTotal(aux->left)+1+nodeTotal(aux->right));
}
NodePointer greaterNode(NodePointer *p){
    NodePointer t;
    t=*p;
    if((t->right)==NULL){
        *p=(*p)->left;
        return(t);
    }else{
        return(greaterNode(&((*p)->right)));
    }
}
void remove(NodePointer *p, int number){
    NodePointer aux;
    if((*p) != NULL){
        if(number==(*p)->value){
            aux = *p;
            if(((*p)->left)==NULL)
                *p=(*p)->right;
            else    
                if(((*p)->right)==NULL)
                    *p=(*p)->left;
                else{
                    aux=greaterNode(&((*p)->left));
                    (*p)->value=aux->value;
                }
            delete(aux);
            cout << "\nO Elemento foi removido!!\n";
        }else{
            if(number<((*p)->value))
                remove(&((*p)->left),number);
            else
                remove(&((*p)->right),number);
        }
    }
}
void listNodes(NodePointer p){
    if(p!=NULL){
        cout << p->value;
        cout << "(";
        listNodes(p->left);
        listNodes(p->right);
        cout << ")";
    }
}
int main(){
    NodePointer root=newNode(35);
    addNewNode(&root, 25);
    addNewNode(&root, 10);
    addNewNode(&root, 30);
    addNewNode(&root, 28);
    addNewNode(&root, 50);
    addNewNode(&root, 40);
    addNewNode(&root, 65);
    searchNode(root, 65);
    listNodes(root);
    remove(&root, 35);
    listNodes(root);

    //cout << "\n" << nodeTotal(root);
    return 0;
}