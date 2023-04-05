// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void Print(int array[], int size);
void MergeSort(int array[], int size);
void Merge(int array[], int size, int leftArr[], int leftSize, int rightArr[], int rightSize);

int main()
{
    const int size = 8;
    int myArray[8] = { 2,4,1,6,8,5,3,7 };

    Print(myArray, size);

    MergeSort(myArray,size);

    Print(myArray, size);

    return 0;
}

void Print(int array[], int size) {
    for (int i = 0; i < size;i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void MergeSort(int array[], int size) {

    if (size == 1) { //if reached bottom... return...
        return;
    }


    int middle = size / 2; //find middle index

    int* leftArr = new int[middle]; 
    int* rightArr = new int[size - middle];

    //load values into leftArray and rightArray
    for (int i = 0; i < middle;i++) {
        leftArr[i] = array[i];
    }
    for (int j = middle; j < size; j++) {
        rightArr[j - middle] = array[j];
    }

    
    //pass left and right arrays from original array by index middle
    MergeSort(leftArr,middle);
    MergeSort(rightArr, size - middle);

    //when all split into size 1...Start Merge back together
    Merge(array, size, leftArr, middle, rightArr, (size - middle)); // middle to create arrays left and right...


}

void Merge(int array[], int size, int leftArr[],int leftSize, int rightArr[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] < rightArr[j]) {
            array[k] = leftArr[i];
            i++;//increment left array index
        }
        else {
            array[k] = rightArr[j];
            j++; //increment right array index
        }
        k++; //always increment original array
    }

    //for when left or right array is "emptied" first...
    while (i < leftSize) {
        array[k] = leftArr[i];
        i++; k++;
    }
    while (j < rightSize) {
        array[k] = rightArr[j];
        j++; k++;
    }

}


