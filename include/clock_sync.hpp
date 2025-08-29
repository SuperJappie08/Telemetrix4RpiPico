#pragma once

extern volatile bool clock_enabled;

// Enable the clock reporting
extern void clock_enable();

// Request a new clock message
extern void clock_now();
