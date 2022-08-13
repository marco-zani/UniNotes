I sistemi più moderni montano molteplici dischi per fornire letture/scritture in parallelo e ridondanza dei dati

RAID (Redundant Array of Inexpensive Disks) ha proprio l'obiettivo di migliorare l'**affidabilità** e le **prestazioni**

Può essere implementato via software, con **funzionalità RAID implementate dal SO**, **oppure via HW**, con un **controllore di dischi intelligente**, o infine con **una batteria RAID**, un'unità a se stante composta da dischi, controllore e cache collegata a una macchina

I concetti chiave del RAID si basano sulla copia speculare (Mirroring) e sezionamento (data striping) dei dati

#### Mirroring
Modo più semplice per implementare la **ridondanza**. Ogni **scrittura avviene su due dischi** in modo che se se ne guasta uno non si perdono i dati.

Inoltre il **parallelismo delle letture** permette di raddoppiare le prestazioni

Offre alta affidabilità ma è costoso

#### Striping
Consiste nella **distribuzione dei dati su più dischi**. **Migliora** anche la capacità di **trasferimento**.

Il **sezionamento** può avvenire **a livello di bit o di blocco**, in modo che il i-esimo segmento si trovi su i-esimo disco

Tramite il bilanciamento del carico, aumento delle prestazioni tramite **accessi multipli e la riduzione del tempo di risposta** 

offre migliori prestazioni ma non migliora l'affidabilità

#### Codici per la correzione degli errori
Si possono usare **uno o più bit di parità per identificare e correggere degli errori**, maggiore è il numero di bit maggiore è la correzione

#### Codice Hamming
___
___
___
___
___

## Livelli di RAID
L'uso combinato di mirroring e data striping, più bit di parità per la correzione degli errori, compongono i 6 livelli RAID

#### RAID 0
Implementa data **striping senza mirroring**. Offre alte prestazioni a basso costo, ma risulta meno affidabile all'aumentare del numero di dischi

#### RAID 1
**Solo mirroring**. Offre affidabilità e prestazioni in lettura in base al numero di dischi, ma ad alto costo e bassa scalabilità

#### RAID 2
Data **striping a livello di bit**, e utilizza codici per la correzione degli errori **(ECC) salvati in dischi separati** rispetto a quelli contenenti dati. In questo modo, in caso di guasto dei dischi, si possono recuperare i dati

Risulta simile a un RAID 0 con maggior affidabilità, ma pur sempre costoso

#### RAID 3
Data **striping a livello di bit con un disco dedicato al bit di parità**. I controllori sono in grado di rilevare la corretta lettura del settore e nel caso di guasto di un settore, si possono usare gli altri dischi e il bit di parità per calcolare il bit mancante

 È in grado di provvedere alla stessa efficenza del RAID 2 ma con solo un disco e velocità di trasferimento superiori. Si riducono le operazioni I/O al secondo e le scritture richiedono più tempo

#### RAID 4
**Data striping a livello di blocco con disco dedicato alla parità**

Offre una maggiore tolleranza ai guasti e letture più veloci. I costi sono scritture lente e la possibilità da parte del disco di parità di fare da collo di bottiglia

#### RAID 5
Data **striping a livello di blocco con bit di parità distribuiti tra tutti i dischi** raid. La logica è che un **blocco di parità non può avere informazioni per i blocchi risiedenti nello stesso disco**. È un implementazione molto popolare

Offre gli stessi vantaggi del RAID 4 ma senza il collo di bottiglia, il tutto a costo delle scritture lente

#### RAID 6 
SImile a **RAID 5 ma con più** informazioni di **ridondanza** per gestire più guasti contemporanei. Al posto della parità si usano i **codici Reed-Solomon**

Offre altissima ridondanza a costo molto elevato e scritture molto lente

#### RAID 0+1
Combinazione di RAID 0 e 1 per fornire affidabilità e alte prestazioni

Risulta più efficente di RAID 5 e con alta affidabilità, ma richiede più dischi e non supporta la rottura simultanea di 2 dischi

#### RAID 1+0
Versione più robusta di RAID 0+1, ma sempre a un costo più elevato

# Riassunto
- RAID 0: aumento delle prestazioni in lettura e scrittura  
-  RAID 1: tollera il guasto di un disco, con ricostruzione automatica  
-  RAID 2: prevede codici a correzione d’errore  
-  RAID 3: oltre ad avere codici a correzione d’errore, comporta minor sovraccarico  
-  RAID 4: consente l’esecuzione di letture contemporanee  
-  RAID 5: letture e scritture contemporanee, parità distribuita tra i dischi  
-  RAID 6: doppia parità, tollera il guasto di 2 dischi  
-  RAID 0+1: sfrutta velocità del livello 0, implementando la sicurezza come nel livello 1  
-  RAID 1+0: Tollera il guasto di piu’ dischi se non sono sotto lo stesso stripe



Next -> [[14-Sottosistema InOutput]]