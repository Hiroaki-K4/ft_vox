#include "Block.hpp"

Block::Block() {
    std::cout << "Constructor of Block class" << std::endl;
}

Block::~Block() {
    std::cout << "Destructor of Block class" << std::endl;
}

bool Block::is_active() {
    return block_active;
}

void Block::set_active(bool active) {
    block_active = active;
}
