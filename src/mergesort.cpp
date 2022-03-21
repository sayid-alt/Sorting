#include <iostream>
using namespace std;

void printArray(int arr[], int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	} cout << endl;
}

void merge(int arr[], int low, int middle, int high){
	int i, j, k;
	int n1 = middle - low + 1; // size of left array side
	int n2 = high - middle; // size of right array side

	int L[n1], R[n2]; // declare the left and right array

	for (i = 0; i < n1; i++)
		L[i] = arr[low + i]; // copy left side array to the new declare array(L1)
	
	for (j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j]; // copy right side array to the new declare array(R2)

	i = 0; j = 0; k = low; // redeclaring i,j, k

	while(i < n1 && j < n2){
		// compare if the sequenze of element's L is less than R
		if (L[i] <= R[j]){ 
			arr[k] = L[i]; // 
			i++;
		} else{
			arr[k] = R[j]; 
			j++;
		} 
		k++;
	}

	while (i < n1){
		arr[k] = L[i]; 
		i++; k++;
	}

	while (j < n2){
		arr[k] = R[j]; 
		j++; k++;
	}
}

void mergesort(int arr[], int low, int high){
	if (low < high){
		int middle = (low + high) /2;
		mergesort(arr, low, middle); // left side of the array after divided into two parts
		mergesort(arr, middle+1, high); // right side of the array after divided into two parts
		merge(arr, low, middle, high); // merging between two parts and sorting
	}
}

int main(){
	int arr[] = {5,4,2,7,8,1,3,2,7,9};
	int sizeOfArr = sizeof(arr)/sizeof(arr[0]);

	// print array before sorting
	printArray(arr, sizeOfArr);
	//printArray after sorting
	mergesort(arr, 0, sizeOfArr);
	printArray(arr, sizeOfArr);

	return 0;
}