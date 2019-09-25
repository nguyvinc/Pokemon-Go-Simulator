/*************************************************************************
* Program Filename: cave.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for cave class
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>

#include "cave.h"

using namespace std;

/*************************************************************************
* Function: spawn
* Description: show location of the cave
* Parameters: map array, place and current array
* Preconditions: none
* Postconditions: cave is shown on the map
* Return: none
*************************************************************************/
void Cave::spawn(char **map, int *place, int *current){
	if(!(place[2] == current[0] && place[3] == current[1]))
		map[place[2]][place[3]] = 'c';
}

/*************************************************************************
* Function: detect
* Description: tells is player is adjacent to cave
* Parameters: place and current array
* Preconditions: player in next to the cave
* Postconditions: message pops up
* Return: none
*************************************************************************/
void Cave::detect(int *place, int *current){
	if(current[0] == place[2]){
		if(current[1] == (place[3] - 1) || current[1] == (place[3] + 1))
			cout << "You see a precious stone nearby" << endl;
	}
	else if(current[1] == place[3]){
		if(current[0] == (place[2] - 1) || current[0] == (place[2] + 1))
			cout << "You see a precious stone nearby" << endl;
	}
}

/*************************************************************************
* Function: action
* Description: evolve pokemon if possible
* Parameters: int row, col, and pokeballs, place and current array, inventory bag
* Preconditions: player lands on cave
* Postconditions: pokemon are evolved if possible
* Return: none
*************************************************************************/
void Cave::action(const int row, const int col, inventory *bag, int *place, int *current, int *pokeballs){
	if(current[0] == place[2] && current[1] == place[3]){
		cout << "You've arrived at the Megastone Cave" << endl;
		if(bag[0].name == "Kirlia"){
			cout << "Your Kirlia has evolved into Gardevoir!" << endl;
			bag[0].name = "Gardevoir";
		}
		if(bag[1].name == "Kadabra"){
			cout << "Your Kadabra has evolved into Alakazam!" << endl;
			bag[1].name = "Alakazam";
		}
		if(bag[2].name == "Pidgeotto"){
			cout << "Your Pidgeotto has evolved into Pidgeot!" << endl;
			bag[2].name = "Pidgeot";
		}
		if(bag[3].name == "Golbat"){
			cout << "Your Golbat has evolved into Crobat!" << endl;
			bag[3].name = "Crobat";
		}
		if(bag[4].name == "Lairon"){
			cout << "Your Lairon has evolved into Aggron!" << endl;
			bag[4].name = "Aggron";
		}
		if(bag[5].name == "Metang"){
			cout << "Your Metang has evolved into Metagross!" << endl;
			bag[5].name = "Metagross";
		}
	}
}