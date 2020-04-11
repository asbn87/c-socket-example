#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "data.h"

int main()
{
    printf("Initiating server...\n");
    struct hash_table* mem = create_hash_table(20000);
    char* data;

    init_hash_table(mem);
    socket_init();
    create_server_socket();
    socket_bind();
    socket_listen();

    printf("Waiting for a client to connect... \n");
    socket_wait_for_connection();

    socket_get_client_details();
    print_client_details();

    while (res >= 0)
    {
        printf("Waiting for message...\n");
        get_received_message_from_client();
        printf("Received from client: %s \n", in_buf);

        data = lookup(mem, in_buf);

        send_message(data);
        printf("Sent to client: %s\n\n", data);
    }
    printf("Client disconnected...\n");

    printf("Closing socket...\n");
    socket_close();
    socket_cleanup();

    return 0;
}
