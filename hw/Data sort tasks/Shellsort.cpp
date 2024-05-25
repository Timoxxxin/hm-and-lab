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

bool compareByNameAndPosition(const Employee& emp1, const Employee& emp2) { // объявляем функцию для сравнения сотрудников по имени и должности
    if (emp1.name != emp2.name) { // сначала сравниваем имена сотрудников.
        return emp1.name < emp2.name; // если имя первого сотрудника меньше имени второго, то true
    } else {  // если имена равны, сравниваем должности.
        return emp1.post < emp2.post; // если должность первого сотрудника меньше должности второго, то true
    }
}

vector<Employee> fillArray() { // объявляем ф-ию для заполнения вектора данными из файла
    vector<Employee> x; // создаем вектор сотрудников
    Employee emp;  // временный объект сотрудника
    ifstream in("input.txt"); // открываем файл для чтения данных
    while (in.peek() != EOF) { // цикл чтения данных из файла до конца файла
        in >> emp.name;  // считываем имя
        in >> emp.post; // считываем должность 

        string temp; //создаем временную переменную для считывания даты
        in >> temp; // считываем дату во врем переменную

        emp.birth.dd = stoi(temp.substr(0, 2));
        emp.birth.mm = stoi(temp.substr(3, 2));
        emp.birth.yy = stoi(temp.substr(6, 4));

        in >> temp;// считываем стаж
        emp.exp = stoi(temp);

        in >> temp;// считываем зп
        emp.salary = stoi(temp);

        x.push_back(emp); // добавляем сотрудника в вектор
    }

    in.close();
    return x;
}

void print(const Employee& x, ofstream& out) { // объявляем ф-ию для вывода информации о сотруднике в файл
    out << setw(10) << x.name << setw(15) << x.post << setw(10); // вывод имени и должности с выравниванием
    if (x.birth.dd < 10) out << setw(6) << "0" << x.birth.dd << "."; // проверка и вывод дня рождения с добавлением нуля при необходимости
    else out << setw(7) << x.birth.dd << "."; // вывод дня рождения
    if (x.birth.mm < 10) out << "0" << x.birth.mm << ".";// проверка и вывод месяца рождения с добавлением нуля при необходимости
    else out << x.birth.mm << ".";
    out << x.birth.yy << setw(9) << x.exp << setw(12) << x.salary << endl;
}

void shellSort(vector<Employee>& arr) { // объявление функции shellSort, которая принимает вектор
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) { 
        for (int i = gap; i < n; i += 1) { // цикл прохода
            Employee temp = arr[i];
            int j;
            for (j = i; j >= gap && compareByNameAndPosition(arr[j - gap], temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() { 
    ofstream out("output_shell.txt");
    vector<Employee> employeeList;// создание вектора для хранения сотрудников
    employeeList = fillArray();// заполнение вектора данными из файла

    shellSort(employeeList);

// Вывод заголовков столбцов в файл
    out << setw(5) << "|name|" << setw(10) << "|post|" << setw(10) << "|birthday|" << setw(10) << "|experience|" << setw(10) << "|salary|" << endl;

// Вывод данных о сотрудниках в файл
    for (const auto& employee : employeeList)
        print(employee, out);

    return 0;
}