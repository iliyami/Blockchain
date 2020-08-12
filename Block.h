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
    int nonce;
    // NOOOOOOOOOOOOOOOOOOOONCe
public:
    Block(Transaction, size_t, int);
    int get_Difficulty();
    int get_index();
    int get_nonce();
    size_t GenerateHash();
};
#endif

Block::Block(Transaction UserTransaction, size_t PrevHash, int index)
{
    transaction = UserTransaction;
    Current_hash = GenerateHash();
    Previous_hash = PrevHash;
    this->index = index;
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
    transaction.get_Difficulty();
}

int Block::get_nonce()
{
    return nonce;
}

