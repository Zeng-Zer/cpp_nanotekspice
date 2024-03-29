##
## Makefile :D
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Tue Feb  7 22:10:47 2017 Riamon Vincent
##

NAME:=		nanotekspice
SRCDIR:=	src/
INCLUDE:=	include/ \
		lib/include \
		lib/include/components \
		lib/include/gates \

SRC:=		main.cpp \
		Nts.cpp \
		Parser.cpp \
		Circuit.cpp \
		Shell.cpp \

LIB:=		libnanotekspice.a

CXX:=		g++
CXXFLAGS:=	-W -Wall -Wextra -g -std=c++14
LDFLAGS:=	-L./ -lnanotekspice
SRC:=		$(addprefix $(SRCDIR), $(SRC))
OBJ:=		$(SRC:.cpp=.o)
RM:=		rm -f

TEST:=		test_nanotekspice
TESTSRC:=	$(filter-out src/main.cpp, $(SRC))
TESTSRC +=	test/main.cpp
TESTOBJ:=	$(TESTSRC:.cpp=.o)

DEFAULT:=	"\033[00;0m"
GREEN:=		"\033[0;32;1m"
RED:=		"\033[0;31;1m"
CYAN:=		"\033[0;36;1m"

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS) && \
		echo -e $(GREEN)"[BIN]"$(CYAN) $(NAME)$(DEFAULT) || \
		echo -e $(RED)"[XX]"$(DEFAULT) $(NAME)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

$(LIB):
	make -C ./lib/

$(TEST): $(TESTOBJ)
	$(CXX) -o $(TEST) $(TESTOBJ) $(CXXFLAGS) $(LDFLAGS) && \
		echo -e $(GREEN)"[BIN]"$(CYAN) $(TEST)$(DEFAULT) || \
		echo -e $(RED)"[XX]"$(DEFAULT) $(TEST)

test: $(LIB) $(TEST)
	echo -e $(GREEN)"\nUNIT TESTS"$(DEFAULT)
	./$(TEST)
	rm -f $(TEST)

clean:
	make clean -C ./lib/
	echo -e $(CYAN)"Cleaning $(NAME) tmp files..." $(DEFAULT)
	$(RM) $(OBJ) $(TESTOBJ)

fclean:	clean
	make fclean -C ./lib/
	echo -e $(CYAN)"Cleaning $(NAME) executable..." $(DEFAULT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re test $(TEST)

.cpp.o:
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(foreach dir, $(INCLUDE), -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<
