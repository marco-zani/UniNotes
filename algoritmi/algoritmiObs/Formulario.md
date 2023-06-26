## Calcolo della complessità

#### Metodo generale
![[2-Analisi delle funzioni#^c5c806]]
![[2-Analisi delle funzioni#^63ce9f]]
![[2-Analisi delle funzioni#^4838b4]]

#### Cheat sheet
![[2-Analisi delle funzioni#Cheat sheet]]
<div style="page-break-after: always;"></div>

#### Master theorem
![[2-Analisi delle funzioni#Ricorrenze lineari con partizione bilanciata]]
![[2-Analisi delle funzioni#Ricorrenze lineari di ordine costante]]

<div style="page-break-after: always;"></div>

## Algoritmi utili

#### Sorting
**Selection**
![[1-Analisi degli algoritmi#^7c8cfd]]

**Insertion**
![[1-Analisi degli algoritmi#^c1a405]]

<div style="page-break-after: always;"></div>

**Merge**
![[1-Analisi degli algoritmi#^ee997e]]

**Quicksort**
![[6-divide-et-impera#^a392a4]]

<div style="page-break-after: always;"></div>

#### Alberi
**DFS**
![[3-Alberi#^03859f]]

**BFS**
![[3-Alberi#^95fa1c]]

<div style="page-break-after: always;"></div>

**Calcolo delle possibili combinazioni**
![[3-Alberi#^d3b1e6]]
![[3-Alberi#^08e30b]]
![[3-Alberi#^19fee4]]

#### Grafi
**BFS**:
![[4-Grafi#^37b0bb]]


**DFS**:
![[4-Grafi#^81d973]]

**Identificazione dei cicli**
![[4-Grafi#^262f70]]
<div style="page-break-after: always;"></div>

![[4-Grafi#^44a571]]

**Per grafo orientato**
![[4-Grafi#^262f70]]

**Albero di copertura**
![[4-Grafi#^fc38d4]]

**Ordinamento topologico**
![[4-Grafi#^8a43b1]]

![[4-Grafi#^329189]]

![[4-Grafi#Connessioni forti]]
<div style="page-break-after: always;"></div>

## Algoritmi ricorrenti
Navigazione degli alberi
```
Object function(Node n, [dati da passare ai figli]){
	[Processa prima di mandare ai figli]
	obj = function(n.child, data)
	[Processa i dati di ritorno]
	return [dati da tornare ai padri]
}
```

Generazione di alberi
```
tree function(Arr [], int index, int n){
	Tree element = Arr[...]
	tree.insert(function(A, [nuovi indici]))
	return element
}
```

Combinatoria ricorsiva
```
int function(int remainingEl, int possibleEl){
	if(remainingEl == 0){
		return 1
	}
	int count = 0
	for(i from 0 to max(possibleEl, remainingEl)){
		count += function(remainingEl -1, possibleEl)
	}
	return count
}
```
<div style="page-break-after: always;"></div>

Combinatoria programmazione dinamica
```
int function(int totEl, int possEl){
	int t[n+1]
	t[0] = 1
	for(i from 1 to n){
		t[i] = 0
		for(k from 1 to minArg(i, possEl)){
			t[i] += t[i-k]
		}
	}
	return t[n]
}
```

Ricerca dicotomica
```
int function(Arr A [], int index, int n, int target){
	if(n >= index){
		int m = index + (n - index)/2
	
		[check elements, eventually return]
		
		if([condition left]){
			return function(A, index, m)
		} else {
			return function(A, m+1, n)	
		}
	}
}
```
<div style="page-break-after: always;"></div>

Indici paralleli
```
int function(Arr A [], int n){
	int max = 0, curr = 0
	int left = 0, right = 0 
	while(right < n){
		if([condition]){ // ex: (a[r] - a[l] <= limit)
			curr++
			max = maxArg(max, curr)
			right ++
		} else {
			curr--
			left++
		}
	}
	return max
}
```
<div style="page-break-after: always;"></div>

## Strutture Dati
#### Sequenza
![[2.5-Strutture dati#^57f04a]]

#### Insieme
![[2.5-Strutture dati#^3945ed]]
<div style="page-break-after: always;"></div>

#### Dizionario
![[2.5-Strutture dati#^1159dd]]

#### Albero binario
![[3-Alberi#^6e51aa]]
<div style="page-break-after: always;"></div>

#### Albero binario di ricerca
![[3-Alberi#^2e1ed6]]

**Successore e precedente**
![[3-Alberi#^54e8a3]]
![[3-Alberi#^5d0e03]]

![[3-Alberi#Eliminazione]]
<div style="page-break-after: always;"></div>

#### Albero Red-Black

![[3-Alberi#Rotazioni]]
<div style="page-break-after: always;"></div>

**Inserimento**
![[3-Alberi#^3baa6d]]
<div style="page-break-after: always;"></div>

![[8- Strutture dati speciali#Priority queue]]


#### Grafi
![[4-Grafi#^9fd3bc]]
