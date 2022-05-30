# Limiti notevoli
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
\frac{sin(x)}{x}=\frac{tan(x)}{x}=\frac{arcsin(x)}{x}=\frac{arctan(x)}{x}=\frac{sinh(x)}{x}=\frac{tanh(x)}{x}=1
$$
$$
	\frac{1-cos(x)}{x^{2}}=\frac{1}{2}
	\qquad\qquad
	\Bigg\{\frac{1-cos(x)}{x}=0\Bigg\}\ cursed
$$
#### Limiti notevoli esponenziali e logaritmici
$$
	\frac{ln(x+1)}{x}=1
	\qquad\qquad
	\frac{log_{a}(x+1)}{x}=\frac{1}{ln(a)}
$$
$$ 
	\frac{(1+x)^{a}-1}{x}=a
	\qquad\qquad
	\frac{a^{x}-1}{x}=ln(a)
	\qquad\qquad
	\frac{e^{x}-1}{x}=1
$$
# Derivate
$$
	\frac{\Delta y}{\Delta x}=\frac{f(x_{0}+h)-f(x_{0})}{h}
$$

#### Derivate fondamentali
$$
	f(x)=constante \qquad\Rightarrow\qquad f^{I}(x)=0
$$
$$ 
	f(x)=x^{a} \qquad\Rightarrow\qquad f^{I}(x)=ax^{a-1}
$$
$$ 
	f(x)=a^{x} \qquad\Rightarrow\qquad f^{I}(x)=a^{x}ln(a)
$$
$$ 
	f(x)=e^{x} \qquad\Rightarrow\qquad f^{I}(x)=e^{x}
$$
$$ 
	f(x)= log_{a}(x) \qquad\Rightarrow\qquad f^{I}(x)=\frac{1}{x\ ln(a)}
$$
$$ 
	f(x)=ln(x) \qquad\Rightarrow\qquad f^{I}(x)=\frac{1}{x}
$$
$$ 
	f(x)=|x| \qquad\Rightarrow\qquad f^{I}(x)=\frac{|x|}{x}
$$
$$ 
	f(x)=sin(x) \qquad\Rightarrow\qquad f^{I}(x)=cos(x)
$$
$$ 
	f(x)=cos(x) \qquad\Rightarrow\qquad f^{I}(x)=-sin(x)
$$
$$ 
	f(x)=tan(x) \qquad\Rightarrow\qquad f^{I}(x)=\frac{1}{cos^{2}(x)}
$$
$$ 
	f(x)=cot(x) \qquad\Rightarrow\qquad f^{I}(x)=-\frac{1}{sin^{2}(x)}
$$
$$ 
	f(x)=arcsin(x) \qquad\Rightarrow\qquad f^{I}(x)=\frac{1}{\sqrt{1-x^{2}}}
$$
$$ 
	f(x)=arccos(x) \qquad\Rightarrow\qquad f^{I}(x)=-\frac{1}{\sqrt{1-x^{2}}}
$$
$$ 
	f(x)=arctan(x) \qquad\Rightarrow\qquad f^{I}(x)=\frac{1}{1+x^{2}}
$$
$$ 
	f(x)=arccot(x) \qquad\Rightarrow\qquad f^{I}(x)=-\frac{1}{1+x^{2}}
$$
$$ 
	f(x)=sinh(x) \qquad\Rightarrow\qquad f^{I}(x)=cosh(x)
$$
$$ 
	f(x)=cosh(x) \qquad\Rightarrow\qquad f^{I}(x)=sinh(x)
$$

#### Regole di derivazione
$$
(f\pm g)^{I} = f^{I} + g^{I}\qquad (c\cdot f)^{I}=c\cdot f^{I}
$$
$$
(f\cdot g)^{I}=f^{I}\cdot g+g^{I}\cdot f\qquad (\frac{f}{g})^{I}=\frac{f^{I}g-g^{I}f}{g^{2}}
$$
Funzione composta
$$
(g(f))^{I}=g^{I}(f)\cdot f^{I}\qquad (h(g(f)))^{I}=h^{I}(g(f))\cdot g^{I}(f)\cdot f^{I}
$$
#### Derivata della funzione inversa
$$
	(f^{-1})^{I}(y_{0})=\frac{1}{f^{I}(x_{0})}=\frac{1}{f^{I}(f^{-1}(y_{0}))}
$$
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
$$ 
	arctan(x)=\sum^{\infty}_{n=0}(-1)^{n}\frac{x^{2n+1}}{2n+1}
$$
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
\sqrt{1+x}=1+\frac{x}{2}+\frac{x^{2}}{8}+\frac{x^{3}}{16}+\frac{5}{128}x^{4}+\cdot\cdot\cdot
$$
___
$$
\sqrt[3]{1+x}=1+\frac{x}{3}-\frac{x^{2}}{9}+\frac{5}{81}x^{3}-\frac{10}{243}x^{4}+\cdot\cdot\cdot
$$
___
$$
	sin(x)=x-\frac{x^{3}}{6}+\frac{x^{5}}{120}
$$
___
$$
	cos(x)=1-\frac{x^{2}}{2}+\frac{x^{4}}{24}
$$
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
f(x)g(x)=[P_{n}(x)+o(x^{n})]\cdot[Q_{n}(x)+o(x^{n})]
$$
$$
f(g(x))=P_{n}(q_{n}(x))
$$

# integrali
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



# Proprietà
#### Logaritmi
$$ log_{a}(\frac{b}{c})=log_{a}(b) - log_{a}(c) $$

#### Seni e coseni
x | sin(x) | cos(x)
:--:|:--:|:--:
0|0|1
π/2|1|0
π|0|-1
3π/2|-1|0
