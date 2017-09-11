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

	LexerEnginePtr make_lexer_engine()
	{
		return LexerEngine::make();
	}
}