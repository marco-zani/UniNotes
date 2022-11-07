# Insiemistica
## Immagine
L'immagine di una funzione è l'insieme dei possibili risultati
#### Contro-immagine
Può essere una sezione del dominio

## Elementi di massimo e minimo
Dato l'insieme A possiamo definire le seguenti nozioni come:
- **Maggiorante/Minorante**: Insieme dei valori maggiori (o minori) uguale a ogni elemento di A
- **Limitato superiormente/inferiormente**: classificazione di un insieme se non arriva a $\pm\infty$ 
- **Massimo/Minimo**: Valori massimi (o minimi) appartenenti ad A. Oppure il minorante o maggiorante appartenente ad A
- **Estremi superiori/inferiori**: Il minimo dei maggioranti / il massimo dei minoranti

Se esistono, **massimo e minimo coincidono gli gli estremi superiori e inferiori**

# Studio di funzione
## Assioma di continuità
Dati due intervalli non intersecati, allora esistono uno o più elementi **separatori** tra i due. Non vale nell'insieme dei razionali

## Suriettività e iniettività
Una funzione è detta **surriettiva** se la linea della **funzione passa per ogni y** compreso nel dominio.
Una fuzione è detta **iniettiva** se un **solo f(x) porta ad un eventuale y** (per esempio, non la parabola)

Analiticamente:
$$
f(x_{1})=f(x_{2})\qquad f(x)=y
$$
Una funzione è **invertibile se bigiettiva**

# Numeri complessi 
## Forma cartesiana
#### Forme e conversioni
$$a+bi$$
Forma classica, viene usata nel piano di Gauss-argand rappresentando un punto $(a,b)$ con l'asse dei reali come ascisse e gli immaginari come ordinate

#### Operazioni
Valgono:
- **somme e differenze**
- **prodotto**  $$w\cdot z=(ac-bd)+(ad+bc)i$$
- **reciproco** $$\frac{1}{z}=\frac{a}{a^2+b^2}-\frac{b}{a^2 + b^2}i$$
- **divisione** $$\frac{w}{z}=\frac{(ca+bd)}{a^2+b^2}+\frac{(ad-cb)}{a^2+b^2}i$$
- **coniugato** (punto riflesso rispetto l'asse dei reali)$$\overline{z} =a-bi$$
- **modulo** (distanza tra lo 0 e il punto)$$|z|=\sqrt{a^2+b^2}$$

## Forma trigonometrica
#### Forme e conversioni
$$g, \theta$$
corrisponde alla distanza tra il punto e lo zero, e l'angolo formatosi. Questa forma vale unicamente nel 1° e 3° quadrante, per raggiungere il 2° e 4° va addizionato $\pi$
le formule di conversione sono:
- da cartesiana a trigonometrica $$g=|z|=\sqrt{a^2+b^2}\qquad\qquad\theta=arctg(\frac{b}{a})$$
- da trigonometrica a cartesiana $$a=g\cdot cos(\theta)\qquad\qquad b=g\cdot sin(\theta)$$
#### Operazioni
Valgono
- **argomento** $$arg(z)=\theta$$
	- proprietà: $arg(z+w)=arg(z)+arg(w)\qquad\qquad arg(\frac{z}{w})=arg(z)-arg(w)$ 
- **prodotto** $$z\cdot w=gr(cos(\theta+\phi)+i\cdot sin(\theta+\phi))$$
	- proprietà: $|z\cdot w|=|z|\cdot|w|$
- **reciproco** $$\frac{1}{z}=\frac{1}{g}(cos(-\theta)+i\cdot sin(-\theta))$$
- **divisione** $$\frac{z}{w}=\frac{g}{r}[cos(\theta-\phi)+i\cdot sin(\theta-\phi)]$$
	- proprietà: $|\frac{z}{w}|=\frac{g}{r}$

## Forma esponenziale
$$z=ge^{i\theta}$$
Risulta applicabile la formula di pareggio: $e^{i\theta}=cos(\theta)+i\cdot sin(\theta)$ 
#### Operazioni
- proprietà delle potenze $$z^n=g^n e^{in\theta}\qquad z\cdot w)=gr\ e^{i(\theta+\phi)}\qquad \frac{1}{z}=g^{-1}e^{-i\theta}$$
## Radici n-esime dei numeri complessi
Più numeri complessi possono riportare alla medesima equazione, questi sono definiti radici n-esime e rispecchiano l'equazione $z^n=a$ 
Per trovare le radici si usa la forma esponenenziale e la seguente formula
$$z=r\cdot e^{i\theta}\qquad allora\qquad \sqrt[n]{z}=\sqrt[n]{r}\cdot e^{i\left(\frac{\theta+2k\pi}{n}\right)} $$
Dato un polinomio $P(x)$ e $\alpha$ radice di $z$, allora $P$ è divisibile da $z-\alpha$ 
#### Teorema fondamentale dell'algebra
Ogni polinomio complesso di grado $n$ ha $n$ radici complesse. Nel caso $P$ contenga coefficienti reali allora ho radici reali o coppie coniugate di radici complesse: $$(x-\alpha)(x-\alpha)=x^2-2ax+a^2+b^2$$
Ogni polinomia è prodotto di fattori irriducibili di grado 1 o 2 che rappresentano eventuali radici reali o complesse coniugate

