# Properties
## Closure wrt union
The **union of free languages generates a free language**.

It's required to refresh the terminal to avoid name collisions
## Closure wrt concatenation
The concatenation of two word comming from free languages is a free language

## Free grammars cleanup
Given a context-free language, it exists a free language with:
- no $\epsilon$-production
- no unit production (A->B)
- no empty terminals
#### $\epsilon$-production elimination
Remove all $\epsilon$ and the non-terminals who lead to them

# Pumping Lemma
We use the pumping lemma to demonstrate that a given language is not a free language

> [!INFO]+ Chomsky normal form
> When a grammar is  composed by productions in the form of:
> $A->AB$
> $A->a$

## Operativelly
given $p$:
1. Chose a word $z\in\mathcal{L}$ longer than p
2. Show that whichever unpacking of $z$ into $uvwxy$ with $|vwx|\leq p$ and $|vx|>0$  is taken
3. find $i$ such that $uv^{i}wx^{i}y\notin\mathcal{L}$ 