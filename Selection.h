#pragma once
#include "SoFRA.h"

template <typename T> void SoFRA<T>::Simple() {
    for (int i = 0, Element = 0; i < Size; i++, Element = i) {
        for (int j = i; j < Size; j++)
            if (Compare(Array[j], Array[Element]))
                Element = j;
        Swap(Array[Element], Array[i]);
    }
}

template <typename T> void SoFRA<T>::Quadratic() {
    int Groups = ceil(sqrt(Size));              //Кол-во групп
    int* IndexArray = new int[Size];           //Массив индексов массива Array
    int* BestIndexArray = new int[Groups];
    T* Result = new T[Size];

   

    for(int i = 0; i<Groups*Groups; i++) {   //Заполнение индексами по порядку
        if(i>=Size)
            Assign(IndexArray[i], -1);
        else
            Assign(IndexArray[i], i);
    }
    
    for (int i = 0, EdgeIndex; i < Groups; i++) {
        EdgeIndex = i * Groups;
        for (int j = EdgeIndex; j < (i + 1) * Groups; j++) {
            if (IndexArray[j] == -1 && j==i*Groups) {
                Assign(BestIndexArray[i], -1);
                break;
            }
            if (IndexArray[j] != -1 && (Compare(Array[IndexArray[EdgeIndex]], Array[IndexArray[j]]) || EdgeIndex==j)) {
                Assign(BestIndexArray[i], IndexArray[j]);
                EdgeIndex=j;
            }
        }
        Assign(IndexArray[EdgeIndex], -1);
    }
  
    for(int i = 0, EdgeIndex = 0; i< Size; i++, EdgeIndex = -1) {
        for (int j = 0; j < Groups; j++) {
            if(BestIndexArray[j] != -1 && EdgeIndex == -1) {
                Assign(EdgeIndex, j);
                continue;
            }
            else if (BestIndexArray[j] != -1 && Compare(Array[BestIndexArray[EdgeIndex]], Array[BestIndexArray[j]]))
                Assign(EdgeIndex, j);
        
        }

        Assign(Result[i], Array[BestIndexArray[EdgeIndex]]);
        Assign(IndexArray[BestIndexArray[EdgeIndex]], -1);
        
        int j = BestIndexArray[EdgeIndex] / Groups * Groups;
        int k = (BestIndexArray[EdgeIndex] / Groups + 1) * Groups;
        int BestEdgeIndex = -1;
        int TmpCount = 0;
        
        while (j < k) {
            if (IndexArray[j] != -1 && BestEdgeIndex==-1) {
                Assign(BestEdgeIndex , j);
                continue;
            }
            else if(IndexArray[j] != -1 && Compare(Array[IndexArray[BestEdgeIndex]], Array[IndexArray[j]]))
                Assign(BestEdgeIndex , j);
            j++;
        }
        if(BestEdgeIndex==-1)
            Assign(BestIndexArray[EdgeIndex],-1);
        else
            Assign(BestIndexArray[EdgeIndex], BestEdgeIndex);
 
    }
    
    delete[] Array;
    Array=Result;
    
    /*delete[] IndexArray;
    delete[] BestIndexArray;
    delete[] Result;*/
}
template <typename T> void SoFRA<T>::Pyramid() {
    function<int(int, int)> PyramidConstruct = [this](int i, int N) {
        int imin;
        if ((2 * i + 2) < N) {
            if (Compare(Array[2 * i + 1], Array[2 * i + 2]))
                imin = 2 * i + 2;
            else
                imin = 2 * i + 1;
        }
        else
            imin = 2 * i + 1;

        if (imin >= N)
            return i;

        if (Compare(Array[i], Array[imin])) {
            Swap(Array[i], Array[imin]);

            if (imin < N / 2)
                i = imin;
        }
        return i;
    };

    for (int i = Size / 2 - 1; i >= 0; --i) {  // просматривается половина массива
        int ir = i;                          //ir- инд-с эл-та который рассматривают
        i = PyramidConstruct(i, Size);
        PrintArray();
        if (ir != i)
            ++i;
    }

    for (int k = Size - 1; k > 0; --k) {
        Swap(Array[0], Array[k]);
        int i1 = 0, ir = -1;

        while (i1 > ir) {
            ir = i1;
            i1 = PyramidConstruct(i1, k);
            PrintArray();
        }

    }
}