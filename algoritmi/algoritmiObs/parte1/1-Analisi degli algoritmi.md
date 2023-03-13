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
Definita come **O grande** indica la **casistica peggiore**
#### Notazione $\Omega$ 
Definita come **Omega grande** indica la **casistica migliore**
#### Notazione $\Theta$ 
Definita come **Theta** indica la **casistica media, o esatta**

# Complessità problemi vs algoritmi
Un algoritmo immediato non è sempre migliore, il modo per confermarlo è dimostrando il contrario

La complessità di un algoritmo 

> [!important]+ Divide-et-impera
> Divide: dividere un problema in sotto problemi di dimensione inferiori
> Impera: risolvi i sottoproblemi con la ricorsione
> combina: unisci le sottosoluzioni per ottene la risposta del problema


> [!warning] pag 47

