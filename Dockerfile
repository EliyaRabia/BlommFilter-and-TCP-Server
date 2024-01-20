
FROM gcc:latest

WORKDIR /usr/src/ex1

COPY ./src/ .

RUN g++ -o ex1 ./Main.cpp ./App.cpp ./ConsoleMenu.cpp ./OptionMenu.cpp ./Options.cpp ./Option1.cpp ./Option2.cpp

CMD ["./ex1"] 
