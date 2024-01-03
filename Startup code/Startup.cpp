#include<array>

#define NULL (void*) 0

typedef unsigned long uint32_t;


extern uint32_t _estack , _sidata , _sdata , _edata , _sbss , _ebss , _etext ;
uint32_t * const MSP_Value {(uint32_t *) &_estack};

// Interrupt Handlers Prototypes.
void Reset_Handler(void)        ;
void Default_Handler(void);
static void System_Initialization();
extern void main();

std::array<uint32_t*> Vector_Table  __attribute__((section(".isr_vector"))) {
    (uint32_t*) &MSP_Value              ,
    (uint32_t*) &Reset_Handler          ,
    (uint32_t*) &NMI_Handler            __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &HardFault_Handler      __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &MemManage_Handler      __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &BusFault_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &UsageFault_Handler     __attribute__((alias("Default_Handler")))   ,
    0                                   ,
    0                                   ,
    0                                   ,
    0                                   ,
    (uint32_t*) &SVCall_Handler         __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &Debug_Monitor_Handler  __attribute__((alias("Default_Handler")))   ,
    0                                   ,
    (uint32_t*) &PendSV_Handler         __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &SysTick_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &WWDG_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &PVD_Handler            __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel1_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel2_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel3_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel4_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel5_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel6_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA1_Channel7_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &ADC1_2_Handler         __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN1_TX_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN1_RX0_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN1_RX1_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN1_SCE_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &EXTI9_5_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM1_BRK_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM1_UP_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM1_TRG_COM_Handler   __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM1_CC_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM2_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM3_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM4_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &I2C1_EV_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &I2C1_ER_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &I2C2_EV_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &I2C2_ER_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &SPI1_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &SPI2_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &USART1_Handler         __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &USART2_Handler         __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &USART3_Handler         __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &EXTI15_10_Handler      __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &RTCAlarm_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &OTG_FS_WKUP_Handler    __attribute__((alias("Default_Handler")))   ,
    0                                   ,
    0                                   ,
    0                                   ,
    0                                   ,
    0                                   ,
    0                                   ,
    0                                   ,
    (uint32_t*) &TIM5_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &SPI3_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &UART4_Handler          __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &UART5_Handler          __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM6_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &TIM7_Handler           __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA2_Channel1_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA2_Channel2_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA2_Channel3_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA2_Channel4_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &DMA2_Channel5_Handler  __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &ETH_Handler            __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &ETH_WKUP_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN2_TX_Handler        __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN2_RX0_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN2_RX1_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &CAN2_SCE_Handler       __attribute__((alias("Default_Handler")))   ,
    (uint32_t*) &OTG_FS_Handler         __attribute__((alias("Default_Handler")))   ,
};


// Interrupt Handlers definitions
void Reset_Handler(void)
{
    // Memory-related variables and pointers defining.
    uint32_t  SectionSize   {0}                 ;
    uint32_t* MemSrcAddr    {NULL}              ;
    uint32_t* MemDestAddr   {NULL}              ;

    // 1. copy .data section form flash to ram
    SectionSize = &_sdata - &_edata             ;
    MemSrcAddr     = (uint32_t*) &_sidata       ;
    MemDestAddr    = (uint32_t*) &_sdata        ;

    for (uint32_t MemCounter=0; MemCounter < SectionSize ; SectionSize++)
    {
        *MemDestAddr++ =  *MemSrcAddr++         ;
    }

    // 2. initialize .bss section with zeros
    SectionSize = &_ebss - &_sbss               ;
    MemDestAddr = (uint32_t*) &_sbss            ;
    for (uint32_t MemCounter=0; MemCounter < SectionSize ; SectionSize++)
    {
        *MemDestAddr++ = 0                      ;
    }

    // 3. call system initialization function
    System_Initialization()                     ;
    // 4. call main()
    main()                                      ;
}



static void System_Initialization()
{
    
}