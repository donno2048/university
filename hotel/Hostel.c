#include "Hostel.h"
#include "Room.h"
Hostel*	AddRoom(Hostel* ht, const  Room* room){
    if (!ht){ //if hostel did not exist yet
        ht =(Hostel *) malloc(sizeof(Hostel)); // allocates memory for hostel
        if (ht ==NULL) {return NULL;}  // on error returns NULL
        ht->rate=0; // puts rate in ht

        ht->hostel_name = (char *) malloc(strlen("Unknown Hostel") + 1);// allocate memory for name, the name being "Unknown Hostel";
        if (ht->hostel_name == NULL) { free(ht);return NULL; }  // on error returns NULL, frees ht
        strcpy(ht->hostel_name, "Unknown Hostel"); // copies name to ht
        ht->rooms=malloc(sizeof(Room *)); //allocates memory for one room.
        if (ht->rooms == NULL) { free(ht->hostel_name);free(ht); return NULL; }// on error returns NULL, frees name and ht
        ht->rooms[0] = DuplicateRoom(room); // duplicates room from parameters
        if (ht->rooms[0] == NULL){free(ht->rooms);free(ht->hostel_name);free(ht); return NULL;} // on error returns NULL, frees array of rooms name and ht
        ht->num_of_rooms=1; // makes room counter 1
    }
    else{
        int indicator = -1; //this indicator will be the room index of the room with the same number already in hostel, if it exists.
        for (int i=0; i < ht->num_of_rooms;i++){
          if (ht->rooms[i]->number == room->number){ //  there can't be two rooms with the same number in a hostel. checks if room numbers are equal.
            indicator = i; // if they are make our indicator that index
          }
        }
        if (indicator==-1){ // indicator stayes -1. room with that number was not found.
          ht->rooms = realloc(ht->rooms, (ht->num_of_rooms+1) * sizeof(Room *));  // reallocates memory for another room
          if (ht->rooms ==NULL) { return NULL;}  // on error returns NULL
          ht->num_of_rooms++; // add one more room to room amount.
          ht->rooms[ht->num_of_rooms-1]= DuplicateRoom(room);
          if (ht->rooms[ht->num_of_rooms - 1] == NULL) { return NULL; } // on error returns NULL
        }
        else{
          ht->rooms[indicator]->available = room->available; //changes values for elements in ht
          ht->rooms[indicator]->number = room->number;
          ht->rooms[indicator]->cost_for_night = room->cost_for_night;
          ht->rooms[indicator]->type = realloc(ht->rooms[indicator]->type, strlen(room->type) +1); //reallocates memory for string.
          if (ht->rooms[indicator]->type ==NULL) { return NULL;} // on error returns NULL
          strcpy(ht->rooms[indicator]->type,room->type); //copies name.

        }
    }
    return ht;
}
Hostel*	DuplicateHostel(const Hostel* source){
    Hostel *hostel=malloc(sizeof(Hostel));
    if (hostel ==NULL) {free(hostel); return NULL;} //if error return NULL
    hostel->rooms=malloc(source->num_of_rooms * sizeof(Room *)); //allocate memory for array of rooms
    if (hostel->rooms ==NULL) {free(hostel); return NULL;} //if error return NULL, free hostel
    int i;
    for (i=0;i<source->num_of_rooms;i++)
      hostel->rooms[i]=DuplicateRoom(source->rooms[i]);
    hostel->num_of_rooms=source->num_of_rooms; // get all other data:
    hostel->rate=source->rate;
    hostel->hostel_name=malloc(strlen(source->hostel_name)+1); // allocate memory for name
    if (hostel->hostel_name ==NULL) {free(hostel->rooms); free(hostel); return NULL;} //if error return NULL, free rooms array and hostel
    strcpy(hostel->hostel_name,source->hostel_name); //copy  name
    return hostel;

}
int GetAvailableRooms(const Hostel* ht, const char* type){
    int i;
    int total=0;
    for (i=0;i<ht->num_of_rooms;i++) // itirates over all rooms
        if (strcmp(ht->rooms[i]->type, type) == 0) //if there is a room with that type, return it.
            total++;
    return total;
}
void FreeHostel(Hostel* ht){
  int i;
  for (i=0;i<ht->num_of_rooms;i++) //itirates over every room
    FreeRoom(ht->rooms[i]);  //frees that room
  free(ht->hostel_name); // frees the hostel name
  free(ht); // free rest of the data
  return;
}
