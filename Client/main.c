#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "serial.h"

int main()
{
    printf("Initiating client...\n");
    socket_init();
    create_client_socket();

    printf("Connecting to server... \n");
    if (connect_to_server() >= 0)
    {
        printf("Connected to server...\n");
    }
    else
    {
        printf("Failed to connect...\n");
        exit(-1);
    }

    while (1)
    {
        printf("\nSend to server: ");
        get_input(out_buf, DEFAULT_BUFLEN);

        send_message();

        get_received_message_from_server();
        printf("Received from server: %s \n", in_buf);
    }

    printf("Closing socket..\n");
    socket_close();
    socket_cleanup();

    return 0;
}