#ifndef _KL2X_DMA_H_
#define _KL2X_DMA_H_


typedef enum
{
    /*        ����ͨ��            */
    Channel_Disabled        = 0,

    /*        UART            */
    DMA_UART0_Rx            = 2,
    DMA_UART0_Tx            = 3,
    DMA_UART1_Rx            = 4,
    DMA_UART1_Tx            = 5,
    DMA_UART2_Rx            = 6,
    DMA_UART2_Tx            = 7,

    /*        I2S           
    DMA_I2S0_Rx             = 14,
    DMA_I2S0_Tx             = 15, */

    /*        SPI            */
    DMA_SPI0_Rx             = 16,
    DMA_SPI0_Tx             = 17,
    DMA_SPI1_Rx             = 18,
    DMA_SPI1_Tx             = 19,

    /*        I2C            */
    DMA_I2C0                = 22,
    DMA_I2C1                = 23,

    /*        FTM            */
    DMA_TPM0_CH0            = 24,
    DMA_TPM0_CH1            = 25,
    DMA_TPM0_CH2            = 26,
    DMA_TPM0_CH3            = 27,
    DMA_TPM0_CH4            = 28,
    DMA_TPM0_CH5            = 29,


    DMA_FTM1_CH0            = 32,
    DMA_FTM1_CH1            = 33,

    DMA_FTM2_CH0            = 34,
    DMA_FTM2_CH1            = 35,


    /*     ADC/DAC/CMP/CMT    */
    DMA_ADC0                = 40,

    DMA_CMP0                = 42,

    DMA_DAC0                = 45,



    DMA_PORTA              = 49,
    DMA_PORTD              = 52,

    DMA_FTM0_OVER           = 54,
    DMA_FTM1_OVER           = 55,
    DMA_FTM2_OVER           = 56,

    DMA_TSI                 = 57,

    DMA_Always_EN1          = 60,
    DMA_Always_EN2          = 61,
    DMA_Always_EN3          = 62,
    DMA_Always_EN4          = 63,

} DMA_sources;



typedef enum
{
    DADDR_RECOVER = 0,        //�ָ�Ŀ�ĵ�ַ
    DADDR_KEEPON  = 1,        //Ŀ�ĵ�ַ���ֲ���

} DMA_cfg;

typedef enum      //DMAÿ�δ����ֽ���
{
    DMA_BYTE1 = 1,
    DMA_BYTE2 = 2,
    DMA_BYTE4 = 0,
} DMA_BYTEn;


typedef enum
{
    DMA_CH0,
    DMA_CH1,
    DMA_CH2,
    DMA_CH3,
} DMA_CHn;

/*

extern unsigned int DMA_GetChannelStatus(void);
*/


#define  DMA_IRQ_EN(DMA_CHn)    (DMA_DCR(DMA_CHn)  |= DMA_DCR_EINT_MASK; enable_irq((DMA_CHn) + 0))  //����DMAͨ������
#define  DMA_IRQ_DIS(DMA_CHn)   (DMA_DCR(DMA_CHn)  &= ~DMA_DCR_EINT_MASK;disable_irq((DMA_CHn) + 0))  //��ֹDMAͨ������
#define  DMA_IRQ_CLEAN(DMA_CHn)  DMA_DSR_BCR(DMA_CHn)|= DMA_DSR_BCR_DONE_MASK //���ͨ�������жϱ�־λ

#define  DMA_EN(DMA_CHn)        DMAMUX0_CHCFG(DMA_CHn) |= DMAMUX_CHCFG_ENBL_MASK         //ʹ��ͨ��Ӳ��DMA����
#define  DMA_DIS(DMA_CHn)       DMAMUX0_CHCFG(DMA_CHn) &= ~DMAMUX_CHCFG_ENBL_MASK         //��ֹͨ��Ӳ��DMA����

//#define  DMA_CHn_DIS(DMA_CHn)   DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,DMA_CHn) &= DMAMUX_CHCFG_SOURCE(Channel_Disabled)  //����ͨ��

//��ʼ��DMA��ʹ��PORT�˿�����ͨ��DMA���䵽BUFF������
void DMA_PORTx2BUFF_Init(DMA_CHn CHn, void *SADDR, void *DADDR, PTxn ptxn, DMA_BYTEn byten, uint32_t count);

#endif  //_DMA_H_