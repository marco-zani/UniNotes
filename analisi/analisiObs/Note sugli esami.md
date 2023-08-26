# Primo parziale
- individuare inf, sup, max e min
- determinare il comportamento di una funzione
- calcolo limite
- trovare i valori $\alpha$ e $\beta$ tali che rendano la funzione derivabile (o continua)
- retta tangente al grafico di f(x) in (a,f(b)) o tangente all'inversa
- numeri complessi
	- determinare la conica disegnata
	- risolvere equazioni
	- regione che soddisfa x
- determinare immagine e dominio delle funzioni

# Secondo parziale
- calcolare taylor alla x
- determinare il termine dominante di un'espressione di taylor
- calcolo di un limite
	- Hopital
- calcolo di un integrale
	- cambio di variabili
	- determinare il comportamento di un integrale
	- limite con un integrale
	- calcolo di un integrale definito
	- calcolare la convergenza dell'integrale
- calcolo di un'equazione differenziale
- teorema di lagrange

# Esami interi
1. [x] (XXXXXYYYYY) Determinare **estremo superiore/inferiore**
2. [X] (XXXXXYYYY) Tipo di soluzioni di un **equazione complessa**
	2. [X] (XX) Dati dei numeri complessi, determinare l'affermazione corretta
	3. [X] (YYY) sistema di equazioni
3. [X] (XX) Determinare **radici di equazioni complesse**
	1. [x] (XY) Date le radici di un polinomio complesso, determinare l'affermazione corretta
	2. [x] (X) Dato un numero complesso determinare l'affermazione corretta sulle sue radici
	3. [x] (Y) con parte immaginaria/reale maggiore di $x$
	4. [x] (YY) determinare il valore di un polinomio conoscendo una radice 
4. [X] (Y) determinare parti reali e immaginarie di un numero complesso
5. [x] (XY) Quale affermazione equivale alla **definizione del limite** $f$
6. [x] (XXXYYYYY) **limite di successione**
	1. [x] (X) data una successione, determinare l'affermazione corretta
7. [X] (XXXXXYYYY) Determinare $\alpha$ e $\beta$ per **mantenere continuità e derivabilità**
8. [X] (XXXXXYYYY) **Retta tangente al grafico** di una funzione in un punto $x$
	2. [X] (X)retta tangente al grafico della funzione inversa
9. [x] (XXXYYYYY) Data una funzione **identificare i punti critici** (massimo/minimo globale/locale)
	1. [x] (XY) Integrale
10. [x] (XXXXXYYYYY) **calcolare un limite**
	1. [x] (X) usando l'hopital
11. [X] (XX) Data una funzione derivabile in due punti, esiste **un punto $x$ tale che la derivata equivale a $\alpha$**
	1. [x] (XYYYY) Data una funzione affermare che in un intervallo esiste un punto la cui derivata equivale a $x$
	2. [x] (Y) Per una funzione differenziabile e di periodo $x$ vale che
12. [x] (XXYY) **Data $f$ derivabile**, calcolare il seguente limite
13. [X] (XXXXYYYYY) calcolare lo **sviluppo di taylor** di una funzione fino all'ordine $x$
	1. [x] (X) in un punto $\neq 0$ 
14. [x] (XXY) Dire **per quale $\alpha$ un integrale improprio** risulta sempre convergente
	1. [x] (X) Divergente 
	2. [x] (XY) Esiste
15. [X] (XXXXXYYYY) **Calcolare** il valore del seguente **integrale definito**
	1. [x] (XXYYYY) **Calcolare** il valore del seguente **integrale improprio**
16. [x] (XXXXXYYYYY) **trovare la soluzione** $y(t)$ del seguente problema di **cauchy**
	1. [x] (XY) Determinare una soluzione
17. [x] (XXXXXYYYYY) **Data la soluzione** al problema di **cauchy**, verificare le affermazioni nell'intorno di $x$

#### Solo vecchi esami
2. [ ] (XX) Date due funzioni, determinare l'affermazione corretta su **dominio/immagine**
17. (XX) Calcolare la **primitiva di una funzione** 
	1. [ ] (X) per parti
	2. [ ] (X) e usarla per calcolare un limite
	3. [ ] (X) e usarla per calcolare un integrale 
