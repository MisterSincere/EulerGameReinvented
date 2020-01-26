/////////////////////////////////////////////////////////////////////
// Filename: GameManager.cpp
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#include "GameManager.h"

#if defined(_WIN32)
# include <Windows.h>
# include <io>
# define WRITE_UNICODE int __prevMode{ _setmode(_fileno(stdout), _O_U16TEXT) };
# define WRITE_RESTORE _setmode(_fileno(stdout), __prevMode);
#else
# include <locale>
# define WRITE_UNICODE (void)0
# define WRITE_RESTORE (void)0
#endif
#include <fcntl.h>

#include "EulerAdventure.h"
#include "Euler.h"
#include "Location.h"
#include "Tuna.h"
#include "ecaHelper.h"


ECA::GameManager::GameManager(EulerAdventure* pAdv, SCENES::Tuna* pTuna)
	: m_pAdv(pAdv)
	, m_pTuna(pTuna)
{
	assert(m_pAdv && m_pTuna);

	// Setup supported commands
	i_commands({
		STR("exit"),
		STR("explore"),
		STR("examine"),
		STR("examine inv"),
		STR("close"),
		STR("interact"),
		STR("interact inv"),
		STR("go"),
		STR("load"),
		STR("save"),
		STR("back"),
		STR("inventar"),
		});
}

bool ECA::GameManager::Handle(EEcstr text) {
	CORETOOLS::SpecificCmd cmd(text);
	if (i_commands < cmd) {
		EE_PRINT("[GAME_MANAGER] Input is not part of autocomplete cmd list!\n");
	}

	if (cmd == STR("exit")) {
		m_pAdv->ChangeGameState(MENU);
		return true;

	} else if (cmd == STR("close")) {
		m_pAdv->ChangeGameState(EXIT);
		return true;

	// Movement
	} else if (cmd == STR("go")) {
		
		// Concatenate all params together for the resulting room
		EEstring room;
		for (size_t i = 0u; i < cmd.params.size(); i++) room += cmd.params[i];

		// Search for at least a location that matches the desired room id, but keep searching for
		// perfect match, meaning also the same environemnt id as euler.
		RoomID roomID = strToRoomID(room.c_str());
		Location* newLoc{ nullptr };
		for (auto const& curLoc : m_locations) {
			if (ROOM_ID(curLoc.second->getID()) == roomID) {
				newLoc = curLoc.second;
				EnvironmentID envID = ENVIRONMENT_ID(curLoc.second->getID());
				if (envID & m_pEuler->getEnvironmentID()) break;
			}
		}

		// If we have found our new location , make a move
		if (newLoc) {
			m_pEuler->move(newLoc);
		} else {
			EE_PRINT("[GAMEMANAGER] Invalid input/location!\n");
		}

	// XPLORATION... YAY!!!
	} else if (cmd == STR("explore")) {

		static bool badExploration{ false };

		Location* pLocation = m_locations[m_pEuler->getCurLocation()];
		if (!pLocation->isExplored()) {
			m_pTuna->AddOutputText(pLocation->getDescription(DESC_EXPLORE));
			pLocation->explore();

			badExploration = false;
		} else if(!badExploration) {
			m_pTuna->AddOutputText(STR("Already explored, ya' bitch!!"));
			badExploration = true;
		}

	}

	return false;
}

