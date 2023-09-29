# Problema dei cammini minimi
Possiamo dividere in tre varianti: 
- il cammino minimo da una **sorgente a tutti i nodi**
	- problema **base**
- il cammino minimo **tra due vertici**
	- si risolve con il **problema precendente**
- cammini minimi fra **tutte le coppie** di vertici
	- si risolve con **programmazione dinamica**


> [!info]- Pesi
> Ci sono varie tipologie, l'utilizzo o meno di numeri negativi, oppure la scelta fra interi o reali

> [!important]- NB
> I cicli negativi portano a ciclare su se stessi all'infinito

# Tipi di problema
## Cammino minimo, sorgente singola
##### Albero di copertura
Dato un grafo, il sotto grafo che comprende tutti i nodi ed è un albero, è definito albero di copertura

> [!info]- Teorema di Bellman
>Una soluzione è ottima se il costo di un nodo risulta unguale o inferiore alla somma del nodo precendete più il costo dell'arco

#### Generico
```
%vettore delle distanze
	int[N] d
% elemento precedente
	int[N] T 
% è inserito?
	boolean[N] b 
% inizializzo
	foreach u ∈ G.V() − {s} do  
		T [u] = nil  
		d[u] = +∞  
		b[u] = false
% nodo sorgente  
	T [s] = nil  
	d[s] = 0  
	b[s] = true


	while not S.isEmpty() do  
	(2) int u = S.extract()  
	b[u] = false  
	foreach v ∈ G.adj(u) do  
	if d[u] + G.w(u, v) < d[v] then  
	if not b[v] then  
	(3) S.add(v)  
	b[v] = true  
	else  
	(4) % Azione da svolgere nel caso v sia già presente in S  
	T [v] = u  
	d[v] = d[u] + G.w(u, v)  
	return (T, d)
```
#### Dijkstra
**Funziona solo con pesi positivi**
L'algoritmo funziona sfruttando code con priorità

L'algoritmo funziona sfruttando code con priorità:
1. Inizializzazione
	1. si imposta tutti gli elementi del vettore delle distanze a infinito
	2. si imposta il punto di partenza a 0
2. Esecuzione dell'algoritmo
	1. Si ricerca il minimo e lo visita
	3. Si somma il peso del nodo al costo degli archi che portano ai vicini
	4. Se il costo è minore del costo del nodo adiacente, si aggiorna il peso
	5. si visitano i nodi adiacenti

#### Bellman-Ford-Moore
Accetta pesi negativi, ma è più pesante:
1. Si crea una coda contenente il nodo di partenza
2. si calcola il peso dei nodi adiacenti
3. se è inferiore questi vengono inseriti nella coda
4. si passa all'elemento successivo

Il dettaglio è che nel momento in cui un nodo viene aggiornato con un peso inferiore, questo viene reinserito nella coda

##### Cicli negativi
Bellman ford raggiungere i cammini minimi in $n-1$ iterazioni, dove $n$ è il numero di vertici. Se alla $n$-esima iterazione c'è un miglioramento, questo determina la presenza di cicli negativi

#### Floyd-Warshall
##### Cammini k-vincolati
Rappresentati come $p_{xy}^k$, dove $x y$ sono i due vertici, sono i cammini che attraversano al massimo $k$ nodi tra i due vertici

Usando $d^k$ come matrice della distanza tra i nodi:
$$d^k[x][y]=\begin{cases}w(x,y) & k=0\\min(d^{k-1}[x][y],d^{k-1}[x][k]+d^{k-1}[k][y])&k>0\end{cases}$$
##### Algoritmo
Oltre a $d$ calcoliamo anche la matrice $T$ che conserva i predecessori del cammino minimo ($T[x][y]$ -> predecessore di $y$ del cammino minimo tra $x$ e $y$)

##### Chiusura transitiva
È il grafo $G^*$ derivato da $G$ dove è presente un arco tra due vertici solo se esiste un cammino tra i due in $G$

La matrice di adiacenza è denotata come $M^n$, definita come:
$$M^k[x][y]=\begin{cases}M[x][y] & k=0\\ M^{k-1}[x][y]\ or\ (M^{k-1}[x][k]\ and\ M^{k-1}[k][y])& k>0\end{cases}$$