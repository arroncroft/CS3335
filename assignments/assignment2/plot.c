#include <stdio.h>
#include <limits.h>
#include <math.h>

int f(int);

int main(void){
	int i, t, funval;
	
    //Make sure to change low and high when testing your program
	int low=-3, high=9;
	i = 0;
	int points[(high - low) + 1];
	for (t=low; t<=high;t++){
		printf("f(%2d)=%3d\n",t,f(t));
		points[i] = f(t);
		i++;
    }

	//find max and min of points to determine y markers
	int max = points[0]; 
	int min = points[0];
	for (i=0; i<sizeof(points)/sizeof(int); i++){
		if(points[i] > max)
			max = points[i];
		if(points[i] < min)
			min = points[i];
	}
	printf("*********\n");
	printf("min = %d\n",min);
	printf("max = %d\n",max);
	printf("*********\n");

	//print y markers and dashes
	int yMarker = min;
	int numDashes = 1;
	printf("%5d",yMarker);
	while(yMarker < max){
		yMarker = yMarker + 5;
		printf("%5d",yMarker);
		numDashes++;
	}
	printf("\n");
	for(i = 0; i < numDashes; i++){
		printf("%5s","|");
	}

	//print x markers and points
	printf("\n");
	i = low;
	while (i <=  high){
		printf("%-2s%2d%*s\n","t=",i,(f(i) - min)+1,"*");
		i++;
	}

	return 0;
}


int f(int t){
	//example 1
	return (t*t-4*t+5);
    
    	//example 2
    	//return (-t*t+4*t-1);
    
	//example 3
    	//return (sin(t)*10);
    
    	//example 4
	//if (t>0)
	//	return t*2;
	//else
	//	return t*8;
}
