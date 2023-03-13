# Relational algebra
The manipulation and retrieval of data from a database is managed through query language. A mathematical query language i the relation algebra, an operational query language.

## basic operators

^3d5d68

The basic operations are: ^fa48a6
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

One complex operation is the **division**, which aswers questions in the format of "find ALL ... that ...",

and it follows this concept:
$A/B$ contains all $x$ tuples such that for every $y$ tuple in $B$, there is a $xy$ tuple in A, **OR** For $A/B$, compute all $x$ values that are not "disqualified" by some $y$ value in $B$

$\pi_{x}(A)\ -\ \pi_{x}((\pi_{x}(A)\times B)-A)$

## Other join types

- **Full outer join** (): shows all left and right tabels elements, with eventual null values

# usefull queries
## Find all x that do every y
Is a division, so we find all elements that do not respect the property and we  subtract them to the initial set. 
We create all possible combinations of the two fields then we subtract the existing couples, obtaining the couples who don't exist in the database. In the end we select the 

**Ex**: Find all the suppliers that supply every part. We also have a catalog that lists all parts sold by the suppliers
So make a **cross product** of suppliers and parts
$$Suppliers\times Parts$$
And then we **subtract the existing tuples**, result in all non existing combinations
$$(Suppliers\times Parts)-\pi_{supplier, part}\ Catalog$$
We lastly select the **"bad" suppliers**, and **subtract them to** the list of **all suppliers**, leaving only the "good" suppliers
$$Suppliers-\pi_{supplier}((Suppliers\times Parts)-\pi_{supplier, part}\ Catalog)$$
## find the most x 
We need to **find all the opposites** and **subtract** them from the entire set

**Ex**: FInd the most expensive part
We first search all element that do not cost more (cost less) than others
$$\sigma_{cost1<cost2}(Parts1\times Parts2)$$
So we find all elements that cost less than something, so we subtract them to the entire set
$$\pi_{cost}\ Parts-(\pi_{cost1}(\sigma_{cost1<cost2}(Parts1\times Parts2)))$$
## Find all that at least x
**Ex**: Find all suppliers who sell more than 2 parts
We **compare** two reletions as much as required by the question and **check** that the supplier is the **same** but the product is **different**
$$p(R1,Catalog)\bowtie_{R1.supplier= R2.supplier\wedge R1.part\neq R2.part}p(R2,Catalog)$$
## Find all that do exactly
Is the same as the previous, but subtract all the ones who exceeds the requirement