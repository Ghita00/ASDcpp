#include <vector>
#include <stdlib.h>
using namespace std;

/*
QUICKSORT
algoritmo di ordinamento basato sul DIVIDE ET IMPERA come il mergesort
su array di lunghezza A[p...r]
1) Divide: divide l'array in 2 sottoarray A[p...q] e A[q+1...m] anche eventualmente vuoti
tali che ogni elemento di A[p...q-1] <= A[q] <= A[q+1...r]

elemento A[q] --> pivot
è fondamentale per la procedura e al termine di essa sarà nella posizione giusta 
2) Impera(esegui): ordina i 2 sottoarray in modo ricorsivo utilizzando il Mergesort e se il problema 
è sufficentemente piccolo(0 o 1 elemento) lo risolve direttamente
3) Combina(TRIVALE): poichè i sottoarray sono ordinati sul posto, non occorre nessun lavoro per combinarli ==> A[p..r] ordinato! 

es:
3   -1  7   0   12  5
pivot ultimo elemento e lo mettiamo al centro
0   3   -1  5   12  7
ricorsivamente otteniamo...
-1  0   3   5   7   12
*/
void quicksort(vector<int> A, int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int partition(vector<int> A, int p, int r){
    int x = A[r];
    int i = p-1;
    int j;
    for(j = p; j<r-1; j++){ //esecuzione ciclo [r-1-p+1] --> theta(n) dove n = r-p+1 
        if(A.at(j) < x){
            i++;
            int aux = A.at(i);
            A.at(i) = A.at(j);
            A.at(j) = aux;
        }
    }
    int aux = A.at(i+1);
    A.at(i+1) = A.at(r);
    A.at(r) = aux;

    return i+1;
}
/*
CORRETTEZZA
la correttezza è determinata dall'invariante del ciclo 
x = per ogni k app [p,...,i], A[k] <= r and
    per ogni k app [i+1,...,j-1], A[k] > x and
    p <= j <= r and 
    p-1 <= i <= j-1
*/

/*
COMPLESSITA
la complessità theta(n)
questo perche abbiamo diviso l'array in 3 parti
    1. quelli <= r
    2. quelli >= r
    3. r(unico valore)
le ultime 2 righe hanno solo lo scopo di invertire il pivot(x) nella posizione corretta
così facendo partizioniamo l'array come richiesto
*/
