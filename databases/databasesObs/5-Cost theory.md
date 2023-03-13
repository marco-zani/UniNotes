# Indexing 
# Indexing


> [!info]- heap file
> file that stores unsorted data like a queue or a stack

On datastorage, Disk can retrieve random pages at fixed cost, but must be organazied. This is called file organization, or the method of arranging a file of records. Indexes are the data structures that allow to find records. Indexes are organized through trees or hashing.
Alternatively, other file organizations can be heap files or sorted files.

An index contains a collection of data entries $x*$ with a key value of $x$. Any field of a relation can be the search key for an index.

#### B+ tree indexes
Uses a tree composed of index entries that points the path that leads to the leaves, which are called data entries and contain the pointers to the datastructures containing the data

#### Hash-based indexes
Better suited for equality selection, this indexes are a **collection of buckets** (primary pages with zero or more overflow pages) which **contain data entries based on a weak hash function**. It's also implemented an hashing function that retrieves the buckets where a record belongs.


> [!info]+ Clusterd and unclustered index
> A clustered index mantains the data records ordered based by the b+ index, meanwhile unclustered are mantained unsorted


## Alternatives for data entry $x$ in index
we can store the data record with key value $x$, rids of data record or list of rids of data records.

In the first alternative, the index structure is a file organization of data records. At most one index on a collection of data records can use this alternative, otherwise the data is duplicated. If data records are very large, the number of pages is high, this implies also lage size of the auxiliary information

With the other alternatives data entries are much smaller than data records, so more efficient for large data records. The third alternative is even more compact

## Clustered and unclustered indexes
A **clustered index**, not only keeps and ordered index, but also the **data entries are ordered**. The opposite is true for unclustered indexes  




# Cost Teory
Definitions:
-  Page: Is the size of one unit inside a hard drive. It's denoted with $p$
-  Record size: is the size of a tuple, denoted with $t_{R}$
-  Pages of relations: is the number of pages occupied by the records of a single relation. it's denoted with $P_{R}$
-  **Cardinality of a relation**: is the **number of records** of a single cardinality, is denoted with $|R|$
-  **Cardinality of an attribute**: is the number of **distinct values** inside an attribute. Is denoted with $R.A$

This definitions can be used to determin other data

> # Records of $R$ per page:
>  $\lfloor \frac{P}{t_{R}}\rfloor = \lfloor \frac{PageSize}{t_{TupleSize}}\rfloor$

