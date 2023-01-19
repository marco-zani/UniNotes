# Propositional logic
A proposition is a statement referred to something in the world, and can be true or false

## Symbols
in order of priority:
1. $\neg/!$ : Negazione
2. $\land$ : AND logico
3.  $\lor$ : OR logico
4. $\subset/\to$ : Implication
5. $\equiv$ : Equivalenza
 

## Concepts
- **validity**: given a proposition, then all existing combination of logic variables return a thruth
- **satisfability**: given a proposition, then it exist a combination of logic variables that returns a thruth
- **unsatisfability**: given a proposition, then all existing combination of logic variables return a falsity

**Model**: Is the set of all combinations of a proposition that return a truth


> [!info]- NB: de Morgan's laws
> $\neg(A\land B)\Rightarrow\neg A\lor\neg B$
> $\neg(A\lor B)\Rightarrow\neg A\land\neg B$


# CNF
## Conversion table

> [!Important]+  symbol $\bigotimes$
> $A \bigotimes B = A \lor B$
> $(A\land B)\bigotimes C= (A\lor C)\land(B\lor C)$
#### Affermations

| input | output |
|:-:|:-:|
| $CNF(A)$| $A$|
|$CNF(A \land B)$|$CNF(A)\land CNF(B)$|
|$CNF(A\lor B)$|$CNF(A) \bigotimes CNF(B)$|
|$CNF(A\rightarrow B)$|$CNF(\neg A) \bigotimes CNF(B)$|
|$CNF(A\equiv B)$|$CNF(A\to B) \land CNF(B\to A)$|

#### Negations

| input | output |
|:-:|:-:|
|$CNF(\neg A)$|$\neg A$|
|$CNF(\neg(A \land B))$|$CNF(\neg A) \bigotimes CNF(\neg B)$|
|$CNF(\neg(A\lor B))$|$CNF(\neg A) \land CNF(\neg B)$|
|$CNF(\neg(A\rightarrow B))$|$CNF(A) \land CNF(\neg B)$|
|$CNF(\neg(A\equiv B))$|$CNF(A\land\neg B) \bigotimes CNF(B\land\neg A)$|

# DPLL

1. substitute all parentesis with $\{\}$, and add other square brackets
2. **AND** and **OR** are substituted with commas ( **,** ) 
3. suppose that one atomic proposition is true, then in the case of **OR**s we can close the brakes

# Tableau
1. apply not to the entire proposition if searching for validity, else you're testing for validity
2. apply tableu transformation 
3. if searching for satisfability, an open branch confirms it, instead if we are searching for validity, an open branch denies it

## Tableu transformations
![[tableuDiagram.jpg]]