# Concetto di processo

Un processo è un istanza di un programma. In un sistema multiprogrammato, i processi, devono avanzare in modo concorrente.

A livello di memoria il processo è composto in un immagine che condtiene codice, attributi, dati (variabili globali) e nello stack salva variabili locali e chiamate, mentre nell'heap la memoria allocata dinamicamente. Il processo è rappresentato dal Process Controll Block (PCB)
  

# Stato di un processo

Lo schema di evoluzione di un processo è formato dagli stati "pronto", "in attesa" e "in esecuzione"

  
## Scheduling

Per garantire multiprogrammazione e time-sharing, c'è bisogno di selezionare quale processo eseguire e in che ordine.

Questo è il compito dei schedulers che si occupano di selezionare quale processi trasferire in coda (Long-term) e quali far eseguire dalla CPU (Short-term). I long-term schedulers sono responsabili del grado di multiprogrammazione

Esistono due code di scheduling: la ready queue che determina i processi pronti all'esecuzione e la coda a un dispositivo.
Quando un processo viene eseguito nella ready queue viene definito dispatched. Da qui può proseguire in diversi modi:

 -  viene inserito nella coda di un dispositivo in attesa di I/O
 -  impiega troppo tempo di esecuzione e viene reinserito nella ready queue
 -  crea un processo figlio e ne attende l'esecuzione
 -  il processo attende un evento

L'operazione di dispatch determina un cambio di contesto (o caricamento di un nuovo processo), il passaggio alla user mode o un salto a un'istruzione da eseguire. Il cambio di processo implica la registrazione dello stato del processo (salvataggio del PCB) ed è un semplice peso al calcolatore
  

# Operazioni sui processi

Un processo può generare un processo figlio in modo sincrono, dove si attende la terminazione dei figli, e asincrono, o con concorrenza.
In UNIX abbiamo le funzioni fork (duplicazione), exec (programma diverso) e wait (esecuzione sincrona).

Un processo invece termina alla fine naturale della sua esecuzione, oppure forzatamente da parte del processo padre o del SO. Questo può essere causato per eccessi nell'uso delle risorse, errori o chiusura del programma/processo padre.

  
# Threads

Un thread è l'unità minima di utilizzo della CPU. Rispetto a un processo, viene associato lo stato di esecuzione, l'insieme dei registri, il program counter...
Nei SO moderni è possibile supportare il multithreading per un singolo processo, ne consegue la separazione tra flusso di esecuzione (thread) e spazio di indirizzamento.

I vantaggi del multithreading sono la riduzione del tempo di risposta, la condivisione delle risorse e la scalabilità (parallelismo). Inoltre, la creazione, terminazione e context switch tra processi risulta più lento rispetto che tra threads

NB: lo stato del thread può divergere da quello del processo

Un thread può essere livello utente (user-level), dove la gestione è affidata alle applicazioni, o a livello kernel (kernel-level), gestito dal kernel e invocato tramite system call.
I vantaggi dello user-level thread sono l'efficienza, data dall'assenza del mode switch tra user e kernel, portabilità e la possibilità di usare uno scheduling implementato nell'applicazione. Tutto questo al costo dell'impossibilità di accesso a multiprocessori e il blocco del processo in caso di blocco del thread.


## Libreria POSIX
Per utilizzare i threads in C viene usata la libreria **pthread.h** e compilata con l'opzione **-lpthread**. Possono essere espressi come attributi la priorità e le dimensioni dello stack.

Per la **creazione** viene usata la syscall pthread_create con come argomenti un tipo pthread_t, gli argomenti, e i puntatori  alla routine e ai suoi argomenti. La syscall di **terminazione** è la pthread_exit che prende in valore il puntatore al thread. Infine la **sincornizzazione** avviene con la syscall pthread_join


# Gestione dei processi del SO

Il SO, come ogni programma, è formato da processi che seguono 3 opzioni:

## Kernel eseguito separatamente
Il SO possiede uno spazio riservato e esegue in modo privilegiato, tipico dei primi OS


## Kernel eseguito all'interno di un processo utente
I servizi del SO vengono chiamati da programmi utente. Questo permette di evitare il context switch in caso di interrupt o trap e risultare più leggero


## Kernel eseguito come processo
I servizi del SO vengono eseguiti in modalità protetta ed esterni rispetto agli altri processi. Questo permette delle esecuzioni ad hoc su sistemi multiprocessore


Next -> [[5-IPC]]