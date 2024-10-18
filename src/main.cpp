#include <cstdio>

#include "event-sim.hpp"
#include "BaseBlock.hpp"
#include "Register.hpp"

int main() {

  printf("cpu-sim\n");
  EventQueue event_queue = EventQueue();
  Clock clock = Clock(&event_queue);

  Register pc = Register(&clock);


  clock.init();

  event_queue.run();
  return 0;
}
