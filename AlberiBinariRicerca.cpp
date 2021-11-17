#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
un albero binario di ricerca è un qualsisi albero che deve rispettare la proprietà di ricerca
la proprità di ricerca dice che per ogni nodo u appartente all'albero deve avere
    1. nel sotto albero radicato a sx tutte le chiavi dei nodi devono essere <= a u->key
    2. nel sotto albero radicato a dx tutte le chiavi dei nodi devono essere >= a u->key

Teorema:
Le operazioni sugli ins dinamici search, minimum, maximum, predecessore, successore, l'inserimento e la delete possono essere 
realizzate nel tempo O(h) in un albero binario di ricerca, di altezza h, se fosse bilanciato l'albero sarebbero logn

obbiettivo: tenere bilanciato albero per implementare operazioni in tempo O(logn)

albero di riferimento per gli esempi 
                    15
            7               18
        3       10                  21
                                19      23
*/

//struttura dati albero binario di ricerca
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

struct Tree {
    PNode root;
    Tree(PNode r = nullptr)
        : root{ r } {}
};
typedef Tree* PTree;

//cerca un nodo in un albero
bool TreeSearch(PNode u, int k) {
    if (u == nullptr) {
        return false;
    }
    else if (u->key == k) {
        return true;
    }
    else {
        if (u->key > k) {
            return TreeSearch(u->right, k);
        }
        else {
            return TreeSearch(u->left, k);
        }
    }
}
//complessità O(h)

//cercare il nodo con il valore minimo
PNode TreeMinimum(PNode u) {
    while (u->left) {
        u = u->left;
    }
    return u;
}
//complessità O(h)

//cercare il nodo con il valore massimo
PNode TreeMaximum(PNode u) {
    while (u->right) {
        u = u->right;
    }
    return u;
}
//complessità O(h)


/*
cercare il successore di un nodo
Per predecessore si intende...
proposizione: dato un nodo con 2 figli il suo successore è un nodo che non ha il figlio sx
*/
PNode TreeSuccessor(PNode u) {
    if (u->right != nullptr) {
        return TreeMinimum(u->right); 
    }
    else {
        PNode v = u->p;
        while (v != nullptr && u == v->right) {
            u = v;
            v = v->p;
        }
        return v;
    }
}
//complessità O(h)

/*
cercare il predecessore di un nodo
Per predecessore si intende...
proposizione: dato un nodo con 2 figli il suo predecessore è un nodo che non ha il figlio dx
*/
PNode TreePredecessor(PNode u) {
    if (u->left != nullptr) {
        return TreeMaximum(u->left);
    }
    else {
        PNode v = u->p;
        while (v != nullptr && u == v->left) {
            u = v;
            v = v->p;
        }
        return v;
    }
}
//complessità O(h)

//inserimento di un nodo z in un albero t
PNode TreeInsert(PTree t, PNode z) {
    PNode padre = nullptr;
    PNode r = t->root;
    

    while (r != nullptr) {
        padre = r;
        if (z->key < r->key) {
            r = r->left;
        }
        else {
            r = r->right;
        }
    }
    
    padre->p = padre;
    //albero vuoto
    if (padre == nullptr) {
        t->root = z;
    }
    else {
        if (z->key <= padre->key) {
            padre->left = z;
        }
        else {
            padre->right = z;
        }
    }
}

/*cancellazione di un nodo
1. caso 1 --> foglia, faccio esplodere il figlio e sistemo il dx o sx del padre                         --> es 10 nel esempio
2. caso 2 --> unico filgio, faccio eslodere il nodo e sistemo il dx o sx del padre e attacco il figlio  --> es 18 nel esempio
3. caso 3 --> 2 figli con successore figlio di z, trovo e sostituisco con il succcessore y di z
4. caso 4 --> 2 figli ma con successore all'interno del sottoalbero
*/

/*operazione di utilità Trasplant(T, u, v)
sposta il sottoalbero con radice in v nella posizione del sotto albero in radice in u
            T                   v               T
        ...     u        +   ...     ... ==> ...     v
            ...     ...                         ...     ...
*/
void Trasplant(PTree T, PNode u, PNode v) { 
    if (u->p == nullptr) { //radice
        T->root = v;
    }
    else {
        //sostituisco u con v, il padre di u punta su v
        if (u == u->p->left) {
            u->p->left = v;
        }
        else {
            u->p->right = v;
        }
        //sistemo il padre di v
        if (u != nullptr) {
            v->p = u;
        }
    }
}
//complessità theta(1) in quanto sono solo assegnamenti

//funzione cardine per l'eleminazione
void TreeDelete(PTree T, PNode z) {     //precondizione z è in T
    if (z->left == nullptr) {           //1. z è una foglia oppure un solo nodo a dx
        //utilizzo la trasplant
        Trasplant(T, z, z->right);
    }
    else if (z->right == nullptr) {     //2. z è una foglia oppure un solo nodo a sx
       //utilizzo la trasplant
        Trasplant(T, z, z->left);
    }
    else {
        //3. z ha 2 figli
        PNode y = TreeMinimum(z->right);
        if (y->p != z) {                //4.situazione complessa, y all'interno del sottoalbero
            Trasplant(T, y, y->right);  //sostituisco y con il figlio destro
            y->right = z->right;        //accacco figlio destro di z...
            z->right->p = y;            //...e modifico il nodo
        }
        Trasplant(T, z, y);
        y->left = z->left;              //quello che era il figlio sx di z
        z->left->p = y;                 //sistemo il padre
    }
}
//complessita theta(h) 

//Costrzione di un albero binario di ricerca
//modo 1: spam di three insert

PTree buildBST(vector<int> A) { //A contiene chiavi da inserire nel notro albero
    PTree T(nullptr); //albero vuoto con etichetta T.root = NIL
    for (int i = 0; i < A.size(); i++) {
        PNode u = creaNodo(A[i]); //crea un nodo che mette sx,rx,p a NIL e key = A[i] --> O(h)
        TreeInsert(T, u);
    }
}
//complessità theta(n^2) per un albero completamente sbilanciato, per esempio l'input è ordinato --> catena!
//sommatoria con i = 0 fino a n-1 di (c + di) = cn + [d(n(n+1)) / 2] = theta(n^2)

/*Pre: A è ordinato*/
//posso partire dall'elemento contarle e costruisco in ricorsione 

PTree buildBST(vector<int> A) {
    PTree t = nullptr;
    t->root = buildBST_aux(A, 1, A.size(), nullptr); //poszioni finali, inziali dell'array e radice albero
    return t;
}

//restituisce il nodo radice dell'albero che sto creando
PNode buildBST_aux(vector<int> A, int inf, int sup, PNode padre) {
    //caso base
    if (inf > sup) {
        return nullptr;
    }
    else {
        int med = (inf + sup) / 2;
        PNode radice = creaNodo(A[med]);
        radice->p = padre;
        radice->left = buildBST_aux(A, inf, med - 1, radice);
        radice->right = buildBST_aux(A, med + 1, sup, radice);
        return radice;
    }
}

PNode creaNodo(int k) {
    PNode newNode(k); //TODO come si istanza?
    return newNode;
}
//complessità theta(n*logn)