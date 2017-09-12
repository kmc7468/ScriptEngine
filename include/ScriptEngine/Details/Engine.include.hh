#ifndef SCRIPTENGINE_HEADER_DETAILS_ENGINE_INCLUDE_HH
#	define SCRIPTENGINE_HEADER_DETAILS_ENGINE_INCLUDE_HH

#	ifdef SCRIPTENGINE_MODULE
import ScriptEngine.LexerEngine;
import ScriptEngine.ParserEngine;
import ScriptEngine.Token;

import std.core;
import std.memory;
#	else
#		include <ScriptEngine/LexerEngine.hh>
#		include <ScriptEngine/ParserEngine.hh>
#		include <ScriptEngine/Token.hh>

#		include <iostream>
#		include <memory>
#	endif

#endif