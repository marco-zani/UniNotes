# Ereditarietà e Polimorfismo
- Overloading modifica la firma di un metodo, Overriding tiene la medesima
- Il tipo dinamico surclassa quello statico in caso di overriding
- **Upcasting** si riferisce alla risalita della gerarchia delle classi, ossia una sottoclasse che viene convertita in una classe padre
	- esempio statico: `Padre p = new Figlio();`
- **Downcasting** invece scenda la gerarchia della classi, ossia una classe padre che viene convertita in una classe figlia
	- esempio dinamico: `Figlio f = (Figlio) p;`

# Visibilità
- `final` è applicabile sia a classi e metodi e limita l'overriding

# Eguaglianza e Identità
- `==` testa l'identità, mentre `equals()` testa l'eguaglianza
- `equals()` deve gestire il caso `null` e il caso l'oggetto non sia un instanza della classe 
- `.getClass()` per confrontare senza includere le sottoclassi

# Costruttori
- Il costruttore di una sottoclasse chiama quello della classe padre a meno che non sia specifica diversamente

# Classi astratte
- Necessitano di implementazione
- se una classe contiene anche un solo metodo astratto, lo diventa anche la classe


# Codice
#### Alert
>[!quote]- Alert
>`Alert alert = new Alert(AlertType.INFORMATION);  `
>`alert.setTitle("Alert Title");  `
>`alert.setHeaderText("Alert header:");  `
>`alert.setContentText("Alert Text");  `
>`alert.showAndWait();`

>[!quote]- TextInputDialog
>`TextInputDialog dialog = new TextInputDialog("Default answer");  `
>`dialog.setTitle("Dialog Title");  `
>`dialog.setHeaderText("Dialog header");  `
>`dialog.setContentText("Answer label:");  `
>`String s= dialog.showAndWait().get();`

#### Try catch
- Esiste la clausola `finally` per eseguire codice sia in caso di errore o meno

#### Events
- Meglio usare `addEventHandler()` per impostare molteplici eventi (setOn... ne gestisce solo uno alla volta)
	- Sintassi: ``addEventHandler([tipo di evento], e->{[funzione]})`

>[!quote]- custom event
>`public class OutOfBoundsEvent extends Event {  `
>`public static final EventType\<OutOfBoundsEvent> CUSTOM = new`
>`EventType(ANY, "CUSTOM");  `
>`public OutOfBoundsEvent() {  `
>`super(OutOfBoundsEvent.CUSTOM);  `
>`}`  
>`}`

#### Immagini e File
>[!quote]- File
>`FileChooser fileChooser = new FileChooser();  `
>`fileChooser.setTitle("Carica un'immagine");  `
>`fileChooser.getExtensionFilters().addAll(  `
>`new FileChooser.ExtensionFilter("JPG", "*.jpg"),  `
>`new FileChooser.ExtensionFilter("PNG", "*.png")  `
>`);  `
>`String url = System.getProperty("user.home");  `
>`File f=new File(url);  `
>`fileChooser.setInitialDirectory(f); // bugged on MacOsX  `
>`File file = fileChooser.showOpenDialog(stage);  `
>`if (file == null) {  `
>`System.out.println("No file chosen");  `
>`System.exit(1);  `
>`}`

>[! quote]- Image
>`Image image = new Image("file://" + file.getAbsolutePath(), 500, 500, true, true);  `
>`ImageView iw = new ImageView(image);`
>`getChildren().add(iw);`



# Lettura codice
- Downcast illecito (Runtime error-ClassCastException): Un downcast in una classe di cui l'oggetto non è istanza
- Una classe figlia chiama sempre il costruttore del padre

#### Tipologie di esercizio
- variabili non inizializate
- problemi di casting
	- bad downcasting
- controlla sempre il print e il println