#ifdef SCRIPTENGINE_MODULE
import ScriptEngine.Token;
#else
#	include <ScriptEngine/Token.hh>
#endif

#include <ScriptEngine/Details/Token.include.hh>
#include "Token.internal.hh"

namespace ScriptEngine
{
	TokenType::TokenType()
	{}
	TokenType::TokenType(const TokenType& token_type)
		: members_(token_type.members_)
	{}
	TokenType::TokenType(TokenType&& token_type) noexcept
		: members_(std::move(token_type.members_))
	{}
	TokenType::~TokenType()
	{}

	TokenType& TokenType::operator=(const TokenType& token_type)
	{
		return assign(token_type);
	}
	TokenType& TokenType::operator=(TokenType&& token_type) noexcept
	{
		return assign(std::move(token_type));
	}
	bool TokenType::operator==(const TokenType& token_type) const
	{
		return equal(token_type);
	}
	bool TokenType::operator!=(const TokenType& token_type) const
	{
		return !equal(token_type);
	}
	TokenType& TokenType::operator[](const std::string& new_member)
	{
		push_back(new_member);

		return *this;
	}
	std::string TokenType::operator[](std::vector<std::string>::size_type index) const
	{
		return at(index);
	}

	TokenType& TokenType::assign(const TokenType& token_type)
	{
		members_ = token_type.members_;
		
		return  *this;
	}
	TokenType& TokenType::assign(TokenType&& token_type) noexcept
	{
		members_ = std::move(token_type.members_);

		return *this;
	}
	bool TokenType::equal(const TokenType& token_type) const
	{
		if (this == &token_type)
		{
			return true;
		}
		else if (members_.size() != token_type.members_.size())
		{
			return false;
		}

		for (std::size_t i = 0; i < members_.size(); ++i)
		{
			if (members_[i] != token_type.members_[i])
			{
				return false;
			}
		}

		return true;
	}
	std::string TokenType::at(std::vector<std::string>::size_type index) const
	{
		return members_.at(index);
	}

	TokenType TokenType::make()
	{
		return TokenType();
	}

	void TokenType::dump() const
	{
		dump(std::cout);
	}
	void TokenType::dump(int depth) const
	{
		dump(std::cout, depth);
	}
	void TokenType::dump(std::ostream& out) const
	{
		dump(out, 0);
	}
	void TokenType::dump(std::ostream& out, int depth) const
	{
		static auto prefix = [](int depth)
		{
			return std::string(depth * 4, ' ');
		};

		if (empty())
		{
			out << prefix(depth) + "TokenType: empty\n";

			return;
		}

		out << prefix(depth) << "TokenType:\n";
	
		for (const std::string& member : members_)
		{
			out << prefix(depth + 1) << member << '\n';
		}
	}

	void TokenType::push_back(const std::string& new_member)
	{
		std::vector<std::string>::iterator member_iter =
			std::find(members_.begin(), members_.end(), new_member);

		if (member_iter != members_.end())
			throw std::invalid_argument(u8"이미 존재하는 멤버입니다.");

		members_.push_back(new_member);
	}
	void TokenType::erase(const std::string& member)
	{
		std::vector<std::string>::iterator member_iter =
			std::find(members_.begin(), members_.end(), member);

		if (member_iter == members_.end())
			throw std::invalid_argument(u8"삭제할 멤버를 찾지 못했습니다.");

		members_.erase(member_iter);
	}
	bool TokenType::find(const std::string& member) const
	{
		return std::find(members_.cbegin(), members_.cend(), member) != members_.cend();
	}

	TokenType::iterator TokenType::begin()
	{
		return members_.begin();
	}
	TokenType::const_iterator TokenType::begin() const
	{
		return members_.begin();
	}
	TokenType::iterator TokenType::end()
	{
		return members_.end();
	}
	TokenType::const_iterator TokenType::end() const
	{
		return members_.end();
	}
	TokenType::const_iterator TokenType::cbegin() const
	{
		return members_.cbegin();
	}
	TokenType::const_iterator TokenType::cend() const
	{
		return members_.cend();
	}
	std::vector<std::string>::size_type TokenType::size() const noexcept
	{
		return members_.size();
	}

	bool TokenType::empty() const noexcept
	{
		return members_.size() == 0;
	}

	TokenType make_token_type()
	{
		return TokenType::make();
	}
}

namespace ScriptEngine
{
	TokenTypeInst::TokenTypeInst(const TokenType& token_type)
		: token_type_(token_type)
	{}
	TokenTypeInst::TokenTypeInst(const TokenType& token_type, std::vector<std::string>::size_type index)
		: token_type_(token_type), index_(index)
	{
		if (index <= token_type.size())
			throw std::out_of_range(u8"인수 'index'가 범위를 초과했습니다.");
	}
	TokenTypeInst::TokenTypeInst(const TokenType& token_type, const std::string& member)
		: token_type_(token_type)
	{
		std::vector<std::string>::const_iterator member_iter =
			std::find(token_type.cbegin(), token_type.cend(), member);

		if (member_iter == token_type.cend())
			throw std::invalid_argument(u8"멤버를 찾지 못했습니다.");

		index_ = std::distance(token_type.cbegin(), member_iter);
	}
	TokenTypeInst::TokenTypeInst(const TokenTypeInst& token_type_inst)
		: token_type_(token_type_inst.token_type_), index_(token_type_inst.index_)
	{}
	TokenTypeInst::TokenTypeInst(TokenTypeInst&& token_type_inst) noexcept
		: token_type_(std::move(token_type_inst.token_type_)), index_(token_type_inst.index_)
	{
		token_type_inst.index_ = 0;
	}
	TokenTypeInst::~TokenTypeInst()
	{}

