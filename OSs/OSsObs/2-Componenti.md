## Gestione dei Processi

Il SO è responsabile dei processi (programmi in esecuzione) in quanto creazione, distruzione, spospensione, riesumazione e sincronizzazione per la communicazione tra processi


## Gestione della memoria primaria

La memoria primaria contiene i dati condivisi dalla CPU e dispositivi I/O. Il sistema operativo gestisce lo spazio, allocazione e rilascio della memoria, e scelta del processo da caricare in memoria
  

## Gestione della memoria secondaria

Il SO gestisce oltre che gestione e allocazione, anche lo scheduling degli accessi al disco
  

## Gestione dell'I/O

Il SO gestisce un sistema per l'accumulo degli accessi ai dispositivi e gestisce driver specifici o generici per i dispositivi

  
## Gestione dei file

Il SO gestisce creazione e cancellazione di file e dyrectories, operazioni primitive, gestione dei backup e corrispondenza tra file e spazio fisico


## Protezione

gestione degli accessi autorizzati e non, degli strumenti per la verifica delle policies e definizione dei controlli da imporre
  

## Sistemi distribuiti

Corrispondono a una serie di calcolcatori con clock e memorie diverse, generalemente usano una connessione gestita dal SO sulla rete

  
# Interfacce

## Interprete dei comandi

Chiamato anche **Shell**, offre all'utente i comandi con la quale interagire con il SO. Questi programmi rientrano nella gestione dei file, status del sistema, strumenti per la programmazione...

Esisteno vari modi per interfacciarsi con i programmi del SO: GUI, CLI e Batch. Queste sono definite interfaccie utente

  
## System calls e API

Le funzioni di un SO vengono definite **system calls** sono utilizzate dai processi tramite le API. Quest'ultime permettono di interporsi e mascherare l'implementazione dei servizi del SO.
Per ogni system call viene associato un numero, che viene usato dall'interfaccia per comunicare col SO. A volte queste call contengono dei parametri.
Quest'ultimi vengono passati al SO in 3 modi:

 -  Tramite **registri**
 -  Tramite **stack** del programma
 -  Tramite tabella in memoria, passando poi l'indirizzo della tabella tramite registro o stack

In dettaglio, la comunicazione tramite stack:

 1.  vengono salvati i parametri sullo stack e chiamata la funzione dalla libreria
 2.  viene caricato il numero della system call in registro ed eseguita la Trap
 3.  selezionata la system call indicata nel registro, viene gestita appropriatamente
 4.  infine ritorno della funzione di libreria e al codice utente

Le **API** più comuni sono Win32 per windows e **POSIX** (Portable Operating System Interface for Unix) API per sistemi unix, linux e Mac OS X


Next -> [[3-Archittettura]]