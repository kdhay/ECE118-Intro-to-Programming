#include"library.h"

char maze[100][100];
char already_rob[100][100], already_enemy[100][100], been[100];
int n_row=0, n_column=0;
int i=1, j=5, player_r=7, player_c=13;
int tres_r=9, tres_c=29;
int r_enemy=1, c_enemy=2;
image*robot=image_from_file("bot.gif");
image*zomb=image_from_file("tenor.gif");
image*gold=image_from_file("gold.gif");
image*grass=image_from_file("grass3.gif");
 
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

void print_maze()
{
	for(int i=0;i<n_row;i++)
	{
		for(int j=0; j<n_column; j++)
			cout<<already_rob[i][j];
		cout<<endl;
	}
	cout<<endl;
}

void won_game()
{
	cout<<"You Win!"<<endl;
	make_window(800,400);
	set_pen_color(color::light_green);
	fill_rectangle(0,0,800,400);
	set_pen_color(color::red);
	set_font_size(40);
	move_to(100,100);
	write_string("YOU HAVE WON! WELL DONE.");
	return;
}

void lost_game()
{
	cout<<"You Lost!"<<endl;
	make_window(800,400);
	set_pen_color(color::red);
	fill_rectangle(0,0,800,400);
	set_pen_color(color::black);
	set_font_size(40);
	move_to(100,100);
	write_string("BETTER LUCK NEXT TIME.");
	return;
}

void move_back(image*pic, char arr[][100], int &r_pos, int &c_pos, int &rob_x, int &rob_y, int side)
{
	if(arr[r_pos][c_pos]=='a')
	{
		set_pen_color(color::white);
		fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
		draw_image(pic, rob_x+side+3, rob_y+3);	
		arr[r_pos][c_pos]='r';
		rob_x+=side; //moves right
		i++;
		c_pos++;
	}
	else if(arr[r_pos][c_pos]=='d')
	{
		set_pen_color(color::white);
		fill_rectangle(rob_x+2,rob_y+2,side-2, side-2);
		draw_image(pic, rob_x-side+3, rob_y+3);
		arr[r_pos][c_pos]='r';
		rob_x-=side;  //left
		i++;
		c_pos--;
	}
	else if(arr[r_pos][c_pos]=='w')
	{
		set_pen_color(color::white);
		fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
		draw_image(pic, rob_x+3, rob_y+side+3);
		arr[r_pos][c_pos]='r';
		rob_y+=side; //moves down
		i++;
		r_pos++;
	}
	else if(arr[r_pos][c_pos]=='s')
	{
		set_pen_color(color::white);
		fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
		draw_image(pic, rob_x+3, rob_y-side+3);
		arr[r_pos][c_pos]='r';
		rob_y-=side; //moves up
		i++;
		r_pos--;
	}
}

void move_automatic(image*pic, char arr[][100], int &r, int &c, int &x, int &y, int side)
{
	bool left=true, up=true, right=true, down=true; 
	
	been[0]=arr[r][c-1]; //left
	been[1]=arr[r-1][c]; // up
	been[2]=arr[r][c+1]; //right
	been[3]=arr[r+1][c]; //down
	
	while(true)
	{
		int d= random_in_range(0,3);
		//cout<<"Direction chosen: " << d<< endl;
		if((been[0]=='z'&&maze[r][c-1]!='#')||(been[1]=='z'&&maze[r-1][c]!='#')||(been[2]=='z'&&maze[r][c+1]!='#')||(been[3]=='z'&&maze[r+1][c]!='#'))
		{
			if(d==0)
			{
				if(been[0]=='z'&&maze[r][c-1]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(x+2, y+2, side-2, side-2);
					draw_image(pic, x-side+3, y+3);
					//set_pen_color(red, g, b);
					//fill_rectangle(x-side, y, size, size);	
					arr[r][c-1]='a';
					x-=side; //moves to left
					i++;
					c--;
					break;
				}
				else
					left=false;
			}
			else if(d==1)
			{
				if(been[1]=='z'&&maze[r-1][c]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(x+2, y+2, side-2, side-2);
					//set_pen_color(red, g, b);
					//fill_rectangle(x, y-side, size, size);	
					draw_image(pic, x+3, y+3-side);
					arr[r-1][c]='w';
					y-=side; //up
					i++;
					r--;
					break;
				}
				else
				{
					up=false;
					//break;
				}
			}
			else if(d==2)
			{
				if(been[2]=='z'&&maze[r][c+1]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(x+2, y+2, side-2, side-2);
					//set_pen_color(red, g , b);
					//fill_rectangle(x+side, y, size, size);	
					draw_image(pic, x+3+side, y+3);
					arr[r][c+1]='d';
					x+=side; //right
					i++;
					c++;
					break;
				}
				else
				{
					right=false;	
					//break;
				}
			}
			else if(d==3)
			{
				if(been[3]=='z'&&maze[r+1][c]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(x+2, y+2, side-2, side-2);
					//set_pen_color(red, g, b);
					//fill_rectangle(x, y+side, size, size);
					draw_image(pic, x+3, y+3+side);
					arr[r+1][c]='s';
					y+=side; //moves down
					i++;
					r++;
					break;
				}
				else
				{
					down=false;	
					//break;
				}
			}
		}
		else //if(left==false&&right==false&&up==false&&down==false)
		{
			move_back(pic, arr, r, c, x, y, side);
			break;
		}
	}
}

