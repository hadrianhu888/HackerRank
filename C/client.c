/**
 * @file client.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char **argv)
{
    WSADATA wsaData;
    SOCKET sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in servaddr;
    int len, n;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        perror("WSAStartup failed");
        exit(EXIT_FAILURE);
    }

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);  // Replace with your server IP address

    len = sizeof(servaddr);

    // Send the initial message
    sendto(sockfd, hello, strlen(hello), 0, (struct sockaddr *) &servaddr, len);
    printf("Hello message sent.\n");

    // Receive server's reply
    n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *) &servaddr, &len);
    buffer[n] = '\0';
    printf("Server: %s\n", buffer);

    // Cleanup
    closesocket(sockfd);
    WSACleanup();

    return 0;
}
