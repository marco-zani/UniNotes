# Tasks
Represent the type of prediction made to solve a problem on some data. In detail is a function assigning an imput an output:
$$f:\mathcal{X}\to\mathcal{Y}\qquad \mathcal{F}_{task}\subset\mathcal{Y^X}$$
## Types of Tasks
- Classification
- Regression
- Clustering
- Density estimation (computing the probability distribution)
- Dimensionality reduction

# Types of distribution
With $x\in\mathcal{X}$ as inputs and $y\in\mathcal{Y}$ as outputs, for supervised learning 
$$p_{data}\in\Delta(\mathcal{X}\times\mathcal{Y})$$
for unsupervised learning:
$$p_{data}\in\Delta(\mathcal{X})$$
# Set types
The training set develops the model, while validation and testing sets check the model efficacy. The difference between the two is that the validation sets returns data to the model to improve himself, while the test set only checks the accuracy

# Training data

> [!info] Data generating distribution
> It's the distribution which generates the training and validation sets

The failure of a model is often associated with a bad data selection, allowing for the presence of additional correlations between data

## Hypothesis space
A model is the implementation of a function $f\in\mathcal{F}_{task}$. A set of models are the hypothesis space $\mathcal{H}\subset\mathcal{F}_{task}$ .
The Algorithm searches the solution in $\mathcal{H}$ because searching the entire $\mathcal{F}_{task}$ is computably impossible

# Errors
## Objective
Finding a model with the lowest amount of errors while trained in the hypothesis space of the training data set ($\mathcal{D}_n$):
$$f^{\star}_{\mathcal{H}}(\mathcal{D}_n)\in min\ E(f;\mathcal{D}_n)$$
## Learning algorithm
Seeks to optimize $f^{\star}_{\mathcal{H}}(\mathcal{D}_n)$. It might stumble upon local minimum and saddle points

## Generic error function
It measures the average error between the prediction and the example:
$$E(f;\mathcal{D}_n)=\frac{1}{n}\sum^n_{i=0}l(f;z_i)$$

## Error types
- Underfitting: Too simple model, plenty of errors even in training
- Overfitting: Too specific to the training set, has low errors in the training set but plenty in the validation stage
- Approximation error: Error in the choosing of the hypothesis space, is the difference between effective objective and real objective
- Irreducible error: Minimum error, is given by the variability of the data
- Generalization error: Error measured only in testing, while undertaking the model to random data
# Generalization
Act of moving from data from the hypothesis space to the entire probabilistic distribution
## Improving generalization
- avoid the minimum
- apply regularization
- inject noise
- augment the quantity of data
- average predictions made by models trained separatly
- apply data transformation
## Regularization
Adding to the error function a $\Omega(f)$ term which simplifies the function form
