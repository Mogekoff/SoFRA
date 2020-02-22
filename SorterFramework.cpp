#include "SorterFramework.h"

/* Вспомогательные методы */

SorterFramework::SorterFramework(const int ArraySize) { //Конструктор
    Size = ArraySize;
    Array = new int[Size];
}

void SorterFramework::Swap(int& A, int& B) {    //Обмен
    int Tmp = A;
    A = B;
    B = Tmp;
    Operations += 3;
}

void SorterFramework::FillB() {     //Худшее заполнение
    for (int i = Size-1; i >= 0; i--)
        Array[Size - 1 - i] = i;
}

void SorterFramework::FillM() {     //Среднее(случайное) заполнение
    for (int i = 0; i < Size; i++)
        Array[i] = rand() % MaxAbsNumber * (rand() % 2 > 0 ? -1 : 1);   //Тер.оп. для вычисления знака числа
}

void SorterFramework::FillG() {     //Лучшее заполнение
    for (int i = 0; i < Size; i++)
        Array[i] = i;
}

void SorterFramework::PrintArray() {
    for (int i = 0; i < Size; i++)
        cout << Array[i] << ' ';
    cout << '\n';
}

void SorterFramework::PrintResults() {
    cout << "Количество сравнений:\t" << Comparisons;
    cout << "\nКоличество операций:\t" << Operations;
    cout << "\nВремя выполнения:\t" << fixed << Time.count() << endl;   //fixed для вывода всего числа
    Comparisons = 0;                                                    //Обнуляем сравнения
    Operations = 0;                                                     //Обнуляем операции
}

void SorterFramework::Sort(void (SorterFramework::* FillFunc)(), void (SorterFramework::* SortFunc)()) {   //Контрольный метод
    (this->*FillFunc)();                                    //Заполнение массива
    cout << "Исходный массив:\t";
    PrintArray();                                           //Вывод массива
    auto StartTime = chrono::high_resolution_clock::now();  //Старт таймера
    (this->*SortFunc)();                                    //Сортировка
    auto FinishTime = chrono::high_resolution_clock::now(); //Конец таймера
    cout << "Отсортированный:\t";
    PrintArray();                                           //Вывод массива
    Time = FinishTime - StartTime;                          //Вычисление времени выполнения
    PrintResults();                                         //Вывод результатов
}

void SorterFramework::Sort(void(SorterFramework::* FillFunc)(), void(SorterFramework::* SortFunc)(const int L, const int R))    //Перегрузка контрольного метода для методов с параметрами
{
    (this->*FillFunc)();
    cout << "Исходный массив:\t";
    PrintArray();
    auto StartTime = chrono::high_resolution_clock::now();
    (this->*SortFunc)(0, Size-1);
    auto FinishTime = chrono::high_resolution_clock::now();
    cout << "Отсортированный:\t";
    PrintArray();
    Time = FinishTime - StartTime;
    PrintResults();
}

/* Реализация методов сортировок */

void SorterFramework::Bubble() {
    for (int i = 1; i <= Size; i++) {
        for (int j = 0; j < Size - i; j++, Comparisons++)
            if (Array[j] > Array[j + 1]) {
                Swap(Array[j], Array[j + 1]);
            }
    }
}

void SorterFramework::OddEven() {
    for (int i = 0; i < Size; i++) {
        if (i % 2 == 0) {
            for (int j = 2; j < Size; j += 2, Comparisons++)
                if (Array[j - 1] > Array[j]) {
                    Swap(Array[j], Array[j - 1]);
                }
        }
        else
            for (int j = 1; j < Size; j += 2, Comparisons++) {
                if (Array[j - 1] > Array[j]) {
                    Swap(Array[j], Array[j - 1]);
                }
            }
    }
}

void SorterFramework::Shaker() {
    int l = 0, r = Size - 1;
    for (int i = 0; i < Size; i++) {
        for (int j = l; j < r; j++, Comparisons++)
            if (Array[j] > Array[j + 1])
                Swap(Array[j], Array[j + 1]);
        r--;
        for (int j = r; j > l; j--, Comparisons++)
            if (Array[j] < Array[j - 1])
                Swap(Array[j], Array[j - 1]);
        l++;
    }
}

void SorterFramework::Dwarf() {
    int i = 0;
    while (i < Size) {
        Comparisons++;
        if (!i || Array[i - 1] <= Array[i])
            i++;
        else {
            Swap(Array[i], Array[i - 1]);
            i--;
        }
    }
}

void SorterFramework::Comb() {
    for (int i = Size; i > 0; i/= 1.24733)
        for (int j = 0; i + j < Size; j++, Comparisons++)
            if (Array[j] > Array[j + i])
                Swap(Array[j], Array[j + i]);
}

void SorterFramework::QSort(const int L, const int R) {
    int i = L,
        j = R;

    double X=Array[(L+R)/2];

    while (i <= j) {
        while (Array[i] < X) {
            i++;
            Comparisons++;
        }
        while (Array[j] > X) {
            j--;
            Comparisons++;
        }

        if (i <= j) {
            Swap(Array[i], Array[j]);
            i++; j--;
        }
    }

    if (L < j)  QSort(L, j);
    if (i < R)  QSort(i, R);
}

void SorterFramework::QSort_Even(const int L, const int R) {
    int i = L,
        j = R;

    if(L%2)         //для рекурсивных вызовов: если крайние элементы оказались нечетными
        i=L-1;
    if(R%2)
        j=R-1;

    double X;
    if((L+R)/2 % 2 == 1 )
        X=Array[((L + R) / 2)-1];
    else
        X=Array[(L + R) / 2];

    while (i <= j) {
        while (Array[i] < X) {
            i+=2;
            Comparisons++;
        }
        while (Array[j] > X) {
            j-=2;
            Comparisons++;
        }

        if (i <= j) {
            Swap(Array[i], Array[j]);
            i+=2; j-=2;
        }
    }

    if (L < j)  QSort_Even(L, j);
    if (i < R)  QSort_Even(i, R);
}
