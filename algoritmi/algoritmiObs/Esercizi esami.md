# 17-01-2023
## B1
#DP
```python
int count(int n, int s):
	DP = []
	for i in range(n):
		DP.append(-1)
	DP[0] = 1
	return rec(DP, n-1, s)

rec(DP[], index, sizes):
	if DP[index] == -1:
		DP[index] = 1
		from i = 1 to min(index, sizes):
		DP[index] += DP[index-i]
	return DP[index]
```

## B3
#DP
```python
minCardinality(int n){
	int S = list<int>()
	S.append(0)
	for [i from 1 to n]{
		S[0] = i
		cardRec(S,n,0)	
	}
	
}

cardRec(list<int> S, int n, int taken){
	if[S[0] == taken]{
		print(S)
	} else 
		for [j from S[i]+1 to n]{
			S[i+1] = j
			cardRec(S,n,i+1)
		}	
	}
}
```

# 09-02-2023
## B1
#DP
```python
int mcs(int[] T, int[] U, int n, int m):
	

vect<int> rec(int[] T, int[] U, int n, int m, vect<int>[][] DP):
	if [n == 0 or m == 0]:
		return empty()
	if [DP[n][m] != empty()]:
		return DP[n][m]
	if [T[n] == U[m]]:
		DP[n][m] = rec(T,U,n-1,m-1,DP).append(T[n])
		return DP[n][m]
	reduceT = rec(T,U,n-1,m,DP)
	reduceU = rec(T,U,n,m-1,DP)
	if [reduceT.size > reduceU.size]:
		DP[n][m] = reduceT
	else:
		DP[n][m] = reduceU
	return DP[n][m]
```
## B2 
## B3
#DP

```python
productK(int []A, int n, int m):

rec(DP[][], A[], index, max):
	if index == 0:
		return  1
	else:
		if index < 0 
			DP[index][mx] = rec(DP,A,index-1,mx)
			if A[index]>mx:
				DP[index][mx] += rec(DP,A,index-1,floor(mx/A[index]))	
		return DP[index][mx]
```

# 20-06-2023
## B1
#backtracking
```python
printMixing(Item[ ] S1, Item[ ] S2, int n1, int n2):
	Item[] T = Item[n1+n2]
	rec(T,S1,S2,n1,n2)
	
rec(Item[] T, Item[ ] S1, Item[ ] S2, int n1, int n2):
	if [(n1,n2) == (0,0)]:
		print(T)
	else:
		if [n1>0]:
			T[n1+n2] = S1[n1]
			rec(T,S1,S2,n1-1,n2)
		if [n2>0]:
			T[n1+n2] = S2[n2]
			rec(T,S1,S2,n1,n2-1)
```
Complessità $O(2^{n1+n2})$ 

## B2
```python
boolean isMixing(Item[ ] S1, Item[ ] S2, Item[] T, int n1, int n2, int n):
	i1,i2 = 0,0
	while[i1 < n1 and i2 < n2]:
		if [T[i1+i2] != S1[i1] and T[i1+i2] != S2[i2]]:
			return false
		if[T[i1+i2] == S1[i1]]:
			i1++
		else
			i2++
	return true
			
```

## B3
#flusso
Si utilizza il calcolo del flusso massimo per effettuare un assegnazione, creando un grafo seguendo i seguenti concetti:
- Un nodo per ogni reviewer, collegato dalla sorgente con capacità $k$
- creiamo due nodi per ogni paper, il nodo expert e il nodo not expert, alla quale colleghiamo ogni reviewer con al massimo un collegamento di capacità 1 per paper
- ogni nodo di un paper va collegato a un nodo di conteggio totale, con capacità 1 dai nodi not expert e capacità 3 dai nodi expert
- infine colleghiamo i nodi di conteggio totale al nodo pozzo con capacità 3

Applicando Ford-fulkerson è facile individuare come la capacità massima sia $3$ per il numero totale di papers

# 11-07-2023
## B1
#flusso 
Si utilizza il calcolo del flusso massimo per effettuare un assegnazione, creando un grafo seguendo i seguenti concetti:
- dalla sorgente si connettono i nodi delle università con capienza $n_i$
- ogni università si collega con capacità 1 a un nodo tavolo-paese
- questi nodi tavolo-paese si collegano con capacità 3 al nodo tavolo $t_i$ 
- infine i tavoli si collegano con capacità $k$ al pozzo
Questa condizione risulta irrealizzabile se esiste un'università che porta $n_i$ studenti con $\frac{n_1}{3}>n_t$ 

## B2
#backtracking 
```python
ipotesi struttura:
Node:
	adj = list<(node,int)>

searchPath(Graph G, Node src, Node dest):
	path = pathRec(src,None,dest,0)
	if path != []:
		print(path)

pathRec(Node curr, Node prev, Node dst, int tot):
	out = []
	for adj, dist in curr.adjacents:
		if adj != prev:
			if adj == dst && dist + tot == 5000
				out.append(dst)
				return out
			elif adj != dst && dist + tot < 5000
				out.append(pathRec(adj, curr, dst, tot + dist))
				if out != []:
					return out
	return []
				
	
```
La complessità di questo algoritmo è polimoniale
## B3 (DA RIFARE)
#DP 
```python
int countMakeup(int n):
	int DP_pari = int[n]
	int DP_dispari = int[n]

	DP_pari[0] = 1
	DP_dispari[0] = 0

	for i = 1 to n:
		DPd[i] = 2 * DPp[i-1]
		DPp[i] = 0
		for j = 0 to i-1
			DPp[i] = DPp[i]+DPd[j]*DPd[i-j]
	return DPp[n]
		
```