> Size of R:
>  $\lceil{\frac{|R|}{\lfloor\frac{P}{t_{R}}\rfloor}}\rceil \times p = \lceil{\frac{\# Tuples}{\# TuplesPerPage}}\rceil \times p$

## Cost
Every action of I/O on the database requires time, by definitiono we will say that an **action of writing and reading will cost 1**. The other tipes of action are:

#### Scan
reading all pages of a relation

#### Sorting
The cost of sorting the data **depends on the number of memory buffers** that the database can use. If only **3 buffers** are avaiable the cost is equal to:

> $2\times N\times (\lceil log_{2}N\rceil+1)$

where $N$ is the number of pages that a relation occupies.
In case **more than 3 buffers** are avaiable then the cost is

> $2\times N\times (\lceil log_{B-1}\lceil\frac{N}{B}\rceil\rceil+1)$

where $B$ is the number of buffers avaiable

## Indexes
#### Composite index
A **B+ tree** on a composite index **can be also used when searching for the first attribute**
#### Index lookup
the cost of using an index is denoted with $L$, and is equal to 1.2 in a hash index, meanwhile, for a B-tree the cost equals to $log_{s}|R.A|$, where $s$ equals to the maximum amount of children a node can have.

The retrieval of unclustered data equals to the **cost of the lookup plus the amount of qualifying records** $L + |R_{A=x}|$, meanwhile the retrieval of **clustered data** is the cost of the **lookup plus the amount of pages occupied by the qualifying data**

> $$L + \frac{|R_{A=x}|}{\lfloor\frac{P}{t_{R}}\rfloor}\qquad or \qquad L + \# pages\ occupied\ by\ the\ tuples$$

#### Selectivity factor
This is the **amount of records expected** to respect a given condition. These records are denoted as $Rc$. The selectivity factor is denoted as **the amount of qualifying records divided by the total records**:

> $$f = \frac{|R_{A=x}|}{|R|}$$

#### Clustered indexes
The use of clustered index determines that **all satisfying records are stored one next** the other in the same pages, result in **lesser pages to return** from the disk

#### Update
An update needs to find, read and modify a record. This means that the cost equals to the index **lookup plus the reading and writing of the pages**, or

> $$L + \# pages\ with\ the\ updated\ records\times 2$$

## Joins
We will use the relation $R$ and $S$

#### Nested loop join
Corresponds to the cross product, the cost equals to the **retrieval of** the first relation **data and the writing of each tuple with all the other tuples** of the second relation
> $$P_{R}+P_{S}\times P_{R}$$

#### Sort Merge Join
After sorting by the common field, the join will only require shifting one of the two relations.
The cost equals to the **Cost of sorting $R$ plus the cost of sorting $S$ plus the reading of the two relations**
>$$Sort\ R+Sort\ S+ P_{R}+P_{S}$$

#### Hash join
This join uses a hash map to make the action more efficient, we will use an oversimplified version. The cost equals to the **reading of the two relation plus twice the sum of the cardinality** of the two relations 
>$$P_{R}+P_{S}+ 2\cdot(|S|+|R|)$$

#### Index nested loops join
This method **uses the index of the second relation** to make the join more efficient, if the index doesn't exist, then this method is not usable. The cost equals to the **reading of the first relation plus the index lookup and retrieval of qualifying records** cost:

> $$P_{R}+|R|\times (L + cost\ of\ retrieveng\ the\ qualifying\ records)$$

So, for **unclustered indexes**, is the **selectivity factor times the cardinality** of the second relation. Given $\delta$ as the selectivity factor:
> $$P_{R}+|R|\times(L + \delta\cdot|S|)$$ 

For **clustered indexes** we **divide for the amount of tuples in a page**:
	$$P_{R}+|R|\times(L + \frac{\delta\cdot|S|}{\frac{P}{t_s}})$$
One important details are **joins with intermidiate result**, **we need to scan  them** because they aren't neither sorted or indexed

## Query plans
They are trees of algebra operation used for calculating the more optimal query execution

Some operations don't need to wait for the final result, but they can use records as they arrive. This operations are called **On-the-fly** operations and they cost zero. An **example** are **projection without duplicate elimination**. Other operations don't even need to use records but only their indexes, so they are called **Index-only** operations

# Formulary
````col
```col-md
flexGrow=1
===
**Sorting with buffer of 3**
>$$2\cdot N\cdot (\lceil log_2\ N \rceil +1)$$

**Selectivity factor**
> $$\delta = \frac{|R_{A=x}|}{|R|}$$

**Update**
$$L + 2\cdot\frac{|R|\cdot\delta}{\frac{p}{t_R}}$$
```
```col-md
flexGrow=1
===
**Sorting with buffer of $B$**
>$$2\cdot N\cdot (\lceil log_{B-1}\ \lceil \frac{N}{B}\rceil \rceil +1)$$

**Index lookup**
> $$L + \frac{|R_{A=x}|}{\lfloor\frac{P}{t_{R}}\rfloor}$$
```
````
```col-md
flexGrow=1
===
**Sort merge join**
>$$\left(2\cdot |R|\cdot (\lceil log_{B-1}\ \lceil \frac{|R|}{B}\rceil \rceil +1)\right)+\left(2\cdot |S|\cdot (\lceil log_{B-1}\ \lceil \frac{|S|}{B}\rceil \rceil +1)\right)+ P_{R}+P_{S}$$
```

````col
```col-md
flexGrow=1
===
**Nested loop join**
> $$P_{R}+P_{S}\times P_{R}$$

**clustered index nested loops join**
>$$P_{R}+|R|\times(L + \frac{\delta\cdot|S|}{\frac{P}{t_s}})$$
```
```col-md
flexGrow=1
===
**Hash join** 
>$$P_{R}+P_{S}+ 2\cdot(|S|+|R|)$$

**unclustered index nested loops join**
> $$P_{R}+|R|\times(L + \delta\cdot|S|)$$

```
````
 
 
