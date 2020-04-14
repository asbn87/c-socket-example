#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#define PORT_NUM        8888                                            // Port used
#define IP_ADDR         "127.0.0.1"                                     // IP address of server (localhost)
#define DEFAULT_BUFLEN  4096                                            // Default buf length of I/O messages

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

WORD socket_version;                                                    // Socket version
WSADATA wsa_data;                                                       // Socket information

int client_s;                                                           // Client socket descriptor
struct sockaddr_in server_addr;                                         // Server Internet address
int res;                                                                // Return code
char in_buf[DEFAULT_BUFLEN];                                            // Input buffer for data
char out_buf[DEFAULT_BUFLEN];                                           // Output buffer for data

int socket_init();                                                      // Initiate socket version
int create_client_socket();                                             // Create client socket
int connect_to_server();                                                // Fill in the server info and connect using the client socket
int get_received_message_from_server();                                 // Receive from the server using the client socket
int send_message();                                                     // Send to the server using the client socket
int socket_close();                                                     // Close the client socket
int socket_cleanup();                                                   // Clean up resources
