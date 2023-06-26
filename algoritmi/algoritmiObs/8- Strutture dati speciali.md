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
#### find()

## Implementazioni
#### Implementazione con liste
#### Implementazione con albero

## Problema delle connessioni
Trovare le componenti connesse di un grafo non orientato dinamico