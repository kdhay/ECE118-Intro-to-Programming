#include"library.h"


void draw_button(int x, int y, int side, int n)
{ 
	set_pen_color(color::white);
	fill_rectangle(x-1, y-1, side+2, side+2); //outline
	set_pen_color(color::black);
	fill_rectangle(x, y, side, side); //square:side
	set_pen_color(color::light_green);
	set_font_size(side);
	move_to(x+(side/4), y+(4*side/5));
	write_char(n);
}

void calculator(int size) //side of button
{
	make_window(size, size+10); //size of calculator
	set_pen_color(color::light_grey);
	fill_rectangle(0, 0, size, size+10);

	int side = 2*(size-10)/13; //5(size+2)+6(side/4) = 13/2 side + 10

	const int x1 = side/4+2; //+2 becasuse of draw_calc function
	const int x2 = x1+5*side/4+2;
	const int x3 = x2+5*side/4+2;
	const int x4 = x3+5*side/4+2;
	const int x5 = x4+5*side/4+2;
	const int y1 = 3*side/2+4; 
	const int y2 = 5*side/4+2+y1;
	const int y3 = 5*side/4+2+y2;
	const int y4 = 5*side/4+2+y3;
	int div = L'÷'; 
	int sqrt = L'√';
	int cbrt = L'³√';


	draw_button(x1, y1, side, '7');
	draw_button(x2, y1, side, '8');
	draw_button(x3, y1, side, '9');
	draw_button(x4, y1, side, '+');
	draw_button(x5, y1, side, cbrt); //cubic root
	
	draw_button(x1, y2, side, '4');
	draw_button(x2, y2, side, '5');
	draw_button(x3, y2, side, '6');
	draw_button(x4, y2, side, '-');
	draw_button(x5, y2, side, sqrt); //square root

	draw_button(x1, y3, side, '1');
	draw_button(x2, y3, side, '2');
	draw_button(x3, y3, side, '3');
	draw_button(x4, y3, side, 'x');
	draw_button(x5, y3, side, '^'); //to the power of

	draw_button(x1, y4, side, 'c');
	draw_button(x2, y4, side, '0');
	draw_button(x3, y4, side, '=');
	draw_button(x4, y4, side, div);
	draw_button(x5, y4, side, '%'); //modulo
}

void display(double display_numb, int size)
{
	int side = 2*(size-10)/13; //5(size+2)+6(side/4) = 13/2 side + 10
	const int x1 = side/4+2; //+2 becasuse of draw_calc function
	
	set_pen_color(color::black); //display for calc
	fill_rectangle(x1, side/4, size-x1-side/4, side);
	set_pen_color(color::white);
	fill_rectangle(x1+1, side/4+1, size-x1-2-side/4,side-2);
	set_pen_color(color::black);
	move_to(size-25, side/4+35);
	write_string(display_numb, direction::west);
}

int column_n(int x, int size)
{
	int side = 2*(size-10)/13; //total = 5(size+2)+6(side/4) = 13/2 side + 10

	int x1 = side/4+2; //+2 becasuse of draw_calc function
	int x2 = x1+5*side/4+2;
	int x3 = x2+5*side/4+2;
	int x4 = x3+5*side/4+2;
	int x5 = x4+5*side/4+2;
	

	if(x<x2)
		return 1; 

	if(x>=x2 && x<x3)
		return 2; 
			
	if(x>=x3 && x<x4)
		return 3; 

	if(x>=x4 && x<x5)
		return 4; 

	else
		return 5; 
		
	}

int row_n(int y, int size)
{
	int side = 2*(size-10)/13; //total = 5(size+2)+6(side/4) = 13/2 side + 10

	int y1 = 3*side/2+4; 
	int y2 = 5*side/4+2+y1;
	int y3 = 5*side/4+2+y2;
	int y4 = 5*side/4+2+y3;
	

	if(y<y2)
		return 1; 

	if(y<y3 && y>=y2)
		return 2; 
			
	if(y<y4 && y>=y3)
		return 3; 

	else
		return 4;
	}

int button_pressed(int x, int y, int size)
{	
		int c = column_n(x, size);	
		int r = row_n(y, size);
		
		if(r==1 && c==1)
			return 7;
		if(r==1 && c==2)
			return 8;
		if(r==1 && c==3)
			return 9;
		if(r==1 && c==4) //+
			return 11;
		if(r==1 && c==5) // factorial
			return 12;
		if(r==2 && c==1)
			return 4;
		if(r==2 && c==2)
			return 5;
		if(r==2 && c==3)
			return 6;
		if(r==2 && c==4) // -
			return 13;
		if(r==2 && c==5)//squareroot
			return 14;
		if(r==3 && c==1)
			return 1;
		if(r==3 && c==2)
			return 2;
		if(r==3 && c==3)
			return 3;
		if(r==3 && c==4) // x
			return 15;
		if(r==3 && c==5)//^
			return 16;
		if(r==4 && c==1) //c
			return 17;
		if(r==4 && c==2) 
			return 0;
		if(r==4 && c==3) //=
			return 18;
		if(r==4 && c==4) // /
			return 19;
		if(r==4 && c==5)//modulo
			return 20;
}

void math(int size)
{
	double current_number=0;
	double result=0.0; //function_n=button pressed
	double op2=0;
	int num=0;
	int function=0;

	while(true)
	{
			wait_for_mouse_click();
			int x = get_click_x();
			int y = get_click_y();
			int function_n= button_pressed(x, y, 500);

			if(function_n<=9) // number alone
			{
				current_number=(current_number*10)+function_n;
				display(current_number, size);
			}
	
			else if (function_n==18) //operator
		   {

					   if(function==11)//addition
						   result=current_number+op2;

						if(function==13)//subtraction
							 result=op2-current_number;

						if(function==15) //x
							result=current_number*op2;

						if(function==16) //to the power of
							result=pow(op2,current_number);

						if(function==19) //div
							result=op2/current_number;
						
						if(function==20) //%
							result=(int)op2%(int)current_number;
						
						display(result,size);
				   }
			else if(function_n==11)
			{
				op2=current_number;
				current_number=0;
				function=11;
			}
			else if(function_n==12) //cube root
			{
				current_number=pow(current_number,1/3.0);
				display(current_number,size);
			}
			else if(function_n==13)
			{
				op2=current_number;
				current_number=0;
				function=13;
			}
			else if(function_n==14) //square root
			{
				current_number=pow(current_number,1/2.0);
				display(current_number,size);
			}
			else if(function_n==15)
			{
				op2=current_number;
				current_number=0;
				function=15;
			}
			else if(function_n==16)
			{
				op2=current_number;
				current_number=0;
				function=16;			 
			}
			else if(function_n==17)
			{
				op2=0;
				current_number=0;
				function=17;
				display(0,size);
			}
			else if(function_n==19)
			{
				op2=current_number;
				current_number=0;
				function=19;
			}
			else if(function_n==20)
			{
				op2=current_number;
				current_number=0;
				function=20;			 
			}

	}
}
	


void print_column_row_button(int size)
{
	int x = 0;
	int y = 0;

	for (int i=1; i <= 30; i++)
	{
		wait_for_mouse_click();
		x = get_click_x();
		y = get_click_y();
		cout << "Mouse was clicked Row " << row_n(y, size) << " Column " << column_n(x, size) << endl;
		cout << "Button pressed was assigned the number: " << button_pressed(x, y, size) << endl;
	}
}


void main()
{
	//make_window(200,200);
	//draw_button(50, 50, 50, '9')
	calculator(500);
	math(500);
	//print_column_row_button(500);
	
}
