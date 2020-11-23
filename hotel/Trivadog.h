#ifndef TRIVADOG_H
#define TRIVADOG_H
//-----------------------------------------------------------------------------------------------//
#include "Hostel.h"
//-----------------------------------------------------------------------------------------------//
typedef struct Trivadog
{
	int		num_of_hostels;   //number of hostels
	Hostel** hostels; 		//a pointer to an array of pointers to hostels
} Trivadog;
//-----------------------------------------------------------------------------------------------//
Trivadog*	DuplicateTrivadog(const Trivadog* source);
Trivadog*	AddHostel(Trivadog* td, const Hostel* ht);
void		FreeTrivadog(Trivadog* td);
int			GetTotalAvailableRooms(Trivadog* td, const char* type);
int*		GetTotalAvailableRoomsInArr(Trivadog* td, char** arr_type, int size);
void		SortByName(Trivadog* td);
void		SortByRate(Trivadog* td);
//-----------------------------------------------------------------------------------------------//
#endif