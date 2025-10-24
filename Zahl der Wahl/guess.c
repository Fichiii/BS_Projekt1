#include "guessing.h"

unsigned int guess_the_number(void)
{
	unsigned int left = 10000;
	unsigned int right = 99999;
	while(left <= right)
	{
		int mid = (left + right)/2;
		int check = evaluate(mid);

		if(check == 0) { return mid; }

		if(check == 1) { left = mid + 1; }

		if(check == -1) { right = mid - 1; }
	}

	return 1; 
}
