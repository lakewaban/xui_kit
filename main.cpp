#include "xui_family_create_win.h"
#include "freeglut_std.h"
#include "xui_timermgr.h"
#include "xui_convas.h"
#include "xui_bitmap.h"
#include "xui_method.h"
#include "xui_window.h"
#include "xui_toggle.h"
#include "xui_textbox.h"
#include "xui_linebox.h"
#include "xui_gridbox.h"
#include "xui_toolbar.h"
#include "xui_separate.h"
#include "xui_scroll.h"
#include "xui_slider.h"
#include "xui_listview.h"
#include "xui_treeview.h"
#include "xui_treenode.h"
#include "xui_treedata.h"
#include "xui_dropbox.h"
#include "xui_timeview.h"
#include "xui_timeline.h" 
#include "xui_timedata.h"
#include "xui_proproot.h"
#include "xui_propkind.h"
#include "xui_propdata.h"
#include "xui_propctrl.h"
#include "xui_propkind.h"
#include "xui_propctrl_slider.h"
#include "xui_propctrl_expand.h"
#include "xui_propctrl_vector.h"
#include "xui_propctrl_stdvec.h"
#include "xui_propctrl_rect2d.h"
#include "xui_propctrl_object.h"
#include "xui_propctrl_simple.h"
#include "xui_propview.h"
#include "xui_kindctrl.h"
#include "xui_desktop.h"
#include "xui_demo.h"

void MouseFunc(int mouse, int state, int x, int y)
{
	xui_method_mouse args;
	args.point = xui_vector<s32>(x, y);
	args.alt   = (glutGetModifiers() & GLUT_ACTIVE_ALT  ) != 0;
	args.ctrl  = (glutGetModifiers() & GLUT_ACTIVE_CTRL ) != 0;
	args.shift = (glutGetModifiers() & GLUT_ACTIVE_SHIFT) != 0;

	switch (mouse)
	{
	case GLUT_LEFT_BUTTON:	 args.mouse = MB_L;							break;
	case GLUT_RIGHT_BUTTON:	 args.mouse = MB_R;							break;
	case GLUT_MIDDLE_BUTTON: args.mouse = MB_M;							break;
	}

	switch (state)
	{
	case GLUT_DOWN:			xui_desktop::get_ins()->os_mousedown(args);	break;
	case GLUT_UP:			xui_desktop::get_ins()->os_mouserise(args);	break;
	}

	glutPostRedisplay();
}

u08 NormalToKey(unsigned char c, bool ctrl)
{
	if (ctrl) c += 96;

	c = toupper(c);
	switch (c)
	{
	case 'A':				return KEY_A;
	case 'B':				return KEY_B;
	case 'C':				return KEY_C;
	case 'D':				return KEY_D;
	case 'E':				return KEY_E;
	case 'F':				return KEY_F;
	case 'G':				return KEY_G;
	case 'H':				return KEY_H;
	case 'I':				return KEY_I;
	case 'J':				return KEY_J;
	case 'K':				return KEY_K;
	case 'L':				return KEY_L;
	case 'M':				return KEY_M;
	case 'N':				return KEY_N;
	case 'O':				return KEY_O;
	case 'P':				return KEY_P;
	case 'Q':				return KEY_Q;
	case 'R':				return KEY_R;
	case 'S':				return KEY_S;
	case 'T':				return KEY_T;
	case 'U':				return KEY_U;
	case 'V':				return KEY_V;
	case 'W':				return KEY_W;
	case 'X':				return KEY_X;
	case 'Y':				return KEY_Y;
	case 'Z':				return KEY_Z;
	case '\n':				return KEY_ENTER;
	case '\r':				return KEY_ENTER;
	case '\t':				return KEY_TAB;
	case '\b':				return KEY_BACK;
	default:				return KEY_NONE;
	}
}

