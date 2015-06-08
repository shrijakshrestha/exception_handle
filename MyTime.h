#ifndef MyTime_H
#define MyTime_H

using namespace std;

class MyTime{
  private:
    int hour;
    int minute;
    int second;

  public:

    MyTime(int,int,int);
    MyTime();

    void setTime(int,int,int);
    int getHour();
    int getMinute();
    int getSecond();

    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    string toString();

    MyTime nextSecond();
    MyTime nextMinute();
    MyTime nextHour();

    MyTime previousSecond();
    MyTime previousMinute();
    MyTime previousHour();
};
#endif // MyTime_H

