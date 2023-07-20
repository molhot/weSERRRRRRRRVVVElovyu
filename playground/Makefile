NAME = webserve
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

CONF_DIR = webserve_tentative/srcs/conf
# conに関するsrc
SRCS = webserve_tentative/srcs/main.cpp $(CONF_DIR)/AllConf.cpp $(CONF_DIR)/LocationConf.cpp $(CONF_DIR)/SameportConf.cpp $(CONF_DIR)/InterpretServerconf.cpp $(CONF_DIR)/InterpretLocationonf.cpp $(CONF_DIR)/HandlingString.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

${NAME}:${OBJS}
	${CXX} ${OBJS} ${CXXFLAGS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all