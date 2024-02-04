#include "Chunk.hpp"

Chunk::Chunk() {
    Blocks = new Block **[CHUNK_SIZE];
    for (int i = 0; i < CHUNK_SIZE; i++) {
        Blocks[i] = new Block *[CHUNK_SIZE];
        for (int j = 0; j < CHUNK_SIZE; j++) {
            Blocks[i][j] = new Block[CHUNK_SIZE];
        }
    }
}

Chunk::~Chunk() {
    for (int i = 0; i < CHUNK_SIZE; i++) {
        for (int j = 0; j < CHUNK_SIZE; j++) {
            delete[] Blocks[i][j];
        }
        delete[] Blocks[i];
    }
    delete[] Blocks;
}
