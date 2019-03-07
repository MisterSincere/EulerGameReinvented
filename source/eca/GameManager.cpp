/////////////////////////////////////////////////////////////////////
// Filename: GameManager.cpp
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#include "GameManager.h"

#include "EulerAdventure.h"


ECA::GameManager::GameManager(EulerAdventure* pAdv)
	: m_pAdv(pAdv)
{
	assert(pAdv);

	// Setup supported commands
	i_commands += STR("exit");
	i_commands += STR("explore");
	i_commands += STR("examine");
	i_commands += STR("examine inv");
	i_commands += STR("close");
	i_commands += STR("interact");
	i_commands += STR("interact inv");
	i_commands += STR("go");
	i_commands += STR("load");
	i_commands += STR("save");
	i_commands += STR("back");
	i_commands += STR("inventar");
}

bool ECA::GameManager::Handle(EEcstr text) {
	if (i_commands[STR("exit")] == text) {
		m_pAdv->ChangeGameState(MENU);
		return true;

	} else if (i_commands[STR("close")] == text) {
		m_pAdv->ChangeGameState(EXIT);
		return true;
	}

	return false;
}

void ECA::GameManager::Init() {
	Description description;
	Location location;
	Student student;
	Item item;
	std::vector<Item*> items;
	std::vector<Student*> students;
	std::vector<LocationEnum> exits;

	//--------------------------------------------------------------------------
	// Office
	//--------------------------------------------------------------------------
	description.default = "In deinem B�ro ist mittig ein �berf�llter Schreibtisch [desk] an dem ein Scott Chefsessel mit original Kunstleder im Wert von 500� steht [chair]. Au�erdem stehen zwei Schr�nke in jeweils einer Ecke des Raumes.";
	description.explore = "Das B�ro ist nicht besonders gro�, aber du bist trotzdem stolz auf deinen Chefsessel. Au�erdem steht eine Vitrine in dem Raum, in der deine Preise und Troph�en stehen.";
	description.alreadyExplored = "Der Raum ist nicht besonders gro�, aber auf deinen Chefsessel bist du trotzdem stolz und nat�rlich auf deine Preis und Troph�en in deiner Vitrine.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Chair
	item.id = ITEM_CHAIR;
	item.name = "Stuhl [chair]";
	item.description = "Ein Scott Chefsessel aus original Kunstleder im Wert von 500�, der nur dir geh�rt.";
	item.interactDescription = "Du setzt dich auf deinen Stuhl.\nEs macht knack und du sitzt auf'm Boden... Das Steak zum Fr�hst�ck war wohl doch zu viel.";
	item.visible = true;
	item.collected = false;
	items.push_back(&item);

	// Working desk
	item.id = ITEM_DESK;
	item.name = "Schreibtisch [desk]";
	item.description = "Dieser Schreibtisch braucht eine neue Lackierung. Achso, und ein Putzkommando!\nTrotz der Unordnung f�llt dir ein vollgekritzeltes Papier [paper] auf, auf dem du dein letztes Meisterwerk, das Ergebnis der unendlichen Summe, niedergeschrieben hast!";
	item.interactDescription = nullptr;	// TODO
	item.visible = true;
	item.collected = false;
	items.push_back(&item);

	// Riddle solution paper
	item.id = ITEM_PAPER;
	item.name = "R�tsell�sung [paper]";
	item.description = "Du hast hier die Summe der Unendlichkeit errechnet. Sie lautet -1/12!";
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_UP);
	location.id = LOCATION_OFFICE;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "B�ro [office]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Korridor obere Etage
	//--------------------------------------------------------------------------
	description.default = "Im Korridor angekommen siehst du mehrere R�ume.";
	description.explore = "Was willste wissen? Es ist nur ein typischer langweiliger Korridor, mit einem Kaffeel�scherkasten [extinguisher box], wie man's in Uni's gewohnt ist!";
	description.alreadyExplored = "Ein typischer Korridor mit einem Kaffeel�scherkasten [extinguisher box]. Ist halt 'ne Uni!";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Coffee extinguisher box
	item.id = ITEM_COFFEE_EXTINGUISHER_BOX;
	item.name = "Kaffeel�scherkasten [coffee extinguisher box]";
	item.description = "Dieser Kasten beinhaltet einen Kaffeel�scher [coffee extinguisher], dieser ist der (un)nat�rlichste Bestandteil einer Feuerwehrausr�stung! Der Kasten ist durch ein elektronisches Sicherheitsschloss gesichert!";
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	// Coffee extinguisher
	item.id = ITEM_COFFEE_EXTINGUISHER;
	item.name = "Kaffeel�scher [coffee extinguisher]";
	item.description = "Ein Feuerl�scher mit komisch riechendem Kaffee gef�llt.";
	item.interactDescription = "Jetzt bist du ein wahrer Feuerwerhmann.... Naja, nicht ganz, aber fast.\nDer Wille z�hlt!";
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_OFFICE);
	exits.push_back(LOCATION_COFFEE_ROOM);
	exits.push_back(LOCATION_CONFERENCE_ROOM);
	exits.push_back(LOCATION_PRINCIPALS_ROOM);
	exits.push_back(LOCATION_GENTLEMENS_TOILET_UP);
	exits.push_back(LOCATION_STAIRWELL);
	exits.push_back(LOCATION_ELEVATOR);

	location.id = LOCATION_CORRIDOR_UP;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Korridor [corridor]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Lethal coffee room
	//--------------------------------------------------------------------------
	description.default = "Dies ist der Kaffee- und Kuchenraum der Lehrer.\nDu siehst eine neumodische Ikea K�che, mit vielen K�chenschr�nken [cupboards] auf denen eine uralte verrostete vermutlich aus dem 1. Weltkrieg stammende Kaffeemaschine [coffeemachine] und eine Mikrowelle steht!";
	description.explore = "Du fragst dich, ws in den ganzen K�chenschr�nken [cupboards] sein k�nnte und warum der Boden hier h�her ist!";
	description.alreadyExplored = "Wei�t du noch als du dich gefragt hast was in den ganzen K�chenschr�nken sein k�nnte und warum der Boden hier h�her ist?";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Coffee machine
	item.id = ITEM_COFFEE_MACHINE;
	item.name = "Kaffeemaschine [coffee machine]";
	item.description = "Eine hochwertige billige Kaffeemaschine, die nicht funktioniert. Irgendwer muss wohl das Stromkabel rausgezogen haben.";
	item.interactDescription = "Du willst den Stecker in die Steckdose stecken, aber die Steckdose will das nun halt nicht und gibt dir deswegen einen t�dlichen Stromschlag.";
	item.visible = true;
	item.collected = false;
	items.push_back(&item);

	// Kitchen cupboards
	item.id = ITEM_CUPBOARDS;
	item.name = "K�chenschr�nke [cupboards]";
	item.description = "Unter einem der Schr�nke ist ein Hohlraum, welcher unter dem ganzen Kaffeeraum hindurch f�hrt zu einem geheimen Raum [chamber].";
	item.interactDescription = nullptr; // TODO
	item.visible = true;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_UP);
	exits.push_back(LOCATION_CONFERENCE_ROOM);

	location.id = LOCATION_COFFEE_ROOM;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Kaffeeraum [coffeeroom]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Teacher's room
	//--------------------------------------------------------------------------
	description.default = "In diesem Raum werden Konferenzen zu wichtigen Themen abgehalten und unwichtigen, aber die betreffen dich ja eh nicht!\nEinem Konferenzraum entsprechend befindet sich in der Mitte ein Tisch in der Form eines U's. Au�erdem h�ngt an der Wand ein Stundenplan und ein Schrank mit den F�chern f�r die Lehrer.";
	description.explore = "Die Lehrer starren dich aus gro�en Augen an. Du bist wohl mitten in eine Versammlung reingeplatzt. Kann dir auch egal sein, ist keine Konferenz von der du wei�t. Dir f�llt der Ventilationsschact [ventilation shaft] auf, bei dem das Gitter nur noch an den Schacht gelehnt ist.";
	description.alreadyExplored = "Die Konferenz wird wohl nie enden. Der Ventilationsschacht [ventilation shaft] ist auch echt auff�llig.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Ventilation shaft
	item.id = ITEM_VENTILATION_SHAFT;
	item.name = "L�ftungsschacht [ventilation shaft]";
	item.description = "Du entdeckst einen Geheimraum [ventilationroom].";
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_UP);
	exits.push_back(LOCATION_COFFEE_ROOM);

	location.id = LOCATION_CONFERENCE_ROOM;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Konferenzraum [conference room]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Chamber of the void
	//--------------------------------------------------------------------------
	description.default = "Dieser Raum sieht aus als wenn hier seit Jahren niemand mehr drin gewesen w�re.";
	description.explore = "Du siehst eine deiner Notizen [note] zwischen zwei Kartons gequetscht. Keine Ahnung wie der Windsto� das verursachen konnte...";
	description.alreadyExplored = "Eine deiner Notizen [note] liegt zwischen zwei Kartons.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Note
	item.id = ITEM_NOTE_1;
	item.name = "Notiz [note]";
	item.description = nullptr; // TODO
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_COFFEE_ROOM);

	location.id = LOCATION_CHAMBER;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Kammer der Leere [chamber]";
	location.description = &description;
	location.explored = false;
	location.visible = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Ventilation room
	//--------------------------------------------------------------------------
	description.default = "Ein Ventilationsraum. Alt, veranzt und staubig. Gel�ftet wurde hier schon seit Jahren nicht mehr!";
	description.explore = "Du siehst eine deiner Notizen [note].";
	description.alreadyExplored = "Aber immerhin liegt hier eine deiner Notizen.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Note
	item.id = ITEM_NOTE_2;
	item.name = "Notiz [note]";
	item.description = nullptr; // TODO
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CONFERENCE_ROOM);

	location.id = LOCATION_VENTILATION_ROOM;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Ventilationsraum [ventilationroom]";
	location.description = &description;
	location.explored = false;
	location.visible = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Ladies' toilets upper level
	//--------------------------------------------------------------------------
	description.default = "In der Damentoilette angekommen, sieht Kollegin Stelz dich irritiert an und geht mit den Worten: \"Sie �berraschen mir immer wieder\" raus.\nBeschreibung: Warst du noch nie in einer Damentoilette?!";
	description.explore = "Jetzt blo� nicht sp�len. Es sei denn du magst keine Skilbooks... [skillbook]. Bei diesem Skillbook scheinst du deine Beamf�higkeit erlernen zu k�nnen.";
	description.alreadyExplored = "Naja, hier liegt halt noch so ein lahmes Skillbook [skillbook].";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Skillbook
	item.id = ITEM_SKILL_BOOK;
	item.name = "Skillbook [skillbook]";
	item.description = "Dies ist das verstaubte Skillbook des toten Beammeisters.";
	item.interactDescription = "Du kannst dich nun beamen!";
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_UP);

	location.id = LOCATION_LADIES_TOILET_UP;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Damentoilette [ladiestoilet]";
	location.description = &description;
	location.explored = false;
	location.visible = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Mens' toilet upper level
	//--------------------------------------------------------------------------
	description.default = "Als du die Herrentoilette betrittst, weht dir ein animalischer Duft entgegen, welchen du dem ebenfalls \"leicht\" animalischen Direktor zuordnest!";
	description.explore = "Der Geruch ist wirklich unertr�glich. Lange wirst du es hier nicht mehr aushalten k�nnen.";
	description.alreadyExplored = "Der Geruch ist wirklich unertr�glich. Lange wirst du es hier nicht mehr aushalten k�nnen.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	exits.push_back(LOCATION_CORRIDOR_UP);

	location.id = LOCATION_GENTLEMENS_TOILET_UP;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Herrentoilette [gentlemenstoilet]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Principals' room
	//--------------------------------------------------------------------------
	description.default = "Das B�ro des Direktors ist �hnlich wie deines, �ber den verm�llten Schreibtisch schaut dich ein grimmiger Haufen Kalorien an. Dies m�sste deiner mathematisch hoch komplexen �berlegungen nach der Direktor sein.";
	description.explore = "Meisterhaft in Inneneinrichtung hat der Direktor hier einen braunen Tisch, zwei graue St�hle und eine Ansammlung von an Krawatten erh�ngten Skeletten.\nEr ist damit besch�ftigt, Frederic Chopin's neunte Death Metal Komposition zu h�ren.";
	description.alreadyExplored = "Der Direktor h�rt noch immer laute Musik von Frederic Chopin.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	exits.push_back(LOCATION_CORRIDOR_UP);

	location.id = LOCATION_PRINCIPALS_ROOM;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Schulleiterraum [principalsroom]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Elevator
	//--------------------------------------------------------------------------
	description.default = "An einer der blank geputzten grauen Fahrstuhlw�nde steht:\"Im Brandfall nicht benutzbar!\".";
	description.explore = "Erst jetzt f�llt dir der Gully [gully] auf dem Boden auf. Wo der wohl hinf�hrt...\nUm das herauszufinden wirst du definitiv so etwas wie einen Hebel ben�tigen.\nDie Feueraxt [fire ax] ist dir eigentlich schon vorher aufgefallen, doch vielleicht wird sie jetzt wichtig?";
	description.alreadyExplored = "Auch ein Gullideckel ist hier noch. #normal";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Fire axe
	item.id = ITEM_FIRE_AXE;
	item.name = "Feueraxt [fire ax]";
	item.description = "Es ist eine Feueraxt!";
	item.interactDescription = "Diese Axt geh�rt zur Grundausstattung eines Feuerbek�mpfers.";
	item.visible = true;
	item.collected = false;
	items.push_back(&item);

	// Gully
	item.id = ITEM_GULLY;
	item.name = "Gulli [gully]";
	item.description = "Ein Gullideckel... er ist eckig, er ist halt auch ein Individuum.\nDu brauchst irgendeinen Trick um den Gullideckel anheben zu k�nnen.";
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_UP);

	location.id = LOCATION_ELEVATOR;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Fahrstuhl [elevator]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Staircase
	//--------------------------------------------------------------------------
	description.default = "Ein Treppenhaus...       es brennt!";
	description.explore = "Das Feuer ist echt unversch�mt! Es blockiert dir doch tats�chlich den Weg in den ersten Stock [floor 1]. Was bildet es sich eigentlich ein?!";
	description.alreadyExplored = "Das Feuer blockiert dir immer noch den Weg in den ersten Stock [floor 1]!";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	exits.push_back(LOCATION_CORRIDOR_UP);
	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_STAIRWELL;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Treppenhaus [stairwell]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Corridor lower level
	//--------------------------------------------------------------------------
	description.default = "Ein langer Korridor...\nAn ihm liegen vier vom Aufbau her identische H�rs�le, jedoch geh�rt der erste den musischen Wissenschaften, der zweite zu den literarischen, der dritte zu den gesellschaftlichen und als letztes kommt endlich der naturwissenschaftliche H�rsal.";
	description.explore = "Grau. Und unspektakul�r. Der M�lleimer muss unbedingt mal geleert werden.";
	description.alreadyExplored = "Grau. Und unspektakul�r.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	exits.push_back(LOCATION_LECTURE_HALL_1);
	exits.push_back(LOCATION_LECTURE_HALL_2);
	exits.push_back(LOCATION_LECTURE_HALL_3);
	exits.push_back(LOCATION_LECTURE_HALL_4);
	exits.push_back(LOCATION_LOCKER_ROOM);
	exits.push_back(LOCATION_STORE_ROOM);
	exits.push_back(LOCATION_LADIES_TOILET_DOWN);
	exits.push_back(LOCATION_GENTLEMENS_TOILET_DOWN);
	exits.push_back(LOCATION_ELEVATOR);
	exits.push_back(LOCATION_STAIRWELL);

	location.id = LOCATION_CORRIDOR_DOWN;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Sch�leretage [studentsfloor]";
	location.description = &description;
	location.explored = false;
	location.visible = true;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Lecture hall 1
	//--------------------------------------------------------------------------
	description.default = "Man darf sich bekanntlich nicht mehr fragen, ob musische Wissenschaften �berhaupt als eine Wissenschaft gelten, da K�nstler und Freidenker sich sonst angegriffen f�hlen, aber ein Naturwissenschaftler wie du hat wohl besseres verdient!";
	description.explore = "Der Professor liegt in ziemlich bizarren Posen auf dem Tisch und erkl�rt den Studenten(und Studentinnen), welche Pose welche Wirkung hat.\nDu kannst das Geld, dass f�r jede Pose gezahlt wird, f�rmlich von dem Direktor in die Tasche des Professors wandern sehen.\nHier steht noch Maribelle [student], obwohl sie wesentlich kleiner ist, schaut sie hochn�sig auf dich herab.";
	description.alreadyExplored = "Maribelle [student] stolziert hier immer noch herum.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	student.name = "Maribelle";
	student.defeated = false;
	student.question = "Ahh, Sie lassen sich also hier blicken, Herr Euler! Beantworten Sie mir doch, wie Chopin mit Vornamen hie�.";
	student.answer = "Frederic";
	student.hint = "Ahh, woher wissen Sie denn das. Als ich das letzte Mal im Konferenzraum war, war die Luft so stickig!\nJemand m�sste mal den L�ftungsschacht untersuchen.";

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_LECTURE_HALL_1;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "H�rsaal 1 [lecture hall 1]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Lecture hall 2
	//--------------------------------------------------------------------------
	description.default = "Im vorderen Teil liest der Professor aus einem Buch einen Text in einer Sprache, die du nicht verstehst, w�hrend im hinteren Teil sich Sch�ler mit K�sek�stchen, Schere-Stein-Papier und Battlefield die Zeit vertreiben.";
	description.explore = "Schon wieder eine Runde 4-1 KD, der Sch�ler ist wirklich gut darin, Minen im richtigen Moment hochzujagen. Der Professer liest weiterhin monoton aus dem Buch vor.\nJochen [student] ist so gelangweilt, dass er deinen Schritten Aufmerksamkeit schenkt.";
	description.alreadyExplored = "Der Professer liest noch immer aus dem Buch vor, w�hrend dir Jochen noch immer hinterher starrt.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	student.name = "Jochen";
	student.defeated = false;
	student.question = "Greetings Mate! Is english DLC working right know?";
	student.answer = "No";
	student.hint = "Oh, I see. Do you think locker 42 is somewhat special? Because I do think so!";

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_LECTURE_HALL_2;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "H�rsaal 2 [lecture hall 2]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Lecture hall 3
	//--------------------------------------------------------------------------
	description.default = "Der Lehrende zeigt aufgeregt auf eine Karte, welchen Schwerpunkt diese Vorlesung auch immer hat, eine Karte macht alles spannender! Sein Gegenspieler gewinnt in dem Pokerduell und jubelt laut auf!";
	description.explore = "Alle Studierenden sind inzwischen wieder drin, w�hrend der Professor eine Runde in der Ecke schmollt.\nOh-oh, da kommt Anthon [student]";
	description.alreadyExplored = "Anthon [student] bemerkt dich sofort, als du den Raum betrittst.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	student.name = "Anthon";
	student.defeated = false;
	student.question = "Ehehe Euler, was sind Dreipacken minus Zweipacken?";
	student.answer = "Einpacken"; // Really... feels dump to even write this one down!
	student.hint = "Ihihi, f�rchte dich vor Kaffe, der ist T�dlich!";

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_LECTURE_HALL_3;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "H�rsaal 3 [lecture hall 3]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Lecture hall 4
	//--------------------------------------------------------------------------
	description.default = "Dein Reich ist gerade von einem Chemieprofessor belegt. Dieser ist grade dabei mit peinlicher Sorgfalt den Tisch in alle vier Himmelsrichtungen gleichzeitig zu katapultieren!";
	description.explore = "Die Frau braucht wieder einmal zu lange, du musst den Vortrag wohl beginnen, w�hrend sie noch Chemikalien mischt.\nGerhard [student], dein pers�hnlicher Fanboy, starrt dich mit gro�en Augen an.";
	description.alreadyExplored = "Gerhards Blick bleibt sofort auf dir haften, als du in Raum gehst.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	student.name = "Gerhard";
	student.defeated = false;
	student.question = "Moin Euler, sagen Sie doch mal Ihre Summe des Unendlichen!";
	student.answer = "-1/12";
	student.hint = "Boah, darauf w�re ich nicht gekommen!\nWissen Sie, warum der Boden im Kaffeeraum so hoch ist? Na, egal...";

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_LECTURE_HALL_4;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "H�rsaal 4 [lecture hall 4]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Locker room
	//--------------------------------------------------------------------------
	description.default = "Modrig steigt der Geruch ranziger K�sebrote durch die L�ftungsschlitze einiger Schlie�f�cher, welche jedoch alle durch Algen in einem sch�nen Armee-Gr�nton gehalten werden. Alle? Nein, nicht alle! Eine glanzpolierte Marmorvariante, die dem Hausmeister geh�rt, koexistiert tats�chlich noch in diesem Raum.";
	description.explore = "So viele Schlie�f�cher [locker], und alle sind nummeriert. Verhindert wird jedoch eine genaue Identifikation des Hausmeisterfaches [shiny locker], da die Nummer wegpoliert wurde.";
	description.alreadyExplored = "Jedoch sind sowohl die Normalen [locker] als auch der Besondere [shiny locker] relativ uninteressant.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Locker
	item.id = ITEM_LOCKER;
	item.name = "Spind [locker]";
	item.description = nullptr; // TODO
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	// Locker 42
	item.id = ITEM_SHINY_LOCKER;
	item.name = "Spind 42 [shiny locker]";
	item.description = nullptr; // TODO
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	// Note
	item.id = ITEM_NOTE_3;
	item.name = "Notiz [note]";
	item.description = nullptr; // TODO
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_LOCKER_ROOM;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Spindraum [lockerroom]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Storage room
	//--------------------------------------------------------------------------
	description.default = "Ein Mob, ein Eimer, ein Feuchttuch.... dich verwundert es, wie der Hausmeister nur mit diesen Sachen zumindest sein Revier so poliert";
	description.explore = "Dir f�llt ein Spachtel [spatula] auf, der eindeutig aus der Chemiesammlung genommen wurde. Hol zur�ck, was dir geh�rt!";
	description.alreadyExplored = "Hier liegt ein Spachtel [spatula], der eindeutig aus der Chemiesammlung genommen wurde.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Spatula
	item.id = ITEM_SPATULA;
	item.name = "Spachtel [spatula]";
	item.description = "Du wolltest ihn eigentlich der Chemiesammlung wiedergeben, aber er gl�nzt so sch�n.";
	item.interactDescription = nullptr; // TODO
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_STORE_ROOM;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Abstellraum [storeroom]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Ladies' toilet lower level
	//--------------------------------------------------------------------------
	description.default = "Es riecht herrlich nach Einhorn und Regenbogen, und nach dem alkohoisierten Hausmeister, der dabei ist den Lippenstift vom Spiegel zu entfernen und dich nicht bemerkt.";
	description.explore = "Es ist ein Graus, Steven hat sich von Rebecca getrennt, und Gr�n ist das neue Schwarz, zumindest nach den Tratschtanten auf dem Klo.";
	description.alreadyExplored = "Die Tratschtanten reden noch immer.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_LADIES_TOILET_DOWN;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Damentoilette [ladiestoilet]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Mens' toilet lower level
	//--------------------------------------------------------------------------
	description.default = "Das Putzfrauenspecialcorps hat sich gestern zur Aufgabe gemacht den gr�nen Schleim von der Wand zu entfernen... Nur noch ein wenig Neutralreiniger auf dem Boden und eine Cap, mit dem Wort \"Obey\", schaukelnd an einer Lampe, sind noch �brig geblieben.";
	description.explore = "Der Schleim hei�t Wilhelm von Kaiser [wilhelm] und verkauft w�hrend der Pausen Katzenbabys f�r diejenigen in Not, ein sehr angenehmer Geselle.";
	description.alreadyExplored = "Wilhelm von Kaiser [wilhelm] schleimt noch immer hier rum.";

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Note
	item.id = ITEM_NOTE_4;
	item.name = "Notiz [note]";
	item.description = nullptr;
	item.interactDescription = nullptr;
	item.visible = true;
	item.collected = false;
	items.push_back(&item);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	location.id = LOCATION_GENTLEMENS_TOILET_DOWN;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Herrentoilette [gentlemenstoilet]";
	location.description = &description;
	location.visible = true;
	location.explored = false;
	m_locations[location.id] = &location;

	//--------------------------------------------------------------------------
	// Elevator shaft
	//--------------------------------------------------------------------------
	description.default = "Im Raum angekommen f�llt dir sofort die ganze Elektronik hier unten auf. Ob hier noch mehr ist?";
	description.explore = "Hier liegt eine Kaffeetasse mit, wer h�tte es gedacht, hei�em Kaffee [cup coffee] drin.";
	description.alreadyExplored = "FANCY DESCRIPTION"; // TODO

	items = std::vector<Item*>();
	students = std::vector<Student*>();
	exits = std::vector<LocationEnum>();

	// Cup of coffee
	item.id = ITEM_CUP_COFFEE;
	item.name = "Kaffeetasse [cup coffee]";
	item.description = "Frischer Kaffee... Yammy";
	item.interactDescription = "Bei dem Versuch die Kaffeetasse hochzuheben, schmei�t du sie um, wodurch du einen sch�nen Kurzschluss verursachst. Wenn du Gl�ck hast, hast du nur dich damit get�tet und nicht gleich die ganze Welt!";
	item.visible = false;
	item.collected = false;
	items.push_back(&item);

	location.id = LOCATION_ELEVATOR_SHAFT;
	location.items = items;
	location.exits = exits;
	location.students = students;
	location.name = "Fahrstuhlschacht [elevator shaft]";
	location.description = &description;
	location.visible = false;
	location.explored = false;
	m_locations[location.id] = &location;
}

void ECA::GameManager::PrintCurrentState()
{
	for (const auto& curLocation : m_locations) {
		
	}
}
