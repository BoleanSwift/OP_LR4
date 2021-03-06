#include "WavParser.h"
#include "WAVFILE.h"
#include <cstdio>
#include <iostream>

using namespace std;

void WavParser::readWav(WAVFILE& myFile, char* fileName) {//��������� wav ����
    FILE* input;
    errno_t err;
    err = fopen_s(&input, fileName, "rb");
    if (err) cout << "��������� ������� ���� ��� ����������\n";
    else {
        fread_s(&myFile.header, sizeof(myFile.header), sizeof(myFile.header), 1, input);//��������� �����
        myFile.setData();

        for (int i = 0; i < myFile.header.subchunk2Size / myFile.header.blockAlign; i++) {
            fread(&myFile.myData[i], myFile.header.blockAlign, 1, input);//��������� ������
        }
    }
    fclose(input);
}

void WavParser::writeWav(WAVFILE& myFile, char* fileName) {
    FILE* output;
    errno_t err;
    err = fopen_s(&output, fileName, "wb");
    if (err) cout << "��������� ������� ���� ��� ������\n";
    else {
        fwrite(&myFile.header, sizeof(myFile.header), 1, output);//���������� �����
        for (int i = 0; i < myFile.header.subchunk2Size / myFile.header.blockAlign; i++) {
            fwrite(&myFile.myData[i], myFile.header.blockAlign, 1, output);//���������� ������
        }
    }
    fclose(output);

}