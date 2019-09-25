/*************************************************************************
* Program Filename: pokestop.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for pokestop class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "event.h"
#include "struct.h"

#ifndef POKESTOP_H
#define POKESTOP_H

class Pokestop: public Event{
	public:
		void spawn(char **, int *, int *);
		void detect(int *, int *);
		void action(const int, const int, inventory *, int *, int *, int *);
		void change_spots(const int, const int, int *);
};

#endif
