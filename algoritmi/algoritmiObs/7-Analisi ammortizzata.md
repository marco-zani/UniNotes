# Ammortizzazione
È un metodo di analisi della complessità nel caso pessimo. È un analisi deterministica, su molteplici operazioni e si basa sul concetto che le operazioni meno costose vadano ad ammortizzare le operazioni più costose ma poco frequenti

> [!Important]+ Esempio del contatore binario
> Un vettore dei booleani $A$ dove ogni posizione rappresenta un bit. È di lunghezza $k$ e il valore si calcola con $$x=\sum^{k-1}_{i=0}A[i]\cdot2^i$$
> Implementa la funzione `increment()`:
>```
>increment(int A[], int k){
>	int i = 0
>	while [i<k and A[i]==1]{
>		A[i]=0
>		i++
>	}
>	if [i<k]{
>		A[i]=1
>	}
>}
>```

## Metodo dell'aggregazione
Calcola la complessità $T(n)$ per $n$ operazioni nel caso pessimo e si divide per $n$ operazioni (si fa la media)

Nell'esempio per rappresentare un numero $n$ abbiamo bisogno di $log(n+1)$ bit e `increment()` richiede al massimo $O(k)$. Per incrementare a $n$ chiamiamo `increment()` $n$ volte, con complessità massima $O(k)$, quindi $n\ O(k)=O(kn)$. Dividiamo per il numero di operazioni $n$, quindi $O(kn)/n=O(k)=O(log\ n)$. Il costo ammortizzato è $log\ n$

## Metodo degli accantonamenti
Si assegna alle operazioni un costo ammortizzato maggiore o minore di quello effettivo

## Metodo del potenziale
Si descrive lo stato del sistema con una funzione di potenziale

# Vettori dinamici
Prendendo in esempio tutte le strutture dati che necessitano di espansione (vettori, hash table...), esse necessitano di funzioni di espansione e contrazione. Queste funzioni vengono applicate quando il fattore di carico $\alpha$ (dim/capacità) supera una certa soglia.
Tipicamente:
- Espansione: $0.5<\alpha<0.75$
- Contrazione: $\alpha<0.25$

L'espansione consiste nel raddoppio della dimensione