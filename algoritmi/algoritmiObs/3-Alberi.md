# Alberi generici
## Albero radicato
È un albero connesso con un nodo definito come radice, e ogni nodo ha un cammino unico per raggiungerlo

## Terminologia
Ogni radice forma sotto di se dei **sotto-alberi**, anch'essi con le loro radici. I nodi derivanti dallo stesso nodo (chiamato **padre**) sono definiti nodi **fratelli**, mentre i nodi sotto di loro sono definiti nodi **figli**. I nodi all'estremità dell'albero sono definiti **foglie**, mentre i restanti sono **nodi interni**

Definiamo come **profondità** la lunghezza del cammino dal nodo alla radice, e chiamiamo **livello** i nodi alla stessa profondità. La profondità massima di un albero è definita **altezza**

# Memorizzazione
## Vettore dei figli
In questo caso il nodo è composto da un puntatore al nodo padre (nullo se radice) e un vettore di puntatori ai nodi figli

## Primo figlio, prossimo fratello
Questo nodo alternativo è composto da un puntatore al nodo padre, un puntatore al primo nodo figlio, e un puntatore al prossimo fratello.
Questo richiede di navigare i fratelli come una lista di puntatori

## Vettore dei padri
Invece che trattare il nodo come una struttura dati a parte, si compone una matrice $2\times n$ (o vettore di tuple) dove assieme al valore si indirizza anche la posizione dell'elemento padre

> [!example]- esempio
> |A|B|C|D|E|
> |0|1 |1 |2|3|

# Alberi binari
Si tratta di alberi radicati con in cui ogni nodo ha al massimo due figli, definiti figlio **destro** e figlio **sinistro**

Come dati contiene il valore, il puntatore al padre, e i puntatori a destra e sinistra


> [!Important]+ Funzioni del nodo
> `Tree(Item v)` (Costruisce un nuovo nodo con `v` come valore)
> `Item read()` (legge il valore)
> `write(Item v)`
> `Tree parent()` (Ritorna il nodo padre, se esistente)
> `Tree left()`
> `Tree right()`
> `insertLeft(Tree t)`
> `insertRight(Tree t)`
> `deleteLeft()`
> `deleteRight()`

^6e51aa

# Visite
## Visita in profondità (DFS)
Si avvale della ricorsione per muoversi fino alle foglie prima di procedere agli elementi dello stesso livello.
Può venire delle varianti pre/in/post order

``` C++
void dfs(){
	// pre-order print()
	if(left != NULL){
		(left)->dfs();
	}
	//in-order
	cout << value << " ";
	if(right != NULL){
		(right)->dfs();
	}
	//post-order print()	
}
```

^03859f

## Visita in ampiezza
Questa tipo di visita invece si muove un livello alla volta. Per farlo usufruisce di una queue. 

```C++
void bfs(){
	vector<Node*> queue = vector<Node*>();
	queue.push_back(this);
	  
	while (queue.size()>0){
		if((*queue[0]).left != NULL){
			queue.push_back((*queue[0]).left);
		}
		if((*queue[0]).right != NULL){
			queue.push_back((*queue[0]).right);
		}
		cout << (*queue[0]).value << " ";
		queue.erase(queue.begin());
	}
	cout << endl;
}
```

^95fa1c



# Alberi binari di ricerca
Vengono implementati (ad esempio nei dizionari) con lo scopo di rendere la ricerca degli elementi più efficiente

Nei nostri esempi consideriamo le chiavi di un dizionario assieme ai loro valori. Le chiavi devono essere ordinate e tutti gli elementi del sotto albero di sinistra devono essere minori dell'elemento radice (il contrario vale per il sotto albero destro). Questo permetto lo sviluppo di un algoritmo di ricerca dicotomica


> [!info]+ Specifica
> Oltre alle normali funzioni di un albero binario abbiamo anche:
> - `Item lookup(Item k)`
> - `Tree successorNode(Tree t)`
> - `Tree predecessorNode(Tree t)`
> - `Tree min()`
> - `Tree max()`

^2e1ed6

#### Successivo e precedente
mentre lookup, min e max risultano di evidente implementazione, il successivo (o predecessore) si implementa in questo modo:
- Nel caso il nodo $n$ abbia un figlio destro, allora il successivo è il `min()` del sotto-albero destro ^54e8a3
- Se invece $n$ non ha un figlio destro, allora il successivo è il primo padre per cui $n$ è nel sotto-albero sinistro ^5d0e03

Per il predecessore basta sostituire destra con sinistra e `min()` con `max()`

#### Nota sull'inserimento
Nel caso in cui l'inserimento ricade in una chiave già presente, allora si aggiorna il valore

#### Eliminazione
L'eliminazione nel caso di un nodo senza o con solo un figlio  è di semplice implementazione (eliminazione diretta o sostituzione con il figlio) ma la casistica con doppio figlio richiede un algoritmo specifico:
1. Individuazione del nodo da eliminare $n$
2. Individuazione del successore $s$ di $n$
3. Se $s$ ha un figlio destro, lo si appende al padre di $s$ al posto di $s$
4. Infine si copia $s$ al posto di $n$