u08 SystemToKey(int c )
{
	switch(c)
	{
	case 0x70:				return KEY_SHIFT;
	case GLUT_KEY_UP:		return KEY_UARROW;
	case GLUT_KEY_DOWN:		return KEY_DARROW;
	case GLUT_KEY_LEFT:		return KEY_LARROW;
	case GLUT_KEY_RIGHT:	return KEY_RARROW;
	case GLUT_KEY_HOME:		return KEY_HOME;
	case GLUT_KEY_END:		return KEY_END;
	case GLUT_KEY_F1:		return KEY_F1;
	case GLUT_KEY_F2:		return KEY_F2;
	case GLUT_KEY_F3:		return KEY_F3;
	case GLUT_KEY_F4:		return KEY_F4;
	case GLUT_KEY_F5:		return KEY_F5;
	case GLUT_KEY_F6:		return KEY_F6;
	case GLUT_KEY_F7:		return KEY_F7;
	case GLUT_KEY_F8:		return KEY_F8;
	case GLUT_KEY_F9:		return KEY_F9;
	default:				return KEY_NONE;
	}
}

void KeyboardFunc(unsigned char c, int x, int y )
{
	xui_method_keybd args;
	args.alt   = (glutGetModifiers() & GLUT_ACTIVE_ALT  ) != 0;
	args.ctrl  = (glutGetModifiers() & GLUT_ACTIVE_CTRL ) != 0;
	args.shift = (glutGetModifiers() & GLUT_ACTIVE_SHIFT) != 0;
	args.kcode = NormalToKey(c, args.ctrl);
	xui_desktop::get_ins()->os_keybddown(args);

	if (args.ctrl == false)
		xui_desktop::get_ins()->os_keybdchar(c);

	glutPostRedisplay();
}

void SpecialFunc(int c, int x, int y )
{
	xui_method_keybd args;
	args.alt   = (glutGetModifiers() & GLUT_ACTIVE_ALT  ) != 0;
	args.ctrl  = (glutGetModifiers() & GLUT_ACTIVE_CTRL ) != 0;
	args.shift = (glutGetModifiers() & GLUT_ACTIVE_SHIFT) != 0;
	args.kcode = SystemToKey(c);
	xui_desktop::get_ins()->os_keybddown(args);

	glutPostRedisplay();
}

void KeyboardUpFunc(unsigned char c, int x, int y)
{
	xui_method_keybd args;
	args.alt   = (glutGetModifiers() & GLUT_ACTIVE_ALT  ) != 0;
	args.ctrl  = (glutGetModifiers() & GLUT_ACTIVE_CTRL ) != 0;
	args.shift = (glutGetModifiers() & GLUT_ACTIVE_SHIFT) != 0;
	args.kcode = NormalToKey(c, args.ctrl);
	xui_desktop::get_ins()->os_keybdrise(args);

	glutPostRedisplay();
}

void SpecialUpFunc(int c, int x, int y)
{
	xui_method_keybd args;
	args.alt   = (glutGetModifiers() & GLUT_ACTIVE_ALT  ) != 0;
	args.ctrl  = (glutGetModifiers() & GLUT_ACTIVE_CTRL ) != 0;
	args.shift = (glutGetModifiers() & GLUT_ACTIVE_SHIFT) != 0;
	args.kcode = SystemToKey(c);
	xui_desktop::get_ins()->os_keybdrise(args);

	glutPostRedisplay();
}

void MouseMove(int x, int y)
{
	xui_method_mouse args;
	args.point = xui_vector<s32>(x, y);
	xui_desktop::get_ins()->os_mousemove(args);

	glutPostRedisplay();
}

void Resize(int w, int h)
{
	h -= 8;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_LINE_SMOOTH);
	//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	//glEnable(GL_POINT_SMOOTH);
	//glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	//GLenum multisampler = 0x809D;
	//GLboolean smooth = glIsEnabled(multisampler);
	//if (smooth)
	//	glDisable(multisampler);

	glMatrixMode(GL_PROJECTION);
	
	f32 m[16];
	memset(m, 0, sizeof(f32) * 16);
	m[0]  =  2.0f / (f32)w;
	m[5]  = -2.0f / (f32)h;
	m[10] =  1.0f / 1000.0f;
	m[12] = -1.0f;
	m[13] =  1.0f;
	m[14] =  1.0f / 1000.0f;
	m[15] =  1.0f;
	glLoadMatrixf(m);

	xui_convas::get_ins()->set_viewport(xui_rect2d<s32>(0, 0, w, h));
	if (xui_desktop::get_ins())
		xui_desktop::get_ins()->set_rendersz(xui_vector<s32>(w, h));
}

