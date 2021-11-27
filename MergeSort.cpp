#include <vector>
#include <stdlib.h>
using namespace std;

/*
MERGE SORT
algortimi di ordinamento basato su DIVIDE ET IMPERA
2 indici p e r che individuano la porzione in cui operano --> A[p..r]
inizialmente 
    - p = 1
    - m = A.size()
    - q = (p + m)/2

1) Divide: divide l'array in 2 sottoarray A[p...q] e A[q+1...m] 
2) Impera(esegui): ordina i 2 sottoarray in modo ricorsivo utilizzando il Mergesort e se il problema 
è sufficentemente piccolo(0 o 1 elemento) lo risolve direttamente
3) Combina: fonde i 2 sottoarray ordinati e crea un array unico e ordinato
*/
void mergesort(vector<int> A, int p, int r){
    if(p < r){
        int q = (p+r)/2; //theta(1)
        mergesort(A, p, q); //theta(n/2)
        mergesort(A, q+1, r); //theta(n/2)
        merge(A, p, q, r); //theta(n)
    }
}

void merge(vector<int> A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    vector<int> L;  //dimensione [1...n1+1]
    vector<int> R;  //dimensione [1...n2+1]
    int i, j;       //dove la i è per la sx e j è per la dx

    for(i = 0; i < n1; i++){ //theta(n1)
        L.at(i) = A.at(p+i-1); 
    }
    for(j = 0; j < n2; j++){ //theta(n2)
        R.at(j) = A.at(q+j); 
    }
    
    //elementi sentinella --> non sono fondamentali 
    //questi valori(che sono dei +inf) mi permettono di avere la certezza di confrontare ed essere sempre maggiore
    L.at(n1+1) = _MAX_INT_DIG;
    R.at(n2+1) = _MAX_INT_DIG;

    i = 0;
    j = 0;
    for(int k = p; k < r; k++){ //theta(r-p+1) ==> theta(A.size()) ==> theta(n)
        if(L.at(i) <= R.at(j)){
            A.at(k) = L.at(i);
            i++;
        }else{
            A.at(k) = R.at(i);
            j++;
        }
    }
}

/*
CORRETTEZZA
la correttezza è determinata dall'invariante del ciclo 
A[p...r-1] contiene i r-p elementi ordinati, elementi più piccoli di L[1...n1+1] e R[1...n2+1]
L[i] e R[j] sono i più piccoli elementi dei loro sottoarray e NON COPIATI in A

alla fine del cilco k = r+1
inv[(r+1)/k] = sottoarray A[p...r-1] --> A[p...r-1+1] --> A[p...r]
contiene i (r+1)-p elemeti più piccoli di L e R 

L[i] e L[j] sono i più piccoli elementi dei loro sottoarray e NON COPIATI in A
non copio i valori sentinella all'interno di A!
*/

/*
COMPLESSITA
Complessità dell'algoritmo
T(n) = theta(n1 + n2) + theta(n) = 
= theta((q-p+1) + (r-q)) + theta(n) =
= theta(r-p+1) + theta(n) = theta(n) + theta(n) = theta(n)

la complessità è definita per casi
costante        n <= 1
2T(n/2) + d     n > 1
applicandoi il Master Theorem abbiamo che theta(n * log n) --> secondo caso f(n) == n^d
*/

/*
Vantaggi e svantaggi
vantaggi:
1. complessità: tetha(nlogn)
2. stabilità: gli elementi duplicati appaiono nell'array finale nello stesso ordine in cui erano nell'array originale

svantaggi:
1. non in loco: ha bisogno di strutture ausiliari nell'ordine di O(n)
2. non è sensibile all'ordinamento degli elementi --> tempo calcolo dipende solo dal numero di chiavi da ordinare
se abbiamo un array ordinato lo ordina di nuovo 
*/

