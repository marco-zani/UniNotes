# Functional dependencies and normal forms
## Functional Dependencies
When **specific attributes determine the values of other attributes** in a pattern. This property are called functional dependecies.

More specifically, a functional dependency is expressed as $X\to Y$ if $X,Y\subseteq U$ and if

>$t_{1}[X]=t_{2}[X] \Rightarrow t_{1}[Y]=t_{2}[Y]$

## Decomposition
A relation can be decomposed in two different relations, reuniting them when needed with a join, to reduce information redundancy

We say that a decomposition is a lossless decomposition when there is no loss of information when replacing the relation

Decomposition is not always more efficient, to properly apply a decomposition it must respect this properties:
-  The **decomposition** must be **lossless** and **preserve** original **functional dependencies**
-  redundancies must be eliminated

This property are all respected in the schema normal form

#### Closure of a set of functional dependencies
The **set of all FD implied by $F$** **is the closure** of $F$, denoted as $F^{+}$

To compute the closure of a set, we use the Armstrong's Axioms:
-  **Reflexive rule**: if $Y\subseteq X$, then $X\to Y$
-  **Augmentation rule**: if $X\to Y$, then $XZ\to YZ$
-  **Transitivity rule**: if $X\to Y$ and $Y\to Z$, then $X\to Z$
-  **Union rule**: if $X\to Y$ and $X\to Z$, then $X\to YZ$
-  **Decomposition rule**: if $X\to YZ$, then $X\to Y$ and $X\to Z$

#### Closure of a set of attributes
**Denoted as $(X)^{+}$** is the **set of all attributes that can be determined by** $X$. This can be used to determine if $X$ si a superkey, a minimal key or nothing at all, if it respects the property $(X)^{+}=U.X \to U$


> [!Info]- Trivial dependencies
> Trivial dependencies are functional dependencies that result obvious, like $XY\to X$ or $X\to X$

## Boyce-Codd Normal Form
This normal formes lists all dependencies $X\to Y$ in $F^{+}$ , where $X$ is the key. except for trivial dependencies 

#### Minimal cover
A simpler version to computing the closure of $F$ is computing the minimal cover. The minimal cover follows this properties:
-  $F^{+}_{min}=F^{+}$
-  **all FD in $\boldsymbol{F_{min}}$ are of form $\boldsymbol{X\to A}$**
-  if we modify $F_{min}$, then $F^{+}_{min}\neq F^{+}$

> [!TIP]- TLDR;
> Is like a closure with only one element on the right


To compute a minimal cover we follow these steps:
-  **Divide** $X\to ABC...$ to $X\to A$, $X\to B$,...
-  if $XA\to B$ and $A\in (X)^{+}$, then is **inner redundant** and can be **removed**
-  remove the remaining redundancies

#### Algoritm for normal form decomposition
-  **Choose a FD** that violates the NF conditions
-  Compute the **attribute closure** 
-  **divide** in two relation schemas
-  **repeat** until in normal form

#### Third normal form
If when for all $\alpha\to\beta$ in $F^{+}$ at least one of the following properties holds:
-  $\alpha\to\beta$ is trivial
-  $\alpha$ is superkey of $R$
-  each attribute $A$ in $\beta-\alpha$ is contained in a candidate key for $R$

then the relation is in third normal form

> [!TIP]- TLDR;
> All FD must be from a super key to other fields, or from other fields to a superkey
> $\star\to...$ 
> $...\to\star$


#### Cover
$G$ is a cover of $F$ when **they're equivalent** ($F^{+}=G^{+}$). When is composed of only elementary FDs is called canonical cover