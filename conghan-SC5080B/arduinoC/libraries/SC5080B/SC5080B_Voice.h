#ifndef SC5080B_VOICE_H
#define SC5080B_VOICE_H

#include <Arduino.h>

class SC5080B_Voice
{
    public:
    SC5080B_Voice(uint8_t s,uint8_t b);
    void init();
    void speakVoiceWord(int num);
    void speakVoiceNumber(int num);

    private:
    int _data;
    int _busy;
};
#endif