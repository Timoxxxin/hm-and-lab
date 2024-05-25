#include <iostream>
#include <math.h>

using namespace std;

// Структура точки
struct point
{
    double x, y;
};

// Создание массива точек
point *create(int n)
{
    point *a = new point[n]; // Выделение памяти под массив точек
    for (int i = 0; i < n; i++)
    {
        cout << "Input " << i + 1 << " point coordinates (x, y): \n"; // Пользовательский ввод координат точек
        cin >> a[i].x >> a[i].y; // Считывание координат точек
    }
    return a; // Возврат массива точек
}

// Подсчет дистанции между двумя точками
double dlina(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // Функция для расчета расстояния между двумя точками
}

// Подсчет максимальной суммы дистанции между точкой со всеми остальными
pair<double, int> maxSumDistance(point *a, int n)
{
    double maxSumDistance = 0.0; // Инициализация переменной для хранения максимальной суммы расстояний
    int NumberOfPoint = 0; // Инициализация переменной для хранения номера точки
    for (int i = 0; i < n; i++)
    {
        double sumDistance = 0.0; // Инициализация переменной для хранения суммы расстояний
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                sumDistance += dlina(a[i], a[j]); // Суммирование расстояний между текущей точкой и всеми остальными
            }
        }
        if (sumDistance > maxSumDistance)
        {
            maxSumDistance = sumDistance; // Обновление максимальной суммы расстояний
            NumberOfPoint = i; // Обновление номера точки
        }
        sumDistance = 0; 
    }
    return pair<double, int>(maxSumDistance, NumberOfPoint + 1); // Возврат максимальной суммы расстояний и номера точки
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n; // Ввод количества точек
    point *a = create(n); // Создание массива точек
    auto result = maxSumDistance(a, n); // Вызов функции для нахождения максимальной суммы расстояний и номера точки
    delete[] a; // Освобождение памяти, выделенной для массива точек
    cout << "Максимальная сумма дистанций " << result.first << ", у которой номер точки: " << result.second; // Вывод результата
    return 0;
}