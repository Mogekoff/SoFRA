#pragma once

namespace Sorts {

namespace Random{}
namespace Swap {
    template <typename T> static void Bubble(T& Array, const int Size) {
        for (int i = 1; i <= Size; i++) {
            for (int j = 0; j < Size - i; j++)
                if (Array[j] > Array[j + 1]) {
                    swap(Array[j], Array[j + 1]);
                }
        }
    }

    template <typename T> static void OddEven(T& Array, const int Size) {
        for (int i = 0; i < Size; i++) {
            if (i % 2 == 0) {
                for (int j = 2; j < Size; j += 2)
                    if (Array[j - 1] > Array[j]) {
                        swap(Array[j], Array[j - 1]);
                    }
            }
            else
                for (int j = 1; j < Size; j += 2) {
                    if (Array[j - 1] > Array[j]) {
                        swap(Array[j], Array[j - 1]);
                    }
                }
        }
    }

    template <typename T> static void Shaker(T& Array, const int Size) {
        int l = 0, r = Size - 1;
        for (int i = 0; i < Size; i++) {
            for (int j = l; j < r; j++)
                if (Array[j] > Array[j + 1])
                    swap(Array[j], Array[j + 1]);
            r--;
            for (int j = r; j > l; j--)
                if (Array[j] < Array[j - 1])
                    swap(Array[j], Array[j - 1]);
            l++;
        }
    }

    template <typename T> static void Dwarf(T& Array, const int Size) {
        int i = 0;
        while (i < Size) {
            if (!i || Array[i - 1] <= Array[i])
                i++;
            else {
                swap(Array[i], Array[i - 1]);
                i--;
            }
        }
    }

    template <typename T> void Comb(T& Array, const int Size) {
        for (int i = Size; i > 0; i /= 1.24733)
            for (int j = 0; i + j < Size; j++)
                if (Array[j] > Array[j + i])
                    swap(Array[j], Array[j + i]);
    }

    template <typename T> void QSort(T& Array, const int R, const int L = 0) {
        int i = L,
            j = R;

        T X = Array[(L + R) / 2];

        while (i <= j) {
            while (Array[i] < X)
                i++;

            while (Array[j] > X)
                j--;

            if (i <= j) {
                swap(Array[i], Array[j]);
                i++; j--;
            }
        }

        if (L < j)  QSort(j, L);
        if (i < R)  QSort(R, i);
    }
}
namespace Selection {
    template <typename T> static void Simple(T& Array, const int Size) {
        for (int i = 0, Element = 0; i < Size; i++, Element = i) {
            for (int j = i; j < Size; j++)
                if (Array[j] <= Array[Element])
                    Element = j;
            swap(Array[Element], Array[i]);
        }
    }

    template <typename T> static void Quadratic(T& Array, const int Size) {
        T* Temp = new T[sqrt(Size)];
        T* Result = new T[Size];

        for (int i = 0, j = 0, Edge = 0; i < Size; i++, j = 0) {

            for (int Group = 1, Count = 0; j < Size; j++) {
                if (Array[j] < Array[Edge])
                    Edge = j;
                if (Group == sqrt(Size) || j == Size - 1) {
                    Group = 1;
                    Temp[Count++] = Edge;
                    Edge = j + 1;
                }
                else
                    Group++;
            }

            for (j = 0, Edge = 0; j < sqrt(Size); j++) { //переработать условие
                if (Array[Temp[j]] < Array[Temp[Edge]])
                    Edge = j;
            }
            Result[i] = Array[Temp[Edge]];
            Array[Temp[Edge]] = T(INT_MAX);
        }

        for (int i = 0; i < Size; i++)
            Array[i] = Result[i];
        delete[] Temp;
        delete[] Result;
    }

    template <typename T> static void Pyramid(T& Array, const int Size) {
        std::function<int(int,int)> PyramidConstruct = [Array](int i, int N) {
            int imin;
            if ((2 * i + 2) < N) {
                if (Array[2 * i + 1] > Array[2 * i + 2]) 
                    imin = 2 * i + 2;
                else 
                    imin = 2 * i + 1;
            }
            else 
                imin = 2 * i + 1;

            if (imin >= N) 
                return i;

            if (Array[i] > Array[imin]) {
                swap(Array[i],Array[imin]);
 
                if (imin < N / 2) 
                    i = imin;
            }
            return i;
        };
        
        for (int i = Size / 2 - 1; i >= 0; --i) {  // просматривается половина массива
            int ir = i;                          //ir- инд-с эл-та который рассматривают
            i = PyramidConstruct(i, Size);
            if (ir != i) 
                ++i;
        }

        for (int k = Size - 1; k > 0; --k) { 
            swap(Array[0],Array[k]);
            int i1 = 0, ir = -1;

            //while (i1 != ir)

            while (i1 > ir) {
                ir = i1;
                i1 = PyramidConstruct(i1, k);
            }

        }
    }
}
namespace Insert {}

}