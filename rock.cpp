/*************************************************************************
* Program Filename: rock.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for rock class
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "rock.h"
#include "struct.h"

using namespace std;

/*************************************************************************
* Function: rock default constructor
* Description: constructs a default rock
* Parameters: none
* Preconditions: rock object created
* Postconditions: rock object has default values
* Return: none
*************************************************************************/
Rock::Rock(){
	type = 0;
}

/*************************************************************************
* Function: spawn
* Description: shows the location of the object on the map
* Parameters: map array, place array, current array
* Preconditions: none
* Postconditions: objects will show on the map
* Return: none
*************************************************************************/
void Rock::spawn(char **map, int *place, int *current){
	if(type == 1){ //Aron
		if(!(place[14] == current[0] && place[15] == current[1]))
			map[place[14]][place[15]] = 'A';
	}
	else if (type == 2){ //Beldum
		if(!(place[16] == current[0] && place[17] == current[1]))
			map[place[16]][place[17]] = 'B';
	}
}

/*************************************************************************
* Function: detect
* Description: checks to see if the player is adjecent to the pokemon
* Parameters: place array, current array
* Preconditions: player is next to pokemon
* Postconditions: message pops up
* Return: none
*************************************************************************/
void Rock::detect(int *place, int *current){
	if(type == 1){
		if(current[0] == place[14]){
			if(current[1] == (place[15] - 1) || current[1] == (place[15] + 1))
				cout << "Catch the Aron nearby" << endl;
		}
		else if(current[1] == place[15]){
			if(current[0] == (place[14] - 1) || current[0] == (place[14] + 1))
				cout << "Catch the Aron nearby" << endl;
		}
	}
	else if(type == 2){
		if(current[0] == place[16]){
			if(current[1] == (place[17] - 1) || current[1] == (place[17] + 1))
				cout << "Catch the Beldum nearby" << endl;
		}
		else if(current[1] == place[17]){
			if(current[0] == (place[16] - 1) || current[0] == (place[16] + 1))
				cout << "Catch the Beldum nearby" << endl;
		}
	}
}

/*************************************************************************
* Function: action
* Description: can try to catch the pokemon
* Parameters: row and col ints, inventory bag, place and current array, int pokeballs
* Preconditions: player lands on object
* Postconditions: none
* Return: none
*************************************************************************/
void Rock::action(const int row, const int col, inventory *bag, int *place, int *current, int *pokeballs){
	int choice;
	if(type == 1){
		if(current[0] == place[14] && current[1] == place[15]){
			cout << "You encountered an Aron. Do you want to catch it? " << endl << "You have " << *pokeballs << " pokeballs left (1-yes, 2-no)" << endl;
			get_choice(&choice);
			if(choice == 1 && *pokeballs > 0)
				throw_ball(row, col, bag, place, pokeballs);
			else if(choice == 2)
				cout << "You decided not to catch the Aron" << endl << endl;
			else
				cout << "You have no pokeballs left" << endl;
		}
	}
	if(type == 2){
		if(current[0] == place[16] && current[1] == place[17]){
			cout << "You encountered an Beldum. Do you want to catch it? " << endl << "You have " << *pokeballs << " pokeballs left (1-yes, 2-no)" << endl;
			get_choice(&choice);
			if(choice == 1 && *pokeballs > 0)
				throw_ball(row, col, bag, place, pokeballs);
			else if(choice == 2)
				cout << "You decided not to catch the Beldum" << endl << endl;
			else
				cout << "You have no pokeballs left" << endl;
		}
	}
}

/*************************************************************************
* Function: throw ball
* Description: player tries to catch pokemon
* Parameters: row, col, pokeball ints, inventory bag, place array
* Preconditions: player decides to throw ball
* Postconditions: none
* Return: none
*************************************************************************/
void Rock::throw_ball(const int row, const int col, inventory *bag, int *place, int *pokeballs){
	*pokeballs -= 1;
	srand(time(NULL));
	int chance = rand() % 4;
	if(chance == 0){
		if(type == 1)
			cout << "The Aron ran away!" << endl << endl;
		else if(type == 2)
			cout << "The Beldum ran away!" << endl << endl;
	}
	else{
		if(type == 1){
			bag[4].caught += 1;
			cout << "You caught the Aron!" << endl << "You've caught Aron " << bag[4].caught << " times" << endl << endl;
			evolve(bag);
		}
		else if(type == 2){
			bag[5].caught += 1;
			cout << "You caught the Beldum!" << endl << "You've caught Beldum " << bag[5].caught << " times" << endl << endl;
			evolve(bag);
		}
	}
	escaped(row, col, place);
}

/*************************************************************************
* Function: evolve
* Description: checks if the player's pokemon evolves
* Parameters: inventory bag
* Preconditions: none
* Postconditions: none
* Return: none
*************************************************************************/
void Rock::evolve(inventory *bag){
	if (type == 1){
#ifdef DEBUG
		if (bag[4].caught == 1){
#endif
#ifndef DEBUG
		if (bag[4].caught == 4){
#endif
			cout << "Your Aron evolved into Lairon!" << endl << endl;
			bag[4].name = "Lairon";
		}	
	}
	else if(type == 2){
#ifdef DEBUG
		if (bag[5].caught == 1){
#endif
#ifndef DEBUG
		if (bag[5].caught == 4){
#endif
			cout << "Your Beldum evolved into Metang!" << endl << endl;
			bag[5].name = "Metang";
		}
	}
}

/*************************************************************************
* Function: escaped
* Description: move the object to a new place if possible
* Parameters: int row and col, place array
* Preconditions: player tried to catch pokemon
* Postconditions: pokemon is moved if possible
* Return: none
*************************************************************************/
void Rock::escaped(const int row, const int col, int *place){
	if(!(row == 3 && col == 3)){
		srand(time(NULL));
		bool change = false;
		int r_row, r_col;
		while(change == false){
			change = true;
			r_row = rand() % row;
			r_col = rand() % col;
			if(type == 1){
				for(int i=0; i<9; i++){
					if(place[2*i] == r_row && place[(2*i)+1] == r_col)
						change = false;
				}
				if(change == true){
					place[14] = r_row;
					place[15] = r_col;
				}
			}	
			else if(type == 2){
				for(int i=0; i<9; i++){
					if(place[2*i] == r_row && place[(2*i)+1] == r_col)
						change = false;
				}
				if(change == true){
					place[16] = r_row;
					place[17] = r_col;
				}
			}
		}
	}
}

