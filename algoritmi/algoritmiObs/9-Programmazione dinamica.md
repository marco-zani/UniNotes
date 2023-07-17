Alcuni problemi ricalcolano sotto-problemi già calcolati. La soluzione è memorizzare i risultati

> [!important]+ NB: tabella
> La tabella deve essere facilmente indirizzabile (O(1)). Quindi per esempio hash table

![[schemaProblemi.png]]

> [!example]+ Domino
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


> [!example]+ Hateville
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

Sotto struttura ottima


> [!example]+ Zaino
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

# Memoization