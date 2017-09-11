#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_TOKEN_HH
#		define SCRIPTENGINE_HEADER_TOKEN_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/Token.include.hh>

SCRIPTENGINE_BEGIN

class TokenType final
{
public:
	TokenType();
	TokenType(const TokenType& token_type);
	TokenType(TokenType&& token_type) noexcept;
	~TokenType();

public:
	TokenType& operator=(const TokenType& token_type);
	TokenType& operator=(TokenType&& token_type) noexcept;
	bool operator==(const TokenType& token_type) const;
	bool operator!=(const TokenType& token_type) const;

public:
	TokenType& assign(const TokenType& token_type);
	TokenType& assign(TokenType&& token_type) noexcept;
	bool equal(const TokenType& token_typE) const;

public:
	bool empty() const noexcept;

private:
	std::vector<std::string> members_;
};

SCRIPTENGINE_END

#	endif
#endif