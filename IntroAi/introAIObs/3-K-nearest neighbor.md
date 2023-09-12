# Basics
Turn features in numerical values and put label in a n-dimensions matrix (where n is the number of features)

> [!info] NB:
> labels are also converted in numbers, like IDs

After the population of the n-space with labels, the classification is determined by the $k$ closest elements to the example

## Computing distances
The distance between example $a$ and example $b$
$$D(a,b)=\sqrt{\sum^n_{i=1}(a_i-b_i)^2}$$
#### Distance and similary
Similarity measures how similar are two object and stays in the range $[0,1]$, meanwhile distance is how different are two objects, and uses the range $[0,+\infty)$ 

## Standardization and scaling
Standardization is the process of rendering different features more comparable by evening the standard deviation with the average.

- **Normalization**: stardardization where the average is $0$ and the standard deviation equals $1$. 
	- Defining $\mu$ as the mean and $\sigma$ as the squared mean of distance of the elements from $\mu$ 
$$\sigma=\sqrt{\frac{\sum^n_{i=0} (x_i-\mu)}{n}}$$ $$x_{norm}=\frac{x-\mu}{\sigma}$$
- **Min-max scaling**: value scaling where all data is in the range between $0$ and $1$$$x_{morm}=\frac{x-x_{min}}{x_{max}-x_{min}}$$
# Minkowski distance
It's a generalization of the formula for distance calculation, based on the value of $p$ :
$$D(a,b)={\sum_{k=1}^p|a_k-b_k|^r}^{\frac{1}{r}}$$
The change of $r$ determines the type of distance calculated (1 -> Manhattan, 2-> Euclidean, ...)

![[distances.png]]

## Cosine similarity
It's the difference between the angles composed by the two points and the positive $x$ axis. 
Given two vectors $d_1$ and $d_2$:
$$cos(d_1,d_2)=\frac{d_1\times d_2}{|d_1||d_2|}$$
# Decision boundaries
This are regions that contain a specific label
## Voronoi diagram
It's a diagram where the area is delimited by the closest point

## Defining $k$

> [!info]- Good model characteristics
> The amounts of errors are low in the training phase and stable during the passage to the validation phase


$k$, or the amount of nearest examples used for classification, can drastically change the prediction. This opens the way to under-fitting and over-fitting issues. Generally, under-fitting happens when the error value is too high in the training set, over-fitting instead leads to higher difference in errors count between training and test settings

![[over-under-fitting.png]]

> [!info]- NB:
> A larger $k$ produces smoother boundaries

Some suggestions when choosing $k$:
- 3,5 or 7
- odd number
- $k<\sqrt{n}$

## k-NN variations
#### Weighted k-NN
The weight of the closest elements is related to the distance value

## Lazy and eager learner
Lazy learners are algorithms that simply store training data, meanwhile eager learning constructs a classification model. 
Lazy learners require less training but make slower predictions.
k-NN is a lazy learner

# Curse of Dimensionality
K-NN requires that the points are close in all dimensions, this means that we need a dense data set, but the data might be not available or impossible to computate in it's entirety

## K-D Tree
It's an optimization of k-NN which consists in dividing the data plane in different region, allowing to compare less points for each new data
The division is stored inside a tree structure, with the examples stored in the leaves
# Summary
- Non parametric
- less than 20 features
- lots of training data
**Advantages:**
- fast training
- easy to program
- no optimization required
- classification can outperform more complex models
**Disadvantages:**
- Slow query time
- easily fooled by anomalies
- choosing distance measure, $k$ and dimensionality
- depends on memory, prohibitive for large data sets