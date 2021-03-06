#ifndef __xui_kindctrl_h__
#define __xui_kindctrl_h__

#include "xui_plusctrl.h"
#include "xui_propkind.h"
#include "xui_propdata.h"
#include "xui_propctrl.h"
#include "xui_control.h"

class xui_kindctrl : public xui_control
{
	xui_declare_rtti

public:
	/*
	//create
	*/
	static const s32		KIND_HEIGHT;
	static xui_kindctrl*	create					( xui_propkind* propkind );

	/*
	//constructor
	*/
	xui_kindctrl( xui_propkind* propkind );

	/*
	//method
	*/
	bool					was_expanded			( void ) const;
	void					set_expanded			( bool flag );

	/*
	//propkind
	*/
	xui_propkind*			get_propkind			( void ) const;
	void					set_propkind			( xui_propkind* propkind );
	void					set_propkind			( const xui_propkind_vec& propkind );

protected:
	/*
	//override
	*/
	virtual void			on_invalid				( xui_method_args& args );
	virtual void			on_perform				( xui_method_args& args );

	/*
	//event
	*/
	void					on_namectrlnonfocus		( xui_component* sender, xui_method_args& args );
	void					on_namectrltextenter	( xui_component* sender, xui_method_args& args );
	void					on_flagctrlclick		( xui_component* sender, xui_method_args& args );
	void					on_kindexpand			( xui_component* sender, xui_method_args& args );

	/*
	//virtual
	*/
	virtual void			on_propkindchange		( void );

	/*
	//method
	*/
	xui_propdata_vec		get_propdataall			( u32 index );
	virtual s32				get_elsectrlsize		( void );
	virtual s32				get_prevctrlsize		( void );

	/*
	//member
	*/
	xui_drawer*				m_iconctrl;
	xui_textbox*			m_namectrl;
	xui_toggle*				m_flagctrl;
	xui_plusctrl*			m_kindplus;
	xui_propkind*			m_propkind;
	xui_propkind_vec		m_propkindvec;
	xui_propctrl_vec		m_propctrlvec;
};

#endif//__xui_kindctrl_h__