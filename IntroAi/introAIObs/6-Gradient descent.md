# Model-based machine learning

1. Pick a model
	- hyperplane, decision tree...
2. Pick a criterion to optimize (objective function)
3. Develop a learning algorithm

# Some notation
## Indicator function
$$1[x]=\cases{1&if\ x=True\\0&if\ x=False}$$
> [!info]- Title
## Vector notation
A **list of features** of an example will be represented with the vector $x$
$j$ will index the feature ($x_j$ is the $j°$ feature of example $x$) and $i$ as index of all examples ($x_i$ is the $i°$ example) 

> [!example]-
> $x_{ij}$ is the $j°$ feature of the $i°$ example 

#### Dot product
$$a\cdot b=\sum^m_{j=1}a_jb_j$$
# Loss functions
## 0/1 Loss function
$$\sum^n_{i=1}1[y_i(w\cdot x_i+b)\leq 0]$$
Takes in consideration the distance from the hyperplane, returning true if the prediction and the label don't agree

> [!example]- Let's reconsider the function
> $\sum1[...]$ means is the sum of all errors. $(w\cdot x_i+b) \leq 0$   defines the hyperplane used for predictions. $y_i$ is the correct label

The learning algorithm consist in minimizing the function through the manipulation of $w$. 
This turns out to be a NP-hard problem, so it's better to use other loss functions

## Convex functions
![[convex_functions.png]]

The idea is to have a differentiable function to use as an indication for the correct direction for minimization (one global minimum)

## Surrogate loss function
Their objective is to provide an upper bound to the actual loss function. 
We define the actual label as $y$ and the predicted label $y'$ 

| Name | Function |
| :---: | :---: |
| 0/1 loss | $l(y,y')=1[yy'\leq0]$|
| Hinge | $l(y,y')=max(0,1-yy')$|
| Exponential|$l(y,y')=exp(-yy')$|
| Squared loss|$l(y,y')=(y-y')^2$|

# Gradient descent

> [!Info]+ Gradient
>Is a vector with all the derivatives for each dimension. This allows to measure the direction changes


We use the gradient descent to find the minimum by following the approach:
1. pick a starting point
2. pick a dimension
3. move a small amount in the decreasing direction given by the derivative
	- $$w_j=w_j-\eta\ \frac{d}{dw_j}\ loss(w)$$ Where $\eta$ is the learning rate
	
1. repeat from step 2 until you reach the minimum

## Bit of math that I don't understand
$$w_j=w_j-\eta\ \frac{d}{dw_j}\ loss(w)$$
$$w_j=w_j+\eta\ \cdot\ \sum^n_{i=1}y_ix_{ij}\ exp(-y_i(wx_i+b))$$
$$...$$
we can summarize with $w_j=w_j+x_{ij}\ y_j\ c$ where $c=\eta\ exp(-y_i(wx_i+b))$ 

## Local minimum and Saddle issues
We can stumble upon local minimum, which stop our descent but not at the lowest point (global minimum).

Another issue are saddle points, where a curve goes downwards and another one upwards. The resulting gradient is 0, but is not at the minimum. The solution are small movements to get unstuck