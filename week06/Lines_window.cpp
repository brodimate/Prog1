#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	next_button{Point{x_max()-200,0}, 100, 40, "Next point", cb_next},
	quit_button{Point{x_max()-100,0}, 100, 40, "Quit", cb_quit},
	next_x{Point{300,0}, 50, 40, "next x:"},
	next_y{Point{450,0}, 50, 40, "next y:"},
	xy_out{Point{100,0}, 100, 40, "current (x,y):"},
	color_menu{Point{x_max()-100,40},100,40,Menu::vertical,"color"},
	menu_button{Point{x_max()-100,80}, 100, 40, "color menu", cb_menu},
	lines_menu{Point{x_max()-100,160},100,40,Menu::vertical,"lines"},
	lines_button{Point{x_max()-100,160}, 100, 40, "lines menu", cb_lines_menu}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	lines_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
	lines_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
	lines_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
	attach(color_menu);
	attach(lines_menu);
	color_menu.hide();
	lines_menu.hide();
	attach(menu_button);
	attach(lines_button);
	attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
int x = next_x.get_int();
int y = next_y.get_int();

lines.add(Point{x,y});

ostringstream ss;
ss << '(' << x << ',' << y << ')';
xy_out.put(ss.str());
redraw();
}