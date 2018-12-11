


public class Character{
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private int currentLocation = 0;
	private int lastLocation = 0;
	private int deathAmount = 0;
	private boolean death = false;
	private boolean beam = false;
	private int amountNotes = 0;
	private boolean lockerQuestion = false;
	private boolean battle = false;
	private boolean battleArt;
	private Location[] location;
	private boolean inQuiz = false;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public Character() {
		location = new Location[21];
		
		/***********************ERSTELLEN DER R�UME***************************************/
		location[0] = new Location("B�ro", "In deinem B�ro ist mittig ein �berf�llter Schreibtisch [desk] an dem ein Scott Chefsessel mit original Kunstleder im Wert von 500� "
				+ "steht [chair]. Au�erdem stehen zwei Schr�nke in jeweils einer Ecke des Raumes.");
		location[1] = new Location("Korridor 2 Etage", "Im Korridor angekommen siehst du mehrere R�ume.");
		location[2] = new Location("Kaffeeraum", "Dies ist der Kaffee- und Kuchenraum der Lehrer."
				+ "\nDu siehst eine neumodische Ikea K�che, mit vielen K�chenschr�nken [cupboards] auf denen eine uralte verrostete vermutlich aus dem "
				+ "1. Weltkrieg stammende Kaffeemaschine [coffeemachine] und eine Mikrowelle steht!");
		location[3] = new Location("Konferenzraum", "In diesem Raum werden Konferenzen zu wichtigen Themen abgehalten und unwichtigen, aber die betreffen dich ja eh nicht!"
				+ "\nEinem Konferenzraum entsprechend befindet sich in der Mitte ein Tisch in der Form eines U's. Au�erdem h�ngt an der Wand ein "
				+ "Stundenplan und ein Schrank mit den F�chern f�r die Lehrer.");
		location[4] = new Location("Kammer der Leere", "Dieser Raum sieht aus als wenn hier seit Jahren niemand mehr drin gewesen w�re.", false);
		location[5] = new Location("Ventilationraum", "Ein Ventilationsraum. Alt, veranzt und staubig. Gel�ftet wurde hier schon seit Jahren nicht mehr!", false);
		location[6] = new Location("Damentoilette", "In der Damentoilette angekommen, sieht Kollegin Stelz dich irritiert an und geht mit den Worten: \"Sie �berraschen mich immer wieder\" raus."
				+ "\nBeschreibung: Warst du noch nie in einer Damentoilette?");
		location[7] = new Location("Herrentoilette", "Als du die Herrentoilette betrittst, weht dir ein animalischer Duft entgegen, welchen du dem ebenfalls \"leicht\" animalischen Direktor zuordnest!");
		location[8] = new Location("Schulleiterraum", "Das B�ro des Direktors ist �hnlich wie deines, �ber den verm�llten Schreibtisch schaut dich ein grimmiger Haufen Kalorien an. Dies m�sste "
				+ "deiner mathematisch hoch komplexen �berlegungen nach der Direktor sein.");
		location[9] = new Location("Fahrstuhl", "An einer der blank geputzten grauen Fahrstuhlw�nde steht:\"Im Brandfall nicht benutzbar!\".");
		location[10] = new Location("Treppenhaus", "Ein Treppenhaus...     es brennt!");
		location[11] = new Location("Korridor 1 Etage", "Ein langer Korridor..."
				+ "\nAn ihm liegen vier vom Aufbau her identische H�rs�le, jedoch geh�rt der erste den musischen Wissenschaften, der "
				+ "zweite zu den literarischen, der dritte zu den gesellschaftlichen und als letztes kommt endlich der naturwissenschaftliche H�rsal.", false);
		location[12] = new Location("H�rsaal 1", "Man darf sich bekanntlich nicht mehr fragen, ob musische Wissenschaften �berhaupt als eine Wissenschaft gelten, da K�nstler und Freidenker "
				+ "sich sonst angegriffen f�hlen, aber ein Naturwissenschaftler wie du hat wohl besseres verdient!");
		location[13] = new Location("Spindraum", "Modrig steigt der Geruch ranziger K�sebrote durch die L�ftungsschlitze einiger Schlie�f�cher, welche jedoch alle durch Algen in einem sch�nen "
				+ "Armee-Gr�nton gehalten werden. Alle? Nein, nicht alle! Eine glanzpolierte Marmorvariante, die dem Hausmeister geh�rt, koexistiert tats�chlich noch in diesem Raum.");
		location[14] = new Location("Abstellraum", "Ein Mob, ein Eimer, ein Feuchttuch.... dich verwundert es, wie der Hausmeister nur mit diesen Sachen zumindest sein Revier so poliert");
		location[15] = new Location("H�rsaal 2", "Im vorderen Teil liest der Professor aus einem Buch einen Text in einer Sprache, die du nicht verstehst, w�hrend im hinteren Teil sich Sch�ler "
				+ "mit K�sek�stchen, Schere-Stein-Papier und Battlefield die Zeit vertreiben.");
		location[16] = new Location("H�rsaal 3", "Der Lehrende zeigt aufgeregt auf eine Karte, welchen Schwerpunkt diese Vorlesung auch immer hat, eine Karte macht alles spannender! "
				+ "Sein Gegenspieler gewinnt in dem Pokerduell und jubelt laut auf!");
		location[17] = new Location("H�rsaal 4", "Dein Reich ist gerade von einem Chemieprofessor belegt. Dieser ist grade dabei mit peinlicher Sorgfalt den Tisch in alle vier "
				+ "Himmelsrichtungen gleichzeitig zu katapultieren!");
		location[18] = new Location("Damentoilette", "Es riecht herrlich nach Einhorn und Regenbogen, und nach dem alkohoisierten Hausmeister, der dabei ist den Lippenstift vom Spiegel zu "
				+ "entfernen und dich nicht bemerkt.");
		location[19] = new Location("Herrentoilette", "Das Putzfrauenspecialcorps hat sich gestern zur Aufgabe gemacht den gr�nen Schleim von der Wand zu entfernen... "
				+ "Nur noch ein wenig Neutralreiniger auf dem Boden und eine Cap, mit dem Wort \"Obey\", schaukelnd an einer Lampe, sind noch �brig geblieben.");
		location[20] = new Location("Fahrstuhlschacht", "Im Raum angekommen f�llt dir sofort die ganze Elektronik hier unten auf. Ob hier noch mehr ist?", false);
		
		
		
		/*************************BESCHREIBUNG BEIM EXPLOREN******************************/
		location[0].getDescriptions().setExploreDescription("Das B�ro ist nicht besonders gro�, aber du bist trotzdem stolz auf deinen Chefsessel. Au�erdem steht eine Vitrine in dem "
				+ "Raum, in der deine Preise und Troph�en stehen.");
		location[1].getDescriptions().setExploreDescription("Was willst du wissen? Es ist nur ein typischer langweiliger Korridor, mit einem Kaffeel�scherkasten [extinguisher box], wie man's in Uni's gewohnt ist!");
		location[2].getDescriptions().setExploreDescription("Du fragst dich, was in den ganzen K�chenschr�nken [cupboards] sein k�nnte und warum der Boden hier h�her ist!");
		location[3].getDescriptions().setExploreDescription("Die Lehrer starren dich aus gro�en Augen an. Du bist wohl mitten in eine Versammlung reingeplatzt. Kann dir auch egal sein, "
				+ "ist keine Konferenz von der du wei�t. Dir f�llt der Ventilationsschacht [ventilation shaft] auf, bei dem das Gitter nur noch an den Schacht gelehnt ist.");
		location[4].getDescriptions().setExploreDescription("Du siehst eine deiner Notizen [note] zwischen zwei Kartons gequetscht. Keine Ahnung wie der Windsto� das verursachen konnte...");
		location[5].getDescriptions().setExploreDescription("Du siehst eine deiner Notizen [note].");
		location[6].getDescriptions().setExploreDescription("Jetzt blo� nicht sp�len. Es sei denn du magst keine Skillbooks... [skillbook]. Bei diesem Skillbook scheinst du eine Beamf�higkeit "
				+ "erlernen zu k�nnen.");
		location[7].getDescriptions().setExploreDescription("Der Geruch ist wirklich unertr�glich. Lange wirst du es hier nicht mehr aushalten k�nnen.");
		location[8].getDescriptions().setExploreDescription("Meisterhaft in Inneneinrichtung hat der Direktor hier einen braunen Tisch, zwei graue St�hle und eine Ansammlung von an Krawatten erh�ngten Skelette.\nEr ist damit besch�ftigt, Frederic Chopin's neunte Death Metal Komposition zu h�ren.");
		location[9].getDescriptions().setExploreDescription("Erst jetzt f�llt dir der Gully [gully] auf dem Boden auf. Wo der wohl hinf�hrt...\n"
				+ "Um das herauszufinden wirst du definitiv so etwas wie einen Hebel ben�tigen."
				+ "\nDie Feueraxt [fire ax] ist dir eigentlich schon vorher aufgefallen, doch vielleicht wird sie jetzt wichtig?");
		location[10].getDescriptions().setExploreDescription("Das Feuer ist echt frech! Es blockiert dir doch tats�chlich den Weg in den ersten Stock [floor 1].");
		location[11].getDescriptions().setExploreDescription("Grau.Und unspektakul�r. Der M�lleimer muss unbedingt mal geleert werden.");
		location[12].getDescriptions().setExploreDescription("Der Professor liegt in ziemlich bizarren Posen auf dem Tisch und erkl�rt den Studenten(und Studentinnen), welche Pose welche Wirkung hat."
				+ "\nDu kannst das Geld, dass f�r jede Pose gazahlt wird, f�rmlich von dem Direktor in die Tasche des Professors wandern sehen.\nHier steht noch Maribelle [student], obwohl sie wesentlich kleiner ist, schaut sie hochn�sig auf dich herab.");
		location[13].getDescriptions().setExploreDescription("So viele Schlie�f�cher [locker], und alle sind nummeriert. Verhindert wird jedoch eine genaue Identifikation des Hausmeisterfaches [shiny locker], da die Nummer wegpoliert wurde.");
		location[14].getDescriptions().setExploreDescription("Dir f�llt ein Spachtel [spatula] auf, der eindeutig aus der Chemiesammlung genommen wurde. Hol zur�ck, was dir geh�rt!");
		location[15].getDescriptions().setExploreDescription("Schon wieder eine Runde 4-1 KD, der Sch�ler ist wirklich gut darin, Minen im richtigen Moment hochzujagen. Der Professer liest weiterhin monoton aus dem Buch vor."
				+ "\nJochen [student] ist so gelangweilt, dass er deinen Schritten Aufmerksamkeit schenkt.");
		location[16].getDescriptions().setExploreDescription("Alle Studierenden sind inzwischen wieder drin, w�hrend der Professor eine Runde in der Ecke schmollt."
				+ "\nOh-oh, da kommt Anthon [student]");
		location[17].getDescriptions().setExploreDescription("Die Frau braucht wieder einmal zu lange, du musst den Vortrag wohl beginnen, w�hrend sie noch Chemikalien mischt."
				+ "\nGerhard [student], dein pers�hnlicher Fanboy, starrt dich mit gro�en Augen an.");
		location[18].getDescriptions().setExploreDescription("Es ist ein Graus, Steven hat sich von Rebecca getrennt, und Gr�n ist das neue Schwarz, zumindest nach den Tratschtanten auf dem Klo.");
		location[19].getDescriptions().setExploreDescription("Der Schleim hei�t Wilhelm von Kaiser [wilhelm] und verkauft w�hrend der Pausen Katzenbabys f�r diejenigen in Not, ein sehr angenehmer Geselle.");
		location[20].getDescriptions().setExploreDescription("Hier liegt eine Kaffeetasse mit, wer h�tte es gedacht, hei�em Kaffee [cup coffee] drin.");
		
		
		/******************BESCHREIBUNG F�R BEREITS UNTERSUCHTE R�UME*********************/
		location[0].getDescriptions().setAlreadyExploredDescription("Der Raum ist nicht besonders gro�, aber auf deinen Chefsessel bist du trotzdem stolz und nat�rlich auf deine Preis und Troph�en "
				+ "in deiner Vitrine.");
		location[1].getDescriptions().setAlreadyExploredDescription("Ein typischer Korridor mit einem Kaffeel�scherkasten [extinguisher box]. Ist halt 'ne Uni!");
		location[2].getDescriptions().setAlreadyExploredDescription("Wei�t du noch als du dich gefragt hast was in den ganzen K�chenschr�nken sein k�nnte und warum der Boden hier h�her ist?");
		location[3].getDescriptions().setAlreadyExploredDescription("Die Konferenz wird wohl nie zu Ende gehen. Der Ventilationssacht [ventilation shaft] ist auch echt auff�llig.");
		location[4].getDescriptions().setAlreadyExploredDescription("Eine deiner Notiz [note] liegt zwischen zwei Kartons.");
		location[5].getDescriptions().setAlreadyExploredDescription("Aber immerhin liegt hier eine deiner Notizen");
		location[6].getDescriptions().setAlreadyExploredDescription("Naja, hier liegt halt noch ein Skillbook [skillbook].");
		location[7].getDescriptions().setAlreadyExploredDescription("Der Geruch ist wirklich unertr�glich. Lange wirst du es hier nicht mehr aushalten k�nnen.");
		location[8].getDescriptions().setAlreadyExploredDescription("Der Direktor h�rt noch immer laute Musik von Frederic Chopin.");
		location[9].getDescriptions().setAlreadyExploredDescription("Auch ein Gullideckel ist hier noch. #normal");
		location[10].getDescriptions().setAlreadyExploredDescription("Das Feuer blockiert dir immer noch den Weg in den ersten Stock [floor 1]!");
		location[11].getDescriptions().setAlreadyExploredDescription("Grau. Und unspektakul�r.");
		location[12].getDescriptions().setAlreadyExploredDescription("Maribelle [student] stolziert hier immer noch herum.");
		location[13].getDescriptions().setAlreadyExploredDescription("Jedoch sind sowohl die Normalen [locker] als auch der Besondere [shiny locker] relativ uninteressant.");
		location[14].getDescriptions().setAlreadyExploredDescription("Hier liegt ein Spachtel [spatula], der eindeutig aus der Chemiesammlung genommen wurde.");
		location[15].getDescriptions().setAlreadyExploredDescription("Der Professer liest noch immer aus dem Buch vor, w�hrend dir Jochen noch immer hinterher starrt.");
		location[16].getDescriptions().setAlreadyExploredDescription("Anthon [student] bemerkt dich sofort, als du den Raum betrittst.");
		location[17].getDescriptions().setAlreadyExploredDescription("Gerhards Blick bleibt sofort auf dir haften, als du in Raum gehst.");
		location[18].getDescriptions().setAlreadyExploredDescription("Die Tratschtanten reden noch immer.");
		location[19].getDescriptions().setAlreadyExploredDescription("Wilhelm von Kaiser [wilhelm] schleimt noch immer hier rum.");
		
		
		/****************************AUSG�NGE*********************************************/
		location[0].setExits("Korridor [corridor]");
		location[1].setExits("B�ro [office]" + "\nKaffeeraum [coffeeroom]" + "\nKonferenzraum [conference room]" + "\nSchulleiterraum [principalsroom]"
							+ "\nHerrentoilette [gentlemenstoilet]" + "\nTreppenhaus [stairwell]" + "\nFahrstuhl [elevator]");
		location[2].setExits("Korridor [corridor]" + "\nKonferenzraum [conference room]");
		location[3].setExits("Korridor [corridor]" + "\nKaffeeraum [coffeeroom]");
		location[4].setExits("Kaffeeraum [coffeeroom]");
		location[5].setExits("Konferenzraum [conference room]");
		for (int i = 6; i < 10; i++) {
			location[i].setExits("Korridor [corridor]");
		}
		location[10].setExits("Lehreretage [floor 2]" + "\nSch�leretage [floor 1]");
		location[11].setExits("H�rsaal <1-4> [lecture hall <1-4>]" + "\nSpindraum [lockerroom]" + "\nAbstellraum [storeroom]" + "\nDamentoilette [ladiestoilet]"
								+ "\nHerrentoilette [gentlemenstoilet]" + "\nFahrstuhl [elevator]" + "\nTreppenhaus [stairwell]");
		for (int i = 12; i <= 19; i++) {		// Die restlichen R�ume haben anfangs alle den Korridor als einzigen Ausgang
			location[i].setExits("Korridor [corridor]");
		}
		
		
		
		
		/**********************ERSTELLEN VON GEGENST�NDEN*********************************/
		location[0].createItem(0, "Schrank", 0, 000);							// wird nie benutzt oder erw�hnt TODO
		location[0].createItem(1, "Stuhl", 0, 001);
		location[0].createItem(2, "Schreibtisch", 0, 002);
		location[0].createItem(3, "R�tsell�sung", 0, 003, false);
		location[1].createItem(0, "Kaffeel�scherkasten", 1, 100, false);
		location[1].createItem(1, "Kaffeel�scher", 1, 101, false);
		location[2].createItem(0, "Kaffeemaschine", 2, 200);
		location[2].createItem(1, "K�chenschr�nke", 2, 201);
		location[3].createItem(0, "L�ftungsschacht", 3, 300, false);
		location[4].createItem(0, "Notiz", 4, 400, false);
		location[5].createItem(0, "Notiz", 5, 500, false);
		location[6].createItem(0, "Skillbook", 6, 600, false);
		location[9].createItem(0, "Feueraxt", 9, 900);
		location[9].createItem(1, "Gulli", 9, 901, false);
		location[13].createItem(0, "Notiz", 13, 1300, false);
		location[13].createItem(1, "Spind 42", 13, 1301, false);
		location[14].createItem(0, "Spachtel", 14, 1400, false);
		location[19].createItem(0, "Notiz", 19, 1900);
		location[20].createItem(0, "Kaffeetasse", 20, 2000, false);
		
		
		/***********************BESCHREIBUNGEN DER GEGENST�NDE****************************/
		location[0].getItemByName("Schrank").setDescription("Funzt >> desSchrank!");
		location[0].getItemByName("Stuhl").setDescription("Ein Scott Chefsessel aus original Kunstleder im Wert von 500�, der nur dir geh�rt.");
		location[0].getItemByName("Schreibtisch").setDescription("Dieser Schreibtisch braucht eine neue Lackierung. Achso, und ein Putzkommando!"
				+ "\nTrotz der Unordnung f�llt dir ein vollgekritzeltes Papier [paper] auf, auf dem du dein letztes Meisterwerk, das Ergebnis der unendlichen Summe, niedergeschrieben hast!");
		location[0].getItemByName("R�tsell�sung").setDescription("Du hast hier die Summe der Unendlichkeit errechnet. Sie lautet -1/12!");
		location[1].getItemByName("Kaffeel�scherkasten").setDescription("Dieser Kasten beinhaltet einen Kaffeel�scher [coffee extinguisher], dieser ist der (un)nat�rlichste Bestandteil einer Feuerwehrausr�stung! "
				+ "Der Kasten ist durch ein elektronisches Sicherheitsschloss gesichert!");
		location[1].getItemByName("Kaffeel�scher").setDescription("Ein Feuerl�scher mit komisch riechendem Kaffee gef�llt.");
		location[2].getItemByName("Kaffeemaschine").setDescription("Eine hochwertig billige Kaffeemaschine. Die nicht funktoniert, irgendwer muss wohl das Stromkabel rausgezogen haben.");
		location[2].getItemByName("K�chenschr�nke").setDescription("Unter einem der Schr�nke ist ein Hohlraum, welcher unter dem ganzen Kaffeeraum hindurch f�hrt zu einem"
				+ "\ngeheimen Raum [chamber].");
		location[3].getItemByName("L�ftungsschacht").setDescription("Du entdeckst einen Geheimraum [ventilationroom].");
		location[4].getItemByName("Notiz").setDescription("Funzt >> desNotiz4!");
		location[5].getItemByName("Notiz").setDescription("Funzt >> desNotiz5!");
		location[6].getItemByName("Skillbook").setDescription("Dies ist das verstaubte Skillbook des toten Beammeisters.");
		location[9].getItemByName("Feueraxt").setDescription("Es ist eine Feueraxt!");
		location[9].getItemByName("Gulli").setDescription("Ein Gullideckel... er ist eckig, er ist halt auch ein Individuum."
				+ "\nDu brauchst irgendeinen Trick um den Gullideckel anheben zu k�nnen.");
		location[14].getItemByName("Spachtel").setDescription("Du wolltest ihn eigentlich der Chemiesammlung wiedergeben, aber er gl�nzt so sch�n.");
		location[20].getItemByName("Kaffeetasse").setDescription("Frischer Kaffee... Yammy");
		
		
		/**********************BESCHREIBUNGEN BEIM INTERAGIEREN***************************/
		location[0].getItemByName("Stuhl").setInteractDescription("Du setzt dich auf deinen Stuhl."
				+ "\nEs macht knack und du sitzt auf'm Boden... Das Steak zum Fr�hst�ck war wohl doch zu viel.");
		location[1].getItemByName("Kaffeel�scherkasten").setInteractDescription("Das kannst du nicht machen. Das elektronische Sicherheitsschloss will das nicht! "
				+ "Ob du einen Weg findest es zu bezwingen?");
		location[1].getItemByName("Kaffeel�scher").setInteractDescription("Jetzt bist du ein wahrer Feuerwehrmann.... Naja, nicht ganz, aber fast.");
		location[2].getItemByName("Kaffeemaschine").setInteractDescription("Du willst den Stecker in die Steckdose stecken, aber die Steckdose will das nun halt nicht und gibt dir deswegen einen t�dlichen Stromschlag.");
		location[6].getItemByName("Skillbook").setInteractDescription("Du kannst dich nun beamen!");
		location[9].getItemByName("Feueraxt").setInteractDescription("Diese Axt geh�rt zur Grundausstattung eines Feuerbek�mpfers.");
		location[20].getItemByName("Kaffeetasse").setInteractDescription("Bei dem Versuch die Kaffeetasse hochzuheben, schmei�t du sie um, wodurch du einen sch�nen Kurzschluss verursachst."
				+ "Wenn du Gl�ck hast, hast du nur dich damit get�tet und nicht gleich die ganze Welt!");
		
		
		
		/*************************ERSTELLEN DER STUDENTEN*********************************/
		location[12].createStudent("Maribelle", 12);
		location[15].createStudent("Jochen", 15);
		location[16].createStudent("Anthon", 16);
		location[17].createStudent("Gerhard", 17);
		
		/****************************SETZEN DER FRAGE*************************************/
		location[12].getStudent().setQuestionText("Ahh, Sie lassen sich also hier blicken, Herr Euler! Beantworten sie mir doch, wie Chopin mit Vornamen hie�.");
		location[15].getStudent().setQuestionText("Greetings Mate! Is english DLC working right know?");
		location[16].getStudent().setQuestionText("Ehehe Euler, was sind Dreipacken minus Zweipacken?");
		location[17].getStudent().setQuestionText("Moin Euler, sagen Sie doch mal Ihre Summe des Unendlichen!");
		
		
		/***************************SETZEN DER ANTWORT************************************/
		location[12].getStudent().setAnswerText("Frederic");
		location[15].getStudent().setAnswerText("No");
		location[16].getStudent().setAnswerText("Einpacken");
		location[17].getStudent().setAnswerText("-1/12");
		
		/******************SETZEN DES HINWEISES AUF DIE NOTIZEN***************************/
		location[12].getStudent().setHint("Ahh, woher wissen Sie denn das. Als ich das letzte Mal im Konferenzraum war, war die Luft so stickig!\nJemand m�sste mal den L�ftungsschacht untersuchen.");
		location[15].getStudent().setHint("Oh, I see. Do you think locker 42 is somewhat special? Because I do think so!");
		location[16].getStudent().setHint("Ihihi, f�rchte dich vor Kaffe, der ist T�dlich!");
		location[17].getStudent().setHint("Boah, darauf w�re ich nicht gekommen!\nWissen Sie, warum der Boden im Kaffeeraum so hoch ist? Na, egal...");
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
	
	
	
	/*******************************ANFANG METHODEN****************************************/
	public void changeLocation(int newLocation) {												// Methode zum Raum wechseln. �bergeben wird der neue Standort
		if(!battle && !death) {
			boolean positionChange = false;
			this.lockerQuestion = false;			 											// Abbruch des Minievents
			
			switch (newLocation) {

			// B�ro
			case 0:
				if (currentLocation == 1 || currentLocation == 0 || beam) {
					if (currentLocation == 0) { Tuna.setMessage("Du bist schon in deinem B�ro!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Location setzen
						this.currentLocation = 0;
						
						Tuna.setText("Du gehst in dein B�ro.");			// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// Korridor
			case 1:
				if (currentLocation == 0 || currentLocation == 1 || currentLocation == 2 || currentLocation == 3 || currentLocation == 6 || currentLocation == 7 || currentLocation == 8
						|| currentLocation == 9 || currentLocation == 10 || beam) {
					if (currentLocation == 1) { Tuna.setMessage("Du bist schon im Korridor!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 1;
						
						Tuna.setText("Du gehst in den Korridor.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// T�dlicher Kaffeeraum
			case 2:
				if (currentLocation == 1 || currentLocation == 2 || currentLocation == 3 || currentLocation == 4 || beam) {
					if (currentLocation == 2) { Tuna.setMessage("Du bist schon im Kafferaum!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 2;
						
						Tuna.setText("Du gehst in den Kaffeeraum.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// Konferenzraum
			case 3:
				if (currentLocation == 1 || currentLocation == 2 || currentLocation == 3 || currentLocation == 4 || currentLocation == 5 || beam) {
					if (currentLocation == 3) { Tuna.setMessage("Du bist schon im Konferenzraum!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 3;
						
						Tuna.setText("Du gehst in den Konferenzraum.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// Kammer der Leere
			case 4:
				if (location[4].isVisible()) {
					if (currentLocation == 2 || currentLocation == 4 || beam) {
						if (currentLocation == 4) { Tuna.setMessage("Du bist schon in der Kammer der Leere!");
						} else {
							positionChange = true;							// Positionswechsel ist m�glich
							this.lastLocation = this.currentLocation;		// Locations setzen
							this.currentLocation = 4;
							
							Tuna.setText("Du gehst in die Kammer der Leere.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
						}
					} else {
						Tuna.setMessage("Du hast noch keine Beamfunktion!");
					}
				} else {
					beep();
				}
				break;
	
			// Ventilationsraum
			case 5:
				if (location[5].isVisible()) {
					if (currentLocation == 3 || currentLocation == 5 || beam) {
						if (currentLocation == 5) { Tuna.setMessage("Du bist schon im Ventilationsraum!");
						} else {
							positionChange = true;							// Positionswechsel ist m�glich
							this.lastLocation = this.currentLocation;		// Locations setzen
							this.currentLocation = 5;
							
							Tuna.setText("Du gehst in den Ventilationsraum.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
						}
					} else {
						Tuna.setMessage("Du hast noch keine Beamfunktion!");
					}
				} else {
					beep();
				}
				break;
	
			// Damen Toiletten
			case 6:
				if (currentLocation == 1 || currentLocation == 6 || beam) {
					if (currentLocation == 6) { Tuna.setMessage("Du bist schon in der Damentoilette!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 6;
						
						Tuna.setText("Du gehst in die Damentoilette.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
						location[6].getDescriptions().setDefaultDescription("Dies ist die Damentoilette."
								+ "\nDu fragst dich, ob du einen bestimmten Grund hast, hier zu sein, oder einfach die T�r verwechselt hast.");
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// Herren Toiletten
			case 7:
				if (currentLocation == 1 || currentLocation == 7 || beam) {
					if (currentLocation == 7) { Tuna.setMessage("Du bist schon in der Herrentoilette!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 7;
						
						Tuna.setText("Du gehst in die Herrentoilette.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
	
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// Schulleiterzimmer
			case 8:
				if (currentLocation == 1 || currentLocation == 8 || beam) {
					if (currentLocation == 8) { Tuna.setMessage("Du bist schon im Schulleiterzimmer!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 8;
						
						Tuna.setText("Du gehst in das Schulleiterzimmer.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
	
			// Fahrstuhl
			case 9:
				if (currentLocation == 1 || currentLocation == 9 || beam) {
					if (currentLocation == 9) { Tuna.setMessage("Du bist schon im Fahrstuhl!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 9;
						
						Tuna.setText("Du gehst in den Fahrstuhl.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
				
			// Treppenhaus
			case 10:
				if (currentLocation == 1 || currentLocation == 10 || currentLocation == 11 || beam) {
					if (currentLocation == 10) { Tuna.setMessage("Du bist schon im Treppenhaus!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 10;
						
						Tuna.setText("Du gehst in das Treppenhaus.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				}
				break;
			
			// Korridor Etage 1
			case 11:
				if (location[11].isVisible()) {
					if (currentLocation == 10 || currentLocation == 11 || currentLocation == 12 || currentLocation == 13 || currentLocation == 14 || currentLocation == 15 || currentLocation == 16 || currentLocation == 17 || currentLocation == 18 || currentLocation == 19 || beam) {
						if (currentLocation == 11) { Tuna.setMessage("Du bist schon im Korridor der 1 Etage!");
						} else {
							positionChange = true;							// Positionswechsel ist m�glich
							this.lastLocation = this.currentLocation;		// Locations setzen
							this.currentLocation = 11;
							
							Tuna.setText("Du gehst in den Korridor.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
						}
					} else {
						Tuna.setMessage("Du hast noch keine Beamfunktion!");
					}
				} else {
					Tuna.setText("Du bist am Feuer gestorben. Kaffee w�re spannender gewesen!"
							+ "\n\n\n<respawn>, um von vorne anzufangen!");
					death = true;
					if (amountNotes != 0) {
						Tuna.addText("\n\nDa du bereits Notizen eingesammelt hast, die jetzt verbrannt sind, solltest du das Spiel neu starten [restart].");
					}
				}
				break;
				
			// H�rsaal 1
			case 12:
				if ((currentLocation == 11 || currentLocation == 12 || beam) && location[11].isVisible()) {  // Wichtig, dass man bei vorhanden sein des Feuers sich nicht schon in die untere Etage beamen kann, auch f�r die n�chsten F�lle
					if (currentLocation == 12) { Tuna.setMessage("Du bist schon in H�rsaal 1!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;
						this.currentLocation = 12;
						
						Tuna.setText("Du gehst in den H�rsal 1");
						
						
					}
					
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				
			// Spindraum
			case 13:
				if ((currentLocation == 11 || currentLocation == 13 || beam) && location[11].isVisible()) {
					if (currentLocation == 13) { Tuna.setMessage("Du bist schon im Spindraum!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 13;
						
						Tuna.setText("Du gehst in den Spindraum.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
					
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
			
			// Abstellraum
			case 14:
				if ((currentLocation == 11 || currentLocation == 14 || beam) && location[11].isVisible()) {
					if (currentLocation == 14) { Tuna.setMessage("Du bist schon im Abstellraum!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 14;
						
						Tuna.setText("Du gehst in den Abstellraum.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
					
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				
			// H�rsaal 2
			case 15:
				if ((currentLocation == 11 || currentLocation == 15 || beam) && location[11].isVisible()) {
					if (currentLocation == 15) { Tuna.setMessage("Du bist schon in H�rsaal 2!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;
						this.currentLocation = 15;
						
						Tuna.setText("Du gehst in den H�rsal 2");
					}
					
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				
			// H�rsaal 3
			case 16:
				if ((currentLocation == 11 || currentLocation == 16 || beam) && location[11].isVisible()) {
					if (currentLocation == 16) { Tuna.setMessage("Du bist schon in H�rsaal 3!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;
						this.currentLocation = 16;
						
						Tuna.setText("Du gehst in den H�rsal 3");
					}
					
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				
			// H�rsaal 4
			case 17:
				if ((currentLocation == 11 || currentLocation == 17 || beam) && location[11].isVisible()) {
					if (currentLocation == 17) { Tuna.setMessage("Du bist schon in H�rsaal 4!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;
						this.currentLocation = 17;
						
						Tuna.setText("Du gehst in den H�rsal 4");
					}
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				
			// Damentoilette Etage 1
			case 18:
				if ((currentLocation == 11 || currentLocation == 18 || beam) && location[11].isVisible()) {
					if (currentLocation == 18) { Tuna.setMessage("Du bist schon in der Damentoilette!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 18;
						
						Tuna.setText("Du gehst in die Damentoilette.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				 
			// Herrentoilette Etage 1
			case 19:
				if ((currentLocation == 11 || currentLocation == 19 || beam) && location[11].isVisible()) {
					if (currentLocation == 19) { Tuna.setMessage("Du bist schon in der Herrentoilette!");
					} else {
						positionChange = true;							// Positionswechsel ist m�glich
						this.lastLocation = this.currentLocation;		// Locations setzen
						this.currentLocation = 19;
						
						Tuna.setText("Du gehst in die Herrentoilette.");		// Text zur�ck setzen mit Hinweis der aktuellen Position
					}
					
				} else if (location[11].isVisible()) {
					Tuna.setMessage("Du hast noch keine Beamfunktion!");
				} else if (!location[11].isVisible()) {					// Meldung, wenn das Feuer noch nicht gel�scht wurde
					Tuna.setMessage("Nene, so nicht!");
				}
				break;
				
			// Fahrstuhlschacht
			case 20:
				if (location[20].isVisible()) {
					if (currentLocation == 9 || currentLocation == 20 || beam) {
						if (currentLocation == 20) { Tuna.setMessage("Du bist schon im Fahrstuhlschacht!");
						} else {
							positionChange = true;							// Positionswechsel ist m�glich
							this.lastLocation = this.currentLocation;		// Locations setzen
							this.currentLocation = 20;
							Tuna.setText("Du kletterst den Gullideckel runter, obwohl, eigentlich f�llst du eher. Du kriegst es auch irgendwie hin, den Gullideckel �ber dir wieder zuzuschieben.");
							location[20].setVisible(false);					// Der Raum soll nicht wieder begehbar sein
						}
						
					} else {
						Tuna.setMessage("Du hast noch keine Beamfunktion!");
					}
				} else {
					beep();
				}
				break;
			}
			
			// Wenn der Positionswechsel auf wahr (also m�glich) gesetzt wurde soll folgendes gemacht
			if (positionChange) {
				// Ausg�nge setzen
				Tuna.setExitsContent(location[newLocation].getExits());
				
				// Beschreibungen
				if (!battle) {
					if (location[currentLocation].isExplored()) {
						Tuna.addText(location[currentLocation].getDescriptions().getAlreadyExploredDescription());
					} else {
						Tuna.addText(location[currentLocation].getDescriptions().getDefaultDescription());
					}
				}
			}
		
		} else if (battle) {
			Tuna.setMessage("Du befindest dich im Kampf!");
		} else if (death) {
			Tuna.setMessage("Du bist tot!");
		}
	}
	
	public void expLocation() {																	// Methode zum Untersuchen des aktuellen Standortes
		if (!death) {	// Geht nicht wenn Tod!
			
			// Beschreibungen anzeigen und boolean explored auf wahr setzen, au�er der Raum wurde bereits untersucht
			if (location[this.currentLocation].isExplored()) { Tuna.setMessage("Dieser Raum wurde bereits untersucht!");
			} else {
				Tuna.addText(location[this.currentLocation].getDescriptions().getExploreDescription());
				location[this.currentLocation].setExplored(true);
			}
			
			// Items an Stelle null im Item-Array des Standortes sichtbar machen
			if ((currentLocation > 0 && currentLocation < 7 && currentLocation != 2) || currentLocation == 20) {
				location[this.currentLocation].getItem(0).setVisible(true);
				/* Im Korridor (1) der Kaffeel�scherkasten
				 * Im Konferenzraum (3) der Ventilationsschacht
				 * In der Kammer der Leere (4) die Notiz
				 * Im Ventilationsraum (5) die Notiz
				 * In der Damentoilette (6) das Skillboook
				 * Im Fahrstuhlschacht (20) die Kaffeetasse
				 */
			}
			
			// Items an Stelle eins im Item-Array des Standortes sichtbar machen
			if (currentLocation == 9) {
				location[this.currentLocation].getItem(1).setVisible(true);
			}
		} else if (death) {
			Tuna.setMessage("Du bist tot!");
		}
	}

	public void interactObject(String object) {													// Methode zum Interagieren mit einem Gegenstand. �bergeben wird der Gegenstand
		if (!death) {
		switch (object) {	// 1.7 notwendig
		// Stuhl
		case "chair":
			if (currentLocation == 0) {
				Tuna.addText(location[0].getItem(1).getInteractDescription());
				location[0].getItem(1).setDescription("Du hast deinen wertvollsten Besitz zerst�rt.");
				location[0].getItem(1).setInteractDescription("Auf diesen \"Stuhl\" willst du dich lieber nicht hinsetzen.");
				location[0].getDescriptions().setDefaultDescription("In deinem B�ro ist mittig ein �berf�llter Schreibtisch [desk] an dem ein kaputter Scott Chefsessel mit original Kunstleder im Wert von"
						+ "\n500� steht [chair].Au�erdem stehen zwei Schr�nke in jeweils einer Ecke des Raumes.");
				location[0].getDescriptions().setExploreDescription("Das B�ro ist nicht besonders gro�, aber du warst stolz auf deinen Chefsessel. Au�erdem steht eine Vitrine in dem"
				+ "\nRaum, in der deine Preise und Troph�en stehen.");
				location[0].getDescriptions().setAlreadyExploredDescription("Der Raum ist nicht besonders gro�, aber auf deinen Chefsessel warst du stolz und auf deine Preis und Troph�en"
				+ "in deiner Vitrine bist du stolz. Auf die hast du dich ja schlie�lich noch nicht draufgesetzt!");
				location[0].setExplored(false); 						// So kann der Spieler den Raum nochmal untersuchen, da sich die Beschreibung ge�ndert hat
			} else {
				beep();
			}
			break;

		// Notizen
		case "note":
			if (currentLocation == 4 && location[4].getItem(0).isVisible() && !location[4].getItem(0).isCollected()) {
				Tuna.iAddContent("Notiz");
				location[4].getItem(0).setCollected(true);
				location[4].getDescriptions().setAlreadyExploredDescription("Die Notiz konntest du mit M�he den armen Kartons entreisen.");
				location[4].getDescriptions().setExploreDescription("Die Notiz konntest du mit M�he den armen Kartons entreisen.");
				new Thread(new Sound()).start(); 																								// Sound Thread
			} else if (currentLocation == 5 && location[5].getItem(0).isVisible() && !location[5].getItem(0).isCollected()) {
				Tuna.iAddContent("Notiz");
				location[5].getItem(0).setCollected(true);
				location[4].getDescriptions().setAlreadyExploredDescription("");
				new Thread(new Sound()).start();																								// Sound Thread
			} else if (currentLocation == 13 && location[13].getItem(0).isVisible() && !location[13].getItem(0).isCollected()) {
				Tuna.iAddContent("Notiz");
				location[13].getItem(0).setCollected(true);
				new Thread(new Sound()).start(); 																								// Sound Thread
			} else {
				beep();
			}
			break;

		// Kaffeemaschine
		case "coffeemachine":
			if (currentLocation == 2) {
				death = true;
				Tuna.addText(location[2].getItem(0).getInteractDescription() + "\n<respawn>");
				Tuna.setMessage("Du starbst den Kaffeetod!");
				location[2].getDescriptions().setExploreDescription("Ein K�chenschrank [cupboards]. Ne, ganz viele... was das wohl zu bedeuten hat. "
						+ "\nZudem liegt in einer Ecke ein Toter... er war anscheinend bei dem Versuch die Kaffeemaschine wieder einzustecken umgekommen."
						+ "Wie kann man nur so d�mlich sein, denkst du dir. Vielleicht kriegst du es ja besser hin?");
				location[2].getDescriptions().setAlreadyExploredDescription("Wei�t du noch als du dich gefragt hast was in den ganzen K�chenschr�nken sein k�nnte und warum der Boden hier h�her ist? "
						+ "\nDer Tote liegt hier immer noch...");
			} else {
				beep();
			}
			break;

		// Feueraxt
		case "fireax":
			if (currentLocation == 9 && !location[9].getItem(0).isCollected()) {
				Tuna.iAddContent("Feueraxt [fire ax]");
				location[9].getItem(0).setCollected(true);
				location[9].getDescriptions().setDefaultDescription("An einer der blank geputzten grauen Fahrstuhlw�nde steht: \"Im Brandfall nicht benutzbar!\".");
				Tuna.addText(location[9].getItem(0).getInteractDescription());
				new Thread(new Sound()).start();
			} else {
				beep();
			}
			break;
		case "inv fireax":
			if (currentLocation == 10 && location[9].getItem(0).isCollected()) {
				death = true;
				Tuna.setText("Bei dem Versuch das Feuer mit der Feueraxt zu l�schen, bist du gestorben!"
						+ "\nTja, ob das Feuer nun gel�scht ist?"
						+ "\n\n<respawn> f�r den n�chsten Versuch.");
				location[10].getDescriptions().setExploreDescription("Das freche Feuer, das dir den Weg in die erste Etage versperrt, wurde wohl von irgendjemandem versucht mit eienr stinknormalen Axt zu l�schen");
				location[10].getDescriptions().setAlreadyExploredDescription("Das freche Feuer, das dir den Weg in die erste Etage versperrt, wurde wohl von irgendjemandem versucht mit eienr stinknormalen Axt zu l�schen");
				
			} else if (currentLocation == 9 && location[9].getItem(0).isCollected() && !location[20].getItem(0).isVisible() && !location[20].isVisible() && location[9].getItem(1).isVisible()) {
				Tuna.addText("Durch die Hebelwirkung hast du es geschafft den Gullideckel beiseite zu schieben. Da drunter siehst du den Fahrstuhlschacht [elevator shaft]");
				location[9].getDescriptions().setExploreDescription("Um den Gullideckel wieder aufzubrechen, br�uchtest du wieder eine heile Feueraxt. Deine ist dir aber kaputt gegangen.");
				location[9].getDescriptions().setAlreadyExploredDescription("Der Gullideckel ist zu und ohne eine heile Feueraxt kriegst du ihn auch nicht mehr auf!");
				location[9].setExplored(false);
				location[20].setVisible(true);
				Tuna.setExitsContent("Korridor [corridor]" + "\nFahrstuhlschacht [elevator shaft]");
				location[9].setExits("Korridor [corridor]" + "\nFahrstuhlschacht [elevator shaft]");
			} else {
				beep();
			}
			break;

		// Skillbook
		case "skillbook":
			if (currentLocation == 6 && location[6].getItem(0).isVisible() && !location[6].getItem(0).isCollected()) {
				this.beam = true;
				location[6].getDescriptions().setAlreadyExploredDescription("Tja, hier wurde wohl schon alles wegger�ubert. Finde den �belt�ter!");
				Tuna.setMessage("Du kannst dich nun beamen.");
				location[6].getItem(0).setCollected(true);
			} else {
				beep();
			}
			break;
		
		// R�tsell�sung
		case "paper":
			if (currentLocation == 0 && location[0].getItem(3).isVisible() && !location[0].getItem(3).isCollected()) {
				Tuna.iAddContent("Die unendliche Summe [paper]");
				location[0].getItem(3).setCollected(true);
			} else {
				beep();
			}
			break;
		
		// Kaffeel�scherkasten
		case "extinguisherbox":
			if (currentLocation == 1 && location[1].getItem(0).isVisible()) {
				Tuna.addText(location[1].getItem(0).getInteractDescription());
			} else {
				beep();
			}
			break;
		
		// Kaffeel�scher
		case "coffeeextinguisher":
			if (currentLocation == 1 && location[1].getItem(0).isVisible() && location[1].getItem(1).isVisible() && !location[1].getItem(1).isCollected()) {
				Tuna.addText(location[1].getItem(1).getInteractDescription());
				Tuna.iAddContent("Kaffeel�scher [coffee extinguisher]");
				location[1].getItem(1).setCollected(true);
				location[1].getItem(1).setInteractDescription("Du hast das Feuer erfolgreich gel�scht!");
				new Thread(new Sound()).start();
			} else {
				beep();
			}
			break;
			
		case "invcoffeeextinguisher":
			if (currentLocation == 10 && location[1].getItem(1).isCollected()) {
				location[11].setVisible(true);
				Tuna.addText(location[1].getItem(1).getInteractDescription());
				// Die Beschreibungen des Treppenhauses �ndern, da dort nun kein Feuer mehr ist
				location[10].getDescriptions().setDefaultDescription("Ein Treppenhaus, welches heldenhaft mit Feuer gel�scht wurde.");
				location[10].getDescriptions().setExploreDescription("Hier liegt nur noch der leere Kaffeel�scher.");
				location[10].getDescriptions().setAlreadyExploredDescription(" Als Andenken an diese heldenhafte Tat, liegt hier nur noch der Kaffeel�scher.");
				Tuna.iDeleteItem("Kaffeel�scher [coffee extinguisher]");
			} else if (location[1].getItem(1).isCollected()) {
				Tuna.addText("Herorisch packst du deinen Kaffeel�scher aus... bis du merkst, irgendetwas fehlt.\nDas FEUER!");
			} else {
				beep();
			}
			break;
			
		// Kaffeetasse
		case "coffeecup":
			if (currentLocation == 20 && location[20].getItem(0).isVisible()) {
				death = true;
				Tuna.addText(location[20].getItem(0).getInteractDescription());
				location[1].getItem(1).setVisible(true);
				location[1].getItem(0).setDescription("Der Kasten ist wohl offen!");
				location[1].getItem(0).setInteractDescription("Da der Strom ausgefallen ist, funktioniert das Schloss nicht mehr. Du �ffnest den Kasten und findest darin einen Kaffeel�scher [coffee extinguisher].");
				location[1].getDescriptions().setDefaultDescription("Der Korridor ist dunkel. Irgendwas scheint passiert zu sein... egal du findest dich noch zurecht.");				
				Tuna.addText("Der Strom ist ausgefallen... zumindest hier im Fahrstuhl und im Korridor."
						+ "\nAchso, und du bist durch den Stromschlag und durch die Tatsache, dass du schon angeschlagen warst, gestorben."
						+ "\n<respawn>");
			} else {
				beep();
			}
			break;
		
		// Gulli
		case "gully":
			if (currentLocation == 9 && !location[20].isVisible() && location[9].getItem(1).isVisible()) {
				Tuna.addText("Der Gullideckel l�sst sich nicht bewegen!");
			} else if (currentLocation == 9 && location[20].isVisible() && location[9].getItem(1).isVisible()) {
				Tuna.addText("Der Gullideckel wurde bewegt. Du kannst in den darunter liegenden Fahrstuhlschacht gehen [elevator shaft]");
			} else {
				beep();
			}
			break;
		
		// Ventilationsschacht
		case "ventilationsshaft":
			if (currentLocation == 3 && location[3].getItem(0).isVisible() && !location[5].isVisible()) {																						// Wenn man im Konferenzraum ist und der Ventilationsschacht gesehen wurde
				Tuna.addText("Du schiebst das Gitter vom Ventilationsschacht zur Seite und entdeckst dahinter einen Geheimraum [ventilationroom].");				// Benachrichtigung f�r den Spieler
				location[5].setVisible(true);																														// Den Raum auch sichtbar/begehbar machen
				Tuna.setExitsContent(Tuna.getExitsContent() + "\nVentilationsraum [ventilationroom]");																// Zur Anzeige den neuen anliegenden Raum hinzuf�gen
				location[3].setExits(Tuna.getExitsContent());																										// Die Ausg�nge des Konferenzraumes neu setzen
			} else {
				beep();
			}
			break;
			
		// Spachtel	
		case "spatula":
			if (currentLocation == 14 && location[14].isExplored() && !location[14].getItem(0).isCollected()) {
				location[14].getItem(0).setCollected(true);
				Tuna.iAddContent("Spachtel [spatula]");
				location[14].getDescriptions().setAlreadyExploredDescription("Hier ist nichts interessantes.");
				location[14].getDescriptions().setExploreDescription("Hier ist nichts interessantes.");
				new Thread(new Sound()).start();
			} else {
				beep();
			}
			break;	
		case "invspatula":
			if (location[14].getItem(0).isCollected() && currentLocation == 13 && location[13].getItem(1).isVisible()) {
				Tuna.addText("Mit M�he und Not befreist du die Notiz [note] aus den Klauen der Algen, die dem Papier wie K�sef�den folgen.");
				location[13].getItem(0).setVisible(true);
			} else if (location[14].getItem(0).isCollected()) {
				Tuna.addText("Spachtel sind in ihrem Nutzen ziemlich begrenzt. Hier gibts nichts herumzuspachteln!");
			} else {
				beep();
			}
			break;
			
		// Student	
		case "student":
			if (currentLocation == 12 || currentLocation == 15 || currentLocation == 16 || currentLocation == 17) {
				Tuna.addText(location[currentLocation].getStudent().getName() + ": \"" + location[currentLocation].getStudent().getQuestionText() + "\"");
				this.setInQuiz(true);
				Tuna.setMessage("Du beginnst einen Dialog mit einen Studenten");
			} else {
				beep();
			}
			break;
			
		// Wilhelm	
		case "wilhelm":
			if (currentLocation == 19 && location[19].isExplored() && !location[19].getItem(0).isCollected()) {
				Tuna.addText("\"Ich habe hier noch diese Notiz f�r Sie bewahrt!\"");
				Tuna.setMessage("Du erh�ltst eine Notiz");
				Tuna.iAddContent("Notiz");
				location[19].getItem(0).setCollected(true);
			} else if (currentLocation == 19 && location[19].getItem(0).isCollected()){
				Tuna.addText("\"Ich habe Ihnen nichts mehr zu geben, Herr Euler, es sei denn, sie wollen ein Katzenbaby?\"\nVilleicht sp�ter");
			}
				
		}
		} else if (death) {
			Tuna.setMessage("Du bist tot!");
		}
		
	}

	public void examineObject(String object) {													// Methode zum Untersuchen eines Gegenstandes. �bergeben wird der Gegenstand
		if (!death) {
		switch (object) {
		
		// Chefsessel
		case "chair":
			if (currentLocation == 0) {
				Tuna.addText(location[0].getItem(1).getDescription());
			} else {
				beep();
			}
			break;
		
		// K�chenschr�nke
		case "cupboards":
			if (currentLocation == 2 && !location[4].isVisible()) {
				Tuna.addText(location[2].getItem(1).getDescription());
				location[4].setVisible(true);
				Tuna.setExitsContent(Tuna.getExitsContent() + "\nKammer der Leere [chamber]");
				location[2].setExits("Korridor [corridor]" + "\nKonferenzraum [conference room]" + "\nKammer der Leere [chamber]");
				location[2].getItem(1).setDescription("Ein K�chenschrank.");
			} else {
				beep();
			}
			break;
			
		// Feueraxt
		case "fireax":
			if (currentLocation == 9 && !location[9].getItem(0).isCollected()) {
				Tuna.addText(location[9].getItem(0).getDescription());
			} else {
				beep();
			}
			break;
		case "inv fireax":
			if (location[9].getItem(0).isCollected()) {
				Tuna.addText(location[9].getItem(0).getDescription());
			} else {
				beep();
			}
			break;
			
		// Skillbook
		case "skillbook":
			if (currentLocation == 6 && !location[6].getItem(0).isCollected()) {
				Tuna.addText(location[6].getItem(0).getDescription());
			} else {
				beep();
			}
			break;
			
		// Ventilationsschacht
		case "ventilationshaft":
			if (currentLocation == 3 && location[3].getItem(0).isVisible() && !location[5].isVisible()) {
				Tuna.addText(location[3].getItem(0).getDescription());
				Tuna.setExitsContent(Tuna.getExitsContent() + "\nVentilationsraum [ventilationroom]");
				location[3].setExits(Tuna.getExitsContent());
				location[5].setVisible(true);
			} else {
				beep();
			}
			break;
			
		// Schreibtisch
		case "desk":
			if (currentLocation == 0) {
				Tuna.addText(location[0].getItem(2).getDescription());
				location[0].getItem(3).setVisible(true);
			} else {
				beep();
			}
			break;
		
		// Vollkegritzeltes Papier
		case "paper":
			if (currentLocation == 0 && location[0].getItem(3).isVisible() && !location[0].getItem(3).isCollected()) {
				Tuna.addText(location[0].getItem(3).getDescription());
			} else {
				beep();
			}
			break;
		case "inv paper":
			if (location[0].getItem(3).isCollected()) {
				Tuna.addText(location[0].getItem(3).getDescription());
			} else {
				beep();
			}
			break;
			
		// Kaffeel�scherkasten
		case "extinguisherbox":
			if (currentLocation == 1 && location[1].getItem(0).isVisible()) {
				Tuna.addText(location[1].getItem(0).getDescription());
			} else {
				beep();
			}
			break;
		
		// Kaffeel�scher
		case "coffeeextinguisher":
			if (currentLocation == 1 && location[1].getItem(1).isVisible()) {
				Tuna.addText(location[1].getItem(1).getDescription());
			} else {
				beep();
			}
			break;
		case "inv coffeeextinguisher":
			if (location[1].getItem(1).isCollected()) {
				Tuna.addText(location[1].getItem(1).getDescription());
			} else {
				beep();
			}
			break;
		
		// Gullideckel
		case "gully":
			if (currentLocation == 9 && location[9].getItem(1).isVisible()) {
				Tuna.addText(location[9].getItem(1).getDescription());
			} else {
				beep();
			}
			break;
			
		case "locker":
			if (currentLocation == 13 && !this.lockerQuestion) {
				this.lockerQuestion = true;
				Tuna.setMessage("Den wievielten Spind denn? [n]");
				Tuna.addText("Gib eine Zahl ein, welchen Spind du untersuchen willst.");
			} else {
				beep();
			}
			break;
			
		case "shinylocker":
			if (currentLocation == 13 && location[13].isExplored()) {
				Tuna.addText("Dein Gesicht spiegelt sich im Spind...\nDu schl�gst instinktiv zu.");
			}
			break;
			
		case "spatula":
			if (currentLocation == 14 && !location[14].getItem(0).isCollected() && location[14].isExplored()) {
				Tuna.addText(location[14].getItem(0).getDescription());
			} else {
				beep();
			}
			break;
		case "invspatula":
			if (location[14].getItem(0).isCollected()) {
				Tuna.addText(location[14].getItem(0).getDescription());
			} else {
				beep();
			}
			break;
		}
		} else if (death) {
			Tuna.setMessage("Du bist tot!");
		}
	}
	
	public void beep() {																			// Spielt einen Warnton ab, wenn der Sound erlaubt wurde
		if (Tuna.isSoundAllowed()) {
			java.awt.Toolkit.getDefaultToolkit().beep();
		}
	}
	/*********************************ENDE METHODEN****************************************/
	
	
	
	/***************************ANFANG GETTER/SETTER METHODEN***************************/
	public int getCurrentLocation() {
		return currentLocation;
	}
	public void setCurrentLocation(int currentLocation) {
		this.currentLocation = currentLocation;
	}
	public boolean isDeath() {
		return death;
	}
	public void setDeath(boolean death) {
		this.death = death;
	}
	public int getDeathAmount() {
		return deathAmount;
	}
	public void setDeathAmount(int deathAmount) {
		this.deathAmount = deathAmount;
	}
	public boolean isBeam() {
		return beam;
	}
	public void setBeam(boolean beam) {
		this.beam = beam;
	}
	public int getAmountNotes() {
		return amountNotes;
	}
	public void setAmountNotes(int amountNotes) {
		this.amountNotes = amountNotes;
	}
	public boolean isBattle() {
		return battle;
	}
	public void setBattle(boolean battle) {
		this.battle = battle;
	}
	public boolean isBattleArt() {
		return battleArt;
	}
	public void setBattleArt(boolean battleArt) {
		this.battleArt = battleArt;
	}
	public Location getLocation() {
		return location[this.currentLocation];
	}
	public Location getLocation(int index) {
		return location[index];
	}
	public int getLastLocation() {
		return lastLocation;
	}
	public void setLastLocation(int lastLocation) {
		this.lastLocation = lastLocation;
	}
	public boolean isLockerQuestion() {
		return lockerQuestion;
	}
	public void setLockerQuestion(boolean lockerQuestion) {
		this.lockerQuestion = lockerQuestion;
	}
	public void setLocation(int index, Location location) {
		this.location[index] = location;
	}
	public boolean isInQuiz() {
		return inQuiz;
	}
	public void setInQuiz(boolean inQuiz) {
		this.inQuiz = inQuiz;
	}
	/****************************ENDE GETTER/SETTER METHODEN*******************************/
}