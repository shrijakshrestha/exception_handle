#include <iostream>
# include "MyTime.h"
# include "OutOfRangeException.h"

using namespace std;

int main()
{
    int hour,minute,second,option;
    int flag=0;
    char requireTime;
    MyTime time;

    cout << "Enter hour minute and second: " << endl;

    while(cin>>hour>>minute>>second)
    {
        try{
            time.setTime(hour,minute,second);
            break;
        }

        catch(OutOfRangeException &outOfRangeException)
        {
            cout << "Exception occurred - " << outOfRangeException.what() << endl;
        }

        cout << "Enter hour minute and second: \n";
    }


while(flag==0)
{
    cout<< "\n\n\n\noptions:\n1.exit\n2. get hour\n3.get minute\n4.get second\n5.get time\n6.next sec\n7.next minute\n8.nest hour\n9.previous sec\n10.previous minute\n11.previous hour\n ";
    cin>>option;
    switch(option)
    {

    case 1:
        flag=1;
        break;
    case 2:
        cout<<"hour:"<<time.getHour();
        break;
    case 3:
        cout<<"minute:"<<time.getMinute();
        break;
    case 4:
         cout<<"second:"<<time.getSecond();
         break;
    case 5:
        cout<<time.toString();
        break;
    case 6:
            time.nextSecond();
            cout << "After one second, time is -> " << time.toString() << endl;
            break;
    case 7:
          time.nextMinute();
          cout << "After one minute, time is -> " << time.toString() << endl;
          break;

    case 8:
        time.nextHour();
        cout << "After one hour, time is -> " << time.toString() << endl;
        break;

    case 9:
        time.previousSecond();
        cout << "Before one second, time was -> " << time.toString() << endl;
        break;
    case 10:
         time.previousMinute();
        cout << "Before one minute, time was -> " << time.toString() << endl;
         break;
    case 11:
        time.previousHour();
        cout << "Before one hour, time was -> " << time.toString() << endl;
        break;

    default:
        cout<<"invalid input. try again";

}


    }
}


