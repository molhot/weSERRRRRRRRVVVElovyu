NAME = ex01
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

CONF_DIR = srcs/conf
# conに関するsrc
SRSC = $(CONF_DIR)/AllConf.cpp $(CONF_DIR)/LocationConf.cpp $(CONF_DIR)/SameportConf.cpp

# main
SRCS += srcs/main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

${NAME}:${OBJS}
	${CXX} ${OBJS} ${CXXFLAGS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all