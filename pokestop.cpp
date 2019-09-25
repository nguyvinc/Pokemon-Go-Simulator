/*************************************************************************
* Program Filename: pokestop.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for pokestop class
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>
#include <stdlib.h>

#include "pokestop.h"

using namespace std;

/*************************************************************************
* Function: spawn
* Description: shows the location of the pokestop
* Parameters: map array, place and current array
* Preconditions: none
* Postconditions: shows the location of the pokestop
* Return: none
*************************************************************************/
void Pokestop::spawn(char **map, int *place, int *current){
	if(!(place[4] == current[0] && place[5] == current[1]))
		map[place[4]][place[5]] = 'p';
}

/*************************************************************************
* Function: detect
* Description: checks if the player is adjacent to the pokestop
* Parameters: place and current array
* Preconditions: player is next to object
* Postconditions: message pops up
* Return: none
*************************************************************************/
void Pokestop::detect(int *place, int *current){
	if(current[0] == place[4]){
		if(current[1] == (place[5] - 1) || current[1] == (place[5] + 1))
			cout << "Fill up on pokeballs" << endl;
	}
	else if(current[1] == place[5]){
		if(current[0] == (place[4] - 1) || current[0] == (place[4] + 1))
			cout << "Fill up on pokeballs" << endl;
	}
}

/*************************************************************************
* Function: action
* Description: gives player pokeballs
* Parameters: int row, col, pokeballs, current and place array, inventory bag
* Preconditions: player is on top of object
* Postconditions: gives pokeballs
* Return: none
*************************************************************************/
void Pokestop::action(const int row, const int col, inventory *bag, int *place, int *current, int *pokeballs){
	srand(time(NULL));
	if(current[0] == place[4] && current[1] == place[5]){
		int ball = (rand() % 8) + 3;
		cout << "You have arrived at the pokestop and received " << ball << " pokeballs from the pokestop" << endl;
		*pokeballs += ball;
		change_spots(row, col, place);
	}
}

/*************************************************************************
* Function: change spots
* Description: moves pokestop if possible
* Parameters: int row and col, place array
* Preconditions: player lands on pokestop
* Postconditions: pokestop moved
* Return: none
*************************************************************************/
void Pokestop::change_spots(const int row, const int col, int *place){
	if(!(row == 3 && col == 3)){
		srand(time(NULL));
		bool change = false;
		int r_row, r_col;
		while(change == false){
			change = true;
			r_row = rand() % row;
			r_col = rand() % col;
			for(int i=0; i<9; i++){
				if(place[2*i] == r_row && place[(2*i)+1] == r_col)
					change = false;
			}
			if(change == true){
				place[4] = r_row;
				place[5] = r_col;
			}
		}
	}
}