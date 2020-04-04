#include "server.h"

int socket_init() {
	socket_version = MAKEWORD(1, 1);
	res = WSAStartup(socket_version, &wsaData);
	return res;
}

int create_server_socket() {
	res = server_s = socket(AF_INET, SOCK_STREAM, 0);
	return res;
}

int socket_bind() {
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	res = bind(server_s, (struct sockaddr*)&server_addr, sizeof(server_addr));
	return res;
}

int socket_listen() {
	res = listen(server_s, 1);
	return res;
}

int socket_wait_for_connection() {
	addr_len = sizeof(client_addr);
	res = client_s = accept(server_s, (struct sockaddr*) & client_addr, &addr_len);
	return res;
}

void socket_get_client_details() {
	memcpy(&client_ip_addr, &client_addr.sin_addr.s_addr, 4);
}

void print_client_details() {
	printf("\nClient connected \nip\t%s \nport\t%d\n\n"
		, inet_ntoa(client_ip_addr)
		, ntohs(client_addr.sin_port));
}

int send_message(const char* message) {
	strcpy(out_buf, message);
	res = send(client_s, out_buf, (strlen(out_buf) + 1), 0);
	return res;
}

int get_received_message_from_client() {
	res = recv(client_s, in_buf, sizeof(in_buf), 0);
	return res;
}

int socket_close() {
	res = closesocket(server_s);
	if (res < 0) {
		return res;
	}
	res = closesocket(client_s);
	if (res < 0) {
		return res;
	}
	return res;
}

int socket_cleanup() {
	res = WSACleanup();
	return res;
}
