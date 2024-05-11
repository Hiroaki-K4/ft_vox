#ifndef CHUNK_HPP
#define CHUNK_HPP

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
