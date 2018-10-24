/**
 * @author Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #6 lab06 The Array ADT With Sorting and Searching functions
 * Description: a header file, IntegerArray.h, in which an IntegerArray class is declared. To take advantages of the abstraction, the implementations of the function members of the class should not been consisted in his file
 * NOTE0: A mini tester was added to my IntegerArray.cpp file since this was at the last moment. Since I was using free functions I definintely had to rethink my whole plan and sadly I didn't have the time for, again, LAST TIME decisions.
 * NOTE1: A decision of free functions for sorting and searching function was made in terms of allow the client the usage of this functions outside the Class if needed/applicable
 * @version Copyright © 2017-11-02 All rights reserved. Langara College
 */
// #include <iostream> is NOT included otherwise it wont find the header file in there
#ifndef IntegerArray_h
#define IntegerArray_h

class IntegerArray {

public:
    
    // Constructs a no-arg default Array
    IntegerArray();
    
    /**
     Construct an Integer Array object with a list of integer values in it
     @param capacity the actual size of the array as an Integer value
     */
    IntegerArray(unsigned int capacity);
    
    // Destructor
    ~IntegerArray();
    
    /**
     Returns an element stored at a specific index of the array
     @param index the index value of the array in which there is an element we want to return
     @return an specific indexed int element of the array
     */
    int getElementAt(int index);
    
    /**
     Assigns an element to a specific location in the array identified by an index
     @param value the integer value to set in the array
     @param index the integer index number
     */
    void setElementAt(int value, int index);
    
    // NON MEMBER FUNCTIONS
    
    /**
     Sorts an array of an specific capacity using ascending Bubble sort
     @param aList the array you want sorted
     @param size the actual capacity of the array
     */
    void bubbleSort(int aList[], int size);
    
    /**
     Sorts an array of an specific capacity using descending Bubble sort
     @param aList the array you want sorted
     @param size the actual capacity of the array
     */
    void descendingBubbleSort(int aList[], int size);
    
    /**
     Sorts an array of an specific capacity using minimum index finder sort
     @param aList the array you want sorted
     @param size the actual capacity of the array
     */
    void minIndexSort(int aList[], int size);
    
    /**
     Search an array of an specific key using linear Search
     @param aList the array you want sorted
     @param size the actual capacity of the array
     @param key the key we're looking for
     @return key when found
     @return -1 if not found
     */
    int linearSearch(int aList[], int size, int key);
    
    /**
     Search an array of an specific key using binary Search
     @param aList the array you want sorted
     @param size the actual capacity of the array
     @param key the key we're looking for
     @return -1 if not found
     */
    int binarySearch(const int aList[], int size, int key);
    
    /**
     Prints an array of an specific capacity
     @param aList the array you want sorted
     @param size the actual capacity of the array
     */
    void arrayPrinter(int aList[], int size);
    
private:
    
    // a pointer, an address to allocate the array
    int* pList;
    unsigned int capacity;
};

#endif /* IntegerArray_h */

/* QUESTION 2
 
 BUBBLE SORT
 functions are categorized as O(n2), which makes them inefficient for larger data sorting. Considering the n our size (the actual size of the Array in the input) and the main operation comparing and then swapping the operations can be summarized as following:
 Best case scenario O(n) Happens if the array is already sorted, that means no swap hence only 1 iteration for the n elements
 Worst case scenario O(n^2) This will occur if the array is sorted in descending order. The first iteration would have to look through n elements, next it would have to look n - 1 elements (biggest element is the last), and so on repeating the pattern.
 Big-O = n + n - 1 + n - 2 ... + 1 = (n*(n + 1))/2 = O(n^2)
 
 SELECTION SORT
 Functions independant ascending or descending are categorized as O(n2), which also makes them quite inefficient for larger volumes of data. this applies for all cases since they traverse data. The outer loops first iteration set has n comparisons (where n is the data size) the second iteration set would have n - 1 comparisons followed by n - 2, n - 3 ... hence O(n2) time complexity.
 
 LINEAR SEARCH
 Despite being not the best approach for searching still has some level of efficiency:
 Best case scenario O(1) happens if the key is the first element in the list, giving a constant time complexity.
 Average case scenario O(n) happens by insinuating that the average element would be somewhere in the middle of the list or n/2 (being n the size of the array), since we are dividing by a constant factor.
 Worst case scenario O(n) happens when the key is not present the list at all. This would force the algorithm to traverse the entire list and return nothing
 
 BINARY SEARCH
 For starters lets analyse the following context: the numbers of comparisons for the recursive and iterative versions are actually the same. For Recursive Binary Search, count each pass through the if-then-else block as one comparison. For Iterative Binary Search, count each pass through the while block as one comparison. Now lets see the cases:
 Best case scenario O(1) this happens when the key is the middle in the array. A constant number of comparisions (actually just 1) are required.
 Average case scenario O (log n) to find this situation we must consider the sum over all elements of the product of the number of comparsions needed to find each element and the probability of searching for that particular element. To simplify the analysis, assume we won't be searching for a not present element in the array and that the probabilities of searching for each element are uniform.
 Worst case scenario O (log n) in here the key doesn't exist in the array at all. Through each recursion or iteration of Binary Search, the size of the admissible range is reduced in half. This halving can be achieved by ceiling(log n) times. Thus, ceiling(log n) comparisons are mandatory.
 
 In conclusion the difference between O(log(N)) and O(N) is extremely significant when N (the volume of data) is huge: hence for any practical problem it is crucial that we avoid O(N) searches. E.g.: suppose your data contains 2 billion (2 * 10**9) values! the Linear search would involve about a billion comparisons; instead binary search would require only 32 comparisons!
*/
