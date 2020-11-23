
#include "rec.h"

int count2 = 0; // do not change!
int count3 = 0; // do not change!
int count4 = 0; // do not change!
int count5 = 0; // do not change!
int count6 = 0; // do not change!
int count7 = 0; // do not change! 
int count8 = 0; // do not change!
int EqualArr(int arr1[], int arr2[], int size)
{
	for (int i = 0;i < size;i++)
		if (arr1[i] != arr2[i])
			return 0;
	return 1;
}

void fx2() {
	count2++;
}
void fx3() {
	count3++;
}
void fx4() {
	count4++;
}
void fx5() {
	count5++;
}
void fx6() {
	count6++;
}
void fx7() {
	count7++;
}
void fx8() {
	count8++;
}



int main()
{
	int mat3[N][N] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},
		{16,17,18,19,20},{21,22,23,24,25} };
	int arr[9] = { 0 };
	int sumcommon = 0;
	int arr1[1] = { 3 };
	int arr2[5] = { 5,4,3,2,1 };
	int arr3[5] = { 5,-1,3,12,1 };

	//1
	if (ReverseNum(1003000604) != 4060003001)
		printf("ReverseNum function is wrong for train (-4)\n");
	if (ReverseNum(111222333) != 333222111)
		printf("ReverseNum function is wrong for train (-4)\n");
	if (ReverseNum(123432100) != 1234321)
		printf("ReverseNum function is wrong for train (-4)\n");



	//2
	int a[] = { 1,4,6,8 };
	int b[] = { 1,2,-3,4,5 };
	int c[] = { -5,-4, 1, 2,3 };
	isSubsetSum(a, 4, 16);
	if (count2 < 2)
		printf("isSubsetSum function is not recursive (-12)\n");
	else
	{
		if (isSubsetSum(a, 4, 15) != 1)
			printf("isSubsetSum function is wrong  (-4)\n");
		if (isSubsetSum(b, 5, 9) != 1)
			printf("isSubsetSum function is wrong  (-4)\n");
		if (isSubsetSum(c, 5, 7) != 0)
			printf("isSubsetSum function is wrong  (-4)\n");
	}


	// 3 

	lastN(45336764, 5);
	if (count3 < 4)
		printf("lastN function is not recursive (-12)\n");
	else {
		if (lastN(45336764, 3) != 764)
			printf("lastN function is wrong for train(-4)\n");
		if (lastN(345, 4) != -1)
			printf("lastN function is wrong for train(-4)\n");
		if (lastN(123, 3) != 123)
			printf("lastN function is wrong for train (-4)\n");

	}

	//4
	ChangeFrame(mat3, 0, 4);
	if (count4 < 4)
		printf("ChangeFrame function is not recursive (-12)\n");
	else {
		if (mat3[2][1] != 8)
			printf("ChangeFrame function is wrong for train (-4)\n");
		if (mat3[1][3] != 17)
			printf("ChangeFrame function is wrong for train (-4)\n");
		if (mat3[3][4] != 20)
			printf("ChangeFrame function is wrong for train (-4)\n");

	}
	// 5
	concatFirst(45, 123);

	if (count5 < 2)
		printf("concatFirst  function is not recursive (-12)\n");
	else {
		if (concatFirst(45, 123) != 12345)
			printf("concatFirst  function is wrong for train (-4)\n");
		if (concatFirst(21, 12) != 1221)
			printf("concatFirst  function is wrong for train (-4)\n");
		if (concatFirst(12345, 6) != 612345)
			printf("concatFirst  function is wrong for train (-4)\n");
	}
	//6
	MergeNumbers(45, 123);
	if (count6 < 2)
		printf("merge function is not recursive (-12)\n");
	else {
		if (MergeNumbers(45, 123) != 12435)
			printf("merge function is wrong for train (-4)\n");
		if (MergeNumbers(10001, 1001) != 110000011)
			printf("merge function is wrong for train (-4)\n");
		if (MergeNumbers(12345, 67) != 1236475)
			printf("merge function is wrong for train (-4)\n");
	}

	//7
	Series(8);

	if (count7 < 7)
		printf(" Series function is not recursive (-12)\n");
	else {
		if (Series(4) != 6)
			printf("Series function is wrong for train(-3)\n");
		if (Series(5) != 4)
			printf("Series function is wrong for train (-3)\n");
		if (Series(2) != 2)
			printf("Series function is wrong for train (-3)\n");
		if (Series(12) != 71)
			printf("Series function is wrong for train (-3)\n");
	}
	//8

	sumcommon = 0;
	FindCommonDigit(1234, 2567, arr, &sumcommon);
	if (count8 < 7)
		printf(" FindCommonDigit function is not recursive (-16)\n");
	else
	{
		sumcommon = 0;
		FindCommonDigit(113355799, 222446688, arr, &sumcommon);
		if (sumcommon != 0)
			printf("FindCommonDigit function is wrong for train(-5)\n");
		sumcommon = 0;
		FindCommonDigit(111355777, 2234466899, arr, &sumcommon);
		if (sumcommon != 1)
			printf("FindCommonDigit function is wrong for train (-5)\n");
		else if (!EqualArr(arr, arr1, sumcommon))
			printf("FindCommonDigit function is wrong for train (-5)\n");
		sumcommon = 0;
		FindCommonDigit(112233445, 112233445, arr, &sumcommon);
		if (sumcommon != 5)
			printf("FindCommonDigit function is wrong for train(-5)\n");
		else if (!EqualArr(arr, arr2, sumcommon))
			printf("FindCommonDigit function is wrong for train (-5)\n");
	}
	printf("done");
	return 0;
}


