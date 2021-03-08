#include "SC5080B_Voice.h"

SC5080B_Voice::SC5080B_Voice(uint8_t s, uint8_t b)
{
    this->_data = s;
    this->_busy = b;
}
void SC5080B_Voice::init()
{
    pinMode(this->_data, OUTPUT);
    pinMode(this->_busy, INPUT);
}
void SC5080B_Voice::speakVoiceWord(int num)
{
    digitalWrite(_data, HIGH);
    delay(1);
    digitalWrite(_data, LOW);
    delay(5);
    for (int i = (0); i < 8; i = i + (1))
    {
        digitalWrite(_data, HIGH);
        if (num & 0x01)
        {
            delayMicroseconds(1500);
            digitalWrite(_data, LOW);
            delayMicroseconds(500);
        }
        else
        {
            delayMicroseconds(500);
            digitalWrite(_data, LOW);
            delayMicroseconds(1500);
        }
        num >>= 1;
    }
    digitalWrite(_data, HIGH);
    delayMicroseconds(400);
    while (!digitalRead(_busy));
}
void SC5080B_Voice::speakVoiceNumber(int num)
{
    boolean tmpTmp;
    int tmpNumber, result;
    tmpTmp = false;
    tmpNumber = num;
    tmpNumber = num - (num / 10000) * 10000;
    for (int i = 3; i >= 1; i = i + (-1))
    {
        result = tmpNumber / pow(10, i);
        tmpNumber = tmpNumber - result * pow(10, i);
        if (result)
        {
            speakVoiceWord(result + 12);
            speakVoiceWord(21 + i);
            tmpTmp = true;
        }
        else if (tmpTmp)
        {
            speakVoiceWord(12);
        }
    }
    if (tmpNumber)
    {
        speakVoiceWord(tmpNumber + 12);
    }
}