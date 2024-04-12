//Задание 1. Основы работы с контейнером vector. 20 баллов
//
//Разработайте программу, выполняющую считывание массива чисел с плавающей запятой, разделяемых пробелами,
//из стандартного потока ввода в vector, обрабатывающую его согласно заданию Вашего варианта и выводящую в стандартный
//поток полученный массив (разделенный пробелами). Значения должны выводиться с точностью 3 знака после запятой.
//В программе должны быть выделены функции, выполняющие считывание массива,
//его обработку (функция обработки вектора значений должна изменять содержимое переданного массива) и вывод результата.
//
//4)Умножить каждый отрицательный элемент массива на произведение
// максимального и минимального элементов исходного массива

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

bool isStringCanBeConvertToDouble(const std::string& str)
{
    bool result = true;
    try
    {
        double d = stod(str);
    }
    catch (const std::invalid_argument& e)
    {
        result = false;
    }
    catch (const std::out_of_range& e)
    {
        result = false;
    }
    return result;
}

std::vector<double> recordData()
{
    std::vector<double> inputData;

    std::istringstream iss;
    std::string inputString;
    std::string stringStreamWord;
    double num;
    bool exitFlag = false;

    while (!exitFlag)
    {
        std::cin >> inputString;
        while(iss >> stringStreamWord)
        {
            if (isStringCanBeConvertToDouble(stringStreamWord))
            {
                num = stod(stringStreamWord);
                inputData.push_back(num);
            }
            else
            {
                std::cout << "Enter string without letter";
            }
            if (stringStreamWord == "/")
            {
                exitFlag = true;
            }
        }
    }
    return inputData;
}

void handleVector(std::vector<double> &nums)
{
    for (double num: nums)
    {
        std::cout << num << ' ';
    }
}

int main()
{
    std::vector<double> nums = recordData();
    handleVector(nums);

    return 0;
}