#include <iostream>
#include<time.h>
#include <windows.h>
#include <MMSystem.h>
#include<graphics.h>
#include<conio.h>

using namespace std;
class Alarm
{
public:

    void dis()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        system("color F3");
        cout <<"===============================================================\n";
        cout <<"\t\t\t TITAN'S ALARM\n";
        cout <<"---------------------------------------------------------------\n\n";
        cout << "Time : "<< ltm->tm_hour << ":";
        cout << ltm->tm_min << ":";
        cout << ltm->tm_sec;

        char date[9];
        _strdate(date);
	    cout <<"\t\t\t\t\tDate : "<< date << endl;
    }

    int alarm(int x,int y,int z)
    {
        int i=0,j=0,k=0,hr,mi,se,a,c,b;
        hr=x;mi=y;se=z;


        time_t now = time(0);
        tm *ltn = localtime(&now);

        int h1=ltn->tm_hour;
        int m1=ltn->tm_min;
        int s1=ltn->tm_sec;
        system("cls");
        system("color F3");

        for(i=((i>h1)?0:h1);i<24;i++)
        {
          for(j=((j>m1)?0:m1);j<60;j++)
           {

             for(k=((k>s1)?0:s1);k<60;k++)
             {

               Sleep(1000);system("cls");
               cout <<"===============================================================\n";
               cout <<"\t\t\t TITAN'S ALARM\n";
               cout <<"---------------------------------------------------------------\n\n";
               cout<<"Time  "<<i<<":"<<j<<":"<<k;

               char date[9];
               _strdate(date);
	           cout <<"\t\t\t\t\tDate : "<< date << endl;

               if(i==hr&&j==mi&&k==se)
               {
                 for(int l=0;l<100;l++)
                 {

                  PlaySound(TEXT("alarm.wav"),NULL,SND_LOOP|SND_ASYNC);

                  cout<<"\n\n\t\t    !! WAKE UP..WAKE UP !!\n";
                  cout<<"\n\n\t\t\t   ---------\n";
                  cout<<"\t\t\t  |    |    |\n";
                  cout<<"\t\t\t  |    |    |\n";
                  cout<<"\t\t\t  |    .    |\n";
                  cout<<"\t\t\t  |     \\  |\n";
                  cout<<"\t\t\t  |       \ |\n";
                  cout<<"\t\t\t   ---------\n";

                  a=rand();cout<<"\nEnter "<<a<<" to SNOOZE(1 min)\n";
                  b=rand();cout<<"\nEnter "<<b<<" to STOP\n";
                  cin>>c;
                   if(c==a)
                  {
                      system("start check1.exe");
                        exit(0);
                  break;
                  }
                  else if(c==b)
                  {
                      break;
                  }
                  else
                  continue;
                    }

             goto label;





            }
         }
      }

   }


        getch();
        closegraph();
        label:
        return 0;

    }

};

int main()
{
    Alarm obj; obj.dis();
    int hr,mi,se;
    cout<<"\nSet Alarm Time\n";
    cin>>hr>>mi>>se;
    cout<<"\n Alarm Set For "<<hr<<":"<<mi<<":"<<se;
    Sleep(1000);
    obj.alarm(hr,mi,se);

    return 0;
}

