/*************************************************************************
* Program Filename: location.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for location class, runs the game
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "location.h"
#include "cave.h"
#include "pokestop.h"
#include "psychic.h"
#include "flying.h"
#include "rock.h"
#include "struct.h"

using namespace std;

//gets map
char **Location::get_map() const{
	return map;
}
//sets map
void Location::set_map(char **m){
	map = m;
}

//gets row
int Location::get_row() const{
	return row;
}
//sets row
void Location::set_row(const int r){
	row = r;
}

//gets col
int Location::get_col() const{
	return col;
}
//sets col
void Location::set_col(const int c){
	col = c;
}

//gets place
int *Location::get_place(){
	return place;
}
//sets place
void Location::set_place(int *p){
	for (int i=0; i<18; i++){
		place[i] = p[i];
	}
}

//gets current
int *Location::get_current(){
	return current;
}
//sets current
void Location::set_current(int cur1, int cur2){
	current[0] = cur1;
	current[1] = cur2;
}

//gets bag
inventory *Location::get_bag(){
	return bag;
}
//sets bag
void Location::set_bag(inventory *other){
	for(int i=0; i<6; i++){
		bag[i] = other[i];
	}
}

//gets pokeballs
int Location::get_pokeballs()const{
	return pokeballs;
}
//sets pokeballs
void Location::set_pokeballs(const int p){
	pokeballs = p;
}



//gets cave
Cave Location::get_Cave()const{
	return c;
}
//sets cave
void Location::set_Cave(const Cave c1){
	c = c1;
}

//gets pokestop
Pokestop Location::get_Pokestop() const{
	return p;
}
//sets pokestop
void Location::set_Pokestop(Pokestop p1){
	p = p1;
}

//gets ps1
Psychic Location::get_ps1() const{
	return ps1;
}
//sets ps1
void Location::set_ps1(const Psychic psy){
	ps1 = psy;
}

//gets ps2
Psychic Location::get_ps2() const{
	return ps2;
}
//sets ps2
void Location::set_ps2(const Psychic psy){
	ps2 = psy;
}

//gets f1
Flying Location::get_f1()const{
	return f1;
}
//sets f1
void Location::set_f1(const Flying f){
	f1 = f;
}

//gets f2
Flying Location::get_f2()const{
	return f2;
}
//sets f2
void Location::set_f2(const Flying f){
	f2 = f;
}

//gets r1
Rock Location::get_r1()const{
	return r1;
}
//sets r1
void Location::set_r1(const Rock r){
	r1 = r;
}

//gets r2
Rock Location::get_r2()const{
	return r2;
}
//set r2
void Location::set_r2(const Rock r){
	r2 = r;
}

//gets e
Event *Location::get_Event(){
	return e;
}
//sets e
void Location::set_Event(Event *e1){
	e = e1;
}


/*************************************************************************
* Function: location default constructor
* Description: constructs a location object with default values
* Parameters: none
* Preconditions: none
* Postconditions: location object with default values created
* Return: none
*************************************************************************/
Location::Location(){
	map = NULL;
	for (int i=0; i<6; i++){
		bag[i].caught = 0;
	}
	bag[0].name = "Raltz";
	bag[1].name = "Abra";
	bag[2].name = "Pidgey";
	bag[3].name = "Zubat";
	bag[4].name = "Aron";
	bag[5].name = "Beldum";
	pokeballs = 5;
}

/*************************************************************************
* Function: Location deconstructor
* Description: frees memory used in location
* Parameters: none
* Preconditions: none
* Postconditions: memory is freed
* Return: none
*************************************************************************/
Location::~Location(){
	if (map != NULL){
		for (int i=0; i<row; i++)
			delete []map[i];
		delete []map;
	}
}

/*************************************************************************
* Function: Location copy constructor
* Description: constructs a location object using values from another location object
* Parameters: location object
* Preconditions: none
* Postconditions: object construct with same values as another location object
* Return: none
*************************************************************************/
Location::Location(const Location &other){
	row = other.row;
	col = other.col;
	map = new char*[row];
	for(int i=0; i<row; i++)
		map[i] = new char[col];
	for(int i=0; i<row; i++){
		for (int j=0; j<col; j++)
			map[i][j] = other.map[i][j];
	}
	for (int i=0; i<18; i++)
		place[i] = other.place[i];
	current[0] = other.current[0];
	current[1] = other.current[1];
	for(int i=0; i<6; i++){
		bag[i].name = other.bag[i].name;
		bag[i].caught = other.bag[i].caught;
	}
	pokeballs = other.pokeballs;
}

