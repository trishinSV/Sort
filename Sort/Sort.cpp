//
//  Sort.cpp
//  Lab3_1_shaker
//
//  Created by Сергей on 18.05.16.
//  Copyright © 2016 Сергей. All rights reserved.
//

#include "Sort.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int k = 0;
Sort:: Sort(int count)
{
    n = count;
    a = new int[n];
    counter = 0;
}


int Sort:: quickSort()
{
    counter = 0;
    newArray();

    qsort(ptr, n, sizeof(int),compare);
      return counter;
}



int Sort:: BinaryInsertionSort()
{
    short x;
    short left;
    short right;
    short sred;
    int count = 0;
    for (short i = 1;  i < n; i++){
        count++;
        if (ptr[i-1] > ptr[i]){
            x = ptr[i];
            left = 0;
            right = i-1;
            do {
                 count++;
                sred = (left + right)/2;
                count++;
                if  (ptr[sred] < x ) left = sred + 1;
                else  right = sred - 1;
            } while (left <= right);
            for (short j = i-1; j>=left; j--)
                ptr[j+1] = ptr[j];
            ptr[left] = x;
        }
    }
    return count;
}


int Sort:: BubbleSort2 ()
{
    int i=1, j, x, k;	//i=1 - ÎÂ‚‡ˇ „‡ÌËˆ‡ Ò‡‚ÌË‚‡ÂÏ˚ı ˝ÎÂÏÂÌÚÓ‚
    int counter = 0;
    do
    {
        k = 0;	//ÔËÁÌ‡Í ÓÚÒÛÚÒÚ‚Ëˇ Ó·ÏÂÌÓ‚
        for (j=n-1; j>=i; j--)
            counter++;
            if (a[j-1]>a[j])
            {
                x = a[j-1];
                a[j-1] = a[j];
                a[j] = x;
                k = j;	//Á‡ÔÓÏËÌ‡ÂÏ ÏÂÒÚÓ ÔÓÒÎÂ‰ÌÂ„Ó Ó·ÏÂÌ‡
            }
        i = k;	//Á‡ÔÓÏËÌ‡ÂÏ ÏÂÒÚÓ ÔÓÒÎÂ‰ÌÂ„Ó Ó·ÏÂÌ‡ Í‡Í Ô‡‚Û˛ „‡ÌËˆÛ
    }
    while (k);
    return counter;
}

int Sort::downHeap(long k, long n)
{
    //  процедура просеивания следующего элемента
    //  До процедуры: ptr[k+1]...ptr[n]  - пирамида
    //  После:  ptr[k]...ptr[n]  - пирамида
    int new_elem, count = 0;
    long child;
    new_elem = ptr[k];
    
    while(k <= n/2) // пока у ptr[k] есть дети
    {
        child = 2*k;
                  //  count++;
        if( child < n && ptr[child] > ptr[child+1] ) //  выбираем большего сына
        {
            child++;

        }
                    count++;
        if( new_elem <= ptr[child] )
        {

            break;
        }
        // иначе
        ptr[k] = ptr[child];    // переносим сына наверх
        k = child;
    }
    ptr[k] = new_elem;
    return count;
}

int Sort:: HeapSort()
{
    newArray();
    long i;
    int temp, count = 0;
    
    // строим пирамиду
    for(i = n / 2 - 1; i >= 0; --i)
        count+=downHeap(i, n-1);
    
    // теперь ptr[0]...ptr[size-1] пирамида
    
    for(i=n-1; i > 0; --i)
    {
        // меняем первый с последним
        temp = ptr[i];
        ptr[i] = ptr[0];
        ptr[0] = temp;
        // восстанавливаем пирамидальность ptr[0]...ptr[i-1]
        count+=downHeap(0, i-1);
    }
    return count;
}

void Sort:: createArray(int l)
{
    switch (l) {
        case 0:
            srand( (unsigned int) time(0) );
            for(int i = 0;i<n;i++)
                a[i] = rand() % 5000;
            break;
        case 1:
       //     srand( (unsigned int) time(0) );
            for(int i = 0;i<n;i++)
                a[i] = i;//rand() % 100;
            break;
        case 2:
      //      srand( (unsigned int) time(0) );
            for(int i = 0;i<n;i++)
                a[i] = -i;//rand() % 100;
        default: 
            break;
    }

}
void Sort::newArray()
{
    ptr = new int [n]; // выделить место в памяти для массива
    
    for (int ix = 0; ix < n; ix++)
        ptr[ix] = a[ix]; // заполняем массив значениями массива arrayToCopy
}
void Sort:: printArray()
{
    for(int i = 0;i<n;++i)
        cout << a[i] << " ";
    cout << endl;
}
void Sort:: printSortedArray()
{
    for(int i = 0;i<n;++i)
        cout << ptr[i] << " ";
    cout << endl;
}

Sort:: ~Sort()
{
    //  delete[] a;
    delete[] ptr;
}
