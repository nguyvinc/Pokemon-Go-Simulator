/*************************************************************************
* Program Filename: flying.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for flying class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "pokemon.h"
#include "struct.h"

#ifndef FLYING_H
#define FLYING_H

class Flying: public Pokemon{
	public:
		Flying();
		
		void spawn(char **, int *, int *);
		void detect(int *, int *);
		void action(const int, const int, inventory *, int *, int * ,int *);
		void throw_ball(const int, const int, inventory *, int *, int *);
		void evolve(inventory *);
		void escaped(const int, const int, int *);
};

#endif