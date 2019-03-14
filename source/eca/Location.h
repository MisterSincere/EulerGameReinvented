/////////////////////////////////////////////////////////////////////
// Filename: Location.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

#include "ecaDefs.h"

namespace ECA {

	class Location {
	public:
		Location(LocationCreateInfo const& cinfo);
		~Location();


		bool isExplored() const;
		bool isVisible() const;
		bool isAdjacent(LocationID) const;

		void explore();
		void setExplored(bool explored);
		void setVisible(bool visibility);

		void addExit(LocationID);
		void removeExit(LocationID);

		void setDescription(LocationDescriptionType which, EEcstr);
		EEcstr getDescription(LocationDescriptionType which) const;

		LocationID getID() const;

		void printDetails() const;

		bool operator==(Location const&) const;
		

	private:
		LocationID							m_id;
		EEcstr									m_name;
		std::vector<Item>				m_items;
		std::vector<LocationID> m_exits;
		std::vector<Student>		m_students;
		LocationDescriptions		m_descriptions;
		bool										m_isVisible;
		bool										m_isExplored;

	};

}