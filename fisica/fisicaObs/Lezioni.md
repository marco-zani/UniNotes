# Lezione 1 - Presentazione e unità di misura
## Definizioni 
- Modelli
- dimensioni/grandezze
- trascurabilità rispetto a
- matematica
## Ordine di grandezza
$$\begin{cases}x\cdot10^y&x<\pi\\
0,x\cdot10^{y+1}&x>\pi\end{cases}$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 2 - Inizio cinetica
## Rondine
![[rondine.png]]

$$x(t)=x_i+v_x(t-t_i)$$
dove $x_i$ è il punto iniziale e $t_i$ l'istante iniziale. Calcoliamo rispetto a un punto finale:
$$x(t_f)=x_i+v_x(t_f-t_i)$$
da qui: $$v_x=\frac{x_f-x_i}{t_f-t_i}=\frac{\Delta x}{\Delta t}$$
In forma vettoriale in due dimensioni:
$$\vec{r}=\begin{bmatrix}x(t)\\y(t)\end{bmatrix}=\begin{bmatrix}x_i+v_x(t-t_i)\\y_i+v_y(t-t_i)\end{bmatrix}=\vec{r}_1+\vec{v}(t-t_i)$$
<div class="page-break" style="page-break-before: always;"></div>

## Moto rettilineo uniforme
![[moto rettilineo uniforme 1.png]]
![[velocità di risalita.png]]
Nel caso della linea tratto-punto blu, usando $y$ come indicatore di quota, si vede che la rondine risale di quota a una velocità maggiore rispetto alla linea continua

