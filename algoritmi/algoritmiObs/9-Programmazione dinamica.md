# Dynamic programming
Alcuni problemi ricalcolano sotto-problemi già calcolati. La soluzione è memorizzare i risultati

In fasi:
- Ottenere la struttura ottima (equazione di ricorrenza)
- dimostrare
- Calcolare il valore ottimo in bottom-up (Dyn prog) o top-down (memoization)
- Ricostruzione della soluzione ottima

> [!important]+ NB: tabella
> La tabella deve essere facilmente indirizzabile (O(1)). Quindi per esempio hash table

![[schemaProblemi.png]]

## Domino

> [!example]- Domino
> l gioco del domino è basato su tessere di dimensione 2 × 1. Scrivere  
un algoritmo efficiente che prenda in input un intero n e restituisca il  
numero di possibili disposizioni di n tessere in un rettangolo 2 × n
>$$DP[n]=\begin{cases}1&n\leq1\\DP[n-1]+DP[n-2] &n>1 \end{cases}$$
> Per semplificare la comprensione, noi partiamo dalla casistica più piccola, e man mano che procediamo, andiamo a sommare i risultati già calcolati per le dimensioni risultanti nel caso noi effettuiamo una determinata azione

Possiamo estrapolare una formula utile:
$$
DP[n]=\begin{cases}c&n\leq1\\\sum^pDP[n-i]&n>1\end{cases}
$$
Dove $c$ è una costante e $p$ sono le possibili combinazioni di scelta e $i$ il loro peso. In codice:
```
DP[] = new int[n]
DP[0]=DP[1]=c
for [i from 2 to n]{
	DP[i]=DP[i-1]+...+DP[i-p]
}
return DP[n]
```

La risoluzione è bottom-up, dal più facile al più difficile, salvando i risultati

## Hateville

> [!example]- Hateville
> _Hateville è un villaggio particolare, composto da n case, numerate  da 1 a n lungo una singola strada. Un vicino i odia i vicini i − 1 e i + 1 (se esistenti)_.
>
>_Hateville vuole organizzare una sagra e vi ha affidato il compito di  raccogliere i fondi. Ogni abitante i ha intenzione di donare una quantità D[i], ma non  intende partecipare ad una raccolta fondi a cui partecipano uno o  entrambi i propri vicini_.
>
>Scrivere un algoritmo che dato il vettore D, restituisca la quantità massima di fondi che può essere raccolta
>
> Partendo dal fondo, valuto come varia il mio guadagno in base se accetto una donazione o meno
> 
> $HV(i)=highest(HV(i-1), \{i\}\cup HV(i-2))$ 
> 
>Aggiungiamo i casi base
>
>$HV(i)=\begin{cases}\emptyset & i=0\\ \{1\} & i=1 \\ highest(HV(i-1), \{i\}\cup HV(i-2)) & i \geq 2\end{cases}$
>
>Convertito
>
>$DP[i]=\begin{cases}\emptyset & i=0\\ D[1] & i=1 \\ max(DP[i-1], DP[i-2]+D[i]) & i \geq 2\end{cases}$

Il nocciolo della questione è che ci troviamo in una situazione dove dobbiamo valutare il  risultato maggiore considerando l'elemento attuale e saltando l'elemento precedente, o ignorare l'elemento attuale.
Quindi:
$$DP[i]=\begin{cases}0&i=0\\D[1]&i=1\\max(DP[i-1], DP[i-2]+D[i])&i>1\end{cases}$$
Dove $D$ è il vettore contenente le offerte. In codice:
```
DP[] = new int[n]
DP[0]=0
DP[1]=D[1]
for [i from 2 to n]{
	DP[i]=max(DP[i-1], DP[i-2] + DP[i])
}
return DP[n]
```

Questo algoritmo ci da il risultato massimo, ma non gli elementi selezionati, questi si possono individuare scorrendo $DP$ da $n$ a $1$ e ritornando gli elementi tali che $DP[i] =DP[i-2]+D[i]$ 

