#ifndef CHUNK_H
#define CHUNK_H

#include "Block.hpp"

class Chunk {
    public:
        Chunk();
        ~Chunk();
        static const int CHUNK_SIZE = 16;

    private:
        Block ***Blocks;
};

#endif
