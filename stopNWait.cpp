#include <iostream>
using namespace std;

#define ll long long int


void transmission(ll &i, ll &N, ll &tf, ll &tt)
{
    while (i <= tf)
    {
        cout << "Sending frame...... " << i << endl;
        int f = rand() % 2;
        if (!f)
        {
            cout << "Ack  received for frame " << i << endl;
            tt++;
            i++;
        }
        else
        {
            cout << "Ack lost for  frame  " << i << endl;
            cout << "Resending frame " << i << endl;
            tt++;
        }
    }
}

int main()
{
    ll tf, tt = 0;
    ll N = 1;
    cout << "Enter the no. of frames to be sent: ";
    cin >> tf;
    ll i = 1;
    transmission(i, N, tf, tt);
    cout << "Total frames which were sent and resent: " << tt << endl;
    return 0;
}