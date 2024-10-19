#include "WireBlock.hpp"

#include <cstdio>
#include <cstdlib>

WireBlock::WireBlock(EventQueue* event_queue) :
  BaseBlock(event_queue) {}

WireBlock::~WireBlock() {

}

void WireBlock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  this->updateInput(src, data, size);
  this->updateBlock();
  this->updateOutput();
}

void WireBlock::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  fprintf(stderr, "Unimplemented WireBlock::updateInput\n");
  exit(1);
}

void WireBlock::updateBlock() {
  fprintf(stderr, "Unimplemented WireBlock::updateBlock\n");
  exit(1);
}

void WireBlock::updateOutput() {
  fprintf(stderr, "Unimplemented WireBlock::updateOutput\n");
  exit(1);
}
