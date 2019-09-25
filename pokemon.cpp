/*************************************************************************
* Program Filename: pokemon.cpp
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains function definitions for pokemon class
* Input: varies
* Output: varies
*************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "pokemon.h"
#include "struct.h"

using namespace std;

//gets type
int Pokemon::get_type()const{
	return type;
}
//sets type
void Pokemon::set_type(const int t){
	type = t;
}

/*************************************************************************
* Function: get choice
* Description: gets an integer input
* Parameters: choice pointer
* Preconditions: none
* Postconditions: input is a 1 or 2
* Return: none
*************************************************************************/
void Pokemon::get_choice(int *choice){
	char input[256];
	bool valid = false;
	while(valid == false){
		cout << "Enter a 1 or 2: ";
		cin.getline(input, 256);
		if(strlen(input) == 1){
			if(input[0] == '1' || input[0] == '2')
				valid = true;
		}
	}
	*choice = atoi(input);
}