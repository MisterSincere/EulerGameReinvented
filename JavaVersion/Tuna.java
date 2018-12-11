import java.awt.Color;
import java.awt.DisplayMode;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.SwingConstants;


public class Tuna extends JFrame {

	/****************************** ERSTELLEN DER ATTRIBUTE *********************************/
	private static final long serialVersionUID = -7979967175297353331L;
	private static final String versionNumber = "v.1.000.3";
	// Optionen
	private static boolean soundAllowed = false;
	private static int width = 1100;
	private static int height = 700;
	private static int selectedItemResolution = 0;
	private static Color ausgabeColor = Color.DARK_GRAY;
	private static Color inventarColor = new Color(0x602600);
	private static Color exitsColor = new Color(0xA03500);
	// Überschrift mit Versionsnummer, Ausgabe und Eingabe
	private JLabel heading = new JLabel(versionNumber, SwingConstants.CENTER);
	private static JTextArea ausgabe = new JTextArea();
	private static JTextField eingabe = new JTextField(20);
	// Inventar
	private static JTextArea inventar = new JTextArea();
	private JLabel iHeading = new JLabel("Inventar", SwingConstants.CENTER);
	private static JTextArea iContent = new JTextArea();
	private static ArrayList<String> iObjects = new ArrayList<String>();
	// Menü
	private JMenuBar menuBar = new JMenuBar();
	private JMenu menuFile = new JMenu("Programm");
	private JMenu menuHelp = new JMenu("Hilfe");
	private JMenuItem menuSettings = new JMenuItem("Einstellungen");
	private JMenuItem menuMessage = new JMenuItem("Willommensmeldung");
	private JMenuItem saveItem = new JMenuItem("Speichern");
	private JMenuItem loadItem = new JMenuItem("Laden");
	private JMenuItem saveExit = new JMenuItem("Speichern und Beenden");
	private JMenuItem exit = new JMenuItem("Beenden");
	// Anzeige für Meldungen
	private static JLabel message = new JLabel();
	// Anzeige der Ausgänge
	private static JTextArea exits = new JTextArea();
	private JLabel eHeading = new JLabel("Anliegende Räume", SwingConstants.CENTER);
	private static JTextArea eContent = new JTextArea();
	// Objekte der Willkommensmeldung
	private JFrame frame = new JFrame("Vielen Dank, dass sie sich für das Original entschieden haben");
	private JCheckBox questionTextBased = new JCheckBox("Sounds");
	private JButton lButtonD = new JButton("Deutsch");
	private JButton lButtonE = new JButton("English");
	private JButton lButtonF = new JButton("Fraince");
	// Der Charakter wird angefertigt
	private static Character Euler = new Character();
	// Schriftart
	private static Font stdFont = new Font("ARIALUNI", Font.PLAIN, 13);
	/****************************** FERTIG ATTRIBUTE ****************************************/
	
	
	
	
	/***************************** ANFANG KONSTRUKTOREN *************************************/
	public Tuna(int width, int height) {
		KeyHandler keyHandler = new KeyHandler();
		// Frame
		setSize(width, height);
		setLocationRelativeTo(null);
		setResizable(false);
		setTitle("Euler: Coffee Adventure    -    " + versionNumber);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		addKeyListener(keyHandler);
		setLayout(null);

		// Menü erstellen
		StandardHandler std_handler = new StandardHandler();
		menuBar.setBounds(0, 0, width, 20);
		saveItem.addActionListener(std_handler);
		loadItem.addActionListener(std_handler);
		menuSettings.addActionListener(std_handler);
		exit.addActionListener(std_handler);
		saveExit.addActionListener(std_handler);
		menuMessage.addActionListener(std_handler);
		menuFile.add(saveItem);
		menuFile.add(loadItem);
		menuFile.addSeparator();
		menuFile.add(menuSettings);
		menuFile.addSeparator();
		menuFile.add(saveExit);
		menuFile.add(exit);
		menuHelp.add(menuMessage);
		menuBar.add(menuFile);
		menuBar.add(menuHelp);
		add(menuBar);

		// Überschrift mit Versionsnummer
		heading.setBounds(0, 20, width, 15);
		heading.setFont(heading.getFont().deriveFont(Font.BOLD, 12));
		heading.setForeground(Color.RED);
		heading.addKeyListener(keyHandler);
		add(heading);

		// Ausgabefeld
		ausgabe.setBounds((int) (width * 0.002), 35, (int) (width * 0.78),
				height - 135);
		ausgabe.setEditable(false);
		ausgabe.setForeground(Color.WHITE);
		ausgabe.setBackground(ausgabeColor);
		ausgabe.setOpaque(true);
		ausgabe.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
		ausgabe.setLineWrap(true);
		ausgabe.setWrapStyleWord(true);
		ausgabe.setFont(stdFont);
		ausgabe.addKeyListener(keyHandler);
		add(ausgabe);

		// Inventar
		inventar.setBounds((int) (width * 0.79), 35, (int) (width * 0.20),
				(int) (height * 0.58));
		inventar.setEditable(false);
		inventar.setBackground(inventarColor);
		inventar.addKeyListener(keyHandler);
		// InventarHeadline
		iHeading.setBounds(0, 0, (int) (width * 0.20), (int) (height * 0.03));
		iHeading.setForeground(Color.WHITE);
		iHeading.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.WHITE));
		iHeading.addKeyListener(keyHandler);
		inventar.add(iHeading);
		// InventarContent
		iContent.setBounds(0, (int) (height * 0.03), (int) (width * 0.20),
				(int) (height * 0.58));
		iContent.setEditable(false);
		iContent.setForeground(Color.WHITE);
		iContent.setBackground(inventarColor);
		iContent.setBorder(BorderFactory.createEmptyBorder(2, 2, 2, 2));
		iContent.setFont(stdFont);
		iContent.addKeyListener(keyHandler);
		inventar.add(iContent);
		add(inventar);

		// Anzeige der Ausgänge
		exits.setBounds((int) (width * 0.79), (int) (height * 0.587) + 35,
				(int) (width * 0.20), height - ((int) (height * 0.587) + 135));
		exits.setEditable(false);
		exits.setBackground(exitsColor);
		exits.addKeyListener(keyHandler);
		// AusgängeHeadline
		eHeading.setBounds(0, 0, (int) (width * 0.20), (int) (height * 0.03));
		eHeading.setForeground(Color.BLACK);
		eHeading.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.WHITE));
		eHeading.addKeyListener(keyHandler);
		exits.add(eHeading);
		// AusgängeContent
		eContent.setBounds(0, (int) (height * 0.03), (int) (width * 0.20), 140);
		eContent.setEditable(false);
		eContent.setForeground(Color.BLACK);
		eContent.setFont(eContent.getFont().deriveFont(Font.BOLD, 12));
		eContent.setBackground(exitsColor);
		eContent.setBorder(BorderFactory.createEmptyBorder(2, 2, 2, 2));
		eContent.setFont(stdFont);
		eContent.addKeyListener(keyHandler);
		exits.add(eContent);
		add(exits);

		// EingabeFeld
		eingabe.setBounds((int) ((width * 0.782 - 250) / 2), (height - 75),
				250, 22);
		eingabe.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY, 1));
		eingabe.addActionListener(new InputHandler());
		add(eingabe);

		// Message
		message.setBounds((int) ((width * 0.782 - 250) / 2) + 265,
				(height - 75), 300, 22);
		message.setForeground(Color.RED);
		add(message);

		setVisible(true);
	}

	public Tuna(String text) {
		JLabel textArea = new JLabel(text);

		frame.setSize(820, 550);
		frame.setUndecorated(false);
		frame.setLocationRelativeTo(null);
		frame.setAlwaysOnTop(true);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(null);

		textArea.setBounds(0, -25, 800, 450);
		textArea.setBackground(Color.WHITE);
		textArea.setFont(stdFont);
		textArea.setBorder(BorderFactory.createEmptyBorder(5, 5, 0, 0));
		frame.add(textArea);

		questionTextBased.setBounds(140, 470, 70, 28);
		questionTextBased.addItemListener(new ItemHandler());
		questionTextBased.setFont(stdFont);
		frame.add(questionTextBased);

		lButtonD.setBounds(220, 470, 100, 28);
		lButtonD.addActionListener(new StandardHandler());
		frame.add(lButtonD);

		lButtonE.setBounds(340, 470, 100, 28);
		lButtonE.setEnabled(false);
		lButtonE.addActionListener(new StandardHandler());
		frame.add(lButtonE);

		lButtonF.setBounds(460, 470, 100, 28);
		lButtonF.addActionListener(new StandardHandler());
		frame.add(lButtonF);

		frame.setVisible(true);
	}

	/***************************** ENDE KONSTRUKTOREN ***************************************/
	
	
	
	
	/******************************* ANFANG METHODEN ****************************************/
	public static void iAddContent(String name) { // Eingesammeltes Element ins
													// Inventar hinzufügen
		if (name == "Notiz") {
			if (iObjects.contains(Euler.getAmountNotes() + "x Notiz")) {
				int amountNotes = Euler.getAmountNotes() + 1;
				Euler.setAmountNotes(amountNotes);
				int index = iObjects.indexOf(amountNotes - 1 + "x Notiz");
				iObjects.set(index, amountNotes + "x Notiz");
			} else {
				Euler.setAmountNotes(1);
				iObjects.add(Euler.getAmountNotes() + "x Notiz");
			}
		} else {
			iObjects.add(name);
		}

		String ausgabe = "";
		for (int i = 0; i < iObjects.size(); i++) {
			ausgabe += iObjects.get(i) + "\n";
		}
		iContent.setText(ausgabe);
	}

	public static void iDeleteContent() { // Löschen des Inventars
		for (int i = 0; i < iObjects.size(); i++) {
			iObjects.remove(i);
		}
		iContent.setText("");
	}

	public static void iDeleteItem(String item) {
		for (int i = 0; i < iObjects.size(); i++) {
			if (iObjects.get(i).equalsIgnoreCase(item)) {
				iObjects.remove(i);
				i = iObjects.size();
			}
		}

		String ausgabe = "";
		for (int i = 0; i < iObjects.size(); i++) {
			ausgabe += iObjects.get(i) + "\n";
		}
		iContent.setText(ausgabe);
	}

	public static void createFrame(String winHeading, String headline,
			String text, int width, int height) { // Eigenes Frame für die Hilfe, so kann das Fenster offen bleiben!
		JFrame meldung = new JFrame();
		JLabel heading = new JLabel(headline, SwingConstants.CENTER);
		JTextArea content = new JTextArea();

		// Frame
		meldung.setSize(width, height);
		meldung.setTitle(winHeading);
		meldung.setLocationRelativeTo(null);
		meldung.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		meldung.setVisible(true);
		meldung.setResizable(false);

		// Überschrift
		heading.setBounds(0, 0, width, 20);
		heading.setFont(heading.getFont().deriveFont(Font.BOLD, 13));
		heading.setBorder(BorderFactory.createMatteBorder(0, 0, 2, 0,
				Color.LIGHT_GRAY));
		meldung.add(heading);

		// Inhalt
		content.setBounds(0, 30, width, height - 30);
		content.setBorder(BorderFactory.createEmptyBorder(20, 10, 5, 10));
		content.setEditable(false);
		content.setText(text);
		content.setFont(stdFont);
		meldung.add(content);
	}

	public void setSizeRelative() { // Neue Größe des
															// Frames und dessen
															// Objekte im
															// Verhältnis setzen
		Tuna.this.setSize(width, height);
		menuBar.setBounds(0, 0, width, 20);
		heading.setBounds(0, 20, width, 15);
		ausgabe.setBounds((int) (width * 0.002), 35, (int) (width * 0.78),
				height - 135);
		inventar.setBounds((int) (width * 0.79), 35, (int) (width * 0.20),
				(int) (height * 0.58));
		iHeading.setBounds(0, 0, (int) (width * 0.20), (int) (height * 0.03));
		iContent.setBounds(0, (int) (height * 0.03), (int) (width * 0.20),
				(int) (height * 0.58));
		exits.setBounds((int) (width * 0.79), (int) (height * 0.587) + 35,
				(int) (width * 0.20), height - ((int) (height * 0.587) + 135));
		eHeading.setBounds(0, 0, (int) (width * 0.20), (int) (height * 0.03));
		eContent.setBounds(0, (int) (height * 0.03), (int) (width * 0.20), 140);
		eingabe.setBounds((int) ((width * 0.782 - 250) / 2), (height - 75),
				250, 22);
		message.setBounds((int) ((width * 0.782 - 250) / 2) + 265,
				(height - 75), 300, 22);
	}

	public boolean isNumber(String text) {
		for (int i = 0; i < text.length(); i++) {
			if ((int) text.charAt(i) < 48 || (int) text.charAt(i) > 57) {
				return false;
			}
		}
		return true;
	}
	/********************************* ENDE METHODEN ****************************************/
	
	
	
	
	/************************** ANFANG INTERNER KLASSEN/LISTENER ****************************/
	// EMPFEHLUNG DIE KLASSEN EINZUKLAPPEN (so wie eigentlich alles :)
	private class ItemHandler implements ItemListener { // ITEM LISTENER; für die Frage in der Willkommensmeldung, ob Sound erlaubt sein soll
		@Override
		public void itemStateChanged(ItemEvent e) {
			Object source = e.getSource();

			if (source == questionTextBased) {
				soundAllowed = true;
			}

			if (e.getStateChange() == ItemEvent.DESELECTED) {
				soundAllowed = false;
			}
		}
	}

	private class StandardHandler implements ActionListener { // ACTION LISTENER (für verschiedenes: Menü, Willkommensmeldung)
		@Override
		public void actionPerformed(ActionEvent event) {
			/**** ABFRAGE SPRACHE IN DER WILLKOMMENSMELDUNG ****/
			if (event.getSource() == lButtonD) {
				frame.setVisible(false);
				new Tuna(1100, 700);
			} else if (event.getSource() == lButtonE) {
				frame.setVisible(false);
			} else if (event.getSource() == lButtonF) {
				frame.setVisible(false);
				new Fraince();

				/*************** MENÜ ITEMS ************************/
			} else if (event.getSource() == saveItem) {
				Main.save(); // Speichert Spielstand
			} else if (event.getSource() == loadItem) {
				Main.load(); // Lädt Spielstand
			} else if (event.getSource() == saveExit) {
				Main.save(); // Speichert und
				System.exit(0); // schließt das Programm
			} else if (event.getSource() == exit) {
				System.exit(0); // Schließt das Programm

			} else if (event.getSource() == menuMessage) { // Gleicher Text wie
															// der beim ersten
															// Start in der
															// Wilkommensmeldung
															// nur ohne Buttons
															// (und als Dialog,
															// siehe Klasse
															// WelcomeDialog)
				WelcomeDialog welcomeDialog = new WelcomeDialog(Tuna.this);
				welcomeDialog.setLocationRelativeTo(Tuna.this);
				welcomeDialog.setVisible(true);

			} else if (event.getSource() == menuSettings) {
				Options options = new Options(Tuna.this);
				options.setLocationRelativeTo(Tuna.this);
				options.setVisible(true);
			}
		}
	}

	private class InputHandler implements ActionListener { // ACTION LISTENER (die Eingabe und was von dieser abhängig ausgeführt werden soll wird hier festgelegt)
		@Override
		public void actionPerformed(ActionEvent e) {
			String eingabeText = eingabe.getText();
			eingabe.setText("");
			message.setText("");

			// Führt entsprechend der Eingabe die vorgegebenen Methoden aus
			if (Euler.isLockerQuestion()) {
				if (eingabeText.equals("42") && !Euler.getLocation(13).getItem(0).isCollected()) {
					Tuna.addText("Du siehst ein Blatt Papier, welches eine deiner Notizen sein könnte, doch die Algen verbieten dir das Einsammeln.\nDu brauchst etwas um die Algen zu eleminieren.");
					Euler.setLockerQuestion(false);
					Euler.getLocation().getItem(1).setVisible(true);
				} else if (!isNumber(eingabeText)) {
					Tuna.setMessage("Die Dinger sind nummeriert!");
				} else {
					Tuna.addText("Langweilig!");
					Euler.setLockerQuestion(false);
				}
			} else if (Euler.isInQuiz()) {
				if (eingabeText.equalsIgnoreCase(Euler.getLocation().getStudent().getAnswerText())) {
					Tuna.addText(Euler.getLocation().getStudent().getName() + " \"" + Euler.getLocation().getStudent().getHint() + "\"");
					Euler.setInQuiz(false);
					Tuna.setMessage("Du hast die Frage erfolgreich beantwortet.");
				} else if (eingabeText.equalsIgnoreCase("bye")) {
					Tuna.setMessage("Du verlässt den Dialog.");
					Tuna.addText("Der Student war deiner Anwesenheit eh nicht würdig!");
					Euler.setInQuiz(false);
				} else if (eingabeText.equals("help")) {
					Main.showHelp();
				} else if (eingabeText.equals("go corridor")) {
					Tuna.setMessage("Du befindest dich in einem Dialog!");
				} else if (eingabeText.equals("exit")) {
					System.exit(0);
				} else if (soundAllowed) {
					java.awt.Toolkit.getDefaultToolkit().beep();
				}
					
			} else {
				switch (eingabeText) {
	
				// GO - Räume Wechseln
				case "go office":
					Euler.changeLocation(0);
					break;
	
				case "go corridor":
					int l = Euler.getCurrentLocation();
					if (l == 0 || l == 1 || l == 2 || l == 3 || l == 6 || l == 7
							|| l == 8 || l == 9) {
						Euler.changeLocation(1);
					} else if (l == 11 || l == 12 || l == 13 || l == 14 || l == 15
							|| l == 16 || l == 17 || l == 18 || l == 19) {
						Euler.changeLocation(11);
					} else {
						if (soundAllowed) {
							java.awt.Toolkit.getDefaultToolkit().beep();
						}
					}
					break;
	
				case "go floor 2":
					if (Euler.getCurrentLocation() == 10) {
						Euler.changeLocation(1);
					} else if (soundAllowed) {
						java.awt.Toolkit.getDefaultToolkit().beep();
					}
					break;
	
				case "go coffeeroom":
					Euler.changeLocation(2);
					break;
	
				case "go conference room":
					Euler.changeLocation(3);
					break;
	
				case "go chamber":
					Euler.changeLocation(4);
					break;
	
				case "go ventilationroom":
					Euler.changeLocation(5);
					break;
	
				case "go ladiestoilet":
					int t1 = Euler.getCurrentLocation();
					int oldT1 = Euler.getLastLocation();
	
					if ((t1 >= 0 && t1 <= 8) || (oldT1 >= 0 && oldT1 <= 8)) {
						Euler.changeLocation(6);
					} else if ((t1 >= 10 && t1 <= 19)
							|| (oldT1 >= 10 && oldT1 <= 19)) {
						Euler.changeLocation(18);
					}
					break;
	
				case "go gentlemenstoilet":
					int t2 = Euler.getCurrentLocation();
					int oldT2 = Euler.getLastLocation();
	
					if ((t2 >= 0 && t2 <= 8) || (oldT2 >= 0 && oldT2 <= 8)) {
						Euler.changeLocation(7);
					} else if ((t2 >= 10 && t2 <= 19)
							|| (oldT2 >= 10 && oldT2 <= 19)) {
						Euler.changeLocation(19);
					}
					break;
	
				case "go principalsroom":
					Euler.changeLocation(8);
					break;
	
				case "go elevator":
					Euler.changeLocation(9);
					break;
	
				case "go stairwell":
					Euler.changeLocation(10);
					break;
	
				case "go floor 1":
					if (Euler.getCurrentLocation() == 10) {
						Euler.changeLocation(11);
					} else if (soundAllowed) {
						java.awt.Toolkit.getDefaultToolkit().beep();
					}
					break;
	
				case "go lecture hall 1":
					Euler.changeLocation(12);
					break;
	
				case "go lockerroom":
					Euler.changeLocation(13);
					break;
	
				case "go storeroom":
					Euler.changeLocation(14);
					break;
	
				case "go lecture hall 2":
					Euler.changeLocation(15);
					break;
	
				case "go lecture hall 3":
					Euler.changeLocation(16);
					break;
	
				case "go lecture hall 4":
					Euler.changeLocation(17);
					break;
	
				case "go elevator shaft":
					Euler.changeLocation(20);
					break;
	
				// EXPLORE - genaueres Untersuchen eines Raumes
				case "explore":
					Euler.expLocation();
					break;
	
				// INTERACT - Mit einem Gegenstand interagieren
				case "interact note":
					Euler.interactObject("note");
					break;
	
				case "interact chair":
					Euler.interactObject("chair");
					break;
	
				case "interact fire ax":
					Euler.interactObject("fireax");
					break;
	
				case "interact skillbook":
					Euler.interactObject("skillbook");
					break;
	
				case "interact paper":
					Euler.interactObject("paper");
					break;
	
				case "interact coffeemachine":
					Euler.interactObject("coffeemachine");
					break;
	
				case "interact inv fire ax":
					Euler.interactObject("inv fireax");
					break;
	
				case "interact extinguisher box":
					Euler.interactObject("extinguisherbox");
					break;
	
				case "interact coffee extinguisher":
					Euler.interactObject("coffeeextinguisher");
					break;
	
				case "interact inv coffee extinguisher":
					Euler.interactObject("invcoffeeextinguisher");
					break;
	
				case "interact cup coffee":
					Euler.interactObject("coffeecup");
					break;
	
				case "interact gully":
					Euler.interactObject("gully");
					break;
					
				case "interact ventilation shaft":
					Euler.interactObject("ventilationsshaft");
					break;
					
				case "interact spatula":
					Euler.interactObject("spatula");
					break;
					
				case "interact inv spatula":
					Euler.interactObject("invspatula");
					break;
				
				case "interact student":
					Euler.interactObject("student");
					break;
					
				case "interact wilhelm":
					Euler.interactObject("wilhelm");
					break;
	
				// EXAMINE / READ
				case "examine chair":
					Euler.examineObject("chair");
					break;
	
				case "examine cupboards":
					Euler.examineObject("cupboards");
					break;
	
				case "examine fire ax":
					Euler.examineObject("fireax");
					break;
	
				case "examine inv fire ax":
					Euler.examineObject("inv fireax");
					break;
	
				case "examine ventilation shaft":
					Euler.examineObject("ventilationshaft");
					break;
	
				case "examine desk":
					Euler.examineObject("desk");
					break;
	
				case "examine extinguisher box":
					Euler.examineObject("extinguisherbox");
					break;
	
				case "examine coffee extinguisher":
					Euler.examineObject("coffeeextinguisher");
					break;
	
				case "examine inv coffee extinguisher":
					Euler.examineObject("inv coffeeextinguisher");
					break;
	
				case "examine gully":
					Euler.examineObject("gully");
					break;
				
				case "examine locker": case "interact locker":
					Euler.examineObject("locker");
					break;
					
				case "examine shiny locker": case "interact shiny locker":
					Euler.examineObject("shinylocker");
					break;
					
				case "examine spatula":
					Euler.examineObject("spatula");
					break;
					
				case "examine inv spatula":
					Euler.examineObject("invspatula");
					break;
					
				case "examine paper":
					if (Euler.getCurrentLocation() == 0 && !Euler.getLocation(0).getItem(3).isCollected()) {				// Als Hinweis auf den Befehl 'read'
						Tuna.setMessage("Willst du es nicht lieber lesen?");
					}
					break;
				
				// Die Lese-Sachen
				case "read paper":
					Euler.examineObject("paper");
					break;
	
				case "read inv paper":
					Euler.examineObject("inv paper");
					break;
	
				case "read timetable":
					Euler.examineObject("timetable");
					break;
					
				case "read notes": case "interact notes": 																	// Man kann mehreres eingeben
					if (Euler.getCurrentLocation() == 17 && Euler.getAmountNotes() == 4) {
						Win win = new Win(Tuna.this);
						SwingUtils.fadeIn(win);
					} else if (Euler.getAmountNotes() == 4) {
						Tuna.setMessage("Du hältst standardmäßig in Hörsaal 4 deine Vorträge");
					} else {
						Tuna.setMessage("Als ob!");
						if (soundAllowed) {
							java.awt.Toolkit.getDefaultToolkit().beep();
						}
					}
					break;
				
				// OTHERS
				case "save":
					if (!Euler.isBattle()) {
						// String name = eingabe.getText();
						Main.save();
					} else {
						Tuna.setMessage("Im Kampf kannst du nicht speichern!");
					}
					break;
	
				case "load":
					Main.load();
					break;
					
				case "back":
					Euler.changeLocation(Euler.getLastLocation());
					break;
	
				case "help":
					Main.showHelp();
					break;
	
				case "exit":
					System.exit(0);
					break;
	
				case "respawn":
					if (Euler.isDeath()) {
						Euler.setCurrentLocation(0);															// Gestartet wird wieder im Büro
						Euler.setLastLocation(0);																// Letzte Location gibt es nicht...
						Euler.setDeath(false);																	// Euler ist nicht mehr Tod
						Tuna.setExitsContent("Korridor [corridor]");											// Ausgänge setzen
						Tuna.setText("Du wachst in deinem Büro auf.");											// Text mit Hinweis auf aktuelle Position
						Tuna.addText(Euler.getLocation(0).getDescriptions().getDefaultDescription());			// Default-Beschreibung vom Büro anzeigen
						
						// Alle Räume müssen/können wieder untersucht werden
						for (int i = 0; i < 21; i++) {
							Euler.getLocation(i).setExplored(false);
						}
					} else {
						Tuna.setMessage("Du bist noch nicht tot!");
					}
					break;
	
				case "restart":
					Character restart = new Character();
					Euler = restart;
					iObjects = new ArrayList<String>();
					iDeleteContent();
					setExitsContent("Korridor [corridor]");
					Tuna.setText(Euler.getLocation(0).getDescriptions()
							.getDefaultDescription());
					break;
	
				case "options":
					Options options = new Options(Tuna.this);
					options.setLocationRelativeTo(Tuna.this);
					options.setVisible(true);
					break;
	
				case "":
					break;
	
				default:
					if (soundAllowed) {
						java.awt.Toolkit.getDefaultToolkit().beep();
					}
				}
			}
		}
	}
	
	private class KeyHandler implements KeyListener {
		
		@Override
		public void keyPressed(KeyEvent e) {
			if (e.getKeyCode() == KeyEvent.VK_O) {
				Options options = new Options(Tuna.this);
				options.setLocationRelativeTo(Tuna.this);
				options.setVisible(true);
			} else if (e.getKeyCode() == KeyEvent.VK_I) {
				Inventar inventar = new Inventar(Tuna.this);
				inventar.setLocationRelativeTo(Tuna.this);
				inventar.setVisible(true);
			} else if (e.getKeyCode() == KeyEvent.VK_H) {
				Main.showHelp();
			}
		}
		
		public void keyReleased(KeyEvent e) {
			
		}
		
		public void keyTyped(KeyEvent e) {}
	}
	
	private class Options extends JDialog implements ActionListener,
			MouseListener { // JDIALOG (der Dialog für die Optionen [kaum
							// relevant für ein textbasiertes Spiel])

		private static final long serialVersionUID = -4174236644682504968L;
		// Auflösungen
		private GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
		private GraphicsDevice device = environment.getDefaultScreenDevice();
		private DisplayMode[] modes = device.getDisplayModes();
		private JPanel resolutionPanel;
		private JPanel languagePanel;
		private JPanel soundPanel;
		private JComboBox<?> choose;
		private JComboBox<?> language;
		private JComboBox<?> soundBox;
		private JPanel container;
		private JLabel output;
		private JLabel inventar;
		private JLabel exits;
		private JButton defaultColor;
		private JPanel jbuttons;
		private JButton quit;
		private JButton save;
		private int newWidth = Tuna.width;
		private int newHeight = Tuna.height;
		private boolean soundAllowed = Tuna.soundAllowed;
		private Color ausgabeColor = Tuna.ausgabe.getBackground();
		private Color inventarColor = Tuna.inventar.getBackground();
		private Color exitsColor = Tuna.exits.getBackground();

		public Options(Tuna frame) {
			super(frame);
			setTitle("Einstellungen");
			setResizable(false);
			setModal(true);
			setLayout(null);
			setSize(230, 400);

			// Auflösung
			resolutionPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
			resolutionPanel.setBounds(0, 20, 200, 50);
			add(resolutionPanel);

			JTextPane resolutionHeading = new JTextPane();
			resolutionHeading.setText("Auflösung:\t");
			resolutionHeading.setBackground(getContentPane().getBackground());
			resolutionHeading.setEditable(false);
			resolutionPanel.add(resolutionHeading);

			// Festlegen der Anzahl der Auflösungen
			int length = 0;
			for (int i = 0; i < modes.length; i++) {
				if (modes[i].getRefreshRate() == 60
						&& modes[i].getBitDepth() == modes[0].getBitDepth()
						&& modes[i].getHeight() != 999
						&& modes[i].getHeight() != 1050
						&& modes[i].getHeight() != 768
						&& modes[i].getWidth() >= 1000
						&& modes[i].getHeight() >= 600) {
					length++;
				}
			}
			String[] asd = new String[length + 1];

			// Erstellen des Strings mit den Auflösungen unter den Folgenden
			// Bedingungen: BitDepth == die der ersten im Array, 60Hz und
			// weiteren Auflösungen die rausgefiltert wurden
			int minusCounter = 0;
			for (int i = 1; i < modes.length; i++) {
				if (modes[i].getRefreshRate() == 60
						&& modes[i].getBitDepth() == modes[0].getBitDepth()
						&& modes[i].getHeight() != 999
						&& modes[i].getHeight() != 1050
						&& modes[i].getHeight() != 768
						&& modes[i].getWidth() >= 1000
						&& modes[i].getHeight() >= 600) {
					asd[i - minusCounter] = modes[i].getWidth() + "x"
							+ modes[i].getHeight() + " ";
				} else {
					minusCounter++;
				}
			}

			asd[0] = "1100x700 ";

			choose = new JComboBox<Object>(asd);
			choose.setSelectedIndex(Tuna.selectedItemResolution);
			choose.addActionListener(this);
			resolutionPanel.add(choose);

			// Sprache?
			languagePanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
			languagePanel.setBounds(0, 70, 200, 50);
			add(languagePanel);

			JTextPane languageHeading = new JTextPane();
			languageHeading.setText("Sprache:\t");
			languageHeading.setBackground(getContentPane().getBackground());
			languageHeading.setEditable(false);
			languagePanel.add(languageHeading);

			String[] languages = { "Deutsch", "Fraince" };
			language = new JComboBox<Object>(languages);
			language.setSelectedIndex(0);
			language.addActionListener(this);
			languagePanel.add(language);

			// Sound?
			soundPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
			soundPanel.setBounds(-8, 120, 200, 50);
			add(soundPanel);

			JTextPane soundHeading = new JTextPane();
			soundHeading.setText("Sound:\t");
			soundHeading.setBackground(getContentPane().getBackground());
			soundHeading.setEditable(false);
			soundPanel.add(soundHeading);

			String[] sound = { "Sound an", "Sound aus" };
			soundBox = new JComboBox<Object>(sound);
			if (soundAllowed) {
				soundBox.setSelectedIndex(0);
			} else {
				soundBox.setSelectedIndex(1);
			}
			soundBox.addActionListener(this);
			soundPanel.add(soundBox);

			// Farbe
			container = new JPanel(null);
			container.setBounds(35, 200, 150, 130);
			add(container);

			output = new JLabel("Ausgabe", SwingConstants.CENTER);
			output.setBounds(0, 0, 75, 100);
			output.setForeground(Color.WHITE);
			output.setBackground(ausgabeColor);
			output.setOpaque(true);
			output.setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2,
					Color.WHITE));
			output.addMouseListener(this);
			container.add(output);

			inventar = new JLabel("Inventar", SwingConstants.CENTER);
			inventar.setBounds(75, 0, 75, 50);
			inventar.setForeground(Color.WHITE);
			inventar.setBackground(inventarColor);
			inventar.setOpaque(true);
			inventar.setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2,
					Color.WHITE));
			inventar.addMouseListener(this);
			container.add(inventar);

			exits = new JLabel("Ausgänge", SwingConstants.CENTER);
			exits.setBounds(75, 50, 75, 50);
			exits.setForeground(Color.WHITE);
			exits.setBackground(exitsColor);
			exits.setOpaque(true);
			exits.setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2,
					Color.WHITE));
			exits.addMouseListener(this);
			container.add(exits);

			defaultColor = new JButton("Default");
			defaultColor.setBounds(25, 105, 100, 20);
			defaultColor.addActionListener(this);
			container.add(defaultColor);

			// JButtons
			jbuttons = new JPanel(null);
			jbuttons.setBounds(2, 340, 220, 30);
			add(jbuttons);

			quit = new JButton("Abbruch");
			quit.setBounds(0, 0, 109, 30);
			quit.addActionListener(this);
			jbuttons.add(quit);

			save = new JButton("Übernehmen");
			save.setBounds(111, 0, 109, 30);
			save.addActionListener(this);
			jbuttons.add(save);
		}

		@Override
		public void actionPerformed(ActionEvent event) {
			if (event.getSource() == language) {
				// Setzen der Sprache
				String s = (String) ((JComboBox<?>) event.getSource())
						.getSelectedItem();

				if (s.equalsIgnoreCase("deutsch")) {
					Tuna.setMessage("Diese Sprache ist bereits ausgewählt!");
				} else if (s.equalsIgnoreCase("fraince")) {
					Tuna.this.setVisible(false);
					new Fraince();
				}

			} else if (event.getSource() == choose) {
				/*
				 * Auflösung setzen Holen der JComboBox und setzen des
				 * selektierten Items
				 */
				JComboBox<?> cb = (JComboBox<?>) event.getSource();
				Tuna.selectedItemResolution = cb.getSelectedIndex();

				// Holen der Chars der Width und Height im ausgewählten String
				// der JComboBox cb
				String resolution = (String) cb.getSelectedItem();
				String sWidth = "";
				String sHeight = "";
				int tempI = 0;
				for (int i = 0; i < resolution.length(); i++) {
					if (resolution.charAt(i) == 120) {	// Ausführen bei Zeichen Zeichen x
						tempI = i + 1;					// Stelle, wo das Auslesen der Höhe beginnen soll
						for (int j = 0; j < i; j++) {
							sWidth += resolution.charAt(j); // Hinzufügen der Zeichen bis i (also bis x)
						}

					} else if (resolution.charAt(i) == 32) { // Ausführen beim Erreichen eines Leerzeichens (wurde beim Speichern der Auflösung im String extra hinzugefügt)
						for (int j = tempI; j < i; j++) {
							sHeight += resolution.charAt(j); // Hinzufügen der Zeichen bis i (also bis zum Leerzeichen)
						}
					}
				}

				// Speichern der geholten Informationen über width und height
				newWidth = Integer.parseInt(sWidth); // newWidth der Options auf den ausgewählten Wert setzen, damit der "save" JButton diesen speichern kann
				newHeight = Integer.parseInt(sHeight); // das gleiche bei der newHeight

			} else if (event.getSource() == soundBox) {
				String s = (String) ((JComboBox<?>) event.getSource()).getSelectedItem(); // Den String des angeklickten Items holen und in s speichern

				if (s.equalsIgnoreCase("sound an")) {
				this.soundAllowed = true; 							// soundAllowed der Options auf true setzen, damit der "save" JButton dies speichern kann
				soundBox.setSelectedIndex(0); 						// Welches Item zu sehen ist
				} else if (s.equalsIgnoreCase("sound aus")) {
				this.soundAllowed = false; 							// soundAllowed der Options auf false setzen, damit der "save" JButton dies speichern kann
				soundBox.setSelectedIndex(1); 						// Welches Item zu sehen ist
				}

			} else if (event.getSource() == defaultColor) {
				// Farben auf Standard setzen
				ausgabeColor = Color.DARK_GRAY;
				inventarColor = new Color(0x602600);
				exitsColor = new Color(0xA03500);
				output.setBackground(Color.DARK_GRAY);
				inventar.setBackground(new Color(0x602600));
				exits.setBackground(new Color(0xA03500));

			} else if (event.getSource() == save) {			// DER ÜBERNEHMEN BUTTON
				// Farben übernehmen und in der Tuna speichern
				Tuna.ausgabeColor = ausgabeColor;
				Tuna.inventarColor = inventarColor;
				Tuna.exitsColor = exitsColor;
				Tuna.ausgabe.setBackground(ausgabeColor);
				Tuna.inventar.setBackground(inventarColor);
				Tuna.iContent.setBackground(inventarColor);
				Tuna.exits.setBackground(exitsColor);
				Tuna.eContent.setBackground(exitsColor);

				// Auflösung übernehmen
				System.out.println(newWidth + "x" + newHeight);
				Tuna.height = newHeight;
				Tuna.width = newWidth;
				setSizeRelative();
				Tuna.this.setLocationRelativeTo(null);

				// Sound übernehmen
				Tuna.soundAllowed = this.soundAllowed;

				Main.saveConf(); 			// Neue Daten per Serialisierung in die doc/.config speichern.
				this.dispose(); 			// Schließen der Optionen, da vermutet wird, dass der Benutzer fertig mit dem Einstellen der Optionen ist.
			} else if (event.getSource() == quit) {
				this.dispose();
			}
		}

		@Override
		public void mouseClicked(MouseEvent me) {
			JLabel ziel = (JLabel) me.getSource();
			// Farbauswahlfenster anzeigen dem die aktuelle Farbe des
			// angeklickten JLabels übergeben wird. Die neu ausgewählte Farbe
			// wird in newColor gespeichert.
			Color newColor = JColorChooser.showDialog(this,
					"Choose your color!", ziel.getBackground());
			// Setzen der Hintergrundfarbe des angeklickten JLabels
			ziel.setBackground(newColor);
			// Speichern der entsprechenden Farbe in der Options-Klasse
			if (ziel == output) {
				ausgabeColor = newColor;
			} else if (ziel == inventar) {
				inventarColor = newColor;
			} else if (ziel == exits) {
				exitsColor = newColor;
			}

		}

		@Override
		public void mouseEntered(MouseEvent me) {
			((JLabel) me.getSource()).setBorder(BorderFactory
					.createMatteBorder(2, 2, 2, 2, Color.BLACK)); // Hovern
		}

		@Override
		public void mouseExited(MouseEvent me) {
			((JLabel) me.getSource()).setBorder(BorderFactory
					.createMatteBorder(2, 2, 2, 2, Color.WHITE)); // Hovern
		}

		@Override
		public void mousePressed(MouseEvent arg0) {
		}

		@Override
		public void mouseReleased(MouseEvent arg0) {
		}
	}
	
	private class Inventar extends JDialog {
		
		private static final long serialVersionUID = -5715973264254585818L;

		public Inventar(Tuna frame) {
			super(frame);
			setTitle("Inventar");
			setResizable(false);
			setModal(true);
			setLayout(null);
			setSize(230, 400);
			
		}
	}
	/*************************** ENDE INTERNE KLASSEN/LISTENER ******************************/
	
	
	
	
	/*************************** ANFANG GETTER/SETTER METHODEN ******************************/
	public static boolean isSoundAllowed() {
		return soundAllowed;
	}
	public static void setSoundAllowed(boolean soundAllowed) {
		Tuna.soundAllowed = soundAllowed;
	}
	public static Character getEuler() {
		return Euler;
	}
	public static void setEuler(Character character) {
		Euler = character;
	}
	public static void setExitsContent(String text) {
		eContent.setText(text);
	}
	public static String getExitsContent() {
		return eContent.getText();
	}
	public static void addText(String text) {
		ausgabe.setText(ausgabe.getText() + "\n> " + text);
	}
	public static void setText(String text) {
		ausgabe.setText(text + "\n");
	}
	public static void setMessage(String text) {
		message.setText(text);
	}
	public static int getWindowWidth() {
		return width;
	}
	public static void setWindowWidth(int width) {
		Tuna.width = width;
	}
	public static int getWindowHeight() {
		return height;
	}
	public static void setWindowHeight(int height) {
		Tuna.height = height;
	}
	public static int getSelectedItemResolution() {
		return selectedItemResolution;
	}
	public static void setSelectedItemResolution(int selectedItemResolution) {
		Tuna.selectedItemResolution = selectedItemResolution;
	}
	public static Color getAusgabeColor() {
		return ausgabeColor;
	}
	public static void setAusgabeColor(Color ausgabeColor) {
		Tuna.ausgabeColor = ausgabeColor;
	}
	public static Color getInventarColor() {
		return inventarColor;
	}
	public static void setInventarColor(Color inventarColor) {
		Tuna.inventarColor = inventarColor;
	}
	public static Color getExitsColor() {
		return exitsColor;
	}
	public static void setExitsColor(Color exitsColor) {
		Tuna.exitsColor = exitsColor;
	}
	public static ArrayList<String> getiObjects() {
		return iObjects;
	}
	public static void setiContent(String text) {
		Tuna.iContent.setText(text);
	}
	public static void setiObjects(ArrayList<String> iObjects) {
		Tuna.iObjects = iObjects;
	}
	/**************************** ENDE GETTER/SETTER METHODEN *******************************/
}