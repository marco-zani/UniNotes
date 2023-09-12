# Assumptions
Some algorithms make strong assumptions on the data in order to work or to have faster training
## Bias
Is the measurement of how strong the assumptions in a model are

# Linear models
Model based on the assumption that a line (or hyperplane) separates the classes


## Line definition
We define each coordinate as the couple of weight $w$ and example coordinate $f$. Given the weight of all dimensions, when can build the weights vector (which is perpendicular to the line or hyperplane) and the line function: 
$$0=b+\sum^n_{i=1}w_if_i$$

By inserting $f_n$ we can determine if the object is part of a classification if the result is positive.

**A model learns by modifying the $w_i$ which moves the result away from the correct prediction** 

One example is perceptron

## Online learning algorithm
Uses a stream of single data points to develop and update a linear model. With each new data point, we check if the model labels it correctly, in case it's not able, we update the model

This is useful for processing moles of data