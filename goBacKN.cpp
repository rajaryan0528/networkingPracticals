#include <bits/stdc++.h>
#include <ctime>
#define ll long long int
using namespace std;

void transmission(ll &i, ll &m, ll &tf, ll &tt)
{
    while (i <= tf)
    {
        int z = 0;
        for (int k = i; k < i + m && k <= tf; k++)    //sending frames in the buffer
        {
            cout << "Sending Frame " << k << "..." << endl;
            tt++;    //total count 
        }
        for (int k = i; k < i + m && k <= tf; k++)
        {
            int f = rand() % 2;   //rand is defined in cstdlib  ,range=[0,RAND_MAX) ,timer
            if (!f)
            {
                cout << "Acknowledgment for Frame " << k << "..." << endl;
                z++;
            }
            else
            {
                cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
                cout << "Retransmitting Window..." << endl;
                break;
            }
        }
        cout << "\n";
        i = i + z;
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