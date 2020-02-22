#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;


class SorterFramework {
private:
    int* Array;
    int Size,
        Comparisons = 0,
        Operations = 0,
        MaxAbsNumber = 100;
    chrono::duration<double> Time;

    void Swap(int& a, int& b);
    void PrintResults();
    void PrintArray();

public:
    SorterFramework(const int ArraySize);

    void FillB();
    void FillM();
    void FillG();

    void Bubble();
    void OddEven();
    void Shaker();
    void Dwarf();
    void Comb();
    void QSort(const int L, const int R);
    void QSort_Even(const int L, const int R);

    void Sort(void (SorterFramework::* FillFunc)(), void (SorterFramework::* SortFunc)());
    void Sort(void (SorterFramework::* FillFunc)(), void (SorterFramework::* SortFunc)(const int L, const int R));
};
