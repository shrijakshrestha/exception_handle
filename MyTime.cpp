
#include <iostream>
#include "MyTime.h"
#include "OutOfRangeException.h"
#include <sstream>

using namespace std;

MyTime::MyTime()
{
}

MyTime::MyTime(int hour, int minute, int second)
{
    setTime(hour,minute,second);
}

void MyTime::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

int MyTime::getHour()
{
    return hour;
}

int MyTime::getMinute()
{
    return minute;
}

int MyTime::getSecond()
{
    return second;
}

void MyTime::setHour(int hour)
{
    if(hour>=0 && hour <=23)
    {
        this->hour = hour;
    }
    else
    {
        throw OutOfRangeException ("PLASE ENTER AGAIN.  ENTERED HOUR OUT OF RANGE");
    }
}

void MyTime::setMinute(int minute)
{
    if(minute>=0 && minute<=59)
    {
        this->minute = minute;
    }
    else
    {
        throw OutOfRangeException ("PLASE ENTER AGAIN. ENTERED MINUTE OUT OF RANGE");
    }
}

void MyTime::setSecond(int second)
{
    if(second>=0 && second<=59)
    {
        this->second = second;
    }
    else
    {
        throw OutOfRangeException ("PLASE ENTER AGAIN. ENTERED SECOND OUT OF RANGE");
    }
}

string MyTime::toString()
{
    stringstream hour, minute, second;
    hour << getHour();
    minute << getMinute();
    second << getSecond();

    return  hour.str() + ":" + minute.str() + ":" + second.str();
}

MyTime MyTime::nextSecond()
{
    if(++second == 60)
    {
        setSecond(0);
        minute++;

        if(minute == 60)
            setMinute(0);
            hour++;

        if(hour == 24)
            setHour(0);
    }
    else
        setSecond(second++);

    return MyTime();
}

MyTime MyTime::nextMinute()
{
    if(++minute == 60)
    {
        setMinute(0);
        hour++;

        if(hour == 24)
            setHour(0);
    }
    else
        setMinute(minute++);

    return MyTime();
}

MyTime MyTime::nextHour()
{
    if(++hour == 24)
    {
        setHour(0);
    }
    else
        setHour(hour++);

    return MyTime();
}

MyTime MyTime::previousSecond()
{
    if(--second == -1)
    {
        setSecond(59);
        minute--;

        if(minute == -1)
            setMinute(59);
            hour--;

        if(hour == -1)
            setHour(23);
    }
    else
        setSecond(second--);

        return MyTime();
}

MyTime MyTime::previousMinute()
{
    if(--minute == -1)
    {
        setMinute(59);
        hour--;
        if(hour == -1)
            setHour(23);
    }
    else
        setMinute(minute--);

    return MyTime();
}

MyTime MyTime::previousHour()
{
    if(--hour == -1)
    {
        setHour(23);
    }
    else
        setHour(hour--);

    return MyTime();
}
