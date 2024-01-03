_estack = ORIGIN(RAM) + LENGTH(RAM) ;
_Min_Heap_Size  = 0x200             ;
_Min_Stack_Size = 0x400             ;


MEMORY{
    RAM     (xrw)   :   ORIGIN = 0x10000000 ,   LENGTH = 64k
    CCMRAM  (xrw)   :   ORIGIN = 0x20000000 ,   LENGTH = 128k
    FLASH   (rw)    :   ORIGIN = 0x08000000 ,   LENGTH = 1024k 
}

SECTIONS{
    /* the order decides which section is assigned first */
    /* Default schema:  customizable but recommended schema
                    .isr_vector
                    .text
                    .rodata
                    .data
                    .bss
    */

    /* interrupt vector table section in flash memory area */
    .isr_vector :
    {
        . = ALIGN(4) ;
        *(.isr_vector)
        . = ALIGN(4) ;
    } > FLASH

    .text       :
    {
        . = ALIGN(4) ;
        *(.text)
        *(.text*)
        . = ALIGN(4) ;
        _etext = .   ;
    } > FLASH
    
    .rodata     :
    {
        . = ALIGN(4) ;
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4) ;
    } > FLASH

    _sidata = LOADADD(.data) ;
    1
    .data       :
    {
        _sdata = .   ;  /*Has address in SRAM not in FLASH*/
        . = ALIGN(4) ;
        *(.data)
        *(.data*)
        . = ALIGN(4) ;
        _edata = .   ;  /*Has address in SRAM not in FLASH*/
    } > FLASH AT>RAM
  
    .bss        :
    {
        _sbss = .    ;
        . = ALIGN(4) ;
        *(.bss)
        *(.bss*)
        . = ALIGN(4) ;
        _ebss = .    ;
    } > RAM


}