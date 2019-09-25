/*************************************************************************
* Program Filename: psychic.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for psychic class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "pokemon.h"
#include "struct.h"

#ifndef PSYCHIC_H
#define PSYCHIC_H

class Psychic: public Pokemon{
	public:
		Psychic();
		
		void spawn(char **, int *, int *);
		void detect(int *, int *);
		void action(const int, const int, inventory *, int *, int * ,int *);
		void throw_ball(const int, const int, inventory *, int *, int *);
		void evolve(inventory *);
		void escaped(const int, const int, int *);
};

#endif