#ifndef __CPU_SIM__BASE__BLOCKIO_HPP__
#define __CPU_SIM__BASE__BLOCKIO_HPP__

#include <base/BaseBlock.hpp>

#include <vector>

template<typename T>
class BlockInput {
private:
  BaseBlock* m_source;
  T          m_val;

public:
  BlockInput(T val) :
    m_source(nullptr),
    m_val(val) {}

  ~BlockInput() {}

  void       setSource(BaseBlock* source) { m_source  = source; }
  BaseBlock* getSource()                  { return m_source; }

  T    get()      { return m_val; }
  void set(T val) { m_val = val; }
};

template<typename T>
class BlockOutput {
private:
  std::vector<BaseBlock*> m_dest;
  T                       m_val;

public:
  BlockOutput(T val) :
    m_dest(std::vector<BaseBlock*>()),
    m_val(val) {}

  ~BlockOutput() {}

  void                    addDestination(BaseBlock* dest) { m_dest.push_back(dest); }
  std::vector<BaseBlock*> getDestination()                { return m_dest; }

  T    get()      { return m_val; }
  void set(T val) { m_val = val; }

  void send(Agent* sender, uint64_t tick) {
    T* send_data = new T;
    *send_data = m_val;
    for (uint64_t i = 0; i < m_dest.size(); i++) {
      sender->createEvent(Event(tick, sender, m_dest[i], (uint8_t*)send_data, sizeof(m_val)));
    }
  }

};

#endif
