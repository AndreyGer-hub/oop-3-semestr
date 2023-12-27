#ifndef TBUBBLESORT_H
#define TBUBBLESORT_H

#include<vector>
#include <algorithm>
#include <iostream>

template<typename T>
void bubbleSort(std::vector<T> &vec)
{
    T tmp;
    for(size_t i = 0; i < vec.size()-1; i++){
        for(size_t j = 0; j < vec.size()-1-i; j++){
            if(vec[j] > vec[j+1]){
                tmp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}

template<typename T>
void fastSort(std::vector<T> &vec)
{
    std::sort(vec.begin(), vec.end());
}
#endif
