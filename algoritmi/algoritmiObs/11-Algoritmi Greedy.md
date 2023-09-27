I problemi di ottimizzazione richiedono una sequenza di decisioni. 
Mentre la programmazione dinamica le valuta tutte, gli algoritmi greedy valutano solo la più promettente. È però necessario dimostrare l'affermazione.
Non tutti i problemi hanno una soluzione greedy


> [!Important]+ Greedy in 4 passi
> - Passare da un problema di scelte alternative a **scelte successive**
> - **Evidenziare** una possibile **scelta ingorda**
> - **Evidenziare** la **sotto-struttura** ottima (sotto problema con medesima struttura)
> - Il codice è in **top-down**, anche **iterativo**

> [!Important]+ Metodo per le dimostrazioni
> Ipotizziamo una soluzione ottima rispettando la nostra scelta greedy. Successivamente ipotizziamo una soluzione ottima senza considerare la scelta ottima secondo l'elemento greedy

> [!warning] proseguire alla slide 57 (forse slide 66 può aiutare)



# Problema degli intervalli pesati
Dati degli intervalli, trovare l'insieme di intervalli di cardinalità massima
## Teorema
Considerando $m$ come l'intervallo in $S[i..j]$ con il minor tempo di fine, allora:
- $S[i..m]$ è vuoto
- $m$ è compreso in qualche soluzione ottima
Di conseguenza non mi interessa più trovare tutte le altre possibilità. quindi analizzo il sotto problema successivo
## Codice
```c++
vector<Interval> solveIntervals(vector<Interval> list){
	vector<Interval> out;
	  
	out.push_back(list[0]);
	  
	int last = 0;
	 
	for (int i = 1; i < list.size(); i++){
		if(list[i].begin > list[last].end){
			out.push_back(list[i]);
			last = i;
		}
	}
	return out;
}
```

# Problema del resto
Dare il resto con il numero minimo di monete. L'algoritmo greedy è estrarre la più grande valuta minore del valore da raggiungere
# Problema di scheduling
Organizzare i job in modo da ridurre il tempo medio di completamento. La soluzione è ordinare in job dal minore al maggiore

# Problema dello zaino frazionario
Simile al problema che abbiamo esaminato in precedenza, con la differenza che si prendere solo una parte dell'oggetto

La soluzione risulta immediata: basta dividere il prezzo per il peso, e ordinare gli oggetti in questo modo, quando raggiungiamo il limite della capienza dello zaino, dividiamo l'ultimo oggetto di valore massimo in modo da farlo stare nello zaino

# Problema della compressione

# Albero di copertura di peso minimo
## Definizioni
- Un taglio è una divisione di un grafo in due sotto-insieme disgiunti
- un arco attraversa il taglio se i due vertici appartengono a insieme diversi
- Un taglio rispetta un insieme di archi se nessuno di questi attraversa il taglio
- un arco leggero è l'arco di peso minore tra tutti gli archi che attraversano il taglio
- un arco è sicuro se rispetta l'insieme o è un arco leggero
## Algoritmo di kruskal
Si usano gli archi di peso minimo e che connettono alberi distinti della foresta

## Algoritmo di Prim
Parte da una radice, è aggiunge l'arco leggero dell'albero che va a generare