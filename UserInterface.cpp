#include "UserInterface.h"
#include <iostream>
#include "WavParser.h"
#include "WAVFILE.h"
using namespace std;

void UserInterface::makeMenu() {
    char* inputFile = new char[100];
    char* outputFile = new char[100];
    int size;
    WavParser parser{};
    WAVFILE myFile{};
    cout << "������ WAV-���� ��� ���������� ";
    cin >> inputFile;
    cout << "������ WAV-���� ��� ������ ";
    cin >> outputFile;
    cout << "������ � ������ ���� �� ������ ���������� ���� ";
    cin >> size;
    parser.readWav(myFile, inputFile);
    myFile.changeDuration(size);
    parser.writeWav(myFile, outputFile);
    cout << "��������� ��������� � " << outputFile << endl;
}