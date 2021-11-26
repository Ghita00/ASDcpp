#include <vector>
#include <stdlib.h>
using namespace std;
/*
INSERTION SORT
avere k elementi ordinati in testa e spostarsi con una variabile j per il resto non ordinato

tecnica incrementale: K elementi già ordinati e voglio estendere la proprietà ai K+1 elementi successivi
ordinamento in loco/sul posto: un algoritmo ordina sul posto se per ogni passo di computazione ALPIU' un numero
costante di elementi sono memorizzati al di fuori dell'array 

post condizione: array di n elementi ordinato

*/
void InsertionSort(vector<int> A){
    int j;
    for (j = 2; j < A.size(); j++){
        int key = A.at(j);
        int i = j-1;
        while(i > 0 && A.at(i) > key){
            A.at(i+1) = A.at(i);
            i = i-1;
        }
        A[i+1] = key;
    }
}
/*
La correttezza è determinata dall'invariante del ciclo 

*/

/*
Complessità secondo un teorema
l'algoritmo insertion sort ordina in loco n elementi eseguendo nel caso peggiore theta(n^2) confronti

dimostrazione:
ordina in loco perché ha solo un elemento è memorizzato al di fuori dell'input
il ciclo esterno è eseguito n-1 volte e nel caso peggiore j-1 volte 
se facciamo un cambio di variabile k = j-1

sommatoria da j=2 fino a n di j-1 = 
= sommatoria da J=1 fino a n-1 di k = [(n-1)(n-1+1)]/2 = [(n-1)n]/2 = theta(n^2)
n = A.size()

caso migliore = array già ordinato in senso non decrescente --> theta(n)
caso peggiore = array già ordinato in senso opposto --> theta(n^2)
*/