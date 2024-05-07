// Вариант 2 – RemoveExtraSpaces – 30 баллов
// Разработайте функцию

// std::string RemoveExtraSpaces(std::string const& arg)
// удаляющую из строки, переданной в параметре arg, лишние пробелы. Лишними считаются все пробелы в начале и конце строки, а также дополнительные пробелы между словами.

// Разработайте с ее использованием программу, выполняющую удаление лишних пробелов из каждой строки входного потока символов и вывод результирующих строк в выходной поток.

// Внимание, реализация данной функции должна иметь сложность не более O(N)

#include <string>
#include <vector>
#include "iostream"

std::string RemoveExtraSpaces(std::string const& arg) 
{
    std::string stringWithoutExtraSpaces;
    bool inWord = false;
    for (char c : arg)
    {
        // Если встречаем не пробел то добавляем встреченный символ в новую строку
        if (c != ' ')
        {
            stringWithoutExtraSpaces.push_back(c);
            inWord = true;
        }
        else 
        {
            // Добавляем пробел в новую строку когда встречаем пробел после набора не пробелов
            if (inWord)
            {
                stringWithoutExtraSpaces.push_back(c);
                inWord = false;
            }
        }
    }

    // Удаление пробелов в начале и конце строки
    int end = stringWithoutExtraSpaces.size();
    while (end > 0 && stringWithoutExtraSpaces[end - 1] == ' ') 
    {
        --end;
    }
    stringWithoutExtraSpaces.erase(end);

    int start = 0;
    while (start < stringWithoutExtraSpaces.size() && stringWithoutExtraSpaces[start] == ' ') 
    {
        ++start;
    }
    stringWithoutExtraSpaces.erase(0, start);

    return stringWithoutExtraSpaces;
}

int main()
{
    std::string testString = "   Это    тестовая   строка    ";
    std::string result = RemoveExtraSpaces(testString);
    std::cout << "Исходная строка:52525 '" << testString << "'\n";
    std::cout << "Строка без лишних пробелов: '" << result << "'\n";
    return 0;
}