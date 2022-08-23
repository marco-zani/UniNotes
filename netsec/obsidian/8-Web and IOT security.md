# Introduction
**Web applications** are difficult to protect because they **are vulnerable at multiple levels**:
- Application level: SQL injection, Cross-Site-Scripting (XSS), Cross-Site Request Forgery (CSRF), broken authentication...
- Server level: Denial-Of-Service, OS exploitation...
- Network level: packet-sniffing, Man-in-the-middle, DNS attacks...
- User layer: Phishing, key-logging, malwares...

The **basic requirements** for web application are:
- **Authentication**
- **Authorization** (AC)
- **Confidentiality**
- **Integrity**
- **Non-repudiation**

And the goals are **secure browsing** and **supporting secure** web and mobile **applications**

# Web application vulnerabilities
## SQL Injection
The goal is to **exfiltrate data or manipulate it** through a **special query** that breaks the interpreter. it leads to **loss of confidentiality, integrity** and can **bypass authentication**.

The mitigation is **input sanitization**, or the **use of prepared queries** only and applying the principle of least priviledge

> [!Info]- famous case
> CardSystems (2005), exposed 43 million credit cards and put the company out of business

## Cross-site scripting (XSS)
An attacker **attaches a script** to a HTTP response, which is then **triggered when the page is loaded** by another user. This attack has two variants:
- **Reflected**: The attacker uses a **constructed URL**
- **Stored**: The bad URL is stored **inside a comment/forum** through a POST

To mitigate this attack, all **input parameters** from HTTP GET and POST must be **filtered**. It's easier if done **through a white list**

## Unvalidated Input
When an **user modifies the HTML code** to circumvent checks and other data inside the webpage. 
The solution is to **validate all parameters on server side**

## Broken Authentication
When authentication data has been broken in other sites and now the authentication **system is vulnerable to credential stuffing**. It can be mitigated by:
- enforcing the use of **stronger passwords**
- using stronger **hash algorithms and salting**
- **encrypting comunication** and **not exponing credential** (cookies)
- implement **2FA and account lockouts**

## Session management
To avoid Cross-site request forgery, session spoofing, broken authentication and other attacks, the **session identifier must be protected** with **timeouts**, **renewal**, a **good random identifier generator** and **proper cookie management**

> [!info]+ NB
> The principle of least priviledge is good damage control against all kinds of attacks

# IOT Applications
## Publish-subscribe communication
IOT uses different types of communication:
- **Many-To-Many communication** model, where information can be delivered at the same time between various consumers
- **Space/Time/Syncronization decoupling**, where the two parties do not need to follow one property of communication 
	- generally the **comunication is mediated or delivered based on their content**

In the Publish-subscriber pattern we have publishers who produce data and subscribers to the data. **When an information is produced**, the publisher **generates an event and notifies all** subscribers. This **communication is mediated through a Event Notification Service** (ENS)

**Events are structurated through a schema** composed of fields and attributes

**Events are tagged with their topic**, this is used to trigger subscription notification. This topics works as **virtual channels** between publishers and subscribers. Topics **can be organized in hierarchies** to trigger notification when new sub-topics are generated

The **ENS** can be implemented in a **centralized or distributed service**