void move_enemy(int &r, int &c, int &x, int &y, int &rob_r, int &rob_c, int &rob_x, int &rob_y, int side)
{
	draw_image(zomb, x+3, y+3); //enemy
	move_automatic(zomb, already_enemy, r, c, x, y, side);

	if(rob_x==x&&rob_y==y)
	{
		lost_game();
		return;
	}
	if(r==rob_r&&c==rob_c)
	{
		lost_game();
		return;
	}
	
}

void move_robots(int p, int q, int side)
{
	//int tres_posx=tres_c*side+j, tres_posy=tres_r*side+j;
	int rob_x=player_c*side; //starting pos- column
	int rob_y=player_r*side; //starting pos- row
	int enemy_x=c_enemy*side; //starting pos- column
	int enemy_y=r_enemy*side; //starting pos- row
	double red=0.2, g=1.0, b=1.0;
	bool automatic=false;

	draw_image(robot, rob_x+3, rob_y+3);

	while(true)
	{
		//print_maze();
		if(automatic==false)
		{			
			if(player_c==tres_c&&player_r==tres_r)
			{
				won_game();
				for(int i=0; i<p; i++) //draws yellow road
				{
					for(int j=0; j<q; j++)
					{
						if(already_rob[i][j]=='a'||already_rob[i][j]=='w'||already_rob[i][j]=='s'||already_rob[i][j]=='d')
						{
							set_pen_color(color::yellow); //yellow road
							fill_rectangle(rob_x, rob_y, side, side);
						}
					}
				}
				break;
			}

			char key = wait_for_key_typed();
		
			if(key=='a'|| key == -91)
			{
				if(maze[player_r][player_c-1]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
					//set_pen_color(red, g, b);
					//fill_rectangle(rob_x-side, rob_y, new_s, new_s);	
					draw_image(robot, rob_x+3-side, rob_y+3);
					rob_x-=side; //moves to left
					i++;
					already_rob[player_r][player_c-1]='a';
					player_c--;
				}
			}
			else if(key=='d'|| key == -89)
			{
				if(maze[player_r][player_c+1]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
					draw_image(robot, rob_x+3+side, rob_y+3);
					//set_pen_color(red, g, b);
					//fill_rectangle(rob_x+side, rob_y, new_s, new_s);	
					rob_x+=side; //moves to right
					i++;
					already_rob[player_r][player_c+1]='d';
					player_c++;
				}
			}
			else if(key=='w'|| key == -90)
			{
				if(maze[player_r-1][player_c]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
					draw_image(robot, rob_x+3, rob_y-side+3);
					//set_pen_color(red, g, b);
					//fill_rectangle(rob_x, rob_y-side, new_s, new_s);	
					rob_y-=side; //moves up
					i++;
					already_rob[player_r-1][player_c]='w';
					player_r--;
				}
			}
			else if(key=='s'|| key == -88)
			{
				if(maze[player_r+1][player_c]!='#')
				{
					set_pen_color(color::white);
					fill_rectangle(rob_x+2,rob_y+2, side-2, side-2);
					draw_image(robot, rob_x+3, rob_y+3+side);
					//set_pen_color(red, g, b);
					//fill_rectangle(rob_x, rob_y+side, new_s, new_s);	
					rob_y+=side; //moves down
					i++;
					already_rob[player_r+1][player_c]='s';
					player_r++;
				}
			}
			else if(key=='g')
				automatic=true;

			else if (key=='m')
				automatic=false;

			else if(key=='b')
				move_back(robot, already_rob, player_r, player_c, rob_x, rob_y, side);
		}
		else
			move_automatic(robot, already_rob, player_r, player_c, rob_x, rob_y, side); 

		move_enemy(r_enemy, c_enemy, enemy_x, enemy_y, player_r, player_c, rob_x, rob_y, side);
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
				draw_image(grass, c, r);
				//set_pen_color(color::dark_grey);
				//fill_rectangle(c, r, side, side); //square:side
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
				draw_image(gold, c, r);
				//set_pen_color(color::red);
				//fill_rectangle(c, r, side, side); //square:side
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
	move_robots(n_row, n_column, side);
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

	for(int i=0; i<n_row; i++)
	{	
		for(int j=0; j<n_column; j++)
		{
			already_rob[i][j]='z';
			already_enemy[i][j]='z';
		}
	}
	
	draw_maze(n_row, n_column, side);
	
}

void main()
{
	read_maze();
	//print_maze();
}
