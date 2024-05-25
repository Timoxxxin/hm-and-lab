#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{
    string sentence, max_word, razdel = "!?,.:;- "; // Объявляем переменные типа строка: sentence (введённое предложение), max_word (самое длинное слово), razdel (строка с разделителями)
    cout << "Sentence: "; 
    getline(cin, sentence); // Считываем введённое предложение

    sentence += "."; // Во избежании ошибки, добавляем в конце точку автоматически

    string::size_type position = 0, end; // Объявляем переменные для хранения позиции начала и конца слова
    int max = 0; // Переменная для хранения длины самого длинного слова
    end = sentence.find_first_of(razdel); // Находим позицию первого разделителя в предложении

    while (end != string::npos) // Пока не достигнут конец строки
    {
        string word = sentence.substr(position, end - position); // Выделяем текущее слово из предложения

        if (word.length() > max) // Если длина текущего слова больше длины текущего максимального слова ->
        {
            max = word.length(); // То обновляем значение максимальной длины слова и 
            max_word = word; // Запоминаем текущее слово как самое длинное
        }

        if (ispunct(sentence[end])) // Если символ в конце слова - знак пунктуации то ->
        {
            position = end + 2; // Переходим к следующему символу после знака пунктуации
        }
        else 
        {
            position = end + 1; // Переходим к следующему символу после конца слова
        }

        end = sentence.find_first_of(razdel, position); // Находим позицию следующего разделителя в предложении
    }

    cout << "Result: " << max_word; // Выводим результат - самое длинное слово
    return 0; 
}
