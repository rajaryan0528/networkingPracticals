/*
Cyclic redundancy check (CRC):
error-detecting codes which are additional data added to a given digital message to help us detect if any error has occurred during transmission of the message.
Basic approach used for error detection is the use of redundancy bits, where additional bits are added to facilitate detection of errors.

*/

#include <iostream>

using namespace std;

string XOR(string encoded, string crc) // Bitwise XOR operation
{
    int crclen = crc.length();

    for (int i = 0; i <= (encoded.length() - crclen);)
    {
        for (int j = 0; j < crclen; j++)
        {
            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }
        for (; i < encoded.length() && encoded[i] != '1'; i++)
            ;
    }

    return encoded;
}

int main()
{
    string msg, generator, dividend = "", checksum;
    string copy;
    cout << endl
         << "-----------Sender Side --------------" << endl;
    cout << "Enter Data bits: " << endl;
    cin >> msg;
    copy=msg;
    cout << "Enter Generator polynomial: " << endl;
    cin >> generator;

    dividend += msg;

    int mSize = msg.length();
    int gSize = generator.length();

    for (int i = 0; i < (gSize - 1); i++)
        dividend += '0';
    dividend = XOR(dividend, generator); // performing bitwise xor

    checksum = dividend.substr(mSize);
    cout << "Checksum generated is: " << checksum << endl; // extracts from that position onwards

    msg = msg + checksum;
    cout << "Message to be Transmitted over network: " << msg << endl; // to be sent to the Reciever

    cout << "\n----------------------------------NOISY CHANNEL SIMULATION----------------------------------------\n";
    int nb, pos;
    cout << "Enter Number of Bits to Flip: ";
    cin >> nb;
    if (nb == 0)
        cout << "Codeword Not Changed.\n";
    else
    {
        for (int i = 0; i < nb; i++)
        {
            cout << "Enter Bit Position to Flip: ";
            cin >> pos;

            if(msg[pos - 1] == 0)
                    msg[pos-1]=='1';
            else
                msg[pos-1]='0';
            
        }
    }

    cout << "---------------Reciever Side-----------------" << endl;

    cout << " The message recieved : " << msg << endl;

    msg = XOR(msg, generator); // bitwise xor is performed between recieved bits and the generator bits

    string temp = msg.substr(mSize);

    for (int i = 0; i < temp.length(); i++) // if the crc numbers of are zero then there's no error in transmission
        if (temp[i] != '0')
        {
            cout << "Error in communication " << endl; // if bits not zero ; ERROR IN TRANSMISSION
            return 0;
        }

    cout << "No Error !" << endl;
    return 0;
}