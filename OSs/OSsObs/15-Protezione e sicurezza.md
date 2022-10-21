#### Proprietà di sicurezza
- Integrità 
- Confidenzialità
- Autenticazione

## Primitive di crittografia
#### Hash crittografiche
È una **funzione con output pseudorandomico di lunghezza fissa**

Le proprietà delle hash sono:
- facilità di compilazione
- impossibilità di invertire la funzione
- possibilità di collisione 

#### Crittografia a chiave simmetrica
Si usufruisce di **due funzioni, una l'inversa dell'altra**, di crittazione e decrittazione, usate per generare un testo cifrato

Esistono due tipi di cifrari: il **cifrario a flusso**, che applica un flusso di bit in XOR al messaggio, e il **cifrario a blocco**, che usa una chiave di lunghezza fissa applicata per ogni blocco che compone il messaggio

Alcun cifrari moderni sono RC4, A5/3 e AES

#### Crittografia a chiave assimetrica
Ogni utente possiede una **chiave pubblica per cifrare** e una **privata per decifrare**. Dalla chiave pubblica non si può derivare quella privata

Per la trasmissione di testo cifrato, il mittente **cripta il messaggio con la chiave pubblica del ricevente**, in modo che possa essere poi decrittata dal ricevente con la sua chiave privata 

Si può usare lo stesso meccanismo per **determinare l'autenticità del messaggio**: il mittente firma il messaggio con la sua chiave privata. Se si decodifica con la chiave pubblica, allora il mittente è colui che ha inviato il messaggio

Alcuni algoritmi d'esempio sono RSA e DSA

##### Certificato digitale
Certificano che **la chiave pubblica appartiene a una specifica entità** 

# Trusted boot
#### Bios 
Un gruppo di interfacce per l'HW indipendenti dal SO. Implementa anche il **POST** (Power-On Self Test) ceh effettua controlli sull'hardware prima di avviare il SO

#### UEFI
QUESTA PARTE NON SI CAPISCE UN CAZZO, PERCHÉ CRISPO NON USA DELLE SLIDE FATTE BENE?

#### TPM
Il Trusted Platform Module è un co-processore "trusted" **separato** sulla scheda madre con il **compito di generare e memorizzare** in sicurezza **le chiavi crittografiche**

# Cifratura del disco
Quando si cifra un disco, nello specifico si cifra il SO, lo Swap, il file system e i file temporanei e di ibernazione. La **chiave di cifratura** (SRK, Storage Root Key) viene **memorizzata nella TPM** e viene **usata per cifrare** un'altra chiave, **la FVEK** (Full Volume Encryption Key), che viene usata per cifrare l'intero volume. La FVEK è memorizzata nel volume di sistema

# Login - Autenticazione utenti
L'autenticazione è basata su uno (o più) di questi principi:
- qualcosa che l'utente sa (password)
- qualcosa che l'utente ha (smartcard)
- qualcosa che l'utente è (biometria)

L'autenticazione degli utenti si divide in due operazioni: l'**identificazione** e l'**autenticazione**. In altre parole prima si dichiara la propria identità e poi la si conferma

#### Memorizzazione delle password
Una password non può essere salvata in chiaro sul sistema. **Unix** infatti usa una funzione di **slow hash con l'aggiunta di salting**. Dopo di che ad ogni verifica della password, il dato inserito subisce lo stesso procedimento e il risultato viene confrontato con quello salvato in memoria.

In unix le password sono salvate in `/etc/passwd`

# Malware
Consiste in software malevolo con l'obiettivo di violare una o più proprietà di sicurezza. Le tipologie sono tante: Trojan, bombe logiche, backdoor, keyloggers, ransomware, virus, worms, spyware, rootkit...

#### Trojan
Sono programmi che si camuffano come leciti o si nascondono all'interno di altri programmi leciti

#### Keylogger
software che memorizza le interazioni con il dispositivo

#### Ransomware
Programma che cripta i dati del computer e chiede un risarcimento per riacederci

#### Rootkits
Installati con privilegi d'amministratore, **modificano il SO per non essere rilevabili**. Possono essere caricati al boot o girare in kernel mode.

Per capire meglio, sono in grado di offrire le solo funzioni modificate al posto di quelle installate dal SO

![[rootkit.png]]

# Vulnerabilità
##### Memoria
La memoria contiene dati e testo (variabili e codice), aggiunta allo stack e all'heap. Lo stack, che lavora in LIFO, contiene i dati temporanei, mentre l'heap contiene i dati allocati a run time

Altri dati invece sono salvati nei registri, come per esempio i puntatori ad aree di memoria:
- EBP: stack base pointer, punta all'indirizzo dello stack gestito dalla funzione attuale
- SP: stack pointer, punta alla fine dello stack
- EIP: instruction pointer, punta alla prossima funzione da eseguire

Quando una funzione viene chiamata, essa viene appesa allo stack 

#### Buffer overflow
Un **buffer** è un **blocco di memoria di dimensioni fisse** che può contenere una o più instanze di qualche informazione. Quando lo mandiamo in overflow vuol dire che i dati che cerchiamo di inserire superano le dimensioni del buffer. 

Un attacco può avvenire, dopo aver allocato un buffer lecito, allocando un buffer con l'offset necessario a sovrascrivere l'indirizzo di ritorno di un'altra funzione, permettendo di redirigire il flow delle funzioni a un codice malevolo, detto shellcode

Riuscire a individuare il return address e l'indirizzo di memoria alla prima istruzione dello shellcode può essere complesso. La soluzione allora è quello di **sovrascrivere molteplici blocchi con un eventuale indirizzo dello shellcode**, e **iniziare lo shellcode con molteplici Nop**, ossia Not operation, che slida all'istruzione successiva.
L'idea è di avere un range di blocchi dove potrebbe essere incluso il return address e avere un altro range di operazioni che mi porterebberò alla prima funzione dello shellcode, il tutto per aumentare la probabilità di far funzionare l'exploit

Una delle possibili mitigazioni è l'**ASLR**, o Address Space Layout Randomization, che **determina randomicamente l'indirizzo base dello stack e dell'heap**