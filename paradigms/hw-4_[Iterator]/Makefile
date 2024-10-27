# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

.PHONY : all clean fclean re

ITERATOR				= iterator
CC						= gcc
CXXFLAGS				= -Wall -Wextra -Werror -std=c++23 -g
RM						= rm -rf

ITERATOR_FILES	= main.c
ITERATOR_OBJS	= $(ITERATOR_FILES:.c=.o)
LINKER			= -lstdc++

all : $(ITERATOR) 

$(ITERATOR) : $(ITERATOR_OBJS)
	@echo $(GREEN) "  Creating $(ITERATOR)" $(RESET)
	@$(CC) $(CXXFLAGS) $(ITERATOR_OBJS) $(LINKER) -o $(ITERATOR)	

%.o : %.c
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) $(ITERATOR_OBJS)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(ITERATOR)
	@echo $(RED) "  Removing $(ITERATOR)" $(RESET)

re : fclean all