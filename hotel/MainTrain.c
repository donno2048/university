#include "Trivadog.h"
#pragma warning(disable:4996)
#include "Trivadog.h"
//-----------------------------------------------------------------------------------------------//
int compareRoomDifferentAddress(Room* a1, Room* a2)
{
	if (a1 == a2)
		return 0;

	if (a1->type == a2->type)
		return 0;

	if (strcmp(a1->type, a2->type) != 0)
		return 0;

	if (a1->number != a2->number)
		return 0;

	if (a1->cost_for_night != a2->cost_for_night)
		return 0;

	if (a1->available != a2->available)
		return 0;

	return 1;
}
//-----------------------------------------------------------------------------------------------//
int compareHostelDifferentAddress(Hostel* f1, Hostel* f2)
{
	int i;

	if (f1 == f2)
		return 0;

	if (f1->hostel_name == f2->hostel_name)
		return 0;

	if (strcmp(f1->hostel_name, f2->hostel_name) != 0)
		return 0;

	if (f1->rate != f2->rate)
		return 0;

	if (f1->num_of_rooms != f2->num_of_rooms)
		return 0;

	for (i = 0; i < f1->num_of_rooms; ++i)
	{
		if (0 == compareRoomDifferentAddress(f1->rooms[i], f2->rooms[i]))
			return 0;
	}

	return 1;
}
//-----------------------------------------------------------------------------------------------//
int compareTrivadogDifferentAddress(Trivadog* b1, Trivadog* b2)
{
	int i;

	if (b1 == b2)
		return 0;

	if (b1->num_of_hostels != b2->num_of_hostels)
		return 0;

	for (i = 0; i < b1->num_of_hostels; ++i)
	{
		if (0 == compareHostelDifferentAddress(b1->hostels[i], b2->hostels[i]))
			return 0;
	}

	return 1;
}
//-----------------------------------------------------------------------------------------------//
int checkRoom(Hostel* f, Room* a)
{
	int i;
	if (NULL == f || NULL == a)
		return 0;

	for (i = 0; i < f->num_of_rooms; ++i)
	{
		if (0 == strcmp(f->rooms[i]->type, a->type)
			&& f->rooms[i]->number == a->number
			&& f->rooms[i]->available == a->available
			&& f->rooms[i]->cost_for_night == a->cost_for_night)
			return 1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------//
int checkHostel(Trivadog* b, Hostel* f)
{
	int i, j, check;
	if (NULL == b || NULL == f)
		return 0;

	for (i = 0; i < b->num_of_hostels; ++i)
	{
		if (0 == strcmp(b->hostels[i]->hostel_name, f->hostel_name) && b->hostels[i]->rate == f->rate && b->hostels[i]->num_of_rooms == f->num_of_rooms)
		{
			check = 0;
			for (j = 0; j < f->num_of_rooms; ++j)
			{
				if (compareRoomDifferentAddress(b->hostels[i]->rooms[j], f->rooms[j]))
					++check;
			}

			if (check == f->num_of_rooms)
				return 1;
		}
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------//
int checkSortedByStringsArray(Trivadog* f, char* names[])
{
	int i;
	for (i = 0; i < f->num_of_hostels; ++i)
	{
		if (0 != strcmp(f->hostels[i]->hostel_name ,names[i]))
			return 0;
	}

	return 1;
}
//-----------------------------------------------------------------------------------------------//
int main()
{
	int sum = 0;
	char* types[2] = { "Deluxe","Simple"};
	char* arr1[4] = { "Sheradog"};
	char* arr2[4] = { "Sheradog"};
	Room room1 = { 304, 100.f, 1 , "Deluxe" };
	Room room2 = { 500, 150.5f, 1, "Simple" };
	Room room3 = { 204, 65.5f, 1, "Simple" };
	Room room4 = { 305, 140.f, 1, "Simple" };
	Room* pItem[3] = { &room1, &room2, &room3 };
	Room* pItem2[4] = { &room1, &room2, &room3, &room4 };
	Room* pItem3[2] = { &room3, &room4 };
	Hostel h1 = { pItem, 3, 9.4f, "DogPenthouse" };
	Hostel h2 = { pItem2, 4, 8.9f, "Sheradog" };
	Hostel h3 = { pItem3, 2, 9.5f, "Hiltdog" };
	Hostel h4 = { pItem, 3, 5.6f, "ClubCat" };
	Hostel h5 = { pItem2, 4, 7.4f, "GoldenDog" };
	Hostel h6 = { pItem2, 4, 7.3f, "NewHostel" };
	Hostel* tmpHostel = NULL;
	Hostel* myHostel;
	Room* p1;
	Room* p2;
	Trivadog* b1 = (Trivadog*)calloc(1,sizeof(Trivadog));
	//------------------------------------------------------------------------------------------------------------
	//=============== EX 1 ================// 
	p1 = CreateNewRoom(305, 140.f, 1, "Simple");
	if (0 == compareRoomDifferentAddress(p1, &room4))
		printf("Failed Ex1 - CreateNewRoom function (-8)\n");

	//=============== EX 2 ================// 
	p2 = DuplicateRoom(&room2);
	if (0 == compareRoomDifferentAddress(p2, &room2))
		printf("Failed Ex2 - DuplicateRoom function (-8)\n");

	//=============== EX 3 ================// 
	tmpHostel = AddRoom(tmpHostel, &room1);
	if (0 == checkRoom(tmpHostel, &room1))
		printf("Failed Ex3 - AddRoom function (-8)\n");

	//=============== EX 4 ================// 
	myHostel = DuplicateHostel(&h1);
	if (0 == compareHostelDifferentAddress(&h1, myHostel))
		printf("Failed Ex4 - DuplicateHostel function (-8)\n");

	//=============== EX 5 ================// 

	b1 = AddHostel(b1, &h2);
	if (0 == checkHostel(b1, &h2))
		printf("Failed Ex5 - AddHostel function (-8)\n");
	if(b1->num_of_hostels != 1)
		printf("Failed Ex5 - AddHostel function (-8)\n");

	//=============== EX 6 ================// 
	SortByName(b1);
	if (0 == checkSortedByStringsArray(b1, arr1))
		printf("Failed Ex6 - SortByName function (-8)\n");

	//=============== EX 7 ================// 
	SortByRate(b1);
	if (0 == checkSortedByStringsArray(b1, arr2))
		printf("Failed Ex7 - SortByNumber function (-8)\n");

	//=============== EX 8 ================// 
	if (1 != GetAvailableRooms(&h2, "Deluxe"))
		printf("Failed Ex8 - GetAvailableRooms function (-8)\n");

	//=============== EX 9 ===============//
	if (1 != GetTotalAvailableRooms(b1, "Deluxe"))
		printf("Failed Ex9 - GetTotalAvailableRooms function (-8)\n");
	
	//=============== EX 10 ===============//
	int* arr_types = GetTotalAvailableRoomsInArr(b1, types,2);
	if (1 != arr_types[0])
		printf("Failed Ex10 - GetTotalAvailableRoomsInArr function (-8)\n");
	if (3 != arr_types[1])
		printf("Failed Ex10 - GetTotalAvailableRoomsInArr function (-8)\n");
	//=============== EX 11 ===============// 
	FreeRoom(p1);
	FreeRoom(p2);

	//=============== EX 12 ===============// 
	FreeHostel(tmpHostel);
	FreeHostel(myHostel);

	//=============== EX 13 ===============// 
	FreeTrivadog(b1);

	//=============== FINISH ================// 
	printf("\n\ndone\n");

	return 0;
}
//-----------------------------------------------------------------------------------------------//