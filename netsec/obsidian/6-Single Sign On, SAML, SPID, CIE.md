# SSO
SSO operates inside of security domains, or applications trusting a common security token for authentication.
The basic concept is:
1.  an user access the application
2. the service provider refers for authentication with the identity provider
3. the identity provider ask the user for credential and after the user is authenticated, provides authentication evidence to the service provider
4. the service provider gives to the user an authentication token

Using this system, the credential never leave the authentication domain, but the service provider must trust the authentication domain, plus the authentication transfer must be protected

# SAML
The Security Assertion Markup Language is a common language and flow between systems that want to provide an SSO experience, and it's XML based.

SAML distinguishes two main entities: and identity provider, who authenticates the user and provides authorisation information, and the service provider, which relies on the information provided by the IsP. IdP e SP share metadata in any form and mean possible, sharing at least the entity ID and the cryptographic keys.
There are also federations, or groups of entities, which establish the initial trust among resources.

The authentication flow follows this procedure:
1.  A user tries to access an SP
2.  The user is redirected to a Discovery Service
	-  it allowes the user to choose the IdP
3.  The user goes back to the SP with the ID of the IdP
4.  The user is redirected to the IdP
5.  the Authentication is performed
6.  The user goes back to the SP with the authentication

NB: SAML can support other resources, and resources can support multiple SAML profiles. The most used is redirect

SAML is composed of the authentication context, metadata and the main content, which is it self composed of profiles, bindings, protocols and assertions.

#### Assertions
The assertion are a set of statements made by the authority, and is classified in authentication assertion (which describes the issuer, the issued, validity period,...), attribute assertion (defining specific details about the subject) and authorization assertion (defines what the subject is entitled to do)

#### Protocols
This section defines the communication and cryptographic protocols used for the exchange

#### Bindings
SAML uses a mechanism called SAML binding to transport the messages between the actors. There are various types like SAML URI, HTTP redirect, HTTP POST,...

#### Profiles
The combination of protocols, assertions and binding define a profile which creates a federation and enables federated SSO. This profiles can be Web browser SSO, Single Logout, artifact resolution...

The two types of web SSO are :

IsP initiated SSO
1.  A user is challenged to supply credentials to the IdP site
2. The user provides credentials and a local security context is created
3. The user accesses to the SP through the IdP, which triggers the SSO service to be called
4. The SSO service builds a SAML assertion
5. The browser issues an HTTP POST request to send the SAML to the SP
6. Final access is allowed or denied to the user by the SP

The opposite is a SP initiated SSO
1.  A user attempts to access a resource on the SP
2. The SP sends a redirect in response
3. The SSO service checks for a pre-existing logon security context, if missing requires the user to provide credentials
4. The user provides a valid credentials and a local security context is created
5. The IdP creates a SAML assertion
6. The browser issues an HTTP POST request to the SP
7. The access is allowed or denied to the user

## Authentication Context
It indicates how a user athenticated at an IdP. It can be required by an SP to enstablish a level of assurance (LOA)

## Metadata
A SAML metadata document describes a SAML deployment which is used to enstablish trust and interoperability. The minimum required is the entity ID, cryptographic keys and protocols endpoints (bindings and URLs). It's important to remember that the keys are both used for encryption and digital signature. In this case is required that each party knows each other in advance.

# SAML Security
Only providing assertion to enstablish trust may lead to man-in-the-middle or replay attacks. SAML fights this vulnerabilities by relieng on a Public Key infrastructure. It also uses SSL/TLS to grant authentication and confidentiality, and the use of XML Signature improves the message integrity.
Other mechanism used are expiration timers and unique identifiers for the messages

regarding privacy instead, SAML uses persisten pseudonyms and one-time identifiers between an identity and a service provider and creates a specific authentication context in which the user is allowed to use only certain operations

# National Identity Infrastructures - Spid
The Spid is based on SAML 2.0 and is managed by the AGency for Digital Italy (AgID).
The trust is achieved thorugh the intermediation of the agency, a third party guarantor, a process of accreditation of digital identity providers, attribute authorities and service providers.

All the entities that have passed the accreditation process are listed in the federation registry. For each record is stored the SAML identifier, name of the subject, type of entity, URL to the service provider's metadata and a list of qualified attributes.

## CIE
Used to store personal information, the eletronic Id Card is provided with a NFC cip with encryption  

# European Identity Infrastructure
An european service used for identification between nations of the EU. Uses various eIDAS-Nodes to connect the different country's services. The communication between a connector and a service relies on SAML

Currently EIDAS is under discussion with a focus on digital wallets, or a user controlled app that permits to select what personal information to share with a service. This gives self-sovereign identity, decentralized identifiers and verifiable credentials.
Currently the EU is developing a European Self-Sovereign Identity Framework, or ESSIF, with the use of decentralized identifiers and european blockchain services.