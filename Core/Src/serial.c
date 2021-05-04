#include "serial.h"
#include <stdarg.h>

void serial_printf(const char *format, ...) {
    uint8_t* error = "Error while logging a message: Memory allocation failed.\r\n";

    char* string;
    char endl = '\r';

    va_list args;
    va_start(args, format);
    if(0 > vasprintf(&string, format, args)) string = NULL;    //this is for logging, so failed allocation is not fatal
    va_end(args);

    if(string) {
        strncat(string, &endl, 1);
        CDC_Transmit_FS((uint8_t *) string, strlen((const char *) string));
        free(string);
    } else {
        CDC_Transmit_FS((uint8_t *) error, strlen((const char *) error));
    }
    return;
}