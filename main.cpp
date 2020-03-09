#include "iNTER.h"
#include "SoFRA.h"

int main(int argc, char* argv[]) {
    srand(time(0));
    setlocale(LC_ALL, "Russian");

    iNTER I(argc, argv);

    SoFRA<int> SF;

    const int Size = 15;

    SF.CreateArray(Size);
    SF.SetSortMod(SF.ASCENDING);
    
    

    I.AddFunction("AR", "Print current ARray",
        [&]() {SF.PrintArray(); });

    I.AddFunction("RS", "Print ReSult of sorting",
        [&]() {SF.PrintResults(); });

    I.AddFunction("FR", "Fill array by random",
        [&]() {SF.FillRandom(); });

    I.AddFunction("FB", "Fill array by descending",
        [&]() {SF.FillBest(); });

    I.AddFunction("FW", "Fill array by ascending",
        [&]() {SF.FillWorst(); });

    I.AddFunction("SWAP.SIMPLE", "Sorting",
        [&]() { SF.Sort([&SF]{iNTER::Print("Сортировка простым обменом (пузырьком)"); SF.Bubble();});});

    I.AddFunction("SWAP.COMB", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Сортировка расчёской"); SF.Comb(); }); });

    I.AddFunction("SWAP.DWARF", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Гномья сортировка"); SF.Dwarf(); }); });

    I.AddFunction("SWAP.ODDEVEN", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Сортировка методом чёт-нечёт"); SF.OddEven(); }); });

    I.AddFunction("SWAP.QSORT", "Sorting",
        [&]() { SF.Sort([&SF,Size] {iNTER::Print("Быстрая сортировка (Хоара)"); SF.QSort(Size-1); }); });

    I.AddFunction("SWAP.SHAKER", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Сортировка шейкером"); SF.Shaker(); }); });

    I.AddFunction("SELECTION.PYRAMID", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Сортировка кучей (пирамидальная)"); SF.Pyramid(); }); });

    I.AddFunction("SELECTION.QUADRATIC", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Квадратичная сортировка Э.Г.Френда"); SF.Quadratic(); }); });

    I.AddFunction("SELECTION.SIMPLE", "Sorting",
        [&]() { SF.Sort([&SF] {iNTER::Print("Сортировка простым выбором"); SF.Simple(); }); });

    I.AddFunction("SETMOD", "Set mode of sorting algorithm: ASCENDING = 0, DESCENDING = 1, NONASCENDING = 2, NONDESCENDING = 3. Example: \"SETMOD 2\"",
        [&]() { SF.SetSortMod(I.GetArgInt()); });

    I.ExecuteCommand("FR");
    I.ExecuteCommand("SELECTION.PYRAMID");
    I.ExecuteCommand("FW");
    I.ExecuteCommand("SELECTION.QUADRATIC");
    I.ExecuteCommand("FR");
    I.ExecuteCommand("SELECTION.QUADRATIC");
    I.ExecuteCommand("FB");
    I.ExecuteCommand("SELECTION.QUADRATIC");
    //I.ExecuteScript("Script.irp");
    

    return I.Interpreter();
}