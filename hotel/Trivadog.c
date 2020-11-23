#include "Trivadog.h"
#include "Hostel.h"
#include "Room.h"
#define MAX 100
#define MAXSTR "ZZ"
int inside(Trivadog* td, const Hostel* ht){ // checks if an hostel is inside of a room.
  int i;
  for (i=0;i<td->num_of_hostels;i++) //itirates over all indexes of hostels
      if (strcmp(td->hostels[i]->hostel_name, ht->hostel_name) ==0) // checks if hostel name equals to other hostels name
        return 1;
  return 0;
}

Trivadog* AddHostel(Trivadog* td, const Hostel* ht){
  if (!inside(td,ht)){
      if (!td){ // if trivadog pointer leads to NULL
          Trivadog* td = malloc(sizeof(Trivadog));// allocates memory for trivadog
          if (td ==NULL) { return NULL;}// on error returns NULL
          td->num_of_hostels=1; // makes the number of hostels in td 1
          td->hostels=malloc(sizeof(Hostel *));// allocates memory for hostel
          if (td->hostels == NULL) { free(td);return NULL; }// on error returns NULL, frees td
          td->hostels[0]=DuplicateHostel(ht); //gets new hostel with ht data
          if (td->hostels[0] == NULL) { free(td); free(td->hostels);return NULL; }// on error returns NULL, frees td
      }
      else{
          td->num_of_hostels++;
          td->hostels=realloc(td->hostels,td->num_of_hostels*sizeof(Hostel *));
          if (td->hostels ==NULL) { return NULL;} // on error returns NULL
          td->hostels[td->num_of_hostels-1]=DuplicateHostel(ht);
          if (td->hostels[td->num_of_hostels - 1] == NULL) {return NULL; } // on error returns NULL
      }
  }
  return td;
}
void SortByName(Trivadog* td){
   for (int i=0; i<td->num_of_hostels; i++){ // itirates over all indexes of hostels
       int min = i;
       for (int j=i+1; j<td->num_of_hostels; j++){ // itirates over all indexes of hostels after i
           if (strcmp(td->hostels[j]->hostel_name, td->hostels[min]->hostel_name) < 0){ // if finds a "smaller" hostel name
                min = j; //make the min index that index
            }
        }
        if (min!=i){ //swap order of hostels, the smallest one after i (if it's not i) and i.
            Hostel *temp = td->hostels[min];
            td->hostels[min] = td->hostels[i];
            td->hostels[i] = temp;
        }
   } // this way everything gets sorted because the minimum after an index is moved to that index, and the numbers order perfectly (strcmp works with ASCII)
}
int GetTotalAvailableRooms(Trivadog* td, const char* type){
    int j;
    int total =0; //total starts at 0
    for (j=0;j<td->num_of_hostels;j++) //itirates over all indexes of hotels.
        total+=GetAvailableRooms(td->hostels[j],type); // adds the amount of rooms in a hostel to total.
    return total;
}

void SortByRate(Trivadog* td){ // this is very similar to sortbyname but instead of strcmp we have subtractoin
   for (int i=0; i<td->num_of_hostels; i++){ // itirates over all indexes of hostels
       int min = i;
       for (int j=i+1; j<td->num_of_hostels; j++){ // itirates over all indexes of hostels after i
           if (td->hostels[j]->rate - td->hostels[min]->rate < 0){ // if finds a smaller hostel rate
                min = j;//make the min index that index
            }
        }
        if (min!=i){ //swap order of hostels, the smallest one after i (if it's not i) and i.
            Hostel *temp = td->hostels[min];
            td->hostels[min] = td->hostels[i];
            td->hostels[i] = temp;
        }
   }
}
int* GetTotalAvailableRoomsInArr(Trivadog* td, char** arr_type, int size){
    int i;
    int *arr=malloc(size*sizeof(int));
    if (arr == NULL) { return NULL; } // on error returns NULL
    for (i=0;i<size;i++) // for every element in arr_type
        arr[i]=GetTotalAvailableRooms(td,arr_type[i]); // add GetTotalAvailableRooms of that element and add it to arr
    return arr;
}
void FreeTrivadog(Trivadog* td){
  int i;
  for (i=0;i<(*td).num_of_hostels;i++) //itirates over all hostels
    FreeHostel(td->hostels[i]);  //frees hostel
  free(td); //frees rest of data
}
