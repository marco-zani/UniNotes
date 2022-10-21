	Quando un programma viene caricato in memoria, generalmente viene caricato per intero. Questo non è necessario e di conseguenza lo spazio degli indirizzi logici può essere molto più ampio di quelli fisici

Il concetto della **memoria virtuale è swappare pagine da e verso la memoria**. Questo può avvenire con la paginazione su domanda o la segmentazione su domanda

# Paginazione su domanda
**Carica la pagina solo quando necessario**, richiedendo quindi meno memoria e meno richieste I/O

Per conoscere lo stato di una pagina viene usato un **bit di validità (in memoria/non in memoria)** per ogni entry della page table. Quando durante traduzione logico a fisico, una entry ha il valid bit a 0, allora triggera un **page fault**

Un page fault si comporta così:
1. il SO controlla la validità del riferimento
	- se risulta invalido abortisce la procedura
2. cerca un frame vuoto e avviene lo swap della pagine nel frame
3. Nella tabella viene modificato il validity bit e viene ripristinata l'istruzione che ha triggerato  il page fault

La paginazione su domanda influenza l' Effective Access Time (EAT):
$$
(1-p)*t_{mem}+p*t_{page\ fault}
$$
dove *p* è la probabilità di generare un page fault

#### Assenza di frame liberi
In caso di assenza di pagine libere **vengono swappate su disco alcune pagine in memoria**. In genere:
1. check della validità della tabella
2. ricerca di un frame vuoto. In caso di fallimento viene usato un algoritmo per individuare un frame "vittima" (da rimpiazzare)
3. swap della vittima in memoria e della pagina sul disco
4. modifica delle tabelle e ripristino dell'istruzione che ha triggerato il page fault

Dato che gli swap sono due il tempo di page fault raddoppia. Come ottimizzazione viene usato un **bit di modifica, o dirty bit**. Questo bit viene impostato a 1 quando le pagine vengono usate (o modificate) e quindi **eligibile come "vittima"** 

# Algoritmi di rimpiazzamento delle pagine
L'obbiettivo di ottenere il minimo tasso di page fault viene ottenuto con l'utilizzo di una **stringa di riferimenti a memoria, o reference string**, sulla quale viene calcolato il numero di page faults. Il numero di page faults è inversamente proporzionale al numero di frames

L'algoritmo ideale rimpiazza le pagine con intervalli d'utilizzo più ampi, ma richiede la conoscenza anticipata della reference string. L'implementazione migliore è tramite approsimazioni

#### FIFO
la prima pagina introdotta è la prima ad essere rimossa, senza tener conto della frequenza di riferimento. Aumenta il tasso di page faults

NB: **anomalia di Belady**, in FIFO, a volte più frames causano più page faults

#### LRU
Least Recently Used **rimpiazza la pagina non usata da più tempo**. Più efficente di FIFO richiede però di ricavare il tempo di utilizzo, che può comportare la necessità di HW addizionale

L'implementazione può avvenire con 
- **contatore**: salva il tempo di clock ogni volta che la pagina viene referenziata. Necessità la ricerca del valore più basso
- **stack**: Viene mantenuto uno stack dove si sposta in cima l'ultima pagina referenziata. L'ultimo elemento corrisponde alla pagina LRU
- **bit reference**: scelgo una pagina con bit a 0. Risulta estremamente approssimato. In alternativa vengono usati più reference bits che vengono aggiornati continuamente
- **conteggio dei riferimenti**: mantiene il numero di riferimenti fatti a ogni pagina e rimpiazza quella con il conteggio più basso 
- **Rimpiazzamento**: cicla le pagine, e rimpiazza le pagine con reference bit a 0, e imposta a 0 quelle con bit uguale a 1


# Allocazione dei frame
Avendo frame limitati è importante **determinare quanti darne per processo**. Generalmente si può esprimere il vincolo che il numero minimo di pagine è uguale al numero massimo di indirizzi in una istruzione

Il **numero di frame** allocati può essere **fisso** o **variabile** in base allo schema di allocazione scelto

In caso di page fault le vittime possono subire un **rimpiazzamento locale o globale**, ossia il processo può scegliere le vittime solo fra i suoi frame, oppure subentra il SO e sceglie dei frame fra tutti i processi. Il secondo caso migliora il throughput

#### Allocazione fissa
Può avvenire in diversi modi: **per parti uguali**, ossia dati m frame e n processi si forniscono m/n processi, oppure **proporzionale**, cioé si allocano i frame a seconda della dimensione del processo (o dell'importanza)

#### Allocazione variabile
Il numero di frames allocati in un certo istante può essere determinato tramite working set e Page Fault Frequency (PFF)

working set viene calcolato in base alla sua località (di indirizzi). Per semplificare la comprensione possiamo considerare la località come uno scope
La località può essere misarata tramite il numero di pagine referenziate in un intervallo di tempo delta. Se delta risulta troppo piccolo porta poca informazione, se troppo grande potrebbe coprire più località del necessario.
In pratica si usa timer e reference bits per approssimare il risultato. **Periodicamente la CPU viene interrotta** e vengono **individuate le pagine con reference bit a 1**. Quelle faranno parte del working set, mentre **le altre verrano scartate**

##### Trashing
Se il **numero necessario di frame supera quelli disponibili**, avviene il trashing, ossia un circolo vizioso dove la CPU **continua a swappare pagine**. 
Questo  può essere anche causato da **troppi pochi frame allocati**

#### Frequenza di page faults
La soluzione più accurata, **assegna** più (o meno) **frames in base** se **il tasso di page faults** risulti troppo alto (o troppo basso)


# Considerazioni
Sono tante le variabili che definiscono le dimensioni di una pagina:
- frammentazione
- dimensione page table
- I/O overhead
- località

La struttura di un programma influisce sul tasso di page faults

Ci sono frames (principalmente usati dal kernel o dall'I/O) che non devono essere rimpiazzati. Questo è definito **frame locking**




Next -> [[11-Memoria secondaria]]