#ifndef SCRIPTENGINE_HEADER_DETAILS_PARSERENGINE_INCLUDE_HH
#	define SCRIPTENGINE_HEADER_DETAILS_PARSERENGINE_INCLUDE_HH

#	ifdef SCRIPTENGINE_MODULE
import ScriptEngine.LexerEngine;

import std.core;
import std.memory;
#	else
#		include <ScriptEngine/LexerEngine.hh>

#		include <iostream>
#		include <memory>
#		include <string>
#	endif

#endif