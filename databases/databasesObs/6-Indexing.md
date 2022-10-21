# Indexing
On datastorage, Disk can retrieve random pages at fixed cost, but must be organazied. This is called file organization, or the mothod of arranging a file of records. Indexes are the data structures that allow to find records ids.Indexes are organized through trees or hashing.
Alternatively, other file organizations can be heap files or sorted files.

An index contains a collection of data entries $x*$ with a key value of $x$. Any field of a relation can be the search key for an index.

#### B+ tree indexes
Data entries are contained in the leaves of a tree and are chained to one another. Non-leaf pages have index entries used to direct searches

#### Hash-based indexes
Better suited for equality selection, this indexes are a collection of buckets (primary pages with zero or more overflow pages) which contain data entries. It's also implemented an hashing function that retrieves the buckets where a record belongs.

## Alternatives for data entry $x$ in index
we can store the data record with key value $x$, rids of data record or list of rids of data records.

In the first alternative, the index structure is a file organization of data records. At most one index on a collection of data records can use this alternative, otherwise the data is duplicated. If data records are very large, the number of pages is high, this implies also lage size of the auxiliary information

With the other alternatives data entries are much smaller than data records, so more efficient for large data records. The third alternative is even more compact

## Clustered and unclustered indexes
An index can be categorized in primary vs secondary, and clustered vs unclustered. These second classification differs for a sorted or unsorted heap file with all the data records

  



