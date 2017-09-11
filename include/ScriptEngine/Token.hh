#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_TOKEN_HH
#		define SCRIPTENGINE_HEADER_TOKEN_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/Token.include.hh>

SCRIPTENGINE_BEGIN

class TokenType final
{
public:
	using iterator = std::vector<std::string>::iterator;
	using const_iterator = std::vector<std::string>::const_iterator;

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
	TokenType& operator[](const std::string& new_member);

public:
	TokenType& assign(const TokenType& token_type);
	TokenType& assign(TokenType&& token_type) noexcept;
	bool equal(const TokenType& token_type) const;

public:
	static TokenType make();

public:
	void dump() const;
	void dump(int depth) const;
	void dump(std::ostream& out) const;
	void dump(std::ostream& out, int depth) const;

	void push_back(const std::string& new_member);
	void erase(const std::string& member);
	bool find(const std::string& member) const;
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cbegin() const;
	const_iterator cend() const;

public:
	bool empty() const noexcept;

private:
	std::vector<std::string> members_;
};

SCRIPTENGINE_END

#	endif
#endif