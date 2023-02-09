/*Description: Implementation of a program in C - to observe the time 
  performance of 3 sorting algorithms (InsertionSort, SelectionSort, QuickSort)
  Author: dcharistes */
  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "main_f.h"

int main() {
	int i, j, k, l, n=0;
    double sum[3], avg[3], sum_avg[3], avg_avg[3];
    clock_t start[3], end[3], start_p, end_p;
	time_t t;
    double cpu_time_used[3], cpu_time_used_p;
	item *a, *b;
	start_p= clock();
    
    srand(1024);

	for(j=0; j<3; j++)
		sum_avg[j]=0;
	for(k=0; k<10; k++){
        n+=10000;
	    a = (item *)malloc(n * sizeof(item));
        b = (item *)malloc(n * sizeof(item));
	    if (a == NULL) {
		    printf("Error while allocating memory!!!");
		    return -1;
	    }
		for(j=0; j<3; j++)
			sum[j]=0;
        for(i=0; i<10; i++){
	        for (j = 0; j < n; j++) {
		        a[j] = rand();
				b[j]=a[j];
			}

            for(l=0; l<3; l++){
                start[l]=clock();
                switch (l)
                {
                case 0: insertionsort(a,n);
                    break;
                case 1: selectionsort(a,n);
                    break;
                case 2: quicksort(a, 0, n-1);
                    break;
                default:
                    break;
                }
                end[l]=clock();
                cpu_time_used[l]= (double)(end[l]-start[l])/CLOCKS_PER_SEC;
				if(l==2) printf("time qsort: %.6f\n", cpu_time_used[2]);
                sum[l]+=cpu_time_used[l];
                for(j=0; j<n; j++)
                    a[j]=b[j];
            }
        }
        for(l=0; l<3; l++){
            avg[l]=(double)sum[l]/10;
			sum_avg[l]+=avg[l];
			Sleep(20);
            printf("%s - Dimension: %d - Average execution time: %lf\n", choice(l), n, avg[l]);
        }
        printf("\n");
		free(a);
		free(b);

    }
	Sleep(1500);
	printf("----------------\n");
	for(l=0; l<3; l++){
		Sleep(20);
		avg_avg[l]=(double)sum_avg[l]/10;
        printf("%s - Average execution time from all dimensions: %lf\n", choice(l), avg_avg[l]);
	}
	end_p=clock();
    cpu_time_used_p= (double)(end_p-start_p)/CLOCKS_PER_SEC;
	cpu_time_used_p=cpu_time_used_p-1.62;
	Sleep(500);
	printf("----------------\n");
	printf("Execution time of the program: %2f\n", cpu_time_used_p);

    
	system("PAUSE");
	return 0;

}
