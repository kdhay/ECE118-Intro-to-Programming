#include"library.h"

void manyclouds()
{	int nclouds = random_in_range(4,10);
	
	for(int i=1; i<nclouds; i++)
	{
		set_pen_color(color::white);
		int const cloudwidth = random_in_range(20,80); //size of cloud
		int direction = random_in_range(55, 100);
		set_pen_width(cloudwidth);
		draw_point();
		set_heading_degrees(direction);
		int const spacebetween = cloudwidth/2; //creates multiple clouds in same spot to give it dimension
		move_distance(spacebetween);
	}
}

void clouds()
{	int const nclouds = random_in_range(8, 15);

	for(int i=1; i<nclouds; i++)
	{
		int x = random_in_range(0, 800);
		int y = random_in_range(10, 300);
		move_to(x, y);
		manyclouds();
	}
}

void sunny_sky(int x, int y, int t)
{   move_to(x,y);
	set_pen_width(100);
	set_pen_color(1.0, 0.92, 0.0);
	draw_point();
	clouds();
}

void stars()
{	int const nstars = random_in_range(25, 100);
	
	for(int i=1; i<nstars; i++)
	{	
		int x = random_in_range(0, 900);
		int y = random_in_range(10, 300);
		set_pen_color(0.91, 0.93, 0.93);
		set_pen_width(4);
		move_to(x,y);
		draw_point();
	}
}

void starry_night(int x, int y, int t)
{	stars();
	move_to(x, y);
	set_pen_width(100);
	set_pen_color(0.91, 0.93, 0.93); 
	draw_point();
}

void time_of_day(int t)
{
	const int x = 800;

	if (t==1) //early morning and late at night (very dark)
	{
		set_pen_color(color::black);
		fill_rectangle(0, 0, 900, 500);
		const int y = 100;
		starry_night(x, y, t);
		set_pen_color(color::black);
		set_heading_degrees(90);
		move_distance(25);
		draw_point();
	}
	
	else if (t==2) // morning
	{	
		set_pen_color(0.6, 0.8, 1.0);
		fill_rectangle(0, 0, 900, 500);
		const int y = 100;
		sunny_sky(x, y, t);
	}
		
	else if (t==3) // afteroon 12pm
	{	
		set_pen_color(0.3, 0.78, 1.0);
		fill_rectangle(0, 0, 900, 500);
		const int y = 60;
		sunny_sky(x, y, t);
	}	

	else if (t==4) // after 6
	{	
		set_pen_color(0, 0.35, 0.58);
		fill_rectangle(0, 0, 900, 500);
		const int y = 60;
		sunny_sky(x, y, t);
	}	

	else if (t==5) // night
	{	
		set_pen_color(0, 0.14, 0.39);
		fill_rectangle(0, 0, 900, 500);
		const int y = 60;
		starry_night(x, y, t);
		set_pen_color(0, 0.14, 0.39);
		set_heading_degrees(90);
		move_distance(25);
		draw_point();
	}	
}

void mountain1(int m)
{
	const int distance = random_in_range(100,150);
	const int angle = random_in_range(45,70);
	
	if (m>0)
	{
		set_pen_width(1);
		set_heading_degrees(angle);
		draw_distance(distance);
		note_position();
		turn_right_by_degrees(random_in_range(60,90));
		draw_distance(distance);
		note_position();
		mountain1(m-1);
	}
}

void mountain2(int n)
{
	const int distance = random_in_range(50,100);
	const int angle = random_in_range(45,70);
	
	if (n>0)
	{
		set_pen_width(1);
		set_heading_degrees(angle);
		draw_distance(distance);
		note_position();
		turn_right_by_degrees(random_in_range(60,90));
		draw_distance(distance);
		note_position();
		mountain1(n-1);
	}
}

void mountain3(int o)
{
	const int distance = random_in_range(50,100);
	const int angle = random_in_range(45,70);
	
	if (o>0)
	{
		set_pen_width(1);
		set_heading_degrees(angle);
		draw_distance(distance);
		note_position();
		turn_right_by_degrees(random_in_range(60,90));
		draw_distance(distance);
		note_position();
		mountain1(o-1);
	}
}

