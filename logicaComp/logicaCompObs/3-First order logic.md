$\forall\Rightarrow$ for all occurences
$\exists\Rightarrow$ at least one occurence

$I(x)[a[x/d]]$ -> $d$ sostituisce $x$

![[FOLDiagram.jpg]]
# Quantifier expansion
$\exists x.A(x)\quad D=\{a,b\}\qquad\Rightarrow\qquad A(a)\lor A(b)$

$\forall x.A(x)\quad D=\{a,b\}\qquad\Rightarrow\qquad A(a)\land A(b)$


# PNF
|Formula|PNF|Assumption|
|:--:|:--:|:--:|
|$\neg\forall x.\phi(x)$|$\exists x.(\neg\phi(x))$||
|$\neg\exists x.\phi(x)$|$\forall x.(\neg\phi(x))$||
|$\forall x.(\phi(x))\land\psi$|$\forall x.(\phi(x)\land\psi)$|$\forall x.\top$|
|$\exists x.(\phi(x))\land\psi$|$\exists x.(\phi(x)\land\psi)$|$\exists x.\top$|
|$\forall x.(\phi(x))\lor\psi$|$\forall x.(\phi(x)\lor\psi)$|$\forall x.\top$|
|$\exists x.(\phi(x))\lor\psi$|$\exists x.(\phi(x)\lor\psi)$|$\exists x.\top$|
|$\forall x.(\phi(x))\to\psi$|$\exists x.(\phi(x)\to\psi)$|$\exists x.\top$|
|$\exists x.(\phi(x))\to\psi$|$\forall x.(\phi(x)\to\psi)$|$\forall x.\top$|
|$\psi\to\forall x.(\phi(x))$|$\forall x.(\psi\to\phi(x))$|$\forall x.\top$|
|$\psi\to\exists x.(\phi(x))$|$\exists x.(\psi\to\phi(x))$|$\exists x.\top$|

# Grounding
Formula -> PNF -> CNF -> quantifiers expansion