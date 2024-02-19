# Introduzione
#### Proprietà degli algoritmi
- efficienza (tempo e spazio impiegato)
- correttezza
- semplicità, manutenibilità, espandibilità, robustezza...
# Analisi degli algoritmi
La complessità è la relazione tra la dimensione dell'input e quella dell'output
#### Notazioni
- $O$ : casistica peggiore
- $\Omega$ : casistica migliore
- $\Theta$ : casistica media/esatta
## Algoritmi
- **Selection sort**: Trova l'elemento minimo del vettore e lo sposta nel primo slot non ordinato
- **Insertion sort**: Scorre gli elementi fino ad individuare una posizione in cui è maggiore del precedente
- **Merge sort**: divide il vettore in due sotto vettori, ripete fino a rimanere con due elementi, poi li ordina. Infine riordina fra loro i vettori già ordinati 
# Analisi delle funzioni
#### Proprietà
- Eliminazione delle costanti: $O(af(x))=O(f(x))$
- Sommatoria: $O(f(x)+g(x))=O(max(f(x),g(x)))$
- Cicli annidati
- Simmetria e transitività
- Logaritmi:  $log\ n=O(n)$
#### Ricorsione
Forma dell'equazione di ricorrenza (merge sort):
$$T(n)=\Theta(n\ log\ n)=\begin{cases}T(n/2)+\Theta(n)&n>1\\ \Theta(1)&n\leq1\end{cases}$$
I metodi per la risoluzione sono:
- **Analisi per livelli**: si analizza ogni livello della ricorsione
- **Analisi per tentativi** (o sostituzione): ipotiziamo una classe di difficoltà e poi confrontiamo usando il metodo dell'induzione
<div style="page-break-after: always;"></div>
#### Master theorem
Sono delle casistiche comuni alla quale si può applicare una formula in base alla forma della funzione ricorsiva

| Nome | Forma | Soluzione |
| ---- | ---- | ---- |
| Ricorrenze lineari con partizione bilanciata | $T(n)=\begin{cases}aT(n/b)+n^\beta&n>1\\d&n\leq1\end{cases}$ | $T(n)=\begin{cases}\Theta(n^\alpha)&\alpha>\beta\\\Theta(n^\alpha log\ n)& \alpha=\beta\\\Theta(n^\beta)&\alpha<\beta\end{cases}$ |
| Ricorrenze lineari di ordine costante | $T(n)=\begin{cases}\sum_{i=1}^h a_iT(n-i)+n^\beta&n>h\\\Theta(1)&n\leq h\end{cases}$ | $T(n)=\begin{cases}\Theta(n^{\beta+1})&a=1\\\Theta(a^nn^\beta)&a\geq 2\end{cases}$ |
## Problemi
#### Problema delle scale
In quanti modi diversi si possono salire $n$ scalini in $k$ modi alla volta. Lo scopo è trovare la funzione ricorsiva adatta, ossia:
$$M(n)=\begin{cases}1&n\leq 0\\M(n-1)+...+M(n-k)&n>0\end{cases}$$
# Strutture dati
#### Tipologie di dati
 - Astratto/primitivo (fornito o implementato nel linguaggio)
 - lineari/non (presenza di sequenze)
 - statici/dinamici
 - Omogeneei/disomogenei
## Strutture comuni
#### Sequenze
Dinamica, lineare, ordinata e ammette ripetizioni, implementa funzioni come: `isEmpty`, `finished`,`head`,`tail`,`next`,`prev`,`insert`,`remove`,`read`,`write`
#### Insieme
Dinamica, non lineare, disordinata e senza ripetizioni. Implementa `size`,`contains`,`insert`,`remove`,`union`,`intersection`,`difference`
#### Dizionari
Rappresentano relazioni univoche chiave-valore. Implementa `lookup`,`insert`,`remove`
#### Alberi e grafi
insiemi di nodi, l'albero presenta anche un nodo radice, mentre i grafi non presentano ordini specifici
#### Lista
Nodi contenenti valori e puntatori all'elemento successivo. Le varianti includono: mono/bidirezionale, presenza di una sentinella (primo elemento vuoto), circolari o meno
<div style="page-break-after: always;"></div>

