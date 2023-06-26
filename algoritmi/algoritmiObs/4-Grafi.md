# Introduzione
## Definizioni
#### Componenti
- Grafo non orientato:
	- $G=(V,E)$ dove $V$ è l'insieme dei nodi e $E$ l'insieme di coppie non ordinate di nodi, chiamati archi
- Grafo orientato:
	- Stesso del non orientato, ma dove le coppie di nodi sono ordinate
- Adiacenza e incidenza:
	- Un nodo $n$ è definito adiacente a $u$ se c'è un arco che li collega
	- Un arco ($u$, $v$) è detto incidente da $u$ a $v$

#### Cardinalità
- grado = # archi su un nodo
	- In un grado orientato si differenzia tra entrante e uscente
- $n=|V|=$  # nodi
- $m=|E|=$ # archi (movements)
	- In un grafo orientato: $m\leq n^2-n$
	- in un grafo non orientato: $m\leq\frac{n(n-1)}{2}$
	- La complessità è espressa sia per $n$ che per $m$ ($O(n+m)$)

#### Tipi di grafo
- Un grafo è completo se per ogni nodo esiste un arco che lo collega agli altri nodi
- Un grafo con pochi archi è detto sparso, se no è chiamato denso
- Un albero libero (free tree) è un grafo con $m=n-1$
	- Un albero radicato è un albero libero con un nodo assegnato come radice
	- Un insieme di alberi liberi è detto foresta

#### Cammini
- Un cammino di lunghezza $k$ è una sequenza di $k$ elementi che collega due nodi

## Specifica
Le funzioni sono:

> [!example]+ 
> - `SET V()` (restituisce tutti i nodi)
> - `int size()`
> - `SET adj(Node u)`
> - `insertNode(Node u)`
> - `insertEdge(Node u, Node v)`
> - `deleteNode(Node u)`
> - `deleteEdge(Node u, Node v)`

^9fd3bc

## Memorizzazione
#### Matrici di adiacenza
Di facile implementazione, ma occupa più spazio. Nel caso dei grafi orientati, $n^2$ bit. Invece nei grafi non orientati ci basta conservare solo metà matrice separata dalla diagonale, quindi $\frac{n(n-1)}{2}$ 

Nei grafi pesati mettiamo come segna posto il costo di quell'arco

Le matrici di adiacenza sono ideali per grafi densi

#### Liste di adiacenza
Più complesse, ma costano solo $an+bm$ bit nel caso del grafo orientato, dove $a$ è il costo di memorizzare un nodo e $b$ il costo di memorizzare un arco. Nel caso del grafo non orientato, gli archi vanno scritti due volte, da parte del nodo di andata e quello di arrivo, perciò il costo in memoria è $an+2\cdot bm$ 

Nei grafi pesati dobbiamo aggiungere alla struttura dati che contiene l'arco anche il peso di esso

Le lista di adiacenza sono ideali per i grafi sparsi

# Visite ai grafi
Una visita è, dato un nodo sorgente $r$, riportare tutti i nodi che possono essere raggiunti da $r$

## BFS (Breadth First Search)
La visita in ampiezza vede prima tutti i nodi a distanza 1, poi a distanza 2, etc...
Viene usata nel calcolo dei cammini più brevi

il pseudo codice è 
```
Queue q
q.enqueue(r)
foreach [nodes-r]{
	distance[n] = -1
}
distance[r] = 0

while [q not empty]{
	curr = q.dequeue
	foreach [node adjacent to curr]{
		if distance[adj] == -1{
			distance[adj] = distance[curr]+1
			***
			q.enqueue(adj)
		}
	}
}
```

^37b0bb

Per trovare il cammino più breve, nel nodo si aggiunge anche il padre (Nel codice al posto di  `***`), in questo modo possiamo anche ricostruire al contrario anche l'albero di copertura con tutti i percorsi più brevi da un nodo $r$ a tutti gli altri

La complessità di questa visita è $O(m+n)$

## DFS (Depth First Search)
La visita in profondità, o visita ricorsiva, viene usata per l'ordinamento topologico o per determinare il livello di connessione delle componenti

pseudo codice:
```
visited[curr] = true //visita pre-order
foreach [node adjacent to curr]{
	if [not visited]{
		dfs(Graph, adj, visited) //visita in-order
	}
}
// visita post-order
```

^81d973

Complessità $O(m+n)$

In caso di grafi molto grandi e connessi la dfs può riempire lo stack e dare errore, in quel caso conviene usare uno stack esplicito oppure bfs

La situazione post-order è molto sensibile perché se implementata male può portare a loop infiniti, perciò si usano dei tag discovery e finish dove:
- quando viene visitato un nodo per la prima volta lo si tagga discovery
- quando un nodo visitato ha il tag discovery si aggiorna con il tag finish e si aggiungono tutti i vicini
- quando un nodo visitato ha il tag finish si effettua la post-visita

## altre definizioni
#### Connessione
Definiamo come componente connessa un gruppo di nodi tutti raggiungibili tra di loro. Nel caso dei grafi orientati, se questa proprietà è rispettata, allora si definiscono fortemente connesse 

> [!important]+ NB
> ![[componenti_connesse.png]]
> Sono evidenziate le componenti fortemente connesse

inoltre, in un grafo sconnesso con diverse componenti sconnesse, definiamo come massimale il sotto-grafo connesso più grande

#### Raggiungibilità
In un grafo orientato, è possibile che un nodo sia raggiungibile da un secondo, ma non il contrario

