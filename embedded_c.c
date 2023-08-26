/**
 * @file embedded_c.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "embedded_c.h"

// Function prototypes

analog_t analogRead(analog_t *analog)
{
    return *analog;
}
analog_t analogWrite(analog_t *analog)
{
    analog_t *in = analog;
    return *in;
}

pin_t pinMode(pin_t *pin)
{
    return *pin;
}
digital_t digitalWrite(digital_t *digital)
{
    return *digital;
}
digit_t digitalRead(digital_t *digital)
{
    return *digital;
}

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

void CAN_Cluster_init(void);
void CAN_Cluster_send(void);
void CAN_Cluster_receive(void);
void CAN_Cluster_filter(void);
void CAN_Cluster_flush(void);
void CAN_Cluster_available(void);
void CAN_Cluster_read(void);
void CAN_Cluster_write(void);

void SPI_init(void);
void SPI_transfer(void);
void SPI_transfer16(void);
void SPI_transfer32(void);
void SPI_transfer64(void);
void SPI_transferNB(void);
void SPI_transfer16NB(void);
void SPI_transfer32NB(void);
void SPI_transfer64NB(void);
void SPI_write(void);
void SPI_write16(void);
void SPI_write32(void);
void SPI_write64(void);
void SPI_writeNB(void);
void SPI_write16NB(void);
void SPI_write32NB(void);
void SPI_write64NB(void);
void SPI_read(void);
void SPI_read16(void);
void SPI_read32(void);
void SPI_read64(void);
void SPI_readNB(void);

void Wire_begin(void);
void Wire_beginTransmission(void);
void Wire_endTransmission(void);
void Wire_requestFrom(void);
void Wire_write(void);

void ethernet_read(void); 
void ethernet_init(void);
void ethernet_write(void);
void ethernet_available(void);
void ethernet_server_init(void);
void ethernet_server_available(void);
void ethernet_server_write(void);
void ethernet_server_read(void);
void ethernet_client_init(void);
void ethernet_client_available(void);
void ethernet_client_write(void);
void ethernet_client_read(void);

void SD_init(void);
void SD_open(void);
void SD_close(void);
void SD_read(void);
void SD_write(void);
void SD_available(void);
void SD_flush(void);
void SD_seek(void);
void SD_position(void);
void SD_size(void);
void SD_remove(void);
void SD_rename(void);
void SD_truncate(void);
void SD_mkdir(void);
void SD_rmdir(void);
void SD_ls(void);
void SD_cd(void);
void SD_pwd(void);
void SD_cat(void);

// Main function

int main(int argc, char **argv);