#ifndef stateMachine_included
#define stateMachine_included

extern char button_state, button_state_altered;

// states for msp430
void next_state();
void dim_led();
void delay();

#endif
