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
	engine->name("Test");
	
	engine->dump();

	auto tokentype = se::TokenType::make()
		["none"]["identifier"]["integer"]["string"];

	for (const auto& a : tokentype)
	{
		std::cout << a << std::endl;
	}

	return 0;
}