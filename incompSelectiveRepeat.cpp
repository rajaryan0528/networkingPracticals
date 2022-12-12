#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define _USE_MATH_DEFINES
void transmission(ll &i, ll &m, ll &tf, ll &tt)
{
    int unsent=0;
    while (i <= tf)
    {
        int z = 0;
        int k;
        for (k = i; k < i + m && k <= tf; k++) // sending frames in the buffer
        {
            cout << "Sending Frame " << k << "..." << endl;
            tt++; // total count
        }
        for (int k = i; k < i + m && k <= tf;k++)
        {
            double param=rand() *M_PI / 180;
            double f = sin(param); // rand is defined in cstdlib  ,range=[0,RAND_MAX) ,timer
            if (f>0.49999 || f<-0.49999)
            {
                cout << "Ack received  for Frame " << k << "..." << endl;
                z++;
            }
            else
            {
                cout<<"NAck received for Frame"<<k<<endl;
                cout << "Retransmitting the frame" <<k<< endl;
                break;

            }            
        }
        i=i+m;
    }
}

int main()
{
    ll totalFrames, m, total = 0;
    srand(time(NULL));
    cout << "Enter the Total number of frames : ";
    cin >> totalFrames;
    cout << "Enter the Window Size : ";
    cin >> m;
    ll i = 1;
    transmission(i, m, totalFrames, total);
    cout << "Total number of frames which were sent and resent are : " << total << endl;
    return 0;
}