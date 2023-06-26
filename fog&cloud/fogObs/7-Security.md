# Container security


# AWS and Azure 

## Azure identity management
When you register you obtain a global administrator account

Azure uses Role Based Access Control based on:
- Security principal
- role definition
- Scope


## AWS
Root account which manages admin accounts 

# Cloud security
- Zero trust
- Data life-cycle: In transit, At rest and in use
	- We must implement security services for each phase
	- Cryptographic AC for in transit and at rest
		 - Cryptographic Access Control
			- Role-Based CAC: 
			- Attribute-Based CAC:
		- CAC Advantages: Layering for enhanced security
		- CAC Drawbacks: Bigger overhead, revocation and renewal of keys, limited operations on encrypted data
		- CAC sub-services:
			- proxy
			- Reference monitor
			- 
	- Hardware based security for in use data
		- Most efficient security but single point of failure
		- Software based security is still impractical for protecting in use data
		- Trusted Execution Environment
			- Inside the CPU, allows the execution of protected programs without the possibility of observing or tampering from the outside
	- Software based security
		- Functional encryption: Applying operation directly unto encrypted data
		- Homomorphic encryption: 

# Know your enemy
## Typical enemies
- Botnet zombies
- Script kiddies
- Advanced Persistent Threats
	- as a service
	- attacks.mitre.org
## Honeypots
- Types:
	- Low interaction: scans commands but do not allow them to follow
	- medium/high interaction: Allows thing
	- pure interaction: complete machine
- the problem is criminal collaborations

