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

	TokenType TokenType::make()
	{
		return TokenType();
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

	bool TokenType::empty() const noexcept
	{
		return members_.size() == 0;
	}
}