	TokenTypeInst& TokenTypeInst::operator=(const TokenTypeInst& token_type_inst)
	{
		return assign(token_type_inst);
	}
	TokenTypeInst & TokenTypeInst::operator=(TokenTypeInst&& token_type_inst) noexcept
	{
		return assign(std::move(token_type_inst));
	}
	bool TokenTypeInst::operator==(const TokenTypeInst& token_type_inst) const
	{
		return equal(token_type_inst);
	}
	bool TokenTypeInst::operator!=(const TokenTypeInst& token_type_inst) const
	{
		return !equal(token_type_inst);
	}

	TokenTypeInst& TokenTypeInst::assign(const TokenTypeInst& token_type_inst)
	{
		if (token_type_ != token_type_inst.token_type_)
		{
			token_type_ = token_type_inst.token_type_;
		}
		index_ = token_type_inst.index_;

		return *this;
	}
	TokenTypeInst& TokenTypeInst::assign(TokenTypeInst&& token_type_inst) noexcept
	{
		if (token_type_ != token_type_inst.token_type_)
		{
			token_type_ = std::move(token_type_inst.token_type_);
		}
		else
		{
			token_type_inst.token_type_ = TokenType();
		}

		index_ = token_type_inst.index_;
		token_type_inst.index_ = 0;

		return *this;
	}
	TokenTypeInst& TokenTypeInst::assign(const std::string& member)
	{
		if (!token_type_.find(member))
			throw std::invalid_argument(u8"멤버를 찾지 못했습니다.");

		index_ = std::distance(token_type_.cbegin(),
			std::find(token_type_.cbegin(), token_type_.cend(), member));

		return *this;
	}
	TokenTypeInst& TokenTypeInst::assign(std::vector<std::string>::size_type index)
	{
		if (token_type_.size() <= index)
			throw std::out_of_range(u8"인수 'index'가 범위를 초과했습니다.");

		index_ = index;

		return *this;
	}
	bool TokenTypeInst::equal(const TokenTypeInst& token_type_inst) const
	{
		return token_type_ == token_type_inst.token_type_ && index_ == token_type_inst.index_;
	}

	std::string TokenTypeInst::selected() const
	{
		return token_type_[index_];
	}
	std::string TokenTypeInst::selected(const std::string& member)
	{
		assign(member);

		return selected();
	}
	std::string TokenTypeInst::selected(std::vector<std::string>::size_type index)
	{
		assign(index);
		
		return selected();
	}
}

namespace ScriptEngine
{
	Token::Token()
		: token_type_(TokenType())
	{}
	Token::Token(const TokenTypeInst& token_type, const std::string& sentence, IndexType line, IndexType col)
		: token_type_(token_type), sentence_(sentence), line_(line), col_(col), end_col_(col + sentence.length() - 1)
	{}
	Token::Token(const Token& token)
		: token_type_(token.token_type_), sentence_(token.sentence_), line_(token.line_), col_(token.col_), end_col_(token.end_col_)
	{}
	Token::Token(Token&& token) noexcept
		: token_type_(std::move(token.token_type_)), sentence_(std::move(token.sentence_)), line_(token.line_), col_(token.col_), end_col_(token.end_col_)
	{
		token.line_ = 0;
		token.col_ = 0;
		token.end_col_ = 0;
	}
	Token::~Token()
	{}

	Token& Token::operator=(const Token& token)
	{
		return assign(token);
	}
	Token& Token::operator=(Token&& token) noexcept
	{
		return assign(std::move(token));
	}
	bool Token::operator==(const Token& token) const
	{
		return equal(token);
	}
	bool Token::operator!=(const Token& token) const
	{
		return !equal(token);
	}

	Token& Token::assign(const Token& token)
	{
		token_type_ = token.token_type_;
		sentence_ = token.sentence_;
		line_ = token.line_;
		col_ = token.col_;
		end_col_ = token.end_col_;

		return *this;
	}
	Token& Token::assign(Token&& token) noexcept
	{
		token_type_ = std::move(token.token_type_);
		sentence_ = std::move(token.sentence_);
		line_ = token.line_;
		col_ = token.col_;
		end_col_ = token.end_col_;

		token.line_ = 0;
		token.col_ = 0;
		token.end_col_ = 0;

		return *this;
	}
	bool Token::equal(const Token& token) const
	{
		return token_type_ == token.token_type_ && sentence_ == token.sentence_ &&
			line_ == token.line_ && col_ == token.col_ && end_col_ == token.end_col_;
	}

	TokenTypeInst Token::token_type() const
	{
		return token_type_;
	}
	std::string Token::sentence() const
	{
		return sentence_;
	}
	Token::IndexType Token::line() const noexcept
	{
		return line_;
	}
	Token::IndexType Token::col() const noexcept
	{
		return col_;
	}
	Token::IndexType Token::end_col() const noexcept
	{
		return end_col_;
	}
}