1. (XX) Dato un integrale determinare quale affermazione è vera
2. (X) Dato un sistema, determinare se l'integrale improprio converge o diverge
3. (X) Data una funzione, determinare il **numero di soluzioni distinte**

4. (XX) Data l'equazione differenziale $f$ tale che il limite equivale a $x$, si calcoli $f(y)$ 
# Metodi
## Analisi delle funzioni
#### Determinare estremo superiore/inferiore
- **Caso disequazione**: Si cercano i punti dove la funzione rispetta la disequazione (dove $x$ è maggiore o minore di $0$), poi si confrontano gli insiemi e si individua i limite superiore (la parentesi a destra)
- **Caso due funzioni**: Si esaminano entrambe le funzioni applicando i vari $n$. Generalmente gli insiemi generati si rimpiccioliscono
#### retta tangente alla funzione
- **Caso funzione normale**: Si calcola la derivata della funzione data e la si applica alla x del punto, ottenendo la $m$, di conseguenza si applica la seguente formula: $m(x-p_x)+p_y$ 
- **Caso funzione inversa**: Bisogna calcolare la derivata della funzione inversa, questo ci permette di applicare la formula: $(f^{-1})^I=\frac{1}{f^I}$, dopo di che si calcola con quale $f(x)=y$ dove $y$ è fornita dalla consegna e poi alla fine la formula della retta corrisponde a $m(x-p_y)+p_x$
#### Identificare punti critici
- **Caso base**: Per identificare un punto critico, abbiamo bisogno di porre la derivata della funzione equivalente a zero ($f^I(x)=0$). Questo però non è sufficiente, bisogna anche analizzare gli intorni del punto per verificare il segno della derivata (disequazione $f^I(x)>0$). Inoltre vanno analizzati i limiti dell'intervallo
## Numeri complessi
#### Soluzione di un'equazione complessa
- **Caso sistema di equazioni**: Converto i numeri complessi in modo da ottenere una equazione con gli elementi $Re(z)$ e $Im(z)$ e risolvo il sistema. In alcuni casi devo risolvere equazioni di secondo grado. In base ai risultati capisco il tipo di soluzione:
	- a e b definiti: un punto
	- a e b definiti ma con due risultati ($x^2$): due/quattro punti
	- $a/b=?$ e $b\neq?$  o $a=b$: una retta
	- $a^2+b^2\leq x$: un cerchio
	- $a^2+b^2=x$: una circonferenza (con $ca^2+b^2+db<1$, $c$ schiaccia la circonferenza, mentre $d$ la sposta )
	- $a<c$ o $a<b$ : semipiano
#### Radici di un numero complesso
- **Caso determinare polinomio da radice**: possiamo prendere le incognite del polinomio, applicare la formula $\frac{-b\pm\sqrt{b^2-4ac}}{2a}$ e metterla in equivalenza con la radice fornita
- **Caso equazione**: Si cerca di risolvere l'equazione individuando il valore di $a$ e $b$ 
- **Caso determinare radice di un polinomio**: Si risolve con la classica formula $\frac{-b\pm\sqrt{b^2-4ac}}{2a}$ 
## Limiti
#### Calcolo
- **Caso generico**: Cerchiamo di individuare la funzione fratta, e applichiamo dell'hopital $lim\frac{f(x)}{g(x)}=lim\frac{f^I(x)}{g^I(x)}$ 
#### Taylor
- **Caso centro $\neq 0$** : Si individuano $f^{(I)},...,f^{(n)}$ per poi applicare la formula $\frac{f^{(i)}(x_0)}{i!}(x-x_0)^i$
- **Caso funzione composta**: bisogna calcolare la funzione interna $g(x)$ nel centro definito $x_0$ e poi la funzione esterna centrata in $g(x_0)$
- **Caso integrale definito**: Applico la formula
#### Successioni
- **Caso generale**: Cerchiamo di estrarre la $n$ o di portarla al denominatore, in modo che ad infinito tenda a $0$. Possiamo anche applicare i limiti notevoli a patto che le funzioni composte tendano a $0$
- **Caso radici**: Possiamo usare la razionalizzazione ($\frac{1}{\sqrt{x}}\cdot\frac{\sqrt{x}}{\sqrt{x}}$ o $\sqrt{x}-\sqrt{x+a}\cdot\frac{\sqrt{x}+\sqrt{x+a}}{\sqrt{x}+\sqrt{x+a}}$)
## Derivate
#### Definire $\alpha$ per mantenere continuità e derivabilità
- **Caso continuità**: basta trovare il valore che rende equivalenti $f(x_o^-)$ e $f(x_0^+)$. Questo si può effettuare con i limiti notevoli o anche con Taylor in $x_0=0$ 
- **Caso derivabilità**: Bisogna effettuare lo stesso calcolo per la continuità, ma l'equazione va messa a sistema con l'equivalenza tra $f^I(x_0^-)$ e $f(x_0^+)$ 
#### In un intervallo esiste un punto tale che:
- **Caso generico**: Qui possono essere applicati due possibili teoremi:
	- **Lagrange**: $\exists f^I(x)=\frac{h(b)-h(a)}{b-a}$ 
	- **Valori continui**: $\exists x_0\rightarrow a < x_0 < b$ 
