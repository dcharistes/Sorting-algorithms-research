#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef int item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {item t = A; A = B; B = t;}
#define compexch(A, B) if (less(A, B)) exch(A, B)

const char* choice(int k);

void quicksort(item *a, int l, int r);

int partition(item *a, int l, int r);

void insertionsort(item *a, int n);

void selectionsort(item *a, int n);