//
// False.cpp for False in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Tue Jan 31 18:16:26 2017 Riamon Vincent
//

#include "components/False.hpp"

False::False(){
  _val = nts::Tristate::FALSE;
  _links.first = 0;
  _links.second = 0;
  _pin[0] = NULL;
}

False::~False() {
}

nts::Tristate False::compute(size_t this_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl;
      return nts::Tristate::UNDEFINED; // To Do throw
    }
  return _val;
}

void False::setLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; // To Do throw
      return ;
    } else if (_pin[this_pin - 1] == NULL) {
      _pin[this_pin - 1] = &comp;
      _links.first = this_pin - 1;
      _links.second = target_pin;
    }
}

void False::dump(void) const {
  std::cout << "False:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate False::getValue(void) const {
  return _val;
}

std::pair<size_t, size_t> False::getLinks(void) const {
  return _links;
}

void False::setValue(nts::Tristate value) {
  _val = value;
}
