# Database management systems
DBMS are developed in a way to **grant data independence, integrity and security**, **efficient and concurrent access** and reduced application development time.

## Data models
A **data model** is **how we describe data**. A **schema** is the description of a particular **collection of data**.
The relational model is the most used and it bases its self on the concept of relations, and **every relation has a schema**

#### Abstraction
The **physical schema** represents the **structure of data on the disk**, the **conceptual schema** defines the **logical structure**, and a **view** is how **users** see the data.

**Schemas are defined using DDL** (Data Definition Language) and the **data is modified using DML** (Data Manipulation Language)


## Structure of DBMS
A DBMS uses a **layered structure** composed by:
- **Query Optimization** 
- **Concurrency control**
- **Recovery components**
- **Relational Operators**
- **Files and access methods**
- **Buffer management**
- **Disk space management**
All architecture **may present variations**

## ACID
ACID is the list of properties that a database must ensure. **We also need concurrency control**

#### Atomicity
Atomicity is a property caracterized by the **all-or-nothing policy**. It is applied through a log who keeps all performed actions

#### Consistency
The database must be consistent before and after the transaction

#### Isolation
multiple transactions occur independently without interference

#### Durability
THe changes of a successful transaction occurs even if the system failure occurs


  



