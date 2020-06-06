#ifndef OP_LR4_HEADER_H
#define OP_LR4_HEADER_H
#include <cstdint>
struct HEADER {//����� wav ����� �������� 44 �����

    int32_t chunkId;   // ������ ������ �������� 0x52494646 (����� "RIFF")
    int32_t chunkSize; // 36 + ����� ������� �������� � ������
    // ������ ������� 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
    // �� ����� ������ ����� ���� 8 ����� �� �������� ���� chunkId �� chunkSize
    int32_t format;
    int32_t subchunk1Id;   // ������ 0x666d7420 � ����� "fmt "
    int32_t subchunk1Size; // ������ 16 ��� ���� PCM. �� ����� ������� ��������, �� ���� ���� ����� �����
    int16_t audioFormat;   // PCM = 1
    int16_t numChannels;   // Mono = 1, Stereo = 2
    int32_t sampleRate;    // ��������� 44100
    int32_t byteRate;      // == SampleRate * NumChannels * BitsPerSample/8
    int16_t blockAlign;    // == NumChannels * BitsPerSample/8
    int16_t bitsPerSample;
    int32_t subchunk2Id;   // 0x64617461 � ����� "data"
    int32_t subchunk2Size; // == NumSamples * NumChannels * BitsPerSample/8, ������� ����� ���������
};
#endif //OP_LR4_HEADER