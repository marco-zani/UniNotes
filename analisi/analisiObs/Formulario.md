# Scomposizione dei polinomi
$$
(a-1)(a^{2}+a+1)=a^{3}-1
$$
# combinatoria
$$\binom{n}{k}=\frac{n!}{k!(n-k)!}$$ 
# Numero di nepero
$$
e=\left(1+\frac{1}{n}\right)^n
$$
# Limiti
Nota bene: 
$a^{n}=\infty => +\infty\quad\forall a>1\qquad\qquad a^{n}=\infty =>0\quad\forall a\in(-1,1)$ 
## Limiti notevoli
#### Equivalenza asintotica
___
 $$
 lim_{n\to 0}\quad\frac{numeratore}{denominatore} \times\ denominatore
$$
$$
  risultato\ LN \times denominatore
$$
___
#### Limiti notevoli trigonometrici
$$ 
\overset{\mathcal{L}}{0}\quad\frac{sin(x)}{x}=\frac{tan(x)}{x}=\frac{arcsin(x)}{x}=\frac{arctan(x)}{x}=\frac{sinh(x)}{x}=\frac{tanh(x)}{x}=1
$$
$$
	\overset{\mathcal{L}}{0}\quad\frac{1-cos(x)}{x^{2}}=\frac{1}{2}
	\qquad\qquad
	\overset{\mathcal{L}}{0}\quad\frac{1-cos(x)}{x}=0
$$
#### Limiti notevoli esponenziali e logaritmici
$$
	\overset{\mathcal{L}}{+\infty}\quad\left(1+\frac{1}{x}\right)^{x}=e
	\qquad\qquad
	\overset{\mathcal{L}}{0}\quad\frac{ln(x+1)}{x}=1
	\qquad\qquad
	\overset{\mathcal{L}}{0}\quad\frac{log_{a}(x+1)}{x}=\frac{1}{ln(a)}
$$
$$
\overset{\mathcal{L}}{-\infty}\quad\left(1+\frac{1}{x}\right)^{x}=e
\qquad\qquad
\overset{\mathcal{L}}{0^{+}}\quad x\cdot ln(x)=0
$$
$$ 
	\overset{\mathcal{L}}{0}\quad\frac{(1+x)^{a}-1}{x}=a
	\qquad\qquad
	\overset{\mathcal{L}}{0}\quad\frac{a^{x}-1}{x}=ln(a)
	\qquad\qquad
	\overset{\mathcal{L}}{0}\quad\frac{e^{x}-1}{x}=1
$$
## Ordine d'infinito
$$
\overset{\mathcal{L}}{+\infty}\quad\frac{a^n}{n^b}=+\infty
\qquad\qquad
\overset{\mathcal{L}}{+\infty}\quad\frac{n^n}{n!}=+\infty
\qquad\qquad
\overset{\mathcal{L}}{+\infty}\quad\frac{\sqrt[n]{n!}}{n}=+\infty
$$
$$
\overset{\mathcal{L}}{+\infty}\quad\frac{(log(x))^a}{x^b}=0
\qquad\qquad
\overset{\mathcal{L}}{0^+}\quad x\cdot log(x)=0
$$
## Sviluppi dell'o-piccolo
$$sin(x)=x+o(x)\qquad cos(x)=1-\frac{x^2}{2}+o(x^2)\qquad tan(x)=x+o(x)$$
$$e^x=1+x+o(x)\qquad log(1+x)=x+o(x)\qquad (1+x)^\alpha=1+\alpha x+o(x)$$
$$arcsin(x)=x+o(x)\qquad arctan(x)=x+o(x)$$

# Derivate
$$
	\frac{\Delta y}{\Delta x}=\frac{f(x_{0}+h)-f(x_{0})}{h}
$$

#### Derivate fondamentali
$$
	f(x)=constante \quad\Rightarrow\quad f^{I}(x)=0
	\qquad\qquad\qquad 
	f(x)=x^{a} \quad\Rightarrow\quad f^{I}(x)=ax^{a-1}
