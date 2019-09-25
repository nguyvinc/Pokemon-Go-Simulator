/*************************************************************************
* Program Filename: rock.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for rock class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "pokemon.h"
#include "struct.h"

#ifndef ROCK_H
#define ROCK_H

class Rock: public Pokemon{
	public:
		Rock();
		
		void spawn(char **, int *, int *);
		void detect(int *, int *);
		void action(const int, const int, inventory *, int *, int * ,int *);
		void throw_ball(const int, const int, inventory *, int *, int *);
		void evolve(inventory *);
		void escaped(const int, const int, int *);
};

#endif