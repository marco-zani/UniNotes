
# Risoluzione dei problemi
Possiamo seguire la soluzione di un problema in 4 fasi:
1. Classificazione
2. caratterizzazione della soluzione
3. Tecnica di progetto
4. Strutture dati

## Classificazione dei problemi
Si distinguono in:
- Problemi decisionali
	- Un dato soddisfa una certa proprietà?
- Problemi di ricerca
- Problemi di ottimizzazione

## Caratterizzazione delle soluzioni
Abbiamo a disposizione:
- Divide-et-impera
	- Divisione dei problemi in sotto-problemi risolti poi ricorsivamente (top-down)
	- Applicato a problemi di decisione e ricerca
- Programmazione dinamica
	- Soluzione costruita bottom-up da sotto-insiemi potenzialmente ripetuti
	- Applicato a problemi di ottimizzazione
- Memoization
	- Programmazione dinamica ma top-down
- Greedy
	- Si applica la scelta localmente ottima
- Backtrack
	- procedura a tentativi con possibile ripristino a condizione precedente
- Ricerca locale
	- Soluzioni temporanee che vanno a definire la soluzione finale ottima
- Algoritmi probabilistici
	- Scelta con giudizio costosa o causale e gratuita?

# Divide-et-impera
Come suggerito dal nome, Questi algoritmi si compongono di una fase di divisione in sotto-problemi, soluzione ricorsiva e unione delle soluzioni

# Esempi
## Minimo divide et impera
```
int minRec(int a[], int i, int f){
	if(i==f){
		return a[i]
	} else {
		m = (i+j)/2
		return min(minRec(a,i,m),minRec(a,m,f))
	}
}
```
con complessità
$$T(n)=\begin{cases}2T(n/2)+1&n>1\\1&n=1\end{cases}$$

## Quicksort
Consiste nello scegliere un elemento di perno (pivot) e trovare la sua posizione spostando tutti gli elementi minori alla sua sinistra e i maggiori alla destra. Fatto questo si ripete l'algoritmo sui sotto gruppi a lato dell'elemento

```
quickSort(Item a[], int low, int high){
	if[low < high]{
		int j = partition(a,low,high)
		quickSort(a,low, j-1)
		quickSort(a, j+1, high)
	}
}

int partition(Item a[], int low, int high){
	Item pivot = a[lo]
	int j = low
	for [i=low+1 to high]{
		if [ a[i]<pivot ] {
			j++
			swap(a[i],a[j])
		}
	}
	a[low] = a[j]
	a[j]=pivot
	return j
}
```

^a392a4

