#include<stdio.h>
#include<stdlib.h>
#include "assignment_2.h"
void main()
{
	int *numbers = malloc(sizeof(int) * 20);
	numbers[0] =24938;
	numbers[1] =37145;
	numbers[2] =33202;
	numbers[3] =11948;
	numbers[4] =56463 ;
	numbers[5] =11085; 
	numbers[6] =76168 ;
	numbers[7] =2133 ;
	numbers[8] =33227 ;
	numbers[9] =49053 ;
	numbers[10] =22368 ;
	numbers[11] =10794 ;
	numbers[12] =4969 ;
	numbers[13] =13269 ;
	numbers[14] =10653 ;
	numbers[15] =12363 ;
	numbers[16] =66010 ;
	numbers[17] =5047 ;
	numbers[18] =43304 ;
	numbers[19] =48515;
	find_second_greatest(numbers,20);
}
