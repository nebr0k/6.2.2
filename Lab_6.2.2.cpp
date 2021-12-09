#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

double iMax(int* a, const int size, int max, int index, int i)
{ 
    if (i >= size)
        return index;

    if (a[i] > max)
    {
        max = a[i];
        index = i;
    }
    return iMax(a, size, max, index, ++i);
}

double iMin(int* a, const int size, int min, int index, int i)
{
    if (i >= size)
        return index;

    if (a[i] < min)
    {
        min = a[i];
        index = i;
    }
    return iMin(a, size, min, index, ++i);
}

int main()
{
    srand((unsigned)time(NULL));
    int n = 0;  // розмір масива
    cout << "N = "; cin >> n;
    int* a = new int[n];
    int Low = -10;
    int High = 10;
    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "max = " << iMax(a, n, a[0], 0, 0) << endl;
    cout << "min = " << iMin(a, n, a[0], 0, 0) << endl;
    cout << "average = " << (iMin(a, n, a[0], 0, 0) + iMax(a, n, a[0], 0, 0)) / 2 << endl;


    return 0;

    delete[] a;

}