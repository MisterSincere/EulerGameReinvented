
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.DisplayMode;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.swing.JFrame;



public class Main {	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static File file = new File("doc");
	private static String fileNameBasic = "doc/.basic";
	private static GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
	private static GraphicsDevice device = environment.getDefaultScreenDevice();
	private static DisplayMode displayMode = device.getDisplayMode();
	private static int width = 1100;
	private static int height = 700;
	private static Screen screen;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*******************************ANFANG METHODEN****************************************/
	public static void main(String[] args) {											// main-Methode!
		/*screen = new Screen();
		
		try {
			screen.setFullScreen(displayMode, window);
		} catch (Exception e) {e.printStackTrace();}*/
		
		
		
		
		Basic basic = new Basic();
		if (!file.exists() || (file.exists() && !file.isDirectory())) {
			file.mkdir();
		}
		try {
			@SuppressWarnings("resource")
			ObjectInputStream is = new ObjectInputStream(new FileInputStream(fileNameBasic));
			basic = (Basic) is.readObject();
			
			
			loadConf();
			System.out.println(displayMode.getWidth() + "x" + displayMode.getHeight() + " " + displayMode.getBitDepth() + " " + displayMode.getRefreshRate() + "Hz");
			Tuna game = new Tuna(width, height);
			game.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			
		} catch (FileNotFoundException e) {
			
			
			try {
				ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(fileNameBasic));
				os.writeObject(basic);
				Tuna game = new Tuna("<html><h1><u>TrueStudio präsentiert:</u></h1>"
						+ "<br><br><b>Die ultimativen Abenteuer des Euler in seiner Uni, ein Adventure voller Geheimnisse und Kaffee...</b>"
						+ "<br><br>Professor Euler muss einen Vortrag vor seinen Studenten halten, jedoch wurden die Unterlagen von einem Windstoß durch die"
						+ "<br>ganze Universität verteilt. Auf der Suche nach diesen muss Euler viele Mysterien lösen: Wieso ist die Kaffemaschine nicht eingesteckt?"
						+ "<br>Warum sind in einer Uni Geheimgänge und Schalter versteckt? Warum brennt das Treppenhaus? Und wer ist eigentlich vor der Steckdose"
						+ "<br>zusammengebrochen?"
						+ "<br><br>Kombinieren sie ihre Raffinese mit Kreativität, um die acht verschwundenen Seiten wiederzufinden."
						+ "<br>Probieren sie unser revolutionäres Kampfsystem aus, und nehmen Sie alles genau unter die Lupe,"
						+ "<br>schließlich könnten Ihre Seiten überall sein!"
						+ "<br><br>\"Die ultimativen Abenteuer des Euler in seiner Uni, ein Adventure voller Geheimnisse und Kaffee...\" wird Ihnen in mehr als 10 minuten"
						+ "<br>Spielzeit mit Witz und Unsinn jeden noch so schlechten Tag verschönern, ein Spaß für alle, die mit einer Kaffeemaschine umgehen können."
						+ "<br><br><br>Viel Spaß wünscht Ihnen"
						+ "<br><b><font color='002FB6'>CTT</font> \"Wir fordern zum selber Denken auf\"</b></html>");
				game.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				os.close();
			} catch (FileNotFoundException e1) {e1.printStackTrace();
			} catch (IOException e1) {e1.printStackTrace();}
			
		} catch (IOException e) {e.printStackTrace();
		} catch (ClassNotFoundException e) {e.printStackTrace();}
		
		
		
		
		
		
		
