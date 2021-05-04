#include "usbd_cdc_if.h"
#include "string.h"

void serial_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
//void uart_printf(UART_HandleTypeDef* huart, char* format, ...) __attribute__ ((format (printf, 1, 2)));