$$
$$ 
	f(x)=a^{x} \quad\Rightarrow\quad f^{I}(x)=a^{x}ln(a)
	\qquad\qquad\qquad 
	f(x)=e^{x} \quad\Rightarrow\quad f^{I}(x)=e^{x}
$$
$$ 
	f(x)= log_{a}(x) \quad\Rightarrow\quad f^{I}(x)=\frac{1}{x\ ln(a)}
	\qquad\qquad\qquad
	f(x)=ln(x) \qquad\Rightarrow\qquad f^{I}(x)=\frac{1}{x}
$$
$$ 
	f(x)=|x| \quad\Rightarrow\quad f^{I}(x)=\frac{|x|}{x}
	\qquad\qquad\qquad 
	f(x)=sin(x) \quad\Rightarrow\quad f^{I}(x)=cos(x)
$$
$$ 
	f(x)=cos(x) \quad\Rightarrow\quad f^{I}(x)=-sin(x)
$$
$$
	f(x)=tan(x) \quad\Rightarrow\quad f^{I}(x)=\frac{1}{cos^{2}(x)}
$$
$$ 
	f(x)=cot(x) \quad\Rightarrow\quad f^{I}(x)=-\frac{1}{sin^{2}(x)}
$$
$$
	f(x)=arcsin(x) \quad\Rightarrow\quad f^{I}(x)=\frac{1}{\sqrt{1-x^{2}}}
$$
$$ 
	f(x)=arccos(x) \quad\Rightarrow\quad f^{I}(x)=-\frac{1}{\sqrt{1-x^{2}}}
$$
$$
	f(x)=arctan(x) \quad\Rightarrow\quad f^{I}(x)=\frac{1}{1+x^{2}}
$$
$$ 
	f(x)=arccot(x) \quad\Rightarrow\quad f^{I}(x)=-\frac{1}{1+x^{2}}
$$
$$
	f(x)=sinh(x) \quad\Rightarrow\quad f^{I}(x)=cosh(x)
	\qquad\qquad
	f(x)=cosh(x) \quad\Rightarrow\quad f^{I}(x)=sinh(x)
$$

#### Regole di derivazione
$$
(f\pm g)^{I} = f^{I} + g^{I}\qquad (c\cdot f)^{I}=c\cdot f^{I}
$$
$$
\left(\frac{1}{f}\right)^I=-\frac{f^I}{f^2}
$$
$$
(f\cdot g)^{I}=f^{I}\cdot g+g^{I}\cdot f\qquad (\frac{f}{g})^{I}=\frac{f^{I}g-g^{I}f}{g^{2}}
$$
Con $f$ inversa di $g$:
$$
(f(g))^I=1\quad\Rightarrow\quad f^I(g)\cdot g^I=1\quad\Rightarrow\quad g^I=\frac{1}{f^I(g)}
$$
Funzione composta
$$
(g(f))^{I}=g^{I}(f)\cdot f^{I}\qquad (h(g(f)))^{I}=h^{I}(g(f))\cdot g^{I}(f)\cdot f^{I}
$$
#### Derivata della funzione inversa
$$
	(f^{-1})^{I}(y_{0})=\frac{1}{f^{I}(x_{0})}=\frac{1}{f^{I}(f^{-1}(y_{0}))}
$$
#### Retta tangente al grafico
$$y=f(x_0)+f^I(x_0)(x-x_0)$$
	# Sviluppi di taylor
$$
f(x)=\sum^{n-1}_{i=0}\frac{f^{(i)}(x_{0})}{i!}(x-x_{0})^{i}+R_{n}(x)	
$$
#### Sviluppi di Taylor McLaurin
##### Forma compatta
$$
e^{x}=\sum^{\infty}_{n=0} \frac{x^{n}}{n!}
\qquad\qquad
ln(x)=\sum^{\infty}_{n=1} (-1)^{n+1}\ \frac{x^{n}}{n}
$$
$$ 
\frac{1}{1-x}=\sum^{\infty}_{n=0}x^{n}
\qquad\qquad
\frac{1}{1+x^{2}}=\sum^{\infty}_{n=0}(-1)^{n}\ x^{2n}
$$
$$
sin(x)=\sum^{\infty}_{n=0}\frac{(-1)^{n}}{(2n+1)!}\ x^{2n+1}
\qquad\qquad
cos(x)=\sum^{\infty}_{n=0}\frac{(-1)^{n}}{(2n)!}\ x^{2n}
$$
per seno e coseno iperbolico togliere $(-1)^n$
$$ 
	arctan(x)=\sum^{\infty}_{n=0}(-1)^{n}\frac{x^{2n+1}}{2n+1}
