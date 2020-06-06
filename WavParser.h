#ifndef OP_LR4_WAVPARSER_H
#define OP_LR4_WAVPARSER_H


#include "WAVFILE.h"

class WavParser {
public:
    void readWav(WAVFILE& myFile, char* fileName);
    void writeWav(WAVFILE& myFile, char* fileName);

};


#endif //OP_LR4_WAVPARSER_H