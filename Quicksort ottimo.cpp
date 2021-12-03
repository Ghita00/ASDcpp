#include <vector>
/*
QUICKSORT RANDOMIZZATO
questa variante permette:
    + aumentare le prestazioni segliendo casulamente il pivot 
    - non posso stabilire a priori il caso peggiore --> tutte avranno il caso medio
pivot : A[m] NO
pivot : A[p...r random] SI 

VANTAGGI
+ T(n) tempo di esecuzione
+ nessuna assunzione  
+ nessun input è il worst case(è determinato dal generatore) 
+ 3/4 volte più veloce del mergesort
*/

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

int randomazed_partion(vector<int> A, int p, int r){
    //speudo codice genero i random da [p, r]
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(p, r); // define the range

    int i = distr(gen); 
    int aux = A[i];
    A[i] = A[r];
    A[r] = aux;
    return partition(A, p, r);
}

void randomized_quicksort(vector<int> A, int p, int r){
    if(p < r){
        int q = randomazed_partion(A, p, r);
        randomazed_quicksort(A, p, q-1);
        randomazed_quicksort(A, q+1, r);
    }
}

/* OTTIMIZZAZIONI INSERTION SORT*/

/*
1. utilizzarlo su array di piccole dimensioni M ==> quick + insertion 
nuovo caso base
if(r-p <= M){
    insertionsort(A, p, r);
}
dove M è una costante 0 <= M <= 25

nuovo sort
void sort(vector<int> A, int p, int r){
    quicksort(A, p, r);
    insertionsort(A, p, r);
}
*/

/*
2. pivot come media di 3 elementi del vettore --> sx + centro + dx ==> la media la cambio con A[r]
*/

/*
3. chiavi duplicate: tripartizione
partition_primo(vector<int> A, int p, int r) --> permuta gli elementi di A[p..r] e restituisce 2 indici(q, t)
propietà degli indici: p <= q <= t <= r
A[q,..,t] = A[q]
A[p,..,q-1] < A[q]
A[t+1,..,m] > A[q]
tempo di computazione --> theta(r-p)
*/

/*
Vantiggi del quicksort
1.

*/

