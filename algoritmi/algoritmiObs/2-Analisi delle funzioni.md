# Proprietà della notazione asintotica

> [!info]- Reminder simboli
> ![[1-Analisi degli algoritmi#Notazione asintotica]]

## Dualità
$$f(n)=O(g(n))\Leftrightarrow g(n)=\Omega(f(n))$$
> Se $f$ è la funzione che descrive il limite superiore di $g$, allora $g$ è la funzione che descrive il limite inferiore di $f$

## Eliminazione delle costanti
$$f(n)=O(g(n))\Leftrightarrow af(n)=O(g(n)), \forall a>0$$
> Possiamo ignorare qualsiasi costante numerica. Vale anche per $\Omega$

## Sommatoria
$$f_1(n)=O(g_1(n)), f_2(n)=O(g_2(n))\Rightarrow f_1(n)+f_2(n)=O(max(g_1(n),g_2(n))))$$

> In caso di somma, prendiamo la complessità più grande. Vale anche per $\Omega$

## Cicli annidati
$$f_1(n)=O(g_1(n)), f_2(n)=O(g_2(n))\Rightarrow f_1(n)\cdot f_2(n)=O(g_1(n)\cdot g_2(n)))$$

> In caso di cicli annidati, moltiplichiamo le complessità. Vale anche per $\Omega$

## Simmetria
$$f(n)=\Theta(g(n))\Leftrightarrow g(n)=\Theta(f(n)) $$

## Transitività
$$f(n)=O(g(n)), g(n)=O(h(n))\Rightarrow f(n)=O(h(n)) $$

## Proprietà dei logaritmi
$$log(n)=O(n) $$

> [!important]+ Notazioni $o,\omega$ 
> A differenza della loro versioni maiuscole, queste notazioni richiedono che la funzione sia inferiore (o superiore) per ognuna delle casistiche di della funzione (è una versione più precisa delle maiuscola)
>
> $o(n)$ implica $O(n)$ (vale anche per $\omega,\Omega$)


> [!Important]+ Ordinamento delle funzioni
> Considerando $r<s$, $h<k$, $a<b$ 
> $O(1)$ -> $O(log^r(n))$ -> $O(log^s(n))$ -> $O(n^h)$ -> $O(n^hlog^r(n))$ -> $O(n^hlog^s(n))$ -> $O(n^k)$ -> $O(a^n)$ -> $O(b^n)$

# Ricorsione
## Equazione di ricorrenza
La ricorsione viene rappresentata matematicamente tramite un'equazione:

$$T(n)=\begin{cases}T(n/2)+\Theta(n)&n>1\\ \Theta(1)&n\leq1\end{cases}$$
che poi viene convertita in formula chiusa:
$$T(n)=\Theta(n\ log\ n)$$


> [!example]+ problema delle scale
> Si possono salire $n$ scalini facendone $1,2$ o $3$ alla volta. In quanti modi diversi si possono salire le scale?
> $$M(n)=\begin{cases}1&n\leq 0\\M(n-1)+M(n-2)+M(n-3)&n>0\end{cases}$$

## Metodi per risolvere le ricorrenze
#### Analisi per livelli

Consiste nell'analizzare i vari livelli della ricorsione

> [!Example]+ esempio 1
> $$T(n)=\begin{cases}T(n/2)+b&n>1\\c&n\geq1\end{cases}$$
> Alla $n$-esima iterazione risulterà $b+b+b+...+b+T(1)$. La somma di $b$ equivale a $log\ n$

> [!Example]+ esempio 2
> $$T(n)=\begin{cases}4T(n/2)+n&n>1\\c&n\geq1\end{cases}$$
> Il tutto ci risulterà: $$n\sum^{log\ n-1}_{j=0}2^j+4^{log\ n}$$
> Se noi incominciamo a fare trasformazioni matematiche arriviamo a $n^2$

> [!Example]+ esempio 3
> $$T(n)=\begin{cases}4T(n/2)+n^3&n>1\\c&n\geq1\end{cases}$$
> Se noi analizziamo le chiamate, deduciamo che al primo livello avremmo $n^3$, al secondo $4\cdot \left(\frac{n}{2}\right)^3$, alla terza $16\cdot\left(\frac{n}{4}\right)^3$. 
> Insomma $l\cdot\left(\frac{n}{2^{l-1}}\right)^3$ dove $l$ è il livello di profondità della ricorsione, dove in questo caso è $log_2\ n$.
> Applichiamo anche qui un po' di matematica e giungiamo alla conclusione di $2n^3+n^2$, ossia $O(n^3)$

