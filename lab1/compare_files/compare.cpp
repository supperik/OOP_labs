#include <string>
#include <fstream>
#include <iostream>

int CompareFiles(std::ifstream& file1, std::ifstream& file2)
{
    char ch1, ch2;
    int line1 = 1;
    int line2 = 1;
    while (file1.get(ch1) && file2.get(ch2))
    {
        if (ch1 != ch2)
        {
            if (ch1 == '\n' || ch2 == '\n')
            {
                return std::max(line1, line2);
            }
            return std::min(line1, line2) + 1;
        }
        if (ch1 == '\n')
        {
            line1++;
        }
        if (ch2 == '\n')
        {
            line2++;
        }
    }

    // Проверка на случай, если один файл короче другого
    if (file1.get(ch1) || file2.get(ch2))
    {
        return std::min(line1, line2) + 1;
    }

    return 0; // Файлы идентичны
}

int main(int argc, char *argv[])
{
    std::ifstream file1(argv[1], std::ifstream::binary);
    std::ifstream file2(argv[2], std::ifstream::binary);

    if (!file1.is_open())
    {
        std::cerr << "Error opening first file." << std::endl;
        return 2; // Ошибка при открытии файлов
    }

    if (!file2.is_open())
    {
        std::cerr << "Error opening second file." << std::endl;
        return 2; // Ошибка при открытии файлов
    }

    if (argc != 3)
    {
        std::cerr << "Usage compare.exe <file1> <file2>" << std::endl;
        return 1; // Ошибка ввода аргументов
    }

    int result = CompareFiles(file1, file2);
    if (result == 0)
    {
        std::cout << "Files are equal" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Files are different. Line number is " << result << std::endl;
        return 1;
    }
}