#### Ciclo
Quando viene trovato un percorso di lunghezza $>2$ che dal nodo $n$ riporta al nodo $n$. Un grafo non orientato senza cicli è definito aciclico, se invece è orientato è definito DAG (Directed Acyclic graph)

Definiamo un ciclo semplice se tutti i nodi sono distinti (non ripassa su un nodo)

#### Ordinamento topologico
Dato un DAG, possiamo ordinare linearmente i suoi elementi. 
Evidenziamo che esistono più ordinamenti topologici diversi, o se è presente un ciclo, non è possibile ordinare il grafo


## Identificazione delle componenti connesse
Possiamo identificare il numero e quali nodi appartengono alle componenti connesse di un grafo usando la dfs e apportando la seguente modifica:
- aggiungere un vettore `id[]` che contiene la lista degli ID delle componenti
- assegniamo ad ogni nodo l'id $0$ e poi chiamiamo la dfs per assegnare un id a tutte i nodi connessi a quel nodo
- terminata la dfs leggiamo i nodi e se sono ancora presenti nodi con id uguale a $0$ allora facciamo ripartire la dfs ma assegnando un id diverso
- ripetiamo finché tutti i nodi hanno un id diverso da 0

definiamo questo algoritmo come `cc`

## Identificazione dei cicli
Si compone di due funzioni:
```
bool hasCycleRec(Graph G, Node node, Node parent, bool[] visited){
	visited[node] = true
	foreach [node adjacent]{
		if [curr != parent]{
			if visited[curr]{
				return true
			} else if hasCycleRec(G, curr, node, visited){
				return true
			}
		}
	}
	return false
}
```

```
bool hasCycle(Graph G){
	bool visited [G.size]
	foreach [n in G.v]{
		visited[n] = false
	}
	foreach [n in G.v]{
		if [not visited[n]]{
			if [hasCylceRec(G,n,NULL, visited)]{
				return true
			}
		}
	}
	return false
}
```

^44a571

Identificazione dei cicli per un grafo orientato:
```
bool hasCycleRec(Graph G, Node n, int &time, int[] dt, int[] ft){
	time++
	dt[n]=time
	foreach[adj in G.adj(n)]{
		if [dt[adj] == 0]{
			if [hasCycleRec(G,adj,time,dt,ft)]{
				return true
			}
		} else if [dt[n]>dt[adj] and ft[v]==0]{
			return true
		}
	}
	time++
	ft[u]=time
	return false
}
```

^262f70

questo algoritmo è determinato da:
- [[4-Grafi#^2efac9|specifica]]
- [[4-Grafi#^c150ec|teorema]]

## Albero di copertura
Ogni volta che si visita un nodo non visitato, si aggiunge l'arco all'albero. Gli archi che non compongono l'albero vengono definiti in diversi modi, considerando $p$ come nodo di partenza e $a$ come nodo di arrivo:
- Se $p$ è antenato di $a$ allora è un arco in avanti
- Se $p$ è discendente di $a$ allora è un arco all'indietro
- Se non è ne antenato ne discendente allora è un arco di attraversamento

in codice:
```
dfs-schema(Graph G, Node n, int &time, int [] dt, int [] ft){
	time++
	dt[n] = time
	foreach [adj in G.adj(n)]{
		if [dt[adj]==0]{
			dfs-schema(G, adj, time, dt, ft)
		} else if [dt[n]>dt[adj] and ft[adj] == 0]{
			// arco indietro
		} else if [dt[n]<dt[adj] and ft[adj] != 0]{
			//arco in avanti
		} else {
			arco di traversamento
		}
	}
	time++
	ft[n] = time
}
```

^fc38d4

con `time` come contatore, `dt` contatore di scoperta e `ft` contatore di fine ^2efac9

#### Classificazione degli archi
Teoremi utili derivanti dall'albero di copertura e classificazione degli archi:
- Due nodi in un albero di copertura sono o discendenti l'uno dell'altro oppure non fanno parte dello stesso branch
- Un grafo orientato è aciclico se non esistono archi all'indietro ^c150ec

## Ordinamento topologico
L'algoritmo basato su DFS consiste nell'ordinare l'elemento quando viene fissato un [[4-Grafi#^2efac9|tempo di fine]] 

```
Stack topSort(Graph G){
	Stack s = Stack()
	bool visited [G.size]
	foreach [node in G] {
		visited[node] = false
	}
	foreach [n in G]{
		if [not visited[n]]{
			ts-dfs(G,n,visited,s)
		}
	}
	return s
}
```

^8a43b1

``` 
ts-dfs(Graph G, Node n, bool[] visited, Stack s){
	visited[n] = true
	foreach[adj in G.adj(n)]{
		if [not visited[adj]]{
			ts-dfs(G, adj, visited, s)
		}
	}
	s.push(n)
}
```

^329189

Questi algoritmi vengono usati per calcoli e istruzioni sottoposti a dipendenze

## Connessioni forti
Per individuare le componenti fortemente connesse possiamo usa l'algoritmo di Kosaraju:
1. applico l'ordinamento topologico sul grafo
2. Generiamo il grafo trasposto $G_t$ (grafo con la direzione degli archi invertita) 
3. individuo le [[4-Grafi#Identificazione delle componenti connesse|componenti connesse]] usando l'ordinamento topologico al contrario (prendo come argomento lo stack e `pop()` gli elementi finché presenti)
Le componenti connesse individuate saranno fortemente connesse