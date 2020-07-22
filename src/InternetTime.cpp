//
//  DJWInternetTime
//  Created by DejaWorks on 22/07/2020.
//  Copyright © 2020 dejaWorks. All rights reserved.
//

#include <InternetTime.h>

InternetTime::InternetTime()
{
}
InternetTime::~InternetTime() {}

void InternetTime::setup(callbackFunction completionFunc)
{
    _completionFunc = completionFunc;

    configTime(_timezone, _dst, "pool.ntp.org", "time.nist.gov");
    Serial.println("Setup InternetTime ...");

    while (!time(nullptr))
    {
        Serial.print("*");
        delay(1000);
    }

    //Serial.println("\nInternet time OK.");
    if (_completionFunc) {
        _completionFunc();
    }
}
/// 0 is London
InternetTime &InternetTime::timeZone(int zone)
{
    this->_timezone = zone * 3600;
    return *this;
}

/// 0 is London
InternetTime &InternetTime::dst(int dst)
{
    this->_dst = dst;
    return *this;
}
String InternetTime::currentTime()
{
    time_t now = time(nullptr);
    struct tm *p_tm = localtime(&now);

    String formattedTime = "";
    formattedTime += p_tm->tm_year + 1900;
    formattedTime += "/";
    formattedTime += p_tm->tm_mon + 1;
    formattedTime += "/";
    formattedTime += p_tm->tm_mday;

    formattedTime += " ";

    formattedTime += p_tm->tm_hour;
    formattedTime += ":";
    formattedTime += p_tm->tm_min;
    formattedTime += ":";
    formattedTime += p_tm->tm_sec;

    return formattedTime;
}