void ECA::GameManager::Init() {
	LocationDescriptions description;
	LocationCreateInfo locationCInfo;
	Student student;
	Item item;
	std::vector<Item> items;
	std::vector<Student> students;
	std::vector<LocationID> exits;

	//--------------------------------------------------------------------------
	// Office
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("In deinem Büro ist mittig ein überfüllter Schreibtisch [desk] an dem ein Scott Chefsessel mit original Kunstleder im Wert von 500€ steht [chair]. Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes.");
	description.explore					= STR("Das Büro ist nicht besonders groß, aber du bist trotzdem stolz auf deinen Chefsessel. Außerdem steht eine Vitrine in dem Raum, in der deine Preise und Trophäen stehen.");
	description.alreadyExplored	= STR("Der Raum ist nicht besonders groß, aber auf deinen Chefsessel bist du trotzdem stolz und natürlich auf deine Preis und Trophäen in deiner Vitrine.");
	description.enter						= STR("Du gehst in dein Büro.");

	items.clear();
	students.clear();
	exits.clear();

	// Chair
	item.id									 = ITEM_CHAIR;
	item.name								 = STR("Stuhl [chair]");
	item.description				 = STR("Ein Scott Chefsessel aus original Kunstleder im Wert von 500€, der nur dir gehört.");
	item.interactDescription = STR("Du setzt dich auf deinen Stuhl.\nEs macht knack und du sitzt auf'm Boden... Das Steak zum Frühstück war wohl doch zu viel.");
	item.visible						 = true;
	item.collected					 = false;
	items.push_back(item);

	// Working desk
	item.id									 = ITEM_DESK;
	item.name								 = STR("Schreibtisch [desk]");
	item.description				 = STR("Dieser Schreibtisch braucht eine neue Lackierung. Achso, und ein Putzkommando!\nTrotz der Unordnung fällt dir ein vollgekritzeltes Papier [paper] auf, auf dem du dein letztes Meisterwerk, das Ergebnis der unendlichen Summe, niedergeschrieben hast!");
	item.interactDescription = nullptr;	// TODO
	item.visible						 = true;
	item.collected					 = false;
	items.push_back(item);

	// Riddle solution paper
	item.id										= ITEM_PAPER;
	item.name									= STR("Rätsellösung [paper]");
	item.description					= STR("Du hast hier die Summe der Unendlichkeit errechnet. Sie lautet -1/12!");
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_UP);

	locationCInfo.id						= LOCATION_OFFICE;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students			= students;
	locationCInfo.name					= STR("Büro [office]");
	locationCInfo.description	= description;
	locationCInfo.explored			= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Korridor obere Etage
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Im Korridor angekommen siehst du mehrere Räume.");
	description.explore					= STR("Was willste wissen? Es ist nur ein typischer langweiliger Korridor, mit einem Kaffeelöscherkasten [extinguisher box], wie man's in Uni's gewohnt ist!");
	description.alreadyExplored = STR("Ein typischer Korridor mit einem Kaffeelöscherkasten [extinguisherbox]. Ist halt 'ne Uni!");
	description.enter						= STR("Du gehst in den Korridor.");

	items.clear();
	students.clear();
	exits.clear();

	// Coffee extinguisher box
	item.id						= ITEM_COFFEE_EXTINGUISHER_BOX;
	item.name					= STR("Kaffeelöscherkasten [coffeeextinguisherbox]");
	item.description	= STR("Dieser Kasten beinhaltet einen Kaffeelöscher [coffeeextinguisher], dieser ist der (un)natürlichste Bestandteil einer Feuerwehrausrüstung! Der Kasten ist durch ein elektronisches Sicherheitsschloss gesichert!");
	item.visible			= false;
	item.collected		= false;
	items.push_back(item);

	// Coffee extinguisher
	item.id										= ITEM_COFFEE_EXTINGUISHER;
	item.name									= STR("Kaffeelöscher [coffeeextinguisher]");
	item.description					= STR("Ein Feuerlöscher mit komisch riechendem Kaffee gefüllt.");
	item.interactDescription	= STR("Jetzt bist du ein wahrer Feuerwerhmann.... Naja, nicht ganz, aber fast.\nDer Wille zählt!");
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_OFFICE);
	exits.push_back(LOCATION_COFFEE_ROOM);
	exits.push_back(LOCATION_CONFERENCE_ROOM);
	exits.push_back(LOCATION_PRINCIPALS_ROOM);
	exits.push_back(LOCATION_GENTLEMENS_TOILET_UP);
	exits.push_back(LOCATION_LADIES_TOILET_UP);
	exits.push_back(LOCATION_STAIRWELL);
	exits.push_back(LOCATION_ELEVATOR);

	locationCInfo.id					= LOCATION_CORRIDOR_UP;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Korridor [corridor]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Lethal coffee room
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Dies ist der Kaffee- und Kuchenraum der Lehrer.\nDu siehst eine neumodische Ikea Küche, mit vielen Küchenschränken [cupboards] auf denen eine uralte verrostete vermutlich aus dem 1. Weltkrieg stammende Kaffeemaschine [coffeemachine] und eine Mikrowelle steht!");
	description.explore					= STR("Du fragst dich, ws in den ganzen Küchenschränken [cupboards] sein könnte und warum der Boden hier höher ist!");
	description.alreadyExplored = STR("Weißt du noch als du dich gefragt hast was in den ganzen Küchenschränken sein könnte und warum der Boden hier höher ist?");
	description.enter						= STR("Du gehst in den Kaffeeraum.");

	items.clear();
	students.clear();
	exits.clear();

	// Coffee machine
	item.id										= ITEM_COFFEE_MACHINE;
	item.name									= STR("Kaffeemaschine [coffeemachine]");
	item.description					= STR("Eine hochwertige billige Kaffeemaschine, die nicht funktioniert. Irgendwer muss wohl das Stromkabel rausgezogen haben.");
	item.interactDescription	= STR("Du willst den Stecker in die Steckdose stecken, aber die Steckdose will das nun halt nicht und gibt dir deswegen einen tödlichen Stromschlag.");
	item.visible							= true;
	item.collected						= false;
	items.push_back(item);

	// Kitchen cupboards
	item.id										= ITEM_CUPBOARDS;
	item.name									= STR("Küchenschränke [cupboards]");
	item.description					= STR("Unter einem der Schränke ist ein Hohlraum, welcher unter dem ganzen Kaffeeraum hindurch führt zu einem geheimen Raum [chamber].");
	item.interactDescription  = nullptr; // TODO
	item.visible							= true;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_UP);
	exits.push_back(LOCATION_CONFERENCE_ROOM);

	locationCInfo.id					= LOCATION_COFFEE_ROOM;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Kaffeeraum [coffeeroom]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Teacher's room
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("In diesem Raum werden Konferenzen zu wichtigen Themen abgehalten und unwichtigen, aber die betreffen dich ja eh nicht!\nEinem Konferenzraum entsprechend befindet sich in der Mitte ein Tisch in der Form eines U's. Außerdem hängt an der Wand ein Stundenplan und ein Schrank mit den Fächern für die Lehrer.");
	description.explore					= STR("Die Lehrer starren dich aus großen Augen an. Du bist wohl mitten in eine Versammlung reingeplatzt. Kann dir auch egal sein, ist keine Konferenz von der du weißt. Dir fällt der Ventilationsschact [ventilation shaft] auf, bei dem das Gitter nur noch an den Schacht gelehnt ist.");
	description.alreadyExplored = STR("Die Konferenz wird wohl nie enden. Der Ventilationsschacht [ventilationshaft] ist auch echt auffällig.");
	description.enter						= STR("Du gehst in den Konferenzraum.");

	items.clear();
	students.clear();
	exits.clear();

	// Ventilation shaft
	item.id										= ITEM_VENTILATION_SHAFT;
	item.name									= STR("Lüftungsschacht [ventilationshaft]");
	item.description					= STR("Du entdeckst einen Geheimraum [ventroom].");
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_UP);
	exits.push_back(LOCATION_COFFEE_ROOM);

	locationCInfo.id					= LOCATION_CONFERENCE_ROOM;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Konferenzraum [conferenceroom]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Chamber of the void
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Dieser Raum sieht aus als wenn hier seit Jahren niemand mehr drin gewesen wäre.");
	description.explore					= STR("Du siehst eine deiner Notizen [note] zwischen zwei Kartons gequetscht. Keine Ahnung wie der Windstoß das verursachen konnte...");
	description.alreadyExplored = STR("Eine deiner Notizen [note] liegt zwischen zwei Kartons.");
	description.enter						= STR("Du betrittst die Kammer der Leere.");

	items.clear();
	students.clear();
	exits.clear();

	// Note
	item.id										= ITEM_NOTE_1;
	item.name									= STR("Notiz [note]");
	item.description					= nullptr; // TODO
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_COFFEE_ROOM);

	locationCInfo.id						= LOCATION_CHAMBER;
	locationCInfo.items					= items;
	locationCInfo.exits					= exits;
	locationCInfo.students			= students;
	locationCInfo.name					= STR("Kammer der Leere [chamber]");
	locationCInfo.description		= description;
	locationCInfo.explored			=	false;
	locationCInfo.visible				= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Ventilation room
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Ein Ventilationsraum. Alt, veranzt und staubig. Gelüftet wurde hier schon seit Jahren nicht mehr!");
	description.explore					= STR("Du siehst eine deiner Notizen [note].");
	description.alreadyExplored = STR("Aber immerhin liegt hier eine deiner Notizen.");
	description.enter						= STR("Du schwebst in den Ventilationsraum.");

	items.clear();
	students.clear();
	exits.clear();

	// Note
	item.id										= ITEM_NOTE_2;
	item.name									= STR("Notiz [note]");
	item.description					= nullptr; // TODO
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CONFERENCE_ROOM);

	locationCInfo.id					= LOCATION_VENTILATION_ROOM;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Ventilationsraum [ventroom]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Ladies' toilets upper level
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("In der Damentoilette angekommen, sieht Kollegin Stelz dich irritiert an und geht mit den Worten: \"Sie überraschen mich immer wieder\" raus.\nBeschreibung: Warst du noch nie in einer Damentoilette?!");
	description.explore					= STR("Jetzt bloß nicht spülen. Es sei denn du magst keine Skilbooks... [skillbook]. Bei diesem Skillbook scheinst du deine Beamfähigkeit erlernen zu können.");
	description.alreadyExplored = STR("Naja, hier liegt halt noch so ein lahmes Skillbook [skillbook].");
	description.enter						= STR("Du perversierst in die Damentoilette.");

	items.clear();
	students.clear();
	exits.clear();

	// Skillbook
	item.id										= ITEM_SKILL_BOOK;
	item.name									= STR("Skillbook [skillbook]");
	item.description					= STR("Dies ist das verstaubte Skillbook des toten Beammeisters.");
	item.interactDescription  = STR("Du kannst dich nun beamen!");
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_UP);

	locationCInfo.id					= LOCATION_LADIES_TOILET_UP;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Damentoilette [ladiestoilet]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Mens' toilet upper level
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Als du die Herrentoilette betrittst, weht dir ein animalischer Duft entgegen, welchen du dem ebenfalls \"leicht\" animalischen Direktor zuordnest!");
	description.explore					= STR("Der Geruch ist wirklich unerträglich. Lange wirst du es hier nicht mehr aushalten können.");
	description.alreadyExplored = STR("Der Geruch ist wirklich unerträglich. Lange wirst du es hier nicht mehr aushalten können.");
	description.enter						= STR("Du gehst in die Herrentoilette.");

	items.clear();
	students.clear();
	exits.clear();

	exits.push_back(LOCATION_CORRIDOR_UP);

	locationCInfo.id					= LOCATION_GENTLEMENS_TOILET_UP;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Herrentoilette [gentlemenstoilet]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Principals' room
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Das Büro des Direktors ist ähnlich wie deines, über den vermüllten Schreibtisch schaut dich ein grimmiger Haufen Kalorien an. Dies müsste deiner mathematisch hoch komplexen Überlegungen nach der Direktor sein.");
	description.explore					= STR("Meisterhaft in Inneneinrichtung hat der Direktor hier einen braunen Tisch, zwei graue Stühle und eine Ansammlung von an Krawatten erhängten Skeletten.\nEr ist damit beschäftigt, Frederic Chopin's neunte Death Metal Komposition zu hören.");
	description.alreadyExplored = STR("Der Direktor hört noch immer laute Musik von Frederic Chopin.");
	description.enter						= STR("Du stolzierst in das Büro des Schulleiters.");

	items.clear();
	students.clear();
	exits.clear();

	exits.push_back(LOCATION_CORRIDOR_UP);

	locationCInfo.id					= LOCATION_PRINCIPALS_ROOM;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Schulleiterraum [principalsroom]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Elevator
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("An einer der blank geputzten grauen Fahrstuhlwände steht:\"Im Brandfall nicht benutzbar!\".");
	description.explore					= STR("Erst jetzt fällt dir der Gully [gully] auf dem Boden auf. Wo der wohl hinführt...\nUm das herauszufinden wirst du definitiv so etwas wie einen Hebel benötigen.\nDie Feueraxt [fire ax] ist dir eigentlich schon vorher aufgefallen, doch vielleicht wird sie jetzt wichtig?");
	description.alreadyExplored = STR("Auch ein Gullideckel ist hier noch. #normal");
	description.enter						= STR("So gehe er in das Objekt, welches auch als ein fahrender Stuhl bezeichnet wird.");

	items.clear();
	students.clear();
	exits.clear();

	// Fire axe
	item.id										= ITEM_FIRE_AXE;
	item.name									= STR("STR(Feueraxt [fireax]");
	item.description					= STR("Es ist eine Feueraxt!");
	item.interactDescription	= STR("Diese Axt gehört zur Grundausstattung eines Feuerbekämpfers.");
	item.visible							= true;
	item.collected						= false;
	items.push_back(item);

	// Gully
	item.id										= ITEM_GULLY;
	item.name									= STR("Gulli [gully]");
	item.description					= STR("Ein Gullideckel... er ist eckig, er ist halt auch ein Individuum.\nDu brauchst irgendeinen Trick um den Gullideckel anheben zu können.");
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_UP);

	locationCInfo.id					= LOCATION_ELEVATOR;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Fahrstuhl [elevator]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Staircase
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Ein Treppenhaus...       es brennt!");
	description.explore					= STR("Das Feuer ist echt unverschämt! Es blockiert dir doch tatsächlich den Weg in den ersten Stock [floor 1]. Was bildet es sich eigentlich ein?!");
	description.alreadyExplored = STR("Das Feuer blockiert dir immer noch den Weg in den ersten Stock [floor 1]!");
	description.enter						= STR("Du stolperst in das Treppenhaus.");

	items.clear();
	students.clear();
	exits.clear();

	exits.push_back(LOCATION_CORRIDOR_UP);
	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_STAIRWELL;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Treppenhaus [stairwell]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Corridor lower level
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Ein langer Korridor...\nAn ihm liegen vier vom Aufbau her identische Hörsäle, jedoch gehört der erste den musischen Wissenschaften, der zweite zu den literarischen, der dritte zu den gesellschaftlichen und als letztes kommt endlich der naturwissenschaftliche Hörsal.");
	description.explore					= STR("Grau. Und unspektakulär. Der Mülleimer muss unbedingt mal geleert werden.");
	description.alreadyExplored = STR("Grau. Und unspektakulär.");
	description.enter						= STR("Du langweilst dich in den Korridor.");

	items.clear();
	students.clear();
	exits.clear();

	exits.push_back(LOCATION_LECTURE_HALL_1);
	exits.push_back(LOCATION_LECTURE_HALL_2);
	exits.push_back(LOCATION_LECTURE_HALL_3);
	exits.push_back(LOCATION_LECTURE_HALL_4);
	exits.push_back(LOCATION_LOCKER_ROOM);
	exits.push_back(LOCATION_STORAGE_ROOM);
	exits.push_back(LOCATION_LADIES_TOILET_DOWN);
	exits.push_back(LOCATION_GENTLEMENS_TOILET_DOWN);
	exits.push_back(LOCATION_ELEVATOR);
	exits.push_back(LOCATION_STAIRWELL);

	locationCInfo.id					= LOCATION_CORRIDOR_DOWN;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Schüleretage [studentsfloor]");
	locationCInfo.description	= description;
	locationCInfo.explored		= false;
	locationCInfo.visible			= true;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Lecture hall 1
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Man darf sich bekanntlich nicht mehr fragen, ob musische Wissenschaften überhaupt als eine Wissenschaft gelten, da Künstler und Freidenker sich sonst angegriffen fühlen, aber ein Naturwissenschaftler wie du hat wohl besseres verdient!");
	description.explore					= STR("Der Professor liegt in ziemlich bizarren Posen auf dem Tisch und erklärt den Studenten(und Studentinnen), welche Pose welche Wirkung hat.\nDu kannst das Geld, dass für jede Pose gezahlt wird, förmlich von dem Direktor in die Tasche des Professors wandern sehen.\nHier steht noch Maribelle [student], obwohl sie wesentlich kleiner ist, schaut sie hochnäsig auf dich herab.");
	description.alreadyExplored = STR("Maribelle [student] stolziert hier immer noch herum.");
	description.enter						= STR("Du gehst in den ersten Hörsaal der Welt... ne warte.");


	items.clear();
	students.clear();
	exits.clear();

	// Maribelle
	student.name			= STR("Maribelle");
	student.defeated	= false;
	student.question	= STR("Ahh, Sie lassen sich also hier blicken, Herr Euler! Beantworten Sie mir doch, wie Chopin mit Vornamen hieß.");
	student.answer		= STR("Frederic");
	student.hint			= STR("Ahh, woher wissen Sie denn das. Als ich das letzte Mal im Konferenzraum war, war die Luft so stickig!\nJemand müsste mal den Lüftungsschacht untersuchen.");
	students.push_back(student);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_LECTURE_HALL_1;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Hörsaal 1 [lecturehall1]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Lecture hall 2
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Im vorderen Teil liest der Professor aus einem Buch einen Text in einer Sprache, die du nicht verstehst, während im hinteren Teil sich Schüler mit Käsekästchen, Schere-Stein-Papier und Battlefield die Zeit vertreiben.");
	description.explore					= STR("Schon wieder eine Runde 4-1 KD, der Schüler ist wirklich gut darin, Minen im richtigen Moment hochzujagen. Der Professer liest weiterhin monoton aus dem Buch vor.\nJochen [student] ist so gelangweilt, dass er deinen Schritten Aufmerksamkeit schenkt.");
	description.alreadyExplored = STR("Der Professer liest noch immer aus dem Buch vor, während dir Jochen noch immer hinterher starrt.");
	description.enter						= STR("Du gehst in den zweiten Hörsaal der Welt... ne warte");

	items.clear();
	students.clear();
	exits.clear();

	// Jochen
	student.name			= STR("Jochen");
	student.defeated	= false;
	student.question	= STR("Greetings Mate! Is english DLC working right know?");
	student.answer		= STR("No");
	student.hint			= STR("Oh, I see. Do you think locker 42 is somewhat special? Because I do think so!");
	students.push_back(student);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_LECTURE_HALL_2;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Hörsaal 2 [lecturehall2]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Lecture hall 3
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Der Lehrende zeigt aufgeregt auf eine Karte, welchen Schwerpunkt diese Vorlesung auch immer hat, eine Karte macht alles spannender! Sein Gegenspieler gewinnt in dem Pokerduell und jubelt laut auf!");
	description.explore					= STR("Alle Studierenden sind inzwischen wieder drin, während der Professor eine Runde in der Ecke schmollt.\nOh-oh, da kommt Anthon [student]");
	description.alreadyExplored = STR("Anthon [student] bemerkt dich sofort, als du den Raum betrittst.");
	description.enter						= STR("Du gehst in den dritten Hörsaal der...Ach was soll der Scheiß denn!");

	items.clear();
	students.clear();
	exits.clear();

	// Anthon
	student.name			= STR("Anthon");
	student.defeated	= false;
	student.question	= STR("Ehehe Euler, was sind Dreipacken minus Zweipacken?");
	student.answer		= STR("Einpacken"); // Really... feels dump to even write this one down!
	student.hint			= STR("Ihihi, fürchte dich vor Kaffe, der ist Tödlich!");
	students.push_back(student);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_LECTURE_HALL_3;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Hörsaal 3 [lecturehall3]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Lecture hall 4
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Dein Reich ist gerade von einem Chemieprofessor belegt. Dieser ist grade dabei mit peinlicher Sorgfalt den Tisch in alle vier Himmelsrichtungen gleichzeitig zu katapultieren!");
	description.explore					= STR("Die Frau braucht wieder einmal zu lange, du musst den Vortrag wohl beginnen, während sie noch Chemikalien mischt.\nGerhard [student], dein persöhnlicher Fanboy, starrt dich mit großen Augen an.");
	description.alreadyExplored = STR("Gerhards Blick bleibt sofort auf dir haften, als du in Raum gehst.");
	description.enter						= STR("Auf allen Vieren in Hörsaal 4 stolzieren.");

	items.clear();
	students.clear();
	exits.clear();
	
	// Gerhard
	student.name			= STR("Gerhard");
	student.defeated	= false;
	student.question	= STR("Moin Euler, sagen Sie doch mal Ihre Summe des Unendlichen!");
	student.answer		= STR("-1/12");
	student.hint			= STR("Boah, darauf wäre ich nicht gekommen!\nWissen Sie, warum der Boden im Kaffeeraum so hoch ist? Na, egal...");
	students.push_back(student);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_LECTURE_HALL_4;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Hörsaal 4 [lecturehall4]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Locker room
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Modrig steigt der Geruch ranziger Käsebrote durch die Lüftungsschlitze einiger Schließfächer, welche jedoch alle durch Algen in einem schönen Armee-Grünton gehalten werden. Alle? Nein, nicht alle! Eine glanzpolierte Marmorvariante, die dem Hausmeister gehört, koexistiert tatsächlich noch in diesem Raum.");
	description.explore					= STR("So viele Schließfächer [locker], und alle sind nummeriert. Verhindert wird jedoch eine genaue Identifikation des Hausmeisterfaches [shiny locker], da die Nummer wegpoliert wurde.");
	description.alreadyExplored = STR("Jedoch sind sowohl die Normalen [locker] als auch der Besondere [shiny locker] relativ uninteressant.");
	description.enter						= STR("Du gehst in den lockeren Raum. (Translator was fired in the process)");

	items.clear();
	students.clear();
	exits.clear();

	// Locker
	item.id										= ITEM_LOCKER;
	item.name									= STR("Spind [locker]");
	item.description					= nullptr; // TODO
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	// Locker 42
	item.id										= ITEM_SHINY_LOCKER;
	item.name									= STR("Spind 42 [shinylocker]");
	item.description					= nullptr; // TODO
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	// Note
	item.id										= ITEM_NOTE_3;
	item.name									= STR("Notiz [note]");
	item.description					= nullptr; // TODO
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_LOCKER_ROOM;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Spindraum [lockerroom]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Storage room
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Ein Mob, ein Eimer, ein Feuchttuch.... dich verwundert es, wie der Hausmeister nur mit diesen Sachen zumindest sein Revier so poliert");
	description.explore					= STR("Dir fällt ein Spachtel [spatula] auf, der eindeutig aus der Chemiesammlung genommen wurde. Hol zurück, was dir gehört!");
	description.alreadyExplored = STR("Hier liegt ein Spachtel [spatula], der eindeutig aus der Chemiesammlung genommen wurde.");
	description.enter						= STR("Du betrittst die Müllhalde.");

	items.clear();
	students.clear();
	exits.clear();

	// Spatula
	item.id										= ITEM_SPATULA;
	item.name									= STR("Spachtel [spatula]");
	item.description					= STR("Du wolltest ihn eigentlich der Chemiesammlung wiedergeben, aber er glänzt so schön.");
	item.interactDescription	= nullptr; // TODO
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_STORAGE_ROOM;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Abstellraum [storeroom]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Ladies' toilet lower level
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Es riecht herrlich nach Einhorn und Regenbogen, und nach dem alkohoisierten Hausmeister, der dabei ist den Lippenstift vom Spiegel zu entfernen und dich nicht bemerkt.");
	description.explore					= STR("Es ist ein Graus, Steven hat sich von Rebecca getrennt, und Grün ist das neue Schwarz, zumindest nach den Tratschtanten auf dem Klo.");
	description.alreadyExplored = STR("Die Tratschtanten reden noch immer.");
	description.enter						= STR("Du gehst mal wieder in eine Damentoilette.");

	items.clear();
	students.clear();
	exits.clear();

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_LADIES_TOILET_DOWN;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Damentoilette [ladiestoilet]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Mens' toilet lower level
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Das Putzfrauenspecialcorps hat sich gestern zur Aufgabe gemacht den grünen Schleim von der Wand zu entfernen... Nur noch ein wenig Neutralreiniger auf dem Boden und eine Cap, mit dem Wort \"Obey\", schaukelnd an einer Lampe, sind noch übrig geblieben.");
	description.explore					= STR("Der Schleim heißt Wilhelm von Kaiser [wilhelm] und verkauft während der Pausen Katzenbabys für diejenigen in Not, ein sehr angenehmer Geselle.");
	description.alreadyExplored = STR("Wilhelm von Kaiser [wilhelm] schleimt noch immer hier rum.");
	description.enter						= STR("Du gehst in die Herrentoilette.");

	items.clear();
	students.clear();
	exits.clear();

	// Note
	item.id										= ITEM_NOTE_4;
	item.name									= STR("Notiz [note]");
	item.description					= nullptr;
	item.interactDescription	= nullptr;
	item.visible							= true;
	item.collected						= false;
	items.push_back(item);

	exits.push_back(LOCATION_CORRIDOR_DOWN);

	locationCInfo.id					= LOCATION_GENTLEMENS_TOILET_DOWN;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Herrentoilette [gentlemenstoilet]");
	locationCInfo.description	= description;
	locationCInfo.visible			= true;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);

	//--------------------------------------------------------------------------
	// Elevator shaft
	//--------------------------------------------------------------------------
	description.defaultStr					= STR("Im Raum angekommen fällt dir sofort die ganze Elektronik hier unten auf. Ob hier noch mehr ist?");
	description.explore					= STR("Hier liegt eine Kaffeetasse mit, wer hätte es gedacht, heißem Kaffee [cup coffee] drin.");
	description.alreadyExplored = STR("FANCY DESCRIPTION"); // TODO
	description.enter						= STR("Du gehst in den Schaft des fahrenden Stuhls.");

	items.clear();
	students.clear();
	exits.clear();

	// Cup of coffee
	item.id										= ITEM_CUP_COFFEE;
	item.name									= STR("Kaffeetasse [cupcoffee]");
	item.description					= STR("Frischer Kaffee... Yammy");
	item.interactDescription	= STR("Bei dem Versuch die Kaffeetasse hochzuheben, schmeißt du sie um, wodurch du einen schönen Kurzschluss verursachst. Wenn du Glück hast, hast du nur dich damit getötet und nicht gleich die ganze Welt!");
	item.visible							= false;
	item.collected						= false;
	items.push_back(item);

	locationCInfo.id					= LOCATION_ELEVATOR_SHAFT;
	locationCInfo.items				= items;
	locationCInfo.exits				= exits;
	locationCInfo.students		= students;
	locationCInfo.name				= STR("Fahrstuhlschacht [elevatorshaft]");
	locationCInfo.description	= description;
	locationCInfo.visible			= false;
	locationCInfo.explored		= false;
	m_locations[locationCInfo.id] = new ECA::Location(locationCInfo);



	// Create the almighty euler himself
	m_pEuler = new ECA::Euler(m_pTuna, m_locations[LOCATION_OFFICE]);
}

void ECA::GameManager::PrintCurrentState()
{	
	// We use some fancy unicode symbols to keep the mass of details enjoyable
  WRITE_UNICODE;

	EE_PRINTW("\n||GAME_STATE||");

	// Iterate through all locations and let them print their informations to the console
	for (auto const& curLocation : m_locations) curLocation.second->printDetails();

	// Needs to be reseted for other prints to the console that would fail otherwise
	WRITE_RESTORE;
}
