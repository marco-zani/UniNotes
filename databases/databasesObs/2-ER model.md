# Entity
an entity is a **real world object** described with a set of attributes. A collection of similar entities is a **entity set**

## weak entities
This are entities that depend to another entity. The **weak entity doesn't by itself**.

This entities are rappresented through a **thick line around the entity** and they use a **thick arrow towards the entity they depend**

A three (or more) way connecting entity is always weak

# Relations
It is a connetion between two or more entity sets. 

Different multiplicity cases:
- many to many
- many to one
- one to one
 
Wisconsin representation system:
- $\rightarrow$ :  "one"
- $\Rightarrow$ : "exactly one"
- $-$ : "many" 
- $=$ : "at least one"

## Multi-way relation

It can also be divided in multiple 2-way relations, where the resulting entity **connects to the other entities with a "exactly one"** relation

It's also important to **valuate the cardinality the relations**, which could lead to a different model

## Roles
In the case an **entity is in relation with itself**, is important to **specify the roles with labels on the line/arrow**

## Aggregation
Is used **when an entity is related to a relation more than the entities composing that relation**

We can treat the **entities and the relation as a single entity**

# Subclasses
A subentity is **represented with a isa relationship**, which **uses a triangle**. 

It **doesn't support multiple inheritance**, and **passes attributes** down the tree

# Keys
This are **unique identifiers** of an entity, are represented through an underlined attribute. They are categorized in:
- **super keys** (keys in general)
- **candidate key** (**minimal** super key)
- **primary key** (the **chosen** key)

Keys can also be composed from multiple attributes

# Schemas


# Relational model
it's the most used model thanks to the characteristic to be easier and faster than other models.

#### Definitions
a relational database is a set of relations, which are made of instances, or tables, and schemas, which specifies name of the relation, and name plus type of each column. In the tables, rows equals to the cardinality and are called tuples,the fields are called degrees

## Integrity constraint
A condition must be true for any instance of the database.

Keys can be constraint because no distinct tuples can have the same values