NAME = webserve
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

CONF_DIR = webserve_tentative/srcs/conf
SOCKET_DIR = webserve_tentative/srcs/makeserver
HTTP_DIR = webserve_tentative/srcs/httphandling

#utils
SRCS = $(CONF_DIR)/HandlingString.cpp

# conに関するsrc
SRCS += $(CONF_DIR)/AllConf.cpp $(CONF_DIR)/LocationConf.cpp $(CONF_DIR)/SameportConf.cpp $(CONF_DIR)/InterpretServerconf.cpp $(CONF_DIR)/InterpretLocationonf.cpp

#socketに関する
SRCS += $(SOCKET_DIR)/makeSockets.cpp $(SOCKET_DIR)/Socket.cpp

#http通信を実際に行うことに関する
SRCS += $(HTTP_DIR)/run.cpp $(HTTP_DIR)/interpret_request.cpp

#main
SRCS += webserve_tentative/srcs/main.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

${NAME}:${OBJS}
	${CXX} ${OBJS} ${CXXFLAGS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all