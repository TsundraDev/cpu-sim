#include "BaseBlock.hpp"
#include <cstdio>
#include <cstdlib>

WireBlock::WireBlock(EventQueue* event_queue) :
  BaseBlock(event_queue) {}

WireBlock::~WireBlock() {

}

void WireBlock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  this->update(src, data, size);
}

void WireBlock::update(Agent* src, uint8_t* data, uint64_t size) {
  fprintf(stderr, "Unimplemented WireBlock::update\n");
  exit(1);
}
