#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define uart0_tx 0
#define uart0_rx 1

int main() {
    int n = 0;
    char buffer[64];
    uart_init(uart0, 115200); // khoi tao uart0 baudrate 115200

    gpio_set_function(uart0_tx, UART_FUNCSEL_NUM(uart0, uart0_tx));
    gpio_set_function(uart0_rx, UART_FUNCSEL_NUM(uart0, uart0_rx));

    while(1) {
        sprintf(buffer, "Day%d: miss her!\r\n", n++); // tao chuoi
        uart_puts(uart0, buffer); // gui chuoi den uart0
        sleep_ms(1000); // delay 1 giay
    }
    return 0;
}