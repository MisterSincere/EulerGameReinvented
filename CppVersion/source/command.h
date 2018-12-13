#pragma once

//////////////
// INCLUDES //
//////////////
#include <string>
#include <cassert>
#include <vector>


namespace CORETOOLS
{

	struct Cmd
	{
		/// Constructors for string and cstring
		Cmd(std::string const& cmd) : p_text(cmd.c_str()) {}
		Cmd(char const* cmd) : p_text(cmd) {}

		/// Get the cstring data
		char const* get() { return p_text; }

		/// Assignment for string and cstring
		Cmd operator=(std::string const& cmd) { p_text = cmd.c_str(); }
		Cmd operator=(char const* cmd) { p_text = cmd; }

		/// Equal operators for Command, string and cstring
		bool operator==(Cmd cmd) const { return (strcmp(p_text, cmd.p_text) == 0); }
		bool operator==(std::string const& cmd) const { return (strcmp(p_text, cmd.c_str()) == 0); }
		bool operator==(char const* cmd) const { return (strcmp(p_text, cmd) == 0); }

		char operator[](unsigned int index) { return p_text[index]; }

		char const* p_text;
	};

	struct CmdList
	{
		// [] operator for string and cstring comparison
		Cmd operator[](unsigned int i) { return p_cmds[i]; }
		Cmd operator[](std::string const& cmd) const { return operator[](cmd.c_str()); }
		Cmd operator[](char const* cmd) {
			auto el = std::find(p_cmds.begin(), p_cmds.end(), cmd);
			if (el == p_cmds.end()) assert(false);
			return *el;
		}

		// Wrapper for vector iterators
		auto begin() const { return p_cmds.begin(); }
		auto end() const { return p_cmds.end(); }

		// += operator to be able to add commands with string and cstring
		CmdList operator+=(char const* cmd) { p_cmds.emplace_back(cmd); return *this; }
		CmdList operator+=(std::string const& cmd) { p_cmds.emplace_back(cmd); return *this; }
		CmdList operator+=(Cmd cmd) { p_cmds.push_back(cmd); return *this; }

		std::vector<Cmd> p_cmds;
	};
}