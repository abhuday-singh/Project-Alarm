#include <iostream>
#include<time.h>
#include <windows.h>
#include <MMSystem.h>

using namespace std;

    int main()
    {
        int i=0,j=0,k=0,a,b,c;


        time_t now = time(0);
        tm *ltn = localtime(&now);

        int h1=ltn->tm_hour;
        int m1=ltn->tm_min;
        int s1=ltn->tm_sec;
        int mi=m1+1;
        system("cls");

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

               if(i==h1&&j==mi&&k==s1)
               {
                for(int l=0;l<100;l++)
                {

                  PlaySound(TEXT("alarm.wav"),NULL,SND_LOOP|SND_ASYNC);


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

    label:
        return 0;

    }
