#include"library.h"

char maze[100][100];
int n_row=0;
int n_column=0;

void grid(int n_row, int n_column, int side)
{
	int x=n_column*side; //total width of widnow
	int y=n_row*side; //total length
	set_pen_color(color::black);

	move_to(0,0);
	for(int i=0; i<n_row; i++)
	{
		set_heading_degrees(90);
		draw_distance(x); // horizontal lines
		move_relative(-x, side); //returns to extreme left and moves down by width
	}
	move_to(0,0);
	for(int j=0; j<n_column; j++)
	{
		set_heading_degrees(180);
		draw_distance(y); //vertical lines
		move_relative(side, -y);
	}
}

void move_random(int &r, int &c, int &x, int &y, int side, double red, double g , double b)
{
	int j=5;
	//int r= row;
	//int c= column;
	int i=1;

	int size=side-2*j;

	int d= random_in_range(1,4);

	if(d==1)
	{
		if(maze[r][c-1]!='#')
		{
			set_pen_color(color::white);
			fill_rectangle(x, y, size, size);
			set_pen_color(red, g, b);
			fill_rectangle(x-side, y, size, size);	
			x-=side; //moves to left
			i++;
			c--;
		}
	}
	if(d==2)
	{
		if(maze[r][c+1]!='#')
		{
			set_pen_color(color::white);
			fill_rectangle(x, y, size, size);
			set_pen_color(red, g, b);
			fill_rectangle(x+side, y, size, size);	
			x+=side; //moves to left
			i++;
			c++;
		}
	}
	if(d==3)
	{
		if(maze[r-1][c]!='#')
		{
			set_pen_color(color::white);
			fill_rectangle(x, y, size, size);
			set_pen_color(red, g , b);
			fill_rectangle(x, y-side, size, size);	
			y-=side; //moves up
			i++;
			r--;
		}
	}
	if(d==4)
	{
		if(maze[r+1][c]!='#')
		{
			set_pen_color(color::white);
			fill_rectangle(x, y, size, size);
			set_pen_color(red, g, b);
			fill_rectangle(x, y+side, size, size);	
			y+=side; //moves down
			i++;
			r++;
		}
	}
	
}

void move_enemy(int &r, int &c, int &rob_x, int &rob_y, int side)
{
	int i=1;
	int j=5;
	//int r=1,c=2; //change this to suit
	int enemy_x=c*side+j; //starting pos- column
	int enemy_y=r*side+j; //starting pos- row
	int new_s=side-2*j; 
	double red=0.4, g= 0, b=0.4;
	
	set_pen_color(red, g, b);
	fill_rectangle(enemy_x, enemy_y, new_s, new_s); //enemy
	
	move_random(r, c, enemy_x, enemy_y, side, red, g, b);

	if(rob_x==enemy_x&&rob_y==enemy_y)
	{
		cout<<"You lost!";
		set_pen_color(color::red);
		move_to(100,100);
		write_string("You lost!");
	}
	
}
void move_robots(int side)
{
	int i=1, j=5;
	int r=7,c=13, tres_posx=29*side+j, tres_posy=9*side+j;
	int r_enemy=1, c_enemy=2;
	int rob_x=c*side+j; //starting pos- column
	int rob_y=r*side+j; //starting pos- row
	int new_s=side-2*j; //so that the robot does not cover the grid lines
	double red=0.2, g=1.0, b=1.0;
	bool automatic=false;

	set_pen_color(red, g, b);
	fill_rectangle(rob_x, rob_y, new_s, new_s); //original robot
	while(true)
	{
		if(automatic==false)
		{
			
			if(rob_x==tres_posx&&rob_y==tres_posy)
			{
				cout<<"You Win!"<<endl;
				set_pen_color(color::red);
				move_to(100,100);
				write_string("You Win!");
				break;
			}
			char key = wait_for_key_typed();
		
			if(key=='a'|| key == -91)
			{
				if(maze[r][c-1]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x,rob_y, new_s,new_s);
					set_pen_color(red, g, b);
					fill_rectangle(rob_x-side, rob_y, new_s, new_s);	
					rob_x-=side; //moves to left
					i++;
					c--;
				}
			}
			else if(key=='d'|| key == -89)
			{
				if(maze[r][c+1]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x,rob_y, new_s,new_s);
					set_pen_color(red, g, b);
					fill_rectangle(rob_x+side, rob_y, new_s, new_s);	
					rob_x+=side; //moves to right
					i++;
					c++;
				}
			}
			else if(key=='w'|| key == -90)
			{
				if(maze[r-1][c]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x,rob_y, new_s,new_s);
					set_pen_color(red, g, b);
					fill_rectangle(rob_x, rob_y-side, new_s, new_s);	
					rob_y-=side; //moves up
					i++;
					r--;
				}
			}
			else if(key=='s'|| key == -88)
			{
				if(maze[r+1][c]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x,rob_y, new_s,new_s);
					set_pen_color(red, g, b);
					fill_rectangle(rob_x, rob_y+side, new_s, new_s);	
					rob_y+=side; //moves down
					i++;
					r++;
				}
			}
			else if(key=='g')
				automatic=true;
		}
		else
			move_random(r, c, rob_x, rob_y, side, red , g, b);

		move_enemy(r_enemy, c_enemy, rob_x, rob_y, side);
		wait(0.2);
		
	}
}


