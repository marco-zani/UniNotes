# Insiemi
Un insieme di $n$ elementi è rappresentato come vettore booleano di dimensione $m$ 


> [!info]+ Implementazione
> - `bool[] v`
> - `int size`
> - `int capacity` (max size)
> - `Set Set(int m)`
> - `bool contains(int x)`
> - `insert(int x)`
> - `remove(int x)`

## Operazioni
#### Union
```
Set union(Set a, Set b){
	int size = max(a,b)
	Set c = Set(size)
	for [i = 0 to a.capacity]{
		if [a.contains(i)]{
			c.insert(i)
		}
	}
	for [i = 0 to b.capacity]{
		if [b.contains(i)]{
			c.insert(i)
		}
	}
	return c
}
```

#### Difference
```
Set difference(Set a, Set b){
	Set c = Set(a.capacity)
	for [i=0 to a.capacity]{
		if [a.contains(i) and not b.contains(i)]{
			c.insert(i)
		}
	}
	return C;
}
```

#### Intersection
```
Set intersection(Set a, Set b){
	int size = min(a,b)
	Set c = Set(size)
	for [i=0 to size]{
		if [a.contains(i) and b.contains(i)]{
			c.insert(i)
		}
	}
	return C;
}
```

# Code con priorità
Una variante di una coda che implementa una priorità per ogni elemento. Questo cambia il modo in cui avviene l'inserimento, e aggiunge le operazioni di estrazione dell'elemento più (o meno) importante e la modifica di priorità

## Heap
Struttura dati che associa i vantaggi di un albero con la semplicità del vettore.

Nel passaggio tra vettore ad albero:
- radice: 1
- padre del nodo $i$: $\lfloor i/2\rfloor$
- figlio sx di $i$: $2i$
- figlio dx di $i$: $2i+1$

Si basa sul concetto di max-heap, ossia un albero dove tutti gli elementi figli sono minori rispetto ai padri. 

#### `heapRestore()`
Con l'inserimento di un nuovo elemento, questo viene messo a radice e confrontato con i figli, se risulta inferiore di uno di essi, allora scambiano di posizione. L'algoritmo si ripete fino a quando entrambi i figli sono minori.

#### `heapBuild()`
Converte un vettore in un albero heap. Inserisce tutti gli elementi nell'albero ordinati così come sono, dopo di che si divide in due parti:
1. Prendiamo la seconda metà ($\lfloor2/n\rfloor$) del vettore, e li consideriamo foglie
2. Applica `heapRestore()` su ogni foglia ( \[$\lfloor2/n\rfloor...1$] )

#### heapsort
```
heapSort(Item[] a, int n){
	heapBuild(A,n)
	for [n to 2]{
		swap(A,1,i)
		heapRestore(A,1,i-1)
	}
}
```

#### Proprietà (Invariante di ciclo)
All'inizio di ogni iterazione di un for, i nodi \[$i+1...n$]  sono radice di un heap

## Priority queue
```
PriorityItem{
	int priority
	Item value
	int pos
}
```
Offre 4 funzioni:
- `insert()`: scorre il vettore fino alla posizione di priorità corretta, sposta tutti gli altri elementi
- `min()`: ritorna l'elemento in posizione 0
- `heapRestore()`:
	```
	heapRestore(PriorityItem[] a, int i, int dim){
		int min = i
		if [2*i <= dim and a[2*i]<a[min]]{
			min = 2*i
		}
		if [2*i+1 <= dim and a[2*i+1]<a[min]]{
			min = 2*i+1
		}
		if [ i!=min ]{
			swap(a,i,min)
			heapRestore(a,min,dim)
		}
	}
	```
- `deleteMin()`: elimina l'elemento in posizione 1 e chiama `heapRestore`
- `decrease(PriorityItem x, int p)`: sposta l'elemento fino a priorità `p` 

# Insiemi disgiunti
Si basano sull'elezione di un elemento come rappresentate dell'insieme al quale ogni elemento punta. Questo permette confronti a costo $O(1)$ per verificare l'appartenenza di un elemento a un gruppo
## Operazioni fondamentali
#### Creare n insiemi disgiunti
#### merge()
Unisce le componenti dei due insiemi disgiunti forniti
#### find()
Ritorna il rappresentante della componente specificata

## Implementazioni
#### Implementazione con liste
Ogni elemento della lista (esclusa la guardia) contiene l'oggetto e due puntatori, uno al rappresentante e l'altro all'elemento successivo

Con questa implementazione il find è immediato $O(1)$ (ritorna il puntatore al rappresentante), mentre il merge consiste nel modificare tutti i puntatori al rappresentante della lista appesa ($O(n^2)$ costo pessimo, $O(n)$ costo ammortizzato)
#### Implementazione con albero
In questo caso invece, ogni nodo possiede l'oggetto e il puntatore al padre, dove la radice è il rappresentante (e punta a se stessa)

Qui il merge diventa più efficiente, basta impostare il nuovo rappresentante come padre del vecchio rappresentante ($O(1)$), mentre il find richiede di risalire tutto l'albero, quindi nel caso pessimo $O(n)$
## Tecniche euristiche
Queste tecniche offrono una soluzione approssimata, e sono usate per risolvere un problema velocemente o dare una soluzione nel caso una perfetta non esista
#### Euristica del peso
Usata nelle liste, consiste nel tenere registrata la lunghezza della lista, e di appendere la lista più corta a quella più lunga 
#### Euristica del rango
Usata con gli alberi, consiste nell'appendere l'albero di altezza inferiore a quello di altezza superiore, confrontando i ranghi. In caso di alberi di pari rango, questo aumenta di $1$ nel nuovo albero
#### Euristica della compressione dei cammini
Si appiattiscono gli alberi con ogni ricerca in modo da avere come padre di tutti i nodi il rappresentante
## Problema delle connessioni
Trovare le componenti connesse di un grafo non orientato dinamico