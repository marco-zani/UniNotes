# Indexing


> [!info]- heap file
> file that stores unsorted data like a queue or a stack

On datastorage, Disk can retrieve random pages at fixed cost, but must be organazied. This is called file organization, or the mothod of arranging a file of records. Indexes are the data structures that allow to find records ids.Indexes are organized through trees or hashing.
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
An index can be categorized in primary vs secondary, and clustered vs unclustered. These second classification differs for a sorted or unsorted heap file with all the data records

  