/*************************************************************************
* Function: Location assignment operator overload
* Description: assigns values of one location object to another
* Parameters: location object
* Preconditions: none
* Postconditions: both objects have same values
* Return: none
*************************************************************************/
void Location::operator=(const Location &other){
	if (map != NULL){
		for (int i=0; i<row; i++)
			delete []map[i];
		delete []map;
	}
	row = other.row;
	col = other.col;
	map = new char*[row];
	for(int i=0; i<row; i++)
		map[i] = new char[col];
	for(int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			map[i][j] = other.map[i][j];
		}
	}
	for (int i=0; i<18; i++)
		place[i] = other.place[i];
	current[0] = other.current[0];
	current[1] = other.current[1];
	for(int i=0; i<6; i++){
		bag[i].name = other.bag[i].name;
		bag[i].caught = other.bag[i].caught;
	}
	pokeballs = other.pokeballs;
}



/*************************************************************************
* Function: check command line
* Description: checks command line arguments
* Parameters: argc and argv
* Preconditions: none
* Postconditions: none
* Return: true or false
*************************************************************************/
bool Location::check_command_line(int argc, char *argv[]){
	if(argc == 3){
		for(int i=0; i<strlen(argv[1]); i++)
			if(!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return false;
		if (atoi(argv[1]) < 3)
			return false;

		for(int i=0; i<strlen(argv[2]); i++)
			if(!(argv[2][i] >= '0' && argv[2][i] <= '9'))
				return false;
		if (atoi(argv[2]) < 3)
			return false;
		
		return true;
	}
	else
		return false;
}

/*************************************************************************
* Function: make map
* Description: makes grid for game
* Parameters: none
* Preconditions: none
* Postconditions: grid is made
* Return: none
*************************************************************************/
void Location::make_map(){
	map = new char*[row];
	for(int i=0; i<row; i++){
		map[i] = new char[col];
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			map[i][j] = ' ';
		}
	}
}

/*************************************************************************
* Function: set entities
* Description: spawns players and prepares pokemon
* Parameters: none
* Preconditions: none
* Postconditions: none
* Return: none
*************************************************************************/
void Location::set_entities(){
	map[current[0]][current[1]] = 'X';
	ps1.set_type(1);
	ps2.set_type(2);
	f1.set_type(1);
	f2.set_type(2);
	r1.set_type(1);
	r2.set_type(2);
}

/*************************************************************************
* Function: resets place
* Description: resets place array
* Parameters: none
* Preconditions: none
* Postconditions: all elements in place array are -1
* Return: none
*************************************************************************/
void Location::reset_place(){
	for(int i=0; i<18; i++){
		place[i] = -1;
	}
}

/*************************************************************************
* Function: spawn event
* Description: assigns each event a random place on the map
* Parameters: none
* Preconditions: none
* Postconditions: each event has its own location on the map
* Return: none
*************************************************************************/
void Location::spawn_event(){
	srand(time(NULL));
	int r_row, r_col;
	for(int i=0; i<9; i++){
		bool empty = false;
		while (empty == false){
			empty = true;
			r_row = rand() % row;
			r_col = rand() % col;
			for (int j=0; j<9; j++){
				if(place[2*j] == r_row && place[(2*j)+1] == r_col)
					empty = false;
			}
		}
		place[2*i] = r_row;
		place[(2*i)+1] = r_col;
	}
}



/*************************************************************************
* Function: game start
* Description: runs the game
* Parameters: loop int
* Preconditions: command line arguments are valid
* Postconditions: game runs
* Return: none
*************************************************************************/
void Location::game_start(int *loop){
	bool win = false;
	int print = 1;
	while (win == false){
		if (print == 1){
#ifdef DEBUG
			show_locations(); //shows location of everything
#endif
			print_map();
			location_detect();
			print = 0;
		}
		move();
		check_home(&win, loop);
		if(win == false){
#ifdef DEBUG
			show_locations(); //shows location of everything
#endif
			print_map();
			location_action();
			location_detect();
		}
	}
}

/*************************************************************************
* Function: show locations
* Description: shows location of all events on the map
* Parameters: none
* Preconditions: none
* Postconditions: all events are displayed on the map
* Return: none
*************************************************************************/
void Location::show_locations(){
	spawn_home();
	
	e = &c;
	e->spawn(map, place, current);
	e = &p;
	e->spawn(map, place, current);
	
	e = &ps1;
	e->spawn(map, place, current);
	e = &ps2;
	e->spawn(map, place, current);
	
	e = &f1;
	e->spawn(map, place, current);
	e = &f2;
	e->spawn(map, place, current);
	
	e = &r1;
	e->spawn(map, place, current);
	e = &r2;
	e->spawn(map, place, current);
}

