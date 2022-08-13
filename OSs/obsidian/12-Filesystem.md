# Interfaccia

#### Concetto di file
Un file è uno **spazio di indirizzamento** logico e contiguo **accompagnato da un insieme di informazioni** come nome, tipo di file, posizione, dimensione, protezione e dati sulla creazione

#### Operazioni sui file
**Creazione**, **scrittura** e **lettura** sono operazioni che attivano delle system calls per modificare o ottenere dati dal disco. Nel caso di scrittura e lettura, è necessario un puntatore per la prossima lettura/scrittura

Altre azioni sono il **riposizionamento**, l'**eliminazione** e il **troncamento**. **Quest'ultimo elimina i dati** nel file **ma mantiene** i suoi **attributi**

Inoltre, le operazioni di **apertura e chiusura**, gestiscono la **copia dei dati dal disco alla memoria e viceversa**. Nel caso dell'apertura nei sistemi multi-utente, vengono mantenute in due tabelle le informazioni sui file aperti dai processi e sui processi stessi

#### Struttura del file
Il tipo di file indica la struttura che seguono le infomazioni, che può variare da nessuna struttura o estremamente complessa

#### Metodi di accesso
**Accesso sequenziale**, offre operazioni come il read/write next e il reset. Non offre il rewrite

**Accesso diretto**, permette di modificare esattamente il dato n. Offre tutte le operazioni, anche quelle dell'accesso sequenziale

# Struttura delle Directories
Sono **collezioni di nodi contenenti informazioni sui file e sulla struttura** del file system.
Alcune di queste informazioni sono nome, tipo, indirizzo, dati sulla lunghezza, dati sulle modifiche...

Le operazioni comprendono **aggiungere**, **eliminare**, **rinominare** e **ricercare** un file, oltre che **visualizzare il contenuto** della directory e **attraversare il file system**

## Organizzazione logica
L'obbiettivo delle directory è avere accesso rapido a un file, classificarli e supportare una nomenclatura utile agli utenti

#### directory a un livello
Formata da una **singola directory per tutti gli utenti**, risulta problematica sia per la nomeclatura che per il raggruppamento (inesistente)

#### Directory a due livelli
**Separa le directory per ogni utente**. Permette di usare lo stesso nome dei file per utenti diversi ma risulta ancora assente il raggruppamento

#### Directory ad albero
offre il **raggruppamento** e offre una **ricerca efficente**

#### directory a grafo 
È in grado di offrire la condivisione, ossia, a livello implementativo, i **collegamenti** (Windows) e i **link** (Linux). I link di linux possono essere separati in **link simbolici**, ossia **contenenti il path della destinazione**, e gli **hard link**, **copie effettive del file**.

Per evitare dei loop, si **permette di collegare solo i file**, e non le directories

## Mount di file systems
È possibili attaccare e staccare interi file systems modulari in determinati punti delle directories chiamati mount points

## Protezione dei file
Nei sistemi multiutente, la condivisione viene raggiunta tramite uno **schema di protezione**, ossia degli schemi che **determinano chi può fare cosa**.

Il possessore del file deve essere in grado di effettuare tutte le operazioni e di decidere chi può fare cosa con il suo file

In **UNIX**, gli utenti sono raggruppati in **3 classi**: il **proprietario**, chi fa parte del **gruppo del proprietario**, e **gli altri**. In base a questa classificazione, si può determinare se una persona è in grado di **leggere**, **scrivere** o **eseguire** un file/directory

# Implementazione del file system
##### File system a livelli
In ordine:
- application programs
- logical file system
- file organization module
- basic file system
- I/O control
- devices
Ognuno di questi livelli si appoggia sulle funzioni di quello inferiore

## Implementazione
le strutture dati usate per gestire un file system sono divise in parte su disco e parte su memoria 

#### Strutture su disco
**Sul disco** che vengono salvati i **blocchi di boot**, i blocchi per il **controllo delle partizioni**, le **strutture delle directory** e i **descrittori di file**

#### Strutture su memoria
**In memoria** vengono caricate la **tabella delle partizioni**, che tiene conto delle partizioni montate, le **strutture delle directory recenti**, e le **tabelle dei file aperti**, quella globale e quella per processo

## Allocazione dello spazio su disco
L'obbiettivo è minimizzare i tempi di accesso e massimizzare utilizzo dello spazio

#### Allocazione contigua
Ogni file occupa una **serie di blocchi contigui**. La entry della directory è semplice perché deve solo tenere l'indirizzo d'inizio e la lunghezza.

Mentre offre un accesso semplice e **supporta sia l'accesso sequenziale che diretto**, presenta tutti gli svantaggi dell'allocazione dinamica della memoria, tra cui lo **spreco di spazio**

