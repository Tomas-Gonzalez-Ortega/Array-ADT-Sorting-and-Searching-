/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #6 lab06 The Array ADT With Sorting and Searching functions
 * Description: implements all the function members of the IntegerArray header class
 * NOTE: A decision of free functions for sorting and searching function was made in terms of allow the client the usage of this functions outside the Class if needed/applicable
 * @version Copyright © 2017-11-02 All rights reserved. Langara College
 */

// ABSTRACION - Implementation hidden for the public
#include <iostream>
#include "IntegerArray.h"
using namespace std;

// Constructs a no-arg default Array
IntegerArray::IntegerArray() {
    capacity = 10;
    pList = new int[capacity];
}

/**
 Construct an Integer Array object with a list of integer values in it
 @param capacity an integer size of the array
 */
IntegerArray::IntegerArray(unsigned int capacity) {
    this->capacity = capacity;
    pList = new int[capacity];
}

// Destructs the IntegerArray object Array
IntegerArray::~IntegerArray() {
    delete []pList; // flush the allocated memory
}

/**
 Returns an element stored at a specific index of the array
 @param index the index value of the array in which there is an element we want to return
 @return an specific indexed int element of the array
 */
int IntegerArray::getElementAt(int index) {
    return pList[index];
}

/**
 Assigns an element to a specific location in the array identified by an index
 */
void IntegerArray::setElementAt(int value,int index) {
    pList[index] = value;
}

/**
 Bubblesorts an Array of an specific capacity
 @param aList the array you want sorted
 @param size the actual capacity of the array
 */
void bubbleSort(int aList[], int size) {
    bool swapped = true;
    int j = 0;
    int temp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < size - j; i++) {
            if (aList[i] > aList[i + 1]) {
                temp = aList[i];
                aList[i] = aList[i + 1];
                aList[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

/**
 Sorts an array of an specific capacity using descending Bubble sorting
 @param aList the array you want sorted
 @param size the actual capacity of the array
 */
void descendingBubbleSort(int aList[], int size) {
    bool swapped = true;
    int j = 0;
    int temp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < size - j; i++) {
            if (aList[i] < aList[i + 1]) {
                temp = aList[i];
                aList[i] = aList[i + 1];
                aList[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

/**
 Sorts an array of an specific capacity using minimum index finder sort
 @param aList the array you want sorted
 @param size the actual capacity of the array
 */
void minIndexSort(int aList[], int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i; //set the minimum index to actual index
        for (int j = i + 1; j < size; j++) {
            if (aList[j] < aList[minIndex])
                minIndex = j; // keeping track of the minimum index
        } // after comparing and not finding any smaller index
        if (minIndex != i) {
            temp = aList[i]; // we store in a temporal array
            aList[i] = aList[minIndex]; // then swap
            aList[minIndex] = temp; // and finally set the values to its original array
        }
    }
}

/**
 Search an array of an specific key using linear Search
 @param aList the array you want sorted
 @param size the actual capacity of the array
 @param key the key we're looking for
 @return key when found
 @return -1 if not found
 */
int linearSearch(int aList[], int size, int key) {
    int i;
    for (i = 0; i < size; i++)
        if (aList[i] == key)
            cout << "key " << key << " found at index " << i << endl;
        return key;
    return -1;
}

/**
 Search an array of an specific key using binary Search
 @param aList the array you want sorted
 @param size the actual capacity of the array
 @param key the key we're looking for
 @return -1 if not found
 */
int binarySearch(const int aList[], int size, int key) {
    int min = 0;
    int max = size - 1;
    int mid = (min + max) / 2;
    while (max >= min) {
        if (key < aList[mid])
            max = mid - 1;
        else if (key == aList[mid])
            return mid;
        else
            min = mid + 1;
    }
    return -1;
}

/**
 Prints an array of an specific capacity
 @param aList the array you want sorted
 @param size the actual capacity of the array
 */
void arrayPrinter(int aList[], int size) {
    for (int i = 0; i < size; i++)
        cout << aList[i];
    cout << endl;
}

/*
 Brief tester for some of the methods
 */
int main() {
    int myArray[10] = {2,5,8,4,1,2,10,2,0,1};
    bubbleSort(myArray, 10);
    arrayPrinter(myArray, 10);
    descendingBubbleSort(myArray, 10);
    arrayPrinter(myArray, 10);
    linearSearch(myArray, 10, 2);
    binarySearch(myArray, 10, 2);
    system("pause");
    return 0;
}
