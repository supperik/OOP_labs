#include <iostream>
#include <string>

std::string HtmlEncode(std::string const& text) {
    std::string result;
    for (char c : text) {
        switch (c) {
            case '"':
                result += "&quot;";
                break;
            case '\'':
                result += "&apos;";
                break;
            case '<':
                result += "&lt;";
                break;
            case '>':
                result += "&gt;";
                break;
            case '&':
                result += "&amp;";
                break;
            default:
                result += c;
                break;
        }
    }
    return result;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << HtmlEncode(line) << std::endl;
    }
    return 0;
}
