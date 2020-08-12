#ifndef Blockchain_H
#define Blockchain_H
#include "Block.h"
#include <vector>

class Blockchain
{
private:
    vector <Block> BlockChain;
public:
    Blockchain();
    vector <Block> get_BlockChain();
    void ShowBlockchain();
    void ShowBlock(int);
    void AddBlock(Block &);

};
#endif

Blockchain::Blockchain()
{
    Transaction GenesisTrans("", "", 0.00);
    Block Genesis(GenesisTrans, 0, 0);
    Genesis.set_nonce(0);
    BlockChain.push_back(Genesis);
}

vector <Block> Blockchain::get_BlockChain()
{
    return BlockChain;
}

void Blockchain::AddBlock(Block &block)
{
    if (block.POW() == true)
    {
        BlockChain.push_back(block);
        cout << "Done!" << endl;
    }
    else
    {
        cout << "Invalid Block!" << endl;
    }
    
}