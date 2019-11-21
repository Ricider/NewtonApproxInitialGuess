#include <stdio.h>
#define BIGSQRT 20000
#define MEDSQRT 200
#define SMOLSQRT 2

#define ITER 10

float newtonApprox(float input, int iter, int magicNum){
	float guess=input/magicNum;
	for (int i=0;i<iter;i++){
		guess=(guess*0.5f)+(input/(2*guess));
	}
	return guess;
}

int main(){
	float bigNewton,medNewton,smolNewton,error;
	int mostPrecise=0x0;
	float lowestError=999999.0f;
	
	for (int i=0;i<0x00000ffff;i++){
		error=1;
		bigNewton=newtonApprox(400000000.0f,ITER,i);
		medNewton=newtonApprox(40000.0f,ITER,i);
		smolNewton=newtonApprox(4.0f,ITER,i);
		error*=(1-(bigNewton/BIGSQRT))*(1-(bigNewton/BIGSQRT))+1;
		error*=(1-(medNewton/MEDSQRT))*(1-(medNewton/MEDSQRT))+1;
		error*=(1-(smolNewton/SMOLSQRT))*(1-(smolNewton/SMOLSQRT))+1;
		if (error<lowestError){
			lowestError=error;
			mostPrecise=i;
		}
	}
	
	
	printf("%f %f %f\n",newtonApprox(400000000.0f,ITER,mostPrecise),
	newtonApprox(40000.0f,ITER,mostPrecise),newtonApprox(4.0f,ITER,mostPrecise));
	printf("%d has error percentage %f \n",mostPrecise, lowestError);
}