		Tuna.setText("Sehr geehrter Herr Euler," + "\nes ist 8 Uhr morgens und du stehst in deinem Büro der Universität (Lehrer Etage). In deinem Büro ist mittig ein "
				+ "überfüllter Schreibtisch [desk] an dem ein Scott Chefsessel aus original Kunstleder im Wert von 500€ steht [chair]. "
				+ "Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes." + "\n\nVon hier aus kannst du in den Korridor [corridor] gehen. Generell gilt: "
				+ "Um woanders hinzugehen gibst du ein: go <Raum>. " + "Für <Raum> setzt du den englischen Namen deines Ziels ein, because you need to learn English."
				+ "\n\nFür Hilfe drücke \"H\" oder gebe unten \"help\" ein!"
				+ "\nFür die Optionen drücke \"O\" oder gebe unten \"options\" ein!");
		Tuna.setExitsContent("Korridor [corridor]");
	}
	
	public static void showHelp() {														// Hilfe-Fenster mit den Variation der Befehle
		Tuna.createFrame("Hilfe", "Ihre Befehle:",
				"\nBefehl um in einen benachbarten Raum zu gehen: \t\tgo <room>"
				+ "\nUm in den vorherigen Raum zurückzugehen:\t\t\tback"
				+ "\nBefehl um einen Gegenstand zu untersuchen: \t\texamine <object>"
				+ "\nBefehl zum Interagieren mit einem Gegenstand: \t\tinteract <object>" + "\nBefehl zum Interagieren mit einem Gegenstand aus dem Inventar: \tinteract inv <object>"
				+ "\nZum Lesen eines Gegenstandes: \t\t\tread <object>  oder  read inv <object>"
				+ "\nBefehl um sich den aktuellen Raum genauer anzusehen: \t\texplore"
				+ "\nZum Verlassen eines Gespräches:\t\t\tbye"
				+ "\n\nSpeichern:\t\tsave"
				+ "\nLaden:\t\tload"
				+ "\nNeustart:\t\trestart"
				+ "\nRespawn (Inventar bleibt):\trespawn"
				+ "\nEinstellungen:\t\toptions"
				+ "\nBeenden:\t\texit", 700, 380);
	}
	
	public static void save() {															// Methode zum Speichern der Spieldaten in die Klasse Save in Datei doc/.save
		if (!Tuna.getEuler().isDeath()) {
		Character euler = Tuna.getEuler();
		Save player = new Save();
		String fileName = "doc/.save";
		
		if (!file.exists() || (file.exists() && !file.isDirectory())) {
			file.mkdir();
		}
		
		
		// Locations speichern
		for (int i = 0; i < 21; i++) {
			player.locations.add(i, euler.getLocation(i));
		}
		
		// Item Beschreibungen speichern
		for (int i = 0; i < 21; i++) {
			player.items.add(i, euler.getLocation(i).getItems());
		}
		
		// Aktuelle Position des Spielers speichern
		player.currentLocation = euler.getCurrentLocation();
		// Inventar
		player.iObjects = Tuna.getiObjects();
		// Beamfunktion
		player.beam = euler.isBeam();
		// AmountNotes
		player.amountNotes = euler.getAmountNotes();
	 
		
		
		try {
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(fileName));
			os.writeObject(player);
			os.close();
			Tuna.setMessage("Speichern erfolgreich!");
		} catch (FileNotFoundException e) {Tuna.setMessage("FileNotFoundException");e.printStackTrace();
		} catch (IOException e) {Tuna.addText("IOException");e.printStackTrace();
		}
		
		} else {
			Tuna.setMessage("Du bist tot. Warum speichern?");
		}

	}
	
	public static void load() {															// Methode zum Laden der Spieldaten aus der Klasse Save der Datei doc/.save
		String fileName = "doc/.save";
		Character Euler = Tuna.getEuler();
		
		try {
			ObjectInputStream is = new ObjectInputStream(new FileInputStream(fileName));
			Save load = (Save) is.readObject();
			is.close();
			
			
				// Laden der gespeicherten Attributwerte
			// Alle Räume laden
			for (int i = 0; i < 21; i++) {
				Euler.setLocation(i, load.locations.get(i));
			}
			
			// Alle Items laden
			for (int i = 0; i < 21; i++) {
				Euler.getLocation(i).setItems(load.items.get(i));
			}
			
			// Aktuelle Position laden
			Euler.setCurrentLocation(load.currentLocation);
			// Letzte Position laden
			Euler.setLastLocation(load.lastLocation);
			
			// Ausgänge
			Tuna.setExitsContent(Euler.getLocation(load.currentLocation).getExits());
			
			
			// Inventar
			Tuna.iDeleteContent();
			Tuna.setiObjects(load.iObjects);
			
			String ausgabe = "";
			for (int i = 0; i < Tuna.getiObjects().size(); i++) {
				ausgabe += Tuna.getiObjects().get(i) + "\n";
			}
			Tuna.setiContent(ausgabe);
			
			// Beamfunktion
			Euler.setBeam(load.beam);
			// Speichern ist nicht erlaubt wenn man Tod ist, somit wissen wir, dass der Boolean auf false wahr.
			Euler.setDeath(false);
			// AmountNotes
			Euler.setAmountNotes(load.amountNotes);
			
			
			
			// Ausgaben
			// Verschiedene Artikel bei der Angabe des aktuellen Raumes (Die Textdatei ID's.txt ist im Material entahlten, welches auf thegame.bplaced.net gedownloadet werden kann)
			if (load.currentLocation == 4 || load.currentLocation == 6 || load.currentLocation == 7 || load.currentLocation == 18 || load.currentLocation == 19) {
				Tuna.setText("Du bist zurück in der " + Euler.getLocation().getName());
			} else {
				Tuna.setText("Du bist zurück im " + Euler.getLocation().getName());
			}
			
			// Die Anzeige der Raumbeschreibungen, abhöngig davon, ob der Raum schon explored wurde
			if (Euler.getLocation().isExplored()) {
				Tuna.addText(Euler.getLocation().getDescriptions().getAlreadyExploredDescription());
			} else {
				Tuna.addText(Euler.getLocation().getDescriptions().getDefaultDescription());
			}
			Tuna.setMessage("Laden erfolgreich!");			// Nachricht an den Spieler
			
			
		} catch (IOException e) {Tuna.setMessage("IOException");e.printStackTrace();
		} catch (ClassNotFoundException e) {Tuna.setMessage("ClassNotFoundException");e.printStackTrace();}
	}

	public static void saveConf() {														// Methode zum Seichern der Einstellungen in die Datei doc/.config
		Basic config = new Basic();
		String fileName = "doc/.config";
		
		if (!file.exists() || (file.exists() && !file.isDirectory())) {
			file.mkdir();
		}
		
		config.width = Tuna.getWindowWidth();
		config.height = Tuna.getWindowHeight();
		config.soundAllowed = Tuna.isSoundAllowed();
		config.selectedItemResolution = Tuna.getSelectedItemResolution();
		config.ausgabeColor = Tuna.getAusgabeColor();
		config.inventarColor = Tuna.getInventarColor();
		config.exitsColor = Tuna.getExitsColor();
		
		try {
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(fileName));
			os.writeObject(config);
			os.close();
		} catch (FileNotFoundException e) {e.printStackTrace();
		} catch (IOException e) {e.printStackTrace();}
	}
	
	public static void loadConf() {														// Methode zum Laden der Einstellungen aus der Datei doc/.config
		String fileName = "doc/.config";
		
		
		try {
			ObjectInputStream is = new ObjectInputStream(new FileInputStream(fileName));
			Basic basic = (Basic) is.readObject();
			is.close();
			
			width = basic.width;
			height = basic.height;
			Tuna.setSoundAllowed(basic.soundAllowed);
			Tuna.setWindowWidth(width);
			Tuna.setWindowHeight(height);
			Tuna.setSelectedItemResolution(basic.selectedItemResolution);
			Tuna.setAusgabeColor(basic.ausgabeColor);
			Tuna.setInventarColor(basic.inventarColor);
			Tuna.setExitsColor(basic.exitsColor);
			
		} catch (FileNotFoundException fe) {
			saveConf();
		} catch (IOException e) {Tuna.addText("IOException");e.printStackTrace();
		} catch (ClassNotFoundException e) {Tuna.addText("ClassNotFoundException");e.printStackTrace();}
	}
	/*********************************ENDE METHODEN****************************************/
	
	
	public static DisplayMode getDisplay() {
		return displayMode;
	}
	public static Screen getScreen() {
		return screen;
	}
}