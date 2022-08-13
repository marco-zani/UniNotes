# Introduction
## Definitions
- **Cryptography** is the science and study of **secret writing**
- **Cryptanalysis** is the science and study of methods of **breaking ciphers**
- **Cryptology** is the **combination** of cryptography and cryptanalysis

Cryptography focuses on **providing confidentiality, integrity, entity and origin authentication**

- **Cryptosystem** is the combination of:
    - $E$ is an **encryption algoritm**
    - $D$ is a **decryption algoritm**
    - $M$ is a set of **plain texts**
    - $K$ is the set of **keys**
    - $C$ is the set of **ciphertexts**
		- we can define $E$ and $D$ as $E:M\times K\to C$ and $D:C\times K\to M$

> [!important]+ Kerckhoff's principle
> The algoritm should not be the secret, but the key

Based on the kerckhoff principles, the **focus shift on generating, storing and managing keys**

## Keys
The **set of all the possible keys** is called **keyspace**, and **entropy** is the randomness of a key.
Keys are defined **computationally secure**, when the **cost** required to break the cypher **excedees the data value or lifetime**

For higher effectiveness, **keys** should be **changed frequently** during a communication. This enstablishes that a **strong distribution tecnique** defines the streght of the system

Cryptography is just one part to make a system secure, the **keys must be protected by access control**

# Ancient encryption
The encryption process can be **applied on blocks** of same lenght **or stream of data**. The transformation could be through:
- **Substitution**: each element is mapped into another element
- **Transposition**: elements are rearranged

## Caesar cipher (ROTk)
It's an **algoritm based on rotation**, matematicaly:

>$E(x)=(x+k)(mod\ 26)\qquad x\in P$
>$D(x)=(x-k)(mod\ 26)\qquad x\in C$

it's one of the **easiest cipher to break**, you **find the most frequent letter** and suppose a shift of the most common letters to the one in the cypher. 

## Vigenere cipher
it's an **evolution of the Caesar cipher**, it uses the same principle but instead of rotating with the same value, it's **used a repeated key**. **Longer the key, more difficult** is to brute force the message

## Columnar cipher
The message is **written on rows of a table** with fixed column lenght defined by the key (the empty spaces are filled with nulls). In the end the **columns are scrambled** based on the key and the message gets rewritten from each column

# Modern encryption
Thanks to the new tecnologies, more complicated algoritms could be implemented, using **bits instead of characters**

## Symmetric keys
A **single key is used to encrypt and decrypt** and is share between all intended receivers. it is categorized in two types: stream cyphers and block cyphers.

### Types of ciphers
#### Stream ciphers
converts plaintext one bit at a time with a **XOR**. it's **more efficient** and it's **used for realtime applications**

#### Block ciphers
**Breaks the message in** successive **blocks** and enciphers them with the **same key**.

One detail on block cyphers they use both **substitution** and **transposition** through **S-boxes** to obtain **confusion** and **P-boxes** to obtain **diffusion**. This two properties determine **high entropy**


### Algoritms
#### Feistel
also called **DES**, it's a block cipher and follows these procedure
1. splits the blocks in two
2. applies substitution to one half using the key, and the output is xored with the other half
3. it swaps the two halves
It **uses 56-bit keys on 64-bit blocks**.

#### AES
it's the **successor to DES**. It uses the **Rijndael block cypher** and **mounts larger keys**
The encryption process is based on a series of table lookups and xor operations. 

The **encryption and decryption algoritms must be separately implemented**

# Asymmetric keys
It's the base for a **secure communication without sharing a secret key**.

It **uses one way functions**. A variant of one-way function are **trapdoor oneway functions**, which **use a key to easily invert** the original function.

During the communication are used **two different keys for encoding and decoding**. The two keys are different but **mathematically related**.
The **public key** is available to everyone, and the **private key** is kept secret.

Then the **sender encrypts** the message **with the pubblic key of the receiver**, which **decrypts using his private key**.

This mechanism can also be used as a **digital signature**. **A host encodes** something **with his private key** so that the receiver can **verify using the** sender **public key**.This  **ensures authentication, non repudiation and integrity**

## RSA
Is the most **used in key exchange, digital signature and encryption of small blocks** of data. It uses variable sized encryption blocks and a variable size key. 

It uses the mathematical concept of **easier to compute products than factorizations**

Recently has been found that around 760k keys can be computed from the public key

## DH
It's a **key agreement protocol**, it doesn't provide authentication and is **vulnerable to Man-In-The-Middle (MITM) attacks**

Uses the mathematical concept of **easier to compute exponents than discrete logarithms**

BALZO TATTICO
