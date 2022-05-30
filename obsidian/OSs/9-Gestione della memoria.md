# Introduzione
La memoria condivisa è importante per un sistema efficente, ma comporta problemi di gestione e protezione delle zone di memoria

L'allocazione in memoria di un programma, ossia la conversione in processo, diventa un vincolo dato che a ogni fase di conversione richiede una diversa semantica degli indirizzi di memoria.

Il collegamente tra indirizzo simbolico (nel programma) e indirizzo fisico (nel processo)
viene definito **binding**

#### Binding & indirizzi
Il binding degli indirizzi può venire in 3 momenti, **2 statici** e **uno dinamico**:
- a compile time (statico)
- a load time (statico)
- a run time (dinamico)

#### Collegamento (linking)
È diviso in statico, dove i riferimenti sono definiti e le librerie copiate nell'immagine del processo, e dinamico, dove i riferimenti (**stub**) servono a recuperare le librerie

#### Loading
Il codice è tradizionalmente caricato in memoria per l'esecuzione, ma nel caso dinamico carica il codice in base al suo utilizzo

#### Indirizzamento logico e fisico
l'indirizzo logico (**o virtuale**) viene generato dalla CPU, mentre quello fisico è visto dalla memoria. I due indirizzi coincidono solo nel binding a compile o load-time

#### MMU
È l'hardware che si occupa di **mappare** indirizzi virtuali e fisici. Si occupa di aggiungere un "offset" all'indirizzo logico per portarlo a quello fisico

#### Considerazioni
Il binding a compile o load time presentano delle difficoltà nei sistemi moderni, perciò si usufruisce della **rilocazione dinamica e statica**


# Schemi di gestione della memoria

## Allocazione contigua
I processi vengono **allocati in posizione contigue**, dove la memoria è divisa in partizioni o fisse o variabili.

Nel caso delle partizioni fisse, la memoria ha partizioni fisse ma di dimensioni diverse. 

### Partizioni fisse

#### Assegnazione della memoria
Gestita dal long term scheduler, può offrire una coda per partizione o per l'intera memoria

La coda per partizione è meno flessibile dato che può lasciare partizione vuote mentre ci sono job nelle altre code.
La coda unica invece può lavorare in FCFS oppure con scansione della coda, ossia con meccanismi **best-fit-only** o **First-available-fit**

#### Supporto per la rilocazione
I **registri di locazione** compongono la MMU e limitano l'accesso alla memoria usata da altri processi, memorizzando **l'indirizzo logico** e il **limite superiore** dello spazio

#### Considerazioni
La semplicità del metodo porta a **frammentazione** interna e esterna, nel frattempo limitando il grado di multiprogrammazione

### Partizioni variabili
Per eliminare la frammentazione interna, le partizioni sono divise in dimensioni identiche a quelle dei processi

#### Assegnazione della memoria
Il SO vede la memoria come "**buche**" alla quale viene allocato un processo, e implementa 3 strategie
- first-fit: la prima buca di dimensioni sufficienti
- best-fit: la buca più simile alle dimensioni del processo
- worst-fit: la buca di dimensioni più grandi

Generalmente viene usato first-fit

Il supporto per la rilocazione è lo stesso delle partizioni fisse

#### Considerazioni
Le partizioni varibili scambiano la frammentazione interna per quella esterna.

## Riduzione della frammentazione
Una soluzione è la **compattazione** della memoria per renderla contigua, questo risulta però **costoso** e applicabile solo con rilocazione dinamica

#### Buddy system
Compromesso tra partizioni fisse e variabili. La memoria è suddivisa in **blocchi** di dimensione variabile. 

A memoria vuota, essa corrisponde a un singolo blocco. All'arrivo di una richiesta si cerca di **suddividere il blocco** in due. Questo meccanismo procede finché non si genera un blocco di dimensioni adeguate al processo

Quando un processo libera un blocco, questo può essere **ricompattato** in un blocco di dimensioni doppie, a ripetersi finché non incontra un blocco occupato

Questo metodo porta a una **compattazione veloce**, però causa **frammentazione interna**

## Paginazione
Per eliminare la frammentazione esterna, usa uno spazio non contiguo. Per la precisione divide la memoria in blocchi detti **frame**, mentre la memoria logica li divide in **pagine**

I processi vengono poi divisi in n pagine, e il link tra pagine e frame è preservato nella **page table**, creata per ogni processo

Questo metodo presenta **frammentazione interna**, ma solo nell'**ultima pagina**

#### Traduzione degli indirizzi
L'indirizzo di memoria è formato da **numero di pagina** (indirizzo logico) e un **offset** che addizionato ritorna l'indirizzo fisico

In particolare viene addizionato il numero di pagina moltiplicato per la dimensione delle pagine

#### Implementazione della page table tramite registri
Le righe della tabella sono salvate nei registri. Questa soluzione efficente è limitata dal numero di registri e allunga il context switch

#### Implementazione della page table in memoria
Vengono usati solo due registri, il Page-table base register (PTBR) e il page-table lenght register (PLTR). 
Con questo metodo però è richiesta un doppio accesso alla memoria (tabella + istruzione)

Per risolvere questo problema viene usata la cache **TLB** (Translation look-aside buffer), che confronta l'elemento fornito con tutte le entry contemporaneamente

TLB memorizza solo un piccolo sotto insieme della page-table ad ogni context switch.
TLB usa un meccanismo **hit or miss** per restituire l'indirizzo fisico

Tempo di accesso effettivo:
$$
(t_{mem}+t_{tlb})\times\alpha + (2\times t_{mem}+t_{tlb})\times(1-\alpha)
$$
#### Protezione
Ad ogni entry viene assegnato un **bit** di **validità** o/e **accesso**, ossia se l'entry è valida e perciò usabile, e un bit per marcare se la pagina è read-only o meno

#### Pagine condivise
Un indirizzo fisico può avere più indirizzi logici, ma read-only

#### Spazio di indirizzamento
Nelle archittetture 64bit, gli indirizzi logici sono molto **più grandi** dello spazio fisico. Questo permette di implementare pagine multilivello o tabelle delle pagine invertite

#### Paginazione multilivello
Si tratta di paginare le pagine. Invece di salvare l'intera tabella in memoria, alcune parti sono salvate sul disco

Questo aumenta gli accessi alla memoria, ma mantenendo prestazioni ragionevoli

#### Tabella delle pagine invertita
È una tabella unica invece che per processo, contenente page number, offset e **process id**.
Anche questo sistema aumenta il tempo necessario per trovare un riferimento.

Per migliorare le prestazioni, la ricerca non è sequenziale ma è una hashmap

## Segmentazione
È uno schema che supporta la vista della memoria da parte dell'utente.
Divide un programma in una collezione di segmenti

Usufruisce di una **tabella dei segmenti** bidimensionale, che mantiene la **base** e il **limite** del segmento. Per il resto implementa TLB , registri e bit di validità come nella paginazione

per condividere qualcosa lo si inserisce in un segmento.

La segmentazione può causare frammentazione esterna

#### Paginazione contro segmentazione
La paginazione non causa frammentazione e non richiede algoritmi per l'allocazione, però la segmentazione da consistenza tra la vista utente e quella della memoria fisica e fornisce associazioni di protezioni e condivisioni di segmenti

## Segmentazione paginata
Unisce il meglio delle due implementazioni. Consiste nel paginare i segmenti, nello specifico, ogni segmento possiede la tua tabella delle pagine

Next -> [[10-Memoria virtuale]]