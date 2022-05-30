# Relazione tra processi
I processi si dividono tra **indipendenti** e **cooperanti**, in base alla loro capacità (o meno)
di influenzare e/o condividere dati con altri processi. Un processo cooperante può fornire inoltre modularità e accelerazione del calcolo. 

La comunicazione fra processi può essere fornita via **messaggi** o **condivisione della memoria**


# IPC-Message passing
Queste IPC offrono meccanismi per lo scambio di messaggi, nel dettaglio le funzioni **send** e **receive** che lavorano su canali di comunicazione sia fisici (memoria condivisa o bus HW) che logici

Le comunicazioni si suddividono in dirette e indirette

## Comunicazioni dirette
i processi devono chiamarsi esplicitamente in modo **simmetrico** (A chiama B) o **asimmetrico** (B trova i messaggi indirizzati a lui)

## Comunicazioni indirette
I messaggi vengono inviate a mailboxes (o **porte**) condivise tra processi. Questo necessita di operazioni aggiuntive per la creazione e eliminazione delle mailbox

Un canale di comunicazione può essere bidirezionale e associato a molteplici processi. Vale anche il contrario. 
Questo pero può generare della confusione nei mittenti e riceventi, quindi vengono implementate tre soluzioni:
- associare un canale ad un massimo di 2 processi
- limitare a un processo alla volta l'operazione receive
- delegare il compito al sistema

## Sincronizzazione
I messaggi possono essere **bloccanti** o meno, ossia che bloccano il mittente o il ricevente


# IPC-Shared memory
Un processo che vuole comunicare via memoria condivisa si deve anche occupare dell'assegnazione e rimozione dei segmenti di memoria collegati

## Pipe
Sono condotte che permettono a due processi di comunicare. Le pipe **ordinarie** sono unidirezionali e funzionano in stile produttore-consumatore. Le pipe **con nome** invece sono bidirezionali e permettono a più processi di usare la stessa pipe


Next ->[[6-Scheduling]]