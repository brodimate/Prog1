/*
g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;


    Simple_window win {Point{100,100}, 800, 1000,"drill13"};
    

    Lines grid;
    for(int i = 100; i<= 800; i += 100)
    {
        grid.add(Point{i,0}, Point{i, 800});
        grid.add(Point{0,i}, Point{800, i});
    }


    Rectangle rec1{Point{0,0},100,100};
    rec1.set_fill_color(Color::red);
    
    Rectangle rec2{Point{100,100},100,100};
    rec2.set_fill_color(Color::red);
    
    Rectangle rec3{Point{200,200},100,100};
    rec3.set_fill_color(Color::red);
    
    Rectangle rec4{Point{300,300},100,100};
    rec4.set_fill_color(Color::red);
    
    Rectangle rec5{Point{400,400},100,100};
    rec5.set_fill_color(Color::red);
    
    Rectangle rec6{Point{500,500},100,100};
    rec6.set_fill_color(Color::red);
    
    Rectangle rec7{Point{600,600},100,100};
    rec7.set_fill_color(Color::red);
    
    Rectangle rec8{Point{700,700},100,100};
    rec8.set_fill_color(Color::red);


    Image i1{Point{0,300}, "200x200.jpg"};
    Image i2{Point{300,0}, "200x200.jpg"};
    Image i3{Point{300,600}, "200x200.jpg"};
    Image i4{Point{600,300}, "200x200.jpg"};
    Image i5{Point{0,0}, "100x100.jpg"};

   
    win.set_label("drill13");
    win.attach(grid);
    win.attach(rec1);
    win.attach(rec2);
    win.attach(rec3);
    win.attach(rec4);
    win.attach(rec5);
    win.attach(rec6);
    win.attach(rec7);
    win.attach(rec8);   
    win.attach(i1);
    win.attach(i2);
    win.attach(i3);
    win.attach(i4);
    win.attach(i5);


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            win.wait_for_button();
            if(j < 7)
            {
                i5.move(100,0);
            }   
            else
            {
                i5.move(-700,100);
            }     
        }
    }
}

