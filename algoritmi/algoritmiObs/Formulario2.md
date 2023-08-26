# Strutture dati speciali
# Programmazione dinamica
## DP
L'algoritmo consiste nel compilare una tabella/vettore, quindi la complessità massima è la dimensione della struttura dati ($n$ o $n^2$)

### Algoritmo su vettore
Il confronto viene applicato sugli elementi precedenti del vettore
#### Domino
``` python
DP[] = new int[n]
DP[0]=DP[1]=c
for [i from 2 to n]{
	DP[i]=DP[i-1]+...+DP[i-p]
}
return DP[n]
```
### Algoritmo su matrice
In questo caso viene applicato un confronto su due direzioni, prima si applica il confronto sulla prima riga come con un vettore, poi si confronta la riga successiva per valutare le scelte precedenti
#### Zaino
```python
for [i from 1 to n]{
	for [c from 1 to C]{
		if [w[i]<= c]{
			DP[i][c] = max(DP[i-1][c-w[i]] + p[i], DP[i-1][c])
		} else {
			DP[i][c]=DP[i-1][c]
		}
	}
}
return DP[n][C]
```

### Complessità
Domino/Hateville: $\Theta(n)$ (si va a compilare un vettore)
Zaino: $\Theta(nC)$ (dove $n$ sono il numero di oggetti e $C$ la capienza dello zaino)


## Memoization
Applicazione della Programmazione dinamica in modo ricorsivo, andando a risolvere i problemi top-down e compilando solo le celle utili della matrice
### Zaino
```python
rec(int[] w, int[] p, int i, int c, int[][]DP):
	if [c <0]:
		return -1
	else if [i == 0 or c == 0]:
		return 0
	else:
		if [DP[i][c] < 0]:
			notTaken = rec(w,p,i-1,c,DP)
			taken = rec(w,p,i-1,c-w[i],DP) + p[i]
			DP[i][c] = max(taken, notTaken)
	return DP[i][c]	
```
### Sotto-sequenza
Il concetto è quello di scomporre la sequenza partendo dal fondo, e confrontando gli elementi comuni riducendo la lettera di una o l'altra sequenza
```python
lcs(string1, string2, ind1, ind2, DP):
	if [ind1 == 0 or ind2 == 0]:
		return 0
	if [DP[ind1][ind2] != -1]:
		return DP[ind1][ind2]
	if [string1[ind1] == string2[ind2]]:
		DP[ind1][ind2] == lcs(string1,string2,ind1-1,ind2-1,DP) +1
		return DP[ind1][ind2]
	DP[ind1][ind2] = max(lcs(string1,string2,ind1-1,ind2,DP), lcs(string1,string2,ind1,ind2-1,DP))
	return DP[ind1][ind2]
```
# Scelta struttura dati
# Algoritmi Greedy
#### costo di lettura

# Ricerca locale
## Flussi
Si Usa l'algoritmo di Ford-Fulkerson, che presenta una complessità di $O(V+E|f^*|)$
dove $|f^*|$ è il flusso massimo
#### Termini
esattamente $x$: ci deve essere un unico canale in uscita dal nodo con una capacità $x$ 

# Back tracking
L'algoritmo ricorsivo si può ricondurre a:
```python
algoritm(){
	if [end condition]{
		process solution
	} else if [condition to proceed]{
		foreach [possible action]{
			algoritm(...)
		}
	}
}
```