# Tipi di scheduling
Esistono due tipi di scheduler, lo **job scheduler**, che gestisce i processi che vanno alla **ready queue**, e il **CPU scheduler**, che seleziona il processo da eseguire. Ovviamente il secondo è estremamente rapido e chiamato in continuazione.

I SO con **memoria virtuale** implementano uno scheduling a **medio termine** che si occupa della **rimozione forzata di un processo** dalla CPU


# Scheduling della CPU
Nello CPU scheduler, è compreso il modulo **dispatcher** che **si occupa di rendere disponibile la CPU** al processo scelto dallo scheduler. La sua latenza determina il tempo necessario per fermare un processo e farne partire un'altro

NB: un **CPU burst** o **I/O burst** sono delle sequenze, un sistema può essere astratto in un ciclo alternato di burst CPU e I/O. I burst CPU sono generalmente brevi e numerosi


## Prelazione
O **preemption è il rilascio forzato della CPU**. Uno scheduling preemptive e non determina se un processo può essere forzato a rilasciare la CPU prima del termine del burst

NB: gli stati di un processo sono:
- pronto
- in esecuzione
- in attesa
- swapped


## Metriche di scheduling
Per valutare l'utilizzo della CPU vengono usate varie metriche come il throughtput,
il tempo di attesa, il **tempo di completamento**(o turn around) e il tempo di risposta (ossia il tempo tra una richiesta al sistema e una prima risposta). 

Per l'ottimizzazione si cerca di **massimizzare** l'**utilizzo** e il **throughput** della CPU, **minimizzando** i tempi di **turnaround**, **attesa** e **risposta**


# Algoritmi di scheduling
## First Come, First Served (FCFS)
Un implementazione semplice a base FIFO, ma che comporta l'accodamento di processi brevi a processi lunghi


## Shortest Job First (SJF)
seleziona i processi per il prossimo burst in ordine di lunghezza, dal più breve al più lungo.  Questo permette di avere il minimo tempo di attesa.
La **versione preemptive** permette ai nuovi **processi di lunghezza breve**, di **superare** quelli più lunghi in esecuzione. Questo algoritmo è chiamato **Shortes Remaining Time First** (SRTF)

È possibile stimare il prossimo burst della CPU utilizzando la media esponenziale dei burst precedenti


## Scheduling a priorità
La CPU viene allocata al processo più importante. La priorità di un processo è determinata dalle **policy interne** (tempo, memoria, file aperti...) o **esterne** al sistema operativo (importanza, ricavo economico...)

Questo metodo può dare origine a **starvation**, ossia l'evento in cui un processo a bassa priorità non viene mai eseguito


## HRRN
Higher Response Ratio Next è un algoritmo non preemptive che **tiene conto** anche **dell'attesa del processo**
$$
1 + \frac{t\_attesa}{t\_burst}
$$

## Round robin (RR)
Ai processi viene assegnato un **lasso di tempo**, in base al numero di processi, al cui termine vengono **rimossi dalla CPU e reinseriti nella ready queue**. Nello specifico, in un lasso di tempo q e n processi, ogni processo riceve **(n-1)\*q** tempo

q deve risultare maggiore del tempo impiegato per il context switch per evitare di impattare sulle presazioni


# Code multilivello
È un meccanismo che implementa una ready queue partizionata in **più sezioni, ognuna con il suo algoritmo di scheduling**

Risulta però necessario impostare uno **scheduling delle code** per determinare quale può accedere alla CPU. I meccanismi sono:
- scheduling a **priorità fissa**, ossia ogni tipo di coda ha il suo ordine
- scheduling con **time slice**, ossia ogni coda riceve un intervallo di tempo in base alla sua priorità


## Code multilivello con feedback
Chiamate anche **code adattive**, permettono a **un processo di spostarsi tra una coda e l'altra** in base a determinati criteri

un esempio è con 3 code con quanti diversi in ordine crescente, nel caso la coda con quanto più breve riceve un job troppo lungo, lo degrada alla coda successiva, mentre invece se risulta vuota, va a prenderne uno


## Scheduling fair share
Per permettere alle applicazioni e agli utenti di condividere risorse in maniera equa fra loro, viene implementato il **fair share scheduler**, che **gestisce i gruppi di processi** invece del singolo


# Valutazione degli algoritmi
## Modello deterministico
Usato per illustrare gli algoritmi, definisce le prestazioni dell'algoritmo per **carichi specifici**

## Modello a reti di code
Viene ipotizzata una distribuzione di CPU burst e I/O burst, e tramite formule per il **calcolo di probabilità** e distribuzione dei burst si determinano utilizzo, tempi di attesa, throughput medio

## Simulazione
**utilizza dati statistici o reali** per ottenere la massima precisione, il tutto a un costo maggiore

## Implementazione
Codifica e **test effettivo** sul sistema


Next -> [[7-Sincronizzazione tra processi]]