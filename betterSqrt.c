#include <stdio.h>

float squareRoot(float input){
	float copy=input;
	unsigned int* guess=(unsigned int*) &copy;
	unsigned char exponentArray=(*guess&0x3f800000)>>23;
	exponentArray=exponentArray>>1;
	(*guess)=(*guess)&(0xc07fffff);
	(*guess)=(*guess)|((exponentArray&0xff)<<23);
	for (int i=5;i>0;i--) copy=(copy*0.5f)+(input/(2*copy));
	return copy;
}

int main(){
	while (1){
		float input;
		scanf("%f",&input);
		printf("%f\n",squareRoot(input));
	}
}