$$
$$(1+x)^-1=\sum^n_{k=0}{(-1)^kx^k}$$
##### Forma estesa
$$
e^{x}=1+x+\frac{x^{2}}{2}+\frac{x^{3}}{6}+\frac{x^{4}}{24}+\frac{x^{5}}{120}
$$
___
$$
ln(1+x)=x-\frac{x^{2}}{2}+\frac{x^{3}}{3}-\frac{x^{4}}{4}+\frac{x^{5}}{5}
$$
___
$$
(1+x)^{a}=1+ax+\frac{a(a-1)}{2}x^{2}+\frac{a(a-1)(a-2)}{6}x^{3}+\cdot\cdot\cdot
$$
___
$$
(1+x)^{-1}=1-x+x^2-x^3+x^4-x^5+...
$$
___
$$
\sqrt{1+x}=1+\frac{x}{2}-\frac{x^{2}}{8}+\frac{x^{3}}{16}-\frac{5}{128}x^{4}+\cdot\cdot\cdot
$$
___
$$
\sqrt[3]{1+x}=1+\frac{x}{3}-\frac{x^{2}}{9}+\frac{5}{81}x^{3}-\frac{10}{243}x^{4}+\cdot\cdot\cdot
$$
___
$$
	sin(x)=x-\frac{x^{3}}{6}+\frac{x^{5}}{120}
$$
Nel seno iperbolico tutti i segni sono a +
___
$$
	cos(x)=1-\frac{x^{2}}{2}+\frac{x^{4}}{24}
$$
Nel coseno iperbolico tutti i segni sono a +
___
$$
arctan(x)=x-\frac{x^{3}}{3}+\frac{x^{5}}{5}
$$
#### Formula di quel succhia cazzi di Peano
$$
f(x)=\sum^{\infty}_{n=0}\frac{f^{(n)}(x_{0})}{n!}\ (x-x_{0})^{n}
$$
#### Algebra degli sviluppi di Taylor
Indicando con P(x) e Q(x) gli sviluppi di Taylor delle funzioni f(x) e g(x) di ordine n
$$
	af(x)= aP_{n}(x)+o(x^{n})
$$
$$
f(x)+g(x)=P_{n}(x)+Q_{n}(x)+o(x^{n})
$$
$$
f(x)g(x)=P_{n}(x)\cdot Q_{n}(x) + o(x^n)
$$
$$
f(g(x))=P_{n}(q_{n}(x))
$$

> [!warning]+ Attenzione alla funzione interna!
> Se la funzione interna non tende a $0$ allora non posso applicare Taylor nel punto 0


