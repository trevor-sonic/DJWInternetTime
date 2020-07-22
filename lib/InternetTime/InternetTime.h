#ifndef INTERNET_TIME_H
#define INTERNET_TIME_H

#include <Arduino.h>

// ----- Callback function types -----
extern "C"
{
	typedef void (*callbackFunction)(void);
}

class InternetTime
{
private:
    // Time setup
    int _timezone = 0 * 3600; // 0 is London
    int _dst = 0;
    callbackFunction _completionFunc = NULL;

public:
    InternetTime(/* args */);
    virtual ~InternetTime();

    void setup(callbackFunction completionFunc);
    String currentTime();
    InternetTime &timeZone(int zone);
    InternetTime &dst(int dst);

};


#endif