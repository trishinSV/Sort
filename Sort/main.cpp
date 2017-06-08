//
//  main.cpp
//  Lab3_1_shaker
//
//  Created by Сергей on 08.05.16.
//  Copyright © 2016 Сергей. All rights reserved.
//

#include <iostream>
#include "Sort.hpp"

using namespace std;

int start;
int num[4] = {500,1000,3000,5000};

int main() {

    system("clear");

    for (int k = 0; k<4; k++) {
        start = num[k];
        
    Sort check(start);
        cout << start<<endl;
        
    for (int i =0; i<3; i++)
        {
        check.createArray(i);
            // check.printArray();
        switch (i) {
            case 0:
                cout << "\nНеупорядоченный массив\n";
                break;
            case 1:
                cout << "\nУпорядоченный в обратном порядке массив\n";
                break;
            case 2:
                cout << "\nУпорядоченный массив\n"; 
            default:
                break;
        }
               cout<<"Бинарными вставками сортировка:\t\t\t"<<check.BinaryInsertionSort()<<endl;// nlogn сравнений n^2 общая
            cout<<"Пузырьковая с фисацией сортировка:\t\t\t"<<check.BubbleSort2()<<endl;// nlogn сравнений n^2 общая
                      cout<<"Пирамидальная сортировка:\t\t\t\t\t"<< check.HeapSort()<<endl; //nlogn
                   cout<<"Быстрая сортировка qsort(): \t\t\t\t"<< check.quickSort()<<endl;  // nlogn

        }
    }
    // getchar();
    return 0;
}
    


