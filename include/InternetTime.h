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
		String comparableNow(String timeStr);
		
public:
    InternetTime(/* args */);
    virtual ~InternetTime();

    void setup(callbackFunction completionFunc);

		// returns the currentTime in 2012312345 format
		String now();


		// returns the currentTime in 2020/12/31 23:45 format
    String currentTime();

    InternetTime &timeZone(int zone);
    InternetTime &dst(int dst);

		// is given time before or equal
		boolean isBefore(String timeStr);

		// is given time agter or equal
		boolean isAfter(String timeStr);

};


#endif
