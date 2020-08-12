#ifndef Transaction_H
#define Transaction_H
#include <iostream>

using namespace std;

class Transaction
{
private:
    string SenderKey;
    string ReceivierKey;
    double Amount;
    int Difficulty;
    string Timestamp;
public:
    Transaction(string, string, size_t = 0.0, int = 4);
    string TimeStamp();
    string get_Timestamp();
    string get_SenderKey();
    string get_ReceiverKey();
    int get_Amount();
};
#endif

Transaction::Transaction(string Senderkey, string ReceiverKey, size_t Amount, int Diff)
{
    this->SenderKey = Senderkey;
    this->ReceivierKey = ReceiverKey;
    this->Amount = Amount;
    Timestamp = TimeStamp();

}

string Transaction::TimeStamp()
{
    time_t tt; 
  
    // Declaring variable to store return value of 
    // localtime() 
    struct tm * ti; 
  
    // Applying time() 
    time (&tt); 
  
    // Using localtime() 
    ti = localtime(&tt); 
  
    return asctime(ti); 
}

string Transaction::get_Timestamp()
{
    return Timestamp;
}

string Transaction::get_SenderKey()
{
    return SenderKey;
}

string Transaction::get_ReceiverKey()
{
    return ReceivierKey;
}

int Transaction::get_Amount()
{
    return Amount;
}

