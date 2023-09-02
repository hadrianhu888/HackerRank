/**
 * @file arduino.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <complex.h> 
#include <stdint.h>
#include <sys/types.h>

#define PORT 8080
#define MAXLINE 1024

/**
 * @brief define global variables 
 * 
 */

int sockfd;
struct sockaddr_in servaddr, cliaddr;
int len, n;
char buffer[MAXLINE];
char *hello = "Hello from server";
WSADATA wsaData;
int iResult;
int iSendResult;
char *sendbuf = "this is a test";
int recvbuflen = 1024;
char recvbuf[1024];
int iResult;
int iSendResult;

/**
 * @brief define structures 
 * 
 */

typedef struct {
    int id;
    char name[20];
    char surname[20];
    char email[30];
    char password[20];
    char username[20];
    char phone[20];
    char address[50];
    char city[20];
    char state[20];
    char country[20];
    char zip[10];
    char date[20];
    char time[20];
} user;

typedef struct {
    int id;
    char name[20];
    char surname[20];
    char email[30];
    char password[20];
    char username[20];
    char phone[20];
    char address[50];
    char city[20];
    char state[20];
    char country[20];
    char zip[10];
    char date[20];
    char time[20];
} admin;

typedef struct {
    int id;
    char name[20];
    char surname[20];
    char email[30];
    char password[20];
    char username[20];
    char phone[20];
    char address[50];
    char city[20];
    char state[20];
    char country[20];
    char zip[10];
    char date[20];
    char time[20];
} manager;

typedef struct {
    int id;
    char name[20];
    char surname[20];
    char email[30];
    char password[20];
    char username[20];
    char phone[20];
    char address[50];
    char city[20];
    char state[20];
    char country[20];
    char zip[10];
    char date[20];
    char time[20];
} customer;

/**
 * @brief signal types 
 * 
 */

typedef enum {
    SIGINT = 2,
    SIGILL = 4,
    SIGFPE = 8,
    SIGSEGV = 11,
    SIGTERM = 15
} signal_type;

typedef enum pin_modes {
    INPUT_T,
    OUTPUT_T
} pin_mode;

/**
 * @brief create digital and analog pins
 * 
 */

typedef struct {
    int pin;
    int value;
} digital_pin;

typedef struct {
    int pin;
    int value;
} analog_pin;

/**
 * @brief define functions 
 * 
 */

void signal_handler(int signal);
void init();
void create_socket();
void bind_socket();
void receive_message();
void send_message();
void close_socket();
void close_winsock();
void error(char *msg);
void error_exit(const char *msg);
void error_winsock(char *msg);
void error_winsock_exit(char *msg);
analog_pin analog_read(int pin);
void analog_write(int pin, int value);
digital_pin digital_read(int pin);
void digital_write(int pin, int value);
pin_mode pinMode(int pin, char *mode);
void delay(int ms);

