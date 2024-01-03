/**
* @file 
* @author
* @brief  
*/

/*
---------------
   TEMPLATE
---------------
MEMORY{
    name: org=0x00h , len=0x00h
    ...
}

SECTIONS{
    out-sec-name: {content} > area-name
    GROUP{
        [ALIGN(exp)]
        sec-def
        ...
    } > are-name
}
*/


/* Memory definitons */
MEMORY{
    CCMRAM  (xrw)    : ORIGIN = 0x00 ,     LENGTH = 64k
    RAM     (xrw)    : ORIGIN = 0x00 ,     LENGTH = 128k
    FLASH   (rw)     : ORIGIN = 0x00 ,     LENGTH = 1024k
}

SECTIONS{
    
    .text: 
    {
        *(.text) 
        *(.text*)
    } >FLASH
    
    .rodata 
    {
        *(.rodata) 
        *(.rodata*)
    }>FLASH
    
    .data 
    {
        *(.data) 
        *(.data*)
    }>FLASH
    
    .bss :
    {
        *(.bss*)
        *(.bss)
    }>RAM

    /* .heap :
    {

    }>RAM

    .vector{}>FLASH
    GROUP{
        [ALIGN(exp)]
        sec-def
        ...
    } > are-name */
}