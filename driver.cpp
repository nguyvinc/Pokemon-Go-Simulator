/*************************************************************************
* Program Filename: driver.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: Starts the game
* Input: Grid size
* Output: Starts the game
*************************************************************************/
#include <iostream>
#include <stdlib.h>

#include "location.h"
#include "event.h"
#include "cave.h"
#include "pokestop.h"
#include "pokemon.h"
#include "psychic.h"
#include "flying.h"
#include "rock.h"

using namespace std;

/*************************************************************************
* Function: main
* Description: initiallizes the game
* Parameters: command line arguments
* Preconditions: proper command line arguments are provided
* Postconditions: game runs
* Return: none
*************************************************************************/
int main(int argc, char *argv[]){
	Location l;
	int loop = 0;
	bool proceed = l.check_command_line(argc, argv);
	
	if (proceed == false)
		cout << "Invalid arguments" << endl;
	else{
		do{
			if(loop == 3){
				cout << "Row number: " << endl;
				l.get_new_grid(argv[1]);
				cout << "Column number: " << endl;
				l.get_new_grid(argv[2]);
			}
			l.set_row(atoi(argv[1]));
			l.set_col(atoi(argv[2]));
			l.make_map();
			l.reset_place();
			l.spawn_event();
			l.set_current(l.get_place()[0], l.get_place()[1]);
			l.set_entities();
			l.game_start(&loop);
		}while(loop == 2 || loop == 3);
	}
	
	return 0;
}