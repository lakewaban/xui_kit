#include "xui_global.h"
#include "onity_resource.h"

xui_bitmap* onity_resource::icon_pickcolour	= NULL;
xui_bitmap* onity_resource::icon_pickselect = NULL;
xui_bitmap* onity_resource::icon_loop		= NULL;
xui_bitmap*	onity_resource::icon_animator	= NULL;
xui_bitmap*	onity_resource::icon_bigerror	= NULL;
xui_bitmap*	onity_resource::icon_bigmessage	= NULL;
xui_bitmap*	onity_resource::icon_bigwarning	= NULL;
xui_bitmap*	onity_resource::icon_center		= NULL;
xui_bitmap*	onity_resource::icon_clear		= NULL;
xui_bitmap*	onity_resource::icon_console	= NULL;
xui_bitmap*	onity_resource::icon_delete		= NULL;
xui_bitmap*	onity_resource::icon_error		= NULL;
xui_bitmap*	onity_resource::icon_file		= NULL;
xui_bitmap*	onity_resource::icon_folder		= NULL;
xui_bitmap*	onity_resource::icon_game		= NULL;
xui_bitmap*	onity_resource::icon_hierarchy	= NULL;
xui_bitmap*	onity_resource::icon_inspector	= NULL;
xui_bitmap*	onity_resource::icon_local		= NULL;
xui_bitmap*	onity_resource::icon_message	= NULL;
xui_bitmap*	onity_resource::icon_pivot		= NULL;
xui_bitmap*	onity_resource::icon_project	= NULL;
xui_bitmap*	onity_resource::icon_rotation	= NULL;
xui_bitmap*	onity_resource::icon_scale		= NULL;
xui_bitmap*	onity_resource::icon_scene		= NULL;
xui_bitmap*	onity_resource::icon_search		= NULL;
xui_bitmap*	onity_resource::icon_select		= NULL;
xui_bitmap*	onity_resource::icon_timeline	= NULL;
xui_bitmap*	onity_resource::icon_translate	= NULL;
xui_bitmap*	onity_resource::icon_warning	= NULL;
xui_bitmap*	onity_resource::icon_world		= NULL;
xui_bitmap* onity_resource::icon_state		= NULL;
xui_bitmap* onity_resource::icon_transition = NULL;
xui_bitmap* onity_resource::icon_leftright	= NULL;
xui_bitmap* onity_resource::icon_topbottom	= NULL;
xui_bitmap* onity_resource::icon_large		= NULL;
xui_bitmap* onity_resource::icon_small		= NULL;
xui_bitmap* onity_resource::icon_reset		= NULL;
xui_bitmap* onity_resource::icon_play		= NULL;
xui_bitmap* onity_resource::icon_left		= NULL;
xui_bitmap* onity_resource::icon_right		= NULL;
xui_bitmap* onity_resource::icon_layerview	= NULL;
xui_bitmap* onity_resource::icon_visible	= NULL;
xui_bitmap* onity_resource::icon_lead		= NULL;
xui_bitmap* onity_resource::icon_layer		= NULL;
xui_bitmap* onity_resource::icon_circle		= NULL;
xui_bitmap* onity_resource::icon_texture	= NULL;
xui_bitmap* onity_resource::icon_particle	= NULL;
xui_bitmap* onity_resource::icon_module		= NULL;
xui_bitmap* onity_resource::icon_sprite		= NULL;
xui_bitmap* onity_resource::icon_action		= NULL;
xui_bitmap* onity_resource::icon_resource	= NULL;
xui_bitmap* onity_resource::icon_framekey	= NULL;

xui_method_explain(onity_resource, init, void)( void )
{
	icon_pickcolour	= xui_bitmap::create("icon/pickcolour.png");
	icon_pickselect = xui_bitmap::create("icon/pickselect.png");
	icon_loop		= xui_bitmap::create("icon/loop.png");
	icon_animator	= xui_bitmap::create("icon/animator.png");
	icon_bigerror	= xui_bitmap::create("icon/bigerror.png");
	icon_bigmessage	= xui_bitmap::create("icon/bigmessage.png");
	icon_bigwarning	= xui_bitmap::create("icon/bigwarning.png");
	icon_center		= xui_bitmap::create("icon/center.png");
	icon_clear		= xui_bitmap::create("icon/clear.png");
	icon_console	= xui_bitmap::create("icon/console.png");
	icon_delete		= xui_bitmap::create("icon/delete.png");
	icon_error		= xui_bitmap::create("icon/error.png");
	icon_file		= xui_bitmap::create("icon/file.png");
	icon_folder		= xui_bitmap::create("icon/folder.png");
	icon_game		= xui_bitmap::create("icon/game.png");
	icon_hierarchy	= xui_bitmap::create("icon/hierarchy.png");
	icon_inspector	= xui_bitmap::create("icon/inspector.png");
	icon_local		= xui_bitmap::create("icon/local.png");
	icon_message	= xui_bitmap::create("icon/message.png");
	icon_pivot		= xui_bitmap::create("icon/pivot.png");
	icon_project	= xui_bitmap::create("icon/project.png");
	icon_rotation	= xui_bitmap::create("icon/rotation.png");
	icon_scale		= xui_bitmap::create("icon/scale.png");
	icon_scene		= xui_bitmap::create("icon/scene.png");
	icon_search		= xui_bitmap::create("icon/search.png");
	icon_select		= xui_bitmap::create("icon/select.png");
	icon_timeline	= xui_bitmap::create("icon/timeline.png");
	icon_translate	= xui_bitmap::create("icon/translate.png");
	icon_warning	= xui_bitmap::create("icon/warning.png");
	icon_world		= xui_bitmap::create("icon/world.png");
	icon_state		= xui_bitmap::create("icon/state.png");
	icon_transition = xui_bitmap::create("icon/transition.png");
	icon_leftright	= xui_bitmap::create("icon/leftright.png");
	icon_topbottom	= xui_bitmap::create("icon/topbottom.png");
	icon_small		= xui_bitmap::create("icon/small.png");
	icon_large		= xui_bitmap::create("icon/large.png");
	icon_reset		= xui_bitmap::create("icon/reset.png");
	icon_play		= xui_bitmap::create("icon/play.png");
	icon_left		= xui_bitmap::create("icon/left.png");
	icon_right		= xui_bitmap::create("icon/right.png");
	icon_layerview	= xui_bitmap::create("icon/layerview.png");
	icon_visible	= xui_bitmap::create("icon/visible.png");
	icon_lead		= xui_bitmap::create("icon/lead.png");
	icon_layer		= xui_bitmap::create("icon/layer.png");
	icon_circle		= xui_bitmap::create("icon/circle.png");
	icon_texture	= xui_bitmap::create("icon/texture.png");
	icon_particle	= xui_bitmap::create("icon/particle.png");
	icon_module		= xui_bitmap::create("icon/module.png");
	icon_sprite		= xui_bitmap::create("icon/sprite.png");
	icon_action		= xui_bitmap::create("icon/action.png");
	icon_resource	= xui_bitmap::create("icon/resource.png");
	icon_framekey	= xui_bitmap::create("icon/framekey.png");

	xui_global::icon_pickcolour = icon_pickcolour;
	xui_global::icon_pickselect = icon_pickselect;
	xui_global::icon_loop		= icon_loop;
}