/*************************************************************************
* Function: spawn home
* Description: show the location of the home on the map
* Parameters: none
* Preconditions: none
* Postconditions: home is shown on the map
* Return: none
*************************************************************************/
void Location::spawn_home(){
	if(!(place[0] == current[0] && place[1] == current[1]))
		map[place[0]][place[1]] = 'H';
}

/*************************************************************************
* Function: print map
* Description: prints the map
* Parameters: none
* Preconditions: none
* Postconditions: the map is printed
* Return: none
*************************************************************************/
void Location::print_map() const{
	cout << "-";
	for (int j=0; j<col; j++)
		cout << "--";
	cout << endl;

	for (int i=0; i<row; i++){
		cout << "|";
		for (int j=0; j<col; j++)
			cout << map[i][j] << "|";
		cout << endl;
		cout << "-";
		for (int j=0; j<col; j++)
			cout << "--";
		cout << endl;
	}
}



/*************************************************************************
* Function: move
* Description: ask if player wants to move or view inventory
* Parameters: none
* Preconditions: none
* Postconditions: player moves
* Return: none
*************************************************************************/
void Location::move(){
	int choice = 5;
	while(choice == 5){
		cout << "Which direction would you like to move? (1-up, 2-right, 3-down, 4-left) or would you like to view your inventory (5)?" << endl;
		get_move(&choice);
		if(choice == 1)
			move_up();
		else if (choice == 2)
			move_right();
		else if (choice == 3)
			move_down();
		else if (choice == 4)
			move_left();
		else if (choice == 5){
			view_inventory();
			print_map();
		}
	}
}

/*************************************************************************
* Function: get move
* Description: gets input 1 to 5
* Parameters: int move
* Preconditions: none
* Postconditions: input is an integer between 1 and 5
* Return: none
*************************************************************************/
void Location::get_move(int *move){
	bool valid = false;
	char input[256];
	while(valid == false){
		valid = true;
		cout << "Enter an integer between 1 and 5: ";
		cin.getline(input, 256);
		if (strlen(input) == 1){
			if(!(input[0] >= '1' && input[0] <= '5'))
				valid = false;
		}
		else
			valid = false;
	}
	*move = atoi(input);
}

/*************************************************************************
* Function: move up
* Description: move the player up
* Parameters: none
* Preconditions: none
* Postconditions: player moves up
* Return: none
*************************************************************************/
void Location::move_up(){
	if(current[0] > 0){
		map[current[0]][current[1]] = ' ';
		set_current((current[0])-1, current[1]);
		map[current[0]][current[1]] = 'X';
	}
	else
		cout << "\nYou can't move up" << endl;
}

/*************************************************************************
* Function: move right
* Description: player moves right
* Parameters: none
* Preconditions: none
* Postconditions: player moves right
* Return: none
*************************************************************************/
void Location::move_right(){
	if(current[1] < (col - 1)){
		map[current[0]][current[1]] = ' ';
		set_current(current[0], (current[1]+1));
		map[current[0]][current[1]] = 'X';
	}
	else
		cout << "\nYou can't move right" << endl;
}

/*************************************************************************
* Function: move down
* Description: player moves down
* Parameters: none
* Preconditions: none
* Postconditions: player moves down
* Return: none
*************************************************************************/
void Location::move_down(){
	if(current[0] < (row - 1)){
		map[current[0]][current[1]] = ' ';
		set_current((current[0])+1, current[1]);
		map[current[0]][current[1]] = 'X';
	}
	else
		cout << "\nYou can't move down" << endl;
}

/*************************************************************************
* Function: move left
* Description: player moves left
* Parameters: none
* Preconditions: none
* Postconditions: player moves left
* Return: none
*************************************************************************/
void Location::move_left(){
	if(current[1] > 0){
		map[current[0]][current[1]] = ' ';
		set_current(current[0], (current[1]-1));
		map[current[0]][current[1]] = 'X';
	}
	else
		cout << "\nYou can't move left" << endl;
}

