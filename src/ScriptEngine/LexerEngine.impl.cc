#ifdef SCRIPTENGINE_MODULE
import ScriptEngine.LexerEngine;
#else
#	include <ScriptEngine/LexerEngine.hh>
#endif

#include <ScriptEngine/Details/LexerEngine.include.hh>

namespace ScriptEngine
{
	LexerEngine::LexerEngine()
	{}
	LexerEngine::~LexerEngine()
	{}

	LexerEngine::Ptr LexerEngine::make()
	{
		return std::make_shared<LexerEngine>();
	}

	void LexerEngine::dump(int depth) const
	{
		dump(std::cout, depth);
	}
	void LexerEngine::dump(std::ostream& out, int depth) const
	{
		static auto prefix = [](int depth)
		{
			return std::string(depth * 4, ' ');
		};

		out << prefix(depth) << "LexerEngine:\n";

		token_type.dump(out, depth + 1);
	}

	LexerEnginePtr make_lexer_engine()
	{
		return LexerEngine::make();
	}
}