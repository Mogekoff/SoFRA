#include "SorterFramework.h"

/* Main */

int main() {
    srand(time(0));
    setlocale(LC_ALL, "");

    /*  FillB - заполняет массив для худшего случая
     *  FillM - заполняет массив случайными числами
     *  FillG - заполняет массив для лучшего случая
     *  Sort - контрольный метод, который вызывает
     *  вспомогательные: выводы массивов, результаты и т.д.
     *  Принимает как аргументы адрес метода заполнения массива (один из FillB,FillM,FillG)
     *  и название метода сортировки (любой, например Bubble).
     *  Реализация сортировок находится в файле SorterFramework.cpp
     *  Все методы в классе описаны в SorterFramework.h
     *  Ниже приведены закоментированные вызовы всех сортировок для всех случаев
     */

    SorterFramework SF(15); //15 - размер массива

//    SF.Sort(&SorterFramework::FillB, &SorterFramework::Bubble);
//    SF.Sort(&SorterFramework::FillM, &SorterFramework::Bubble);
//    SF.Sort(&SorterFramework::FillG, &SorterFramework::Bubble);
//    SF.Sort(&SorterFramework::FillB, &SorterFramework::OddEven);
//    SF.Sort(&SorterFramework::FillM, &SorterFramework::OddEven);
//    SF.Sort(&SorterFramework::FillG, &SorterFramework::OddEven);
//    SF.Sort(&SorterFramework::FillB, &SorterFramework::Shaker);
//    SF.Sort(&SorterFramework::FillM, &SorterFramework::Shaker);
//    SF.Sort(&SorterFramework::FillG, &SorterFramework::Shaker);
//    SF.Sort(&SorterFramework::FillB, &SorterFramework::Dwarf);
//    SF.Sort(&SorterFramework::FillM, &SorterFramework::Dwarf);
//    SF.Sort(&SorterFramework::FillG, &SorterFramework::Dwarf);
//    SF.Sort(&SorterFramework::FillB, &SorterFramework::Comb);
//    SF.Sort(&SorterFramework::FillM, &SorterFramework::Comb);
//    SF.Sort(&SorterFramework::FillG, &SorterFramework::Comb);
//    SF.Sort(&SorterFramework::FillB, &SorterFramework::QSort);
//    SF.Sort(&SorterFramework::FillM, &SorterFramework::QSort);
//    SF.Sort(&SorterFramework::FillG, &SorterFramework::QSort);

    SF.Sort(&SorterFramework::FillM, &SorterFramework::QSort_Even); //Случайное заполнение, быстрая сортировка элементов на четных местах


    return 0;
}