Infatti per allocare uno spazio si può **sovrastimare lo spazio necessario** (spreco) **oppure** quando non c'è più spazio, i **dati vengono ricopiati in uno spazio più grande** (pesante)

#### Extent
È una variante dell'allocazione contigua, ma invece di allocare singoli blocchi ne **alloca una serie** (chiama extent). I vari extent però non devono essere per forza contigui

Un esempio può essere FAT (File Allocation Table), dove tiene in lista tutti i blocchi del disco, permettendo l'accesso diretto

#### Allocazione a lista
Un file è una **lista di blocchi** che possono essere **sparsi nel disco**. La **directory tiene i puntatori al primo e ultimo blocco**, mentre **ogni blocco ha il puntatore a quello successivo**
L'indirizzamento è composto dall'indirizzo logico (*X*) e la dimensione dei blocchi (*N*): 
- numero del blocco nella lista = *X*/(*N*-1)

Questo metodo non comporta nessuno spreco e la creazione ed estensione di un file risultano molto semplici, In contrasto pero risulta meno efficente, affidabile e **non offre l'accesso diretto**


#### Allocazione indicizzata
Ogni file ha un **blocco indice contenente gli indirizzi degli altri blocchi**, mentre la **directory tiene l'indirizzo dell'index block**.

L'allocazione indicizzata offre un accesso diretto efficiente e senza frammentazione esterna. La dimensione del blocco però **limita la dimensione dei file**, per questo sono stati implementati schemi a più livelli (indici multilivello, schemi concatenati e combinati)

##### Indici multilivello
Un **index table che referenza altre index table**.

##### Schema concatenato
Consiste in una lista concatenata di blocchi indice, o meglio: l'**ultimo indice di un blocco punta a un'altro blocco indice**

##### Schema combinato
Usiamo l'**esempio Unix**: A ogni file è associato un index-node che fa da blocco indice ma contiene anche attributi del file. Questi **i-node sono gestiti dal SO e memorizzati sul disco in una porzione riservata**, generalmente l'inizio del disco. Ogni i-node possiede 10 puntatori diretti, 1 puntatore a un index block, 1 puntatore a index block di 2° livello e un index block di 3° livello

### Implementazione delle directories
Le directory possono essere scritte come liste lineari con i nomi dei file e i puntatori ai blocchi. Una implementazione semplice ma poco efficiente.
In alternativa si può **utilizzare una tabella hash**, più efficiente ma con il rischio di collisioni

	questa parte la deduco dagli schemi, non c'è scritto se no unn cazzo madonna puttana slide di merda del professore
	
	Per gestire le collisioni, invece si può invece che salvare il puntatore al file, si salva il puntatore a dei blocchi concatenati contenenti i file che possiedono lo stesso hash, in modo da effetturare la ricerca su una pool di pochi files

# Gestione dello spazio libero
In modo da accedere facilemente a **blocchi liberi**, il **SO tiene una mappa** che può essere implementata tramite vettore di bit, lista concatenata, raggruppamento e conteggio

#### Vettore di bit
Si mantiene un vettore di dimensioni pari alla somma dei blocchi, e si imposta a 1 i blocchi occupati. Questa mappa richiede extra spazio e risulta efficente solo se è mantenibile in memoria

#### Lista concatenata di blocchi liberi
In alternativa al vettore di bit, può venir salvata una **lista concatenata di tutti i blocchi liberi**, garantendo il minimo spreco di spazio

#### Raggruppamento
**Nei blocchi liberi vengono salvati gli indirizzi di altri blocchi liberi**, mentre nella ultima entry del blocco, si ha un puntatore al gruppo successivo di blocchi liberi. Questo metodo fornisce rapidamente grandi quantità di blocchi liberi

#### Conteggio
Viene mantenuto il conteggio di quanti blocchi liberi seguono il primo e il puntatore al successivo gruppo libero

# Efficienza e prestazioni
**Il disco rappresenta il collo di bottiglia**, e gli algoritmi di allocazione risultano essenziali per migliorare l'efficienza. 

Alcune soluzioni hardware sono i dischi virtuali (RAM disk) e le cache del disco (buffer cache)

#### RAM disk
Il driver della RAM permette di eseguire le **operazioni dei dischi in memoria** in modo estremamente veloce, ma **solo per i file temporanei**

#### Buffer cache
**Memorizza i blocchi usati di frequente** secondo indicazione del SO e sfrutta il principul della località spaziale (dati vicini) e temporale (usati spesso assieme)

A causa delle dimensioni della cache bisogna implementare politiche di rimpiazzamento e di scrittura

#### Recupero
Può succedere che i contenuti in cache divergano da quelli su disco, quindi bisogna implementare un **controllo di consistenza**. Inoltre è importante effettuare backups

Log Structured File system 
**È SPIEGATO TUTTO DI MERDA** 

next -> [[13-RAID]]