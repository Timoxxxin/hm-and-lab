#include <iostream>
#include <vector>
#include <algorithm> // Для sort и unique

using namespace std;

int main() {
    vector<int> vec; // Объявление вектора для временного хранения элементов
    int n, value, a, b, X, newElement; // Объявление переменных для хранения значений и интервалов
    
    cout << "Введите количество элементов: ";
    cin >> n; 
    
    cout << "Введите значения элементов:\n";
    for (int i = 0; i < n; ++i) { // Цикл для ввода значений элементов
        cin >> value;   
        vec.push_back(value); // Добавление значения в конец вектора
    }

    cout << "Введите интервал [a, b] и число X для замены:\n";
    cin >> a >> b >> X; // Ввод интервала [a, b] и числа X для замены

    // Замена чисел в интервале [a, b] на X
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) { // Цикл по всем элементам вектора
        if (*iter >= a && *iter <= b) { // Если элемент находится в интервале
            *iter = X; // Замена элемента на X
        }
    }

    // Сортировка элементов вектора
    cout << "Сортировка:\n";
    sort(vec.begin(), vec.end()); // Сортировка элементов вектора   
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // Вывод отсортированных элементов
        cout << *iter << " ";
    cout << endl;

    // Вставка нового элемента в отсортированную последовательность
    cout << "Введите новый элемент для вставки: ";
    cin >> newElement; // Ввод нового элемента
    vec.insert(upper_bound(vec.begin(), vec.end(), newElement), newElement); // Вставка нового элемента в отсортированный вектор

    // Удаление повторяющихся элементов
    cout << "Удаление дубликатов:\n";
    vec.erase(unique(vec.begin(), vec.end()), vec.end()); // Удаление повторяющихся элементов
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // Вывод уникальных элементов
        cout << *iter << " ";
    cout << endl;

    return 0;
}