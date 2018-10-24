//
//  IntegerArrayTester.cpp
//  Lab04 The Array ADT
//
//  Created by Tom Nuss on 2017-11-02.
//  Copyright © 2017 Tomas Gonzalez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "IntegerArray.h"
using namespace std;

/*
 Brief tester for some of the methods
 */
int main() {
    int myArray[10] = {2,5,8,4,1,2,10,2,0,1};
    IntegerArray::bubbleSort();
    arrayPrinter(myArray, 10);
    descendingBubbleSort(myArray, 10);
    arrayPrinter(myArray, 10);
    linearSearch(myArray, 10, 2);
    binarySearch(myArray, 10, 2);
    system("pause");
    return 0;
}
