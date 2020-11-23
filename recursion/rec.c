#include "rec.h"
int len(int n){ // this returns the length of a number n in the decimal base
	if (n<10){
		return 1;
	}
	return (1+len(n/10));
}

int MaxPower(int n){ // This returns the maximum power of 10 that is smaller or equal to a number n
	if (n<10){
		return 1;
	}
	return (10*MaxPower(n/10));
}


//---------------------------1--------------------------
long ReverseNum(unsigned long n)
{
	if (n/10==0) //base case: reversnum will be the same number
	{
		return n;
	}
	unsigned long powa = MaxPower(n); // This is the maximum power of 10 that is smaller or equal to n
	return ((n%10)*(powa) + ReverseNum(n/10)); // this takes the last digit, and puts it in front of the reverse of the number without it. this reverses the number.
}

//---------------------------2--------------------------

int isSubsetSum(int a[], int size, int k)
{
	/******** DON'T CHANGE ********/
	fx2(); // do not change!!!
	/******************************/

	/*Write your code down here*/
	if (k==0){
		return 1; //base case:  if we reach a state where the sum is 0, it means that after subtracting enough numbers their sum was the original k
	}
	if (size==0) // base case: if we went through this tunnel of possibilities, and at the end, size =0, it means that this tunnel won't lead us anywhere
	{
		return 0;
	}
	if (k<0){ // base case: when we subtracted the last number it was bigger than the sum, so it means this tunnel of possibillities is not going to give us the original sum
		return 0;
	}
	return isSubsetSum(a, size-1, k - a[size-1]) || (isSubsetSum(a, size-1, k)); // this is a way to iterate over all the combinations of numbers - the first option is to use the number, the other one is to not use it. "using" the number k means we subtact it from the sum, to see if (sum-k) could be a sum of other numbers. if it is, then (sum -k) +k =sum.
}

//---------------------------3--------------------------
int lastN(int num, int n)
{
	/******** DON'T CHANGE ********/
	fx3(); // do not change!!!
	/******************************/

	/*Write your code down here*/
	if (n==0){ //base case
		return 0;
	}
	int leno = len(num); //this is the length of num
	int powa = MaxPower(num); // This is the maximum power of 10 that is smaller or equal to n
	if (n >leno){ // As stated in the prompt, if n is bigger than the length of the number, return -1
		return -1;
	}
	if (n==leno){ // after eliminating enough digits from the end, we reached a point where the length of our input is n. return the input
		return num;
	}
	if (len(num%powa) < n) {return num%powa;} // num%powa is the number without the last digit. if the next digit is 0, our next input's length might of been smaller than n, which would of returned us a -1. to avoid this, just return the next input, because it's length is smaller than n.
	return (lastN(num%powa,n));
}
//---------------------------4--------------------------
void ChangeFrame(int mat[][N], int rowCol, int size)
{

	/******** DON'T CHANGE ********/
	fx4(); // do not change!!!
	/******************************/
	if (size > rowCol + 1)
	{
		int i;
		for (i = rowCol;i < size;++i) { //replace in the diagonal index the horyzontal and diagonal lines
			mat[rowCol][i] = mat[rowCol][i] + mat[i][rowCol];
			mat[i][rowCol] = mat[rowCol][i] - mat[i][rowCol];
			mat[rowCol][i] = mat[rowCol][i] - mat[i][rowCol];
		}
		ChangeFrame(mat, rowCol + 1, size); //do for every diagonal index
	}
}


//---------------------------5--------------------------

int concatFirst(int num, int start)
{
	/******** DON'T CHANGE ********/
	fx5(); // do not change!!!
	/******************************/

	/*Write your code down here*/
	if (num==0){ //base case: after reducing the first input enough, this will be our answer
		return start;
	}
	return (concatFirst(num/10, start*10) - num/10 + num); // eliminate the first digit of num, and put start in front of it, with it's first digit being an extra 0. subtruct num without it's first digit. now we have start with m 0s after it where m is the length of num. add num to that, and we got start with num after it!
}
//---------------------------6--------------------------

int MergeNumbers(int n1, int n2)
{
	/******** DON'T CHANGE ********/
	fx6(); // do not change!!!
	/******************************/
	if (n1 == 0) //base cases
		return n2;
	if (n2 == 0)
		return n1;
	return 100 * MergeNumbers(n1 / 10, n2 / 10) + 10 * (n2 % 10) + n1 % 10; //delete the first two digits from the numbers, apply the function to them. now we just need to add the digits back. shift the last digits to be 00, and add the digits back in the right order,
}
//---------------------------7--------------------------


int Series(int n)
{
	/******** DON'T CHANGE ********/
	fx7(); // do not change!!!
	/******************************/

	/*Write your code down here*/
	if (n<4){ // for the first 3 numbers in the series we will return the numbers themselves.
		return n;
	}
	if (n%2==0){ // if the number is even we will return the sum of the previous 3 numbers.
		return (Series(n-1)+Series(n-2)+Series(n-3));
	}
	if (n%2==1){  //if the number is add we will add the absolute value of the two even place before it.
        if (Series(n-1)-Series(n-3) <0){ //to simulate an absolute value, we will create two cases, where if the difference is negative we will return it*-1
            return -1*(Series(n-1)-Series(n-3));
        }
        else{
            return Series(n-1)-Series(n-3);
        }

	}
}
//---------------------------8--------------------------

void FindCommonDigit(unsigned long n1, unsigned long n2, int arr[], int* sumCommon)
{
	/******** DON'T CHANGE ********/
	fx8(); // do not change!!!
	/******************************/
	if ((n1 != 0) && (n2 != 0))
	{
		if ((n1 < 10) && (n2 < 10))
		{
			if ((n1 == n2) && (n1 != arr[(*sumCommon) - 1]))
				arr[(*sumCommon)++] = n1;
		}
		else if (n1 % 10 == arr[(*sumCommon) - 1])
			FindCommonDigit(n1 / 10, n2, arr, sumCommon);
		else if (n2 % 10 == arr[(*sumCommon) - 1])
			FindCommonDigit(n1, n2 / 10, arr, sumCommon);
		else if (n1 % 10 == n2 % 10)
		{
			arr[(*sumCommon)++] = n1 % 10;
			FindCommonDigit(n1 / 10, n2 / 10, arr, sumCommon);
		}
		else if (n1 % 10 < n2 % 10)
			FindCommonDigit(n1, n2 / 10, arr, sumCommon);
		else
			FindCommonDigit(n1 / 10, n2, arr, sumCommon);
	}
}
