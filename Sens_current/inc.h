#define LED_ON          GPIOC->BSRR = GPIO_BSRR_BR_13
#define LED_OFF         GPIOC->BSRR = GPIO_BSRR_BS_13

#define F_CPU 		72000000UL
#define TIMERTICK  	F_CPU/10000-1

#define VREFINT_CAL             ((u16*) ((u32) 0x1FFFF7BA))
#define CAL_VINT                ( (u32) (*VREFINT_CAL))
#define ADC_CH_REF              ADC_CHSELR_CHSEL17_Pos
#define ADC_CH_MS0              ADC_CHSELR_CHSEL3_Pos
#define MEAS_COUNT              1000
u16 led_timer_1, led_timer;
u16 adc_timer;
u1 led_st;
u1 start;
u16 cnt=0;
u8 temp;

struct
{
  float ref;
  float meas_0;
  
  u16 ref_a[MEAS_COUNT];
  u16 meas_a[MEAS_COUNT];
}Volt;