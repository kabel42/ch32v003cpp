#ifndef STARTUP_H

void handle_reset()            __attribute__((naked)) __attribute((section(".text.handle_reset"))) __attribute__((used));
void DefaultIRQHandler( void ) __attribute__((section(".text.vector_handler"))) __attribute__((naked)) __attribute__((used));

#define DMDATA0 ((volatile uint32_t*)0xe00000f4)
#define DMDATA1 ((volatile uint32_t*)0xe00000f8)

#include <sys/stat.h>

int _write(int fd, const char *buf, int size) __attribute__((used));
int _close(int file) __attribute__((used));
int _fstat(int file, struct stat *st) __attribute__((used));
int _isatty(int file) __attribute__((used));
int _lseek(int file, int ptr, int dir) __attribute__((used));
void _exit(int status) __attribute__((used));
void _kill(int pid, int sig) __attribute__((used));
int _getpid(void) __attribute__((used));
int _read (int file, char * ptr, int len) __attribute__((used));

#endif