#### Pila
Variante della lista, le operazioni `insert` e  `remove` riguardano il primo elemento (LIFO)
#### Coda
Variante FIFO della lista
#### Varianti
- insieme -> vettore booleano
- albero -> vettore dei padri

# Alberi
#### Albero radicato
La base di un qualsiasi albero, è un grafo con un nodo a radice e un cammino unico per raggiungere ciascuno degli altri nodi

Ogni nodo dell'albero è radice del suo sotto albero. I nodi vengono classificati per relazione (padri, figli e fratelli) o per posizione nell'albero (radice, foglie e nodi interni)
#### Metodi di memorizzazione
Vettore dei figli (basilare), puntatore a padre, primo figlio e prossimo fratello, oppure vettore di tuple contenenti valore e indice del nodo padre
## Strutture
#### Alberi binari
Caratterizzati dalla presenza di al massimo 2 figli per ogni nodo. Implementano `read`,`write`,`parent`,`left`,`right`,`insertLeft`,`insertRight`,`deleteLeft`,`deleteRight`
#### Alberi binari di ricerca
I valori vengono ordinati inserendo i valori minori nel figlio sinistro e quelli maggiori in quello destro. Implementano `lookup`,`min`,`max`,`successor`,`predecessor`. Nel dettaglio `successor` e `predecessor` risalgono e/o riscendono l'albero per trovare l'elemento richiesto

l'eliminazione richiede di effettuare un riordinamento specifico, sostituendo il nodo con il suo successore e riposizionando il figlio destro
#### Alberi Red-Black
Sono alberi che usano la colorazione dei nodi per garantire il bilanciamento dell'albero, riducendo al minimo il tempo di ricerca. Le regole che implementano sono:
- Radici, foglie e tutti i figli di un nodo rosso sono neri
- I cammini dalla radice ad ogni foglia hanno lo stesso numero di nodi neri

Nel caso, durante un inserimento, queste regole vengano rotte, si applica una rotazione sull'albero per ribilanciare il tutto. Anche nel caso dell'eliminazione di un nodo nero è necessario applicare un ribilanciamento
<div style="page-break-after: always;"></div>

## Algoritmi
#### Visita in profondità (DFS)
Visita i nodi in modo ricorsivo, scendendo il sotto-albero prima di passare al nodo fratello. La stampa può essere in pre/in/post order
#### Visita in ampiezza (BFS)
Visita tutti i nodi di un livello prima di procedere al successivo, aggiungendo a una coda tutti i nodi figli e processandoli LIFO
## Problemi
- Implementazione di dizionari e ricerca dicotomica
# Grafi
#### Definizioni
- Grafi orientati 
- Adiacenza
- Cardinalità di un nodo
- Cammini
- Tipi di grafi:
	- completo
	- sparso/denso
	- libero
	- foreste
- Componenti connesse: nodi raggiungibili tra loro. Nel caso dei grafi orientati, si definiscono fortemente connessi
- Raggiungibilità: in un grafo orientato è possibile che fra due nodi solo uno possa raggiungere l'altro
- cicli
#### Specifiche
Implementano `size`,`insertNode`,`insertEdge`,`deleteNode`,`deleteEdge`

Possono essere memorizzati con matrici e liste d'adiacenza, oppure con nodi e puntatori
## Algoritmi
#### BFS
Uguale alla BFS degli alberi, visita prima i nodi più vicini prima di spostarsi 
#### DFS
Uguale alla DFS degli alberi
<div style="page-break-after: always;"></div>

