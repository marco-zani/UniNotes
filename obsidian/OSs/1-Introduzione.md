Un Sistema operativo è un insieme di programmi con solo scopo di coordinare e rendere efficente e allocare risorse il livello hardware. Il sistema operativo inoltre offre efficenza e astrazione, indirettamente proporzionali

  
# Principali evoluzioni dei sistemi operativi

## 1a generazione

Primi calcolatori a valvole termoioniche con esecuzione da console, implementano la gestione delle prime periferiche e lo sviluppo dei software

  
## 2a generazione

Con i calcolatori a transistor, nasce il batching (batch = lotto), ossia il raggruppamento dei job simili. Grazie all'automatic job sequency, è il SO e non un operatore a passare da un job al successivo. Questa sequenzializzazione è gestita tramite il Job Control Language.

Per la prima volta abbiamo la sovrapposizione delle operazioni I/O e di elaborazione, per gestirle vengono implementati due meccanismi asincroni: Interrupts e DMA

Concettualmente, quando la CPU riceve un segnale di interrupt, interrompe il job che stava eseguendo e salva lo stato, effettua l'azione richiesta dal'I/O e poi riprende il suo lavoro. Questo risulta poco utile dato che sarebbe la CPU a venire continuamente interrotta, influendo sulla capacità di svolgere un job rapidamente

In alternativa all'interrupt, viene implementato un controller HW che si occupa del trasferimento I/O invece di appesantire la CPU. Questo metodo è chiamato DMA o Direct Memory Access

Per la gestione di sovrapposizioni nello stesso job, vengono usufruite le tecnologie di buffering e spooling. In particolare, il Simultaneous Peripheral Operation Online (o SPOOL), usufruisce di un disco magnetico usato come grande buffer per tutti i job. Richiede un qualche tipo di job scheduling

  
## 3a generazione

Introduzione della multiprogrammazione (sfruttamento dell'attesa I/O per l'esecuzione di un'altro job) e dei circuiti integrati. Nascono anche i primi sistemi Time sharing (o multitask/multi utente), questo però ha introdotto nuovi problemi di protezione della memoria, CPU e I/O. I meccanismi sviluppati sono l'esecuzione Dual mode (USER e SUPERVISOR/KERNEL) alle risorse I/O, dove tutte le operazioni I/O sono privilegiate e gestite dal SO, l'associazione di un registro per ogni processo (protezione della memoria) e l'accesso di ogni job alla CPU limitato da un timer

  
## 4a generazione

Nascita di nuovi tipi di SO e specializzazioni: per PC, di rete, distribuiti, mobile, embedded...



Next -> [[2-Componenti]]