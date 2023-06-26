By defining $x$  as all the possible instances and $y$ as all possible labels, we compose the training set $$\{\langle x_i,y_i\rangle\}^n_{i=n}$$
# Decision tree
We define a tree where each node tests one feature, where $n$ possible outcomes lead to $n$ branches, and where the leaves are predictions

The decision tree takes an input $x$ and routes it inside the tree until a leaf is reached. This is made possible by routing functions $\phi$ inside each non-terminal node

> [!info]- NB
> $Node(\phi, 1,...,n)$ with $\phi(x)\in\{1,...,n\}$, where $1,...,n$ are the branches

Each leaf holds a prediction function $h$ which could be $h\in y^x$ (classification, regression) or $h\in\Delta(x)$ (density estimation)


> [!info]+ Notation
> $Node(\phi_1,$
> 	$Node(\phi_2,$
> 		$Leaf(h_1)$,
> 		$Leaf(h_2)$
> 	),
> 	$Leaf(h_3)$
> )
