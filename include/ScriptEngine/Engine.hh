#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_ENGINE_HH
#		define SCRIPTENGINE_HEADER_ENGINE_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/Engine.include.hh>

SCRIPTENGINE_BEGIN

class Engine
{
public:
	using Ptr = std::shared_ptr<Engine>;

public:
	Engine();
	Engine(const Engine& engine) = delete;
	~Engine();

public:
	Engine& operator=(const Engine& engine) = delete;
	bool operator==(const Engine& engine) const = delete;
	bool operator!=(const Engine& engine) const = delete;

public:
	static Ptr make();

public:
	void dump() const;
	void dump(int depth) const;
	void dump(std::ostream& out) const;
	void dump(std::ostream& out, int depth) const;

public:
	TokenType token_type(const TokenType& token_type);

public:
	LexerEngine lexer_engine;
	ParserEngine parser_engine;
};

using EnginePtr = Engine::Ptr;

EnginePtr make_engine();

SCRIPTENGINE_END

#	endif
#endif