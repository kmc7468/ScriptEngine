#ifdef SCRIPTENGINE_MODULE
import ScriptEngine;
import std.core;
#else
#	include <ScriptEngine/ScriptEngine.hh>
#	include <iostream>
#endif

int main()
{
	ScriptEngine::Engine e;
	e.name("asdf");

	std::cout << e.name() << std::endl;

	return 0;
}