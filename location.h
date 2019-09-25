/*************************************************************************
* Program Filename: location.h
* Author: Vincent Nguyen
* Date: 5/24/17
* Desciption: contains declaration for location class and functions
* Input: none
* Output: none
*************************************************************************/
#include <iostream>

#include "cave.h"
#include "pokestop.h"
#include "psychic.h"
#include "flying.h"
#include "rock.h"
#include "struct.h"

#ifndef LOCATION_H
#define LOCATION_H

class Location{
	private:
		char **map;
		int row;
		int col;
		int place[18]; //row, col - home, cave, pokestop, ps1, ps2, f1, f2, r1, r2
		int current[2]; //row, col
		inventory bag[6]; //Raltz, Abra, Pidgey, Zubat, Aron, Beldum
		int pokeballs;
		
		Cave c;
		Pokestop p;
		Psychic ps1, ps2;
		Flying f1, f2;
		Rock r1, r2;
		Event *e;

	public:
		char **get_map() const;
		void set_map(char **);
		int get_row() const;
		void set_row(const int);
		int get_col() const;
		void set_col(const int);
		int *get_place();
		void set_place(int *);
		int *get_current();
		void set_current(int, int);
		inventory *get_bag();
		void set_bag(inventory *);
		int get_pokeballs() const;
		void set_pokeballs(const int);

		Cave get_Cave() const;
		void set_Cave(const Cave);
		Pokestop get_Pokestop() const;
		void set_Pokestop(const Pokestop);
		Psychic get_ps1() const;
		void set_ps1(const Psychic);
		Psychic get_ps2() const;
		void set_ps2(const Psychic);
		Flying get_f1() const;
		void set_f1(const Flying);
		Flying get_f2() const;
		void set_f2(const Flying);
		Rock get_r1()const;
		void set_r1(const Rock);
		Rock get_r2()const;
		void set_r2(const Rock);
		Event *get_Event();
		void set_Event(Event *);

		Location();
		~Location();
		Location(const Location &);
		void operator=(const Location &);

		bool check_command_line(int, char *[]);
		void make_map();
		void set_entities();
		void reset_place();
		void spawn_event();
		
		void game_start(int *);
		void show_locations();		
		void spawn_home();
		void print_map() const;
		
		void move();
		void get_move(int *);
		void move_up();
		void move_right();
		void move_down();
		void move_left();
		void view_inventory();
		
		void location_action();
		void location_detect();
		void check_home(bool *, int *);
		void get_loop(int *);
		void get_new_grid(char *);
};

#endif
