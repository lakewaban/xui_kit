#ifndef __onity_timeline_h__
#define __onity_timeline_h__

#include "xui_dockpage.h"
#include "xui_treeview.h"

class onity_propactor;
class onity_preview;
class onity_lineview;
class onity_timeline : public xui_dockpage
{
	xui_declare_rtti

public:
	/*
	//constructor
	*/
	onity_timeline( void );

	/*
	//method
	*/
	onity_propactor*	get_editprop			( void );
	void				set_editprop			( onity_propactor* editprop );

	/*
	//override
	*/
	virtual void		render_else				( void );

protected:
	/*
	//callback
	*/
	virtual void		on_perform				( xui_method_args& args );

	/*
	//event
	*/
	void				on_linectrlclick		( xui_component* sender, xui_method_args&			args );
	void				on_sizectrlmousemove	( xui_component* sender, xui_method_mouse&			args );
	void				on_timelineaddlayer		( xui_component* sender, xui_method_args&			args );
	void				on_timelinedellayer		( xui_component* sender, xui_method_args&			args );
	void				on_timelinedragover		( xui_component* sender, xui_method_treedragdrop&	args );
	void				on_timelinedragdrop		( xui_component* sender, xui_method_treedragdrop&	args );

	/*
	//method
	*/
	void				refresh_timeview		( void );

	/*
	//member
	*/
	xui_timeview*		m_timeview;
	onity_preview*		m_drawview;
	onity_lineview*		m_lineview;
	xui_toggle*			m_linectrl;
	xui_control*		m_sizectrl;
	onity_propactor*	m_editprop;
};

#endif//__onity_timeline_h__