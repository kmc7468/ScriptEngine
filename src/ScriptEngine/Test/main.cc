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
	auto token_type = se::TokenType::make()
		["none"]["identifier"]["integer"]["string"];

	auto engine = se::make_engine();
	engine->token_type(token_type);
	engine->dump();

	return 0;
}