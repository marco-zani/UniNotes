# Predictive Top-Down Parsing

- first: set of terminals that can anticipate a non terminal
- follow: set of terminals that can follow a non terminal, $\$$ represents the string end

#### Example
$E\to E+T\ |\ T$
$T\to T*F\ |\ F$
$F\to (E)\ |\ id$

|element|first| follow|
|--|--|--|
|$E$|$(,id$|$\$,+,)$|
|$T$|$(,id$|$\$,+,*,)$|
|$F$|$(,id$|$\$,+,)$|
## Elimination of immediate left recursion
The rule
$$A\to A\alpha\ |\ \beta$$
with $\alpha\neq\epsilon$ and $\beta\neq A\gamma$, can be converted in:
$$\displaylines{
A\to\beta A^I \\
A^I\to\alpha A^I\ |\ \epsilon
}$$
There is also the case with multiple pipelines:
$$A\to A\alpha_n\ |\ ...\ |\ \beta_n\ |\ ...$$
becomes
$$\displaylines{
A\to\beta_nA^I\ |\ ...\\
A^I\to \alpha_nA^I\ |\ ...\ |\ \epsilon
}$$