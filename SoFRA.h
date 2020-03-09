#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <thread>
#include <cmath>
#include <functional>

using namespace std;

template <typename T>
class SoFRA {
private:
    T* Array = nullptr;
    int Size = 0,
        Comparisons = 0,
        Movements = 0;
    chrono::duration<double> Time;
    
    short SortMode = 0;

    void Swap(T& a, T& b);
    bool Compare(T a, T b);
    void Assign(T& a, const T b);

public:
    
    const short ASCENDING = 0, DESCENDING = 1, NONASCENDING = 2, NONDESCENDING = 3;
    
    void SetSortMod(int Mode);
    void PrintResults();
    void PrintArray();
    void CreateArray(const unsigned ArraySize);
    void FillWorst();
    void FillRandom();
    void FillBest();
    bool Sort(function<void()> SortFunction, function<void()> FillFunction = nullptr);

    void Edge(T* Arr,  int& EdgeIndex, int& EdgeValue, const int To, int From = 0);

    void Bubble();
    void OddEven();
    void Shaker();
    void Dwarf();
    void Comb();
    void QSort(const int R, const int L = 0);

    void Simple();
    void Quadratic();
    void Pyramid();
    
    
};
    
#include "Staff.h"
#include "Fillings.h"

#include "Insert.h"
#include "Selection.h"
#include "Swap.h"