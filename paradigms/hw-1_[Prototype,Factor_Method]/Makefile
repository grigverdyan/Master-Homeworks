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

PROTOTYPE				= prototype
FACTORY_METHOD			= factory_method
CC						= gcc
CXXFLAGS				= -Wall -Wextra -Werror -std=c++23 -g
RM						= rm -rf

PROTOTYPE_FILES			= prototype.c
FACTORY_METHOD_FILES	= factory_method.c

PROTOTYPE_OBJS			= $(PROTOTYPE_FILES:.c=.o)
FACTORY_METHOD_OBJS		= $(FACTORY_METHOD_FILES:.c=.o)

LINKER				= -lstdc++

all : $(FACTORY_METHOD) $(PROTOTYPE) 

$(PROTOTYPE) : $(PROTOTYPE_OBJS)
	@echo $(YELLOW) "  Creating $(PROTOTYPE)" $(RESET)
	@$(CC) $(CXXFLAGS) $(PROTOTYPE_OBJS) $(LINKER) -o $(PROTOTYPE)	

$(FACTORY_METHOD) : $(FACTORY_METHOD_OBJS)
	@echo $(GREEN) "  Creating $(FACTORY_METHOD)" $(RESET)
	@$(CC) $(CXXFLAGS) $(FACTORY_METHOD_OBJS) $(LINKER) -o $(FACTORY_METHOD)	

%.o : %.c
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) $(PROTOTYPE_OBJS) $(FACTORY_METHOD_OBJS)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(PROTOTYPE) $(FACTORY_METHOD)
	@echo $(RED) "  Removing $(PROTOTYPE) and $(FACTORY_METHOD)" $(RESET)

re : fclean all