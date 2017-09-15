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
			throw std::invalid_argument(u8"�̹� �����ϴ� ����Դϴ�.");

		members_.push_back(new_member);
	}
	void TokenType::erase(const std::string& member)
	{
		std::vector<std::string>::iterator member_iter =
			std::find(members_.begin(), members_.end(), member);

		if (member_iter == members_.end())
			throw std::invalid_argument(u8"������ ����� ã�� ���߽��ϴ�.");

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
			throw std::out_of_range(u8"�μ� 'index'�� ������ �ʰ��߽��ϴ�.");
	}
	TokenTypeInst::TokenTypeInst(const TokenType& token_type, const std::string& member)
		: token_type_(token_type)
	{
		std::vector<std::string>::const_iterator member_iter =
			std::find(token_type.cbegin(), token_type.cend(), member);

		if (member_iter == token_type.cend())
			throw std::invalid_argument(u8"����� ã�� ���߽��ϴ�.");

		index_ = std::distance(token_type.cbegin(), member_iter);
	}
	TokenTypeInst::TokenTypeInst(const TokenTypeInst& token_type_inst)
		: token_type_(token_type_inst.token_type_), index_(token_type_inst.index_)
	{}
	TokenTypeInst::~TokenTypeInst()
	{}

	TokenTypeInst& TokenTypeInst::operator=(const TokenTypeInst& token_type_inst)
	{
		return assign(token_type_inst);
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
	TokenTypeInst& TokenTypeInst::assign(const std::string& member)
	{
		if (!token_type_.find(member))
			throw std::invalid_argument(u8"����� ã�� ���߽��ϴ�.");

		index_ = std::distance(token_type_.cbegin(),
			std::find(token_type_.cbegin(), token_type_.cend(), member));
	}
	TokenTypeInst& TokenTypeInst::assign(std::vector<std::string>::size_type index)
	{
		if (token_type_.size() <= index)
			throw std::out_of_range(u8"�μ� 'index'�� ������ �ʰ��߽��ϴ�.");

		index_ = index;
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
	{}
}