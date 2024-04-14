#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include "bloom_filter.h" // Include your Bloom filter implementation

int size = 128; // Size of the Bloom filter
int numHashes = 2; // Number of hash functions
BloomFilter bloomFilter(size, numHashes); // Create a Bloom filter

void handle_connection(const char* ip_address, int port_no, const char* url) {
    // Check if the URL is possibly in the set
    if (bloomFilter.lookup(url)) {
        std::cout << "URL is possibly in the set\n";
        return;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return;
    }

    // Send the URL
    int data_len = strlen(url);
    int sent_bytes = send(sock, url, data_len, 0);
    if (sent_bytes < 0) {
        // error
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    } else if (read_bytes < 0) {
        // error
    } else {
        // Update the Bloom filter with the received data
        bloomFilter.insert(url);
        std::cout << "Received: " << buffer << std::endl;
    }

    close(sock);
}

int main() {
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    // Send each URL in a separate thread
    std::thread t1(handle_connection, ip_address, port_no, "http://example.com");
    std::thread t2(handle_connection, ip_address, port_no, "http://example.org");
    std::thread t3(handle_connection, ip_address, port_no, "http://example.net");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}