//
// cpp_nanotekspice_parser.hpp for cpp_nanotekspice_parser in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Jan 30 13:53:21 2017 Riamon Vincent
// Last update Mon Jan 30 17:01:47 2017 Riamon Vincent
//

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
# define CPP_NANOTEKSPICE_PARSER_HPP

# include <string>
# include <vector>

namespace nts {
  enum class ASTNodeType : int {
    DEFAULT = -1,
    NEWLINE = 0,
    SECTION,
    COMPONENT,
    LINK,
    LINK_END,
    STRING,
  };

  typedef struct s_ast_node {
    s_ast_node(std::vector<struct s_ast_node*> *children)
      : children(children) {}
    std::string lexeme;
    ASTNodeType type;
    std::string value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  class IParser {
  public:
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t_ast_node& root) = 0;
    virtual t_ast_node *createTree() = 0;
    virtual ~IParser() {}
  };
}

#endif //CPP_NANOTEKSPICE_PARSER_HPP
