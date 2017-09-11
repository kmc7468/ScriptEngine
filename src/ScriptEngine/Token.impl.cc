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

	bool TokenType::empty() const noexcept
	{
		return members_.size() == 0;
	}
}