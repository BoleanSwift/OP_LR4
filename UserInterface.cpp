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
    cout << "¬вед≥ть WAV-файл дл€ зчитуванн€ ";
    cin >> inputFile;
    cout << "¬вед≥ть WAV-файл дл€ запису ";
    cin >> outputFile;
    cout << "¬вед≥ть в ск≥льки раз≥в ви хочете розт€гнути файл ";
    cin >> size;
    parser.readWav(myFile, inputFile);
    myFile.changeDuration(size);
    parser.writeWav(myFile, outputFile);
    cout << "–езультат записаний в " << outputFile << endl;
}