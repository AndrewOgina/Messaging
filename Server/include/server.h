#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define SA struct sockaddr


// @warning: All functions work only with ipV4.

/**
 * @include server.h
 * 
 * @brief Creates a socket and returns the socket file descriptor. Does error handling.
 * 
 * @param sockType - SOCK_STREAM(for TCP) or SOCK_DGRAM(for Datagram).
 * 
 * @return An integer which is the socket file descriptor.
 * @note Ipv4 only.
*/
int getSocket(int sockType);

/**
 * @brief Fills a sockaddr_in  struct and returns it.
 * @param port - The port the server runs on.
 * @return A sockaddr_in struct
*/
struct sockaddr_in get_sockaddr_in(int port);


/**
 * @brief Binds address and listens for connections.
 * 
 * @param sockFD - The socket file descriptor
 * @param servaddr - A pointer to a sockaddr_in struct containing server address info.
 * 
 * @note Make sure the sockaddr_in struct is filled.
*/
void bind_and_listen(int* sockFD,struct sockaddr_in* servaddr);


/**
 * @brief Accepts incoming request and returns an accept file descriptor.
 *        Also prints out successful connections.
 * @param sockFD -  The socket file descriptor.
 * @param clientAddr - A pointer to a sockaddr_in struct to store client address.
 * @param clientAddrlen - A pointer to a socklen_t instance to store the client;s address length.
 * 
 * @return Returns 
 * 
 * @note Should be called within a loop.
*/
int acceptConnections(int sockFD,struct sockaddr_in* clientAddr,socklen_t* clientAddren);


/**
 * @brief Sends a message over a TCP server.
 * 
*/
void sendTCP();
void receiveTCP();

#endif