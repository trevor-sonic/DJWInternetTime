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
    configTime(_timezone, _dst, "pool.ntp.org", "time.nist.gov", "0.uk.pool.ntp.org");
    Serial.println("Setup InternetTime _");

    int count = 0;
    while (time(nullptr) <= 100000  && count < 60)
    {
        Serial.print(".");
        count += 1;
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
    if(p_tm->tm_mon<9){formattedTime += "0";}
    formattedTime += p_tm->tm_mon + 1;
    formattedTime += "/";
    if(p_tm->tm_mday<10){formattedTime += "0";}
    formattedTime += p_tm->tm_mday;

    formattedTime += " ";

    if(p_tm->tm_hour<10){formattedTime += "0";}
    formattedTime += p_tm->tm_hour;
    formattedTime += ":";
    if(p_tm->tm_min<10){formattedTime += "0";}
    formattedTime += p_tm->tm_min;
    formattedTime += ":";
    if(p_tm->tm_sec<10){formattedTime += "0";}
    formattedTime += p_tm->tm_sec;

    return formattedTime;
}
String InternetTime::now() {
    time_t now = time(nullptr);
    struct tm *p_tm = localtime(&now);
    String year = "";
    String formattedTime = "";
    year += p_tm->tm_year + 1900;
    formattedTime += year.substring(2,4);
    if(p_tm->tm_mon<9){formattedTime += "0";}
    formattedTime += p_tm->tm_mon + 1;
    if(p_tm->tm_mday<10){formattedTime += "0";}
    formattedTime += p_tm->tm_mday;

    if(p_tm->tm_hour<10){formattedTime += "0";}
    formattedTime += p_tm->tm_hour;
    if(p_tm->tm_min<10){formattedTime += "0";}
    formattedTime += p_tm->tm_min;
    // if(p_tm->tm_sec<10){formattedTime += "0";}
    // formattedTime += p_tm->tm_sec;

    return formattedTime;
}
// format the time (now) comparable
String InternetTime::comparableNow(String timeStr){
  String nowOrg = now();
  String nowStr = "";

  String year;
  year = timeStr.substring(0,2);
  if(year == "00"){
    nowStr += "00";
  }else{
    nowStr += nowOrg.substring(0,2);
  }

  String month;
  month = timeStr.substring(2,4);
  if(month == "00"){
    nowStr += "00";
  }else{
    nowStr += nowOrg.substring(2,4);
  }

  String day;
  day = timeStr.substring(4,6);
  if(day == "00"){
    nowStr += "00";
  }else{
    nowStr += nowOrg.substring(4,6);
  }

  String hour;
  hour = timeStr.substring(6,8);
  nowStr += nowOrg.substring(6,8);

  String minute;
  minute = timeStr.substring(8,10);
  nowStr += nowOrg.substring(8,10);

  return nowStr;
}

// timeStr format like 2012251830 (6:30pm)
boolean InternetTime::isBefore(String timeStr){
  String nowStr = comparableNow(timeStr);

  if(timeStr <= nowStr){
    return true;
  }
  return false;
}
// timeStr format like 2012251830 (6:30pm)
boolean InternetTime::isAfter(String timeStr){

  String nowOrg = now();
  String nowStr = "";

  String year;
  year = timeStr.substring(0,2);
  if(year == "00"){
    nowStr += "00";
  }else{
    nowStr += nowOrg.substring(0,2);
  }

  String month;
  month = timeStr.substring(2,4);
  if(month == "00"){
    nowStr += "00";
  }else{
    nowStr += nowOrg.substring(2,4);
  }

  String day;
  day = timeStr.substring(4,6);
  if(day == "00"){
    nowStr += "00";
  }else{
    nowStr += nowOrg.substring(4,6);
  }

  String hour;
  hour = timeStr.substring(6,8);
  nowStr += nowOrg.substring(6,8);

  String minute;
  minute = timeStr.substring(8,10);
  nowStr += nowOrg.substring(8,10);

  if(timeStr >= nowStr){
    return true;
  }
  return false;

}
