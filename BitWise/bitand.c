#include<stdio.h>

int bitAnd(int x,int y){
	return ~(~x | ~y);
}

int main(){
	int x,y;
	printf("Enter two numbers : \n");
	scanf("%d%d",&x,&y);
	int andBit=bitAnd(x,y);
	printf("Bit And : %d\n",andBit);
} 
