/**
 * @file embedded_c.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EMBEDDED_C_H
#define EMBEDDED_C_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <limits.h>

#if 1 

// Data types 

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} pin_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} digital_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} analog_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} interrupt_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} serial_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} random_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} tone_t;

typedef struct arc
{
    /**
     * @brief alive rolling count
     * counts from 0 to 3 and then resets to 0
     */
    int8_t arc;
    int8_t pin;
    int8_t mode;
    int8_t value;
    int8_t state; 
} arc_t; 

typedef struct can {
    int8_t pin;
    int8_t mode;
    int8_t value;
    int8_t filter;
    int8_t flush;
    int8_t available;
    int8_t read;
    int8_t write;
    int8_t send;
    int8_t receive;
    int8_t cluster;
    int8_t init;
    int8_t end;
    int8_t begin;
    arc_t arc;
} can_t;


typedef struct spi {
    double pin;
    double mode;
    double value;
    double transfer;
    double transfer16;
    double transfer32;
    double transfer64;
    double transferNB;
    double transfer16NB;
    double transfer32NB;
    double transfer64NB;
    double write;
    double write16;
    double write32;
    double write64;
    double writeNB;
    double write16NB;
} spi_t;

typedef struct wire {
    int pin;
    int mode;
    int value;
    int begin;
} wire_t;

typedef struct ethernet {
    int pin; 
    int mode;
    int value;
    int read;
    int write;
    int available;
    int server;
    int client;
} ethernet_t;

typedef struct sd {
    int pin;
    int mode;
    int value;
    int open;
    int close;
    int read;
    int write;
    int available;
    int flush;
    int seek;
    int position;
    int size;
} sd_t;

typedef struct {
    int pin;
    int mode;
    int value;
} shift_t;

typedef struct {
    long int year; 
    long int month;
    long int day;
    long int hour;
    long int minute;
    long int second;
} time_t;

typedef struct {
    long int rand;  
} randopm_t;

typedef struct {
    int pin[8];
} digit_t;

typedef int int8_t;
typedef int int16_t;
typedef int int32_t;
typedef int int64_t;
typedef int uint8_t;
typedef int uint16_t;
typedef int uint32_t;
typedef int uint64_t;

typedef struct {
    int8_t pin;
    int8_t mode;
    int8_t value;
} parity_t;

typedef struct pulse {
    int8_t pin;
    int8_t mode;
    int8_t value;
} pulse_t;

// Variables and constants

typedef enum 
{
    INPUT,
    OUTPUT,
    INPUT_PULLUP
} pinMode;

typedef enum 
{
    LOW,
    HIGH
} digitalWrite;

typedef enum 
{
    LOW,
    HIGH
} digitalRead;

typedef enum 
{
    FALLING,
    RISING
} interruptMode;

typedef enum {
    FALLING,
    RISING
} interruptMode;

typedef enum {
    DEC,
    HEX,
    OCT,
    BIN
} numberFormat;

typedef enum {
    BIN_MODE,
    OCT_MODE,
    DEC_MODE,
    HEX_MODE
} serialMode;

typedef enum {
    LSB,
    MSB
} bitOrder;

typedef enum {
    SPI_MODE0,
    SPI_MODE1,
    SPI_MODE2,
    SPI_MODE3
} spiMode;

typedef enum {
    MASTER,
    SLAVE
} spiRole;

typedef enum {
    LSBFIRST,
    MSBFIRST
} spiBitOrder;

typedef enum {
    LOW,
    HIGH
} spiClockPolarity;

typedef enum {
    RISING,
    FALLING
} spiClockPhase;

typedef enum {
    NONE,
    EVEN,
    ODD
} parityType;

typedef enum {
    BIN,
    OCT,
    DEC,
    HEX
} baseType;

// Function prototypes

analog_t analogRead(analog_t *analog);
analog_t analogWrite(analog_t *analog);

pin_t pinMode(pin_t *pin);
digital_t digitalWrite(digital_t *digital);
digit_t digitalRead(digital_t *digital);

time_t delay(time_t *time);
time_t delayMicroseconds(time_t *time);

interrupt_t attachInterrupt(interrupt_t *interrupt);
interrupt_t detachInterrupt(interrupt_t *interrupt);

interrupt_t interrupts(interrupt_t *interrupt);
interrupt_t noInterrupts(interrupt_t *interrupt);

int setup(void);
int loop(void);

