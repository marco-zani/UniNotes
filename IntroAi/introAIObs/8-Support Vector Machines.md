## Large margin classifiers
Using a linear model, we define as margin the distance between the two closest elements of the different labels and the line

This closest points are defined as **support vectors**

> [!info]- NB: cardinality
> for $n$ dimensions we have at least $n+1$ support vectors

## Measuring the margin
The distance is equivalent to $$\frac{w\cdot x_i+b}{||w||}=\frac{1}{||w||}$$

## Maximizing the margin
The objective is to select the hyperplane with the larges margin with correctly classified points. We can write it as: $$max_{w,b}\ margin(w,b)$$
$$max_{w,b}\frac{1}{||w||}=min_{w,b}||w||$$
In short we need to minimize the norm of the weights. They must also be subject to $y_i(w\cdot x_i+b)\geq 1\ \forall i$ 

# Soft margin classification
For avoiding exceptions, we can add slack variables that allows this type of data to be ignored when calculating the margin:
$$min_{w,b}\quad||w||^2+C\sum_i\varsigma_i$$
subject to:$$y_i(w\cdot x_i+b)\geq1-\varsigma_i\qquad \forall i,\ \varsigma_i\geq 0$$

> [!info]+ Value of $C$
> A small $C$ allows to ignore constraints, which leads to large margins, meanwhile a large $C$ leads to a narrower margin. With $C=\infty$ we enforce all constraints, leading to an hard margin

#### Value of the slack variable
$$\varsigma_i\begin{cases}0&&y_i(w\cdot x_i+b)\geq1&(correctly\ classified)\\1-y_i(w\cdot x_i+b)&& y_i(w\cdot x_i+b)<1&(incorrectly\ classified) \end{cases}$$
Which leads to $\varsigma_i=max(0,1-yy')$ where $yy' = y_i(w\cdot x_i +b)$ 

We can apply the form of loss functions to the hinge loss:
- Hinge: $l(y,y')=max(0,1-yy')$
- Squared: $(l(y,y')=(y-y')^2)$
- 0/1 : $l(y,y')=1[yy'\leq0]$


# Non linearly separable data
## Dual problem
Our optimization problem is $min_{w,b}||w||^2$ subjected to $yy'\geq1\ \forall i$, also referred as primal problem. 
One solution is applying a Lagrange multiplier $\alpha_i$ to each inequality constraint

$$max \sum_i \alpha_i-\frac{1}{2}\sum_i\sum_j\alpha_i\alpha_jy_iy_jx_i^Tx_j\qquad such\ that\qquad \sum_i\alpha_iy_i=0 $$
#### Solution
Given the Lagrange multipliers, the solution to the primal is $$w=\sum_i\alpha_iy_ix_i$$$$b=y_k-\sum_i\alpha_iy_ix_i^Tx_k$$ In this case, when $\alpha_i$ is non zero implies that $x_i$ is a support vector, so the resulting function is: $$f(x)=\sum_i\alpha_iy_ix_i^Tx+b$$ where $x_i$ is the support vector and $x$ is the test point

## Non linear SVM
In some cases data is not easily separable, so is useful to introduce a Higher-dimensional space using the Kernel trick

#### Kernel trick
A linear classifiers works with the two vectors $K(x_i,x_j)=x_i^Tx_j$. We could use a transformation $\Phi:x\to\phi(x)$ to obtain $K(x_i,x_j)=\phi(x_i)^T\phi(x_j)$. 

A kernel function implicitly maps data without needing to compute$\phi(x)$ 


> [!warning] slide 57
