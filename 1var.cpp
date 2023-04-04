#include <iostream>
#include <omp.h>
using namespace std;


int main(int argc, char** argv) {

    //две матрицы 2000х2000
    int row1 = 2000, row2 = 2000, col1 = 2000, col2 = 2000;
    int** a, ** b, ** c;

    //заполнение первой матрицы
    a = new int* [row1];
    for (int i = 0; i < row1; i++)
    {
        a[i] = new int[col1];
        for (int j = 0; j < col1; j++)
        {
            a[i][j] = j % 10;
        }
    }

    //заполнение второй матрицы
    b = new int* [row2];
    for (int i = 0; i < row2; i++)
    {
        b[i] = new int[col2];
        for (int j = 0; j < col2; j++)
        {
            b[i][j] = j % 10;
        }
    }


    clock_t start = clock();

    // ------------------- ОРИГИНАЛЬНЫЙ АЛГОРИТМ -------------------

    // Умножение матриц
    c = new int* [row1];
    for (int i = 0; i < row1; i++)
    {
        c[i] = new int[col2];
        for (int j = 0; j < col2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    // ------------------- ОБРАЩЕНИЕ КО 2 МАТРИЦЕ ПОСТРОЧНО -------------------

    //// Умножение матриц
    //c = new int* [row1];

    //for (int i = 0; i < row1; i++) {
    //    c[i] = new int[col2] {};

    //    for (int k = 0; k < col1; k++) {
    //        int r1 = a[i][k];

    //        //построчное обращение ко 2 матрице(дружелюбность к кэшу)
    //        for (int j = 0; j < col2; j++) {
    //            c[i][j] += r1 * b[k][j];
    //        }
    //    }
    //}

    // ------------------- КОНВЕЙЕР -------------------

    //// Умножение матриц
    //c = new int* [row1];
    //int maxCol2 = (col2 / 4) * 4;
    //
    //for (int i = 0; i < row1; i++) {
    //    c[i] = new int[col2] {};

    //    for (int k = 0; k < col1; k++) {
    //        int r1 = a[i][k];
    //        //построчное обращение ко 2 матрице + конвейер
    //        for (int j = 0; j < maxCol2; j += 4) {
    //            c[i][j] += r1 * b[k][j];
    //            c[i][j + 1] += r1 * b[k][j + 1];
    //            c[i][j + 2] += r1 * b[k][j + 2];
    //            c[i][j + 3] += r1 * b[k][j + 3];
    //        }

    //        //доработка после конвейера
    //        for (int j = maxCol2; j < col2; j++) {
    //            c[i][j] += r1 * b[k][j];
    //        }

    //    }
    //}

    // ------------------- МНОГОПОТОЧНОСТЬ -------------------


    //// Умножение матриц
    //c = new int* [row1];
    //int maxCol2 = col2 / 4;

    ////многопоточность
    //#pragma omp parallel for
    //for (int i = 0; i < row1; i++) {
    //    c[i] = new int[col2] {};

    //    for (int k = 0; k < col1; k++) {
    //        int r1 = a[i][k];

    //        //построчное обращение ко 2 матрице + конвейер
    //        for (int j = 0; j < maxCol2; j += 4) {
    //            c[i][j] += r1 * b[k][j];
    //            c[i][j + 1] += r1 * b[k][j + 1];
    //            c[i][j + 2] += r1 * b[k][j + 2];
    //            c[i][j + 3] += r1 * b[k][j + 3];
    //        }

    //        //доработка после конвейера
    //        for (int j = maxCol2; j < col2; j++) {
    //            c[i][j] += r1 * b[k][j];
    //        }

    //    }
    //}

    clock_t end = clock();

    cout << "time = " << end - start << endl;

    //// Вывод элементов первой матрицы
    //cout << endl << "matrix a:" << endl;
    //for (int i = 0; i < row1; i++)
    //{
    //    for (int j = 0; j < col1; j++)
    //        cout << a[i][j] << " ";
    //    cout << endl;
    //}

    //// Вывод элементов второй матрицы
    //cout << endl << "matrix b:" << endl;
    //for (int i = 0; i < row2; i++)
    //{
    //    for (int j = 0; j < col2; j++)
    //    {
    //        cout << b[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //// Вывод матрицы произведения
    //cout << endl << "result matrix:" << endl;
    //for (int i = 0; i < row1; i++)
    //{
    //    for (int j = 0; j < col2; j++)
    //        cout << c[i][j] << " ";
    //    cout << endl;
    //}

    return 0;
}








