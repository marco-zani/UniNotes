# Components
Generative grammar is composed of four parts:
- The **Vocabulary** $V$ which contains symbols
- The **Terminals** $T$ which are a subtype of vocabulary symbols
- A **Start symbol** $S$: used for obtaining a new string
- A **Set of productions** $P$: rules for deducing strings

## Language
We define as **language** the set of **words** that can be **obtained using a given grammar**. We can also represent a language in **mathematical form**: $\{a^{n}b^{n}\quad|\quad n>0\}$

Each rewriting is called **derivation step**

## Notations
- **non-terminals** are written in **capital letters**
- $\epsilon$ is the empty word
- **\* means zero or more repetitions** in the base set
- **+ means one or more repetitions**

# Context-free languages
A **context-free grammar** uses production rules following the form of:
> **single non-terminal** $\rightarrow$ **string of terminal and/or non terminal**

A context-free grammar develops a context-free language

## Derivations
#### Canonical derivation
Where **every derivation** step replaces the **rightmost or leftmost** non-terminal

#### Derivation tree
Trees that use the start symbol as root, and terminals as leaves. The final word is called frontier of the tree

## Ambiguity
A grammar is ambiguos if the resulting language can be generated with two canonical derivations