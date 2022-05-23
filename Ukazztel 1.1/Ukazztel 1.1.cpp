// Ukazztel 1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <conio.h>
using namespace std;

void sort(int* arrN, int sizeN)
{
	/*Даны 2 массива минимального размера ввести ттретий минимальный без повторов*/

    int tmp = 0;
    for (int i = 0; i < sizeN; ++i)
    {
        for (int j = i + 1; j < sizeN; ++j)
        {
            if (arrN[j] < arrN[i])
            {
                tmp = arrN[j];
                arrN[j] = arrN[i];
                arrN[i] = tmp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(unsigned(time(0)));

    cout << "Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массивов A и B, которые не являются общими для них\n\n";
    {
        int sizeA, sizeB;
        cout << "Введите размер первого массива: ";
        cin >> sizeA;
        cout << "Введите размер второго массива: ";
        cin >> sizeB;
        int* arrA = new int[sizeA];
        int* arrB = new int[sizeB];
        cout << "\n\nПервый массив: ";
        for (int x = 0; x < sizeA; x++)
        {
            arrA[x] = rand() % 9 + 1;
            cout << arrA[x] << " ";
        }
        cout << "\n\nВторой массив: ";
        for (int x = 0; x < sizeB; x++)
        {
            arrB[x] = rand() % 9 + 1;
            cout << arrB[x] << " ";
        }

        sort(arrA, sizeA);
        sort(arrB, sizeB);

        cout << "\n\nПервый массив (Отсортированный): ";
        for (int x = 0; x < sizeA; x++)
        {
            cout << arrA[x] << " ";
        }
        cout << "\n\nВторой массив (Отсортированный): ";
        for (int x = 0; x < sizeB; x++)
        {
            cout << arrB[x] << " ";
        }

        int* arrC = new int[sizeA < sizeB ? sizeA : sizeB];
        int sizeC = 0;

        cout << endl << endl << endl;

        bool flag;
        for (int x = 0; x < sizeA; x++)
        {
            flag = true;
            for (int y = 0; y < sizeB; y++)
            {
                if (arrA[x] == arrB[y])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                arrC[sizeC] = arrA[x];
                sizeC++;
            }
        }

        int y;
        for (int x = 0; x < sizeA; x++)
        {
            flag = true;
            for (y = 0; y < sizeB; y++)
            {
                if (arrB[x] == arrA[y])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                arrC[sizeC] = arrA[y];
                sizeC++;
            }
        }
        sizeC--;

        cout << "\n\nТретий массив: ";
        for (int x = 0; x < sizeC; x++)
        {
            cout << arrC[x] << " ";
        }

        delete[] arrA;
        delete[] arrB;
        delete[] arrC;
    }
    _getch();
    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