# Limiti

> [!warning] NON SI FANNO I LIMITI A PEZZI

Il limite di una successione può tendere a un valore, a $\pm\infty$ o non esistere. Nel caso tenda a un valore, può arrivare da sinistra o destra ($x^{+}/x^{-}$)
## Fatti generali dei limiti
$$l_{+\infty}\quad n^{\alpha}=+\infty\quad\alpha>0\qquad\qquad l_{+\infty}\quad n^{\alpha}=0\quad\alpha<0$$
#### Permanenza del segno
Dopo un punto, una successione mantiene il simbolo del limite
#### Unicità del limite
Il limite di una successione in un punto è unico 
#### Casistiche possibili
$$
\overset{\mathcal{L}}{+\infty}\quad f(x)
\qquad\qquad
\overset{\mathcal{L}}{-\infty}\quad f(x)
\qquad\qquad
\overset{\mathcal{L}}{x_{0}}\quad f(x)
$$
#### Sottosuccessioni
È sufficente trovare 2 sotto successioni con limiti differenti per determinare che la successione non ha limite
#### Successioni monotone
Una successione si definisce **debolmente o strettamente crescente/decrescente** se ogni **elemento successivo risulta maggiore-uguale o solamente maggiore** (o minore). Quindi una successione debolmente crescente o decrescente può tendere o a $\pm\infty$ o a $l$ 
## Strumenti per il calcolo dei limiti di funzione
### Teoremi algebrici
Con $a_{n}\to l_{1}$ e $b_{n}\to l_{2}$
$$a_{n}\pm b_{n}\qquad\qquad a_{n}^{b_{n}}\to l_{1}^{l_{2}}$$
$$a_{n}\cdot b_{n}\to l_{1}\cdot l_{2}\qquad\qquad\frac{a_{n}}{b_{n}}\to\frac{l_{1}}{l_{2}}$$
$$
|a_n|\to0\qquad\Rightarrow\qquad a_n\to0
$$
Vale tutto tranne nei casi ambigui, ossia $\pm\infty\mp\infty$, $0\cdot(\pm\infty)$, $\frac{0}{0}$, $\frac{\pm\infty}{\pm\infty}$, $0^{0}$, $(\pm\infty)^{0}$, $1^{\pm\infty}$, $\frac{x}{0}$  
### Teorema del confronto
se $a_{n}\geq b_{n}$ allora:
- quando $b_{n}\to+\infty$ allora $a_{n}\to+\infty$
- quando $a_{n}\to-\infty$ allora $b_{n}\to-\infty$
#### Confronto a tre
Se $a_{n}\leq b_{n}\leq c_{n}$ e $a_{n}\to l$ e $c_{n}\to l$ allora anche $b_{n}\to l$