#### Analisi per tentativi (o sostituzione)
1. Si "indovina" una possibile soluzione e si formula l'ipotesi ^c5c806
2. Si sostituisce le espressioni di $T(\cdot)$ con l'ipotesi induttiva ^63ce9f
3. Si dimostra la validità nel caso base ^4838b4

> [!example]+ esempio
> $$T(n)=\begin{cases}T(\lfloor\frac{n}{2}\rfloor)+n&n>1\\1&n\leq1\end{cases} $$
> Individuiamo subito che l'espansione della formula è uguale a $1+\frac{1}{2}+\frac{1}{4}+...$ che ad infinito porta a $2$, mentre noi ci fermiamo a $log\ n$, quindi sicuramente $2n$ è un limite superiore (semplificato a $O(n)$). Applichiamo quindi l'induzione sostituendo $T(\lfloor\frac{n}{2}\rfloor)$ con $c\cdot\lfloor\frac{n}{2}\rfloor$ e confrontando che sia minore o uguale della nostra ipotesi, ossia $cn$
> 
> $$\begin{aligned}T(n) &=T(\lfloor\frac{n}{2}\rfloor)+n\\
>& \leq c\lfloor\frac{n}{2}\rfloor+n \\
>& \leq \frac{cn}{2}+n \\
>& = (\frac{c}{2}+1)n \\
>& \leq^? cn \\
>& \Rightarrow\frac{c}{2}+1\leq c\Rightarrow c\geq 2
> \end{aligned}$$
> Dato che il caso base richiede una $c\geq 1$ e l'induzione una $c\geq 2$, esiste un valore valido per entrambi, quindi l'ipotesi è corretta
>
> Per il limite inferiore basta cambiare il segno $\leq$ con $\geq$. In caso la parte non ricorsiva non sia costante, possiamo formulare in questo modo $$T(n)=T(...)+f(x)\geq f(x)\geq^? d\ i(x)$$
> dove $f(x)$ è la parte non ricorsiva e $i(x)$ la nostra ipotesi
> 
> In caso di un'intuizione sbagliata, il risultato sarà impossibile (es: $0\geq 1$)


##### Cheat sheet

|forma|Complessità superiore|formula matematica|
|:---:|:---:|:---:|
|$T(\lfloor\frac{n}{2}\rfloor)+T(\lceil\frac{n}{2}\rceil)+1$|$O(n)$|$\sum^{log\ n}_{i=0}2^i$|
|$T(\lfloor\frac{n}{2}\rfloor)+n$|$O(n)$|$n\cdot\sum^{log\ n}_{i=0}\frac{1}{2}^i$|
|$T(n-1)+n$|$O(n^2)$|$\sum_{i=1}^ni$|
|$2T(\lfloor\frac{n}{2}\rfloor)+n$|$O(n\ log\ n)$||
|$9T(\lfloor\frac{n}{3}\rfloor)+n$|$O(n^2)$||

#### Analisi per ricorrenze comuni

#### Metodo dell'esperto (Master Theorem)
Si basa su una famiglia di teoremi che permette una semplice risoluzione

##### Ricorrenze lineari con partizione bilanciata
Presa una funzione nella forma $$T(n)=\begin{cases}aT(n/b)+n^\beta&n>1\\d&n\leq1\end{cases} $$
Posto $\alpha=log_ba$, allora $$T(n)=\begin{cases}\Theta(n^\alpha)&\alpha>\beta\\\Theta(n^\alpha log\ n)& \alpha=\beta\\\Theta(n^\beta)&\alpha<\beta\end{cases}$$
##### Ricorrenze lineari di ordine costante
Con $a_{1..h}$ tutte costanti positive: $$T(n)=\begin{cases}\sum_{i=1}^h a_iT(n-i)+n^\beta&n>h\\\Theta(1)&n\leq h\end{cases}$$
Posto $a=\sum a_{1..i}$ allora $$T(n)=\begin{cases}\Theta(n^{\beta+1})&a=1\\\Theta(a^nn^\beta)&a\geq 2\end{cases}$$
