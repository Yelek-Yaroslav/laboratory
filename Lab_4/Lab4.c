#include <stdio.h>
#include <locale.h>
#define SIZE 15

int linearSearch(int arr[], int size, int target) {
 for (int i = 0; i < size; i++) {
 if (arr[i] == target) {
 return i;
 }
 }
 return -1;
}

int binarySearch(int arr[], int size, int target) {
 int left = 0, right = size - 1;
 while (left <= right) {
 int mid = left + (right - left) / 2;
 if (arr[mid] == target)
 return mid;
 else if (arr[mid] < target)
 right = mid - 1;
 else
 left = mid + 1;
 }
 return -1;
}

void sortDescending(int arr[], int size) {
 for (int i = 0; i < size - 1; i++) {
 for (int j = 0; j < size - i - 1; j++) {
 if (arr[j] < arr[j + 1]) {
 int temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
}

int main() {
 setlocale(LC_ALL, "");
 int X[SIZE];
 int A;
 printf("Enter 15 array elements:\n");
 for (int i = 0; i < SIZE; i++) {
 scanf_s("%d", &X[i]);
 }

 printf("Enter value of A: ");
 scanf_s("%d", &A);
 int linearIndex = linearSearch(X, SIZE, A);
 if (linearIndex != -1)
 printf("Linear search: Element found at position %d\n", linearIndex);
 else
 printf("Linear search: Element not found\n");
 sortDescending(X, SIZE);
 printf("Sorted array: ");
 for (int i = 0; i < SIZE; i++) {
 printf("%d ", X[i]);
 }

 printf("\n");
 int binaryIndex = binarySearch(X, SIZE, A);
 if (binaryIndex != -1)
 printf("Binary search: Element found at position %d\n", binaryIndex);
 else
 printf("Binary search: Element not found\n");
 
 return 0;
}
