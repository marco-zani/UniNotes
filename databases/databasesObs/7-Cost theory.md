# Cost Teory
Definitions:
-  Page: Is the size of one unit inside a hard drive. It's denoted with $p$
-  Record size: is the size of a tuple, denoted with $t_{R}$
-  Pages of relations: is the number of pages occupied by the records of a single relation. it's denoted with $P_{R}$
-  Cardinality of a relation: is the number of records of a single cardinality, is denoted with $|R|$
-  Cardinality of an attribute: is the number of distinct values inside an attribute. Is denoted with $R.A$

This definitions can be used to determin other data

> # Records of $R$ per page:
>  $\lfloor \frac{P}{t_{R}}\rfloor = \lfloor \frac{PageSize}{t_{TupleSize}}\rfloor$

> Size of R:
>  $\lceil{\frac{|R|}{\lfloor\frac{P}{t_{R}}\rfloor}}\rceil \times p = \lceil{\frac{\# Tuples}{\# TuplesPerPage}}\rceil \times p$

## Cost
Every action of I/O on the database requires time, by definitiono we will say that an action of writing and reading will cost 1. The other tipes of action are:

#### Scan
Is the operation of reading a relation, his cost is equal to the pages of a relation

#### Sorting
The cost of sorting the data depends on the number of memory buffers that the database can use. If only 3 buffers are avaiable the cost is equal to:

> $2\times N\times (\lceil log_{2}N\rceil+1)$

where $N$ is the number of pages that a relation occupies.
In case more than 3 buffers are avaiable then the cost is

> $2\times N\times (\lceil log_{B-1}\lceil\frac{N}{B}\rceil\rceil+1)$

where $B$ is the number of buffers avaiable

#### Index lookup
the cost of using an index is denoted with $L$, and is equal to 1.2 in a hash index, meanwhile, for a B-tree the cost equals to $log_{s}|R.A|$, where $s$ equals to the maximum amount of children a node can have.

The retrieval of unclustered data equals to $L + |R_{A=x}|$, meanwhile the retrieval of clustered data is

> $L + \frac{|R_{A=x}|}{\lfloor\frac{P}{t_{R}}\rfloor}$ or $L + \# pages\ occupied\ by\ the\ tuples$

#### Selectivity factor
This is the amount of records expected to respect a given condition. These records are denoted as $Rc$. The selectivity factor is denoted as:

> $f = \frac{|R_{A=x}|}{|R|}$

#### Update
The cost equals to the index lookup plus the reading and writing of the page, or

> $L + \# pages\ with\ the\ updated\ records\times 2$

## Joins
We will use the relation $R$ and $S$

#### Nested loop join
Corresponds to the cross product, the cost equals to $P_{R}+P_{S}\times P_{R}$

#### Sort Merge Join
The cost equals to the Cost of sorting $R$ plus the cost of sorting $S$ plus $P_{R}+P_{S}$

#### Hash join
This join uses a hash map to make the action more efficient. The cost equals to $3\times(P_{R}+P_{S})$

#### Index nested loops join
This method uses the index of the second relation to make the join more efficient, if the index doesn't exist, then this method is not usable. The cost equals to:

> $P_{R}+|R|\times$(index lookup cost + cost of retrieveng the qualifying records)

The resulting formula, for unclustered indexes, is, given $\delta$ as the selectivity factor:
> $P_{R}+|R|\times(L + \delta\cdot|S|)$ 

For clustered indexes:
	$$P_{R}+|R|\times(L + \frac{\delta\cdot|S|}{\frac{P}{t_s}})$$
One important details are joins with intermidiate result, we need to keep scanning them because they aren't neither sorted or indexed

## Query plans
A query can be converted in tree composed of relational algebra operations, which is used to compute in advance the cost of the query. Every query can generate different trees, so it's the database role to determine the most efficient. This action is called optimization.

Some operations don't need to wait for the final result, but they can use records as they arrive. This operations are called **On-the-fly** operations. Other operations don't even need to use records but only their indexes, so they are called **Index-only** operations

  
  