Un moto rettilineo uniforme non può esistere nella realtà a causa della sua infinità e l'essere retto
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 3 - Sistemi inerziali
## 1° principio d'inerzia
Un corpo permane nel suo stato di quiete o moto rettilineo uniforme a meno che non intervenga un agente esterno
##  2° principio d'inerzia
In un sistema inerziale (dove vale il primo principio d'inerzia), la forza che agisce su un corpo è direttamente proporzionale alla massa e accelerazione
$$\vec{F}=m\cdot \vec{a}$$
La massa inerziale è la capacità di un corpo di opporsi ad una forza

#### Accelerazione 
$$^{lim}_{\Delta t\to 0}\quad \frac{\Delta v}{\Delta t}=a$$
## Molla
![[molla.png]]
La forza esercitata dalla molla, o **forza elastica**, corrisponde a $$F_{\mathcal{el}}=-K\cdot\Delta x$$
Con $K$ come costante elastica
![[molla verticale.png]]

| $\Delta x$ | F      |
| ---------- | ------ |
| $1\ cm$    | $3\ N$ |
| $1\ cm$    | $6\ N$ |
| $3\ cm$    | $9\ N$ |
<div class="page-break" style="page-break-before: always;"></div>

## Molla e Ghiaccio
![[molla e ghiaccio 3 fasi.png]]
In questo sistema abbiamo una molla compressa che spinge per un tempo $T$ con una forza $F$ contro un blocco di ghiaccio di massa $m$, facendolo scivolare su una superficie senza attrito. Cerchiamo di individuare la velocità finale e in quanto tempo raggiunge una distanza specifica
#### Newton
$$N=kg\cdot \frac{m}{s^2}$$
<div class="page-break" style="page-break-before: always;"></div>

### Risoluzione
![[molla e ghiaccio schema base.png]]
$$v(t)=v_i+\int_{t_i}^{t^f}a\ dt=v_i+\frac{F}{m}\int_{t_i}^{t^f} dt=v_i+\frac{F}{m}(t-t_i)$$
$$s(t)=s_i+\int_i^f v(t)dt=s_i+v_i(t-t_i)+\frac{1}{2}a(t-t_i)^2$$
<div class="page-break" style="page-break-before: always;"></div>

## Moto rettilineo uniformemente accellerato
![[moto rettilineo uniformemente accellerato.png]]
In questo problema lanciamo un oggetto in aria con una velocità iniziale $v_i$, cerchiamo di individuare in quale punto viene raggiunta l'altezza massima sapendo che l'oggetto è sottoposto alla forza di gravità $g=9,8\frac{m}{s^2}$
![[moto rettilineo uniformemente accellerato schema base.png]]
$$v(t)=v_i+a(t-t_i)\qquad with \qquad a=-|a|$$
$$h(t)=h_i+v_i(t-t_i)+\frac{1}{2}a(t-t_i)^2$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 4 - Moto circolare
## Studio dei grafici
![[coefficiente angolare.png]]
La velocità nel punto $x_1$ corrisponde al coefficiente angolare, o la derivata in quel punto
$$\Delta s=\vec{s}_f-\vec{s}_i$$
Alcune strutture nel grafo non possono esistere nella realtà:
![[grafo impossibili.png]]
- ―― impossibile: sparisce
- $---$ impossibile: torna indietro nel tempo
- $-\cdot-$ impossibile: esiste in diversi punti contemporaneamente
![[inclinazione velocità.png]]
Come possiamo vedere,con $v_a>v_b$, all'aumentare della velocità, aumenta l'inclinazione della retta. Ovviamente nel caso di $0°$ corrisponde la quiete dell'oggetto, mentre se l'inclinazione è negativa, allora il verso della velocità di è invertito 

![[confronto spazio velocità accelerazione.png]]
Sappiamo che:
$$x(t)\qquad v(t)=\frac{dx}{dt}\qquad a(t)=\frac{dv}{dt}=\frac{d^2x}{dt^2}$$
<div class="page-break" style="page-break-before: always;"></div>

## Moto circolare
![[moto circolare.png]]
Nonostante l'apparenza, la velocità varia, è il suo modulo a rimanere costante
$$\vec{F}=m\cdot\frac{d\vec{v}}{dt}$$
![[moto circolare zoomato.png]]
Usando la geometria dei vettori $\Delta\vec{v}=\vec{v}_f+(-\vec{v}_i)$, è dimostrabile l'esistenza di una forza che attrae l'oggetto verso il centro, la **forza centripeta**
$$\vec{a}_c=\frac{d\vec{v}}{dt}=^{lim}_{\Delta t\to0}$$
Calcoliamo ora la velocità angolare $w$ con un periodo $T$ (il tempo necessario per compiere un giro)
$$v=\frac{C}{T}=\frac{2\pi r}{T}\qquad\Rightarrow\qquad w=\frac{2\pi}{T}\Rightarrow v=wr$$
L'accelerazione centripeta, che verge sempre verso il centro, corrisponde a
$$a_c=\frac{v^2}{r}=w^2r$$
![[moto circolare uniforme coordinate.png]]
Dato che l'angolo $\alpha=\alpha_0+wt$, possiamo confrontare la posizione, velocità e accelerazione delle singole componenti
![[moto circolare confronto posizione velocità accelerazione.png]]
<div class="page-break" style="page-break-before: always;"></div>

$$\begin{cases}x_p=r\cdot cos(wt)\\y_p=r\cdot sin(wt)\end{cases}$$
$$\begin{cases}v_{x_p}=-wr\cdot sin(wt)\\v_{y_p}=wr\cdot cos(wt)\end{cases}$$
$$\begin{cases}a_{x_p}=-w^2r\cdot cos(wt)\\a_{y_p}=-w^2r\cdot sin(wt)\end{cases}\qquad\Rightarrow\qquad\begin{cases}a_{x_p}=-w^2(x_p)\\a_{y_p}=-w^2(y_p)\end{cases}$$
Con $t=\frac{\alpha-\alpha_0}{w}$.
Usando $\vec{P}$ vettore delle posizioni di $P$, abbiamo
$$|\vec{P}|=\sqrt{x_p^2+y_p^2}=r\qquad|\vec{v}|=wr\qquad|\vec{a}|=w^2r$$
che porta a $$\vec{a}=-w^2\vec{P}$$
## Curva in strada
![[curva in strada.png]]
Con $r_c$ il raggio di curvatura, è possibile calcolarlo sapendo con quale forza veniamo spinti verso l'interno della curva $$|\vec{a}_n|=\frac{v^2}{r_c}\qquad\Rightarrow\qquad r_c=\frac{v^2}{|\vec{a}_n|}$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 5 - Pendolo
## Moto vario 
![[grafo moto vario.png]]

![[grafo direzione velocità.png]]
$$\Delta\vec{r}=\vec{r}_f-\vec{r}_i$$
$$\vec{v}=\frac{d\vec{r}}{dt}$$
La velocità è sempre tangente alla traiettoria
![[grafo accelerazione normale e tangenziale.png]]

$\vec{a}_n$ è l'accelerazione normale, mentre $\vec{a}_t$ è l'accelerazione tangenziale. $\vec{a}_t$ è tangente al punto della traiettoria individuato, mentre $\vec{a}_n$ è sempre perpendicolare a $\vec{a}_t$

È possibile individuare l'accelerazione normale sfruttando il raggio di curvatura del moto
$$a_n=\frac{v^2}{r_c}$$
## Tensione
![[schema tensione.png]]
La tensione della corda è pari e opposta alla forza alla quale è sottoposta, in questo caso la forza peso
$$\vec{T}=m\cdot -\vec{g}$$
<div class="page-break" style="page-break-before: always;"></div>

## Pendolo
![[schema pendolo.png]]
$$P_t=-P\ sin(\Theta)\qquad P_n=T=P\ cos(\Theta)$$
$$a_t=\frac{l\ d^2\Theta}{dt^2}\qquad w^2=\frac{g}{l}$$
La formula fondamentale del pendolo per piccole oscillazioni ($\Theta << 1\ rad$):
$$\frac{l\ d^2\Theta}{dt^2}+ w^2\Theta=0$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 6 - Pendolo (contd)
$$\Theta(t)=A\ sin(wt+\phi)\qquad\phi=-w\cdot t_0$$
$A$ corrisponde all'ampiezza e $\phi$ alla fase, ossia l'offset di partenza rispetto al punto d'equilibrio
$$T=2\pi\sqrt{\frac{l}{g}}$$
La formula per il periodo $T$ dimostra **l'isocronia delle piccole oscillazioni** ossia che per piccoli angoli solo $l$ e $g$ influiscono sul periodo, non $A$
## Forza di richiamo della molla
![[schema forza di richiamo della molla.png]]
$$F=\frac{d^2x}{dt^2}+\frac{Kx}{m}=0$$
<div class="page-break" style="page-break-before: always;"></div>

Da qui troviamo che il periodo della molla, ossia il tempo che ci impiega per passare da uno stato di massimo allungamento a uno di minimo:
$$T=2\pi\sqrt{\frac{m}{K}}$$
## Periodo (contd)
$$\nu=\frac{d\Theta}{dt}=A\ w\ cos(wt+\phi)$$
$$\alpha=\frac{d\nu}{dt}=-A\ w^2\ sin(wt+\phi)$$
![[schema componenti pendolo.png]]
<div class="page-break" style="page-break-before: always;"></div>

con $A=\Theta_{max}$
$$a=l\ \Theta_{max}\ sin(wt+\phi)$$
$$v_t=l\ \nu= l\ \Theta_{max}\ w\ cos(wt+\phi)$$
$$a_t=l\ \alpha=-l\ \Theta_{max}\ w^2\ sin(wt+\phi)$$
![[schema pendolo tensione e forza peso.png]]
$$T=mg\ cos(\Theta)+m\frac{v_t^2}{l}$$
Quindi, per piccole oscillazioni
$$T(t)=mg(1-\frac{\Theta_{max}^2\ sin^2(wt+\phi)}{2})\ +\ ml\ \Theta_{max}^2\ w^2\ cos(wt+\phi)$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 7 - Lavoro
## 3a legge della dinamica
Ad ogni azione che un corpo $A$ effettua su un corpo $B$, il corpo $B$ esercita una reazione sul corpo $A$
$$\vec{F}_{A\to B}=-\vec{F}_{B\to A}$$
## Slitta su lago ghiacciato
![[slitta su lago ghiacciato]]
$$A_{sl}=\frac{F}{m_{sl}}\qquad\qquad\frac{F}{m_{per}}=a_{per}$$
Partendo dal punto $0$ con velocità $0$, allora $x(t)=-\frac{1}{2}at^2$ 
## Prodotto scalare tra vettori
![[schema spostamento.png]]
$$\Delta\vec{r}=\vec{r}_f-\vec{r}_i\quad\ -_{\Delta t\to0}\to\quad d\vec{r}$$
Applicare un prodotto scalare tra vettori significa $\vec{a}\cdot\vec{b}=c$ dove $c=|\vec{a}||\vec{b}|\ cos(\Theta_{ab})$ 
## Lavoro di una forza
$$dW=|\vec{F}|\ |d\vec{r}|\ cos\Theta$$
Il lavoro viene misurato in Joules, ossia $J = N\cdot m$. Il lavoro viene misurato in base agli effetti della forza misurata. In caso il lavoro sia negativo allora si definisce lavoro resistente, invece se positivo è lavoro motore
## Scalata in montagna
![[schema montagna.png]]
Misurando il lavoro esercitato dalla forza peso durante la scalata di una montagna, otteniamo la sommatoria delle sezioni in cui c'è stato un cambio di quota. Ignoriamo le parti di piano perché in quel caso il coseno dell'angolo tra le forze si annulla
![[schema segmenti della montagna.png]]
$$W_{A\to B}=\int_A^B\vec{F}\cdot d\vec{r}$$
![[schema zoom segmento montagna.png]]
$$W_{0\to 2k}=\int_{0}^{2k}mg\ dh$$

> [!tip]+ Semplificazione
> Applicare il coseno serve solo a calcolare la forza trasposta che effettua un lavoro sull'altra forza
> $$F\ cos(\Theta)\ ds= F_t\ ds$$

<div class="page-break" style="page-break-before: always;"></div>

# Lezione 8 - Piano inclinato
## Teorema dell'energia cinetica
$$\vec{F}\ d\vec{s}=m\ \frac{d\vec{v}}{dt}\ d\vec{s}\quad\Rightarrow\quad dW=d[\frac{1}{2}\ m\ v^2]$$
Grazie a questa formula possiamo definire l'energia cinetica di un corpo come $E_K=\frac{1}{2}mv^2$, ossia il quanta energia è contenuta nello spostamento.
Il teorema dell'energia cinetica enuncia che il lavoro della forza risultante è uguale alla variazione della sua energia cinetica
$$W^{(R)}_{i\to f}=E_{K_f}-E_{K_i}$$
Due importanti osservazioni su questo teorema sono:
- Il lavoro va considerato sulla risultante, ossia la somma di tutte le forze esercitate sull'oggetto
- Il teorema vale solo nei sistemi inerziali
## Attrito radente
Una superficie perfettamente non esiste, ma presenta una serie di irregolarità che, messe e contatto con un'altra superficie, si incastrano fra di loro. La difficoltà con la quale si piegano o rompono queste regolarità definisce la costante d'attrito $\mu$, con la quale si calcola la forza d'attrito
$$F_A=\mu |\vec{N}|\hat{A}$$
![[schema irregolarità attrito.png]]
Inoltre l'attrito si può dividere in statico e dinamico. Quello statico è una forza che si oppone a quella esercitata su un oggetto, tenendolo in stato di quite, mentre quello dinamico è una forza costante che si oppone allo spostamento
![[schema forza d'attrito.png]]
$$statica\cases{\vec{F}_{A_s}=-\vec{F}\\|\vec{F}_{A_s}|=|\vec{F}_{A_s}^{max}|=\mu_s|\vec{N}|}$$
$$dinamica\cases{\vec{F}_{A_d}=-\mu_d|\vec{N}|\hat{v}}$$
## Piano inclinato 
![[schema piano inclinato.png]]
<div class="page-break" style="page-break-before: always;"></div>

Possiamo usare il teorema dell'energia cinetica per semplificare la risoluzione di questo problema. Dato che $W=\Delta E_K$ e $W=Ph$
$$mgh=\frac{1}{2}mv_f^2-\frac12mv_i^2\qquad\Rightarrow\qquad v_f=\sqrt{v_i^2+2gh}$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 9 - Forze conservative e dissipative
## Oggetto spinto su una rampa
![[schemaoggetto spinto su una rampa.png]]
![[schema del lavoro dell'attrito.png]]
$$h=\frac{L}{sin\ \Theta}$$
Il lavoro compiuto dalla forza peso a salire e scendere è nullo
$$W_p=mg\ sin\ \Theta\ [\int_L^0dx\ -\ \int_L^0dx]=0$$
![[schema del lavoro dell'attrito semplificato.png]]
Usando $W_{A_D}$ come lavoro dell'attrito a discendere e $W_{A_S}$ come lavoro a salire
$$|\vec{A}_S|=\mu d\cdot|\vec{N}|$$
$$W_A=W_{A_S}+W_{A_D}=-2\mu dmgL\ cos\ \Theta$$
## Molla e grave
![[schema molla semplificato.png]]
<div class="page-break" style="page-break-before: always;"></div>

Questo lo possiamo rivedere anche nella molla o nel grave
$$W_p=mg\Delta H\qquad\qquad W_{el}=-\frac12K\Delta x^2$$
Nello spostamento effettuato $A\to B$
$$W_p=(-mgh_f)-(-mgh_i)\qquad\qquad (-\frac12Kx^2_f)-(-\frac12Kx^2_i)$$
## Forza conservativa
Ossia **se il lavoro da $A$ ad $A$ è nullo**, qualsiasi sia il percorso:
- $W_{A\to A}[\vec{F}]=0$
- $W_{A\to B}[\vec{F}]=0$, non dipende dal percorso
- Se esiste una primitiva $W_{A\to B}=-(U(\vec{x}_B)-U(\vec{x}_A))$, dove $U$ è l'energia potenziale
Se vale una di queste allora valgono anche le altre
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 10 - Forza conservativa
![[schema confronto fra percorsi.png]]
Il riferimento non è importante, viene solo misurata la differenza di energia potenziale
$$\Delta U_{0\to B}\ -\ \Delta U_{0\to A}=\Delta U_{A\to B}$$
$$U(P)=U(0)+\Delta U_{0\to P}$$
## Teorema di conservazione dell'energia meccanica
Definendo $W^{FC}$ il lavoro delle forze conservative, $W^{FNC}$ le forze non conservative e l'energia meccanica come $E=U+E_K$
$$W_{i\to f}^{TOT}=E_{Kf}-E_{Ki}\qquad\qquad W_{i\to f}^{FC}=-(U_f-U_i)\qquad\qquad W_{i\to f}^{FNC}=E_f-E_i$$
<div class="page-break" style="page-break-before: always;"></div>

## Conservazione meccanica
Caso in cui $E_f=E_i$
![[disegno molla semplificato.png]]
![[grafo energia meccanica.png]]
![[grafo energia meccanica grave.png]]
Usando il caso del grave come esempio, possiamo semplificare i calcoli
$$\Delta E_K=\Delta U\quad\Rightarrow\quad v_f=\sqrt{2gh}$$
## Forze non conservative
Caso in cui $E_f\neq E_i$ 
![[schema macchina.png]]
Quindi $E_f=E_i+W_{i\to f}^{FNC}$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 11 - Urti
## Urti
![[schema urto.png]]

> [!info]+ Approfondiamo la formulazione generale della forza
> Considerando il moto $\vec{p}$ come $\vec{p}=m\vec{v}$, allora $$\vec{F}=\frac{d\vec{p}}{dt}$$

$$\vec{F}_{impulsiva}=\frac{\Delta\vec{p}}{\Delta t}\qquad\Rightarrow\qquad\Delta\vec{p}=\vec{F}_{imp}\ \Delta t$$
$$d\vec{p}_1=-d\vec{p}_2\qquad d[\ \vec{p}_1+\vec{p}_2\ ]=0\qquad d\vec{p}=0$$
![[schema lunghezza d'urto.png]]
$$m_1v_{f1}+m_2v_{f2}=m_1v_{i1}+m_2v_{i2}$$
## Urti elastici
Oltre alla conservazione del moto, **è conservata anche l'energia cinetica**
$$m_1v^2_{f1}+m_2v^2_{f2}=m_1v^2_{i1}+m_2v^2_{i2}$$
I gradi di libertà corrispondono a n° dimensioni  meno $1$ 
<div class="page-break" style="page-break-before: always;"></div>

## Sistemi di punti materiali
![[schema sistema di punti materiali.png]]
$$\vec{R}^{(I)}=0\qquad\Leftarrow\qquad \vec{F}_{i\to j}=-\vec{F}_{j\to i}$$
$$\vec{R}=\frac{d^2}{dt^2}\ [\ \sum_im_i\vec{x}_i\ ]$$
Possiamo perciò definire il centro di massa
$$\vec{x}_{cm}=\sum_i\frac{m_i}{m_{TOT}}\cdot\vec{x}_i\qquad\qquad\vec{v}_{cm}=\frac{d\vec{x}_{cm}}{dt}\qquad\qquad\vec{a}_{cm}=\frac{d^2\vec{x}_{cm}}{dt^2}$$
quindi
$$\vec{R}=m_{TOT}\ \vec{a}_{cm}$$

## Legge di conservazione della quantità di moto
In un sistema isolato, la quantità di moto $P_{cm}$ si conserva, ossia è costante
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 12 - Sistemi di riferimento
![[schema sistemi di riferimento.png]]
$$\vec{r}=\vec{00'}+\vec{r'}$$
Quando confrontiamo due sistemi di riferimento, ogni forza va esaminata come la forza più il vettore che descrive lo spostamento fra i due sistemi, in questo caso $\vec{00'}$.

Nel momento in cui l'accelerazione fra i due sistemi $\vec{a_0}\neq\vec{0}$, allora il sistema di riferimento non è inerziale, e non valgono le leggi della dinamica classica
<div class="page-break" style="page-break-before: always;"></div>

Da qui ci possiamo appoggiare a due oggetti che fra di loro compongono un centro di massa
$$\cases{\vec{F}_{ext}=M\vec{a}_{cm}\\\vec{r}=\vec{r}_{cm}+\vec{r'}_{cm}\\\vec{v}=\vec{v}_{cm}+\vec{v'}_{cm}\\\vec{a}=\vec{a}_{cm}+\vec{a'}_{cm}}$$
## Urti anaelastici
![[schema tre oggetti.png]]
$$x_{cm}=\frac{m_1x_1+m_2x_2}{m_1+m_2}\qquad\qquad v_{cm}=\frac{m_1v_1+m_2v_2}{m_1+m_2}$$
$$E_{K_i}=\frac12(m_1+m_2)\vec{v}_{cm}^2+E_{K_i}'\qquad\qquad E_{K_f}=\frac12(m_1+m_2)\vec{v}_{cm}^2$$
$E_{K_i}$ **sarà sempre maggiore di** $E_{K_f}$ dato che c'è una dispersione di energia nel momento in cui i due corpi collidono
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 13 - Forze apparenti
## Principio di relatività Galileiana
$$\begin{cases}\vec{x}=\vec{x}'+\vec{00'}\\\vec{v}=\vec{v}'+\vec{v_{0'}}\end{cases}$$ Questo principio viene applicato implicitamente in tutte le situazioni che usufruiscono di un sistema inerziale
## Sistemi non inerziali
$$\vec{F}=m\vec{a}\quad\xrightarrow{S\to S'}\quad\vec{F}_{ext}=m(\vec{a}'+\vec{a_{0'}})$$
$$m\vec{a}'=\vec{F}_{ext}-\vec{F}_{app}\qquad\qquad\vec{F}_{app}=\vec{F}_T=-m\vec{a_{0'}}$$
Le forze apparenti solo quelle forze che dipendono dal sistema di riferimento, che presenta un'accelerazione. 
$$tan(\Theta) = \frac{F_{app}}{F_{ext}}$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 14 - Forza di gravità
## Forze fondamentali
Le forze fondamentali sono 4:
- La forza **forte**: l'energia che tiene uniti gli atomi
- La forza **elettromagnetica**: cariche elettriche e correnti
- La forza **debole**: responsabile del decadimento nucleare
- La forza **gravitazionale**
## Forza gravitazionale
![[schema sole terra.png]]
$$\vec{F}=-G\frac{m_{g1}m_{g2}}{\vec{r}^2_{1\to2}}\hat{r}_{1\to2}$$
Questa formula risulta un template alla quale diverse altre forze si riferiscono
### Attrazione gravitazionale della terra
possiamo considerare la distanza tra un corpo sulla crosta terreste e il centro della terra come la distanza fra i due corpi, visto che il centro di gravità coincide con il centro di massa, quindi in questo caso $r_{ct}=R_t:
$$g=G\frac{m_{gt}}{R^2_t}$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 14 pt2 - Termodinamica
Teniamo in considerazione che quando trattiamo di termodinamica, andiamo a trattare sistemi di punti con un numero di entità nell'ordine del $6\times10^{23}$, ossia il numero di Avogadro $N_A$ 
## Sistema termodinamico
![[schema sistema termodinamico.png]]
<div class="page-break" style="page-break-before: always;"></div>

In questo sistema viene osservato il rapporto tra ambiente e sistema, ossia le **trasformazioni termodinamiche**. Questi sistemi di classificano in 3 categorie:
- Sistema aperto: ove avviene scambio di energia e di massa
- Sistema chiuso: ove avviene scambio di energia ma non si massa
- Sistema isolato: ove non avviene scambio di energia o massa
## Variabili termodinamiche
Si differiscono in grandezze **estensive**, ossia che riguardano l'intero sistema (massa, volume), e intensive, ossia che valgono per qualsiasi punto locale del sistema (pressione, temperatura)
## Equilibrio termidinamico
Ogni calcolo su un sistema deve essere fatto quando esso si trova in uno stato di equilibrio, ossia quando è presente:
- Equilibrio meccanico (assenza di forze)
- Equilibrio termico
- Equilibrio chimico
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 15 - Calore
## Contatto termico
Una superficie viene definita **diatermica** se è in grado di trasferire la temperatura, se no è definita **adiabatica**
## Esperimenti di joules
Gli esperimenti riguardavano l'inserimento di macchine in grado di compiere un lavoro in un contenitore d'acqua, in particolare un mulinello, un circuito elettrico, delle lastre che si sfregano e un palloncino
![[esperimenti di joules.png]]
In ognuno di questi esperimenti, a parità di temperatura iniziale e di lavoro introdotto nel sistema, la temperatura finale era sempre la stessa
Perciò la differenza di energia interna ad un sistema equivaleva al quantitativo di lavoro introdotto:
$$W=-\Delta U$$
## Calore
## Primo principio della termodinamica
la differenza di energia interna a un sistema equivale al calore meno il lavoro
$$\Delta U_{int}=Q-W$$
## Trasformazioni cicliche
![[schema cicli.png]]![[Pasted image 20240528150108.png]]
La differenza tra due spostamenti non dipende dai punti intermedi
$$dU_{int}=\delta Q-\Delta W$$
<div class="page-break" style="page-break-before: always;"></div>

## Convenzione dei segni

| Ricevuto | Dato  |
| :------: | :---: |
|  $W<0$   | $W<0$ |
|  $Q>0$   | $Q<0$ |
## Grandezze
- Capacità termica $C=[\frac{dQ}{dT}]_\gamma$ 
- Calore specifico $c_\gamma=\frac{C_\gamma}{m}$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 16 - Trasmissione del calore
## Fasi
![[schema fasi.png]]
![[schema punto triplo.png]]
Usando $\lambda$ per indicare il calore latente ($\frac EM$):
$$dQ=\lambda\ dm$$
<div class="page-break" style="page-break-before: always;"></div>

## Trasmissione del calore
### Conduzione
![[schema conduzione.png]]
Usiamo il concetto di **sorgente** per intendere una fonte potenzialmente infinita di calore
In questo caso il calore si propaga attraverso la materia
$$dQ=-K\frac{dT}{dZ}dS\ dt$$
Dove $K$ indica la conducibilità ($\frac{E}{LTt}=\frac{J}{m\ s\ K}$)
<div class="page-break" style="page-break-before: always;"></div>

### Convezione
![[schema convezione.png]]
Tipo dei liquidi, questo metodo di trasmissione è caratterizzato dal riscaldamento di una sacca di sostanza che poi si distacca e naviga nel resto
### Irraggiamento
![[schema irraggiamento.png]]
In questo caso il calore è trasferito per via di onde elettro-magnetiche
Un flusso di energia ($\frac E{L^2t}$) è descritto dalla legge di Stefan-Boltzman:
$$\epsilon=\sigma e T^4$$
dove $\sigma$ è la costante di Stefan-Boltzman e $e$ rappresenta l'emmisività

> [!info]- Costante solare
> È il quantitativo di energia erogata dal sole $$c=1,36\frac J{m^2S}$$

## Gas perfetti
Sono gas a bassa pressione, e permettono di introdurre 4 leggi:
- Gay lussac I: in una trasformazione isocora (volume costante) vale che $$p=p_0(1+\beta t)$$
- Gay lussac II: In una trasformazione isobara (pressione costante) vale che $$V=V_0(1+\alpha t)$$
- Boyle: In una trasformazione isoterma (temperatura costante) vale che $$p_iV_i=p_fV_f\qquad o\qquad pV=const$$
- Avogadro: il numero di moli di un gas equivale a $N=\frac 1{K_B}\frac{pV}T$ dove $N=6,022\times 10^{23}$, $K_B=1,38\times10^{-23}\frac JK$ e $R=\frac{pV}{nT}=8,314\frac J{K\ mol}$ 
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 17 - Teoria cinetica dei gas
## Evidenze sperimentali della teoria cinetica![[Pasted image 20240529085022.png]]
È stato possibile definire sperimentalmente che $pV=nRT$ e che l'energia interna di un gas dipende unicamente dalla sua temperatura, perciò è stato possibile definire la teoria
## Teoria cinetica dei gas
È dimostrabile che $$U=\frac32NK_BT$$ ossia $$\overline{E}_K=\frac32K_BT$$ o più generalmente $$\overline{E}_K=\frac l2K_BT$$ dove $l$ sono i gradi di libertà
<div class="page-break" style="page-break-before: always;"></div>

La teoria si basa su presupposto che, ignorando gli scontri fra molecole e considerando solo urti perfettamente elastici, era possibile usare la pressione come forza media esercitata dalle molecole sulle superfici, ma dato che la pressione dipende dalla temperatura, si può collegare l'energia cinetica media di un gas alla sua temperatura
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 18 - Trasformazioni notevoli
Richiamando $$\Delta Q=Q-W\qquad\qquad dU=\delta Q-\delta W$$
## Trasformazioni isocore
Dove $V$ è costante, ossia $dV=0$, possiamo calcolare che $$dW=0\qquad\qquad dU=dQ\qquad\qquad dQ=nc_vdT$$
Specialmente unendo le ultime due possiamo calcolare $c_v=\frac32R$ 
## Trasformazioni isobare
In questo caso le componenti costanti sono $p$ e $\frac{nRT}V$, che determina:$$dU=nc_vdT\qquad\qquad dQ=nc_pdT\qquad\qquad dW=nRdT$$
Da qui possiamo determinare la relazione di Mayer $$c_p-c_v=R$$ dove $R$ è sempre maggiore di $0$, inoltre definiamo per semplicità $\gamma=\frac{c_p}{c_v}$ 
## Trasformazioni isoterme
La componente costante è $T$, perciò $dU=0. Da qui $$dQ=dW=p\ dV\qquad\qquad Q=nRT\ ln(\frac{V_B}{V_A})$$
## Trasformazioni adiabatiche
Infine la nostra condizione è che $dU=dW$, si può dimostrare perciò che $$pV^\gamma=const$$
<div class="page-break" style="page-break-before: always;"></div>

## Tabella riassuntiva

| nome        | caratteristica | $\Delta U$ |            $dQ$            |            $dW$            |
| ----------- | :------------: | :--------: | :------------------------: | :------------------------: |
| isocore     | $\Delta V=0$   |  $nc_vdT$  |          $nc_vdT$          |            $0$             |
| isobare     | $\Delta p=0$   |  $nc_vdT$  |          $nc_pdT$          |        $nR\Delta T$        |
| isoterme    | $\Delta T=0$   |    $0$     | $nRT\ ln(\frac{V_f}{V_i})$ | $nRT\ ln(\frac{V_f}{V_i})$ |
| adiabatiche | $Q=0$          |  $nc_vdT$  |            $0$             |      $-nc_v\Delta T$       |
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 19 - Macchine termiche
## Macchine termiche
Un ciclo di trasformazioni termodinamiche, positivo, descrive una macchina termica. Nel caso il ciclo sia negativo, la macchina è denominata frigorifera
## Efficienza delle macchine
### Macchine termiche
Definiamo l'efficienza con il simbolo $\eta$ $$\eta=\frac W{Q_A}=1-\frac{|Q_C|}{|Q_A|}$$
### Macchine frigorifere
$$\eta=\frac{Q_C}{|W|}$$
### Collegamento al secondo principio della termodinamica
L'efficienza di una macchina si muove nell'intervallo $[0,1)$ dove **$1$ è irraggiungibile**
## Ciclo di Carnot
Ciclo reversibile di un gas ideale composto da questa sequenza di trasformazioni termodinamiche:
1. isoterma
2. adiabatica
3. isoterma
4. adiabatica

![[schema ciclo di carnot.png]]

$$AB\cases{\Delta U=0\\Q=nRT_2ln(\frac{V_B}{V_A})}\qquad\qquad\qquad\qquad  BC\cases{Q=0\\\Delta U=nc_v(T_1-T_2)}$$
$$CD\cases{\Delta U=0\\Q=nRT_1ln(\frac{V_D}{V_C})}\qquad\qquad\qquad\qquad DA\cases{Q=0\\\Delta U=nc_v(T_2-T_1)}$$
<div class="page-break" style="page-break-before: always;"></div>

L'efficienza di un ciclo di Carnot dipende direttamente dalla differenza tra $T_1$ e $T_2$:
$$\eta=1-\frac{|Q_C|}{|Q_A|}=1-\frac{T_1}{T_2}$$

![[schema macchina di carnot.png]]
<div class="page-break" style="page-break-before: always;"></div>

### Esempio - Ciclo diesel
![[schema ciclo diesel.png]]
Il ciclo di Carnot è idealizzato, il vero comportamento di un ciclo diesel è più simile al seguente schema
![[]vero schema ciclo diesel]
Dove le diverse fasi sono:
$0A$ - nebulizzazione
$AB$ - compressione
$BC$ - esplosione
$CD$ - decompressione
$DA$ - espulsione
L'efficienza è data da:
$$\eta=1-\frac{|T_A-T_D|}{T_C-T_B}$$
<div class="page-break" style="page-break-before: always;"></div>

## Ciclo di Carnot inverso
![[schema macchina frigorifera di carnot.png]]
$$\xi=\frac{Q_C}{|W|}=\frac{T_1}{T_2-T_1}$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 20 - Secondo principio della termodinamica
## Enunciato di Kelvin-Planck
**Non esiste un processo in grado di convertire il calore il solo lavoro**
## Enunciato di Clausius
**È impossibile trasferire calore a un corpo di temperatura maggiore**
## Equivalenza degli enunciati
![[schema negazione kelvin-planck.png]]
Avessimo una macchina in grado di convertire tutto il calore in lavoro, potremmo usare quel lavoro su un'altra macchina frigorifera. Unendo le due macchine, ne otterremo una che sposta il calore da una sorgente fredda ad una calda

![[schema negazione clausius.png]]
Fossimo in grado di spostare il calore da una sorgente fredda ad una più calda, potremmo usare quel calore per alimentare una macchina termodinamica. Estraendo lo stesso calore che reimmettiamo nella sorgente fredda e unendo tutto in una singola macchina, avremmo una macchina in grado di convertire tutto il calore in lavoro
## Teorema di Carnot
Una macchina qualsiasi che opera tra due temperature sarà sempre meno efficiente di una macchina che opera un ciclo reversibile, al massimo si eguagliano solo se anche la prima è reversibile
$$\eta_x(T_1,T_2)\leq\eta_{rev}(T_1,T_2)$$
### Corollari
Una macchina termica con ciclo reversibile funziona come il ciclo di Carnot, di conseguenza possiamo definire l'efficienza come $$\eta_R=\eta_{Carnot}=1-\frac{T_1}{T_2}$$
Di conseguenza, l'efficienza di una macchina irreversibile sarà $$\eta_{irr}<1-\frac{T_1}{T_2}$$
Possiamo perciò riscrivere la formula $$\frac{Q_1}{T_1}+\frac{Q_2}{T_2}\leq 0$$
## Teorema di Clausius
![[schema teorema di clausius.png]]
$$\sum_j^N\frac{Q_j}{T_j}\leq 0\qquad\Rightarrow\qquad\oint\frac{dQ}{T}\leq 0$$
<div class="page-break" style="page-break-before: always;"></div>

# Lezione 21 - Entropia
## Entropia
![[schema percorso ciclo reversibile.png]]
L'integrale di una reversibile non dipende dal percorso/trasformazione
$${\int_A^B}_{rev}\frac{dQ}{T}=S_B-S_A=\Delta S_{AB}$$
Questa grandezza è definita **entropia** 
$$dS=[\frac{dQ}{T}]_{rev}$$
<div class="page-break" style="page-break-before: always;"></div>

## Variazione di entropia per le trasformazioni notevoli 

| Trasformazione |                 Formula                 |
| :------------: | :-------------------------------------: |
|    Isoterma    |  $\Delta S_{AB}=nRln(\frac{V_B}{V_A})$  |
|    Isocora     | $\Delta S_{AB}=nc_vln(\frac{T_B}{T_A})$ |
|    Isobara     | $\Delta S_{AB}=nc_pln(\frac{T_B}{T_A})$ |
|   Adiabatica   |              $\Delta S=0$               |
#### Variazione dell'entropia per i cambi di fase
$$\Delta S=\frac{\lambda dm}T$$
![[schema variazione dell'entropia.png]]
<div class="page-break" style="page-break-before: always;"></div>

## Teorema dell'entropia
![[schema teorema dell'entropia.png]]
$$\Delta S_{AB}\geq\int_A^B\frac{dQ}T$$
In un sistema isolato:
$$S(t+\Delta t)-S(t)\geq 0$$
$$S=K_Bln[N]$$

