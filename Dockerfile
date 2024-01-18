
#FROM gcc:latest

#WORKDIR /usr/src/ex1

#COPY ./src/ .

#RUN g++ -o ex1 ./Main.cpp ./App.cpp ./Console_Menu.cpp ./Option_Menu.cpp ./Option1.cpp ./Option2.cpp

#CMD ["./ex1"] 

FROM ubuntu:latest

# Set the working directory inside the container.
WORKDIR /

# Copy the entire project to the working directory.
COPY . .

# Install necessary dependencies.
RUN apt-get update && \
    apt-get install -y g++ && \
    apt-get install -y libgtest-dev cmake

# Build the C++ code.
RUN cmake -B build -S . && \
    cmake --build build

# Command to run when the container starts.
CMD ["./build/CalcTests"]