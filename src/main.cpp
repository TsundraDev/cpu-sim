#include <cstdio>
#include <cassert>

#include <event-sim.hpp>
#include <components/Clock.hpp>
#include <components/Register.hpp>
#include <components/UpdatePC.hpp>

int main() {

  printf("cpu-sim\n");

  // Setup devices
  EventQueue event_queue = EventQueue();
  Clock clock = Clock(&event_queue);
  Register pc = Register(&event_queue, &clock);
  UpdatePC update_pc = UpdatePC(&event_queue);

  // Setup PC
  pc.setInput(&update_pc);
  pc.addOutput(&update_pc);

  // Setup UpdatePC
  update_pc.setInput(&pc);
  update_pc.addOutput(&pc);


  clock.init();

  event_queue.run();
  return 0;
}
