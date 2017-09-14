#if defined(SCRIPTENGINE) || !defined(SCRIPTENGINE_MODULE)
#	ifndef SCRIPTENGINE_HEADER_LEXRULE_HH
#		define SCRIPTENGINE_HEADER_LEXRULE_HH
#		include <ScriptEngine/Config.hh>
#		include <ScriptEngine/Details/LexRule.include.hh>

SCRIPTENGINE_BEGIN

class LexRule
{
public:
	using Ptr = std::shared_ptr<LexRule>;
};

using LexRulePtr = LexRule::Ptr;

SCRIPTENGINE_END

#	endif
#endif