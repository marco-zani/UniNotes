# Definizioni
## Modelli di calcolo
La **complessità** corrisponde alla relazione tra dimensione dell'input e il tempo impiegato dall'algoritmo

#### Dimensione dell'input
il numeor di **bit** necessari a rappresentare un input è definito **criterio di costo logaritmico**, mentre il **numero di elementi** corrisponde al **criterio di costo uniforme**

#### Tempo
Un istruzione elementare

#### Modello di calcolo
È un'astrazione del calcolatore. Usiamo la **Random Access Machine**, caratterizzata da **memoria infinita** ed a tempo d'accesso costante, **processore singolo** e costo delle istruzioni uniforme

#### Classi di complessità

|$f(n)$|**Tipo**|
|:--:|:--:|
|$log\ n$|logaritmico|
|$\sqrt{n}$|sublineare|
|$n$|lineare|
|$n\ log\ n$|loglineare|
|$n^2$|quadratico|
|$n^3$|cubico|
|$2^n$|esponenziale|
## Notazione asintotica
#### Notazione $O$ 
Definita come **O grande** indica la **casistica peggiore** (Limite superiore)
#### Notazione $\Omega$ 
Definita come **Omega grande** indica la **casistica migliore** (Limite inferiore)
#### Notazione $\Theta$ 
Definita come **Theta** indica la **casistica media, o esatta**

# Complessità problemi vs algoritmi
Un algoritmo immediato non è sempre migliore, il modo per confermarlo è dimostrando il contrario

La complessità di un algoritmo consiste nel costo di esecuzione in base all'input

La complessità di un problema invece valuta molteplici algoritmi, individuando il migliore ($O(f(n))$), l'ottimo ($\Theta(f(n))$) e il limite di tempo inferiore ($\Omega(f(n))$)

> [!important]+ Divide-et-impera
> Divide: dividere un problema in sotto problemi di dimensione inferiori
> Impera: risolvi i sottoproblemi con la ricorsione
> combina: unisci le sottosoluzioni per ottene la risposta del problema

# Tipologia dell'input
Esaminare l'imput è fondamentale per individuare l'algoritmo più adeguato

## Tipologia di analisi
L'analisi del **caso pessimo** è la **più importante**, mentre invece il caso medio è difficile da individuare, e il caso ottimo dipende eccessivamente dall'input

## Ordinamento
#### Selection sort
Si basa sulla ricerca dell'elemento minimo nel vettore, e lo spostamento nel primo slot non ordinato

Time: $O(n^2)$ 
Memory: 1

##### Min()
```C++
int min(vector<int> arr, int offset){
	int pos = offset;
	if(offset < arr.size()){
		int min = arr[offset];
		for(int i = offset; i < arr.size(); i++){
			if(arr[i]<min){
				min = arr[i];
				pos = i;
			}
		}
	} else {
		pos = -1;
	}
	return pos;
}
```

##### Selection sort
```C++
void selection_sort(vector<int> &arr){
	for (int i = 0; i < arr.size(); i++){
		int curr_min = min(arr, i);
		if(curr_min != -1){
			swap(arr,i,curr_min);
		}
	}
}
```

^7c8cfd

#### Insertion Sort
Si basa sullo scorrimento degli elementi partendo in ordine verso una posizione in cui è maggiore del precedente

Tempo: $O(n^2)$
Memoria: 1

```C++
void insertion_sort(vector<int> &arr){
	for(int i = 1; i < arr.size(); i++){
		int in_hand = arr[i];
		int ii = i;
		for(; ii > 0 && arr[ii-1] > in_hand; ii--){
			arr[ii] = arr[ii-1];
		}
		arr[ii] = in_hand;
	}
}
```

^c1a405

#### Merge sort
Basato su divide-et-impera, divide il vettore in due sotto-vettori e ripete l'azione finché non rimangono 2 elementi (o 1) e li ordina. Infine risalendo sfrutta i vettori già ordinati per ordinare con più facilità gli elementi

```c++
void merge(vector<int> &arr, int begin, int mid, int end) {
	vector<int> temp;
	  
	int left_index = begin, right_index = mid + 1;
	  
	while (left_index <= mid && right_index <= end) {
		if (arr[left_index] <= arr[right_index]) {
			temp.push_back(arr[left_index]);
			left_index++;
		} else {
			temp.push_back(arr[right_index]);
			right_index++;
		}
	}
  
	if (left_index <= mid) {
		while (left_index <= mid) {
			temp.push_back(arr[left_index]);
			left_index++;
		}
	}
  
	for (int el : temp) {
		arr[begin] = el;
		begin++;
	}
}

void merge_sort(vector<int> &arr, int begin, int end) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		  
		merge_sort(arr, begin, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, begin, mid, end);
	}
}

```

^ee997e


