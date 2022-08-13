# Ereditarietà
La gerarchia di ereditarietà viene definita tramite `extends` e permette a una classe di ereditare tutti gli attributi e metodi della classe padre. Java non permette di ereditare da più classi

Object è la radice di tutte le classi, e implementa i metodi `equals`, `finalize` e `toString`

Un'estensione di una classe può essere definita strutturale se aggiunge variabili e comportamentale se aggiunge o modifica i metodi

## Overloading e Overriding
Per accedere ai metodi della classe padre si usa la pseudo variabile `super`. Dato che i costruttori non vengono ereditati, è possibile richiamarli usando la notazione `super()` come prima istruzione del costruttore

L'Overloading consiste nell'avere più metodi dentro la stessa classe ma con firme (numero e tipo di parametri) diverse. L'Overriding invece è la ridefinizione di una fuzione passata dalla superclasse, mantenendo la medesima firma

# Polimorfismo
Basato sul concetto della **sostituzione di Liskov**, ossia che:

> Se S è sottotipo di T, allora le variabili di tipo T possono essere sostituite da variabili di tipo S senza alterare il comportamento del programma

Il polimorfismo di una variabile si differisce tra **tipo statico** e **tipo dinamico** se viene **dichiarato a compilation time** o **assunto a runtime**

>[!example]-
// tipo statico A, tipo dinamico A  
A x = new A() 
// tipo statico B, tipo dinamico B  
B y = new B()
// tipo statico A, tipo dinamico B  
A z = new B() 
// illegale
B w = new A() 

## Regole polimorfismo
>[!tldr]+ Regola 1
Il compilatore determina la firma del metodo da eseguire basandosi sul tipo statico

>[!tldr]+ Regola 2 
Solo in caso di **overriding**, la **firma** del metodo viene determinata a runtime **basandosi su tipo dinamico**