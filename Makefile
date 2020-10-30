##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	g++ -o

RM	=	rm -f

GATE_PATH = src/Gate/

ERRORS_PATH = src/Error/

PARSE_PATH	=	src/Parser/

COMPONENT_PATH = src/Component/

GATE		=	$(GATE_PATH)Nand.cpp					\
				$(GATE_PATH)nor.cpp						\
				$(GATE_PATH)Xor.cpp						\
				$(GATE_PATH)Or.cpp						\
				$(GATE_PATH)And.cpp						\
				$(GATE_PATH)IGate.cpp					\
				$(GATE_PATH)Inverted.cpp				\

ERRORS		=	$(ERRORS_PATH)ChipsetError.cpp			\
				$(ERRORS_PATH)ComponentError.cpp		\
				$(ERRORS_PATH)Errors.cpp				\
				$(ERRORS_PATH)FileError.cpp				\
				$(ERRORS_PATH)InputError.cpp			\
				$(ERRORS_PATH)LinkError.cpp				\
				$(ERRORS_PATH)OutputError.cpp			\
				$(ERRORS_PATH)PinError.cpp				\

COMPONENT	=	$(COMPONENT_PATH)Link.cpp				\
				$(COMPONENT_PATH)Component4001.cpp		\
				$(COMPONENT_PATH)Component4011.cpp		\
				$(COMPONENT_PATH)Component4030.cpp		\
				$(COMPONENT_PATH)Component4071.cpp		\
				$(COMPONENT_PATH)Component4081.cpp		\
				$(COMPONENT_PATH)Component4069.cpp		\
				$(COMPONENT_PATH)Input.cpp				\
				$(COMPONENT_PATH)Output.cpp				\
				$(COMPONENT_PATH)Clock.cpp				\
				$(COMPONENT_PATH)True.cpp				\
				$(COMPONENT_PATH)False.cpp				\

PARSE		=	$(PARSE_PATH)Parse.cpp					\
				$(PARSE_PATH)Circuit.cpp				\

SRC	=	src/main.cpp	\
		$(GATE)			\
		$(COMPONENT)	\
		$(ERRORS)		\
		$(PARSE)		\
		src/Factory.cpp	\

OBJ	=	$(SRC:.cpp=.o)

LIB	=	-L./lib/ -lmy

CFLAGS	=	-I./include/ -I./include/Component -I./include/Gate -I./include/Error/ -I./include/Parser/

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(NAME) $(OBJ) -I./include/ -I./include/Component -I./include/Gate

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

%.o:	%.cpp
	g++ -c -o $@ $< $(CFLAGS)

re:	fclean all