# Basi
## Induzione
Si verifica un'affermazione $\mathcal{P}_{n}$ al caso base dato e in un ipotetico caso successivo  $\mathcal{P}_{n+1}$
1. $f(x)$ dove $x$ è il caso base
2. $\mathcal{P}_{n} + f(n+1)=\mathcal{P}_{n+1}$ nel caso di un'uguaglianza
3. 

## Divisione fra polinomi
$$
P_{1}=P_{2}Q+R\Rightarrow \frac{P_{1}}{P_{2}}=Q+\frac{R}{P_{2}}
$$
1. Ordinare i termini e tabellare aggiungendo i termini a zero
2. divisione fra i termini di massimo grado
3. moltiplicare il risultato per il divisore invertito di segno e addizioniamolo al dividendo
4. ripetiamo i passi 2 e 3 fino a quando il grado del dividendo è minore a quello del divisore
5. ci rimangono in tabella il quoziente e il resto

## Ruffini

## Fattorizzazione dei polinomi
- si cercano le radici intere nei sottomultipli del termine noto
$$ 
x^{3}+3x^{2}-25x+\underline{21}\rightarrow(1,3,7,21)
$$

# Derivate
#### Calcolo derivata inversa in un punto y
- calcolo la derivata della funzione
- calcolo il punto x mettendo in equazione la funzione e la y
- calcolo la derivata nel punto x
- infine applico 1/(f'(x))

# continuità con parametro
risolvo il limite (molto probabilmente con taylor) e porto a sinistra la a

# Integrali
#### integrali per sostituzione


# Equazioni differenziali
#### equazioni differenziali elementari
Nel caso in cui l'equazione sia nella forma 
$$
y^{(n)}=f(x)
$$
Allora ci basta integrare f(x)

#### equazioni differenziali a variabili separiabili
Nel caso in cui l'equazione sia nella forma 
$$
y^{I}=f(x)\cdot g(y)
$$
si suddivide y' in dy/dx, e si spostano gli elementi, risolvono i due integrali e si isola la y

DIO RICORDA CHE 1/e^(x) È UGUALE A e^(-x)

#### equazioni differenziali lineari del primo ordine
Nel caso in cui l'equazione sia nella forma 
$$
y^{I}+a(x)y(x)=f(x)
$$