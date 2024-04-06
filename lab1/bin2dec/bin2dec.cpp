#include <iostream>
#include <string>

bool IsValidBinary(const std::string& binaryString) {
    int len = binaryString.size();
    if (len > 32 || len == 0) return false;
    for (char bit : binaryString) {
        if (bit != '0' && bit != '1') {
            return false;
        }
    }
    return true;
}

unsigned int BinaryToDecimal(const std::string& binaryString) {
    unsigned int decimalNumber = 0;
    int length = binaryString.length();

    for (int i = 0; i < length; i++) {
        int digit = binaryString[i] - '0';

        decimalNumber += digit * (1U << (length - i - 1));
    }

    return decimalNumber;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <Binary number>" << std::endl;
        return 1;
    }

    std::string binaryString = argv[1];

    if (!IsValidBinary(binaryString)) {
        std::cerr << "Error: Recieved invalid binary number." << std::endl;
        return 1;
    }

    unsigned int decimalNumber = BinaryToDecimal(binaryString);

    std::cout << decimalNumber << std::endl;

    return 0;
}
