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

## Updating the weights
$$
w_j=w_j+\quad\eta^{(1)}\quad\cdot\quad y_ix_{ij}\ ^{(2)}\quad\cdot\quad exp(-y_i(w\cdot x_i+b))^{(3)}\quad-\quad\eta\lambda w_j\ ^{(4)}
$$
where:
1. Is the learning rate
2. the direction to update
3. how wrong is the prediction
4. regularization

Because with $p=1$ the regularization moves towards 0, we can ignore the magnitude, so we can modify $^{(4)}$ of the L1 regularization to be:  $\eta\lambda\ sign(w_j)$

So we get:
- L1: $w_j=w_j+\eta(lossFunc-\lambda sign(w_j))$
- L2: $w_j=w_j+\eta(lossFunc-\lambda w_j)$
- L$p$: $w_j=w_j+\eta(lossFunc-\lambda cw_j^{p-1})$

# Summary
- L1 is more sparse but requires gradient descent
- L2 with some loss function can solve the problem directly
- Lp doesn't shrink weight enough