## Bilanciamento
In un albero binario, il costo massimo di `lookup()` è pari all'altezza dell'albero, perciò si applicano funzioni di bilanciamento per avere una distribuzione equa (e di altezza minima) dei nodi.

Definiamo fattore di bilanciamento $\beta(n)$ la massima differenza di altezza fra i sotto-alberi di $n$

#### Alberi Red-Black
In questi ABR speciali, ogni nodo è colorato o di rosso o di nero, e le foglie sono composte da nodi speciali `Nil`.
Inoltre devono essere rispettati i seguenti vincoli:
- la radice è nera
- tutte le foglie sono nere
- entrambi i figli di un nodo rosso sono neri
- Ogni cammino da un nodo alle sue foglie contengono lo stesso numero di nodi neri

I nodi `Nil` in realtà sono puntatori a un singolo nodo, così da 
risparmiare memoria


##### Rotazioni
Nel caso in cui un inserimento vada a rompere uno dei vincoli, si applicano le rotazioni:
(caso di rotazione a sinistra)
1. Prendere il figlio sinistro del figlio destro di $n$ e metterlo come figlio destro
2. Mettere $n$ come figlio sinistro del suo figlio destro
3. Sostituire la vecchia posizione di $n$ rispetto al padre dall'ex figlio destro di $n$

##### Inserimento
Segue 4 principi generali:
- Lettura bottom-up
- ripristino del vincolo 3 (se due nodi consecutivi sono rossi)
- spostiamo le sezioni critiche verso l'alto (vincolo 4)
- coloriamo la radice di nero (vincolo 1)

In pratica:

>1. Memorizziamo il nodo coinvolto ($c$), suo padre($p$), suo zio($z$) e suo nonno ($n$)
>2. Valutiamo i 5 casi possibili:
>	1. $c$ è il primo nodo
>		1. lo inseriamo e lo coloriamo di nero
>	2. $p$ è nero
>		1. inseriamo $c$ colorato di rosso
>	3. $c$, $p$ e $z$ sono rossi
>		1. Coloriamo $p$ e $z$ di nero e $n$ di rosso
>		2. Se $n$ è radice rossa o suo padre è rosso, aggiorniamo i nodi considerando $c=n$ e reiteriamo 
>	4.  $c$ e $p$ rossi, e $z$ nero
>		1. Con $c$ figlio **destro** di $p$ e $p$ figlio **sinistro** di $n$:
>			-  rotazione a **sinistra** da $p$
>		2. Con $c$ figlio **sinistro** di $p$ e $p$ figlio **destro** di $n$:
>			- Rotazione a **destra** da $p$
>		3. proseguo nel caso 5 
>	5.  $c$ e $p$ rossi, e $z$ nero
>		1. Con $c$ figlio **sinistro** di $p$ e $p$ figlio **sinistro** di $n$:
>			-  rotazione a **destra** da $n$
>		2. Con $c$ figlio **destro** di $p$ e $p$ figlio **destro** di $n$:
>			- Rotazione a **sinistra** da $n$
>		3. Coloro $n$ di rosso e $p$ di nero

^3baa6d

Per quanto risulti complesso, l'inserimento ha costo di $O(log\ n)$ 

##### Cancellazione
La cancellazione rimane invariata nel caso eliminiamo un nodo rosso, ma nel caso sia un nodo nero bisogna applicare un algoritmo


> [!warning] slide 83

#### Calcolo di tutte le possibili combinazioni
Questo esercizio si risolve usando la programmazione dinamica, in particolare consideriamo un albero strutturalmente diverso come un albero con lo stesso numero di nodi di partenza, ma organizzati differentemente. 
Nello specifico, possiamo considerare $s$ come numero di nodi andati a sinistra, e $n$ il numero di nodi totali. Quindi usiamo una formula ricorsiva che è la somma di tutte le combinazioni di $s$ nodi sinistri per i restanti nodi destri 

$$P(n)=\begin{cases}1&n=0\\\sum^{n-1}_{s=0}P(s)\cdot P(n-s-1) &n\geq1\end{cases}$$ ^d3b1e6

Nel momento in cui aggiungiamo dei limiti: 
- Nel caso sia richiesto un albero pieno (0 o 2 figli): 

$$T(n)=\begin{cases}0&n\ pari\\1&n=1\\\sum^{n-2}_{i=1}T(i)\cdot T(n-1-i)&n\geq1,\ n\ dispari\end{cases}$$ ^08e30b

- Nel caso in cui ci siano $k$ nodi con un figlio:
	- Da notare come sia la somma del caso precedente e dei casi di un figlio a sinistra e un figlio a destra

$$T(n,k)=\begin{cases}1&n=1,\ k=0\\0&k\geq n\\2T(n-1,k-1)+\sum^{n-2}_{i=1}T(i,k)\cdot T(n-1-i,k)&else\end{cases}$$ ^19fee4

- Nel caso invece di un'altezza limitata, si passa anche quel valore, che va poi a eliminare le ricorrenze che non rispecchiano la proprietà