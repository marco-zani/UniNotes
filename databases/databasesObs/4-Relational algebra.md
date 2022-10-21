# Relational algebra
The manipulation and retrieval of data from a database is managed through query language. A mathematical query language i the relation algebra, an operational query language.

## basic operators
The basic operations are:
- **Selection** ($\sigma$): selects a subset of rows from relation
- **Projection** ($\pi$): selects the columns from relation
- **Cross-product** ($\times$): allows to combine two relations
- **Set difference** (-)
- **Union** ($\cup$)

## suboperators
there are also other sub-operators:
- **Renomination** ($\rho$, $\rightarrow$)
- **Join** ($\Join \_$) or theta join: the union on determined conditions
- **Intersection** ($A-(A-B)$)
- **Division** ($ $)
- **Equijoin**: a join on only equalities
- **Natural join**($\Join$): is a equijoin on all common fields

One complex operation is the division, which aswers questions in the format of "find ALL ... that ...",

and it follows this concept:
$A/B$ contains all $x$ tuples such that for every $y$ tuple in $B$, there is a $xy$ tuple in A, **OR** For $A/B$, compute all $x$ values that are not "disqualified" by some $y$ value in $B$

$\pi_{x}(A)\ -\ \pi_{x}((\pi_{x}(A)\times B)-A)$

## Other join types

- **Full outer join** (): shows all left and right tabels elements, with eventual null values