### Criteri della radice e del rapporto
#### criterio della radice
Con una successione in forma $\sqrt[n]{a_{n}}\to l$:
- se $l>1$ allora $a_{n}\to+\infty$
- se $l<1$ allora $a_{n}\to 0$
- se $l=1$ allora non ho informazione
#### Criterio del rapporto
Con una successione $a_{n}>0$ posso eseguire il limite $L\to\infty\quad\frac{a_{n+1}}{a_{n}}$ e applicare la casistica del criterio della radice
#### Criterio rapporto->radice
Con una successione $a_{n}>0$, se riesco ad applicare il criterio del rapporto allora riesco ad applicare anche quello della radice. **NON VALE IL CONTRARIO**
#### Criterio funzione->successione
### Continuità
Una funzione si definisce continua se esiste il limite nei vari punti dell'intervalloo della funzione
#### Caratterizzazione di non esistenza
Dato $\overset{\mathcal{L}}{x_{0}^{+}}\quad f(x)=a$  e  $\overset{\mathcal{L}}{x_{0}^{-}}\quad f(x)=b$  e $a\neq b$ allora il limite di $\overset{\mathcal{L}}{x}\quad f(x)$ non esiste
### Cambiamenti di variabile
### Limiti notevoli
[[Formulario#Limiti notevoli]]
### Ordine d'infinito
[[Formulario#Ordine d'infinito]]
## o-Piccolo
Si segna $f(x)=o(g(x))$ se esiste una funzione tale che $$f(x)=g(x)w(x)\qquad\qquad\overset{\mathcal{L}}{x_0}\quad w(x)=0$$
ossia esisten una funzione tendente a zero che si mangia $g(x)$. In alternativa vale
$$\overset{\mathcal{L}}{x_0}\quad\frac{f(x)}{g(x)}=0$$
#### proprietà dell'o-piccolo
date le funzioni $f_1(x)=g(x)w_1(x)$ e $f_2<(x)=g(x)w_2(x)$
- somma: $o(g)\pm o(g)=o(g)$  
- costante: $c\cdot o(g)=o(g)$ 
- prodotto: $o(g)\cdot o(g)=o(g^2)$
- composizione: $o(o(g))=o(g)$ 
#### Sviluppi dell'o-piccolo
[[Formulario#Sviluppi dell'o-piccolo]]

## Hopital
> [!warning] poco usato, meglio [[#Formula di Taylor]]

Volendo calcolare il limite $\overset{\mathcal{L}}{x_0}\quad\frac{f(x)}{g(x)}$ ben definito, ma indeterminato ($\frac{0}{0}$, $\frac{\pm\infty}{\pm\infty}$). Allora:
$$\overset{\mathcal{L}}{x_0}\quad\frac{f^I(x)}{g^I(x)}=l\qquad\Rightarrow\qquad\overset{\mathcal{L}}{x_0}\quad\frac{f(x)}{g(x)}=l$$

> [!info]- NB
> Se il limite delle derivate non esiste, allora non posso applicare il teorema


# Derivate
#### rapporto incrementale
$$\frac{f(x_0+h)-f(x_0)}{h}$$
questa funzione ci ritorna il coefficiente angolare della funzione nel punto $x_0$ con intervallo $h$
#### Condizione di derivabilità
Una funzione è derivabile se il limite con $h\to0$ esiste, ossia i limiti sinistro e destro della derivata nel punto $x_0$ devono esistere e coincidere

#### Derivabilità
È derivabile la somma, il prodotto, il quoziente e la composizione tra derivabili
## Derivata e o-piccolo
$$f(x_0+h)=f(x_0)+f^I(x_0)h+o(h)\qquad \text{se }h\to0$$
## Regole di derivazione
[[Formulario#Regole di derivazione]]

## Formula di Taylor
Data una funzione che tende a $0$, esiste un polinomio in forma $P(x_0)+o(x^a),\ x\to0$ in grado di approssimare la funzione

> [!info]- Resto di Peano
> la parte $o(x^a)$ è definita resto di peano

$P_n(x)$ deriva dalla formula:
$$\frac{f(0)}{0!}+\frac{f^I(0)}{1!}x+...+\frac{f^{(n)}(0)}{n!}x^n+o(x^k)\qquad\text{oppure}\qquad \sum^n_{k=0}{\frac{f^{(k)}(0)}{k!}x^k}+o(x^k)$$

> [!info]- Utile
> Data $f(x)$, quanto vale la derivata terza nel punto $0$?
> I coefficienti di sviluppo di Taylor al grado $x^3$ sono la nostra derivata diviso $3!$, quindi devo moltiplicare Taylor per $3!$

#### Tabella degli sviluppi di Taylor
[[Formulario#Forma compatta]]

#### Algebra di Taylor
[[Formulario#Algebra degli sviluppi di Taylor]]

### Taylor nel punto $x_0\neq 0$ 
$$
f(x)=\sum\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n + o((x-x_0)^n)
$$

# Integrali
#### indefiniti e definiti
Un integrale si definisce indefinito se non viene calcolato in un intervallo specifico


# Equazioni differenziali
#### Problema di cauchy
equazione differenziale con condizioni iniziali che determinano il valore dei parametri