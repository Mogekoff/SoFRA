#pragma once
#include "SoFRA.h"

template <typename T> void SoFRA<T>::Bubble() {
    for (int i = 1; i <= Size; i++) {
        for (int j = 0; j < Size - i; j++)
            if (Compare(Array[j], Array[j + 1]))
                Swap(Array[j], Array[j + 1]);

    }
}
template <typename T> void SoFRA<T>::OddEven() {
    for (int i = 0; i < Size; i++) {
        if (i % 2 == 0) {
            for (int j = 2; j < Size; j += 2)
                if (Compare(Array[j - 1], Array[j]))
                    Swap(Array[j], Array[j - 1]);

        }
        else
            for (int j = 1; j < Size; j += 2) {
                if (Compare(Array[j - 1], Array[j]))
                    Swap(Array[j], Array[j - 1]);

            }
    }
}
template <typename T> void SoFRA<T>::Shaker() {
    int l = 0, r = Size - 1;
    for (int i = 0; i < Size; i++) {
        for (int j = l; j < r; j++)
            if (Compare(Array[j], Array[j + 1]))
                Swap(Array[j], Array[j + 1]);
        r--;
        for (int j = r; j > l; j--)
            if (Compare(Array[j - 1], Array[j]))
                Swap(Array[j], Array[j - 1]);
        l++;
    }
}
template <typename T> void SoFRA<T>::Dwarf() {
    int i = 0;
    while (i < Size) {
        if (!i || Compare(Array[i], Array[i - 1]))
            i++;
        else {
            Swap(Array[i], Array[i - 1]);
            i--;
        }
    }
}
template <typename T> void SoFRA<T>::Comb() {
    for (int i = Size; i > 0; i /= 1.24733)
        for (int j = 0; i + j < Size; j++)
            if (Compare(Array[j], Array[j + i]))
                Swap(Array[j], Array[j + i]);
}
template <typename T> void SoFRA<T>::QSort(const int R, const int L) {
    int i = L,
        j = R,
        X = (L + R) / 2;
        
    while (i <= j) {
        while (Compare(Array[X], Array[i]))
            i++;

        while (Compare(Array[j], Array[X]))
            j--;

        if (!Compare(i, j)) {
            Swap(Array[i], Array[j]);
            i++; j--;
        }
    }

    if (Compare(j, L))  QSort(j, L);
    if (Compare(R, i))  QSort(R, i);
}
