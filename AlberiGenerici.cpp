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

//visita anticipata in profondità
void visitaProfondita(PNode u) {
    if (u != nullptr) {
        cout << u->key;
        visitaProfondita(u->left);
        visitaProfondita(u->right);
    }
}
//complessità theta(n)

//visità posticipata in ampiezza
void visitaAmpiezza(PNode u) {
    if (u != nullptr) {
        visitaAmpiezza(u->left);
        cout << u->key;
        visitaAmpiezza(u->right);
    }
}
//complessità theta(n)

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
//complessità O(h)

