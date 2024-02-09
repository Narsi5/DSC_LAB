#include<stdio.h>

void toh(int n,char source,char spare,char destination);
static int step =0;
int main(){
	int n;
	printf("enter the no of rings");
	scanf("%d",&n);
	toh(n,'A','B','C');
	return 0;
}


void toh(int n,char A,char B ,char C){
	if(n==1)
		printf("\n Step %d: Move %d from %c to %c",++step,n,A,C);
	else{
		toh(n-1,A,C,B);
		toh(1,A,B,C);
		toh(n-1,B,A,C);
	}
}
