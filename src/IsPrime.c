#include <stdio.h>
#include <math.h>


///if num is 2n or 3n, that's the easy case
///else we have to control the step
///5,7,(no 9),11,13,(no15),17,19,(no21),23,25,(no27),29,31...
///so the step is 2 in this loop and the next time it is 4
///the way to change 2 to 4 and change 4 to 2 automaticly
/// is that
///2 xor 4 == 6 so 2 xor 6 == 4 and 4 xor 6 == 2
int isPrime(int num){	
	if (num <= 0) return 0;
	if (num <= 3) return 1; 
	if (num % 2 == 0) return 0;
	if (num % 3 == 0) return 0;
	int sqrt_of_num = (int)(sqrt(num));
	int i;
	int step = 4;
	for (i = 5; i <= sqrt_of_num; i +=  step){
		if (num % i == 0) return 0;
		step ^= 6;
	}
	return 1;
}

int __main()
{
    int num;
    //scanf("%d",&num);
    for(num = 1;num <= 50; num++){
        if (isPrime(num)){
        	printf("%d is prime.\n",num);
        }else{
        	printf("%d is not a prime.\n",num);
        }
    }
    return 0;
}
