#include "BaseBlock.hpp"
#include <cstdio>
#include <cstdlib>

BaseBlock::BaseBlock(EventQueue* event_queue) :
  Agent(event_queue) {}

BaseBlock::~BaseBlock() {

}

void BaseBlock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  fprintf(stderr, "Unimplemented BaseBlock::recvEvent\n");
  exit(1);
}

void BaseBlock::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  fprintf(stderr, "Unimplemented BaseBlock::updateInput\n");
  exit(1);
}

void BaseBlock::updateBlock() {
  fprintf(stderr, "Unimplemented BaseBlock::updateBlock\n");
  exit(1);
}

void BaseBlock::updateOutput() {
  fprintf(stderr, "Unimplemented BaseBlock::updateOutput\n");
  exit(1);
}

