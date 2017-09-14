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

	void LexerEngine::dump() const
	{
		dump(std::cout);
	}
	void LexerEngine::dump(int depth) const
	{
		dump(std::cout, depth);
	}
	void LexerEngine::dump(std::ostream& out) const
	{
		dump(out, 0);
	}
	void LexerEngine::dump(std::ostream& out, int depth) const
	{
		static auto prefix = [](int depth)
		{
			return std::string(depth * 4, ' ');
		};

		out << prefix(depth) << "LexerEngine:\n";

		token_type_.dump(out, depth + 1);
	}

	TokenType LexerEngine::token_type() const
	{
		return token_type_;
	}
	TokenType LexerEngine::token_type(const TokenType& token_type)
	{
		return token_type_ = token_type;
	}

	LexerEnginePtr make_lexer_engine()
	{
		return LexerEngine::make();
	}
}