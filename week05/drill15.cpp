#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; } 
double slope(double x) { return x/2; } 
double square(double x) { return x*x; } 
double sloping_cos(double x) { return cos(x)-slope(x); } 


int main()
{
    using namespace Graph_lib;

    
    constexpr int xmax = 600;
    constexpr int ymax = 600;
    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    constexpr int r_min = -10;
    constexpr int r_max = 11;
    constexpr int n_points = 400;
    constexpr int x_scale = 20;
    constexpr int y_scale = 20;
    constexpr int xlength = xmax - 200;
    constexpr int ylength = ymax - 200;
    Point orig{x_orig,y_orig};

    Simple_window win {Point{100,100}, xmax, ymax,"Function graphs"};
    
    Axis x {Axis::x, Point{100,y_orig}, xlength, xlength/x_scale, "1 = = 20 pixels"};
    Axis y {Axis::y, Point{x_orig,ylength+100}, ylength, ylength/y_scale, "1 = = 20 pixels"};
    
    x.set_color(Color::red);
    y.set_color(Color::red);


    Function first {one, r_min, r_max, orig, n_points, x_scale, y_scale};

    Function second {slope, r_min, r_max, orig, n_points, x_scale, y_scale};


    Text text {Point{100,ymax-170}, "x/2"};

    Function third {square, r_min, r_max, orig, n_points, x_scale, y_scale};

    Function fourth {[] (double x) { return cos(x); }, r_min, r_max, orig, n_points, x_scale, y_scale};

    fourth.set_color(Color::blue);

    Function fifth {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};


    win.attach(first);
    win.attach(second);
    win.attach(third);
    win.attach(fourth);
    win.attach(fifth);
    win.attach(text);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();
}