void Render()
{
	xui_timermgr::get_ins()->update(0.016f);
	xui_desktop::get_ins()->update(0.016f);

	xui_convas::get_ins()->set_cliprect(xui_convas::get_ins()->get_viewport());
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//g_convas->draw_circle(xui_vector<s32>(100, 10), 10, xui_colour(1.0f), 0, 360);
	//g_convas->draw_rectangle(xui_rect2d<s32>(0, 0, 150, 150), xui_colour(1.0f, 1.0f, 0.0f, 0.0f));
	//g_convas->draw_round(xui_rect2d<s32>(100, 100, 300, 200), xui_colour(1.0f, 0.0f, 0.0f, 0.0f), 8);

	//xui_bitmap* image = xui_bitmap::create(std::string("test.png"));
	//g_convas.draw_image(image, xui_vector<s32>(30, 30), xui_colour(1.0f, 1.0f, 0.0f, 0.0f));

	//xui_family_render textdraw;
	//textdraw.renderstyle = TEXTDRAW_STROKE;

	//std::wstringstream text;
	//text << rect2d_value.get_h();
	//g_convas->draw_text(text.str(), xui_family("Arial", 30, false), xui_vector<s32>(0, 0), textdraw);

	//g_convas->draw_text(bool_value ? L"True" : L"False", xui_family("Arial", 30, false), xui_vector<s32>(0, 30), textdraw);
	//g_convas->draw_text(enum_map[(s32)enum_value], xui_family("Arial", 30, false), xui_vector<s32>(0, 60), textdraw);
	//g_convas->draw_text(string_value, xui_family("Arial", 30, false), xui_vector<s32>(0, 90), textdraw);
	//g_convas->draw_text(text.str(), xui_family("Arial", 30, false), xui_vector<s32>(0, 120), textdraw);

	//xui_vector<s32> pt(0, 150);
	xui_desktop::get_ins()->render();
	glutSwapBuffers();
}

