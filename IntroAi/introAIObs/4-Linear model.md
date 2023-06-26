Some model make strong assumptions about the data, this allowes for higher performace with fitting data or complete failure. Other models instead work with more varied data

with model assumptions or by directly knowing the model, can improve the learning time

# Bias
Is the measurement of how strong the assumptions in a model are

# Linear models
Model with a strong bias based on the assumption that a line separates the classes

> [!note]- Line definition
> Are a pair of values ($w_1,w_2$) through an origin $a$
> $a=w_1f_1+w_2f_2$ 
> In $n$ dimension:
> $0=b+\sum^n_{i=1}w_if_i$
> with $b=-a$

By inserting $f_n$ we can determine if the object is part of a classification if the result is positive.

**A model learns by modifying $w_1$ and $w_2$** 


> [!info]- Parameters
> The weights and the b value


> [!info]- Algorithm
> ```repeat until convergence (or for some # of iterations):  
>	for each training example (f1 , f2 , ..., fn, label):  
>		check if it is correct based on the current model  
>		if not correct, update all the weights:  
>			for each wi:  
>				wi = wi + fi*label  
>			b = b + label ```

One example is perceptron

## Online learning algorithm
Uses a stream of single data points to develop and update a linear model. 

> [!info]- Use cases
> Used with:
>- data streams
>- large-scale dataset
>- privacy must be preserved
