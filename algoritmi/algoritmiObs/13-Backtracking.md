# Soluzioni ammissibili
Sono le soluzione che soddisfano tutti i criteri determinati dal problema
## Brute force
si analizzano l'intero spazio delle soluzioni ammissibili. Alcuni esempi sono:
- Algoritmi di enumerazione: elencano tutte le soluzioni ammissibili
- Algoritmi di ricerca: permutano le soluzioni fino alla prima ammissibile
- Algoritmi di conteggio: come gli algoritmi di enumerazione ma ritorna il conteggio delle soluzioni ammissibili
- Algoritmi di ottimizzazione: enumera tutte le soluzioni ammissibili e ritorna quella più congrua al task

Lo spazio delle soluzioni è spesso troppo vasto, perciò si cerca di analizzare solo le parti con possibili soluzioni valide

# Backtracking
Si basa sul concetto "Ritenta, sarai più fortunato":
- ricorsivamente: sistematicamente esplora lo spazio di ricerca, memorizzando le scelte precedenti
- iterativamente: approccio greedy che può ritornare sui suoi passi
## Funzionamento generale
Una soluzione è rappresentata tramite un vettore di scelte, che raccoglie i suoi elementi da un insieme di scelte fornito dal problema

il vettore delle scelte può comporre sottoinsiemi o permutazione dell'insieme delle scelte

## Enumerazione
1. Se la soluzione è valida, processala
2. Se no, calcola le possibili scelte
	1. per ogni scelta accettala e torna ricorsivamente al punto 1
#### Soluzioni parziali
Con $i$ indice delle decisioni e $S$ vettore delle scelte, se $S[1..i-1]$ non è soluzione ammissibile allora è soluzione parziale

## Sottoinsiemi
processiamo l'elemento $i$-esimo
1. se siamo oltre all'ultimo elemento processiamo la soluzione
2. se no valutiamo se prendere o meno l'$i$-esimo elemento
	1. ritorniamo ricorsivamente al punto 1 con le nostre scelte

Complessità: $\Theta(n\cdot 2^n)$
## Permutazioni
1. Se l'insieme delle scelte è vuoto, allora processa la soluzione
2. Se no estraiamo un elemento dall'insieme 
	1. ritorniamo al punto 1 con le nostre scelte
3. reinseriamo l'elemento e continuiamo a iterare su tutti gli elementi

Complessità: $\Theta(n^2n!)$

##### Versione più efficiente
Si basa sul scendere gli elementi fino al primo:
```
perm(Item[] S, int i){
	if [i==1]{
		Print(S)
	} else {
		for [j from 1 to i]{
			swap(S,i,j)
			permRec(S,i-1)
			swap(S,i,j)
		}
	}
}
```
Complessità: $\Theta(n\cdot n!)$

# k-sotto insiemi
Si elencano tutti i sotto-insiemi di dimensione k, quindi:
```
kssRec(int n, int k, int[ ] S, int i){
	size = count(S)
	if [i>n and size==k]{
		print(S)
	}else if [i>n and size != k]{
		return
	} else {
		foreach [c in [0,1]]{
			S[i] = c
			kssRec(n, k, S, i + 1)
		}
	}
 }
```

Da qui possiamo sviluppare delle ottimizzazioni
- inserire gli elementi a discesa: andiamo da $S[n]$ a $S[0]$
- Fermarsi ottenuta una soluzione ammissibile: controllare se `missing<0` (pruning)
- Fermarsi se non è possibile ottenere una soluzione ammissibile: controllare se `n-(i-1)<missing` (total pruning)

Pulendo poi il codice il risultato è:
```C
kssRec(int n, int missing, int[ ] S, int i){
	if [missing == 0]{
		print(S)
	} else if [i <= n and [0 < missing and missing <= n-(i-1)]]{
		foreach [c in [0,1]]{
			S[i] = c
			kssRec(n, missing − c, S, i + 1)
		}
	}
}
```

Questo algoritmo risulta molto efficiente per $k$ lontani da $\frac{1}{2}\ n$ 

# Subset Sum
Dato un insieme di interi e un valore $k$, trovare un sotto-insieme tale che la somma degli elementi equivale a $k$

da qui è evidente come adattare il codice in modo che se la somma supera il nostro $k$ allora la ricorsione si ferma

```C
bool ssRec(int[] A, int n, int missing, int[ ] S, int i){
	if [missing == 0]{
		print(S)
		return true
	} else if [i > n and missing < 0]{
		return false
	} else {
		foreach [c in [0,1]]{
			S[i] = c
			if [kssRec(A,n, missing − (c*A[i]), S, i + 1)]{
				return true
			}	
		}
		return false
	}
}
```

# Le $n$ regine
In questo problema bisogna posizionare $n$ regine in una scacchiera $n\times n$. In questo caso il pruning si applica sulle righe, colonne e diagonali dove sono già posizionate regine

```C
queens(int n, int[ ] S, int i){
	if [i > n]{
		print S
	}  else {
		for [j = 1 to n]{
			boolean legal = true 
			for [k = 1 to i − 1]{
				if [S[k] == j or S[k] == j + i − k 
					or S[k] == j − i + k]{
					legal = false
				} 
			if [legal] {
				S[i] = j
				queens(n, S, i + 1)
			}
		} 
	} 
}
```

# Sudoku
# Knight tour
# Inviluppo convesso
Un poligono convesso è un poligono dove due punti qualsiasi sul perimetro del poligono, possono essere collegati senza attraversare il suddetto perimetro. L'inviluppo convesso è, dati dei punti, il poligono convesso di area minima che li contiene tutti 
## Algoritmo di Jarvis
1. Si seleziona il punto più a sinistra di tutti
2. si calcola l'angolo tra la retta verticale e il nuovo punto, per tutti i punti
3. si seleziona il punto con angolo minore
4. si ripete usando la retta tra i due punti precedenti al posto della retta verticale
5. si finisce quando si torna al punto zero

## Algoritmo di Graham
Simile, parte dall'elemento più in basso e 


> [!warning] finire slide 67
