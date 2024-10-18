#include "BaseBlock.hpp"
#include <cstdio>
#include <cstdlib>

RegisterBlock::RegisterBlock(Clock* clock) :
  BaseBlock(clock->event_queue()),
  m_clock(clock) {
  clock->addOutput(this);
}

RegisterBlock::~RegisterBlock() {

}

void RegisterBlock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  if (src == m_clock) {
    this->updateBlock();
    this->updateOutput();
  } else {
    this->updateInput(src, data, size);
  }
}

void RegisterBlock::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  fprintf(stderr, "Unimplemented RegisterBlock::updateInput\n");
  exit(1);
}

void RegisterBlock::updateBlock() {
  fprintf(stderr, "Unimplemented RegisterBlock::updateBlock\n");
  exit(1);
}

void RegisterBlock::updateOutput() {
  fprintf(stderr, "Unimplemented RegisterBlock::updateOutput\n");
  exit(1);
}

