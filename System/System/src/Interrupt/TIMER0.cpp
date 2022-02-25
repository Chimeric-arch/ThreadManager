#include "Interrupt/TIMER0.h"

unsigned char CoadjutorSystem::Timer0::__status__ = __FALSE;

void CoadjutorSystem::Timer0::Enable()
{
  __WRITE_REG(SREG, SREG_I, __FALSE);
  __WRITE_REG(TIMSK0, TOIE0, __TRUE);
  TCCR0B = 0x03;
  TCNT0 = 0x06;
  __WRITE_REG(SREG, SREG_I, __TRUE);
  __status__ = __TRUE;
}

void CoadjutorSystem::Timer0::Disable()
{
  __WRITE_REG(SREG, SREG_I, __FALSE);
  __WRITE_REG(TIMSK0, TOIE0, __FALSE);
  __WRITE_REG(SREG, SREG_I, __TRUE);
  __status__ = __FALSE;
}

void CoadjutorSystem::Timer0::Reset() { TCNT0 = 0x06; }

unsigned char &CoadjutorSystem::Timer0::Status() { return __status__; }