If we move from a binary classification to a multi-class classification, linear models need an update

# OVA & AVA
## One Vs All
We define the binary problem between one positive sample and all other negative samples, and then consider all different classification models.

This method can lead to ambiguity in the zones where either lines do no include an area

![[OVA_ambiguity.png]]

In this situation we pick the most confident classification

## All Vs All
The alternative is to compare all labels against all labels in pairs (Ex: A vs B, B vs C, A Vs C). This is also called **all pairs approach**.
The result is $K(K-1)/2$ classifiers, where $K$ is the amount of labels.
Each classification values a class as positive or negative. When a new example gets categorized with all classifications, wins the class with most scores

## OVA vs AVA
Ava has faster training, but slower test time and more inclined to errors

Still, is more suggested to use other models

# Micro and macro averaging
With multiple labels is easier to fall for data imbalance (trained too much on certain confrontations and others too little). Micro averaging consist in the more common average between all classes, but Macro average calculates the average for each class, and then averages the result

## Confusion matrix
Another solution is the use of a matrix with predicted labels as rows and real label as columns. This way, in each cell different from the diagonal we can see the amounts of errors (in percentage)