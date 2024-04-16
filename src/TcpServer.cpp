#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include "BloomFilter.h"

using namespace std;

// void initialize_client(int client_sock, BloomFilter* bloomFilter){
//     char buffer[4096];
//     int expected_data_len = sizeof(buffer) - 1; // Leave space for null terminator
//     std::string buffer_str;
//     int read_bytes;

//     // Keep reading data until we have a complete message
//     size_t newline_pos;
//     do {
//         read_bytes = recv(client_sock, buffer, expected_data_len, 0);
//         if(read_bytes > 0){
//             buffer[read_bytes] = '\0'; // Null-terminate the data
//             buffer_str += buffer; // Append data to buffer_str
//         }
//         newline_pos = buffer_str.find('\n');
//     } while(read_bytes > 0 && newline_pos == std::string::npos);

//     // Process the complete message
//     if(newline_pos != std::string::npos) {
//         std::string message = buffer_str.substr(0, newline_pos);
//         buffer_str = buffer_str.substr(newline_pos + 1);
//         int splitIndex1 = message.find(' ');
//         std::string size = message.substr(0, splitIndex1);
//         std::string rest = message.substr(splitIndex1+1);
//         int splitIndex2 = rest.find(' ');
//         std::string hash1 = rest.substr(0, splitIndex2);
//         std::string hash2 = rest.substr(splitIndex2+1);
//         try {
//             bloomFilter = new BloomFilter(std::stoi(size), std::stoi(hash1), std::stoi(hash2));
//             } catch (std::invalid_argument& e) {
//                 std::cerr << "Invalid argument: " << e.what() << '\n';
//             } catch (std::out_of_range& e) {
//                 std::cerr << "Out of range: " << e.what() << '\n';
//             }
//     }
// }

void handle_client(int client_sock, BloomFilter* bloomFilter) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer) - 1; // Leave space for null terminator
    std::string buffer_str;
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    
    while(read_bytes > 0){
        buffer[read_bytes] = '\0'; // Null-terminate the data
        buffer_str += buffer; // Append data to buffer_str

        // Process complete messages
        size_t newline_pos;
        while ((newline_pos = buffer_str.find('\n')) != std::string::npos) {
            std::string message = buffer_str.substr(0, newline_pos);
            buffer_str = buffer_str.substr(newline_pos + 1);

            int splitIndex = message.find(' ');
            if (splitIndex != std::string::npos) {
                std::string choice_str = message.substr(0, splitIndex);
                std::string url = message.substr(splitIndex+1);

                try {
                    int choice = std::stoi(choice_str);
                    bloomFilter->execute(choice, url);
                } catch (std::invalid_argument& e) {
                    std::cerr << "Invalid argument: " << e.what() << '\n';
                } catch (std::out_of_range& e) {
                    std::cerr << "Out of range: " << e.what() << '\n';
                }
            } else {
                std::cerr << "Invalid input format\n";
            }
        }

        read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    }
    close(client_sock);
}

int main()
{
    const int server_port = 5555;
    // BloomFilter* bloomFilter;
    // int sock = socket(AF_INET, SOCK_STREAM,0);
    // if (sock < 0)
    // {
    //     perror("error creating socket");
    // }
    // struct sockaddr_in sin;
    // memset(&sin,0, sizeof(sin));
    // sin.sin_family = AF_INET;
    // sin.sin_addr.s_addr = INADDR_ANY;
    // sin.sin_port = htons(server_port);
    // if (bind(sock,(struct sockaddr*)&sin,sizeof(sin)) < 0)
    // {
    //     perror("error binding socket");
    // }
    // if (listen(sock,5) < 0)
    // {
    //     perror("error listening to a socket");
    // }

    // struct sockaddr_in client_sin;
    // unsigned int addr_len = sizeof(client_sin);
    // int client_sock = accept(sock,(struct sockaddr*)&client_sin,&addr_len);
    // if (client_sock < 0)
    // {
    //     perror("error accepting client");
    // }
    // std::thread client_thread(initialize_client, client_sock, bloomFilter);


    
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
        if (client_sock < 0)
        {
            perror("error accepting client");
            continue; // Skip to the next iteration of the loop
        }

        std::thread client_thread(handle_client, client_sock, bloomFilter);
        client_thread.detach();
    }
    
    close(sock);
    return 0;
}