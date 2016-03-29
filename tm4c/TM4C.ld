/*------------------------------------------------------------------------------
 | Copyright (c) 2016 by Lukasz Janyst <lukasz@jany.st>
 |
 | Permission to use, copy, modify, and/or distribute this software for any
 | purpose with or without fee is hereby granted, provided that the above
 | copyright notice and this permission notice appear in all copies.
 |
 | THE SOFTWARE IS PROVIDED 'AS IS' AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 | REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 | AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 | INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 | LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 | OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 | PERFORMANCE OF THIS SOFTWARE.
 +----------------------------------------------------------------------------*/

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00040000
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

SECTIONS
{
  .text :
  {
    LONG(0x20003fff) /* the stack location */
    KEEP(*(.nvic))
    *(.text*)
    *(.rodata*)
     __text_end_vma = .;
  } > FLASH

  .data :
  {
    __data_start_vma = .;
    *(.data*)
    *(vtable)  /* apparently tivaware needs this in RAM */
    __data_end_vma = .;
  } > RAM AT > FLASH

  .bss :
  {
    __bss_start_vma = .;
    *(.bss*)
    *(COMMON)	/* non-ISO C bulshit, just in case */
    __bss_end_vma = .;
  } > RAM
}
