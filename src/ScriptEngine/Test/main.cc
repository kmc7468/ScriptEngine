#ifdef SCRIPTENGINE_MODULE
import ScriptEngine;
import std.core;
#else
#	include <ScriptEngine/ScriptEngine.hh>
#	include <iostream>
#endif

namespace se = ScriptEngine;

int main()
{
	auto engine = se::make_engine();
	engine->name = "Test";
	engine->dump();

	auto lexer_engine = se::make_lexer_engine();
	lexer_engine->token_type = se::TokenType::make()
		["none"]["identifier"]["integer"]["string"];
	lexer_engine->dump();

	return 0;
}