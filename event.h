/*************************************************************************
* Program Filename: event.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration of event class and prototypes
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "struct.h"

#ifndef EVENT_H
#define EVENT_H

class Event{
	public:
		virtual void spawn(char **, int *, int *) = 0;
		virtual void detect(int *, int *) = 0;
		virtual void action(const int, const int, inventory *, int *, int *, int *) = 0;
};

#endif

