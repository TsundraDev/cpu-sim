#ifndef __CPU_SIM__COMPONENTS__CLOCK_HPP__
#define __CPU_SIM__COMPONENTS__CLOCK_HPP__

#include <cstdint>
#include <vector>

#include "event-sim.hpp"
#include <base/BaseBlock.hpp>
#include <base/ClockBlock.hpp>

class Clock : public ClockBlock {
public:
  Clock(EventQueue* event_queue);
  ~Clock();

  void init();
};

#endif
