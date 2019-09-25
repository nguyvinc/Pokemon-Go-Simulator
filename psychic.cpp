/*************************************************************************
* Program Filename: psychic.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for psychic class
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "psychic.h"
#include "struct.h"

using namespace std;

/*************************************************************************
* Function: psychic default constructor
* Description: constructs a default psychic
* Parameters: none
* Preconditions: psychic object created
* Postconditions: psychic object has default values
* Return: none
*************************************************************************/
Psychic::Psychic(){
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
void Psychic::spawn(char **map, int *place, int *current){
	if(type == 1){ //Raltz
		if(!(place[6] == current[0] && place[7] == current[1]))
			map[place[6]][place[7]] = 'R';
	}
	else if (type == 2){ //Abra
		if(!(place[8] == current[0] && place[9] == current[1]))
			map[place[8]][place[9]] = 'a';
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
void Psychic::detect(int *place, int *current){
	if(type == 1){
		if(current[0] == place[6]){
			if(current[1] == (place[7] - 1) || current[1] == (place[7] + 1))
				cout << "Catch the Raltz nearby" << endl;
		}
		else if(current[1] == place[7]){
			if(current[0] == (place[6] - 1) || current[0] == (place[6] + 1))
				cout << "Catch the Raltz nearby" << endl;
		}
	}
	else if(type == 2){
		if(current[0] == place[8]){
			if(current[1] == (place[9] - 1) || current[1] == (place[9] + 1))
				cout << "Catch the Abra nearby" << endl;
		}
		else if(current[1] == place[9]){
			if(current[0] == (place[8] - 1) || current[0] == (place[8] + 1))
				cout << "Catch the Abra nearby" << endl;
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
void Psychic::action(const int row, const int col, inventory *bag, int *place, int *current, int *pokeballs){
	int choice;
	if(type == 1){
		if(current[0] == place[6] && current[1] == place[7]){
			cout << "You encountered a Raltz. Do you want to catch it? " << endl << "You have " << *pokeballs << " pokeballs left (1-yes, 2-no)" << endl;
			get_choice(&choice);
			if(choice == 1 && *pokeballs > 0)
				throw_ball(row, col, bag, place, pokeballs);
			else if(choice == 2)
				cout << "You decided not to catch the Raltz" << endl << endl;
			else
				cout << "You have no pokeballs left" << endl;
		}
	}
	if(type == 2){
		if(current[0] == place[8] && current[1] == place[9]){
			cout << "You encountered an Abra. Do you want to catch it? " << endl << "You have " << *pokeballs << " pokeballs left (1-yes, 2-no)" << endl;
			get_choice(&choice);
			if(choice == 1 && *pokeballs > 0)
				throw_ball(row, col, bag, place, pokeballs);
			else if(choice == 2)
				cout << "You decided not to catch the Abra" << endl << endl;
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
void Psychic::throw_ball(const int row, const int col, inventory *bag, int *place, int *pokeballs){
	*pokeballs -= 1;
	srand(time(NULL));
	int chance = rand() % 4;
	if(chance == 0){
		if(type == 1){
			bag[0].caught += 1;
			cout << "You caught the Raltz!" << endl << "You've caught Raltz " << bag[0].caught << " times" << endl << endl;
			evolve(bag);
		}
		else if(type == 2){
			bag[1].caught += 1;
			cout << "You caught the Abra!" << endl << "You've caught Abra " << bag[1].caught << " times" << endl << endl;
			evolve(bag);
		}
	}
	else{
		if(type == 1)
			cout << "The Raltz ran away!" << endl << endl;
		else if(type == 2)
			cout << "The Abra teleported away!" << endl << endl;
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
void Psychic::evolve(inventory *bag){
	if (type == 1){
#ifdef DEBUG
		if (bag[0].caught == 1){
#endif
#ifndef DEBUG
		if (bag[0].caught == 2){
#endif
			cout << "Your Raltz evolved into Kirlia!" << endl << endl;
			bag[0].name = "Kirlia";
		}	
	}
	else if(type == 2){
#ifdef DEBUG
		if (bag[1].caught == 1){
#endif
#ifndef DEBUG
		if (bag[1].caught == 2){
#endif
			cout << "Your Abra evolved into Kadabra!" << endl << endl;
			bag[1].name = "Kadabra";
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
void Psychic::escaped(const int row, const int col, int *place){
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
					place[6] = r_row;
					place[7] = r_col;
				}
			}	
			else if(type == 2){
				for(int i=0; i<9; i++){
					if(place[2*i] == r_row && place[(2*i)+1] == r_col)
						change = false;
				}
				if(change == true){
					place[8] = r_row;
					place[9] = r_col;
				}
			}
		}
	}
}

