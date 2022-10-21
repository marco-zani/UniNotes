# Functional dependencies and normal forms
## Functional Dependencies
In a relation, it happens frequently that some information is repeated in a pattern. In this case we say a specific attribute functionally determines the values of other attributes. This constraints are called functional dependecies.

More specifically, a functional dependency is expressed as $X\to Y$ if $X,Y\subseteq U$ and if

>$t_{1}[X]=t_{2}[X] \Rightarrow t_{1}[Y]=t_{2}[Y]$

## Decomposition
Functional dependencies help identify redundancy of information. To reduce redundancy, a relation can be decomposed in two different relations, which are then reunited with a join. This can not be always be applied because some relations can lead to a lossy decomposition.
We say that a decomposition is a lossless decomposition when there is no loss of information when replacing the relation

> $<R(U),F>\ \Rightarrow\ <R_{1}(X_{1}),F_{1}>,...,<R_{n}(X_{n}),F_{n}>$
> $U=X_{1}\cup ...\cup X_{n}$

Decomposition is not always more efficient, to properly apply a decomposition it must respect this properties:
-  The decomposition must be lossless
-  redundancies must be eliminated
-  The functional dependencies of the original schemas should be preserved

This property are all respected in the schema normal form

#### Closure of a set of functional dependencies
Given a set of functional dependencies, some are logically implied. We say that a set $F$ of FD logically implies a FD $X\to Y$ if every instance that satisfies $F$ also satisfies $X\to Y$. The set of all FD implied by $F$ is the closure of $F$, denoted as $F^{+}$

To compute the closure of a set, we use the Armstrong's Axioms:
-  **Reflexive rule**: if $Y\subseteq X$, then $X\to Y$
-  **Augmentation rule**: if $X\to Y$, then $XZ\to YZ$
-  **Transitivity rule**: if $X\to Y$ and $Y\to Z$, then $X\to Z$
-  **Union rule**: if $X\to Y$ and $X\to Z$, then $X\to YZ$
-  **Decomposition rule**: if $X\to YZ$, then $X\to Y$ and $X\to Z$

#### Closure of a set of attributes
Denoted as $(X)^{+}$ is the set of all attributes that can be determined by $X$. This can be used to determine if $X$ si a superkey, a minimal key or nothing at all, if it respects the property $(X)^{+}=U.X \to U$

NB: Some dependencies are defined as trivial when $X\to Y,\ Y\subseteq X$

## Normal Form
The normal form of a relation is determined when all dependencies $X\to Y$ in $F^{+}$ are listed, with the exception of trivial dependencies ($X$ is superkey of $R$)

#### Minimal cover
A simpler version to computing the closure of $F$ is computing the minimal cover. The minimal cover follows this properties:
-  $F^{+}_{min}=F^{+}$
-  all FD in $F_{min}$ are of form $X\to A$
-  if we modify $F_{min}$, then $F^{+}_{min}\neq F^{+}$

To compute a minimal cover we follow these steps:
-  Normalize each $X\to ABC...$ to $X\to A$, $X\to B$,...
-  if $XA\to B$ and $A\in (X)^{+}$, then is redundant and can be removed
-  remove the remaining redundancies

#### Algoritm for normal form decomposition
-  Choose some FD that violates the NF conditions
-  Compute $Y=(X)^{+}/X$ and $Z=U/XY$
-  contruct two relation schemas
    -  $<R_{1}(XY),(\Pi_{XY}F^{+})_{min}>,<R_{2}(XZ),(\Pi_{XZ}F^{+})_{min}>$
-  if not in normal form, then decompose again

#### Third normal form
If when for all $\alpha\to\beta$ in $F^{+}$ at least one of the following properties holds:
-  $\alpha\to\beta$ is trivial
-  $\alpha$ is superkey of $R$
-  each attribute $A$ in $\beta-\alpha$ is contained in a candidate key for $R$

then the relation is in third normal form

#### Cover
$G$ is a cover of $F$ when $F^{+}=G^{+}$. When is composed of only elementary FDs is called canonical cover