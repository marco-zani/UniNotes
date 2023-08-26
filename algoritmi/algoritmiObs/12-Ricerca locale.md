
Il concetto è: data una soluzione valida, si può cercare una soluzione migliore nelle sue vicinanze

# Flusso massimo
## Definizioni
Una rete di flusso, è un grafo con l'aggiunta di due nodi particolari, una sorgente e un pozzo, e il flusso è una funzione con le seguenti proprietà:
- vincolo sulla capacità: il flusso non è superiore alla capacità dell'arco
- Simmetria opposta: il flusso che attraversa un arco in una direzione è l'opposto di quello che lo attraversa in direzione contraria
- Conservazione del flusso: per ogni nodo (esclusi sorgente e pozzo) la somma dei flussi entranti è pari alla somma dei flussi uscenti

Il valore del flusso è pari alla somma dei flussi uscenti dalla sorgente
## Problema
Data una rete trovare il flusso massimo che la può attraversare

## Metodo delle reti residue
1. Si parte con la rete iniziale
2. Si trova un flusso dalla rete 
	1. Si identifica un cammino nel grafo e si assegna come capacità del cammino l'arco di peso minore (collo di bottiglia)
3. lo si sottrae alla rete, ottenendo così la rete residua
	1. Durante la sottrazione, oltre che a diminuire la capacità degli archi, si aumenta la capacità degli archi opposti
4. Si ripete step 2 e 3 fino a che non ci sono più flussi
5. Si sommano tutti i flussi individuati, ottenendo il flusso massimo

## Complessità
$O(VE^2)$

# Variazioni
- Flusso massimo con capacità limitata
- Flusso generato o consumato in ogni nodo
- Flussi con costo associato, ricerca del costo minimo

## Abbinamento massimo dei grafi bipartiti
Dati $n$ jobs, $m$ workers e una lista di coppie tra job e workers che rappresenta le abilitazioni. L'obbiettivo è assegnare il maggior numero di jobs ad un singolo worker diverso