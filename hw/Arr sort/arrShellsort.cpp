#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void shellSort(vector<vector<int>>& arr, int n) { // функция сортировки Шелла с шагом d = N/2^i
    for (int gap = n / 2; gap > 0; gap /= 2) { // Внешний цикл для определения шага сортировки
        for (int i = 0; i < gap; i++) { // Цикл для прохода по всем подмассивам
            for (int j = i + gap; j < n; j += gap) { // Внутренний цикл для сортировки подмассива
                if ((j % n) % 2 == 0) {  // Если столбец четный, сортируем по убыванию
                    for (int k = j; k >= gap; k -= gap) {
                        if (arr[k - gap][i] < arr[k][i]) {  // Если текущий элемент меньше предыдущего, меняем их местами
                            swap(arr[k - gap], arr[k]);
                        } else {
                            break; 
                        }
                    }
                } else { // Если столбец нечетный, сортируем по возрастанию
                    for (int k = j; k >= gap; k -= gap) {
                        if (arr[k - gap][i] > arr[k][i]) {// Если текущий элемент больше предыдущего, меняем их местами
                            swap(arr[k - gap], arr[k]);
                        } else {
                            break; 
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    ifstream inputFile("input.txt");
    ofstream outputFile("arr_Shell_output.txt");
    inputFile >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) { // Считывание массива из файла
        for (int j = 0; j < n; j++) {
            inputFile >> arr[i][j];
        }
    }

    shellSort(arr, n); // Вызов функции сортировки Шелла

    for (int i = 0; i < n; i++) { // Запись отсортированного массива в файл
        for (int j = 0; j < n; j++) {
            outputFile << arr[i][j] << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}