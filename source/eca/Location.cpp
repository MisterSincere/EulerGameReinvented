#include "Location.h"

#include <algorithm>
#include "ecaHelper.h"

ECA::Location::Location(LocationCreateInfo const& cinfo)
	: m_id(cinfo.id)
	, m_name(cinfo.name)
	, m_items(cinfo.items)
	, m_exits(cinfo.exits)
	, m_students(cinfo.students)
	, m_descriptions(cinfo.description)
	, m_isVisible(cinfo.visible)
	, m_isExplored(cinfo.explored)
{
}

ECA::Location::~Location()
{
	RELEASE_S(m_name);
	RELEASE_S(m_descriptions.defaultStr);
	RELEASE_S(m_descriptions.explore);
	RELEASE_S(m_descriptions.alreadyExplored);
	RELEASE_S(m_descriptions.enter);
}

bool ECA::Location::isExplored() const
{
	return m_isExplored;
}

bool ECA::Location::isVisible() const
{
	return m_isVisible;
}

bool ECA::Location::isAdjacent(LocationID const id) const
{
	for (auto const curID : m_exits) if (curID == id) return true;
	return false;
}

void ECA::Location::explore()
{
	m_isExplored = true;
	for (auto& item : m_items) item.visible = true;
}

void ECA::Location::setExplored(bool explored)
{
	m_isExplored = explored;
}

void ECA::Location::setVisible(bool visibility)
{
	m_isVisible = visibility;
}

void ECA::Location::addExit(LocationID id)
{
	if(!isAdjacent(id)) m_exits.push_back(id);
	else EE_INFO("[LOCATION] Location id %d (room: %s) is already an exit of this location!\n", id, ECA::roomIDToStr(ROOM_ID(id)));
}

void ECA::Location::removeExit(LocationID id)
{
	auto el = std::find(m_exits.begin(), m_exits.end(), id);
	if (el != m_exits.end()) m_exits.erase(el);
	else EE_INFO("[LOCATION] Location id %d (room: %s) was not found defined as an exit, so remove failed!\n", id, ECA::roomIDToStr(ROOM_ID(id)));
}

void ECA::Location::setDescription(LocationDescriptionType which, EEcstr str)
{
	switch (which) {
	case DESC_DEFAULT: m_descriptions.defaultStr = str;
	case DESC_EXPLORE: m_descriptions.explore = str;
	case DESC_ALREADY_EXPLORED: m_descriptions.alreadyExplored = str;
	case DESC_ENTER: m_descriptions.enter = str;
	}
}

EEcstr ECA::Location::getDescription(LocationDescriptionType which) const
{
	//if ((int)which > sizeof(LocationDescriptions)) return nullptr;
	//return reinterpret_cast<EEcstr>(reinterpret_cast<char const*>(&m_descriptions) + (int)which);
	switch (which) {
	case DESC_DEFAULT: return m_descriptions.defaultStr;
	case DESC_EXPLORE: return m_descriptions.explore;
	case DESC_ALREADY_EXPLORED: return m_descriptions.alreadyExplored;
	case DESC_ENTER: return m_descriptions.enter;
	default: return nullptr;
	}
}

LocationID ECA::Location::getID() const
{
	return m_id;
}



void ECA::Location::printDetails() const
{
	// General information about this location: name, explored, visibility, id
	EE_PRINTW("\n\n| \033[1;32m%s\033[0m | E:%s V:%s | \033[1;35m%02d\033[0m\n",
		m_name,
		(m_isExplored) ? L"■" : L"□",
		(m_isVisible) ? L"■" : L"□",
		m_id);

	EE_PRINTW("|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");

	// Descriptions
	EE_PRINTW("| \033[1;35mDESCRIPTIONS\033[0m:\n")
	EE_PRINTW("| | \033[0;35mDEFAULT:\033[0m %s\n",  m_descriptions.defaultStr);
	EE_PRINTW("| | \033[0;35mEXPLORE:\033[0m %s\n",  m_descriptions.explore);
	EE_PRINTW("| | \033[0;35mEXPLORED:\033[0m %s\n", m_descriptions.alreadyExplored);

	// Items
	if (!m_items.empty()) {
		EE_PRINTW("|\n");
		EE_PRINTW("| \033[1;35mITEMS:\033[0m\n");
		for (Item const& curItem : m_items) {
			EE_PRINTW("| | \033[1;35m%02d » \033[0m\033[0;35m%s\033[0m %svisible\033[0m %scollected\033[0m\n",
				curItem.id,
				curItem.name,
				(curItem.visible) ? L"\033[1;32m" : L"\033[1;31m",
				(curItem.collected) ? L"\033[1;32m" : L"\033[1;31m");
			EE_PRINTW("| | | \033[0;35mD:\033[0m %s\n", curItem.description);
			EE_PRINTW("| | | \033[0;35mI:\033[0m %s\n", curItem.interactDescription);
		}
	}

	// Students
	if (!m_students.empty()) {
		EE_PRINTW("|\n");
		EE_PRINTW("| \033[1;35mSTUDENTS:\033[0m\n");
		for (Student const& curStud : m_students) {
			EE_PRINTW("| | \033[1;35m%s %s\033[0m\t\n",
				(curStud.defeated) ? L"■" : L"□",
				curStud.name);
		}
	}

	// Exits
	if (!m_exits.empty()) {
		EE_PRINTW("|\n");
		EE_PRINTW("| \033[1;35mEXITS:\033[0m ");
		for (LocationID const loc : m_exits) EE_PRINTW("%02d ", loc);
		EE_PRINTW("\n");
	}

	EE_PRINTW("|________________________________________________________________________________________________\n");
}

bool ECA::Location::operator==(Location const& other) const
{
	EE_INFO("[Location] == operator overload called!\n");
	return other.m_id == this->m_id;
}
