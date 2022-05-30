Nella creazione di un SO è inportante distinguire policies e meccanismi, ossia cosa e come deve essere fatto qualcosa. Altri principi importanti sono il KISS (Keep It Small & Simple) e il POLA (Principle Of the Least Privileges), ossia l'assegnazione dei privilegi minimi

  
# Strutture di un SO

## Sistemi monolitici

Non presentano nessun tipo di gerarchia, il software comunica direttamente con l'HW. Questo però comportava una forte dipendenza dalla tipologia di HW
  

## Sistemi a struttura semplice

Sviluppati per ridurre i costi di sviluppo, implementano gerarchie molto flessibili. Come esempio abbiamo MS-DOS e UNIX originale

MS-DOS offre nel minimo spazio, più funzionalità possibili. Usa una struttura minima, ma con interfaccie e livelli poco ben definiti. UNIX invece aveva una base limitata a causa delle funzionalità HW


## Sistema a livelli

Sono organizzati gerarchicamente, con la user interface al livello più alto e l'HW al livello più basso, e implementano un modello a layers. Questo permette una maggiore modularità, ma con minor efficenza e portabilità.

Un esempio è THE, SO accademico sviluppato da Dijkstra


## Sistemi basati su kernel

Evoluzione del sistema a livelli, divide le funzionalità in servizi kernel e non-kernel. Questo allieva gli svantaggi e i vantaggi del sistema a livelli


## Micro-kernel

Evoluzione del kernel, ma che contiene le funzioni strette necessarie, come Inter Process Communication (IPC), gestione memoria e scheduling CPU


## Virtual Machine

È un approccio a livelli dove HW e VM vengono trattati come HW, in modo da offrire timesharing multiplo. Il concetto chiave è la separazione tra multiprogrammazione (VM) e presentazione (SO). Questo metodo permette la protezione completa del sistema, ottimizzazione delle risorse, portabilità e la possibilità di installare più SO sulla stessa
macchina. D'altro canto però risulta più pesante a livello di prestazioni e richiede la gestione della dual mode virtuale, ossia la VM e VMM funzionano una in modalità kernel e l'altra in modalità user

Esistono due tipi di hypervisor, il type-1 che si posiziona tra hardware e VM in modalità kernel, e il type-2, che si appoggia al SO dell'host e permette in contemporanea l'esecuzione di altre applicazioni. Il type-1 permette anche di implementare hypervisors micro kernel o monolitici.


## Sistemi client-server

Molto efficente nei SO distribuiti, si basa sulla gestione delle comunicazioni da parte del kernel e il resto delle funzioni nei processi utente

Next -> [[4-Processi e Threads]]