void all_mountains(int m, int n, int o)
{
	const int pos1 = random_in_range(200,230);
	move_to(0, pos1);
	start_shape();
	set_pen_color(0.77, 0.77, 0.75); // pale grey
	mountain1(m);
	move_to(900,500);
	note_position();
	move_to(0,500);
	note_position();
	move_to(0, pos1);
	note_position();
	fill_shape();
	int const pos2 = random_in_range(245,260);
	move_to(0, pos2);
	start_shape();
	set_pen_color(0.65, 0.77, 0.64); //pale green
	mountain2(n);
	move_to(900,500);
	note_position();
	move_to(0,500);
	note_position();
	move_to(0, pos2);
	note_position();
	fill_shape();
	int const pos3 = random_in_range(270,280);
	move_to(0, pos3);
	start_shape();
	set_pen_color(0.79, 0.71, 0.80); //pale purple
	mountain3(o);
	move_to(900,500);
	note_position();
	move_to(0,500);
	note_position();
	move_to(0, pos3);
	note_position();
	fill_shape();
}

void street(int t)
{
	if (t==2 || t==3){
		set_pen_color(0.45, 0.45, 0.45); }
	else {
		set_pen_color(0.17, 0.21, 0.23);}

	set_heading_degrees(90);
	fill_rectangle(0, 445, 900, 55);
}

void street_lines(int x)
{
	if (x>0)
	{	int const y = 445+(55/2.0);
		set_pen_color(color::white);
		fill_rectangle(x, y, 20, 5);
		street_lines(x-40);
	}
}

void sidewalk()
{
	set_pen_color(color::light_grey);
	fill_rectangle(0,400,900, 45);
	move_to(0,445);
	set_pen_color(color::black);
	set_heading_degrees(90);
	set_pen_width(1);
	draw_distance(900); 
}

void one_window(int x, int y, int w, int h, bool door)
{ 
	if (!door)
	{
		int random_window = random_in_range(1,10);
		if (random_window == 1)
		{
			fill_rectangle(x, y, w, h);
			int red= random_in_range(100,255);//curtain color
			int w_new = w/4.0; 
			int x_new = x+3*w/4.0;
			move_to(x,y);
			fill_rectangle(x, y, w_new, h, red);
			fill_rectangle(x_new, y, w_new, h, red);

		}
		
		else 
		{
			fill_rectangle(x, y, w, h);
		}
	}
	else 
	{
		fill_rectangle(x+(w/3), y+h-20, 2*w/3, 30, color::orange);
	}

}

void window_row(int x, int y, int w, int h, int X, bool door) 
{
	if(X>0) //dealing with horizontal- no of windows in a row
	{
		int make_door = random_in_range(1,2);

		if((make_door == 1 || X == 1) && door)
			one_window(x, y, w, h, true);
		else 
			one_window(x, y, w, h, false);

		move_to(x, y);

		if(make_door == 1 && door)
			window_row(x+w+10, y, w, h, X-1, false);
		else
			window_row(x+w+10, y, w, h, X-1, door);
	}
}

void all_office_windows(int x, int y, int w, int h, int X, int Y)
{
	if(Y>0)
	{
		window_row(x, y, w, h, X, false);
		move_to(x,y);
		all_office_windows(x, y+h+10, w, h, X, Y-1);
	}
}

void all_windows(int x, int y, int w, int h, int X, int Y)
{
	if(Y>0)
	{
		if(Y>1)
		{	
			window_row(x, y, w, h, X, false);
			move_to(x,y);
			all_windows(x, y+h+10, w, h, X, Y-1);
		}

		if (Y==1)
		{
			window_row(x, y, w, h, X, true);
			move_to(x,y);
			all_windows(x, y+h+10, w, h, X, Y-1);
		}
	}
}

void building_color()
{
	int red= random_in_range(50,250);//color out of 255
	int green= random_in_range(50,150);//color out of 255
	int blue= random_in_range(50,250);//color out of 255
	double r= red/255.0;
	double g= green/255.0;
	double b= blue/255.0;
	set_pen_color(r,g,b);
}

void office_building(int x, int y, int h)
{
	
	const int w = random_in_range(100,200); //width of building
	building_color();
	fill_rectangle(x, y, w, h);
	int X = random_in_range(4,6); //columns (no. of windows in 1 row)
	int Y = random_in_range(4,6); //rows (no. of windows in 1 column)
	int w_new = (w-((X+1)*10))/X; // width of window
	int x_new = x+10;   //start pos- top-left corner
	int y_new = 410-h+10; 
	int h_new = (h-((Y+1)*10))/Y; //height of window
	cout << "X: " << X << " Y: " << Y << " w_new: " << w_new << " x_new: " << x_new << " y_new: " << y_new << " h_new: " << h_new << endl;
	set_pen_color(0.0, 0.0, 0.18);
	all_office_windows(x_new, y_new, w_new, h_new, X, Y);
	//all_windows(x_new, y_new, w_new, h_new, X, Y);
}

