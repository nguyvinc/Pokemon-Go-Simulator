/*************************************************************************
* Program Filename: flying.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for flying class
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "flying.h"
#include "struct.h"

using namespace std;

/*************************************************************************
* Function: flying default constructor
* Description: constructs a default flying
* Parameters: none
* Preconditions: flying object created
* Postconditions: flying object has default values
* Return: none
*************************************************************************/
Flying::Flying(){
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
void Flying::spawn(char **map, int *place, int *current){
	if(type == 1){ //Pidgey
		if(!(place[10] == current[0] && place[11] == current[1]))
			map[place[10]][place[11]] = 'P';
	}
	else if (type == 2){ //Zubat
		if(!(place[12] == current[0] && place[13] == current[1]))
			map[place[12]][place[13]] = 'Z';
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
void Flying::detect(int *place, int *current){
	if(type == 1){ 
		if(current[0] == place[10]){
			if(current[1] == (place[11] - 1) || current[1] == (place[11] + 1))
				cout << "Catch the Pidgey nearby" << endl;
		}
		else if(current[1] == place[11]){
			if(current[0] == (place[10] - 1) || current[0] == (place[10] + 1))
				cout << "Catch the Pidgey nearby" << endl;
		}
	} 
	else if(type == 2){
		if(current[0] == place[12]){
			if(current[1] == (place[13] - 1) || current[1] == (place[13] + 1))
				cout << "Catch the Zubat nearby" << endl;
		}
		else if(current[1] == place[13]){
			if(current[0] == (place[12] - 1) || current[0] == (place[12] + 1))
				cout << "Catch the Zubat nearby" << endl;
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
void Flying::action(const int row, const int col, inventory *bag, int *place, int *current, int *pokeballs){
	int choice;
	if(type == 1){
		if(current[0] == place[10] && current[1] == place[11]){
			cout << "You encountered a Pidgey. Do you want to catch it? " << endl << "You have " << *pokeballs << " pokeballs left (1-yes, 2-no)" << endl;
			get_choice(&choice);
			if(choice == 1 && *pokeballs > 0)
				throw_ball(row, col, bag, place, pokeballs);
			else if(choice == 2)
				cout << "You decided not to catch the Pidgey" << endl << endl;
			else
				cout << "You have no pokeballs left" << endl;
		}
	}
	if(type == 2){
		if(current[0] == place[12] && current[1] == place[13]){
			cout << "You encountered an Zubat. Do you want to catch it? " << endl << "You have " << *pokeballs << " pokeballs left (1-yes, 2-no)" << endl;
			get_choice(&choice);
			if(choice == 1 && *pokeballs > 0)
				throw_ball(row, col, bag, place, pokeballs);
			else if(choice == 2)
				cout << "You decided not to catch the Zubat" << endl << endl;
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
void Flying::throw_ball(const int row, const int col, inventory *bag, int *place, int *pokeballs){
	*pokeballs -= 1;
	srand(time(NULL));
	int chance = rand() % 2;
	if(chance == 0){
		if(type == 1){
			bag[2].caught += 1;
			cout << "You caught the Pidgey!" << endl << "You've caught Pidgey " << bag[2].caught << " times" << endl << endl;
			evolve(bag);
		}
		else if(type == 2){
			bag[3].caught += 1;
			cout << "You caught the Zubat!" << endl << "You've caught Zubat " << bag[3].caught << " times" << endl << endl;
			evolve(bag);
		}
	}
	else{
		if(type == 1)
			cout << "The Pidgey flew away!" << endl << endl;
		else if(type == 2)
			cout << "The Zubat flew away!" << endl << endl;
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
void Flying::evolve(inventory *bag){
	if (type == 1){
#ifdef DEBUG
		if (bag[2].caught == 1){
#endif
#ifndef DEBUG
		if (bag[2].caught == 3){
#endif
			cout << "Your Pidgey evolved into Pidgeotto!" << endl << endl;
			bag[2].name = "Pidgeotto";
		}	
	}
	else if(type == 2){
#ifdef DEBUG
		if (bag[3].caught == 1){
#endif
#ifndef DEBUG
		if (bag[3].caught == 3){
#endif
			cout << "Your Zubat evolved into Golbat!" << endl << endl;
			bag[3].name = "Golbat";
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
void Flying::escaped(const int row, const int col, int *place){
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
					place[10] = r_row;
					place[11] = r_col;
				}
			}	
			else if(type == 2){
				for(int i=0; i<9; i++){
					if(place[2*i] == r_row && place[(2*i)+1] == r_col)
						change = false;
				}
				if(change == true){
					place[12] = r_row;
					place[13] = r_col;
				}
			}
		}
	}
}

