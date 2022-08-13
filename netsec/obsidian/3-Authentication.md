# Introduction
**Passwords** are the **main** human computer **authentication system**, but **more secure and userfriendly alternatives are researched**.

In a **secure system** is used **access controll** and all relevant **events are logged**.

The current situation has found that there isn't a perfect authentication system, but a **combination** of password, OTP and other techniques is more likely to succeed

# Lessons learned
Passwords were created for protection against jokes and abuse of resources, but it was **easy to guess** passwords or to find the passwords **stored in clear**. 
To prevent this password **hashing and salting were invented**.

After a major attack (morris worm) password were **stored in a shadowfile readable only by the root user**

> [!INFO]- Morris worm
> created as an experiment for exploiting easy to guess password, due to code error it exhausted the computer resources causing a DOS


## Passwords and the web
With the internet, new issues with passwords have been discovered: 
- the **reuse of the same password** for different services
- **phishing** 
- the need to **reset forgotten passwords**

nowadays is common to **outsource the authentication process** to third party services, and smartphones increase security by using the **two factors authentication** (2FA).

# User authentication and digital identity
The authentication called **user authentication**, in this case, **by password** consist in providing an username and a password to prove your claim (who you are)

#### Bootstraping
**The process of providing a password to a new user**. It varies based on the dimension of the company/service but remains a **vulnerable operation**

## Identity proofing and enrollment
The process of identity proofing follows 3 steps:
-  **Resolution**: **collection of data**, or Personal Identifiable Information (PII), from the applicant
-  **Validation**: control of the data to check **if it is valid according to the standards**
-  **Verification**: **linkage** between claimed identity and existing user

#### Identity Assurance Levels (IAL)
They define th certainty of one user identification, and are divided in 3 levels:
- **IAL1**: all attributes are **self-asserted** by the user or should be treated as self-asserted.
- **IAL2**: requires either **remote or in-person identification**. 
- **IAL3**: is required the **verification by an authorized representative**.

#### Digital identity lifecycle
```mermaid
flowchart LR 
    n1([Enrolment])
    n2([Authentication])
    n3([Authorization])
    n4([Deregistration])
	n1-->n2
	n2-->n3
	n3-->n2 & n4
	n4-->n1
```

# Attacks and mitigations
## Bruteforcing
We can guess a password with two attack types: 
- **classic brute force**:  **tries all possible combinations** of symbols
- **dictionary**: uses a **list of commonly used passwords**.

This type of attacks **can't be prevented**, but we can **reduce the probability** to be successful. The mitigations are:
- **outdated methods**
	- change default passwords
	- forbid commonly used passwords
- **new methods**
	- limit the number of attempts
	- don't use password hints or knowledge based
	- incourage the use of **password generators** and **managers**

## Phishing
An attacker impersonates the system to trick a user into releasing sensible data. It can also use **social engineering**

## Spoofing
Password spoofing is the use of programs with **fake** login **interfaces** that **captures user and password** when a legittimate user gets bamboozled. 

The **countermeasure** is to implement **mutual authentication mechanisms** between user and OS

## Credential stuffing
Is the use of information from **compromised databases** to be applied **on other services**.

A good counter is **keeping track** if your users have been pwned and **force password reset**

## Password file protection
We could use **cryptographic protection**, **access controll**  and further **measures to slow dictionary attacks**

# Hashing and salting
The Hash is a mathematical function. **Password** usually get **stored in the form of hash**.

The characteristics of an hash function are:
- **easy computation**
- **compression**: returns an output of **fixed lenght**
- **one-way direction**
- **collision resistance**

> [!INFO]- Strong vs Weak collision resistance
> Strong collision resistance is the property to be improbable to produce 2 messages with the same hash code. This can be problematic if your storing passwords.
>
> Weak collision is when a password retrieves the same hash in the login as another one. This could lead to an exploit of the system security

The principal **algoritms** in use are **RIPEMD-160** and **SHA-256** (others have been cracked like MD4, MD5, SHA-1).

Hashing can be **broken through** the use of **dictionary or rainbowtable** (hash dictionaries) attacks.

**Salting** is the practice of **appending random values** to the end of the password before hashing. This process aims to increase the security of the hashes.

# Extensions for password based authentication
## Multi Factor Authentication
MFA **requires more than one authentication mechanisms** for certyfing an user 

> [!INFO]- Types of authentication mechanism 
>  knowledge, possession or inherence. 

The **most common** is two factor authentication (**2FA**)

## Time based one time passwords
Based on an **algoritm that processes a secret key, the unix time and a time interval** to generate the same number on the server and the host. The **generated value is then requested** by the server **for authentication**.
This methods is still **vulnerable to phishing and replay attack**, or the secret key could be stolen and used by the attacker to create new OTP

**Smartphones** are widely used in MFA, they **provide a mobile platform** to generate password codes, but they also represent vulnerabilities. They can be **subject to weak protection of text messages, SIM cloning and device theft**

## Assurance level (NIST)
1.  requires at least **single factor authentication**, provides some assurance the claimant controls the authenticator
2.  requires **two factor authentication**, provides high confidence that the claimant controls the authenticator
3.  requires **proof of possession**, providing very high confidence that the claimant controls the authenticator

## Contextual authentication
Is based on additional data regarding a login like:
- **device**
- **location**
- **time**
- **network**
**If this data differs** too much from a tipical behaviour, **additional requirements for authentication** are presented

# Outsourcing authentication
**Implementing** an efficient authentication system **can be difficult for smaller organizations**, so the solution is to **delegate to** trusted **third party** providers.

## Single Sign On 
SSO is one method the uses outsourcing. It's a mechanism that **collects your password** on the first login, **and manages successives logins**. 

This **increases the usabilty** of a system and allows the use of more complex password, **at the cost of just one password to compromise**. 
This mechanism is also an example of the **balance between convenience and security**
