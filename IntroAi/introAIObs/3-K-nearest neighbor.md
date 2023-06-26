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
The distance between two features measured with different units is not precise, so we apply a process of standardization or normalization. In other cases we can apply scaling:
- **Normalization**: defining $\mu$ as the mean and $\sigma$ as the squared mean of distance of the elements from $\mu$ 
$$\sigma=\sqrt{\frac{\sum^n_{i=0} (x_i-\mu)}{n}}$$ $$x_{norm}=\frac{x-\mu}{\sigma}$$
- **Min-max scaling**:$$x_{morm}=\frac{x-x_{min}}{x_{max}-x_{min}}$$
# Minkowski distance
It's a generalization of the euclidean distance, with $p$ the number of dimensions:
$$D(a,b)={\sum_{k=1}^p|a_k-b_k|^r}^{\frac{1}{r}}$$
The change of $r$ determines the type of distance calculated (1 -> Manhattan, 2-> Euclidean, ...)

![[distances.png]]

## Cosine similarity
Given two vectors $d_1$ and $d_2$:
$$cos(d_1,d_2)=\frac{d_1\times d_2}{|d_1||d_2|}$$
# Decision boundaries
This are regions that contain a specific label
## Voronoi diagram
It describes areas nearest to a given point, it's determined by segments equidistant between two points

## Defining $k$
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

## Lazy and eager learner
Lazy learners are algorithms that simply store training data, meanwhile eager learning constructs a classification model. 
Lazy learners require less training but make slower predictions.
k-NN is a lazy learner

# Curse of Dimensionality
With higher dimensions, the points are more distanced, and k-NN less efficient. We need a dense data set, but the data might be not available

## K-D Tree
Another way to manage data is through K-D Trees (Decision trees), that consist in nodes who maintain a mean point, and with the left and right child, the lower and higher values of the next node. The data is then stored at the leaves


> [!Info]- Parameters
> tree structure, predictions at the leaves


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