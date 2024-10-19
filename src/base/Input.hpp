#ifndef __CPU_SIM__INPUT_HPP__
#define __CPU_SIM__INPUT_HPP__

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
};

#endif