/**
 * @brief main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

void signal_handler(int signal) {
    switch (signal) {
        case SIGINT:
            printf("Caught SIGINT: Terminating\n");
            break;
        case SIGILL:
            printf("Caught SIGILL: Terminating\n");
            break;
        case SIGFPE:
            printf("Caught SIGFPE: Terminating\n");
            break;
        case SIGSEGV:
            printf("Caught SIGSEGV: Terminating\n");
            break;
        case SIGTERM:
            printf("Caught SIGTERM: Terminating\n");
            break;
        default:
            printf("Caught wrong signal: Terminating\n");
            break;
    }
    exit(1);
}

void init() {
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        error_winsock_exit("WSAStartup failed");
    }
}

void create_socket() {
    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        error_winsock_exit("Socket creation failed");
    }
}

void bind_socket() {
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        error_winsock_exit("Bind failed");
    }
}

void receive_message()
{
    len = sizeof(cliaddr);

    while (1) {
        n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
        if (n == SOCKET_ERROR) {
            error_winsock_exit("recvfrom failed");
        }

        buffer[n] = '\0';
        printf("Client : %s\n", buffer);

        sendto(sockfd, hello, strlen(hello), 0, (struct sockaddr *)&cliaddr, len);
        printf("Hello message sent.\n");
    }
}
void send_message()
{
    // sends message 
    iResult = send(sockfd, sendbuf, (int)strlen(sendbuf), 0);
    if (iResult == SOCKET_ERROR) {
        error_winsock_exit("send failed");
    }
    printf("Bytes Sent: %ld\n", iResult);
}
void close_socket()
{
    // cleanup
    closesocket(sockfd);
}
void close_winsock()
{
    // cleanup
    closesocket(sockfd);
    WSACleanup();
}
void error(char *msg)
{
    if(strcmp(msg, "send failed") == 0)
    {
        int msg_status = 1;
    }
    else if(strcmp(msg, "WSAStartup failed") == 0)
    {
        int msg_status = 2;
    }
    else if(strcmp(msg, "Socket creation failed") == 0)
    {
        int msg_status = 3;
    }
    else if(strcmp(msg, "Bind failed") == 0)
    {
        int msg_status = 4;
    }
    else if(strcmp(msg, "recvfrom failed") == 0)
    {
        int msg_status = 5;
    }
    else
    {
        error_exit("error failed");
    }
}
void error_winsock(char *msg)
{
    // Send an initial buffer
    if(strcmp(msg, "send failed") == 0)
    {
        int msg_status = 1;
    }
    else if(strcmp(msg, "WSAStartup failed") == 0)
    {
        int msg_status = 2;
    }
    else if(strcmp(msg, "Socket creation failed") == 0)
    {
        int msg_status = 3;
    }
    else if(strcmp(msg, "Bind failed") == 0)
    {
        int msg_status = 4;
    }
    else if(strcmp(msg, "recvfrom failed") == 0)
    {
        int msg_status = 5;
    }
    else
    {
        error_winsock_exit("error_winsock failed");
    }
}
void error_winsock_exit(char *msg)
{
    if (strcmp(msg, "WSAStartup failed") == 0)
    {
        int msg_status = 1;
    }
    else if (strcmp(msg, "Socket creation failed") == 0)
    {
        int msg_status = 2;
    }
    else if (strcmp(msg, "Bind failed") == 0)
    {
        int msg_status = 3;
    }
    else if (strcmp(msg, "recvfrom failed") == 0)
    {
        int msg_status = 4;
    }
    else if (strcmp(msg, "send failed") == 0)
    {
        int msg_status = 5;
    }
    else
    {
        error_winsock_exit("error_winsock_exit failed");
    }
}

void error_exit(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void error_exit_winsock(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    WSACleanup();
    exit(1);
}

analog_pin analog_read(int pin) {
    analog_pin aPin = {pin, 0};  
    // Add your logic here to read from the pin
    return aPin;
}

void analog_write(int pin, int value) {
    // Add your logic to write the value to the pin
}

digital_pin digital_read(int pin) {
    digital_pin dPin = {pin, 0};
    // Add your logic to read from the pin
    return dPin;
}

void digital_write(int pin, int value) {
    // Add your logic to write the value to the pin
}

pin_mode pinMode(int pin, char *mode) {
    if (strcmp(mode, "INPUT") == 0) {
        return INPUT_T;
    } else if (strcmp(mode, "OUTPUT") == 0) {
        return OUTPUT_T;
    } else {
        error_exit("Invalid pin mode");
    }
}

void delay(int ms) {
    if (ms >= 0) {
        Sleep(ms);
    } else {
        error_exit("Invalid time for delay");
    }
}

int main(int argc, char const *argv[]) {
    init();
    create_socket();
    bind_socket();
    receive_message();
    send_message();
    close_socket();
    close_winsock();
    //test analog and digital signals
    analog_pin aPin = analog_read(1);
    printf("Analog pin %d value: %d\n", aPin.pin, aPin.value);
    digital_pin dPin = digital_read(1);
    printf("Digital pin %d value: %d\n", dPin.pin, dPin.value);
    // test pin mode
    pin_mode pMode = pinMode(1, "INPUT");
    printf("Pin mode: %d\n", pMode);
    // test delay
    delay(1000);
    return 0;
}