void draw_maze(int n_row, int n_column, int side)
{ //side=length of each square side
	int x= n_column*side; //total width
	int y= n_row*side; //total legnth
	make_window(x,y); 

	for(int i=0; i<n_row; i++)
	{
		int r=i*side; //length of one square

		for(int j=0; j<n_column; j++)
		{
			int c=j*side; 

			if(maze[i][j]=='#')
			{
				set_pen_color(color::dark_grey);
				fill_rectangle(c, r, side, side); //square:side
			}
			else if(maze[i][j]=='~')
			{
				set_pen_color(color::white);
				fill_rectangle(c, r, side, side); //square:side
			}
			else if(maze[i][j]=='+') //starting pos
			{
				set_pen_color(color::green);
				fill_rectangle(c, r, side, side); //square:side
			}
			else if(maze[i][j]=='$') //treasure
			{
				set_pen_color(color::red);
				fill_rectangle(c, r, side, side); //square:side
			}
				else if(maze[i][j]=='E') //enemy
			{
				set_pen_color(color::black);
				fill_rectangle(c, r, side, side); //square:side
			}
			else
				return;
		}
		cout<<endl;
	}
	grid(n_row, n_column, side);
	move_robots(side);
}


void read_maze()
{
	ifstream fin("maze.txt");
	string piece;
	int side= 30;//n_row/n_column*5;

	if(fin.fail())
	{
		cout<<"Unable to open file."<<endl;
		exit(1);
	}
	int r=0;

	while(true)
	{
		if(!fin.eof())
		{
			getline(fin,piece); //any line
			n_row++;
			n_column=piece.length();

			for(int c=0; c<n_column;c++) 
			{
				maze[r][c]=piece[c];//stores maze into array by char

				if(piece[c]=='$')
				{
					cout<<"Treasure located at: "<<r<<", "<<c<<endl;
					cout<<endl;
				}
				if(piece[c]=='*')
				{
					cout<<"Enemy located at: "<<r<<", "<<c<<endl;
					cout<<endl;
				}
				if(piece[c]=='+')
				{
					cout<<"Robot located at: "<<r<<", "<<c<<endl;
					cout<<endl;
				}
			}
			r++;  //next row
		}
		else
			break;
		
	}
	fin.close();
	cout<<"Number of rows: "<<n_row<< " and number of columns: "<< n_column; //total rows and columns
	
	draw_maze(n_row, n_column, side);
	
}
void print_maze()
{
	for(int i=0;i<n_row;i++)
	{
		for(int j=0; j<n_column; j++)
			cout<<maze[i][j];
		cout<<endl;
	}
}
void main()
{
	read_maze();
	print_maze();
}
