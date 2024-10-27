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

TARGET			= interprter
CC				= gcc
CXXFLAGS		= -Wall -Wextra -Werror -std=c++23 -g
RM				= rm -rf

TARGET_FILES	= main.c
TARGET_OBJS	= $(TARGET_FILES:.c=.o)
LINKER			= -lstdc++

all : $(TARGET) 

$(TARGET) : $(TARGET_OBJS)
	@echo $(GREEN) "  Creating $(TARGET)" $(RESET)
	@$(CC) $(CXXFLAGS) $(TARGET_OBJS) $(LINKER) -o $(TARGET)	

%.o : %.c
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) $(TARGET_OBJS)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(TARGET)
	@echo $(RED) "  Removing $(TARGET)" $(RESET)

re : fclean all