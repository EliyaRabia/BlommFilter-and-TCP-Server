CXX = g++
CXXFLAGS = -Wall -sdt=c++11
SRCS = Main.cpp App.cpp ConsoleMenu.cpp OptionMenu.cpp Options.cpp Option1.cpp Option2.cpp TcpClient.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = my_program
all: $(EXEC)
$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) $(EXEC) -o $(OBJS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f *.o $(EXEC)