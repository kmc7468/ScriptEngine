#ifdef SCRIPTENGINE_MODULE
import ScriptEngine.Engine;
#else
#	include <ScriptEngine/Engine.hh>
#endif

#include <ScriptEngine/Details/Engine.include.hh>

namespace ScriptEngine
{
	Engine::Engine()
	{}
	Engine::~Engine()
	{}

	Engine::Ptr Engine::make()
	{
		return std::make_shared<Engine>();
	}

	void Engine::dump() const
	{
		dump(std::cout);
	}
	void Engine::dump(std::ostream& out) const
	{
		static auto prefix = [](int depth)
		{
			return std::string(depth * 4, ' ');
		};

		out << "Engine:\n";

		out << prefix(1) << "Name: " << name_ << '\n';
	}

	std::string Engine::name() const
	{
		return name_;
	}
	std::string Engine::name(const std::string& new_name)
	{
		return name_ = new_name;
	}

	EnginePtr make_engine()
	{
		return Engine::make();
	}
}