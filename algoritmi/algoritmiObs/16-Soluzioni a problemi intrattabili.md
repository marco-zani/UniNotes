Dei diversi tipi di soluzioni, ognuna rinuncia a qualcosa per la sua soluzione:
- algoritmi pseudo-polinomiali: sono efficienti sono per alcuni tipi di input (Generalità)
- approssimazione: forniscono soluzioni vicine a quella ottimale (Ottimalità)
- euristici: forniscono sperimentalmente buoni risultati (Formalità)
- branch&bound: richiedono accurate potature (Efficienza)

# Algoritmi pseudo-polinomiali
## Dimensioni del problema
Corrisponde alla lunghezza della stringa che codifica un'istanza

Il valore $\#$ invece è il più grande valore all'interno dell'istanza

## Algoritmi fortemente/debolmente $\mathbb{NP}$-completi 

> [!warning] slide 13
# Algoritmi di approssimazione
Bisogna dimostrare che la soluzione che non si discosti al più di $\alpha$ rispetto al costo della soluzione ottima
$$c(x*)\leq c(x)\leq c(x*)\cdot\alpha(n)$$
## Bin-packing approssimato
> [!warning] slide 29
## TSP con Disuguaglianze triangolari
un grafo con disuguaglianze triangolari è un grafo dove per ogni collegamento tra 2 città, passare per un intermediario è meno conveniente

Inoltre consideriamo che un circuito Hamiltoniano, rimosso un arco, diventa un albero di copertura minimo

A questo punto possiamo usare il seguente processo:
1. Prendiamo un albero di copertura minimo
2. sostituiamo ogni arco con due archi orientati in direzioni opposte
3. per la disuguaglianza triangolare, formiamo nuovi archi diretti tra le città

il risultato di questa operazione è un circuito Hamiltoniano minimo di dimensione al massimo 2 volte quella dell'albero di copertura
# Algoritmi euristici
Non forniscono una soluzione necessariamente ottima o approssimata, ma valida. Si applicano spesso tecniche greedy o di ricerca locale
## TSP greedy
Partendo da una città visitiamo quella più vicina senza mai ripassare per città già visitate
## TSP ricerca locale
miglioramento dell'algoritmo greedy: possiamo cancellare due archi non consecutivi e sostituirli con archi di costo minore (costo di esaminazione $O(n^2)$) 
# Branch&Bound
Si definiscono un limite superiore e uno inferiore con il compito di prevedere la direzione della soluzione: se i due si incontrano, allora si può fermare l'esecuzione di questo ramo per favorirne lo sviluppo di altri
## TSP
In questo caso possiamo effettuare numerosi controlli per verificare il costo della funzione:
- la somma degli archi percorsi
- il minimo fra tutti gli archi che vanno verso nodi non ancora scelti
- per ogni nodo non scelto, il minimo verso nodi non ancora scelti o la chiusura del circuito
- il minimo della somma tra entrata e uscita di un nodo