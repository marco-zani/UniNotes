The public key crypto are more secure and supply high levels of integrity, confidentiality and non repudiation.
All at the cost of efficiency and the lacking of authentication. PKC is the solution to this cons.

# Digital signature
Some data that vouches the origin and integrity of a message, it uses the private key to "sign" the message so that the recipient can use the public key of the sender to verify the origin. This system used hash fucntion to enable the signature, but today hash functions are considered deprecated, plus this method still doesn't guarantee the real identity of the user

# Public Key infrastructure
The main requirements on the public key are to be bound on the identity of the party controlling the private key and that this bound is still valid. These two requirements can be satisfied via PKI.

The initial proposal to bound public keys and identities were bulletin boards. In IoT the public key were hardcoded in the software and in internet applications is widely spread the use of digital certificates signed by a Trusted Third Party (TTP)

The PKI binds the entity to the public key through a process of registration and issuance by a Certificate Authority (CA). Then is the Registration Authority that assures a valid and correct registration. The last component of the PKI is the Validation Authority who provides informations of the entity on behalf of the CA

## Digital Certificates
This certificates bind a public key and a person/service/hardware component/... and it contains the issuer, the subject (or user), the public key and the digital signature of the issuer.

The certificates are stored in a certificate distribution system, togheter with the Certificate Revocation List

(CRL)

Proccedure to obtain a certificate:
1. The user generates a public and private key-pair or is assigned one by some authority
2. The user requests the certificate to the CA server
3. The CA answers with the certificate including public key and digital signature
4. The user gathers the information required by the CA
5. The user send a certificate request (CSR) to the CA including public key and additional data. The request is digitally signed by the user
6. The CA verifies the identity of the user and generates a certificate binding the user identity with his public key
7. The CA issues the certificate signed by the CA to the user

## Requirements on PKI
- The TTP must be able to check a party identity
- The relying parties shall be able to check the time and general validity of the certificate
	- One way to do this is through CRLs, the other is through the OCSP, or Onlne Certificate Status Protocol
- The cryptographic software of the relying party must be updated according to the latest known vulnerabilities. The software validating certificates shall also work correctly

# SSL and TLS
The Secure Sockets Layer and his successor the Transport Layer Security are protocols developed to secure comunications between client and server

## TLS in the browser
His goal is to provide the user with identity of page origin. HTTPS (HTTP + TLS) provides the authentication of the web server and bidiractional encryption against man-in-the-middle, eavesdropping and tampering attacks while protecting privacy and integrity of exchanged data

## TLS overview
TLS is composed of two main protocols: the handshake protocoll which consist in the use of the public key criptography tto share a secret simmetric key between client and server, and the record protocol which uses the key obtained through the handshake to encrypt the communication. It also uses some additional protocols like the Change Cipher Protocol to switch to simmetric key encryption, and the Alert Protocol to report failures

The handshake protocol step by step:
1. The clients sends a hello message containing the supported cipher suite
	- A cypher suite is the set of algoritms used to secure a network connection
		- They usually include key exchange, bulk encryption and message authentication code algoritms
		- it also can include signatures and authentication algorithms to authenticate server and clint
2. The server answers with a hello message containg the chosen protocol and cipher suite, plus the session ID
3. IF the client has requested an authenticated connection, the server must send an X.509 certificate.
	- it is also the step with the server key exchange
4. the client verifies the server certificate and answers with his own certificate and his part in the client key exchange
	- the key exchange contains the pre-master key which is used to calculate the master key
	- the master key is obtainad using a pseudo random function
5. The server sends a change cipher spec, which determins the beginning of the use of the new cipher
	- it's also sent the finished, or an hash generated from the entire handshake, used to signal the completition of the algoritm
6. At this point every message is sent using the shared key

TLS provides authentication for both server and client by encrypting the clint's choosen key with the server public key, then the server uses the public key of the client to decrypt the data sent by the client in phase 4. If this exchange fails, the session terminates.
This entire communication is encrypted, this provides confidentiality within the session.
Lastly TLS uses a Message Authentication Code (MAC) to provide data integrity. The MAC uses an algorithm composed of cryptographic functions which are similar to hash functions and digital signatures but use differetn security requirements

## TLS Vulnerabilities
TLS suffers in securities issues because of logical flaws, compatibility with old cipher suites and implementation issues

RC4NOMORE: An attack born in 2017, it used guesses and observation of occurences of the cipher RC4 to authenticate as the victim

Poodle: an exploit of SSL 3.0. The attacker impersonates the server to downgrade the connection to SSL 3.0, then uses a vulnerability of the protocol to break the entire thing

Bleichenbacher attack: a vulnerability of SSL, it guesses the padding by looking at the server response. In TLS is fixed as decryption failures are hidden from the attacker

Heartbleed: find in the extension heartbeat which kept connections open. The message was composed of the data and datalenght, from which the server replayed with the same message. But if the data was shorter than the declared lenght, the server would fill the missing space with data from his memory, which could have contained sensible information

All this vulnerabilities were using the weakness of the ciphers or failures in the logic, which in successive updates were patched. Right now the best mitigations for TLS vulnerabilities are proper configuration of the TLS server

## TLS 1.3
This new version containes:
- Clean-up: removal of unsafe or unused feature, like a smaller cipher suites Poodle
- Security: application of modern techniques
- Privacy: more extensive encryption
- Performance: Faster handshake (1 RTT and 0 RTT)
- Backwards compatability

NB: forward secrecy or perfect forward secrecy is the property that session keys will not be compromised even if long-term secrets are compromised

## Ephemeral Diffie-Hellman
This variant of the normal DH from the fact that DH uses the same private key. In EDH, a temporary DH key is generated for every connection. On the other side this doesn't allow for authentication, in fact, in TLS is used Authenticated Encryption with Associated Data (AEAD) cyphers.