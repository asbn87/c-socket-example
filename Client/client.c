#include "client.h"

int socket_init() {
	socket_version = MAKEWORD(1, 1);
	res = WSAStartup(socket_version, &wsa_data);
	return res;
}

int create_client_socket() {
	res = client_s = socket(AF_INET, SOCK_STREAM, 0);
	return res;
}

int connect_to_server() {
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = inet_addr(IP_ADDR);
	res = connect(client_s, (struct sockaddr*) & server_addr, sizeof(server_addr));
	return res;
}

int get_received_message_from_server() {
	res = recv(client_s, in_buf, sizeof(in_buf), 0);
	return res;
}

int send_message() {
	res = send(client_s, out_buf, (strlen(out_buf) + 1), 0);
	return res;
}

int socket_close() {
	res = closesocket(client_s);
	return res;
}

int socket_cleanup() {
	res = WSACleanup();
	return res;
}
