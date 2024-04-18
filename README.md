# ex4 - Bloom Filter and Tcp Server - BIU Advanced Programming Course
### The Tcp BloomFilter
In this program you can see our bloomfilter and our tcp server, the bloom filter and the tcp server were developed in cpp for our part 4 of the project in advanced programming course in BIU. 

The bloom filter is kind of an hash table that stores urls.

You can add url into this bloomfilter and check if an url already exist in it. 

The Tcp server, is a server that is written in cpp and its target is to comunnicate between this bloom filter and our Node js server which will be explained later. 

the node js server is used for our facebook website and android app, you can see more about it in here: 

https://github.com/orshmuel9/FacebookServer/tree/part4

### Compile and run the bloom filter and the tcp server
- first, download this folder (from the branch "part4") in zip format and extract it.
- open the terminal in that folder ( or in vs code).
- run the following commands:
- cd src
- make
- ./ex4
- now the server and the bloom filter are running!

### Some remarks 
In our implementation of the code, the node js server sets the size of the bloom filter and sets the hash functions which will make the insertions of the urls.

Also the urls which will enter into the bloom filter are written in the env file of the node js server. so if you want it to work you need to follow the instructions of the node js server repo.

*there is a link up there* 

## Developed by:
Eliya Rabia 

Or Shmuel

Ofek Yemini
