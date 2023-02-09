#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "main_f.h"

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
            return "WrongInput!";break;
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