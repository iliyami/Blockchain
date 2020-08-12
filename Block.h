#ifndef Block_H
#define Block_H
#include <iostream>

using namespace std;

class main
{
private:
    hash <size_t> Current_hash;
    hash <size_t> Previous_hash;
    string Transaction;
    string Timestamp;
    int nonce;
public:
    int difficulty;
    int index;

    
};

#endif