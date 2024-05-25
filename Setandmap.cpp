#include <iostream> 
#include <set>  // Подключаем библиотеку для использования множеств
#include <vector>
using namespace std;

int main()
{
    vector<int> sequence;  // вектор для хранения последовательности чисел
    int n, num;

    cout << "Введите размер последовательности: ";  
    cin >> n;  

    cout << "Введите элементы последовательности: ";  
    for (int i = 0; i < n; ++i) {  
        cin >> num;  
        sequence.push_back(num);  
    }

    set<int> digits;  // множество для хранения цифр 
    for(int i = 0; i < 10; ++i) { 
        digits.insert(i); 
    }

    for(int num : sequence) {  
        while(num > 0) {  
            digits.erase(num % 10);  
            num /= 10;  
        }
    }

    cout << "Цифры, которые не встречаются в двузначных числах заданной последовательности:" << endl;
    for(set<int>::iterator it = digits.begin(); it != digits.end(); ++it){  // цикл для перебора и вывода цифр, которые не встречаются
        cout << *it << " ";  
    }

    cout << endl;  

    return 0;  
}