#### CC (algoritmo per l'individuazione delle componenti connesse)
Applico molteplici volte dfs fino ad aver visitato tutti i nodi. Ogni nuova applicazione corrisponde a una nuova componente connessa
#### Algoritmo di Kosaraju
1. Applico l'ordinamento topologico sul grafo
2. Genero il grafo trasposto
3. Applico l'algoritmo per le componenti connesse, partendo dai nodi con tempo di fine più basso trovato dall'ordinamento topologico
le componenti connesse trovate sono fortemente connesse
## Problemi 
#### Cammino più breve
Si risolve con BFS
#### Ordinamento topologico
Si risolve con DFS. Ci possono essere più ordinamenti, o nessuno nel caso di cicli
#### Identificazione delle componenti connesse
Si risolve applicando molteplici volte la DFS finché tutti i nodi non vengono visitati
#### Identificazione dei cicli
Si risolve con DFS. Ritorna true non appena incontra un elemento già visitato
#### Albero di copertura
Per ogni nodo non visitato si aggiunge un arco nell'albero di copertura
#### Identificazione di connessioni forti
Applico l'algoritmo di Kosaraju

# Hashing
#### Definizioni
- tabelle e funzioni hash
- collisione
- funzioni di hashing perfette (senza collisioni)
- Avalanche effect: il cambio minimo di un valore porta a uno cambio completo dell'hash
## Funzioni di hashing 
#### Estrazione
Viene estratta una sotto-stringa del binario del valore. Alta probabilità di conflitti
<div style="page-break-after: always;"></div>

#### XOR
Si applica lo XOR su sotto-insiemi del binario. Genera conflitti in caso di anagrammi
#### Divisione
Viene applicato un modulo $m$. $m$ è indicato come un numero primo, grande e lontano dalle potenze di $2$ e $10$
#### Moltiplicazione di Knuth
Sfrutta la funzione $\lfloor m\cdot(C\cdot k-\lfloor C\cdot k\rfloor)\rfloor$ dove $m$ è potenza di $2$ e $C$ è costante  $(0,1)$. Manca l'avalanche effect
#### Funzioni di hashing moderne
FNV, Murmur, City e Farm hash
## Gestione collisioni
#### Liste di trabocco
Ad ogni slot dell'hash corrisponde una lista dinamica
#### Indirizzamento aperto
Cerca un nuovo slot libero secondo uno dei seguenti principi:
- Ispezione lineare: cerca il primo slot successivo
- Ispezione quadratica: cerca lo slot successivo effettuando salti di $i^2$ dove $i$ è il numero di salti
- Doppio hashing: Riapplica l'hashing per individuare un nuovo slot

In caso di cancellazione si sostituisce con un valore `del` piuttosto che `nil` in modo da permettere l'indirizzamento aperto
# Divide-et-impera
## Classificazione di problemi e soluzioni
Problemi:
- decisionali (se una proprietà è rispettata)
- ricerca
- ottimizzazione
Soluzioni
- Divide-et-impera -> decisione e ricerca
- Programmazione dinamica/Memoization -> ottimizzazione
- Greedy
- Backtrack
- Ricerca locale
- Probabilistiche
## Algoritmi
<div style="page-break-after: always;"></div>

#### QuickSort
Si sceglie un elemento mediano come pivot, e si spostano tutti gli elementi minori a sinistra e maggiori a destra, questo si poi ripete ricorsivamente per il sottovettore di sinistra e il sottovettore di destra
#### Algoritmo di Strassen 
Divide le matrici $n\times n$ in 4 matrici $n/2\times n/2$, fino ad arrivare e calcolare le matrici $2\times2$ 
## Problemi
#### Torri di Hanoi
#### Moltiplicazioni di matrici
Si applica l'algoritmo di Strassen
#### Gap
Dato un vettore decrescente, trovare un elemento maggiore rispetto al precedente. La soluzione è analizzare i estremi
# Analisi ammortizzata
Analisi deterministica che ammortizza le operazioni più costose e rare con quelle meno costose e più comuni
## Metodi
#### Aggregazione
Effettua la media dei costi delle operazioni
#### Accantonamenti
Si usa una somma di costi ammortizzati che è limite superiore ai costi effettivi
#### Potenziale
Si mantiene da parte il quantitativo di potenziale conservato in uno stato per abbassare/alzare il costo dell'operazione

