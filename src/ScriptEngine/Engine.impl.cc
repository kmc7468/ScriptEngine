#ifdef SCRIPTENGINE_MODULE
import ScriptEngine.Engine;
#else
#	include <ScriptEngine/Engine.hh>
#endif

#include <ScriptEngine/Details/Engine.include.hh>

namespace ScriptEngine
{
	std::string Engine::name() const
	{
		return name_;
	}
	std::string Engine::name(const std::string& new_name)
	{
		return name_ = new_name;
	}
}