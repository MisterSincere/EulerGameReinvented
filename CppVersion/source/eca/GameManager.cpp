#include "GameManager.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>


ECA::GameManager::GameManager(sf::RenderWindow* pWindow)
	: ITextHandler(pWindow)
{
	i_commands += "exit";
	i_commands += "explore";
	i_commands += "examine";
	i_commands += "examine inv";
	i_commands += "interact";
	i_commands += "interact inv";
	i_commands += "go";
	i_commands += "load";
	i_commands += "save";
	i_commands += "back";
	i_commands += "inventar";
}

void ECA::GameManager::Handle(char const* text) {
	if (i_commands["exit"] == text) {
		i_pWindow->close();
	}
}

void ECA::GameManager::init() {
	Description description;
	Location location;
	Student student;
	Item item;
	std::vector<Item*> items;
	std::vector<Student*> students;
	std::vector<LocationEnum> exits;
	//--------------------------------------------------------------------------
	//B�ro
	//--------------------------------------------------------------------------
		description = {
			//default
			"In deinem B�ro ist mittig ein �berf�llter Schreibtisch [desk] an dem ein Scott Chefsessel mit original Kunstleder im Wert von 500� steht [chair]. Au�erdem stehen zwei Schr�nke in jeweils einer Ecke des Raumes.",
			//explore
			"Das B�ro ist nicht besonders gro�, aber du bist trotzdem stolz auf deinen Chefsessel. Au�erdem steht eine Vitrine in dem Raum, in der deine Preise und Troph�en stehen.",
			//already explored
			"Der Raum ist nicht besonders gro�, aber auf deinen Chefsessel bist du trotzdem stolz und nat�rlich auf deine Preis und Troph�en in deiner Vitrine."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);

		location = {
			//name
			"B�ro [office]",
			//enum/id
			OFFICE,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Korridor obere Etage
	//--------------------------------------------------------------------------
		description = {
			//default
			"Im Korridor angekommen siehst du mehrere R�ume.",
			//explore
			"Was willst du wissen? Es ist nur ein typischer langweiliger Korridor, mit einem Kaffeel�scherkasten [extinguisher box], wie man's in Uni's gewohnt ist!",
			//already explored
			"Ein typischer Korridor mit einem Kaffeel�scherkasten [extinguisher box]. Ist halt 'ne Uni!"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(OFFICE);
		exits.push_back(COFFEE_ROOM);
		exits.push_back(CONFERENCE_ROOM);
		exits.push_back(PRINCIPALS_ROOM);
		exits.push_back(GENTLEMENS_TOILET_UP);
		exits.push_back(STAIRWELL);
		exits.push_back(ELEVATOR);

		location = {
			//name
			"Korridor [corridor]",
			//enum/id
			CORRIDOR_UP,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;
	
	//--------------------------------------------------------------------------
	//T�dlicher Kaffeeraum
	//--------------------------------------------------------------------------
		description = {
			//default
			"Dies ist der Kaffee- und Kuchenraum der Lehrer.\nDu siehst eine neumodische Ikea K�che, mit vielen K�chenschr�nken [cupboards] auf denen eine uralte verrostete vermutlich aus dem 1. Weltkrieg stammende Kaffeemaschine [coffeemachine] und eine Mikrowelle steht!",
			//explore
			"Du fragst dich, was in den ganzen K�chenschr�nken [cupboards] sein k�nnte und warum der Boden hier h�her ist!",
			//already explored
			"Wei�t du noch als du dich gefragt hast was in den ganzen K�chenschr�nken sein k�nnte und warum der Boden hier h�her ist?"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);
		exits.push_back(CONFERENCE_ROOM);

		location = {
			//name
			"Kaffeeraum [coffeeroom]",
			//enum/id
			COFFEE_ROOM,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Lehrerzimmer
	//--------------------------------------------------------------------------
		description = {
			//default
			"In diesem Raum werden Konferenzen zu wichtigen Themen abgehalten und unwichtigen, aber die betreffen dich ja eh nicht!\nEinem Konferenzraum entsprechend befindet sich in der Mitte ein Tisch in der Form eines U's. Au�erdem h�ngt an der Wand ein Stundenplan und ein Schrank mit den F�chern f�r die Lehrer.",
			//explore
			"Die Lehrer starren dich aus gro�en Augen an. Du bist wohl mitten in eine Versammlung reingeplatzt. Kann dir auch egal sein, ist keine Konferenz von der du wei�t. Dir f�llt der Ventilationsschacht [ventilation shaft] auf, bei dem das Gitter nur noch an den Schacht gelehnt ist.",
			//already explored
			"Die Konferenz wird wohl nie zu Ende gehen. Der Ventilationssacht [ventilation shaft] ist auch echt auff�llig."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);
		exits.push_back(COFFEE_ROOM);

		location = {
			//name
			"Konferenzraum [conference room]",
			//enum/id
			CONFERENCE_ROOM,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Kammer der Leere
	//--------------------------------------------------------------------------
		description = {
			//default
			"Dieser Raum sieht aus als wenn hier seit Jahren niemand mehr drin gewesen w�re.",
			//explore
			"Du siehst eine deiner Notizen [note] zwischen zwei Kartons gequetscht. Keine Ahnung wie der Windsto� das verursachen konnte...",
			//already explored
			"Eine deiner Notiz [note] liegt zwischen zwei Kartons."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(COFFEE_ROOM);

		location = {
			//name
			"Kammer der Leere [cahmber]",
			//enum/id
			CHAMBER,
			//explored
			false,
			//visible
			false,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Ventilationsraum
	//--------------------------------------------------------------------------
		description = {
			//default
			"Ein Ventilationsraum. Alt, veranzt und staubig. Gel�ftet wurde hier schon seit Jahren nicht mehr!",
			//explore
			"Du siehst eine deiner Notizen [note].",
			//already explored
			"Aber immerhin liegt hier eine deiner Notizen"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CONFERENCE_ROOM);

		location = {
			//name
			"Ventilationsraum [ventilationroom]",
			//enum/id
			VENTILATION_ROOM,
			//explored
			false,
			//visible
			false,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Damen Toiletten obere Etage
	//--------------------------------------------------------------------------
		description = {
			//default
			"In der Damentoilette angekommen, sieht Kollegin Stelz dich irritiert an und geht mit den Worten: \"Sie �berraschen mich immer wieder\" raus.\nBeschreibung: Warst du noch nie in einer Damentoilette?",
			//explore
			"Jetzt blo� nicht sp�len. Es sei denn du magst keine Skillbooks... [skillbook]. Bei diesem Skillbook scheinst du eine Beamf�higkeit erlernen zu k�nnen.",
			//already explored
			"Naja, hier liegt halt noch ein Skillbook [skillbook]."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);

		location = {
			//name
			"Damentoilette [ladiestoilet]",
			//enum/id
			LADIES_TOILET_UP,
			//explored
			false,
			//visible
			false,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Herren Toiletten obere Etage
	//--------------------------------------------------------------------------
		description = {
			//default
			"Als du die Herrentoilette betrittst, weht dir ein animalischer Duft entgegen, welchen du dem ebenfalls \"leicht\" animalischen Direktor zuordnest!",
			//explore
			"Der Geruch ist wirklich unertr�glich. Lange wirst du es hier nicht mehr aushalten k�nnen.",
			//already explored
			"Der Geruch ist wirklich unertr�glich. Lange wirst du es hier nicht mehr aushalten k�nnen."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);

		location = {
			//name
			"Herrentoilette [gentlemenstoilet]",
			//enum/id
			GENTLEMENS_TOILET_UP,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Schulleiterraum
	//--------------------------------------------------------------------------
		description = {
			//default
			"Das B�ro des Direktors ist �hnlich wie deines, �ber den verm�llten Schreibtisch schaut dich ein grimmiger Haufen Kalorien an. Dies m�sste deiner mathematisch hoch komplexen �berlegungen nach der Direktor sein.",
			//explore
			"Meisterhaft in Inneneinrichtung hat der Direktor hier einen braunen Tisch, zwei graue St�hle und eine Ansammlung von an Krawatten erh�ngten Skelette.\nEr ist damit besch�ftigt, Frederic Chopin's neunte Death Metal Komposition zu h�ren.",
			//already explored
			"Der Direktor h�rt noch immer laute Musik von Frederic Chopin."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);

		location = {
			//name
			"Schulleiterraum [principalsroom]",
			//enum/id
			PRINCIPALS_ROOM,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Fahrstuhl
	//--------------------------------------------------------------------------
		description = {
			//default
			"An einer der blank geputzten grauen Fahrstuhlw�nde steht:\"Im Brandfall nicht benutzbar!\".",
			//explore
			"Erst jetzt f�llt dir der Gully [gully] auf dem Boden auf. Wo der wohl hinf�hrt...\nUm das herauszufinden wirst du definitiv so etwas wie einen Hebel ben�tigen.\nDie Feueraxt [fire ax] ist dir eigentlich schon vorher aufgefallen, doch vielleicht wird sie jetzt wichtig?",
			//already explored
			"Auch ein Gullideckel ist hier noch. #normal"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);

		location = {
			//name
			"Fahrstuhl [elevator]",
			//enum/id
			ELEVATOR,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Treppenhaus
	//--------------------------------------------------------------------------
		description = {
			//default
			"Ein Treppenhaus...     es brennt!",
			//explore
			"Das Feuer ist echt frech! Es blockiert dir doch tats�chlich den Weg in den ersten Stock [floor 1].",
			//already explored
			"Das Feuer blockiert dir immer noch den Weg in den ersten Stock [floor 1]!"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_UP);
		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Treppenhaus [stairwell]",
			//enum/id
			STAIRWELL,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Korridor untere Etage
	//--------------------------------------------------------------------------
		description = {
			//default
			"Ein langer Korridor...\nAn ihm liegen vier vom Aufbau her identische H�rs�le, jedoch geh�rt der erste den musischen Wissenschaften, der zweite zu den literarischen, der dritte zu den gesellschaftlichen und als letztes kommt endlich der naturwissenschaftliche H�rsal.",
			//explore
			"Grau. Und unspektakul�r. Der M�lleimer muss unbedingt mal geleert werden.",
			//already explored
			"Grau. Und unspektakul�r."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(LECTURE_HALL_1);
		exits.push_back(LECTRUE_HALL_2);
		exits.push_back(LECTRUE_HALL_3);
		exits.push_back(LECTRUE_HALL_4);
		exits.push_back(LOCKER_ROOM);
		exits.push_back(STORE_ROOM);
		exits.push_back(LADIES_TOILET_DOWN);
		exits.push_back(GENTLEMENS_TOILET_DOWN);
		exits.push_back(ELEVATOR);
		exits.push_back(STAIRWELL);

		location = {
			//name
			"Sch�leretage [studentsfloor]",
			//enum/id
			CORRIDOR_DOWN,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//H�rsaal 1
	//--------------------------------------------------------------------------
		description = {
			//default
			"Man darf sich bekanntlich nicht mehr fragen, ob musische Wissenschaften �berhaupt als eine Wissenschaft gelten, da K�nstler und Freidenker sich sonst angegriffen f�hlen, aber ein Naturwissenschaftler wie du hat wohl besseres verdient!",
			//explore
			"Der Professor liegt in ziemlich bizarren Posen auf dem Tisch und erkl�rt den Studenten(und Studentinnen), welche Pose welche Wirkung hat.\nDu kannst das Geld, dass f�r jede Pose gazahlt wird, f�rmlich von dem Direktor in die Tasche des Professors wandern sehen.\nHier steht noch Maribelle [student], obwohl sie wesentlich kleiner ist, schaut sie hochn�sig auf dich herab.",
			//already explored
			"Maribelle [student] stolziert hier immer noch herum."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		student = {
			//name
			"Maribelle",
			//defeated
			false,
			//question
			"Ahh, Sie lassen sich also hier blicken, Herr Euler! Beantworten sie mir doch, wie Chopin mit Vornamen hie�.",
			//answer
			"Frederic",
			//hint
			"Ahh, woher wissen Sie denn das. Als ich das letzte Mal im Konferenzraum war, war die Luft so stickig!\nJemand m�sste mal den L�ftungsschacht untersuchen."
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"H�rsaal 1 [lecture hall 1]",
			//enum/id
			LECTURE_HALL_1,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//H�rsaal 2
	//--------------------------------------------------------------------------
		description = {
			//default
			"Im vorderen Teil liest der Professor aus einem Buch einen Text in einer Sprache, die du nicht verstehst, w�hrend im hinteren Teil sich Sch�ler mit K�sek�stchen, Schere-Stein-Papier und Battlefield die Zeit vertreiben.",
			//explore
			"Schon wieder eine Runde 4-1 KD, der Sch�ler ist wirklich gut darin, Minen im richtigen Moment hochzujagen. Der Professer liest weiterhin monoton aus dem Buch vor.\nJochen [student] ist so gelangweilt, dass er deinen Schritten Aufmerksamkeit schenkt.",
			//already explored
			"Der Professer liest noch immer aus dem Buch vor, w�hrend dir Jochen noch immer hinterher starrt."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		student = {
			//name
			"Jochen",
			//defeated
			false,
			//question
			"Greetings Mate! Is english DLC working right know?",
			//answer
			"No",
			//hint
			"Oh, I see. Do you think locker 42 is somewhat special? Because I do think so!"
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"H�rsaal 2 [lecture hall 2]",
			//enum/id
			LECTRUE_HALL_2,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//H�rsaal 3
	//--------------------------------------------------------------------------
		description = {
			//default
			"Der Lehrende zeigt aufgeregt auf eine Karte, welchen Schwerpunkt diese Vorlesung auch immer hat, eine Karte macht alles spannender! Sein Gegenspieler gewinnt in dem Pokerduell und jubelt laut auf!",
			//explore
			"Alle Studierenden sind inzwischen wieder drin, w�hrend der Professor eine Runde in der Ecke schmollt.\nOh-oh, da kommt Anthon [student]",
			//already explored
			"Anthon [student] bemerkt dich sofort, als du den Raum betrittst."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		student = {
			//name
			"Anthon",
			//defeated
			false,
			//question
			"Ehehe Euler, was sind Dreipacken minus Zweipacken?",
			//answer
			"Einpacken",
			//hint
			"Ihihi, f�rchte dich vor Kaffe, der ist T�dlich!"
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"H�rsaal 3 [lecture hall 3]",
			//enum/id
			LECTRUE_HALL_3,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//H�rsaal 4
	//--------------------------------------------------------------------------
		description = {
			//default
			"Dein Reich ist gerade von einem Chemieprofessor belegt. Dieser ist grade dabei mit peinlicher Sorgfalt den Tisch in alle vier Himmelsrichtungen gleichzeitig zu katapultieren!",
			//explore
			"Die Frau braucht wieder einmal zu lange, du musst den Vortrag wohl beginnen, w�hrend sie noch Chemikalien mischt.\nGerhard [student], dein pers�hnlicher Fanboy, starrt dich mit gro�en Augen an.",
			//already explored
			"Gerhards Blick bleibt sofort auf dir haften, als du in Raum gehst."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		student = {
			//name
			"Gerhard",
			//defeated
			false,
			//question
			"Moin Euler, sagen Sie doch mal Ihre Summe des Unendlichen!",
			//answer
			"-1/12",
			//hint
			"Boah, darauf w�re ich nicht gekommen!\nWissen Sie, warum der Boden im Kaffeeraum so hoch ist? Na, egal..."
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"H�rsaal 4 [lecture hall 4]",
			//enum/id
			LECTRUE_HALL_4,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Sprindraum
	//--------------------------------------------------------------------------
		description = {
			//default
			"Modrig steigt der Geruch ranziger K�sebrote durch die L�ftungsschlitze einiger Schlie�f�cher, welche jedoch alle durch Algen in einem sch�nen Armee-Gr�nton gehalten werden. Alle? Nein, nicht alle! Eine glanzpolierte Marmorvariante, die dem Hausmeister geh�rt, koexistiert tats�chlich noch in diesem Raum.",
			//explore
			"So viele Schlie�f�cher [locker], und alle sind nummeriert. Verhindert wird jedoch eine genaue Identifikation des Hausmeisterfaches [shiny locker], da die Nummer wegpoliert wurde.",
			//already explored
			"Jedoch sind sowohl die Normalen [locker] als auch der Besondere [shiny locker] relativ uninteressant."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Spindraum [lockerroom]",
			//enum/id
			LOCKER_ROOM,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Abstellraum
	//--------------------------------------------------------------------------
		description = {
			//default
			"Ein Mob, ein Eimer, ein Feuchttuch.... dich verwundert es, wie der Hausmeister nur mit diesen Sachen zumindest sein Revier so poliert",
			//explore
			"Dir f�llt ein Spachtel [spatula] auf, der eindeutig aus der Chemiesammlung genommen wurde. Hol zur�ck, was dir geh�rt!",
			//already explored
			"Hier liegt ein Spachtel [spatula], der eindeutig aus der Chemiesammlung genommen wurde."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Abstellraum [storeroom]",
			//enum/id
			STORE_ROOM,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Damen Toiletten untere Etage
	//--------------------------------------------------------------------------
		description = {
			//default
			"Es riecht herrlich nach Einhorn und Regenbogen, und nach dem alkohoisierten Hausmeister, der dabei ist den Lippenstift vom Spiegel zu entfernen und dich nicht bemerkt.",
			//explore
			"Es ist ein Graus, Steven hat sich von Rebecca getrennt, und Gr�n ist das neue Schwarz, zumindest nach den Tratschtanten auf dem Klo.",
			//already explored
			"Die Tratschtanten reden noch immer."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Damentoilette [ladiestoilet]",
			//enum/id
			LADIES_TOILET_DOWN,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Herren Toiletten untere Etage
	//--------------------------------------------------------------------------
		description = {
			//default
			"Das Putzfrauenspecialcorps hat sich gestern zur Aufgabe gemacht den gr�nen Schleim von der Wand zu entfernen... Nur noch ein wenig Neutralreiniger auf dem Boden und eine Cap, mit dem Wort \"Obey\", schaukelnd an einer Lampe, sind noch �brig geblieben.",
			//explore
			"Der Schleim hei�t Wilhelm von Kaiser [wilhelm] und verkauft w�hrend der Pausen Katzenbabys f�r diejenigen in Not, ein sehr angenehmer Geselle.",
			//already explored
			"Wilhelm von Kaiser [wilhelm] schleimt noch immer hier rum."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Herrentoilette [gentlemenstoilet]",
			//enum/id
			GENTLEMENS_TOILET_DOWN,
			//explored
			false,
			//visible
			true,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;

	//--------------------------------------------------------------------------
	//Fahrstuhlschacht
	//--------------------------------------------------------------------------
		description = {
			//default
			"Im Raum angekommen f�llt dir sofort die ganze Elektronik hier unten auf. Ob hier noch mehr ist?",
			//explore
			"Hier liegt eine Kaffeetasse mit, wer h�tte es gedacht, hei�em Kaffee [cup coffee] drin.",
			//already explored
			"FANCY DESCRIPTION" //TODO
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		location = {
			//name
			"Fahrstuhlschacht [elevator shaft]",
			//enum/id
			ELEVATOR_SHAFT,
			//explored
			false,
			//visible
			false,
			//description
			&description,
			//items
			items,
			//exits
			exits,
			//students
			students
		};

		locations[location.id] = &location;
}
