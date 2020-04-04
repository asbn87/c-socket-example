#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORT_NUM 8888
#define DEFAULT_BUFLEN	4096						// Default buf length of i/o messages

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

WORD socket_version;								// Socket version
WSADATA wsaData;									// Socket information

int server_s;										// Welcome socket descriptor
struct sockaddr_in server_addr;						// Server Internet address
int res;											// Return code
int addr_len;										// Internet address length
struct sockaddr_in client_addr;						// Client Internet address
int client_s;										// Connection socket descriptor
struct in_addr client_ip_addr;						// Client IP address
char out_buf[DEFAULT_BUFLEN];						// Output buffer for data
char in_buf[DEFAULT_BUFLEN];						// Input buffer for data

int socket_init();									// Initiate socket version
int create_server_socket();							// Create client socket
int socket_bind();									// Fill in server info and bind the welcome socket
int socket_listen();								// Listen on welcome socket for a connection
int socket_wait_for_connection();					// Wait for a connection
void socket_get_client_details();					// Copy the four-byte client IP address into an IP address structure
void print_client_details();						// Print client details
int send_message(const char* message);				// Send message to client using the connect socket
int get_received_message_from_client();				// Receive from the client using the connect socket
int socket_close();									// Close the welcome and connect sockets
int socket_cleanup();								// Cleanup resources