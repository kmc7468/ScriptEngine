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
	std::string operator[](std::vector<std::string>::size_type index) const;

public:
	TokenType& assign(const TokenType& token_type);
	TokenType& assign(TokenType&& token_type) noexcept;
	bool equal(const TokenType& token_type) const;
	std::string at(std::vector<std::string>::size_type index) const;

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
	std::vector<std::string>::size_type size() const noexcept;

public:
	bool empty() const noexcept;

private:
	std::vector<std::string> members_;
};

TokenType make_token_type();

class TokenTypeInst final
{
public:
	explicit TokenTypeInst(const TokenType& token_type);
	TokenTypeInst(const TokenType& token_type, std::vector<std::string>::size_type index);
	TokenTypeInst(const TokenType& token_type, const std::string& member);
	TokenTypeInst(const TokenTypeInst& token_type_inst);
	~TokenTypeInst();

public:
	TokenTypeInst& operator=(const TokenTypeInst& token_type_inst);
	bool operator==(const TokenTypeInst& token_type_inst) const;
	bool operator!=(const TokenTypeInst& token_type_inst) const;

public:
	TokenTypeInst& assign(const TokenTypeInst& token_type_inst);
	TokenTypeInst& assign(const std::string& member);
	TokenTypeInst& assign(std::vector<std::string>::size_type index);
	bool equal(const TokenTypeInst& token_type_inst) const;

public:
	std::string selected() const;
	std::string selected(const std::string& member);
	std::string selected(std::vector<std::string>::size_type index);

private:
	TokenType token_type_;
	std::vector<std::string>::size_type index_ = 0;
};

class Token final
{
public:
	using IndexType = std::string::size_type;

public:
	Token();
	Token(const TokenType& token_type, const std::string& sentence, IndexType line, IndexType col);
	Token(const Token& token);
	Token(Token&& token) noexcept;
	~Token();

public:
	Token& operator=(const Token& token);
	Token& operator=(Token&& token) noexcept;
	bool operator==(const Token& token) const;
	bool operator!=(const Token& token) const;

public:
	Token& assign(const Token& token);
	Token& assign(Token&& token) noexcept;
	bool equal(const Token& token) const;

public:
	TokenType token_type() const;
	std::string sentence() const;
	IndexType line() const noexcept;
	IndexType col() const noexcept;
	IndexType end_col() const noexcept;

private:
	TokenType token_type_;
	std::string sentence_;

	IndexType line_;
	IndexType col_;
	IndexType end_col_;
};

SCRIPTENGINE_END

#	endif
#endif