## Algoritmi
#### Contatore binario
Vettore di booleani dove ogni bit rappresenta $2^i$ dove $i$ è la posizione. Il valore si ottiene con la somma delle posizioni. Implementa la funzione `increment`
## Vettori dinamici
Sono i vettori che ridimensionano l'utilizzo della memoria in base al quantitativo di elementi contenuti, in particolare al fattore di carico (`size`/capacità)
# Strutture dati speciali
<div style="page-break-after: always;"></div>

#### Insiemi
È implementato come un vettore di booleani che implementa le funzioni `union`, `difference`, `intersection`
#### Insiemi disgiunti
Sono insiemi i cui elementi eleggono un rappresentante per indicare l'appartenenza a un insieme

Presenta due implementazioni molto efficienti: tramite lista oppure tramite albero. La prima ha un `find` $O(1)$ mentre la seconda un `merge` $O(1)$

Per una maggiore efficienza, si usano tecniche euristiche per bilanciare le strutture dati per operazioni più efficienti:
- Euristica del peso: Salvare la lunghezza della lista per appendere la lista più corta alla più lunga
- Euristica del rango: Si appende l'albero di altezza inferiore a quello di altezza superiore
- Compressione dei cammini: Si appiattiscono gli alberi in modo da avere altezza massima $1$
#### Code con priorità
Variante delle code, aggiunge una priorità associata ad ogni elemento, metodi per estrarre gli elementi più o meno importanti e per cambiare la priorità di un elemento
#### Heap
Un albero con rappresentazione vettoriale. La radice corrisponde a $1$ e i figli a $2i$ e $2i +1$ dove $i$ è indice dell'elemento. Implementa due funzioni aggiuntive `heapRestore` per correggere l'albero dopo l'inserimento di un nuovo elemento, e `heapBuild` per convertire da vettore normale a heap
# Programmazione dinamica
## Problemi
#### Domino
Problema di combinatoria. Tutte le possibili combinazioni in cui dei pezzi del domino possono essere inseriti in una certa area

La soluzione generica consiste nel scegliere una posizione e controllare ricorsivamente le condizioni ottenuti da quella posizione. Si sommano quindi i risultati di tutte le possibili posizioni
#### Hateville
Problema di scelta. In questo caso dobbiamo scegliere quali donazioni prendere considerando che questo ci esclude la possibilità di prendere le successive

La soluzione in questo caso è di confrontare le condizioni ottenute prendendo o meno una scelta, e verificare quale delle due ci da un maggior guadagno
#### Zaino
Sempre un problema di scelta, ma bisogna confrontare l'intero insieme di scelte. In più in questo caso l'esclusione non è data dalla vicinanza delle scelte, ma da una capienza totale

La soluzione è simile a quella di hateville, con la differenza che lo spostamento in caso di selezione va fatto in base alla capienza occupata. Inoltre vengono presi in considerazione tutti gli oggetti, uno alla volta (una riga alla volta)
<div style="page-break-after: always;"></div>

#### Zaino libero
Questa variante semplifica l'algoritmo in quanto non è necessario rimuovere un oggetto ma possono essere confrontati tutti ogni volta. Di conseguenza basta un vettore della capienza sulla quale si verifica il massimo guadagno di tutti gli oggetti
#### Sottosequenza comune massimale
Problema decisionale. La soluzione DP consiste nel spostare gli indici, trovare le lettere uguali e ritornare il valore più alto
#### String matching approssimato
Questa variante, invece di aumentare il valore ogni volta che si ritorna due indici uguali, aumenta nel caso della divergenza. Il risultato poi ritornerà il valore più piccolo
#### Prodotto di catena di matrici
Moltiplicare molteplici matrici richiede una parentesizzazione, l'ordine di queste può influire enormemente sul numero di calcoli necessari. 

La soluzione consiste nell'utilizzo di due matrici differenti, una per mantenere il numero di moltiplicazioni scalari, la seconda per il minor valore di $k$ (indice separatore della parentesizzazione) 
#### Insieme indipendente di intervalli pesati
Questo problema di ottimizzazione richiede una pre elaborazione, ossia ordinare gli intervalli per tempo di fine.

