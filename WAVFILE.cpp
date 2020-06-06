#include <cstdint>
#include "WAVFILE.h"


using namespace std;

void WAVFILE::setData() {// инициализируем данные здесь
    myData = new short int[header.subchunk2Size / header.blockAlign];
}

void WAVFILE::changeDuration(int size) {// изменяем длительность

    header.chunkSize = (header.chunkSize - 36) * size + 36;//изменяем chunkSize
    short int* tmpData = new short int[(header.subchunk2Size / header.blockAlign) * size];

    int f = 0;

    for (int i = 0; i < header.subchunk2Size / header.blockAlign; i++) {//изменяем данные
        for (int d = 0; d < size; d++) {
            tmpData[f] = myData[i];
            f++;
        }
    }

    myData = tmpData;
    header.subchunk2Size = header.subchunk2Size * size;//изменяем subchunk2size



}

