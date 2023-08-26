# Introduzione
## Definizioni
- Tabelle hash: vettori che memorizzano una chiave
- funzione hash: funzione che trasforma una chiave in un hash 
- Collisione: quando due chiavi forniscono lo stesso hash

## Tabelle ad accesso diretto
Con gruppi piccoli usiamo un hash di identità ($h(k)=k$) 

## Funzioni hash perfette
Sono funzioni iniettive, ovvero senza collisioni. Sono però difficili da ottenere
L'obbiettivo di conseguenza è cercare di distribuire il più uniformemente le chiavi negli indici

In forma matematica definiamo come $P(k)$ la probabilità di inserire una chiave $k$ e $Q(i)$ la probabilità che una chiave finisca nella cella $i$, allora:
$$Q(i)=\sum_{k\in U:h(k)=i}P(k)$$
Una funzione gode di **uniformità semplice** se la probabilità $Q(i)$ è uguale a $\frac{1}{m}$ dove $m$ sono il numero di celle nella tabella

# Funzioni Hash
Per riuscire a raggiungere l'uniformità semplice dobbiamo conoscere la distribuzione di $P$. Questo può essere solo approssimato con tecniche euristiche

Generalmente convertiamo la chiave nel suo valore numerico

## Funzioni semplici
Usiamo come per esempio la trasformazione delle stringhe

Come primo passaggio convertiamo le singole lettere in binario, poi possiamo applicare:
- Estrazione: estraiamo una sotto-stringa dal binario
	- Questo però ha un'alta probabilità di generare conflitti
- XOR: Possiamo effettuare la somma bit a bit su sotto-insiemi della stringa 
	- Questo può generare conflitti in caso di anagrammi
- Divisione: Applichiamo il modulo al numero risultante
	- Usando il modulo di $m$, meglio se $m$ grande, primo e distante dalla potenze di 2 e 10

#### Metodo della moltiplicazione (Knuth)
Prendiamo $m$ come potenza di 2  e $C$ come costante tra 0 e 1 (esclusi). La formula corrisponde a:
$$\lfloor m\cdot(C\cdot k-\lfloor C\cdot k\rfloor)\rfloor$$
Questo metodo però manca dell'avalanche effect (cambio un valore cambia tutto l'hash) 

## Funzioni moderne
FNV, Murmur, City e Farm hash

# Gestione collisioni
In caso la posizione sia già occupata, dobbiamo trovare posizioni alternative

## Liste di trabocco
Chiamate anche concatenamento o chaining, consistono nel gestire una cella di una tabella come lista dinamica.

Per l'inserimento degli elementi bisogna consultare la coda della cella, mentre per il `lookup()` e la rimozione bisogna anche scansionare la lista

#### Costi
Considerando $n$ come numero di chiavi, $m$ capacità della tabella, $\alpha=n/m$ fattore di carico:

|azione|costo|
|--|--|
|hashing|$\Theta(1)$|
|Ricerca senza successo|$\Theta(1)+\alpha$|
|Ricerca con successo|$\Theta(1)+\alpha/2$|

## Indirizzamento aperto
È una soluzione più semplice rispetto alle liste di trabocco.
Consiste nel trovare un nuovo slot libero in caso di conflitto

Definiamo come sequenza di ispezione gli indici ordinati che vengono esaminati in caso di conflitto

#### Ispezione lineare (primary clustering)
$$H(k,i)=(H_1(k)+h\cdot i)\ mod\ m$$
In caso di conflitto si passa allo slot successivo, si ripete finché non si trova uno slot libero.

All'aumentare delle ispezioni aumentano anche i tempi di inserimento e cancellazione

##### Ispezione quadratica (secondary clustering)
$$H(k,i)=(H_1(k)+h\cdot i^2)\ mod\ m$$
Invece che saltare lo slot di 1, lo si salta di un valore quadratico rispetto alla permutazione (1,4,9,16....)

#### Doppio hashing
$$H(k,i)=(H_1(k)+H_2(k)\cdot i)\ mod\ m$$
si applica l'hashing anche per determinare le successive ispezioni


> [!warning] slide 49 implementazione hashing doppio

## Cancellazione
Non possiamo semplicemente cancella un elemento, perché se si trova nel mezzo di una concatenazione si vanno a perdere gli elementi successivi, per questo si usa un elemento speciale `del` invece di `nil`

