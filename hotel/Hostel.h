#ifndef HOSTEL_H
#define HOSTEL_H
//-----------------------------------------------------------------------------------------------//
#include "Room.h"
//-----------------------------------------------------------------------------------------------//
typedef struct Hostel
{
	Room**		rooms;			//a pointer to an array of pointers to rooms
	int			num_of_rooms;	//number of rooms in this hostel
	float		rate;			//the rate of this hostel
	char* 		hostel_name;	//the name of the hostel
} Hostel;
//-----------------------------------------------------------------------------------------------//
Hostel*	AddRoom(Hostel* ht, const  Room* room);
Hostel*	DuplicateHostel(const Hostel* source);
int		GetAvailableRooms(const Hostel* ht, const char* type);
void	FreeHostel(Hostel* ht);
//-----------------------------------------------------------------------------------------------//
#endif 