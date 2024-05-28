#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>// для использования функции swap

using namespace std;     

// функция быстрой сортировки
void QuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {     // условие рекурсивного вызова
        int pivot = arr[high];    // выбор опорного элемента (последний элемент в подмассиве)
        int i = low - 1;  
        for (int j = low; j < high; j++) {    // проход по подмассиву
            if (arr[j] < pivot) {   // если текущий элемент меньше опорного
                i++;
                swap(arr[i], arr[j]);   // меняем местами элементы
            }
        }
        swap(arr[i + 1], arr[high]);    // меняем местами опорный элемент и элемент после последнего меньшего
        int pi = i + 1;   
        QuickSort(arr, low, pi - 1);    //  вызов для левой части
        QuickSort(arr, pi + 1, high);   //  вызов для правой части
    }
}

int main() {
    int n; 
    ifstream in("input.txt");   
    ofstream out("arr_fast_output.txt"); 
    in >> n;   

    vector<vector<int>> arr(n, vector<int>(n));   // Объявление двумерного вектора размером n x n
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            in >> arr[i][j];  
        }
    }

    for (int j = 0; j < n; j++) {   // проход по каждому столбцу 
        vector<int> arr_col;    // вектор для хранения столбца
        for (int i = 0; i < n; i++) {
            arr_col.push_back(arr[i][j]);   // копирование элементов столбца во временный вектор
        }

        QuickSort(arr_col, 0, n - 1);   // сортировка столбца

        for (int i = 0; i < n; i++) {
            arr[i][j] = arr_col[i];    // копирование отсортированных элементов обратно в массив
        }
    }

    for (int i = 0; i < n; i++) {   // запись отсортированного массива в файл
        for (int j = 0; j < n; j++) {
            out << arr[i][j] << " ";   // запись элемента массива в файл
        }
        out << endl;  
    }

    in.close();   
    out.close();   
    
    return 0;   
}