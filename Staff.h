#pragma once
#include "SoFRA.h"

template <typename T> void SoFRA<T>::Edge(T* Arr, int& EdgeIndex, int& EdgeValue, const int To, int From) {
    int EdgeIndex = 0;
    while(From++ < To)
        if (Compare(Arr[From], Arr[EdgeIndex])) {
            EdgeIndex = From;
            EdgeValue = Arr[EdgeIndex];
        }
}

template <typename T> void SoFRA<T>::Swap(T& A, T& B) {
    T Tmp = A;
    A = B;
    B = Tmp;
    Movements += 3;
}

template <typename T> void SoFRA<T>::Assign(T& a, const T b) {
    Movements++;
    a = b;
}

template <typename T> void SoFRA<T>::PrintArray() {
    string ArrayString;
    for (int i = 0; i < Size; i++)
        ArrayString += to_string(Array[i]) + ' ';
    iNTER::Print(ArrayString);
}
template <typename T> void SoFRA<T>::PrintResults() {
    iNTER::Print("Количество сравнений:\t" + to_string(Comparisons)
        + "\nКоличество перемещений:\t" + to_string(Movements)
        + "\nВсего операций:\t" + to_string(Movements+Comparisons)
        + "\nВремя выполнения:\t" + to_string(Time.count())
    );
    Comparisons = 0;
    Movements = 0;
    Time = 0s;
}

template <typename T> bool SoFRA<T>::Sort(function<void()> SortFunction, function<void()> FillFunction) {
    if(Array == nullptr) {
        iNTER::Print("No Array.");
        return false;
    }
    if (FillFunction != nullptr)
        FillFunction();
    iNTER::Print("Исходный массив:\t");
    PrintArray();
    auto StartTime = chrono::high_resolution_clock::now();
    SortFunction();
    Time = chrono::high_resolution_clock::now() - StartTime;
    iNTER::Print("Отсортированный:\t");
    PrintArray();
    PrintResults();
}

template <typename T> bool SoFRA<T>::Compare(T a, T b) {
    Comparisons++;
    if (SortMode == ASCENDING)
        return a > b;
    if (SortMode == DESCENDING)
        return a < b;
    if (SortMode == NONASCENDING)
        return a >= b;
    if (SortMode == NONDESCENDING)
        return a <= b;
}
template <typename T> void SoFRA<T>::CreateArray(const unsigned ArraySize) {
    delete[] Array;
    Array = new T[ArraySize];
    Size = ArraySize;
}



template <typename T> void SoFRA<T>::SetSortMod(int Mode) {
    if (Mode >= 0 && Mode <= 3)
        SortMode = Mode;
    else
        iNTER::Print("[ERROR} No such comparison operation");
}
