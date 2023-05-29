#ifndef STARTUP_H

void handle_reset()            __attribute__((naked)) __attribute((section(".text.handle_reset"))) __attribute__((used));
void DefaultIRQHandler( void ) __attribute__((section(".text.vector_handler"))) __attribute__((naked)) __attribute__((used));

#define DMDATA0 ((volatile uint32_t*)0xe00000f4)
#define DMDATA1 ((volatile uint32_t*)0xe00000f8)

int _write(int fd, const char *buf, int size) __attribute__((used));

#endif