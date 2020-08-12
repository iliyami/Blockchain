#ifndef Block_H
#define Block_H
#include "Transaction.h"
#include <ctime>

class Block
{
private:
    size_t Current_hash;
    size_t Previous_hash;
    Transaction transaction;
    int index;
    int Difficulty;
    size_t nonce;
    // NOOOOOOOOOOOOOOOOOOOONCe
public:
    Block(Transaction &, size_t, int, int);
    int get_Difficulty();
    int get_index();
    int get_nonce();
    size_t get_PrevHash();
    size_t GenerateHash();
    void set_nonce(size_t);
    bool POW();
    bool DigitChecker(string);
};
#endif

Block::Block(Transaction &UserTransaction, size_t PrevHash, int index, int Diff)
{
    transaction = UserTransaction;
    Current_hash = GenerateHash();
    Previous_hash = PrevHash;
    this->index = index;
    Difficulty = Diff;
}

size_t Block::GenerateHash()
{
    string ToHash = to_string(transaction.get_Amount()) + transaction.get_SenderKey() + transaction.get_ReceiverKey() + transaction.get_Timestamp() + to_string(Previous_hash);
    
    hash <string> DataHash; 
    hash <string> PrevHash;
    
    // struct DataPrevHashes
    // {
    //     size_t CurrentHash;
    //     size_t PrvHash;
    // }data;
    // data.CurrentHash = DataHash(ToHash);
    // data.PrvHash = PrevHash(to_string(Previous_hash));
    // Previous_hash = PrevHash(to_string(Previous_hash));

    return DataHash(ToHash);
}

int Block::get_index()
{
    return index;
}

int Block::get_Difficulty()
{
    return Difficulty;
}

int Block::get_nonce()
{
    return nonce;
}

void Block::set_nonce(size_t nonce)
{
    this->nonce = nonce;
}

size_t Block::get_PrevHash()
{
    return Previous_hash;
}

bool Block::DigitChecker(string Guess)
{
    for (int i = 0; i < Difficulty - 1; i++)
    {
        if (Guess[i] != '0')
        {
            return false;
        }
    }
    return true;
}

bool Block::POW()
{
    bool AccessGrant = false;
    do
    {
        string GuessStr;
        nonce = rand();
        hash <string> Guess;
        GuessStr = Guess(to_string(nonce) + to_string(Previous_hash) + to_string(Current_hash) + transaction.AllToString());
        if (DigitChecker(GuessStr) == true)
        {
            AccessGrant = true;
        }
        
    } while (AccessGrant == false);
    return true;
}


