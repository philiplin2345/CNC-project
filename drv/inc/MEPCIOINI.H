#if !defined(_EPCIO_INI_H_)
#define _EPCIO_INI_H_

#define IRQ3 	        3
#define IRQ5	        5
#define IRQ7 	        7
#define IRQ10	        10
#define IRQ11	        11
#define IRQ12	        12
#define IRQ15	        15

//  Base Address define
#define BASE_200		0x200
#define BASE_220		0x220
#define BASE_240		0x240
#define BASE_260		0x260
#define BASE_280		0x280
#define BASE_2A0		0x2A0
#define BASE_2C0		0x2C0
#define BASE_2E0		0x2E0
#define BASE_300		0x300
#define BASE_320		0x320
#define BASE_340		0x340
#define BASE_360		0x360
#define BASE_380		0x380
#define BASE_3A0		0x3A0
#define BASE_3C0		0x3C0
#define BASE_3E0		0x3E0

//  Define constant for ISA section
#define RESET_DDA		0x01
#define RESET_ENC		0x02
#define RESET_RIO0		0x03
#define RESET_RIO1		0x04
#define RESET_ADC		0x05
#define RESET_LIO		0x06
#define RESET_PCL		0x07
#define RESET_DAC		0x08
#define RESET_PERI		0x09
#define RESET_ALL		0x0A
#define INT_RISE_EDGE	0x00   
#define INT_FALL_EDGE   0x01
#define INT_LEVEL_HIGH  0x02
#define INT_LEVEL_LOW   0x03
    
//define encoder A/B phase decoder mutiplier rate
#define ENC_RATE_X0	    0x0
#define ENC_RATE_X1	    0x1
#define ENC_RATE_X2	    0x2
#define ENC_RATE_X4	    0x3

#define ENC_TYPE_AB	    0x0
#define ENC_TYPE_CW	    0x1
#define ENC_TYPE_PD	    0x2
#define ENC_TYPE_NO	    0x3

#define ENC_TRIG_FIRST	0x0
#define ENC_TRIG_LAST	0x1

#define ENC_TRIG_NO	    0x0000
#define ENC_TRIG_INDEX0	0x0001
#define ENC_TRIG_INDEX1	0x0002
#define ENC_TRIG_INDEX2	0x0004
#define ENC_TRIG_INDEX3	0x0008
#define ENC_TRIG_INDEX4	0x0010
#define ENC_TRIG_INDEX5	0x0020
#define ENC_TRIG_INDEX6	0x0040
#define ENC_TRIG_INDEX7	0x0080
#define ENC_TRIG_INDEX8	0x0100
#define ENC_TRIG_LDI0	0x0200
#define ENC_TRIG_LDI1	0x0400
#define ENC_TRIG_RDI0	0x0800
#define ENC_TRIG_RDI1	0x1000
#define ENC_TRIG_ADC0	0x2000
#define ENC_TRIG_ADC1	0x4000

#define ENC_INT_INDEX0	0x00
#define ENC_INT_INDEX1	0x01
#define ENC_INT_INDEX2	0x02
#define ENC_INT_INDEX3	0x03
#define ENC_INT_INDEX4	0x04
#define ENC_INT_INDEX5	0x05
#define ENC_INT_INDEX6	0x06
#define ENC_INT_INDEX7	0x07
#define ENC_INT_INDEX8	0x08

#define ENC_INT_COMP0	0x00
#define ENC_INT_COMP1	0x01
#define ENC_INT_COMP2	0x02
#define ENC_INT_COMP3	0x03
#define ENC_INT_COMP4	0x04
#define ENC_INT_COMP5	0x05
#define ENC_INT_COMP6	0x06
#define ENC_INT_COMP7	0x07
#define ENC_INT_COMP8	0x08

// Define DDA section constant value
#define DDA_LEN10	    0x00
#define DDA_LEN11	    0x01
#define DDA_LEN12	    0x02
#define DDA_LEN13	    0x03
#define DDA_LEN14	    0x04
#define DDA_LEN15	    0x05

#define DDA_FMT_PD	    0x00
#define DDA_FMT_CW	    0x01
#define DDA_FMT_AB	    0x02
#define DDA_FMT_NO	    0x03

//define RIO section constant value
#define RIO_SET0	    0x0
#define RIO_SET1	    0x1
#define RIO_SLAVE0	    0x0
#define RIO_SLAVE1	    0x1
#define RIO_SLAVE2	    0x2
#define RIO_SLAVE3	    0x3
#define RIO_PORT0	    0x0
#define RIO_PORT1	    0x1
#define RIO_PORT2	    0x2
#define RIO_PORT3	    0x3
#define RIO_DI0		    0x0
#define RIO_DI1		    0x1
#define RIO_DI2		    0x2
#define RIO_DI3		    0x3

