/*************************************************************************
* Program Filename: pokemon.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for pokemon class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "event.h"
#include "struct.h"

#ifndef POKEMON_H
#define POKEMON_H

class Pokemon: public Event{
	protected:
		int type;
	public:
		int get_type()const;
		void set_type(const int);
		
		void get_choice(int *);
		virtual void throw_ball(const int, const int, inventory *, int *, int *) = 0;
		virtual void evolve(inventory *) = 0;
		virtual void escaped(const int, const int, int *) = 0;
};

#endif