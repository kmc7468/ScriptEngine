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
	void Engine::dump(int depth) const
	{
		dump(std::cout, depth);
	}
	void Engine::dump(std::ostream& out) const
	{
		dump(out, 0);
	}
	void Engine::dump(std::ostream& out, int depth) const
	{
		static auto prefix = [](int depth)
		{
			return std::string(depth * 4, ' ');
		};

		out << prefix(depth) << "Engine:\n";

		lexer_engine.dump(depth + 1);
		parser_engine.dump(depth + 1);
	}

	TokenType Engine::token_type(const TokenType& token_type)
	{
		lexer_engine.token_type = token_type;
		parser_engine.token_type = token_type;

		return token_type;
	}

	EnginePtr make_engine()
	{
		return Engine::make();
	}
}