#include "GameManager.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "EulerAdventure.h"


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
		EulerAdventure::ChangeGameState(EXIT);
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
	//Büro
	//--------------------------------------------------------------------------
		description = {
			//default
			"In deinem Büro ist mittig ein überfüllter Schreibtisch [desk] an dem ein Scott Chefsessel mit original Kunstleder im Wert von 500€ steht [chair]. Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes.",
			//explore
			"Das Büro ist nicht besonders groß, aber du bist trotzdem stolz auf deinen Chefsessel. Außerdem steht eine Vitrine in dem Raum, in der deine Preise und Trophäen stehen.",
			//already explored
			"Der Raum ist nicht besonders groß, aber auf deinen Chefsessel bist du trotzdem stolz und natürlich auf deine Preis und Trophäen in deiner Vitrine."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Stuhl
		item = {
			//name
			"Stuhl [chair]",
			//enum/id
			CHAIR,
			//description
			"Ein Scott Chefsessel aus original Kunstleder im Wert von 500€, der nur dir gehört.",
			//interactDescription
			"Du setzt dich auf deinen Stuhl.\nEs macht knack und du sitzt auf'm Boden... Das Steak zum Frühstück war wohl doch zu viel.",
			//visible
			true,
			//collected
			false
		};
		items.push_back(&item);

		//Schreibtisch
		item = {
			//name
			"Schreibtisch [desk]",
			//enum/id
			DESK,
			//description
			"Dieser Schreibtisch braucht eine neue Lackierung. Achso, und ein Putzkommando!\nTrotz der Unordnung fällt dir ein vollgekritzeltes Papier [paper] auf, auf dem du dein letztes Meisterwerk, das Ergebnis der unendlichen Summe, niedergeschrieben hast!",
			//interactDescription
			nullptr, //TODO
			//visible
			true,
			//collected
			false
		};
		items.push_back(&item);

		//Rätsellösung
		item = {
			//name
			"Rätsellösung [paper]",
			//enum/id
			PAPER,
			//description
			"Du hast hier die Summe der Unendlichkeit errechnet. Sie lautet -1/12!",
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

		exits.push_back(CORRIDOR_UP);

		location = {
			//name
			"Büro [office]",
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
			"Im Korridor angekommen siehst du mehrere Räume.",
			//explore
			"Was willst du wissen? Es ist nur ein typischer langweiliger Korridor, mit einem Kaffeelöscherkasten [extinguisher box], wie man's in Uni's gewohnt ist!",
			//already explored
			"Ein typischer Korridor mit einem Kaffeelöscherkasten [extinguisher box]. Ist halt 'ne Uni!"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Kaffeelöscherkasten
		item = {
			//name
			"Kaffeelöscherkasten [coffee extinguisher box]",
			//enum/id
			COFFEE_EXTINGUISHER_BOX,
			//description
			"Dieser Kasten beinhaltet einen Kaffeelöscher [coffee extinguisher], dieser ist der (un)natürlichste Bestandteil einer Feuerwehrausrüstung! Der Kasten ist durch ein elektronisches Sicherheitsschloss gesichert!",
			//interactDescription
			"Das kannst du nicht machen. Das elektronische Sicherheitsschloss will das nicht! Ob du einen Weg findest es zu bezwingen?",
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

		//Kaffeelöscher
		item = {
			//name
			"Kaffeelöscher [coffee extinguisher]",
			//enum/id
			COFFEE_EXTINGUISHER,
			//description
			"Ein Feuerlöscher mit komisch riechendem Kaffee gefüllt.",
			//interactDescription
			"Jetzt bist du ein wahrer Feuerwehrmann.... Naja, nicht ganz, aber fast.",
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
	//Tödlicher Kaffeeraum
	//--------------------------------------------------------------------------
		description = {
			//default
			"Dies ist der Kaffee- und Kuchenraum der Lehrer.\nDu siehst eine neumodische Ikea Küche, mit vielen Küchenschränken [cupboards] auf denen eine uralte verrostete vermutlich aus dem 1. Weltkrieg stammende Kaffeemaschine [coffeemachine] und eine Mikrowelle steht!",
			//explore
			"Du fragst dich, was in den ganzen Küchenschränken [cupboards] sein könnte und warum der Boden hier höher ist!",
			//already explored
			"Weißt du noch als du dich gefragt hast was in den ganzen Küchenschränken sein könnte und warum der Boden hier höher ist?"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Kaffeemaschine
		item = {
			//name
			"Kaffeemaschine [coffee machine]",
			//enum/id
			COFFEE_MACHINE,
			//description
			"Eine hochwertig billige Kaffeemaschine. Die nicht funktoniert, irgendwer muss wohl das Stromkabel rausgezogen haben.",
			//interactDescription
			"Du willst den Stecker in die Steckdose stecken, aber die Steckdose will das nun halt nicht und gibt dir deswegen einen tödlichen Stromschlag.",
			//visible
			true,
			//collected
			false
		};
		items.push_back(&item);

		//Küchenschränke
		item = {
			//name
			"Küchenschränke [cupboards]",
			//enum/id
			CUPBOARDS,
			//description
			"Unter einem der Schränke ist ein Hohlraum, welcher unter dem ganzen Kaffeeraum hindurch führt zu einem geheimen Raum [chamber].",
			//interactDescription
			nullptr, //TODO
			//visible
			true,
			//collected
			false
		};
		items.push_back(&item);

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
			"In diesem Raum werden Konferenzen zu wichtigen Themen abgehalten und unwichtigen, aber die betreffen dich ja eh nicht!\nEinem Konferenzraum entsprechend befindet sich in der Mitte ein Tisch in der Form eines U's. Außerdem hängt an der Wand ein Stundenplan und ein Schrank mit den Fächern für die Lehrer.",
			//explore
			"Die Lehrer starren dich aus großen Augen an. Du bist wohl mitten in eine Versammlung reingeplatzt. Kann dir auch egal sein, ist keine Konferenz von der du weißt. Dir fällt der Ventilationsschacht [ventilation shaft] auf, bei dem das Gitter nur noch an den Schacht gelehnt ist.",
			//already explored
			"Die Konferenz wird wohl nie zu Ende gehen. Der Ventilationssacht [ventilation shaft] ist auch echt auffällig."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Lüftungsschacht
		item = {
			//name
			"Lüftungsschacht [ventilation shaft]",
			//enum/id
			VENTILATION_SHAFT,
			//description
			"Du entdeckst einen Geheimraum [ventilationroom].",
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"Dieser Raum sieht aus als wenn hier seit Jahren niemand mehr drin gewesen wäre.",
			//explore
			"Du siehst eine deiner Notizen [note] zwischen zwei Kartons gequetscht. Keine Ahnung wie der Windstoß das verursachen konnte...",
			//already explored
			"Eine deiner Notiz [note] liegt zwischen zwei Kartons."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Notiz
		item = {
			//name
			"Notiz [note]",
			//enum/id
			NOTE1,
			//description
			nullptr, //TODO
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"Ein Ventilationsraum. Alt, veranzt und staubig. Gelüftet wurde hier schon seit Jahren nicht mehr!",
			//explore
			"Du siehst eine deiner Notizen [note].",
			//already explored
			"Aber immerhin liegt hier eine deiner Notizen"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Notiz
		item = {
			//name
			"Notiz [note]",
			//enum/id
			NOTE2,
			//description
			nullptr, //TODO
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"In der Damentoilette angekommen, sieht Kollegin Stelz dich irritiert an und geht mit den Worten: \"Sie überraschen mich immer wieder\" raus.\nBeschreibung: Warst du noch nie in einer Damentoilette?",
			//explore
			"Jetzt bloß nicht spülen. Es sei denn du magst keine Skillbooks... [skillbook]. Bei diesem Skillbook scheinst du eine Beamfähigkeit erlernen zu können.",
			//already explored
			"Naja, hier liegt halt noch ein Skillbook [skillbook]."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Skillbook
		item = {
			//name
			"Skillbook [skillbook]",
			//enum/id
			SKILL_BOOK,
			//description
			"Dies ist das verstaubte Skillbook des toten Beammeisters.",
			//interactDescription
			"Du kannst dich nun beamen!",
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"Der Geruch ist wirklich unerträglich. Lange wirst du es hier nicht mehr aushalten können.",
			//already explored
			"Der Geruch ist wirklich unerträglich. Lange wirst du es hier nicht mehr aushalten können."
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
			"Das Büro des Direktors ist ähnlich wie deines, über den vermüllten Schreibtisch schaut dich ein grimmiger Haufen Kalorien an. Dies müsste deiner mathematisch hoch komplexen Überlegungen nach der Direktor sein.",
			//explore
			"Meisterhaft in Inneneinrichtung hat der Direktor hier einen braunen Tisch, zwei graue Stühle und eine Ansammlung von an Krawatten erhängten Skelette.\nEr ist damit beschäftigt, Frederic Chopin's neunte Death Metal Komposition zu hören.",
			//already explored
			"Der Direktor hört noch immer laute Musik von Frederic Chopin."
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
			"An einer der blank geputzten grauen Fahrstuhlwände steht:\"Im Brandfall nicht benutzbar!\".",
			//explore
			"Erst jetzt fällt dir der Gully [gully] auf dem Boden auf. Wo der wohl hinführt...\nUm das herauszufinden wirst du definitiv so etwas wie einen Hebel benötigen.\nDie Feueraxt [fire ax] ist dir eigentlich schon vorher aufgefallen, doch vielleicht wird sie jetzt wichtig?",
			//already explored
			"Auch ein Gullideckel ist hier noch. #normal"
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Feueraxt
		item = {
			//name
			"Feueraxt [fire ax]",
			//enum/id
			FIRE_AXE,
			//description
			"Es ist eine Feueraxt!",
			//interactDescription
			"Diese Axt gehört zur Grundausstattung eines Feuerbekämpfers.",
			//visible
			true,
			//collected
			false
		};
		items.push_back(&item);

		//Gulli
		item = {
			//name
			"Gulli [gully]",
			//enum/id
			GULLY,
			//description
			"Ein Gullideckel... er ist eckig, er ist halt auch ein Individuum.\nDu brauchst irgendeinen Trick um den Gullideckel anheben zu können.",
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"Das Feuer ist echt frech! Es blockiert dir doch tatsächlich den Weg in den ersten Stock [floor 1].",
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
			"Ein langer Korridor...\nAn ihm liegen vier vom Aufbau her identische Hörsäle, jedoch gehört der erste den musischen Wissenschaften, der zweite zu den literarischen, der dritte zu den gesellschaftlichen und als letztes kommt endlich der naturwissenschaftliche Hörsal.",
			//explore
			"Grau. Und unspektakulär. Der Mülleimer muss unbedingt mal geleert werden.",
			//already explored
			"Grau. Und unspektakulär."
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
			"Schüleretage [studentsfloor]",
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
	//Hörsaal 1
	//--------------------------------------------------------------------------
		description = {
			//default
			"Man darf sich bekanntlich nicht mehr fragen, ob musische Wissenschaften überhaupt als eine Wissenschaft gelten, da Künstler und Freidenker sich sonst angegriffen fühlen, aber ein Naturwissenschaftler wie du hat wohl besseres verdient!",
			//explore
			"Der Professor liegt in ziemlich bizarren Posen auf dem Tisch und erklärt den Studenten(und Studentinnen), welche Pose welche Wirkung hat.\nDu kannst das Geld, dass für jede Pose gazahlt wird, förmlich von dem Direktor in die Tasche des Professors wandern sehen.\nHier steht noch Maribelle [student], obwohl sie wesentlich kleiner ist, schaut sie hochnäsig auf dich herab.",
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
			"Ahh, Sie lassen sich also hier blicken, Herr Euler! Beantworten sie mir doch, wie Chopin mit Vornamen hieß.",
			//answer
			"Frederic",
			//hint
			"Ahh, woher wissen Sie denn das. Als ich das letzte Mal im Konferenzraum war, war die Luft so stickig!\nJemand müsste mal den Lüftungsschacht untersuchen."
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Hörsaal 1 [lecture hall 1]",
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
	//Hörsaal 2
	//--------------------------------------------------------------------------
		description = {
			//default
			"Im vorderen Teil liest der Professor aus einem Buch einen Text in einer Sprache, die du nicht verstehst, während im hinteren Teil sich Schüler mit Käsekästchen, Schere-Stein-Papier und Battlefield die Zeit vertreiben.",
			//explore
			"Schon wieder eine Runde 4-1 KD, der Schüler ist wirklich gut darin, Minen im richtigen Moment hochzujagen. Der Professer liest weiterhin monoton aus dem Buch vor.\nJochen [student] ist so gelangweilt, dass er deinen Schritten Aufmerksamkeit schenkt.",
			//already explored
			"Der Professer liest noch immer aus dem Buch vor, während dir Jochen noch immer hinterher starrt."
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
			"Hörsaal 2 [lecture hall 2]",
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
	//Hörsaal 3
	//--------------------------------------------------------------------------
		description = {
			//default
			"Der Lehrende zeigt aufgeregt auf eine Karte, welchen Schwerpunkt diese Vorlesung auch immer hat, eine Karte macht alles spannender! Sein Gegenspieler gewinnt in dem Pokerduell und jubelt laut auf!",
			//explore
			"Alle Studierenden sind inzwischen wieder drin, während der Professor eine Runde in der Ecke schmollt.\nOh-oh, da kommt Anthon [student]",
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
			"Ihihi, fürchte dich vor Kaffe, der ist Tödlich!"
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Hörsaal 3 [lecture hall 3]",
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
	//Hörsaal 4
	//--------------------------------------------------------------------------
		description = {
			//default
			"Dein Reich ist gerade von einem Chemieprofessor belegt. Dieser ist grade dabei mit peinlicher Sorgfalt den Tisch in alle vier Himmelsrichtungen gleichzeitig zu katapultieren!",
			//explore
			"Die Frau braucht wieder einmal zu lange, du musst den Vortrag wohl beginnen, während sie noch Chemikalien mischt.\nGerhard [student], dein persöhnlicher Fanboy, starrt dich mit großen Augen an.",
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
			"Boah, darauf wäre ich nicht gekommen!\nWissen Sie, warum der Boden im Kaffeeraum so hoch ist? Na, egal..."
		};

		exits.push_back(CORRIDOR_DOWN);

		location = {
			//name
			"Hörsaal 4 [lecture hall 4]",
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
			"Modrig steigt der Geruch ranziger Käsebrote durch die Lüftungsschlitze einiger Schließfächer, welche jedoch alle durch Algen in einem schönen Armee-Grünton gehalten werden. Alle? Nein, nicht alle! Eine glanzpolierte Marmorvariante, die dem Hausmeister gehört, koexistiert tatsächlich noch in diesem Raum.",
			//explore
			"So viele Schließfächer [locker], und alle sind nummeriert. Verhindert wird jedoch eine genaue Identifikation des Hausmeisterfaches [shiny locker], da die Nummer wegpoliert wurde.",
			//already explored
			"Jedoch sind sowohl die Normalen [locker] als auch der Besondere [shiny locker] relativ uninteressant."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Locker
		item = {
			//name
			"Spind [locker]",
			//enum/id
			LOCKER,
			//description
			nullptr, //TODO
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

		//Spind 42
		item = {
			//name
			"Spind 42 [shiny locker]",
			//enum/id
			SHINY_LOCKER,
			//description
			nullptr, //TODO
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

		//Notiz
		item = {
			//name
			"Notiz [note]",
			//enum/id
			NOTE3,
			//description
			nullptr, //TODO
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"Dir fällt ein Spachtel [spatula] auf, der eindeutig aus der Chemiesammlung genommen wurde. Hol zurück, was dir gehört!",
			//already explored
			"Hier liegt ein Spachtel [spatula], der eindeutig aus der Chemiesammlung genommen wurde."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Spachtel
		item = {
			//name
			"Spachtel [spatula]",
			//enum/id
			SPATULA,
			//description
			"Du wolltest ihn eigentlich der Chemiesammlung wiedergeben, aber er glänzt so schön.",
			//interactDescription
			nullptr, //TODO
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
			"Es ist ein Graus, Steven hat sich von Rebecca getrennt, und Grün ist das neue Schwarz, zumindest nach den Tratschtanten auf dem Klo.",
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
			"Das Putzfrauenspecialcorps hat sich gestern zur Aufgabe gemacht den grünen Schleim von der Wand zu entfernen... Nur noch ein wenig Neutralreiniger auf dem Boden und eine Cap, mit dem Wort \"Obey\", schaukelnd an einer Lampe, sind noch übrig geblieben.",
			//explore
			"Der Schleim heißt Wilhelm von Kaiser [wilhelm] und verkauft während der Pausen Katzenbabys für diejenigen in Not, ein sehr angenehmer Geselle.",
			//already explored
			"Wilhelm von Kaiser [wilhelm] schleimt noch immer hier rum."
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Notiz
		item = {
			//name
			"Notiz [note]",
			//enum/id
			NOTE4,
			//description
			nullptr, //TODO
			//interactDescription
			nullptr, //TODO
			//visible
			true,
			//collected
			false
		};
		items.push_back(&item);

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
			"Im Raum angekommen fällt dir sofort die ganze Elektronik hier unten auf. Ob hier noch mehr ist?",
			//explore
			"Hier liegt eine Kaffeetasse mit, wer hätte es gedacht, heißem Kaffee [cup coffee] drin.",
			//already explored
			"FANCY DESCRIPTION" //TODO
		};

		items = std::vector<Item*>();
		students = std::vector<Student*>();
		exits = std::vector<LocationEnum>();

		//Kaffeetasse
		item = {
			//name
			"Kaffeetasse [cup coffee]",
			//enum/id
			CUP_COFFEE,
			//description
			"Frischer Kaffee... Yammy",
			//interactDescription
			"Bei dem Versuch die Kaffeetasse hochzuheben, schmeißt du sie um, wodurch du einen schönen Kurzschluss verursachst. Wenn du Glück hast, hast du nur dich damit getötet und nicht gleich die ganze Welt!",
			//visible
			false,
			//collected
			false
		};
		items.push_back(&item);

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