#define RIO_INT_RISE	0x0
#define RIO_INT_FALL	0x1
#define RIO_INT_LEVEL	0x2

//define ADC section constant value
#define ADC_COMP_RISE	0x0
#define ADC_COMP_FALL	0x1
#define ADC_COMP_LEVEL	0x2
#define ADC_TYPE_BIP	0x0
#define ADC_TYPE_UNI	0x1
#define ADC_MODE_SINGLE 0x0
#define ADC_MODE_FREE	0x1
#define ADC_MASK_NO	0x0
#define ADC_MASK_BIT1	0x1
#define ADC_MASK_BIT2	0x2
#define ADC_MASK_BIT3	0x3

//define LIO section constant value
#define LIO_OUT_EN0	    0x0
#define LIO_OUT_EN1 	0x1
#define LIO_OUT_EN2 	0x2
#define LIO_OUT_EN3 	0x3
#define LIO_OUT_EN4 	0x4
#define LIO_OUT_EN5 	0x5
#define LIO_OUT_EN6 	0x6
#define LIO_OUT_EN7	    0x7
#define LIO_INT_RISE	0x0
#define LIO_INT_FALL	0x1
#define LIO_INT_LEVEL	0x2
#define LIO_LDI0	    0x0
#define LIO_LDI1	    0x1
#define LIO_LDI2	    0x2
#define LIO_LDI3	    0x3
#define LIO_LDI4	    0x4
#define LIO_LDI5	    0x5
#define LIO_LDI6	    0x6
#define LIO_LDI7	    0x7
#define LIO_DFI0	    0x0
#define LIO_DFI1	    0x1
#define LIO_DFI2	    0x2
#define LIO_DFI3	    0x3
#define LIO_DFI4	    0x4
#define LIO_DFI5	    0x5
#define LIO_DFI6	    0x6
#define LIO_OT0		    0x0
#define LIO_OT1		    0x1
#define LIO_OT2		    0x2
#define LIO_OT3		    0x3
#define LIO_OT4		    0x4
#define LIO_OT5		    0x5
#define LIO_HOME0	    0x0
#define LIO_HOME1	    0x1
#define LIO_HOME2	    0x2
#define LIO_HOME3	    0x3
#define LIO_HOME4	    0x4
#define LIO_HOME5	    0x5
#define LIO_INH0	    0x0
#define LIO_INH1	    0x1
#define LIO_INH2	    0x2
#define LIO_INH3	    0x3
#define LIO_INH4	    0x4
#define LIO_INH5	    0x5


//  Define DAC section constant value
#define DAC_TRIG_ENC0	0x00000001
#define DAC_TRIG_ENC1	0x00000002
#define DAC_TRIG_ENC2	0x00000004
#define DAC_TRIG_ENC3	0x00000008
#define DAC_TRIG_ENC4	0x00000010
#define DAC_TRIG_ENC5	0x00000020
#define DAC_TRIG_ENC6	0x00000040
#define DAC_TRIG_ENC7	0x00000080
#define DAC_TRIG_ADC0	0x00000100
#define DAC_TRIG_ADC1	0x00000200
#define DAC_TRIG_ADC2	0x00000400
#define DAC_TRIG_ADC3	0x00000800
#define DAC_TRIG_ADC4	0x00001000
#define DAC_TRIG_ADC5	0x00002000
#define DAC_TRIG_ADC6	0x00004000
#define DAC_TRIG_ADC7	0x00008000
#define DAC_TRIG_LDI0	0x00010000
#define DAC_TRIG_LDI1	0x00020000
#define DAC_TRIG_LDI2	0x00040000
#define DAC_TRIG_LDI3	0x00080000
#define DAC_TRIG_DFI0	0x00100000
#define DAC_TRIG_DFI1	0x00200000
#define DAC_TRIG_DFI2	0x00400000
#define DAC_TRIG_DFI3	0x00800000
#define DAC_TRIG_R0DI0	0x01000000
#define DAC_TRIG_R0DI1	0x02000000
#define DAC_TRIG_R0DI2	0x04000000
#define DAC_TRIG_R0DI3	0x08000000
#define DAC_TRIG_R1DI0	0x10000000
#define DAC_TRIG_R1DI1	0x20000000
#define DAC_TRIG_R1DI2	0x40000000
#define DAC_TRIG_R1DI3	0x80000000
 
#define DAC_CMD_SOFT	0x0
#define DAC_CMD_PCL	0x1
#define DAC_SOURCE_SOFT	0x0
#define DAC_SOURCE_PCL	0x1

#endif