- **Caso periodico**: Il periodo $t$ indica ogni quanto la funzione si ripete
- **Caso della catena**: Basta convertire la forma scomposta in composta: $lim_{\to x_0}\frac{f(g(x))-f(g(x_0))}{x-x_0}=(f(g(x)))^I |_{x=x_0}$ che diventa $f^I(g(x))g^I(x)|_{x=x_0}$  
## Integrali
#### Calcolo valore integrale definito
- **Caso funzione composta**: Devo applicare l'integrazione per sostituzione, ossia $\int_b^a f(g(x))g^I(x)$ applico $t=g(x)$ e $dt=g^I(x)dx$ ottenendo $\int_{g(b)}^{g(a)} f(t)dt$ e poi nella soluzione sostituisco $F(t)$ con  $F(g(x))$. A questo punto posso applicare $\int_b^a\rightarrow F(b)-F(a)$ 
- **Caso funzione non semplice**: Posso provare ad approcciare la funzione con integrazione per parti: con $\int f(x)$ posso sempre applicare la formula $\int f(x)g^I(x)=fg-\int f^Ig$ usando come $g^I(x)=1$ e $g(x)=x$, sperando che la derivata di $f(x)$ sia più semplice da processare
#### Calcolo di un integrale improprio
- **Caso variabile per esistenza/convergenza di un integrale**: Si cerca la divergenza (generalmente $\int^{+\infty}x$ e $\int_0\frac{1}{x}$) e si usano gli asintoti per individuare come convergere usando $\frac{1}{x^\alpha}=\frac{1}{1-\alpha}$ se $\alpha<1$. Per approssimare a 0 si può usare taylor
- **Caso funzione classica**: Si effettua il calcolo come un integrale definito, può necessitare però di trasformazioni e separazioni dell'intervallo dell'integrale 
## Equazioni differenziali
#### Trovare la soluzione al problema di cauchy
- **TRUCCO**: Calcolare le soluzioni in $x_0=0$ e confrontare con le condizioni di cauchy
- **Caso EDO a variabili separabili**: Sono in forma $y^I(x)=a(x)b(y(t))$, che diventa $\int\frac{1}{b(y(x))}=\int a(x)$  
- **Caso EDO di primo ordine**: Cerco di modificare la funzione per ottenere la forma $y^I(x)+a(x)y(x)=f(x)$, da qui posso applicare la formula $e^{-A(x)}(\int f(x)e^{A(x)}dx +c)$ dove $A(x)=\int a(x)$ 
- **Caso EDO non omogenea**: Oltre alla soluzione generale, bisogna anche trovare la soluzione particolare della parte non omogenea. Quindi se $\{f(x)=P(x)$, allora eseguiamo $f(Q(x))$ dove $Q(x)$ è la forma particolare $at^2+bt+c$, e mettiamo tutto a sistema con $P(x)$, separando per i gradi di $t$. Quindi se la soluzione di $f(x)$ è $s(x)$, allora la nostra soluzione generica è $s(x)+f(Q(x))$ 
#### Verificare l'intorno di $x$ della soluzione
- **Caso generale**: Per determinare la monotonia di una funzione in un punto, se $f^I(x_0)>0$ allora è crescente, se no è decrescente. Per la convessità, $f^{II}(x_0)>0$, se no è concava