Sotto struttura ottima

## Zaino

> [!example]- Zaino
> _Dato un insieme di oggetti, ognuno caratterizzato da un peso e un  profitto, e uno "zaino" con un limite di capacità, individuare un  sottoinsieme di oggetti:_
> _il cui peso sia inferiore alla capacità dello zaino_
> _il valore totale degli oggetti sia massimale, i.e. più alto o uguale al valore di qualunque altro sottoinsieme di oggetti_
> _Dati vettore dei pesi, dei profitti e la capacità dello zaino, ritornare l'insieme degli oggetti che ritornano il massimo profitto_
> 
> Valutiamo una matrice con indice degli oggetti e la capacità residua. Valutiamo se prendiamo o meno l'oggetto, quindi:
>
> $DP [i][c] = DP [i − 1][c − w[i]] + p[i]$
>  oppure
> $DP[i][c]= DP[i-1][c]$
> 

Questo esercizio è simile al precedente, ma invece che considerare un piccolo pool di elementi alla volta, bisogna considerare l'intero insieme. Inoltre, non solo dobbiamo considerare il massimo guadagno, ma dobbiamo anche rispettare il limite della capienza. 
Quindi, in questo caso, se scegliamo un oggetto, il valore è aggiunto in una matrice con come righe la capienza
$$DP[i][c]=\begin{cases}0&i=0\ or\ c=0\\-\infty&c<0\\max(DP[i-1][c-w[i]]+p[i], DP[i-1][c])&else\end{cases}$$
In codice:
```
DP[][] = new int[n][C]
foreach [cell in DP[i][] ]{
	cell = 0
}
foreach [cell in DP[][C]]{
	cell = 0
}

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

La complessità è $O(n2^k)$ 

# Memoization
A differenze della programmazione dinamica, la memoization si muove in top-down. Questo vuol dire che gli algoritmi calcolano soltanto le soluzione che sono necessarie alla soluzione del problema

La tabella $DP$ viene generata con in ogni cella un token che indica che il problema non è ancora stato risolto

## Zaino
Riprendendo il problema dello zaino, l'inizializzazione della tabella:
```
DP = new int[n][C]
for [i from 1 to n]{
	for[c from 1 to C]{
		DP[i][c] = -1
	}
}
```

Algoritmo dello zaino ricorsivo:
```
int zainoRec(int[] w, int[] p, int i, int c, int[][]DP ){
	if [c<0]{
		return -infty
	} else if [i == 0 or c == 0]{
		return 0
	} else {
		if [ DP[i][c] < 0 ]{
			DP[i][c] = max(zainoRec(w,p,i-1,c,DP), 
				zainoRec(w,p,i-1,c-w[i], DP) + p[i])
		}
		return DP[i][c]
	}
}
```

Il costo di inizializzazione è $O(nC)$. Il costi di esecuzione cambia se si usa una hashTable in $O(min(2^n,nC))$

## Zaino senza limiti
Questa variante rimuove il limite di volte che un oggetto può esser preso. Questo semplifica il problema è ci permette di semplificare la soluzione:
Impostiamo un vettore $DP[]$ dove $DP[c]$ è il valore massimo a capienza $c$.
Di conseguenza la formula ricorsiva diventa:
$$DP[c]=\begin{cases}0&c=0\\max_{w[i]\leq c}\ \{DP[c-w[i]] + p[i]\}&c>0\end{cases}$$
In codice:
```
int zainoRecLibero(int[] w, int[] p, int n, int c, int[] DP){
	if [c == 0]{
		return 0
	}
	if [DP[c] < 0]{
		int maxSoFar = 0
		for [i from 1 to n]{
			if [w[i] <= c]{
				int val = zainoRecLibero(w,p,n,c-w[i],DP) + p[i]
				maxSoFar = max (maxSoFar, val)
			}
		}
		DP[c] = maxSoFar
	}
	return DP[c]
}
```

Lo spazio occupato equivale a $\Theta(C)$. Inoltre, per avere gli elementi inseriti, conviene tenere un vettore di interi a parte

## Sottosequenza comune massimale

> [!example]-DNA
> I caratteri di una stinga possono essere A,C,G,T. Date due stringhe definire quanto sono simili

Teniamo come definizione distanza di edit, ossia il numero di caratteri da ignorare per ottenere la stringa richiesta, e la funzione prefisso $T()$ dove $T(3)$ è il prefisso dei primi 3 caratteri della stringa $T$
L'obbiettivo del problema è date due stringhe trovare la stringa comune più lunga

#### Soluzione ricorsiva
Si controllano l'ultimo carattere delle due stringhe, da qui si generano due casi:
- se coincidono, allora si concatena l'ultimo carattere al risultato della funzione ricorsiva alimentata dalle stringhe -1 carattere
- se divergono, allora si sdoppia la funzione dove in un caso è la prima stringa a togliere un carattere, nel secondo l'altra
Infine il caso base, dove almeno una delle due stringhe è vuota, ritorna $\emptyset$  
Da qui:
$$LCS(T(i), U(j))=\begin{cases}\emptyset&i=0\ or\ j=0\\LCS(T(i-1), U(j-1))\bigoplus t_i&t_i= u_j\\longest(LCS(T(i-1), U(j)), LCS(T(i), U(j-1)))&t_i\neq u_j\end{cases}$$

#### Soluzione in DP
Possiamo dedurre la formula della DP per ottenere la semplice lunghezza massima:
$$DP[i][j]=\begin{cases}0&i=0\ or\ j=0\\DP[i-1][j-1]+1&t_i= u_j\\max(DP[i-1][j], DP[i][j-1])&t_i\neq u_j\end{cases}$$
da qui il codice:
```
DP = new int[n][m]
foreach [cell in DP[][0]]{
	cell = 0
}
foreach [cell in DP[0][]]{
	cell = 0
}
for [i from 1 to n]{
	for [j from 1 to m]{
		if [ T[i] == U[i] ]{
			DP[i][j] = DP[i-1][j-1]+1
		} else {
			DP[i][j] = max(DP[i][j-1],DP[i-1][j])
		}
	}
}
return DP[n][m]
```
La complessità è $O(mn)$

Per ricostruire la soluzione usiamo una funzione ricorsiva che naviga la matrice e aggiunge gli elementi in list quando uguali:
```
List subsequence(int[][] DP, Item[]T, Item[]U, int i, int j){
	if [i==0 or j==0]{
		return  List()
	}
	if [T[i]==U[j]]{
		S = subsequence(DP,T,U,i-1,j-1)
		S.append(T[i])
		return S
	} else {
		if [DP[i-1][j] > DP[i][j-1]]{
			return subsequence(DP,T,U,i-1,j)
		} else {
			return subsequence(DP,T,U,i,j-1)
		}
	}
}
```
La complessità è $O(m+n)$

Nel caso la ricostruzione della soluzione non è necessario, si può modificare `lcs()` in modo da usare dei vettori che conservino solo l'elemento precedente e non l'intera riga

```
int lcs(Item[ ] T, Item[ ] U, int n, int m) {
	DP' = new int[m]
	DP = new int[m]
	for [j from 0 to m {
		DP[j] = 0 
	}
	for [i from 1 to n] {
		DP' , DP = DP, DP'
		DP[0] = 0 
		for [j from 1 to m]{
			if [T[i] ==U[j]] {
				DP[j] = DP' [j − 1] + 1
			} else {
				DP[j] = max(DP0 [j], DP[j − 1])
			}
		}
	}
	 return DP[m]
}
```

## String matching approssimato

L'occorrenza $k$-approssimata di $P$ in $T$ è una sottostringa di $T$ che, modificando al più $k$ caratteri, è uguale a $P$. Queste modifiche possono essere sostituzione, inserimento o eliminazione.

Il problema richiede di trovare il minimo valore $k$ per approssimare $P$ in $T$ 

Definiamo la tabella $DP[i][j]$ come il minimo valore $k$ per un approssimazione di $P(i)$ in $T(j)$. Da qui:
- avanza su entrambi i caratteri in caso siano uguali o si effettui una sostituzione
- avanza su $P$ (pattern) in caso di inserimento
- avanza su $T$ (testo) in caso di cancellazione
In più i casi base sono: 
- Se $i=0$, allora ho finito il pattern, quindi non ho bisogno di ulteriori modifiche quindi ritorno $0$
- Se $j=0$, allora ho finito la parola, quindi avrò bisogno di tanti inserimenti quanti caratteri del pattern mi mancano, quindi ritorno $i$ 

Quindi, in equazione di ricorsione:
$$
DP[i][j]=\begin{cases}0&i=0\\i&j=0\\\delta=if(P[i]=T[i], 0, 1);&else\\min\left(DP[i-1][j-1]+\delta,\quad DP[i][j-1]+1,\quad DP[i-1][j]+1\right)\end{cases}
$$

Il risultato corrisponde al valore più piccolo dell'ultima riga, ossia $min(DP[m])$ 

In codice:
```
DP = new int[m][n]
for [j from 0 to n]{
	DP[0][j] = 0
}
for [i from 0 to m]{
	DP[i][0] = i
}
for [i from 1 to m]{
	for [j from 1 to n]{
		DP[i][j] = min(DP[i-1][j-1]+if[P[i]==T[j],0,1],
						DP[i-1][j]+1,
						DP[i][j+1])
	}
}
int pos = 0
for [j from 1 to n]{
	if [DP[m][j]<DP[m][pos]]{
		pos = j
	}
}
return pos
```


> [!important]+ Take home
> Non per forza la soluzione è in basso a destra

## Prodotto di catena di matrici


> [!warning] Parte 3 slide 11

## Insieme indipendente di intervalli pesati

Dati $n$ intervalli $[(a_1,b_1),...,(a_n,b_n)]$, dove $a_i$ è il tempo di inizio dell'intervallo $i$ e $b_i$ il tempo di fine, con associato un profitto $w_i$, trovare l'insieme di profitto massimo

definiamo come disgiunti due intervalli tali che $b_j\leq a_i$ oppure $b_i\leq a_j$ 

Per risolvere questo esercizio è prima necessario calcolare il predecessore di ogni intervallo, ossia l'elemento con il massimo tempo di fine prima dell'inizio dell'elemento. In caso questo elemento non esiste, allora si prende $0$

$$DP[i]=\begin{cases}0&i=0\\max(DP[i-1], DP[pred_i]+w_i)&i>0\end{cases}$$

In codice:

```
int[] getPredecessors(int[]a, int[]b, int n){
	pred = new int[n]
	pred[0]=0
	for [i from 1 to n]{
		j = i-1
		while [j>0 and b[j]>a[i]]{
			j=j-1
		}
		pred[i]=j
	}
	return pred
}
```

questo può essere ottimizzato preordinando il vettore degli intervalli in modo crescente per tempo di fine intervallo. Questo permette di escludere l'intervallo $i$ se prendendone uno precedente, ma con lo stesso tempo di fine, porta a un valore $DP[j]$ più alto

quindi:
```
Set maxInterval(int[] a, int[] b, int n){
	//ordinamento intervalli
	pred = getPredecessors(a,b,n)
	DP= new int[n]
	DP[0]=0
	for [i from 1 to n]{
		DP[i] = max(DP[i-1], DP[pred[i]] + w[i])
	}
	i = n
	s = Set()
	while [i>0]{
		if[DP[i-1]>w[i]+DP[pred[i]]]{
			i--
		} else {
			s.insert(i)
			i= pred[i]
		}
	}
	return s
}
```

Complessità di ordinamento + calcolo processori + riempimento tabella e ricostruzione della soluzione: $O(n\ log\ n)$ 


> [!important]+ Take home
> A volte è necessario pre processare i dati
