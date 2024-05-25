#include <iostream>
#include <fstream> // подключаем библиотеку для работы с файлами 
#include <vector>
#include <string>// со строками
#include <algorithm>// для работы с сортировками 
#include <iomanip> // для форматирования вывода 

using namespace std;

struct Date { // Структура для хранения даты
    int dd, mm, yy;
};

struct Employee { // Создаем структуру для представления сотрудника
    string name, post;
    Date birth;
    int exp, salary;
};

bool compareBySalary(const Employee& emp1, const Employee& emp2) { // объявляем функцию для сравнения сотрудников по зп
    return emp1.salary < emp2.salary; // если зарплата первого сотрудника меньше зарплаты второго то true
}

void quickSort(vector<Employee>& arr, int left, int right) {
    int i = left, j = right; // объявляем переменные для левой и правой границ массива
    int sup = arr[(left + right) / 2].salary; // выбираем опорный элемент (зарплату сотрудника посередине)

    while (i <= j) { // пока левая граница не превысила правую
        while (arr[i].salary < sup) { //поиск элемента большего или равного опорному слева
            i++;
        }
        while (arr[j].salary > sup) { // поиск элемента меньшего или равного опорному справа
            j--;
        }       
        if (i <= j) { // если нашли такие элементы, меняем их местами
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j); // сортируем левую часть
    }
    if (i < right) {
        quickSort(arr, i, right); // сортируем правую часть
    }
}

vector<Employee> fillArray() { // объявляем ф-ию для заполнения вектора данными из файла
    vector<Employee> x; // создаем вектор сотрудников
    Employee emp; // временный объект сотрудника
    ifstream in("input.txt");   // открываем файл для чтения данных
    while (in.peek() != EOF) { // цикл чтения данных из файла до конца файла
        in >> emp.name;  
        in >> emp.post;

        string temp; //создаем временную переменную для считывания даты
        in >> temp;

        emp.birth.dd = stoi(temp.substr(0, 2));
        emp.birth.mm = stoi(temp.substr(3, 2));
        emp.birth.yy = stoi(temp.substr(6, 4));

        in >> temp;
        emp.exp = stoi(temp);

        in >> temp;
        emp.salary = stoi(temp);

        x.push_back(emp); // добавляем сотрудника в вектор
    }

    in.close();
    return x;
}

void print(const Employee& x, ofstream& out) { // объявляем ф-ию для вывода информации о сотруднике в файл
    out << setw(10) << x.name << setw(15) << x.post << setw(10); // вывод имени и должности с выравниванием
    if (x.birth.dd < 10) out << setw(6) << "0" << x.birth.dd << "."; // проверка и вывод дня рождения с добавлением нуля при необходимости
    else out << setw(7) << x.birth.dd << ".";// вывод дня рождения
    if (x.birth.mm < 10) out << "0" << x.birth.mm << ".";// проверка и вывод месяца рождения с добавлением нуля при необходимости
    else out << x.birth.mm << ".";
    out << x.birth.yy << setw(9) << x.exp << setw(12) << x.salary << endl;
}

int main() {
    ofstream out("output_quick.txt");
    vector<Employee> employeeList; // создание вектора для хранения сотрудников
    employeeList = fillArray();// заполнение вектора данными из файла

    quickSort(employeeList, 0, employeeList.size() - 1);
    
// Вывод заголовков столбцов в файл
    out << setw(5) << "|name|" << setw(10) << "|post|" << setw(10) << "|birthday|" << setw(15) << "|experience|" << setw(10) << "|salary|" << endl;

// Вывод данных о сотрудниках в файл
    for (const auto& employee : employeeList)
        print(employee, out);

    return 0;
}