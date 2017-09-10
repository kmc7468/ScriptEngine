#ifdef SCRIPTENGINE_MODULE
import ScriptEngine;
import std.core;
#else
#	include <ScriptEngine/ScriptEngine.hh>
#	include <iostream>
#endif

int main()
{
	auto engine = ScriptEngine::make_engine();
	engine->name("Test");
	
	engine->dump();

	return 0;
}