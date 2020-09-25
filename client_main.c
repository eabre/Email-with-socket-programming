#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#define SERVER_ADDRESS_CLIENT "192.168.1.55" //server'ın paylaştığı bilgilere ulaşabilmek için onun çalıştığı bilgisayarın static ip'si gereklidir 

int main() {
    int network_socket;
    char x[256];
    char server_response[256];
    char system_command[256];
    char send_to_server[256] = { "1998" };


    struct sockaddr_in client_address;
    client_address.sin_family =AF_INET;
    client_address.sin_port =htons(9002);
    inet_pton(AF_INET, SERVER_ADDRESS_CLIENT, &(client_address.sin_addr));

        network_socket = socket(AF_INET,SOCK_STREAM,0);

    int connection_status = connect(network_socket, (struct sockaddr *) &client_address, sizeof(client_address));
    if (connection_status == -1) {
        printf(" There was an error making a connection to the remote socket \n\n");
    }

    //send(network_socket, send_to_server, sizeof (send_to_server),0);
    
    printf("connection succesful :)\n enter the password");

    scanf("%s", x);
    printf("%s \n", x);
    if (!strcmp(x,send_to_server)) {
        send(network_socket, x, sizeof (x),0); //password request was sended.
    }
    else {
        printf("Wrong password !!!\n");
        exit(1);
    }

    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf(" Response: %s\n", server_response);
    bzero((char *) &server_response, sizeof(server_response));
    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf(" mail: %s", server_response);

    close(network_socket);

    return 0;
}