In questo modo è semplice verificare il massimo tra la scelta di prendere un intervallo e sommarlo agli elementi antecedenti piuttosto che ignorarlo
# Scelta della struttura dati
## Algoritmi
#### Dijkstra
Usa una coda di priorità per visitare gli elementi successivi. In caso di miglioramenti di un peso, esso viene aggiornato
#### Bellman-Ford-Moore
Simile a Dijkstra, ma quando un peso viene aggiornato, il nodo viene reinserito nella coda, questo permette di accettare elementi negativi e di individuare cicli negativi. Infatti l'algoritmo ottiene i cammini minimi in $n-1$ iterazioni, se ci sono ulteriori miglioramenti allora è presente almeno un ciclo negativo
#### Floyd-Warshall
Questo algoritmo permette di trovare la lunghezza dei cammini minimi fra tutte le coppie di nodi. Il funzionamento consiste nell'esaminare un nodo $k$ come intermediario, e ritornare il minimo tra il collegamento diretto tra i nodi o il passaggio tramite questo intermediario
## Problemi
<div style="page-break-after: always;"></div>

#### Cammini minimi
3 varianti:
- Tra due vertici
- Da un vertice a tutti gli altri
- Tra tutte le coppie di vertici
# Algoritmi greedy
## Problemi
#### Intervalli pesati
Questa variante richiede ritornare il numero massimo di intervalli indipendenti, senza alcun valore associato.

La soluzione ingorda ordina in tempo di fine, seleziona il primo elemento e il primo successivo. Si ripete fino a fine dell'intervallo

Dimostrazione:
Supponiamo una soluzione ottimale $A[i..j]$ e $k$ un intervallo in $A$, allora $A[i..k]$ e $A[k..j]$ sono sotto soluzioni ottimali
#### Problema del resto
Dare il resto con il minor numero di monete

La soluzione è usare sempre il taglio più alto inferiore al resto che si deve dare

Dimostrazione
# Ricerca locale
#### Definizioni
- Vincolo sulla capacità
- Simmetria opposta
- Conservazione del flusso
## Algoritmo delle reti residue (Ford-Fulkerson)
Consiste ripetere la ricerca di un cammino verso il pozzo, e qundo trovato di invertire i flussi con una quantità pari alla capienza massima del cammino trovato. Quando non si trovano più cammini allora si ha raggiunto il flusso massimo

La complessità consiste nella somma del numero di vertici e archi moltiplicata per il flusso massimo
# Backtracking
Utile per i problemi "trova una soluzione"
## Algoritmi
#### Jarvis
Seleziona il punto più a "sinistra" e calcola la linea retta che lo attraversa verticalmente, da li individua il punto ad un angolo minore e ricalcola la linea che attraversa entrambi i punti. Ripete fino a tornare al punto originale
#### Graham
Seleziona il punto più basso e ordina i punti in base all'angolo rispetto al punto selezionato e la retta orizzontale, e inserisce i primi due. Da qui aggiungiamo verifichiamo se i prossimi punti sono interni all'inviluppo rispetto alla retta passante per per gli ultimi due punti. Se si gli ignoriamo, se no eliminiamo l'ultimo vertice e aggiungiamo il nuovo. Ripete finché non finiscono i vertici

## Problemi
#### Problemi elementari
Stampa di tutti i sotto-insiemi possibili o le permutazioni di un insieme. 
#### $k$-Sottoinsiemi
sono i sotto-insiemi di dimensione $k$
#### Subset sum
Sotto-insieme di somma $k$
#### Le regine
Consiste nell'ottenere tutti i modi piazzare $n$ regine in una scacchiera $n\times n$ senza conflitti.
#### Sudoku
#### Knight tour
Ritorna una serie di mosse che permettano a un cavallo di attraversare una scacchiera $n\times n$ senza visitare due volte una cella
#### Generazione labirinti
#### Inviluppo convesso
Dati dei punti in un piano, disegnare un poligono senza angoli convessi

Si risolve con l'algoritmo di Jarvis o di Graham
# Algoritmi probilistici
# Problemi NP completi
# Soluzioni a problemi intrattabili