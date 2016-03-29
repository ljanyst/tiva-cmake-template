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
// Handler declarations
//------------------------------------------------------------------------------
void __int_handler(void);
#define DEFINE_HANDLER(NAME)  void NAME ## _handler() __attribute__ ((weak, alias ("__int_handler")))

void __rst_handler();
void reset_handler() __attribute__ ((weak, alias ("__rst_handler")));

DEFINE_HANDLER(nmi);
DEFINE_HANDLER(hard_fault);
DEFINE_HANDLER(mman);
DEFINE_HANDLER(bus_fault);
DEFINE_HANDLER(usage_fault);
DEFINE_HANDLER(svcall);
DEFINE_HANDLER(debug_monitor);
DEFINE_HANDLER(pendsv);
DEFINE_HANDLER(systick);

DEFINE_HANDLER(gpio_porta);
DEFINE_HANDLER(gpio_portb);
DEFINE_HANDLER(gpio_portc);
DEFINE_HANDLER(gpio_portd);
DEFINE_HANDLER(gpio_porte);
DEFINE_HANDLER(uart0);
DEFINE_HANDLER(uart1);
DEFINE_HANDLER(ssi0);
DEFINE_HANDLER(i2c0);
DEFINE_HANDLER(pwm0_fault);
DEFINE_HANDLER(pwm0_gen0);
DEFINE_HANDLER(pwm0_gen1);
DEFINE_HANDLER(pwm0_gen2);
DEFINE_HANDLER(qei0);
DEFINE_HANDLER(adc0_seq0);
DEFINE_HANDLER(adc0_seq1);
DEFINE_HANDLER(adc0_seq2);
DEFINE_HANDLER(adc0_seq3);
DEFINE_HANDLER(watchdog);
DEFINE_HANDLER(timer0a_32);
DEFINE_HANDLER(timer0b_32);
DEFINE_HANDLER(timer1a_32);
DEFINE_HANDLER(timer1b_32);
DEFINE_HANDLER(timer2a_32);
DEFINE_HANDLER(timer2b_32);
DEFINE_HANDLER(analog_comp0);
DEFINE_HANDLER(analog_comp1);
DEFINE_HANDLER(sysctl);
DEFINE_HANDLER(flashctl);
DEFINE_HANDLER(gpio_portf);
DEFINE_HANDLER(uart2);
DEFINE_HANDLER(ssi1);
DEFINE_HANDLER(timer3a_32);
DEFINE_HANDLER(timer3b_32);
DEFINE_HANDLER(i2c1);
DEFINE_HANDLER(qei1);
DEFINE_HANDLER(can0);
DEFINE_HANDLER(can1);
DEFINE_HANDLER(hibernation);
DEFINE_HANDLER(usb);
DEFINE_HANDLER(pwm0_gen3);
DEFINE_HANDLER(udma_soft);
DEFINE_HANDLER(udma_error);
DEFINE_HANDLER(adc1_seq0);
DEFINE_HANDLER(adc1_seq1);
DEFINE_HANDLER(adc1_seq2);
DEFINE_HANDLER(adc1_seq3);
DEFINE_HANDLER(ssi2);
DEFINE_HANDLER(ssi3);
DEFINE_HANDLER(uart3);
DEFINE_HANDLER(uart4);
DEFINE_HANDLER(uart5);
DEFINE_HANDLER(uart6);
DEFINE_HANDLER(uart7);
DEFINE_HANDLER(i2c2);
DEFINE_HANDLER(i2c3);
DEFINE_HANDLER(timer4a_32);
DEFINE_HANDLER(timer4b_32);
DEFINE_HANDLER(timer5a_32);
DEFINE_HANDLER(timer5b_32);
DEFINE_HANDLER(timer0a_64);
DEFINE_HANDLER(timer0b_64);
DEFINE_HANDLER(timer1a_64);
DEFINE_HANDLER(timer1b_64);
DEFINE_HANDLER(timer2a_64);
DEFINE_HANDLER(timer2b_64);
DEFINE_HANDLER(timer3a_64);
DEFINE_HANDLER(timer3b_64);
DEFINE_HANDLER(timer4a_64);
DEFINE_HANDLER(timer4b_64);
DEFINE_HANDLER(timer5a_64);
DEFINE_HANDLER(timer5b_64);
DEFINE_HANDLER(sysexcept);
DEFINE_HANDLER(pwm1_gen0);
DEFINE_HANDLER(pwm1_gen1);
DEFINE_HANDLER(pwm1_gen2);
DEFINE_HANDLER(pwm1_gen3);
DEFINE_HANDLER(pwm1_fault);

