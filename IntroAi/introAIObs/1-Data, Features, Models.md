
> [!info]-  Learning process
>Measuring->Preprocessing->Dimensionality reduction-model learning->Model testing->Results
>
> For preprocessing we mean noise filtering, feature extraction and normalization. Dimensionality reduction instead means feature selection and projection

# Examples and features
An **example** is a single piece of **data**. An algorithm can't natively interpret an example, so we use **features** (**characteristics**) of an example. Features determine **labels**
Labels are used by the model to determine if a prediction is successful
## Classification
Learning is based on the generalization of data

## Training & test set
We use a probabilistic model of learning based on data generating distribution. Which means that both training and testing data will come from the same pool containing an higher amount of probable cases and lower improbable cases

# Supervised learning
builds a model based on labeled examples
## Classification
Uses a finite set of labels. 

> [!important]+ Math
> Given a **training set** $\mathcal{T}=\{(x_1,y_1),...,(x_n,y_n)\}$, learn a function $f$ to predict $y$ given $x$. $y$ is categorical, $x$ is multidimensional

## Regression
The label is real-valued (numeric)

$y$ is real-valued, instead of categorical

## Ranking
The label is a ranking

> [!example]- Uses
> most fitting image, user preference, query relevance


# Unsupervised learning
Given the data we provide no labels

## Clustering

> [!important]+ Math
> Given $\mathcal{T}=\{x_1,...,x_m\}$ output the **hidden structures** of the data, or **clusters**

## Anomaly detection
Part of pre-processing, needed to remove unusual or atypical data

## Dimensionality reduction
We reduce the amount of variables to obtain a more sensefull data set

# Reinforcement learning
Concept: An agent learns from the environment by interacting with it receiving rewards for performing actions
In other words: given a sequence of states and a reward for completing that sequence, learn to predict the action to take for a single state

# Additional variations
## variation in data availability
#### semi-supervised
#### active learning
## How data is made available
#### Online vs offline learning
## Model type
#### Generative vs discriminative model
#### Parametric vs non-parametric

