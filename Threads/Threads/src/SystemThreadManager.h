#pragma once
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdlib.h>
#include "SystemMacros.h"
#include "Threads.h"
#include "SystemTime.h"

#define THIS 

namespace System
{
  class ThreadManager
  {
  private:
    static bool __manager_status__;
    static unsigned int __total_threads__;
    static unsigned int __thread_stack_size__;
    static unsigned long *__thread_timer_stack__;
    static subSystem::Thread *__thread_stack__;

  private:
    static bool _check_existing_address_(__std_thread__ *thread);
    static int _check_stack_address_();
    static void _shift_thread_stack_(unsigned int cursor);

  public:
    static bool Begin();
    static void xManager();
    static bool xCreateThread(__std_thread__ *thread, const char *threadName, unsigned long loopRuntime_ms);

    static void xChangeThreadRuntime(unsigned int ThreadNumber, unsigned long loopRuntime);
    static void xChangeThreadRuntime(__std_thread__ *addr_Thread, unsigned long loopRuntime);
    static void xChangeThreadRuntime(const char *functionName, unsigned long loopRuntime);

  public:
    struct control
    {
      static bool xRunThread(unsigned int ThreadNumber);
      static bool xRunThread(__std_thread__ *addr_Thread);
      static bool xRunThread(const char *functionName);

      static bool xPauseThread(unsigned int ThreadNumber);
      static bool xPauseThread(__std_thread__ *addr_Thread);
      static bool xPauseThread(const char *functionName);

      static bool xResumeThread(unsigned int ThreadNumber);
      static bool xResumeThread(__std_thread__ *addr_Thread);
      static bool xResumeThread(const char *functionName);

      static bool xDeleteThread(unsigned int ThreadNumber);
      static bool xDeleteThread(__std_thread__ *addr_Thread);
      static bool xDeleteThread(const char *functionName);
    } Control;

    struct get
    {
      static __std_thread__ *xThreadAddress(unsigned int ThreadNumber);
      static __std_thread__ *xThreadAddress(const char *functionName);

      static unsigned int xThreadNumber(__std_thread__ *addr_Thread);
      static unsigned int xThreadNumber(const char *functionName);

      static bool xThreadStatus(unsigned int ThreadNumber);
      static bool xThreadStatus(__std_thread__ *addr_Thread);
      static bool xThreadStatus(const char *functionName);

      static const char *xThreadName(unsigned int ThreadNumber);
      static const char *xThreadName(__std_thread__ *addr_Thread);
      static const char *xThreadName(const char *functionName);

      static unsigned long xThreadRuntime(unsigned int ThreadNumber);
      static unsigned long xThreadRuntime(__std_thread__ *addr_Thread);
      static unsigned long xThreadRuntime(const char *functionName);

      static unsigned int xTotalThreads();
      static unsigned int xStackSpace();
    } Get;
  };
}