# Integrali
#### Proprietà dell'integrale
$$
\int^{b}_{a}f(x)dx=-\int^{a}_{b}f(x)dx
$$
$$
\int_{a}^{b}[f(x)+g(x)]dx=\int_{a}^{b}f(x)dx+\int_{a}^{b}g(x)dx
$$
$$
\int_{a}^{b}[cf(x)]dx=c\int_{a}^{b}f(x)dx
$$
#### Teorema fondamentale
$$
\int_{a}^{b}f(x)=F(b)-F(a)
$$
#### Integrali fondamentali
$$
\int a\ dx = ax + c\qquad \int x^{n}\ dx=\frac{x^{n+1}}{n+1}+c\qquad\int\frac{1}{x}\ dx=ln(|x|)+c
$$
$$
\int sin(x)\ dx= -cos(x)+c\qquad \int cos(x)\ dx=sin(x)+c
$$
$$
\int\frac{1}{cos^{2}(x)}\ dx=tan(x)+c\qquad \int\frac{1}{sin^{2}(x)}\ dx=-cot(x)+c
$$
$$
\int e^{x}\ dx=e^{x}+c\qquad\int a^{x}\ dx=\frac{a^{x}}{ln(a)}+c
$$
$$
\int sinh(x)\ dx=cosh(x)+c\qquad\int cosh(x)\ dx=sinh(x)+c
$$
$$
\int\frac{1}{1+x^{2}}\ dx=arctan(x)+c
$$
$$
\int\frac{1}{\sqrt{1-x^{2}}}\ dx=arcsin(x)+c\qquad\int\frac{-1}{\sqrt{1-x^{2}}}\ dx=arccos(x)+c
$$
#### Integrazione per parti
$$
\int f(x)g^{I}(x)\ dx=f(x)g(x)-\int f^{I}(x)g(x)\ dx+c
$$
In alternativa, con g derivata
$$
\int f\cdot g = f\cdot G - \int f^{I}\cdot G
$$
Nelle funzioni elementari non integrabili direttamente, conviene integrare per parti con 1 come seconda funzione

#### Integrazione per sostituzione
$$
\int f(g(x))g^{I}(x)\ dx= \left[\int f(t)\ dt\right]_{t=g(x<)}
$$



# Equazioni differenziali
#### Equazioni differenziali lineari del primo ordine
$$
y^{I}+a(x)y(x)=f(x)\qquad\Rightarrow\qquad y(x)=e^{-A(x)}\int f(x)e^{A(x)}dx+ce^{-A(x)}
$$
#### Equazioni differenziali lineari del secondo ordine a coefficenti costanti omogenee
$$
ay^{II}+by^{I}+cy(x)=0
$$
Da qui si aprono tre possibilità in base ai valori lambda:
___
$$\lambda_{1}\neq\lambda_{2} \Rightarrow \qquad y(x)=c_{1}e^{\lambda_{1}}+c_{2}e^{\lambda_{2}}$$
$$
\lambda_{1}=\lambda_{2} \Rightarrow\qquad y(x)=c_{1}e^{\lambda}+c_{2}xe^{\lambda}
$$
$$
\lambda=\alpha\pm i\beta\Rightarrow\qquad y(x)=c_{1}e^{\alpha x}sin(\beta x)+c_{2}e^{\alpha x}cos(\beta x)
$$
# Proprietà
#### Esponenziali
	$e^{x}\cdot e^{y}=e^{x+y}$ 

**Solo con tutte le x** confermate come **positive**:
- $(3x^{2}+1)^{2}=(e^{x}+4)^{2}\qquad\Rightarrow\qquad 3x^{2}+1=e^{x}+4$

#### Logaritmi
$$ log_{a}(\frac{b}{c})=log_{a}(b) - log_{a}(c)\qquad\qquad x=e^{log(x)}$$
#### Radici 
$$
\sqrt[n]{a}\sqrt[n]{b}=\sqrt[n]{ab}\qquad\qquad\sqrt[n]{\sqrt[m]{a}}=\sqrt[n\cdot m]{a}
$$
#### Seni e coseni
x | sin(x) | cos(x)
:--:|:--:|:--:
0|0|1
π/2|1|0
π|0|-1
3π/2|-1|0

**proprietà fondamentale**: $cos^{2}x+sin^{2}x=1$
simile è quella delle iperboliche: $cosh^{2}(x)-sinh^{2}(x)=1$

$$sin(-x)=-sin(x)\qquad\qquad sin(x+2\pi)=sin(x)\qquad\qquad sin(x+\frac{\pi}{2})=cos(x)$$
$$sin(2x)=2sin(x)cos(x)\qquad\qquad sinh(2x)=2sinh(x)cosh(x)$$

formule parametriche:
$$t=tan\left(\frac{x}{2}\right)\qquad\qquad sin(x)=\frac{2t}{1+t^{2}}\qquad\qquad cos(x)=\frac{1-t^{2}}{1+t^{2}}$$
