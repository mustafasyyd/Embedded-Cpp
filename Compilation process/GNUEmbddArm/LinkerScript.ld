/**
* @file     LInkerScript.ld 
* @author   mustafa.sayed
* @brief    Linker script file / directives for memoty and sections of the target embdd sys.
*
*/

_estack = ORIGIN(RAM) + LENGTH(RAM);    /*end of stack address = start address + length of RAM*/
_Min_Heap_Size  = 0x200 ;               /*Minimum amount required for heap*/
_Min_Stack_Size = 0x400 ;               /*Minimum amount required for stack*/

/* Memory Areas definitons (origin and length) */
MEMORY{
    CCMRAM  (xrw)    : ORIGIN = 0x10000000 ,     LENGTH = 64k
    RAM     (xrw)    : ORIGIN = 0x80000000 ,     LENGTH = 128k
    FLASH   (rw)     : ORIGIN = 0x80000000 ,     LENGTH = 1024k
}

SECTIONS{
    /*.text section in FLASH with 4 Bytes alignment*/
    .text  : 
    {
        . = ALIGN(4);
        *(.text) 
        *(.text*)
        . = ALIGN(4);
        _etext = .  ;
    } >FLASH
    
    /*.rodata section in FLASH with 4 Bytes alignment*/
    .rodata :
    {
        /* _srodata = . ; */
        . = ALIGN(4) ;
        *(.rodata) 
        *(.rodata*)
        . = ALIGN(4) ;
        /* _erodata = . ; */
    }>FLASH
    
    /*.data section in FLASH at compile time and in RAM at startup(run-time) with 4 Bytes alignment*/
    .data   :
    {
        _sdata = .  ;
        . = ALIGN(4);
        *(.data) 
        *(.data*)
        . = ALIGN(4);
        _edata = .  ;
    }>FLASH AT>RAM
    
    /*.bss section in RAM with 4 Bytes alignment*/
    .bss    :
    {
        _sbss = .   ;
        . = ALIGN(4);
        *(.bss*)
        *(.bss)
        . = ALIGN(4);
        _ebss = .   ;
    }>RAM
}