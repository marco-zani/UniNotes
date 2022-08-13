# Introduzione
## Modello produttore-consumatore
Ipotizziamo l'accesso a un buffer da parte di due funzioni che leggono il valore nel buffer, lo estraggono e poi o lo aumentano o lo diminuiscono. In base alla sequenza definita dallo scheduler, i valori riportati possono non coincidere con quelli che ci si aspetta.

il problema è che entrambi i processi possono **accedere contemporaneamente alla sezione critica**

## Sezione critica
Con sezione critica si intende una porzione di codice in cui si accede a una **risorsa condivisa**. Per risolvere il problema si richiedono 3 criteri:
- la **mutua esclusione**
- il **progresso** (solo i processi intenti ad entrare nella SC possono determinare chi entra)
- l'**attesa limitata**

vengono implementate tre tipologie di soluzioni: la sincronizzazione in ambiente globale (condivisione di una cella di memoria), soluzione software oppure HW


# Soluzioni software
## Algoritmo alternato
Usufruisce di stretta alternanza tra due processi, ma non rispetta il criterio del progresso dato che se un processo non è interessato ad accedere alla SC impedisce anché all'altro processo di entrare 

## Algoritmo con flag
simile all'alternato, ma imposta un flag a true quando vuole entrare nella sezione critica, ma se entrambi i processi si impostano in attesa portano ad un deadlock

## Algoritmo corretto
``` 
// Processo i
int turn;
boolean flag[2];
while(1){
	flag[i]=TRUE;
	turn=j;
	while(flag[j]==TRUE && turn==j){
		\\sezione critica
	}
	flag[i]=FALSE;
}
```
Questo algoritmo rispetta tutte e tre le condizioni della situazione critica

## Algoritmo del fornaio
Applica l'algoritmo individuato a molteplici processi. A ogni processo viene assegnato un valore che determina l'ordina con la quale può accedere alla SC


# Soluzioni Hardware
La soluzione più efficente a livello hardware è quella di **rendere l'accesso alla risorsa breve** quanto un singolo ciclo di istruzione (o **istruzione atomica**)


## Test&Set
```
bool TestAndSet(bool &var){
	bool temp=var;
	var = true;
	return temp;
}

main(){
	bool lock = false;
	
	while(1){
		while(TestAndSet(lock));
		//SC
		lock = false;
	}
}
```

## Swap
Molto simile al test&set usa lo scambio della variabile lock con valori "dummy" impostati a true

## Test&Set e Swap con attesa limitata
Nessuna delle due soluzioni rispetta però l'attesa limitata

==========
non ho capito

=========

## Vantaggi e svantaggi
le soluzioni HW risultano più facilmente **scalabili** ma più **complesse** da implementare per il programmatore, senza contare che richiedono il busy waiting (**spreco CPU**)


# Semafori
I semafori si presentano come soluzione generica ai problemi delle soluzioni precendenti

Presentano una **variabile intera** (binaria o generica, ossia con valori >= 1) che può essere accessa tramite 2 funzioni:
- **Signal** (V): **Incrementa** la variabile di 1
- **Wait** (P): **tenta di decrementare** la variabile di 1. Se la variabile è a 0, **attende**

L'implementazione dei semafori binari, per garantire l'atomicità, richiede busy waiting (o spinlock)

 I **semafori interi** invece, possono essere implementati **senza busy waiting**

```
P(Sem &s){
	 P(mutex);
	 s.value -= 1 
	 if(s.value<0){
		 V(mutex);
		 append(process i, .List);
		 sleep();
	 }else
		 V(mutex);
} 
```
 
 ```
V(Sem &s){ 
	P(mutex) 
	s.value += 1 
	if(s.value<0){
		V(mutex);
		PCB *p = remove(s.List);
		wakeup(p);
	}else
		V(mutex);
}	
```

Il busy waiting viene quindi spostato all'interno della mutex (mutua esclusione), che risulta più veloce e diminuisce lo spreco. 
In alternativa si possono disabilitare gli interrupt durante `P()` e `V()`


## Semafori per attesa evento
Per l'esecuzione di azioni in successione può essere utilizzato un semaforo impostato in partenza a 0

## Limitazioni
un processo può entrare in **deadlock** se **attende un evento che solo lui può generare**, oppure soffrire di **starvation** se rimane in attesa indefinita. Inolte possono essere complessi da implementare correttamente nel codice, per ciò sono state create delle alternative ad alto livello

# Monitor
**Construtti ad hoc** per la condivisione di dati. In ogni monitor **limita l'accesso** a variabili e procedure **ad un singolo processo alla volta**

Per l'accesso alla queue del monitor si usano variabili **condition** accessibili tramite le primitive `wait()`, che blocca sempre il processo chiamante, e `signal()`, che sveglia il processo.

In seguito al `signal()` il processo può o passare l'esecuzione al processo sbloccato, o uscire dal monitor

Sfortunatamente sono pochi i linguaggi che forniscono un monitor


## Problemi classici
- produttore/consumatore
- i filosofi a cena
- il barbiere assonnato



Next -> [[8-Deadlock]]