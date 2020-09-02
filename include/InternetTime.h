//
//  DJWInternetTime
//  Created by DejaWorks on 22/07/2020.
//  Copyright © 2020 dejaWorks. All rights reserved.
//

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
		String now();
    String currentTime();
    InternetTime &timeZone(int zone);
    InternetTime &dst(int dst);
		boolean isBefore(String timeStr);
		boolean isAfter(String timeStr);
		boolean isBefore(String yearStr, String monthStr, String dayStr, String hourStr, String minuteStr);
		boolean isAfter (String yearStr, String monthStr, String dayStr, String hourStr, String minuteStr);

};


#endif
