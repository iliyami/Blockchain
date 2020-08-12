#include "Blockchain.h"

int main()
{
    Blockchain BlockChain;

    Transaction T1("Alice", "Bob", 0.0000007);

    Block block(T1, BlockChain.get_BlockChain()[BlockChain.get_BlockChain().size() - 1].get_PrevHash(), BlockChain.get_BlockChain().size(), 2);
    
    BlockChain.AddBlock(block);
}