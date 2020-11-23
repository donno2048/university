#include "Room.h"
Room* CreateNewRoom(int _number, float _cost, int _available, const char* _type){
    Room *room=(Room *)malloc(sizeof(Room)); // allocates memory for the room
    if (room ==NULL) {return NULL;}  // on error returns NULL
    room->number=_number; // puts all data from the paramaters of the function:
    room->cost_for_night=_cost;
    room->available=_available;
    room->type=(char *)malloc(strlen(_type)+1); // allocates memory for the room type
    if (room->type ==NULL) {free(room); return NULL;} // on error returns NULL and frees memory off room
    strcpy(room->type,_type);
    return room;
}
Room* DuplicateRoom(const Room* source){
    return CreateNewRoom(source->number, source->cost_for_night,source->available,  source->type); // returns the pointer to a room created with CreateNewRoom, that has the same data as source

}
void FreeRoom(Room* rm){
    free(rm->type);//frees type first
    free(rm); // then free all other memory from that room
}
