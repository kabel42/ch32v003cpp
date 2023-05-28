#ifndef STARTUP_H

void handle_reset()            __attribute__((naked)) __attribute((section(".text.handle_reset"))) __attribute__((used));
void DefaultIRQHandler( void ) __attribute__((section(".text.vector_handler"))) __attribute__((naked)) __attribute__((used));

#endif