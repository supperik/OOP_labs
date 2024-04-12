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
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <float.h>

const std::string inputValueError = "Value Error: Readed invalid string: ";
const std::string inputValueLimitsError = "Value Error: Enter smaller number than last. Max length of number: ";

std::vector<float> recordData(std::istream& input)
{
    std::vector<float> vector;
    std::string stringValue;
    float value = 0;

    while (input >> value)
    {
        try
        {
            vector.push_back(value);
        }
        catch (std::exception &e)
        {
            std::cerr << inputValueError << &e;
        }
    }

    return vector;
}

void divideVectorElemsOnHalfOfMaxElemInVector(std::vector<float>& nums)
{
    std::cout << (*std::max_element(nums.begin(), nums.end()) / 2) << '\n';
    for (float num: nums)
    {
        num = num / (*std::max_element(nums.begin(), nums.end()) / 2);

        std::cout << num << ' ';
    }
    std::cout << '\n';
}

void PrintSortedVector(std::vector<float> vector, std::ostream& output)
{
    std::sort(vector.begin(), vector.end());
    output << std::fixed << std::setprecision(2);
    for (int i = 0; i < vector.size(); i++)
    {
        output << vector[i];
        if (i != vector.size() - 1)
        {
            output << " ";
        }
    }
}

int main()
{
    std::vector<float> nums = recordData(std::cin);
    divideVectorElemsOnHalfOfMaxElemInVector(nums);
    PrintSortedVector(nums, std::cout);

    return 0;
}