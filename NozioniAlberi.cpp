/*
Albero: è una coppia T = (N, A), dove:
N = insieme finito di nodi tra cui un nodo è definito radice
A = sotto ins di NxN e sono coppie di nodi chimate archi
in un albero ogni nodo a parte la radice ha esattamente un padre

terminologie:
Grado nodo ==> numero di figli del nodo
Nodo foglia ==> nodo che non ha figli
Nodo interno ==> nodo che ha almeno un figlio
Nodi fratelli ==> 2 nodi con lo stesso padre

Cammino su un albero: sequenza di nodi <n0...nk> con 
- u = n0 
- u_primo = nk
- <ni-1, ni> appartiene ad A per ogni i = 1,...,k
la lunghezza di un cammino è il numero degli archi 

Altezza di albero: è il numero di livelli di un albero 
NB: potrebbe essere diverso dall'altezza di un nodo
presa un nodo x che appartiene a T possiamo dire che 
    - profondita ==> lunghezza del cammino dalla radice al nodo x
    - altezza ==> lunghezza del cammino PIU LUNGO da u a una foglia
    - livello ==> l'insieme di tutti nodi alla stessa profondità

Nodo antenato: 
T --> albero
x --> nodo radicato in T
r --> radice di T
y è un nodo intermedio se si trova sul cammino tra x e r(verso l'alto)
Proprio: x != y

Nodo discendete
se y è un antenato di x, allora x è un discendente di y
Proprio: x != y

NB: ogni nodo è andatenato e discendete di se stesso ma in quel caso non è proprio

Albero binari --> definiti in modo ricorsivo
un albero vuoto è un albero binario
un albero costruito da un nodo radice, un albero binario radicato a sx e un albero binario radicato a dx
è un albero binario

Albero K-ario 
è un albero in cui i figlii di un nodo sono etichettati con interi positivi distinti 
e le etichette maggiori di k sono assenti

Albero K-ario completo
albero dove
1. tutte le foglie hanno la stessa profondità
2. tutti i nodi interni hanno esattamente grado k

Visite alberi
1. preordine --> visita la radice, sottoalbero sx e infine nel sottoalbero dx
2. simmetrica --> visita il sottoalbero sx, la radice e infine il sottoalbero dx
3. posticipata --> visita il sottoalbero sx, il sottoalbero dx e infine la radice
4. ampiezza --> guardo lv per lv

        A
    L       B
E       R       O
preordine = A L E R B O
simmetrica = E L R A B O
posticipata = E R L O B A 
ampiezza = A L B E R O
*/