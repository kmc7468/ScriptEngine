#ifdef SCRIPTENGINE_MODULE
import ScriptEngine.ParserEngine;
#else
#	include <ScriptEngine/ParserEngine.hh>
#endif

#include <ScriptEngine/Details/ParserEngine.include.hh>

namespace ScriptEngine
{
	ParserEngine::ParserEngine()
	{}
	ParserEngine::~ParserEngine()
	{}

	ParserEngine::Ptr ParserEngine::make()
	{
		return std::make_shared<ParserEngine>();
	}

	void ParserEngine::dump() const
	{
		dump(std::cout);
	}
	void ParserEngine::dump(int depth) const
	{
		dump(std::cout, depth);
	}
	void ParserEngine::dump(std::ostream& out) const
	{
		dump(out, 0);
	}
	void ParserEngine::dump(std::ostream& out, int depth) const
	{
		static auto prefix = [](int depth)
		{
			return std::string(depth * 4, ' ');
		};

		out << prefix(depth) << "ParserEngine:\n";

		token_type_.dump(depth + 1);
	}

	TokenType ParserEngine::token_type() const
	{
		return token_type_;
	}
	TokenType ParserEngine::token_type(const TokenType& token_type)
	{
		return token_type_ = token_type;
	}

	ParserEnginePtr make_parser_engine()
	{
		return ParserEngine::make();
	}
}