//------------------------------------------------------------------------------
// NVIC table
//------------------------------------------------------------------------------
#define HANDLER(NAME) NAME ## _handler
void(* nvic_table[])(void) __attribute__ ((section (".nvic"))) = {
  HANDLER(reset),
  HANDLER(nmi),
  HANDLER(hard_fault),
  HANDLER(mman),
  HANDLER(bus_fault),
  HANDLER(usage_fault),
  0, 0, 0, 0,
  HANDLER(svcall),
  HANDLER(debug_monitor),
  0,
  HANDLER(pendsv),
  HANDLER(systick),
  HANDLER(gpio_porta),
  HANDLER(gpio_portb),
  HANDLER(gpio_portc),
  HANDLER(gpio_portd),
  HANDLER(gpio_porte),
  HANDLER(uart0),
  HANDLER(uart1),
  HANDLER(ssi0),
  HANDLER(i2c0),
  HANDLER(pwm0_fault),
  HANDLER(pwm0_gen0),
  HANDLER(pwm0_gen1),
  HANDLER(pwm0_gen2),
  HANDLER(qei0),
  HANDLER(adc0_seq0),
  HANDLER(adc0_seq1),
  HANDLER(adc0_seq2),
  HANDLER(adc0_seq3),
  HANDLER(watchdog),
  HANDLER(timer0a_32),
  HANDLER(timer0b_32),
  HANDLER(timer1a_32),
  HANDLER(timer1b_32),
  HANDLER(timer2a_32),
  HANDLER(timer2b_32),
  HANDLER(analog_comp0),
  HANDLER(analog_comp1),
  0,
  HANDLER(sysctl),
  HANDLER(flashctl),
  HANDLER(gpio_portf),
  0, 0,
  HANDLER(uart2),
  HANDLER(ssi1),
  HANDLER(timer3a_32),
  HANDLER(timer3b_32),
  HANDLER(i2c1),
  HANDLER(qei1),
  HANDLER(can0),
  HANDLER(can1),
  0, 0,
  HANDLER(hibernation),
  HANDLER(usb),
  HANDLER(pwm0_gen3),
  HANDLER(udma_soft),
  HANDLER(udma_error),
  HANDLER(adc1_seq0),
  HANDLER(adc1_seq1),
  HANDLER(adc1_seq2),
  HANDLER(adc1_seq3),
  0, 0, 0, 0, 0,
  HANDLER(ssi2),
  HANDLER(ssi3),
  HANDLER(uart3),
  HANDLER(uart4),
  HANDLER(uart5),
  HANDLER(uart6),
  HANDLER(uart7),
  0, 0, 0, 0,
  HANDLER(i2c2),
  HANDLER(i2c3),
  HANDLER(timer4a_32),
  HANDLER(timer4b_32),
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0,
  HANDLER(timer5a_32),
  HANDLER(timer5b_32),
  HANDLER(timer0a_64),
  HANDLER(timer0b_64),
  HANDLER(timer1a_64),
  HANDLER(timer1b_64),
  HANDLER(timer2a_64),
  HANDLER(timer2b_64),
  HANDLER(timer3a_64),
  HANDLER(timer3b_64),
  HANDLER(timer4a_64),
  HANDLER(timer4b_64),
  HANDLER(timer5a_64),
  HANDLER(timer5b_64),
  HANDLER(sysexcept),
  0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0,
  HANDLER(pwm1_gen0),
  HANDLER(pwm1_gen1),
  HANDLER(pwm1_gen2),
  HANDLER(pwm1_gen3),
  HANDLER(pwm1_fault) };

//------------------------------------------------------------------------------
// Linker symbols
//------------------------------------------------------------------------------
extern unsigned long __text_end_vma;
extern unsigned long __data_start_vma;
extern unsigned long __data_end_vma;
extern unsigned long __bss_start_vma;
extern unsigned long __bss_end_vma;

//------------------------------------------------------------------------------
// Handler definitions
//------------------------------------------------------------------------------
void __int_handler(void)
{
  while(1);
}

extern void main();

void __rst_handler()
{
  unsigned long *src = &__text_end_vma;
  unsigned long *dst = &__data_start_vma;

  while(dst < &__data_end_vma) *dst++ = *src++;
  dst = &__bss_start_vma;
  while(dst < &__bss_end_vma) *dst++ = 0;

  main();
}
