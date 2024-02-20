# Introduzione
Ci sono due tipi di algoritmi probabilistici:
- Montecarlo: dove la correttezza è probabilistica
- Las Vegas: dove il tempo di esecuzione è probabilistico
# Numeri primi
L'algoritmo deve determinare se il numero $n$ dato è primo o in caso contrario fornire i fattori che lo compongono
## Algoritmo di Fermat
Usufruisce del piccolo teorema di fermat, che afferma che esistono dei numeri pseudo-primi che rispettano la seguente proprietà:
$$b^{n-1}\ mod\ n=1$$
questo implica che se $b^{n-1}\ mod\ n$ è diverso da 1, allora $n$ non è sicuramente primo. Di conseguenza possiamo effettuare molteplici controlli su varie basi $b$, in modo che al primo `False` ci possiamo fermare
## Algoritmo Miller-Rabin
Simile a quello di fermat, richiede che due proprietà siano verificate:
- il minimo comune multiplo di $n$ e $b$ sia 1
- $b^m\ mod\ n=1$ e che per ogni $i<b$, $b^{m\cdot 2^i}\ mod\ n=n-1$ 
Se anche solo una delle due non è rispettata, allora $n$ non è primo
A questo punto si differenziano due tipi di basi:
- I testimoni, che provano che un numero non è primo
- I strong liars: numeri che indicano che $n$ è primo anche se non lo è
La presenza dei strong Liars è di 1/4 sull'insieme, quindi questo algoritmo è di tipo monte carlo con 1/4 di probabilità di ritornare un valore errato
# Bloom filters
Sono l'unione tra i bitSet (elenchi prefissati di oggetti rappresentati in bit) e le hash tables. 
Questa struttura dati dinamica occupa poca memoria, però utilizza una risposta probabilistica

Quando si verifica se un elemento fa parte del bloom filter, i valori di ritorno sono:
- Sicuramente non è presente
- potrebbe essere presente

I bloom filters vengono usati per verificare se è necessario fare un'operazione più costosa o meno (tipo operazioni I/O o in rete)

# Valori statistici
Alcuni algoritmi usano valori come:
- media
- varianza
- moda (valori più frequenti)

## Trovare l'elemento in posizione $k$