void Idle()
{
	int lastTime = timeGetTime();
	Render();
	int currTime = timeGetTime();
	int deltaTime = currTime - lastTime;
	if (deltaTime < 16)
		Sleep(16 - deltaTime);
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutCreateWindow("Test");
	glutReshapeFunc(Resize);
	glutDisplayFunc(Render);
	glutMouseFunc(MouseFunc);
	glutPassiveMotionFunc(MouseMove);
	glutMotionFunc(MouseMove);
	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SpecialFunc);
	glutSpecialUpFunc(SpecialUpFunc);
	glutIdleFunc(Idle);
	glEnable(GL_BLEND);
	glutReshapeWindow(1024, 768);
	//glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	//glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);
	//glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	g_family_create = new xui_family_create_win();
	xui_timermgr::init();
	xui_desktop::init();
	xui_convas::init();
	xui_window* window = new xui_window(xui_vector<s32>(500, 500));
	window->ini_component(0, 0, DOCKSTYLE_F);
	//window->set_corner(5);

	xui_linebox* linebox = new xui_linebox(xui_vector<s32>(200, 100), NULL);
	linebox->set_corner(5);
	linebox->set_backcolor(xui_colour(1.0f, 0.40f, 0.40f, 0.40f));

	xui_gridbox* gridbox = new xui_gridbox(NULL);
	gridbox->set_corner(5);
	gridbox->set_backcolor(xui_colour(1.0f, 0.40f, 0.40f, 0.40f));
	gridbox->set_sidestyle(SIDESTYLE_S);
	gridbox->set_sidecolor(xui_colour(1.0f, 1.0f, 1.0f, 1.0f));
	gridbox->set_rowcount(3);
	gridbox->set_colcount(3);
	gridbox->set_rowpixel(0, 50);
	gridbox->set_rowpixel(1, 50);
	gridbox->set_rowpixel(2, 50);
	gridbox->set_colpixel(0, 80);
	gridbox->set_colpixel(1, 100);
	gridbox->set_colpixel(2, 30);
	//window->add_child(gridbox);

	//linebox->set_sidestyle(SIDESTYLE_S);
	//linebox->set_sidecolor(xui_colour(1.0f, 1.0f, 1.0f, 1.0f));
	//xui_linebutton* button1 = new xui_linebutton("", xui_rect2d<s32>(0, 0, 150, 50));
	//button1->set_sidestyle(SIDESTYLE_S);
	//button1->set_sidecolor(xui_colour(1.0f, 0.27f, 0.27f, 0.27f));
	//linebox->add_linectrl(button1);
	//xui_linebutton* button2 = new xui_linebutton("", xui_rect2d<s32>(0, 0, 150, 50));
	//button2->set_sidestyle(SIDESTYLE_S);
	//button2->set_sidecolor(xui_colour(1.0f, 0.27f, 0.27f, 0.27f));
	//linebox->add_linectrl(button2);
	//window->add_child(linebox);

	xui_textbox* textbox = new xui_textbox(xui_vector<s32>(150, 100));
	textbox->set_backcolor(xui_colour(1.0f, 0.0f, 0.0f, 0.0f));
	textbox->set_sidecolor(xui_colour(1.0f, 1.0f, 1.0f, 1.0f));
	textbox->set_sidestyle(SIDESTYLE_S);
	textbox->set_hinttext(L"");
	textbox->set_textalign(TA_RC);
	textbox->set_borderrt(xui_rect2d<s32>(0, 0, 20, 0));
	//textbox->set_numbonly(true);
	//textbox->set_password(true);
	//textbox->set_readonly(true);
	//window->add_child(textbox);
	//linebox->add_linectrl(textbox);
	gridbox->set_gridctrl(1, 1, textbox);

	xui_button* button = new xui_button(xui_vector<s32>(50));
	button->set_icon(xui_bitmap::create("button.png"));
	button->set_text(L"button");
	button->set_textfont(xui_family("Arial", 16, false));
	button->set_corner(5);
	button->set_sidestyle(SIDESTYLE_S);
	button->set_sidecolor(xui_colour(1.0f, 1.00f, 1.00f, 1.00f));
	button->set_backcolor(xui_colour(1.0f, 0.40f, 0.40f, 0.40f));
	//button->set_borderrt(xui_rect2d<s32>(5,5,5,5));
	button->set_textoffset(xui_vector<s32>( 30, 0));
	button->set_iconoffset(xui_vector<s32>(-10, 0));
	//window->add_child(button);
	//linebox->add_linectrl(button);
	gridbox->set_gridctrl(1, 0, button);

	//xui_toggle* toggle = new xui_toggle(xui_vector<s32>(100), NULL, TOGGLE_CIRCLE);
	//toggle->set_icon(xui_bitmap::create("button.png"));
	//toggle->set_text(L"button");
	//toggle->set_font(xui_family("Arial", 16, false));
	//toggle->set_corner(5);
	//toggle->set_sidestyle(SIDESTYLE_S);
	//toggle->set_sidecolor(xui_colour(1.0f, 1.00f, 1.00f, 1.00f));
	//toggle->set_backcolor(xui_colour(1.0f, 0.40f, 0.40f, 0.40f));
	//toggle->set_borderrt(xui_rect2d<s32>(10, 10, 10, 10));
	//toggle->set_borderrt(xui_rect2d<s32>(5,5,5,5));
	//toggle->set_textoffset(xui_vector<s32>( 30, 0));
	//toggle->set_iconoffset(xui_vector<s32>(-10, 0));
	//window->add_child(toggle);
	//linebox->add_linectrl(toggle);
	//gridbox->set_gridctrl(1, 2, toggle);

	xui_separate* separate = new xui_separate(xui_vector<s32>(20));

	xui_toolbar* toolbar = new xui_toolbar(xui_vector<s32>(200));
	toolbar->set_backcolor(xui_colour(0.0f, 0.0f, 0.0f, 0.0f));
	//toolbar->add_item(textbox);
	//toolbar->add_item(button);
	//toolbar->add_item(separate);
	//toolbar->add_item(toggle);

	//window->add_child(toolbar);

	//xui_scroll* scroll = new xui_slider(xui_vector<s32>(100, 20), NULL, FLOWSTYLE_H, true);
	//scroll->set_backcolor(xui_colour(1.0f, 0.30f, 0.30f, 0.30f));
	//scroll->set_borderrt(xui_rect2d<s32>(0, 2, 0, 2));
	//scroll->set_range(2000);

	//window->add_child(scroll);

	//u08 widgettype[LIW_COUNT] = {255, LIW_ICON, LIW_TEXT};
	//s32 widgetsize[LIW_COUNT] = {0,   20,       60};
	xui_listview* listview = new xui_listview(xui_vector<s32>(250, 200), false);
	listview->set_backcolor(xui_colour(1.0f, 0.4f, 0.4f, 0.4f));
	listview->set_allowmulti(true);
	for (int i = 0; i < 20; ++i)
		listview->add_item(L"test", xui_bitmap::create("button.png"));
	//window->add_child(listview);

	std::vector<xui_treecolumn> columninfo;
	columninfo.push_back(xui_treecolumn(TREECOLUMN_BOOL,  36, L"", xui_bitmap::create("button.png")));
	columninfo.push_back(xui_treecolumn(TREECOLUMN_TEXT,  60, L"test"));
	columninfo.push_back(xui_treecolumn(TREECOLUMN_MAIN, 180, L"main"));
	xui_treeview* treeview = new xui_treeview(xui_vector<s32>(250, 200), columninfo);
	treeview->set_backcolor(xui_colour(1.0f, 0.4f, 0.4f, 0.4f));
	treeview->set_sidecolor(xui_colour(1.0f, 0.7f, 0.7f, 0.7f));
	treeview->set_corner(5);
	treeview->set_allowmulti(true);
	for (int i = 0; i < 10; ++i)
	{
		std::wstringstream text;
		text << L"test";
		text << i+5;
		xui_treedata* data = new xui_treedata(text.str());
		xui_treenode* node = treeview->add_upmostnode(i, data);

		if (i % 2 == 0)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::wstringstream childtext;
				childtext << L"child";
				childtext << j;

				xui_treedata* childdata = new xui_treedata(childtext.str());
				xui_treenode* childnode = node->add_leafnode(j, childdata);
			}
		}
	}
	//treeview->xm_mousedragitem += new xui_method_static<xui_method_dragdrop>(treeview_dragitem);
	//window->add_child(treeview);

	xui_dropbox* dropbox = new xui_dropbox(xui_vector<s32>(50), NULL);
	dropbox->set_backcolor(xui_colour(1.0f, 0.2f, 0.2f, 0.2f));
	dropbox->set_sidestyle(SIDESTYLE_S);
	dropbox->set_sidecolor(xui_colour(1.0f, 0.5f, 0.5f, 0.5f));
	//dropbox->set_readonly(true);
	dropbox->add_item(L"asfg");
	dropbox->add_item(L"tat");
	dropbox->add_item(L"test");
	dropbox->add_item(L"chris");
	//window->add_child(dropbox);


	//window->add_child(timeview);

	xui_demo::test_button(window);
	xui_demo::test_toggle(window);
	xui_demo::test_textbox(window);
	xui_demo::test_linebox(window);
	xui_demo::test_gridbox(window);
	xui_demo::test_toolbar(window);
	xui_demo::test_scroll(window);
	xui_demo::test_slider(window);
	xui_demo::test_listview(window);
	xui_demo::test_dropbox(window);
	xui_demo::test_treeview(window);
	xui_demo::test_timeview(window);
	xui_demo::test_propview(window);

	xui_desktop::get_ins()->add_child(window);

	glutMainLoop();
	return 0;
}