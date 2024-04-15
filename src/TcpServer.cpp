#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "BloomFilter.h"

using namespace std;
int main()
{
    const int server_port = 5555;
    BloomFilter* bloomFilter = new BloomFilter();
    int sock = socket(AF_INET, SOCK_STREAM,0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock,(struct sockaddr*)&sin,sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }
    if (listen(sock,5) < 0)
    {
        perror("error listening to a socket");
    }
    while (true){
        struct sockaddr_in client_sin;
            unsigned int addr_len = sizeof(client_sin);
            int client_sock = accept(sock,(struct sockaddr*)&client_sin,&addr_len);
            if (client_sock <
                0)
            {
                perror("error accepting client");
            }
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(client_sock, buffer, expected_data_len,0);
            while(read_bytes > 0){
                std::string buffer_str(buffer);
                int splitIndex = buffer_str.find(' ');
                std::string choice_str = buffer_str.substr(0, splitIndex);
                std::string url = buffer_str.substr(splitIndex+1);
                
                int choice = std::stoi(choice_str);
                bloomFilter->execute(choice, url);

                int sent_bytes = send(client_sock, buffer, read_bytes,0);
                    if (sent_bytes < 0)
                    {
                        perror("error sending to client");
                    }
            read_bytes = recv(client_sock, buffer, expected_data_len,0);
            }
            if (read_bytes == 0)
            {
                // connection is closed 
            }
                else {
                    // error 
                }
            close(client_sock);
    }
    
    close(sock);
    return 0;
}