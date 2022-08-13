Un deadlock viene causato quando un gruppo di processi è in attesa di un evento che può essere causato solo dallo stesso insieme

Per generarsi, un deadlock necessità delle seguenti condizioni:
- Mutua esclusione
- Hold&Wait
- No preemption
- Attesa circolare

  
# RAG - modello astratto
Il **Resource Allocation Graph** è un grafo dove i nodi rappresentano **processi** (cerchi) e **risorse** (rettangoli) e gli archi rappresentano se il processo **richiede o detiene** la risorsa

In questi grafi, **se troviamo cicli** 'che comprendono tutti gli elementi (o processi) del grafo' (da confermare), vuol dire che **si può generare un deadlock**


# Gestione dei deadlock
La **prevenzione statica** consiste nell'evitare lo svilupparsi delle 4 condizioni, un alternativa può essere il **Detection&Recovery**, che non previene il deadlock ma prevede metody per il ripristino del sistema al corretto funzionamento, per un maggior utilizzo delle risorse a costo dell'eventuale recovery.

Altre **alternative non usate** sono la **prevenzione dinamica**, che risulta troppo specifica e costosa, e il non gestire i deadlock


## Prevenzione statica
Nella prevenzione statica si possono approcciare vari metodi: nel caso del Hold&Wait, si può limitare il processo a detenere una singola risorsa alla volta, con il rischio starvation.

Un altro approccio, verso la no preemption, risulta applicabile solo per le risorse in cui lo stato è facilmente reintegrabile


## Prevenzione dinamica
Consiste nell'**analisi dinamica del grafo delle risorse**, in modo da aumentare al massimo l'utilizzo delle risorse senza il rischio di deadlock

Un sistema si definisce **safe** se allocando le risorse ai processi, essi **possano arrivare al termine**, se questa sequenza di processi non esiste, allora il sistema è **unsafe**

L'idea è di implementare algoritmi che lasciano sempre il sistema in uno stato safe.


#### Algoritmo con RAG
Funzionante **solo con un'istanza per risorsa**. Estende il RAG con archi di **rivendicazione**, o archi su risorse che potrebberò essere richieste in futuro

L'algoritmo si aspetta che il processo indichi quale risorse vuole usare, e, in base al grafo, cerca di rilevare dei cicli


#### Algoritmo del banchiere
Meno efficente ma funziona con più istanze rispetto al RAG.

Al seguito della dichiarazione delle risorse necessarie da parte del processo, si usano un **algoritmo di allocazione** e uno di **verifica dello stato** per determinare se ci si trova in uno stato safe

ALGORITMO BANCHIERE DA CAPIRE


## Rilevamento & ripristino
Anche qui abbiamo la possibilità di agire tramite RAG, ma con molteplici risorse dobbiamo implementare un algoritmo di rilevamento specifico.


#### Rilevamento
L'algoritmo di basa sull'**esplorazione di ogni possibile sequenza di allocazione dei processi**

SIMILE AL BANCHIERE, NON SI CAPISCE UN CAZZO, PORCA PUTTANA


#### Ripristino
In caso di deadlock, si procede con l'**uccisione dei processi** coinvolti o la **prelazione delle risorse** bloccate dai processi. 

Il primo caso risulta molto costoso, anche nel caso di uccisione selettiva fino alla scomparsa del deadlock.

Nel secondo caso, effettuo un **rollback** di un processo **a uno stato di safe**, effettuando eventualmente un **total rollback**. Questo però **può generare starvation**, per cui risulta essenziale considerare il numero di rollback



# Conclusioni
Ognuno dei tre approcci presenta i suoi svantaggi. A volte la soluzione migliore è una soluzione **combinata**, come, per esempio, spartire le risorse in classi e applicare un algoritmo specifico per classe

Ma a volte, la soluzione più semplice è quella di non fare niente, come in UNIX


Next -> [[9-Gestione della memoria]]