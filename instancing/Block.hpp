#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

enum BlockType {
    BlockType_Default = 0,
    BlockType_Grass,
    BlockType_Dirt,
    BlockType_Water,
    BlockType_Stone,
    BlockType_Wood,
    BlockType_Sand,
    BlockType_NumTypes,
};

class Block {
    public:
        Block();
        ~Block();
        bool is_active();
        void set_active(bool active);

    private:
        bool block_active;
        BlockType block_type;
};

#endif
