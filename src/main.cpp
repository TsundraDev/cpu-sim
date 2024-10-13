#include <cstdio>

#include "event-sim.hpp"
#include "BaseBlock.hpp"

int main() {

  printf("cpu-sim\n");
  EventQueue event_queue = EventQueue();
  Clock clock = Clock(&event_queue);

  clock.init();

  event_queue.run();
  return 0;
}
