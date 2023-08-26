la corretNon tutti gli algoritmi si risolvono in modo polinomiale
# Definizioni
#### Problema astratto
Un problema $R$ è una relazione tra $I$ istanze del problema e $S$ soluzioni: $R\subseteq I\times S$. Con istanza intendiamo combinazione di dati in input che descrivono le condizioni del problema
#### Tipi di problemi:
- Ottimizzazione: la miglior soluzione
- Ricerca: una possibile soluzione
- Decisione: se l'istanza rispetta determinate proprietà
		- più facile da trattare matematicamente, preclude la risoluzione efficiente degli altri tipi di problemi
#### Riduzione polinomiale
Due problemi $A$ e $B$ sono **polinomialmente riducibili** se esiste una funzione $f$ in grado di convertire un istanza $I_A$ in $I_B$ in un tempo polinomiale
# Insieme indipendente
> L'insieme dei nodi $S$ di un grafico $G$ è indipendente se non esiste alcun arco che li collega fra di loro

> [!info]- Packing problem
> Questo problema rientra nella categoria di problemi in cui si cerca di selezionare il maggior numero di oggetti soggetti a vincoli di esclusione

Nel caso decisionale, verifichiamo se esiste un insieme indipendente di dimensione $k$ 
## Copertura di vertici
> L'insieme di nodi $S$ è copertura di vertici se ogni nodo di $G$ ha un arco verso $S$

Nel caso decisionale, determiniamo se esiste una copertura di dimensione al massimo $k$ 


> [!info]- Covering problem
> Si cerca il più piccolo sottoinsieme di oggetti in grado di coprire l'intero insieme
#### Problemi duali
L'insieme indipendente e la copertura dei vertici sono due facce della stessa medaglia (un vertice non può appartenere ad entrambi). Di conseguenza i due problemi sono equivalenti secondo la riduzione polinomiale
## SAT
> Problema di soddisfacibilità (SATisfability) delle formule booleane in forma normale congiuntiva, ossia che esista una combinazione di variabili che rendono la formula vera

In questo caso consideriamo la 3-SAT, ossia con 3 variabili. 
1. È possibile convertire la formula in un grafo collegando i terzetti e le variabili in conflitto.
2. Da qui verifichiamo la soddisfacibilità se è presente un insieme indipendente

Di conseguenza l'insieme indipendente, la copertura dei vertici e 3-sat (con le opportune modifiche) sono polinomialmente riducibili da SAT ^a5024a
# Classi $\mathbb{P},\mathbb{PSPACE}$ 
#### Classi di complessità
- Definiamo $\mathbb{TIME}(f(n))$ l'insieme di problemi decisionali risolvibili in un tempo $O(f(n))$
- Definiamo $\mathbb{SPACE}(f(n))$ l'insieme di problemi decisionali risolvibili in uno spazio $O(f(n))$
Nel dettaglio:
- la classe $\mathbb{P}$ sono tutti i problemi risolvibili in tempo polinomiale in referenza alla dimensione dell'input
- la classe $\mathbb{PSPACE}$ sono i problemi risolvibili in uno spazio polinomiale 
## Relazioni fra problemi
Se un problema $A$ è riduzione polinomiale di un problema $B$, e $B$ appartiene a $\mathbb{P}$, allora anche $A\in\mathbb{P}$
## Classe $\mathbb{NP}$
Un **Certificato** di un problema decisionale $R$ è l'insieme di informazioni che provano che l'istanza $i$ è vera nel problema $R$
L'insieme di tutti i problemi che ammettono un certificato verificabile in tempo polinomiale sono definiti classe $\mathbb{NP}$ 

> [!tips]+ In breve
> Se è possibile verificare se un'istanza è vera in tempo polinomiale

## Classe $\mathbb{NP}$-hard
Se ogni problema di $\mathbb{NP}$ è riducibile polinomialmente rispetto a un problema $R$, allora $R$ è $\mathbb{NP}$-hard

## Classe $\mathbb{NP}$-completo
Se un problema $R$ appartiene sia ad $\mathbb{NP}$ che ad $\mathbb{NP}$-hard

È stato dimostrato che SAT è un problema $\mathbb{NP}$-completo, perciò viene utilizzato per determinare che altri problemi sono $\mathbb{NP}$-completi. Perciò, come dichiarato [[#^a5024a|qui]], 3-SAT, insieme indipendente e copertura dei vertici sono problemi $\mathbb{NP}$-completi

# Problemi $\mathbb{NP}$-completi classici
- Cricca
- Traveling salesperson (TSP)
- programmazione lineare 0/1
- copertura esatta di problemi
- partizione
- somma di sottoinsieme
- zaino
- circuito hamiltoniano