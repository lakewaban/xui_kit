#include "NP2DSTransition.h"
#include "NP2DSCondition.h"
#include "NP2DSParam.h"
#include "NP2DSState.h"

#include "xui_global.h"
#include "xui_propkind.h"
#include "xui_kindctrl.h"
#include "onity_resource.h"
#include "onity_propctrl_condition.h"
#include "onity_proptransition.h"

/*
//constructor
*/
xui_create_explain(onity_proptransition)( onity_propfile* propfile, NP2DSTransition* transition )
: onity_propleaf(propfile)
, m_transition(transition)
{
	std::string text;
	text += transition->GetSelfState()->GetName();
	text += " >> ";
	text += transition->GetNextState()->GetName();
	xui_propkind* kind = new xui_propkind(this, xui_global::ascii_to_unicode(text), "Transition", xui_kindctrl::create, onity_resource::icon_transition, true);
	m_condition = new onity_propdata_condition(
		kind,
		L"",
		onity_propctrl_condition::create,
		m_transition);

	kind->add_propdata(m_condition);
	add_propkind(kind);
}

/*
//method
*/
xui_method_explain(onity_proptransition, get_transition,	NP2DSTransition*)( void )
{
	return m_transition;
}

/*
//notify
*/
xui_method_explain(onity_proptransition, on_delparam,		void			)( NP2DSParam* param )
{
	m_condition->refresh();
}
xui_method_explain(onity_proptransition, on_addparam,		void			)( NP2DSParam* param )
{
	m_condition->refresh();
}