#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
//struttura dati albero generico
struct Node {
    //value
    int key;        //Node's value 
    Node* p;        //Node's father
    Node* left;     //Node's child left 
    Node* right;    //Node's child right

    //costructor
    Node(int k, Node* padre, Node* sx = nullptr, Node* dx = nullptr)
        : key{ k }, p{ padre }, left{ sx }, right{ dx } {}
};

typedef Node* PNode;

struct Tree{
    PNode root;
    Tree(PNode r = nullptr)
        : root{ r } {}
};

typedef Tree* PTree;

//accedere al padre
PNode padre(PNode u) {
    return u->p;
}

//accedere ai figli
pair<PNode, PNode> figli(PNode u) {
    pair<PNode, PNode> ret;
    ret.first = u->left;
    ret.second = u->right;
    return ret;
}

//visita in pre ordine
void visitaPreordine(PNode u) {
    if (u != nullptr) {
        cout << u->key;
        visitaPreordine(u->left);
        visitaPreordine(u->right);
    }
}
//complessita theta(n)

//visita simmetrica
void visitaSimmetrica(PNode u) {
    if (u != nullptr) {
        visitaSimmetrica(u->left);
        cout << u->key;
        visitaSimmetrica(u->right);
    }
}
//complessita theta(n)

//visita in post ordine
void visitaPosticipata(PNode u) {
    if (u != nullptr) {
        visitaPosticipata(u->left);
        visitaPosticipata(u->right);
        cout << u->key;
    }
}
//complessita theta(n)

//stampa i nodi del livello k 
void stampaLivello(PNode u, int k) {
    if (u != nullptr) {
        if (k == 0) {
            cout <<u->key;
        }
        stampaLivello(u->left, k - 1);
        stampaLivello(u->right, k - 1);
    }
}
//complessita O(h)

