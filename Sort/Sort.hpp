//
//  Sort.hpp
//  Lab3_1_shaker
//
//  Created by Сергей on 18.05.16.
//  Copyright © 2016 Сергей. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include <cstdlib>
static int counter = 0;
class Sort {
private:
    int *a, n;
    int *ptr;
public:
    Sort(int count);
    void newArray();
    ~Sort();
    
    int BinaryInsertionSort();
    int BubbleSort2();
    int quickSort();
    int HeapSort();
    int downHeap(long k, long n);
    void createArray(int l);
    void printArray();
    void printSortedArray();

    static int compare(const void * x1, const void * x2)
    {
        counter++;
        return  -(*(int*)x1 - *(int*)x2);
    }
};

#endif /* Sort_hpp */
