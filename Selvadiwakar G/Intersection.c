#include <stdio.h>


 void printIntersection(int arr1[], int arr2[], int m, int n) {

int i= 0, j = 0;

while (i < m && j < n) {

if (arr1[i] < arr2[j]) {

i++; 

} else if (arr2[j] < arr1[i]) {

j++;



} else { 

printf("%d", arr2[j]);

i++;

j++;

}

printf("\n"); 

}

}


- int main() {

int arr1[] = {1, 3, 4, 5, 6};

int arr2[] = {2, 3, 5, 7};

int m = sizeof(arr1) / sizeof(arr1[0]);

int n = sizeof(arr2) / sizeof(arr2[0]);

printf("Intersection of the two arrays: ");

printIntersection(arr1, arr2, m, n);

return 0;

}