/*************************************************************************
* Function: view inventory
* Description: prints inventory info
* Parameters: none
* Preconditions: none
* Postconditions: prints inventory info
* Return: none
*************************************************************************/
void Location::view_inventory(){
	cout << endl << "You have " << pokeballs << " pokeballs left" << endl << "These are your pokemon:" << endl;
	
	cout << "Current evolution: " << bag[0].name << "- Raltz caught " << bag[0].caught << " times" << endl;
	cout << "Current evolution: " << bag[1].name << "- Abra caught " << bag[1].caught << " times" << endl;
	cout << "Current evolution: " << bag[2].name << "- Pidgey caught " << bag[2].caught << " times" << endl;
	cout << "Current evolution: " << bag[3].name << "- Zubat caught " << bag[3].caught << " times" << endl;
	cout << "Current evolution: " << bag[4].name << "- Aron caught " << bag[4].caught << " times" << endl;
	cout << "Current evolution: " << bag[5].name << "- Beldum caught " << bag[5].caught << " times" << endl << endl;
}



/*************************************************************************
* Function: location action
* Description: checks if any events occur
* Parameters: none
* Preconditions: none
* Postconditions: none
* Return: none
*************************************************************************/
void Location::location_action(){
	e = &c;
	e->action(row, col, bag, place, current, &pokeballs);

	e = &p;
	e->action(row, col, bag, place, current, &pokeballs);
	
	e = &ps1;
	e->action(row, col, bag, place, current, &pokeballs);
	e = &ps2;
	e->action(row, col, bag, place, current, &pokeballs);
	
	e = &f1;
	e->action(row, col, bag, place, current, &pokeballs);
	e = &f2;
	e->action(row, col, bag, place, current, &pokeballs);
	
	e = &r1;
	e->action(row, col, bag, place, current, &pokeballs);
	e = &r2;
	e->action(row, col, bag, place, current, &pokeballs);
}

/*************************************************************************
* Function: location detect
* Description: check if player is next to any events
* Parameters: none
* Preconditions: none
* Postconditions: messages print if player is next to events
* Return: none
*************************************************************************/
void Location::location_detect(){
	e = &c;
	e->detect(place, current);

	e = &p;
	e->detect(place, current);
	
	e = &ps1;
	e->detect(place, current);
	e = &ps2;
	e->detect(place, current);
	
	e = &f1;
	e->detect(place, current);
	e = &f2;
	e->detect(place, current);
	
	e = &r1;
	e->detect(place, current);
	e = &r2;
	e->detect(place, current);
}

/*************************************************************************
* Function: check home
* Description: checks if player wins the game
* Parameters: bool win and int loop
* Preconditions: none
* Postconditions: none
* Return: none
*************************************************************************/
void Location::check_home(bool *win, int *loop){
	if (current[0] == place[0] && current[1] == place[1]){
		cout << "You've made it back home" << endl;
		if(bag[0].name == "Gardevoir" && bag[1].name == "Alakazam" && bag[2].name == "Pidgeot" && bag[3].name == "Crobat" && bag[4].name == "Aggron" && bag[5].name == "Metagross"){
			*win = true;
			cout << endl << "Congratulations, you've caught all of the pokemon and returned home" << endl << "Would you like to (1)exit, (2)play with same grid, or (3)play with a different grid size?" << endl;
			get_loop(loop);
			for(int i=0; i<row; i++){
				delete []map[i];
			}
			delete []map;
			map = NULL;
		}
	}
}

/*************************************************************************
* Function: get loop
* Description: gets loop input
* Parameters: int loop
* Preconditions: none
* Postconditions: input will be 1, 2, or 3
* Return: none
*************************************************************************/
void Location::get_loop(int *loop){
	bool valid = false;
	char input[256];
	while (valid == false){
		cout << "Enter a 1, 2, or 3: ";
		cin.getline(input, 256);
		if(strlen(input) == 1){
			if(input[0] == '1' || input[0] == '2' || input[0] == '3')
				valid = true;
		}
	}
	*loop = atoi(input);
}

/*************************************************************************
* Function: get new grid
* Description: get new row and column numbers
* Parameters: argv
* Preconditions: none
* Postconditions: both number will be an integer equal to or above 3
* Return: none
*************************************************************************/
void Location::get_new_grid(char *argv){
	bool valid = false;
	while(valid == false){
		valid = true;
		cout << "Enter an integer: ";
		cin.getline(argv, 256);
		if(strlen(argv) == 1){
			if(!(argv[0] >= '3' && argv[0] <= '9'))
				valid = false;
		}
		else{
			for(int i=0; i<strlen(argv); i++){
				if(!(argv[i] >= '0' && argv[i] <= '9'))
					valid = false;
			}
		}
	}
}

