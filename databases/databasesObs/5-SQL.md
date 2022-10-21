A basic SQL query is composed by relation-list, target-list and qualification and it follows this strategy:
-  Compute the cross-product of relation-list (FROM)
-  discard resulting tuples if they fail qualifications (SELECT)
-  delete attributes that are not in target-list (WHERE)


> [!infp]- Order
> FROM -> WHERE -> 


SQL is also capable of nesting queries. This is done by adding the operator IN in the WHERE section, and the nested query inside. It can be also used the operator EXISTS to let the inner query use parameters from the outer query.

parentesis

NB: "at least one" equals to **distinct**

# Operators LIKE and AS
LIKE is used in string matching, it uses % to represent multiple characters and _ just for one. To generate new name fields is also used the operator AS

fast renomination like **FROM table t** is using what are called range variables

To compare a field with a set of values is used **[operation] ANY/ALL(query)**. You can also check if a tuple is inside another query with **WHERE x IN/EXISTS**

# UNION and INTERSECT
UNION can be used to unite two compatible sets of tuples, meanwhile INTERSECT computes the intersection between the tuples

NB: **UNIQUE** is used for "exactly one"

# IN
Is an operator who allowes to check if a tuple is IN another set of tuples

# Agregate Operators
SQL offers various extentions to relational algebra, such as COUNT, SUM, AVG, MAX and MIN

NB: **HAVING** allowes to **add other constraints on the grouping operators**, it can be completed with **EVERY**

# Limitations
it can be used, during the table creation, the operator **CONSTRAINTS/CHECK** to apply constraints when adding data to a table. To manage constraints that work between table is used **CREATE ASSERTION...**

Also **TRIGGER** can be created

# Deductive Databases
TO apply recursevly

> [!warning]- finire