void draw_city_scene(int x)
{
	int space_left = 900-x;
	const int random_pos = random_in_range(215,230);
	if (random_pos <= space_left)	
		{
			const int h = random_in_range(130,350);
			const int y = 410-h;
			office_building(x,y,h);
			draw_city_scene(x+random_pos);
		}
}

void one_house(int x, int y, int h)
{
	int w = random_in_range(60,150);
	set_pen_color(1.0, 0.84, 0.48);
	fill_rectangle(x, y, w, h);
	set_pen_color(0.8, 0.23, 0.31);
	move_to(x-5,y);
	start_shape();
	note_position();
	set_heading_degrees(0);
	turn_right_by_degrees(45);
	draw_to(x+(w/2), y-30);
	note_position();
	draw_to(x+w+5,y);
	note_position();
	draw_to(x-5,y);
	note_position();
	fill_shape();
	//set_pen_color(color::orange);
	//fill_rectangle(x+(w/2), y+h-30, 20, 30);
	int X = random_in_range(2,3); // no. of windows in a row
	int Y = random_in_range(2, 3); // no. of windows in a column
	int w_new = (w-((X+1)*10))/X; // width of window
	int x_new = x+10;   //start pos- top-left corner
	int y_new = 420-h+10; 
	int h_new = (h-((Y+1)*10))/Y; //height of window
	set_pen_color(color::light_blue);
	all_windows(x_new, y_new, w_new, h_new, X, Y);
}

void draw_suburbs(int x)
{
	int space_left = 875-x;
	const int random_pos = random_in_range(140,200);
	if (random_pos <= space_left)	
		{
			const int h = random_in_range(80, 100);
			const int y = 420-h;
			one_house(x, y, h);
			draw_suburbs(x+random_pos);
		}
}

void grass()
{
	for(int i=0; i<30000; i++)
	{	
		double r = random_in_range(90,170);
		double b = random_in_range(90,160);
		double g = random_in_range(170,255);
		set_pen_color(r/255.0, g/255.0, b/255.0);
		int x_pos = random_in_range(0,900);
		int y_pos = random_in_range(400,444); //on sidewalk alone
		move_to(x_pos,y_pos);
		set_pen_width(1);
		set_heading_degrees(0);
		draw_distance(2);
	}
}

void random_leaf_color()
{
	const int red = random_in_range(50, 100);
	const int green = random_in_range(116, 255);
	const int blue = random_in_range(50, 100);
	set_pen_width(4);
	set_pen_color(red/255.0, green/255.0, blue/255.0);
}

void tree(int x, int y)	
{
	const int nleaves = random_in_range(150, 250); // no. of leaves
	move_to(x, y);
	set_pen_color(color::brown);
	int height = random_in_range(23,45);
	fill_rectangle(x, y, 5, -height); //tree trunk 

		for(int i=0; i<=nleaves; i++) //leaves
		{			 
			const int xpos = random_in_range(x-15, x+20); //where leaves beign
			const int ypos = random_in_range(y-35, y-75); 
			random_leaf_color();
			move_to(xpos, ypos-height);
			draw_point(); //leaves
		}
}

void all_trees(int x, int y)
{
	int space_left = 900-x;
	const int random_pos = random_in_range(60,100);
	if (random_pos < space_left)	
		{
			tree(x,y);
			all_trees(x+random_pos, y);
		}
}

void car(int x, int y)
{
	building_color();
	fill_rectangle(x, y, 30, 25);
	fill_rectangle(x+30, y+25, 15, -15);
	move_to(x+10, y+25);
	set_pen_color(color::black); 
	set_pen_width(10);
	draw_point(); // back wheel
	move_to(x+30, y+25);
	draw_point(); //front wheel
	set_pen_color(color::dark_grey);
	fill_rectangle(x+5, y+4, 8, 8); //windows
	fill_rectangle(x+15, y+4, 8, 8);
	set_pen_color(color::yellow);
	fill_rectangle(x+41, y+10, 4, 4); 
}

void all_cars(int x, int y)
{
	int space_left = 900-x;
	const int random_pos = random_in_range(70,200);
	if (random_pos < space_left)	
		{
			car(x,y);
			all_cars(x+random_pos, y);
		}
}

void scene(){
	const int t = random_in_range(1, 5);
	make_window(900, 500);
	time_of_day(t);
	all_mountains(10,10,10);
	street(t);
	sidewalk();
	grass();
	draw_city_scene(10);
	draw_suburbs(40);
	all_trees(25,440);
	street_lines(900);
	all_cars(random_in_range(30, 60), 460);
	print(t);
}

void main(){
	scene(); }
