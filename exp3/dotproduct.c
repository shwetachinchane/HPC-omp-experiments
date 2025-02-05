#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void sequential(){
double arr1[10000],arr2[10000];
        double temp = 0;
        double start1 = omp_get_wtime();
    
        for(int i=0;i<10000;i++){
        arr1[i]= i +2.0;
        arr2[i] = i+4.0;
        }
        double end1 = omp_get_wtime();
        double start2 = omp_get_wtime();
        for(int i=0;i<10000;i++){
        double tempdot = arr1[i] * arr2[i];
        temp = temp + tempdot;
        }
        double end2 = omp_get_wtime();
        printf("Scaler sum %f\n",temp);
        printf("First For Loop Time1 %f\n",end1-start1);
        printf("Second For Loop Time2 %f\n",end2-start2);
        printf("Total Time for Sequential Execution %f\n",(end2-start2) + (end1-start1));
}
int main(){
	sequential();

	double arr1[10000],arr2[10000];
	double temp = 0;
	double start1 = omp_get_wtime();
	#pragma omp parallel for
	for(int i=0;i<10000;i++){
	arr1[i]= i +2.0;
	arr2[i] = i+4.0;
	}
	double end1 = omp_get_wtime();
	double start2 = omp_get_wtime();
	#pragma omp parallel for reduction(+:temp)
	for(int i=0;i<10000;i++){
	double tempdot = arr1[i] * arr2[i];
	temp = temp + tempdot;
	}
	double end2 = omp_get_wtime();
	printf("Scaler sum %f\n",temp);
	printf("First For Loop Time1 %f\n",end1-start1);
	printf("Second For Loop Time2 %f\n",end2-start2);
	printf("Total Time for parallel Execution %f\n",(end2-start2) + (end1-start1));
	return 0;
}