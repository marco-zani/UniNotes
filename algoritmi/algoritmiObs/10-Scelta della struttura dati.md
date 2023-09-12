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

#### Bellman-Ford-Moore
Accetta pesi negativi
