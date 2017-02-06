//
// NOR-4001.hpp for NOR-4001 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:42:59 2017 Riamon Vincent
//

#ifndef NOR4001_HPP_
# define NOR4001_HPP_

#include "IComponent.hpp"

namespace nts {
  class NOR4001 : public nts::IComponent {
  public:
    NOR4001(nts::Tristate val);
    virtual ~NOR4001();
    virtual nts::Tristate Compute(size_t this_pin = 1);
    virtual void SetLink(size_t this_pin,
			 nts::IComponent& comp,
			 size_t target_pin);
    virtual void Dump(void) const;
    nts::Tristate calcInput(size_t pin);
    nts::Tristate calcOutput(size_t pin);
    nts::Tristate nor_gate(size_t first_pin, size_t second_pin) const;

  private:
    nts::IComponent *_pins[14];
    std::map<size_t, size_t> _links;
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //NOR4001_HPP_
