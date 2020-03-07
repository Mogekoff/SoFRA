#pragma once
#include "SoFRA.h"

template <typename T> void SoFRA<T>::FillWorst() {
    for (int i = Size - 1; i >= 0; i--)
        Array[Size - 1 - i] = T(i);
}
template <typename T> void SoFRA<T>::FillRandom() {
    for (int i = 0; i < Size; i++)
        Array[i] = T(rand() % 100);
}
template <typename T> void SoFRA<T>::FillBest() {
    for (int i = 0; i < Size; i++)
        Array[i] = T(i);
}
