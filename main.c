//------------------------------------------------------------------------------
// Copyright (c) 2016 by Lukasz Janyst <lukasz@jany.st>
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED 'AS IS' AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Register addresses
//------------------------------------------------------------------------------
#define STCTRL_REG           (*(volatile unsigned long *)0xe000e010)
#define STRELOAD_REG         (*(volatile unsigned long *)0xe000e014)
#define STCURRENT_REG        (*(volatile unsigned long *)0xe000e018)

#define GPIOHBCTL_REG        (*(volatile unsigned long *)0x400fe06c)
#define RCGCGPIO_REG         (*(volatile unsigned long *)0x400fe608)

#define GPIODATA_REG_PORTF   (*(volatile unsigned long *)0x4005d3fc)
#define GPIODIR_REG_PORTF    (*(volatile unsigned long *)0x4005d400)
#define GPIOAFSEL_REG_PORTF  (*(volatile unsigned long *)0x4005d420)
#define GPIOPUR_REG_PORTF    (*(volatile unsigned long *)0x4005d510)
#define GPIODEN_REG_PORTF    (*(volatile unsigned long *)0x4005d51c)
#define GPIOLOCK_REG_PORTF   (*(volatile unsigned long *)0x4005d520)
#define GPIOCR_REG_PORTF     (*(volatile unsigned long *)0x4005d524)
#define GPIOAMSEL_REG_PORTF  (*(volatile unsigned long *)0x4005d528)
#define GPIOPCTL_REG_PORTF   (*(volatile unsigned long *)0x4005d52c)

//------------------------------------------------------------------------------
// Initialize the SysTick timer
//------------------------------------------------------------------------------
void init_sys_tick()
{
  STCTRL_REG    = 0;                  // disable
  STRELOAD_REG  = 0x00ffffff;         // maximum reload value
  STCURRENT_REG = 0;                  // clear the current
  STCTRL_REG    = 0x00000005;         // enable with the system clock
}

//------------------------------------------------------------------------------
// Initialize GPIO
//------------------------------------------------------------------------------
void init_gpio()
{
  volatile unsigned long delay;
  (void)delay;

  // Enable the high performance bus (AHB) for Port F.
  GPIOHBCTL_REG |= 0x20;

  // Enable the clock for port F.
  RCGCGPIO_REG |= 0x20;

  // Do something to wait a couple cycles until the clock settles. We fetch
  // the value of the register to give it enough time.
  delay = RCGCGPIO_REG;

  // Additional protection is provided for pins that can be used as JTAG and
  // NMI. One of these pins is PF0 which we want to use because it connects to
  // the SW2 switch of the board. To enable it, we need to write a magic number
  // to the corresponding port lock register. Also to enable commiting to the
  // bits correspionding to pin the PF0 of GPIOAFSEL, GPIOPUR, GPIOPDR and
  // GPIODEN, we need to set the corresponding bit in the GPIOCR commit
  // register.
  GPIOLOCK_REG_PORTF  = 0x4c4f434b;
  GPIOCR_REG_PORTF   |= 0x01;

  // Select the direction for the pins: PF0 and PF4 (the switches) are input,
  // PF1-PF3 (the LEDs) are output
  GPIODIR_REG_PORTF |=  0x0e;

  // Enable the pullup resistors for PF4 (SW1) and PF0 (SW2).
  GPIOPUR_REG_PORTF |=  0x11;

  // Enable pins PF0-PF4
  GPIODEN_REG_PORTF |= 0x1f;
}

//------------------------------------------------------------------------------
// Count bus cycles and block until counted enough. By default the system clock
// runs at 16MHz this gives 62.5ns per tick.
//------------------------------------------------------------------------------
void st_wait_cycles(unsigned long delay)
{
  STRELOAD_REG = delay-1;
  STCURRENT_REG = 0;
  while(!(STCTRL_REG & 0x00010000));
}

//------------------------------------------------------------------------------
// Wait a multiple of one milisecond
//------------------------------------------------------------------------------
void st_wait(unsigned long times)
{
  int i;
  for(i = 0; i < times; ++i)
    st_wait_cycles(16000); // 16000 * 62.5ns = 1ms
}

//------------------------------------------------------------------------------
// Start the show
//------------------------------------------------------------------------------
int main(void)
{
  init_sys_tick();
  init_gpio();

  unsigned long led = 0x02;

  while(1) {
    unsigned long sw1 = !(GPIODATA_REG_PORTF & 0x01);
    unsigned long sw2 = !(GPIODATA_REG_PORTF & 0x10);
    if(sw1 && sw2) led = 0x06;
    else if(sw1) led = 0x04;
    else if(sw2) led = 0x08;
    else led = 0x02;

    GPIODATA_REG_PORTF |= led;
    st_wait(1000);
    GPIODATA_REG_PORTF &= ~led;
    st_wait(1000);
  }
}
