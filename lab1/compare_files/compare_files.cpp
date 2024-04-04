#include "iostream"
#include "fstream"


using namespace std;

int CompareFiles(ifstream &file1, ifstream &file2) {
    string lineFromFile1;
    string lineFromFile2;
    for (int i = 0; getline(file1, lineFromFile1) && getline(file2, lineFromFile2); i++) {
        if (lineFromFile1 == lineFromFile2);
        else return i;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    string file1String = argv[1];
    string file2String = argv[2];

    if (argc < 2) {return -1;}
    if (file1String.substr(file1String.find_last_of('.') + 1) != "txt" || file2String.substr(file1String.find_last_of('.') + 1) != "txt") {
        cout << "file(s) from arguments extension is not txt" << endl;
        return -1;
    }

    ifstream file1(argv[1]);
    ifstream file2(argv[2]);
    int compareResult = CompareFiles(file1, file2);
    if (compareResult == 0) cout << "Files are equal";
    else cout << "Files are different. Line number is " << compareResult + 1 << endl;
    return 0;
}
