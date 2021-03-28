#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Open_polyline lines;
	bool wait_for_button();

	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	Menu lines_menu;
	Button lines_button;
	
	void change(Color c) { lines.set_color(c); }
	void hide_menu() { color_menu.hide(); menu_button.show(); }
	void changelns(Line_style ls) { lines.set_style(ls); }
	void hide_lines() {lines_menu.hide(); lines_button.show();}
	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void solid_pressed() { changelns(Line_style::solid); hide_lines(); }
	void dash_pressed() { changelns(Line_style::dash); hide_lines(); }
	void dot_pressed() { changelns(Line_style::dot); hide_lines(); }
	void lines_menu_pressed() { lines_button.hide(); lines_menu.show(); }
	void next();
	void quit();
	
	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_black(Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}
	static void cb_menu(Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed();}
	static void cb_solid(Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}
	static void cb_dash(Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_dot(Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_lines_menu(Address, Address pw){reference_to<Lines_window>(pw).lines_menu_pressed();}
	static void cb_next(Address, Address pw) {reference_to<Lines_window>(pw).next();}
	static void cb_quit(Address, Address pw) {reference_to<Lines_window>(pw).quit();}
};