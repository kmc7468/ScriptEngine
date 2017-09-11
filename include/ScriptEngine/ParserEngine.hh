#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_PARSERENGINE_HH
#		define SCRIPTENGINE_HEADER_PARSERENGINE_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/ParserEngine.include.hh>

SCRIPTENGINE_BEGIN

class ParserEngine
{
public:
	using Ptr = std::shared_ptr<ParserEngine>;

public:
	ParserEngine();
	ParserEngine(const ParserEngine& engine) = delete;
	~ParserEngine();

public:
	ParserEngine& operator=(const ParserEngine& engine) = delete;
	bool operator==(const ParserEngine& engine) const = delete;
	bool operator!=(const ParserEngine& engine) const = delete;

public:
	static Ptr make();

public:
	void dump() const;
	void dump(int depth) const;
	void dump(std::ostream& out) const;
	void dump(std::ostream& out, int depth) const;

public:
	LexerEnginePtr lexer_engine = nullptr;

	std::string name;
};

using ParserEnginePtr = ParserEngine::Ptr;

ParserEnginePtr make_parser_engine();

SCRIPTENGINE_END

#	endif
#endif