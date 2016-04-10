#-------------------------------------------------------------------------------
# Copyright (c) 2016 by Lukasz Janyst <lukasz@jany.st>
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED 'AS IS' AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
# OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.
#-------------------------------------------------------------------------------

macro(add_raw_binary output input)
  add_custom_command(
    OUTPUT ${output}
    COMMAND arm-none-eabi-objcopy -O binary ${input} ${output}
    DEPENDS ${input}
    COMMENT "Creating raw binary ${output}")
  add_custom_target(${output}-target ALL DEPENDS ${output})
endmacro(add_raw_binary)
