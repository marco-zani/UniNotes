# Avoid over-fitting

> [!info]- Over-fitting recap
> ![[3-K-nearest neighbor#Defining $k$]]

To accomplish this task we use a **regularizer**, and additional criteria to the loss function that introduces a bias for leaning towards certain weights
$$argmin_{w,b}\sum^n_{i=1}loss(yy')+\lambda\ regularizer(w,b)$$
# Regularizers
A good idea is to penalize huge weighs (because they bring too much change in the prediction). Some common regularizers are:
- Sum of the weights (1-norm): $r(w,b)=\sum|w_j|$
	- penalizes small values
- Sum of the squared weights (2-norm): $r(w,b)=\sqrt{\sum|w_j|^2}$
	- penalizes large values
- p-norm: $r(w,b)=\sqrt[p]{\sum|w_j|^p}=||w||^p$ 

Because regularizers are convex with $p\geq 1$, we can add them to the loss function and still use the gradient descent to find a minimum


> [!warning] prosegue a pag 33
