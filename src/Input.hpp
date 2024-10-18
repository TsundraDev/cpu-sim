#ifndef __CPU_SIM__INPUT_HPP__
#define __CPU_SIM__INPUT_HPP__

#include "BaseBlock.hpp"
#include <vector>

template<typename T>
class Input {
private:
  BaseBlock* m_source;
  T          m_val;

public:
  Input(BaseBlock* source, T val) :
    m_source(source),
    m_val(val) {}

  ~Input() {}

  void       setSource(BaseBlock* source) { m_source  = source; }
  BaseBlock* getSource()                  { return m_source; }

  T    get()      { return m_val; }
  void set(T val) { m_val = val; }
};

template<typename T>
class Output {
private:
  std::vector<BaseBlock*> m_dest;
  T                       m_val;

public:
  Output(T val) :
    m_dest(std::vector<BaseBlock*>()),
    m_val(val) {}

  ~Output() {}

  void                    addDestination(BaseBlock* dest) { m_dest.push_back(dest); }
  std::vector<BaseBlock*> getDestination()                { return m_dest; }

  T    get()      { return m_val; }
  void set(T val) { m_val = val; }
};

#endif
