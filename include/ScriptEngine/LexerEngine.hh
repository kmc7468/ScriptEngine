#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_LEXERENGINE_HH
#		define SCRIPTENGINE_HEADER_LEXERENGINE_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/LexerEngine.include.hh>

SCRIPTENGINE_BEGIN

class LexerEngine
{
public:
	using Ptr = std::shared_ptr<LexerEngine>;

public:
	LexerEngine();
	LexerEngine(const LexerEngine& lexer_engine) = delete;
	~LexerEngine();

public:
	LexerEngine& operator=(const LexerEngine& lexer_engine) = delete;
	bool operator==(const LexerEngine& lexer_engine) const = delete;
	bool operator!=(const LexerEngine& lexer_engine) const = delete;

public:
	static Ptr make();

public:
	void dump(int depth = 0) const;
	void dump(std::ostream& out, int depth = 0) const;

public:
	TokenType token_type;
};

using LexerEnginePtr = LexerEngine::Ptr;

LexerEnginePtr make_lexer_engine();

SCRIPTENGINE_END

#	endif
#endif