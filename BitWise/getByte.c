#include<stdio.h>
int getByte(int x,int y){
    return (x>>(y<<3)) & 0b11111111;
}
int main(){
	printf("%d",getByte(0x12345678,1)==0x56);
}

