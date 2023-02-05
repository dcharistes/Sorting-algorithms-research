#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef int item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { item t = A; A = B; B = t; }
#define compexch(A, B) if (less(A, B)) exch(A, B)

const char* choice(int k);

void quicksort(item *a, int l, int r);

int partition(item *a, int l, int r);

void insertionsort2(item *a, int n);

void insertionsort(item *a, int n);

void selectionsort(item *a, int n);

void display(item *a, int n);

int main() {
	int i, j, k, l, n=0;
    double sum[3], avg[3], sum_avg[3], avg_avg[3];
    clock_t start[3], end[3], start_p, end_p;
	time_t t;
    double cpu_time_used[3], cpu_time_used_p; //try an array [3] to save the execution time of each algorithm
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
				if(l==2) printf("time qsort: %2f\n", cpu_time_used[2]);
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

const char* choice(int k){
    switch (k)
    {
        case 0:
            return "InsertionSort"; break;
        case 1:
            return "SelectionSort"; break;
        case 2:
            return "QuickSort"; break;
        default:
            return "WrongInput";break;
    }
}

void quicksort(item a[], int l, int r) {
	int i;
	if (r <= l)
		return;
	i = partition(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}

int partition(item a[], int l, int r) {
	int i = l, j = r - 1;
	item v = a[r];
	while (1) {
		while (less(a[i], v)) i++;
		while (less(v, a[j])) {
			j--;
			if (j == l)
				break;
		}
		if (i >= j)
			break;
		exch(a[i], a[j]);
		i++;
		j--;
	}
	exch(a[i], a[r]);
	return i;
}

void insertionsort(item *a, int n) {
	int i, j;
	item temp;
	for (i = 1; i < n; i++) {
		compexch(a[i], a[0]);
	}
	for (i = 2; i < n; i++) {
		j = i;
		temp = a[i];
		while (less(temp, a[j - 1])) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}

void selectionsort(item *a, int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (less(a[j], a[min]))
				min = j;
		}
		exch(a[i], a[min]);
	}
}