complessità $O(n^2)$ 

# 23-08-2023
## B1
#flusso
L'algoritmo costruirebbe una rete di flusso secondo i seguenti principi:
- Un nodo sorgente che si collega ai nodi produttori con capienza pari alla capacità produttiva del nodo
- un nodo pozzo collegato ai nodi consumatori con capienza pari alla quantità d'acqua consumata
- i nodi intermedi collegati seguendo le indicazioni del grafo passato.
Ottenuta la rete di flusso basterà applicare l'algoritmo di 


## B2
#backtracking
```python
subPalindrome(Item[ ] S, int n):
	taken = []
	rec(S,taken,n)

rec(Item []S, Item taken [], int n):
	if (n < 0):
		if isPal(taken):
			print(taken)
	else:
		rec(S,taken, n-1)
		taken.append(S[n])
		rec(S,taken, n-1)

bool isPal(Item [] S):
	out = true
	left = S.begin()
	right = S.end()
	while(left < right):
		if S[left] != S[right]:
			return false
	return out
```
## B3 (DA RIFARE)
#DP

```python
	
```

# 24-08-2022
## B1
#flusso
- creo i nodi $supervisore/slot$ e $aula/slot$ 
- collego con capacità 1 la sorgente con i corsi, poi i corsi con le aule/slot di capacità sufficiente, poi collego aula/slot con i supervisori/slot con stesso slot, infine collego ai relativi supervisori
- collego i supervisori con il pozzo con una capacità $d$
costo totale:
O(|E|f^*) dove f^* è corrisponde al numero di corsi totale, mentre gli archi corrispondono alla somma di $C + ACO + AOS + SO + S$, di conseguenza $O(AOC(C+S)+CSO)$ 

## B2
#backtracking
```python
printElegant(int n):
	v = []
	for i=1 to n:
		v.push(i)
	rec(v,[])

rec(list remaining, list taken):
	if(remaining.size() == 0):
		print(taken)
	else:
		for el in remaining:
			if el % taken.size() == 0 or taken.size() % el == 0:
				remaining.remove(el)
				taken.push(el)
				rec(remaining, taken)
				remaining.push(el)
				taken.remove(el)
	
```
## B3
#DP
```python
int maxConnections(int[ ] X, int[ ] Y, int n):
	DP = [n][n]
	from i = 0 to n-1:
		DP[0][i] = 0
		DP[i][0] = 0
	

```


# 13-07-2022
## B3
#DP
```python
int countIncreasing(Int [] A, int n, int k):
	DP = [n][k]
	for el in DP
		el = -1
	return rec(DP, A, n, k)

rec(DP,A,index,size):
	if DP[index][size] < 0:
		if k == 1:
			 DP[index][size] = 1
		else:
			DP[index][size] = 0
			if index > size:
				from i = 0 to index-1:
					if A[i] < A[index]:
						DP[index][size] += DP[i][size-1]
	return DP[n][k]
```

# 22-06-2022
## B3
#DP 
```python
int countsequences(n,m):
	DP = [m][n]
	for el in DP:
		el = -1
	return rec(DP,m,n)

rec (DP,index, size):
	if DP[index][size] < 0:
		if size == 1:
			DP[index][size] = 1
		else:
			DP[index][size] = 0
			if index > size:
				from i = 0 to floor(index/2):
					DP[index][size] += rec(DP,i, size-1)
	return DP[index][size]
	
```

# 07/02/2022
## B2
#DP
```python
int discordville(int []D, int[]N, int n):
	DP = [n]
	for el in DP:
		el = -1
	DP[0] = D[0]
	return rec(DP,D,N,n)

def rec(DP,D,N,index):
	if DP[index] < 0:
		taken = rec(DP,D,N,index-N[index]) + D[index]
		noTaken = rec(DP,D,N,index-1)
		DP[index] = max(taken, noTaken)
	return DP[index]	
```

# 17-01-2022
## B3
#DP
```python
int countWellBalanced(int n):
	DP = [n]
	for el in DP:
		el = -1
	DP[0] = 1
	DP[1] = 1
	return rec(DP, n)

def rec(DP, index):
	if DP[index] < 0:
		if index % 2 == 1:
			DP[index] = rec(DP, (index-1)/2)^2
		else: 
			DP[index] = 2 * rec(DP,floor((index-1)/2)) * rec(DP,ceil((index-1)/2))
	return DP[index]
```

# 31-08-2021
## B3
#DP 
```python
int countSumEvent(int n):
	DP = [n]
	for el in DP:
		el = -1
	DP[0] = 1
	return rec(DP, n)
	
rec(DP, index):
	if DP[index] < 1:		
		DP[index] = 0
			from i = 1 to index/2
				DP[index] += rec(DP, index-2i)
	return DP[index]
```

# 16-06-2021
## B3
```python
int maxSumIncreasing(int []A, int n):
	DP = [n]
	for el in DP:
		el = -1
	DP[0] = A[0]
	rec(DP,A,n)
	max(DP)

rec(DP,A,index):
	if DP[index]< 0:
		DP[index] = A[index]
		from i = 0 to index-1:
			j = rec(DP,A, i)
			if A[index] > A[i] and j + A[i] > DP[index]:
				DP[index] = j + A[index]
	return DP[index]
```

# 26-0702021
## B3
```python
maxSumK(V,n,k):
	DP = [n]

	for el in DP:
		el = -1
	DP[0]=V[0]
	return rec(DP,V,n,k)

rec(DP,V, index, size):
	if DP[index] < 0:
		
	return DP[index]
```