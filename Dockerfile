
FROM gcc:latest

WORKDIR /usr/src/ex1

COPY ./src/ .

RUN g++ -o ex1 ./Main.cpp ./App.cpp ./ConsoleMenu.cpp ./OptionMenu.cpp ./IOptions.cpp ./Option1.cpp ./Option2.cpp

CMD ["./ex1"] 
