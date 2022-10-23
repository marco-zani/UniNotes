# Modelling representation
## Mental representation
A mental representation is a **concept that allowes us to reason and interract with the world**

#### analogical mental representation
Mental representation perceived through the senses

#### Linguistic mental representation
Is the connection between a word and his mental concept

## Representation
The **main properties** of a representation are its abilities to **describe the world** and **present** a concept **to multiple people**.
Representation can be **analogical** (**depicting the world**) and **linguistic** (**describe the world**)

## Modeling
It's the activity towards the creation of a representation. A **linguististic representation modeling** is called **Theory**, meanwhile an **analogical** one is a **model**. 
**The pair of theory and model form a world model**:
$$M_{w}=\langle T,M_{T}\rangle$$

We can say that a **theory denotes its model**, and the **model is the semantics of the theory**:
$$T=D(M)\qquad\qquad M=S(T)$$
# Modelling mental models
## knowledge semantics
#### Sentence and fact
A **model is a set of facts**, and facts are analogical representation of a part of the world described by the model.
Instead, **senteces are representation of facts** and part of theory. 
Denotation and semantics are applied the same way to sentences and facts:
$$s=D(f)\qquad\qquad f=S(s)$$
When **a sentence denotes multiple facts**, we say that is **ambiguous** or **polysemic**. Instead, when **multiple sentences denote the same fact**, they are called **synonyms**

#### Correctness and completeness
We define **a theory** of a model **correct** only **if for all sentences there is a corresponding fact**.
We also define a **theory complete** only **if for all facts there is a corresponding sentence**

With a large amount of facts, **usually completeness is given up for correctness**

## Language semantics
A **domain** is a set of models ($D=\{M\}$) and a **language** is a set of theories ($L=\{T\}$). 
A language denotes a domain if it describes all its models, and the domain is the semantics of the language

The difference between a domain and submodel is the ability to represent something with a larger spectrum. Plus, different  languages can describe the same domain, capturing different aspects. This causes **semantic heterogeneity** 

correctness and completeness is applyied in the same way to languages and domains

## Mental model
A mental model is composed of language, domain, model and theory
Is the world which generates a mental model, which it represents back the world both analogically and linguistically.

A model can't represent exactly the world, this is called **semantic gap** and is caused by the fact that our senses aren't capable to capture the full complexity of the world

# Informal to formal
## Informal language
A **term** is the language elements which denotes a set of world entities. A **sentence** is the language element which denotes a set of world facts.
The **syntax** is the set of rules who define sentences. An **alphabet** are the primitive elements of a language
> [!warning]- Da fare
> A term or sentence is primitive if it belongs to a term
or sentence alphabet, complex otherwise. An sentence is atomic if it is the base
case of the sentence formation rules. Primitive sentences are atomic sentences
but the contrary is not true.

A syntex is defined by:
- a set of **primitive terms** called **term alphabet**
- a set of **term formation rules** 
- a set of **term to sentence formation rules**, which compose atomic sentences
- a set of primitive sentence called **sentence alphabet**
- a set of **sentence formation rules**
- a set of **sentence to term formation rules** which can construct atomic terms

A syntax uses this definition to:
- define entities via primitive terms
- denotes selected entities with complex terms
- define properties via atomic sentences
- define the thruth via primitive sentences
- compose complex desciptions with complex sentences
- build atomic term with other atomic terms

Syntaxes are also used to compose declarative sentence which descibe the world and reverse engineer languages to allow machine to understand humans

#### From syntax to informal semantics
1. we use primitive terms to define entities
2. we use complex term to describe how entities compose other entities
3. we use atomic sentences to denote facts
4. we use primitive sentences to denote facts without describing their generation
5. we use atomic sentences to describe how entities interract to build a fact

Complex sentences describe combinations of facts and can be categorized in:
- negative sentences ("...not...")
- conjunctive sentences ("...not...but...")
- disjunctive sentences ("...or...")
- implication ("...if...then...")
- equivalences ("...if and only if...")
- and many more... 

> [!info]- NB
> names denote single entities, noun phrases denote entities with specification to better identify them. Verbs denote relations and verbal phrases denote facts

#### AMBIGUITY
If a word has an ambiguos meaning, then we define the word as **polysemous**. If a language accepts polysemous words than is defined as **informal language**

## Semi-formal language
We define a syntax as **formal** if:
- the alphabet is recognizable
- the set of formation rules finite
- exists a correctness checking algorithm
A sentence generated from a formal syntax is called **formula** or **well formed formula** (**wff**)


> [!info]- NB
> an alphabet is formed by the smallest elements that compose complex elements

> [!info]- NB
> Formal rules are used for positioning the terms (alphabet, sentences...) in a way that makes sense

Semi-formal languages are still vulnerable to ambiguity, but it's less severe

## Formal language
A language $L$ is defined as formal if:
- formulas and terms are generated by a formal syntax
- The domain is formally defined. We will call it **domain of interpretation**
- The language denotes to all atomic formulas only one element of the domain, with no ambiguity
The denotation function is callded **interpretation function**


> [!warning] da finire (1.3.3-pag 5)

# Set theory
# Formal reasoning
# Using models