#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_ENGINE_HH
#		define SCRIPTENGINE_HEADER_ENGINE_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/Engine.include.hh>

SCRIPTENGINE_BEGIN

class Engine
{
public:
	std::string name() const;
	std::string name(const std::string& new_name);

private:
	std::string name_;
};

SCRIPTENGINE_END

#	endif
#endif