serial_t Serial_begin(serial_t *serial);
serial_t Serial_print(serial_t *serial);
serial_t Serial_println(serial_t *serial);
serial_t Serial_read(serial_t *serial);
serial_t Serial_readln(serial_t *serial);
serial_t Serial_available(serial_t *serial);
serial_t Serial_flush(serial_t *serial);
serial_t Serial_end(serial_t *serial);
serial_t Serial_write(serial_t *serial);

random_t randomSeed(randopm_t *random);
random_t random(random_t *random);

tone_t tone(tone_t *tone);
tone_t noTone(tone_t *tone);

shift_t shiftOut(shift_t *shift);
shift_t shiftIn(shift_t *shift);

pulse_t pulseIn(pulse_t *pulse);
pulse_t pulseInLong(pulse_t *pulse);
pulse_t millis(pulse_t *pulse);
pulse_t micros(pulse_t *pulse);
pulse_t nanos(pulse_t *pulsed);
pulse_t picos(pulse_t *pulse);

double min(double x, double y);
double max(double x, double y);
double abs(double x);
double constrain(double x, double a, double b);
double map(double x, double y, double a, double b);
double pow(double x, double y);
double sqrt(double x);
double sin(double x);
double cos(double x);
double tan(double x);
double asin(double x);
double acos(double x);
double exp(double x);
double log(double x);
double log10(double x);
double logn(double x);

pulse_t lowByte(pulse_t pulse);
pulse_t highByte(pulse_t pulse);
pulse_t bitRead(pulse_t pulse);
pulse_t bitWrite(pulse_t pulse);
pulse_t bitSet(pulse_t pulse);
pulse_t bitClear(pulse_t pulse);
pulse_t bit(pulse_t pulse);

can_t canBegin(can_t *can);
can_t canEnd(can_t *can);
can_t canAvailable(can_t *can);
can_t canRead(can_t *can);
can_t canWrite(can_t *can);
can_t canFlush(can_t *can);
can_t canSend(can_t *can);
can_t canReceive(can_t *can);
can_t canFilter(can_t *can);
can_t canCluster(can_t *can);

spi_t spiBegin(spi_t *spi);
spi_t spiEnd(spi_t *spi);
spi_t spiTransfer(spi_t *spi);
spi_t spiTransfer16(spi_t *spi);
spi_t spiTransfer32(spi_t *spi);
spi_t spiTransfer64(spi_t *spi);
spi_t spiTransferNB(spi_t *spi);
spi_t spiTransfer16NB(spi_t *spi);
spi_t spiTransfer32NB(spi_t *spi);
spi_t spiTransfer64NB(spi_t *spi);
spi_t spiWrite(spi_t *spi);
spi_t spiWrite16(spi_t *spi);
spi_t spiWrite32(spi_t *spi);
spi_t spiWrite64(spi_t *spi);
spi_t spiWriteNB(spi_t *spi);
spi_t spiWrite16NB(spi_t *spi);
spi_t spiWrite32NB(spi_t *spi);
spi_t spiWrite64NB(spi_t *spi);
spi_t spiRead(spi_t *spi);
spi_t spiRead16(spi_t *spi);
spi_t spiRead32(spi_t *spi);
spi_t spiRead64(spi_t *spi);
spi_t spiReadNB(spi_t *spi);
spi_t spiRead16NB(spi_t *spi);
spi_t spiRead32NB(spi_t *spi);
spi_t spiRead64NB(spi_t *spi);

wire_t wireBegin(wire_t *wire);
wire_t wireBeginTransmission(wire_t *wire);
wire_t wireEndTransmission(wire_t *wire);
wire_t wireRequestFrom(wire_t *wire);
wire_t wireAvailable(wire_t *wire);
wire_t wireRead(wire_t *wire);
wire_t wireWrite(wire_t *wire);
wire_t wireBegin(wire_t *wire);

ethernet_t ethernetBegin(ethernet_t *ethernet);
ethernet_t ethernetAvailable(ethernet_t *ethernet);
ethernet_t ethernetRead(ethernet_t *ethernet);
ethernet_t ethernetWrite(ethernet_t *ethernet);
ethernet_t ethernetServer(ethernet_t *ethernet);
ethernet_t ethernetClient(ethernet_t *ethernet);

sd_t sdOpen(sd_t *sd);
sd_t sdClose(sd_t *sd);
sd_t sdRead(sd_t *sd);
sd_t sdWrite(sd_t *sd);
sd_t sdAvailable(sd_t *sd);
sd_t sdFlush(sd_t *sd);
sd_t sdSeek(sd_t *sd);
sd_t sdPosition(sd_t *sd, int position);
sd_t sdSize(sd_t *sd);

// Main function

int main(int argc, char **argv);

#endif 

#endif // EMBEDDED_C_H