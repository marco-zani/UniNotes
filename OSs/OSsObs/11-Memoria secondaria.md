# Tipologie di supporto
#### Nastri magnetici
Composti da una sottile striscia di plastica rivestita di un materiale magnetizzabile, arrivano fino a una **capienza massima di circa 5 TB**. Sono molto lenti in termini di accesso e il riposizionamento della testina può richiedere decine di secondi.
Oramai sono deprecati e usati solo per backup

#### Dischi magnetici
Formati da piatti d'alluminio e ricorperti di materiale ferromagnetico, posso raggiungere **fino ai 18 TB** e usano varii diametri per velocità di rotazione maggiori.
Per la lettura e scrittura usano una testina sospesa sulla superfice magnatica

Sono formati dalle componenti:
- platter
- cylinder
- track 
- sector
**Un settore è l'unità più piccola** d'informazione, e varia tra i 32 byte e i 4KB. Generalmente vengono **ragruppati in clusters per** motivi di **efficenza** dei file.
Sono identificati tramite superfice, traccia e settore

Il tempo di accesso corrisponde alla somma dei tempi impiegati per spostare la testina (**seek time**), spostare il settore (**latency time**) e la lettura vera e propria (**Transfer time**)

$$
seek\ time + \frac{rotations\ per\ second}{2} + \frac{block\ size}{transfer\ speed}
$$
Il tempo dominante è quello impigato dal seek time, perciò per aumentare l'efficenza bisogna implementare algoritmi di scheduling per **minimizzare gli spostamenti della testina**

#### Dispositivi a stato solido
Usa chip NVRAM o memorie flash NAND per memorizzare i dati. Le **letture** risultano **estremamente rapide**, mentre invece la **scrittura**, essendo un'**operazione complessa**, richiede più tempo. 
Rispetto ai dischi rigidi risultano più efficenti, silenziose e meno soggette a danni, ma sono più costose

# Scheduling degli accessi a disco
Logicamente, **un disco viene visto come un vettore unidimensionale**, dove ogni unità è rappresentata da un cluster

Un **processo che esegue un'operazione I/O esegue una syscall** passando l'indice del vettore, il tipo di accesso, indirizzo di destinazione e il quantitativo di memoria da trasferire.

gli algoritmi di scheduling cercano di approssimare una soluzione con il miglior corsto/efficacia

#### FCFS
Classico processing in ordine d'arrivo

#### SSTF
Shortest Seek Time First, si cerca la richiesta con il minimo spostamento della testina.
Può causare **starvation**

#### Scan
Chiamato anche algoritmo dell'ascensore, parte da un'estremità del disco e **scorrendo serve tutte le richieste** correnti. Terminato, riparte dalla direzione opposta con le nuove richieste

#### CScan
Variante circolare dello scan, **dopo aver raggiunto la fine del disco riparte da 0**. Fornisce un tempo d'attesa più uniforme

#### (C)LOOK
Altra variante dello scan, invece che arrivare alla fine del disco, **si ferma all'ultima richiesta** in una direzione prima di cambiare direzione. può essere implementata anche ciclicamente

#### N-step Scan
**Partiziona le richieste in più code** di dimensione N, così da permettere uno scorrimento più rapido. Le code vengono riempite in FCFS. FSCAN è la variante a 2 code

#### LIFO
Può risultare utile in caso di accessi con elevata località, ma può causare starvation

# Gestione del disco
#### Formattazione dei dischi
La formattazione fisica riguarda la divisione del disco in settori. Invece, per usare un disco, il SO deve partizionare il disco in gruppi di cilindri (partizionamento), usare una formattazione logica per il file system e impostare dei blocchi di boot dove estrarre il bootstrap all'avvio

Concettualmente: dividiamo il disco in **formattazione fisica** contenente i **settori**, l'**identificativo** e lo spazio di correzione degli errori (**ECC**), metre nella **formattazione logica** contiene il **file system**, le **liste di spazio libero** oppure occupato, e le directory vuote

#### Blocchi difettosi
**L'ECC contiene il valore calcolato sull'intero settore**. Durante ogni lettura, l'**ECC viene ricalcolato**, e **se differisce** allora segnala un **bad block**

Se un bad block viene gestito **off-line**, vuol dire che **i dischi individuati vengono messi in una lista e successivamente processati** con una utility (CHKDSK)

La gestione **on-line** invece, **rimappa il blocco su uno buono** non utilizzato (questo necessita di **predisporre blocchi di scorta, l'azione è chiamata sector sparring**). In questo modo quando il SO richiede il badblock, viene trasferito al blocco di scorta

#### Gestione dello spazio di swap
È un **estensione virtuale della ram** ricavata generalmente da una partizione separata con **gestore apposito** (aumenta l'efficenza). Questo spazio viene allocato o con la creazione di un processo o quando si forza una pagina fuori dalla memoria fisica


Next -> [[12-Filesystem]]