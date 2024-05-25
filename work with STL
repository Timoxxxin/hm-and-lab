#include <iostream> 
#include <vector> 
using namespace std;

int main() { 
    setlocale (LC_ALL,"RUS");
    vector<int> numbers; // Создание вектора для хранения целых чисел.
    int n; 

    cout << "Введите количество чисел: ";
    cin >> n; 

    cout << "Введите целые числа: "; 
    for (int i = 0; i < n; ++i) { 
        int num; 
        cin >> num; 
        numbers.push_back(num); // Добавление числа в конец вектора.
    }

    int min_num = numbers[0]; // Инициализация минимального числа первого элемента вектора.
    int count = 1; 

    for (int i = 1; i < n; ++i) { 
        if (numbers[i] < min_num) { 
            min_num = numbers[i];
            count = 1; 
        } else if (numbers[i] == min_num) { 
            count++; 
        }
    }

    cout << "Количество минимальных чисел: " << count << endl; 

    return 0; 
}