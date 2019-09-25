/*************************************************************************
* Program Filename: cave.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for cave class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "event.h"
#include "struct.h"

#ifndef CAVE_H
#define CAVE_H

class Cave: public Event{
	public:
		void spawn(char **, int *, int *);
		void detect(int *, int *);
		void action(const int, const int, inventory *, int *, int *, int *);
};

#endif
