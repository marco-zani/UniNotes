Il sotto sistema di I/O sono i metodi per controllare i dispositivi I/O

# Hardware di I/O
I dipositivi per memorizzazione, trasmissione e interazione uomo-macchina sono numerosi ed eterogenei, e vanno distinti tra dispositivi e controllori. Per gestirli ci si appoggia a concetti comuni come porta, bus e controllore

#### Controllore
Consiste nella **parte elettronica del dispositivo**, possiede un suo indirizzo ed è connesso al resto del sistema tramite bus. Il controllore **contiene i registri per comandare il dispositivo**, ossia quello di **stato** e quello di **controllo**, oltre che ai buffer di conversione dei dati

L'**accesso ai registri** può avvenire tramite la **mappatura in memoria** (memory mapped), ossia che i registri vengono visti nello spazio di indirizzamento della memoria e acceduti tramite instruzioni di accesso alla memoria, **oppure** tramite mappatura su I/O (I/O mapped), ossia si accede ai registri tramite **istruzioni specifiche**. Sono anche disponibili soluzioni ibride

#### Accesso
##### Polling
**Ciclicamente controlla il busy bit** nel registro di controllo, e quando diventa 0 allora esegue il comando. Dato che l'attesa è attiva, c'è uno spreco di CPU

##### Interrupt
Il **dispositivo I/O invia un segnale quando risulta disponibile**. La gestione dell'interrupt è data a un controllore che offre funzioni di mascheramento dell'interrupt, numerazione per identificazione dell?I/O e ordinamento per priorità dell'interrupt

##### DMA
Il Direct Memory Access, è una **soluzione HW** che permette l'**accesso diretto tra I/O e memoria**. L'unico ruolo della CPU è quello di dire al DMA sorgente e destinazione del trasferimento e il quantitativo di dati da trasferire, poi il DMA lavora in autonomia

# Interfaccia di I/O
Per poter gestire i dispositivi non omogenei, si usufruisce di **abstraction**, **encapsulation** e **software layering** per nascondere le differenze, il tutto per offrire un interfaccia comune con funzioni standard

# Software di I/O
Gli obiettivi di un buon driver sono indipendenza dal dispositivo, buone prestazioni e uso di una notazione uniforme mentre devono essere in grado di gestire gli errori e i trasferimenti sincroni e asincroni

## Organizzazione per livelli di astrazione
#### Gestori di interrupt
Astratti il più possibile, si occupano del **bloccaggio e sbloccaggio dei processi**

#### Device driver
**Traducono le richieste astratte in richieste device dependent**, ossia interagendo con i controllori dei dispositivi. Sono scritti in linguaggio macchina e spesso condivisi tra classi di dispositivi

#### SW del SO indipendente dal dispositivo
I compiti principali sono la definizione di interfacce uniformi, gestione dei nomi, protezione, buffering durante il trasferimento, gestione degli errori e rilascio dei dispositivi

##### Spooling
Per la **gestione di I/O non condivisibile**. Se più processi vogliono accedere al dispositivo contemporaneamente, vengono messi in attesa in una spooling directory (una **queue**). Sarà poi compito dello spooler (un processo di sistema) di autorizzare un processo alla volta

##### Programmi utente
tipicamente system calls per l'accesso ai dispositivi


Next -> [[15-Protezione e sicurezza]]