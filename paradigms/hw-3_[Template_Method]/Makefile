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

TEMPLATE_METHOD			= template_method
CC						= gcc
CXXFLAGS				= -Wall -Wextra -Werror -std=c++23 -g
RM						= rm -rf

TEMPLATE_METHOD_FILES	= main.c
TEMPLATE_METHOD_OBJS	= $(TEMPLATE_METHOD_FILES:.c=.o)
LINKER					= -lstdc++

all : $(TEMPLATE_METHOD) 

$(TEMPLATE_METHOD) : $(TEMPLATE_METHOD_OBJS)
	@echo $(GREEN) "  Creating $(TEMPLATE_METHOD)" $(RESET)
	@$(CC) $(CXXFLAGS) $(TEMPLATE_METHOD_OBJS) $(LINKER) -o $(TEMPLATE_METHOD)	

%.o : %.c
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) $(TEMPLATE_METHOD_OBJS)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(TEMPLATE_METHOD)
	@echo $(RED) "  Removing $(TEMPLATE_METHOD)" $(RESET)

re : fclean all