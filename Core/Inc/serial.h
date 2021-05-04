#include "usbd_cdc_if.h"
#include "string.h"

void serial_print();

void serial_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
