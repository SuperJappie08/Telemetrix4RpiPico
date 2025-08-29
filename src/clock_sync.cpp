#include <cstdint>
#include <span>

#include "clock_sync.hpp"
#include "message_types.hpp"
#include "serialization.hpp"

#include <hardware/timer.h>

// clock report buffer
uint8_t clock_report_message[] = {5, CLOCK_TIME, 0, 0, 0, 0};

volatile bool clock_enabled = false;

void clock_enable() { clock_enabled = true; }

void clock_now() {
  encode_u32(time_us_32(),
             std::span(clock_report_message).subspan<2, sizeof(uint32_t)>());
}
