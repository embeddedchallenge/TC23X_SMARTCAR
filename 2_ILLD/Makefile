#iLLD MakeFile

#Define core ofr the micro
MCPU = tc23xx

#Use Gcc for arm compiler otherwise Gcc for c compiler
TCPREFIX 	= tricore
CC 			= $(TCPREFIX)-gcc
AS			= $(TCPREFIX)-gcc

#Directorys of source to build
GEN											=	./Gen
ILLD_ILLD_TC23A_TRICORE						=	./iLLD/iLLD/TC23A/Tricore
ILLD_ILLD_TC23A_TRICORE_ASCLIN_ASC 			= 	./iLLD/iLLD/TC23A/Tricore/Asclin/Asc
ILLD_ILLD_TC23A_TRICORE_ASCLIN_LIN 			= 	./iLLD/iLLD/TC23A/Tricore/Asclin/Lin
ILLD_ILLD_TC23A_TRICORE_ASCLIN_SPI 			= 	./iLLD/iLLD/TC23A/Tricore/Asclin/Spi
ILLD_ILLD_TC23A_TRICORE_ASCLIN_STD 			= 	./iLLD/iLLD/TC23A/Tricore/Asclin/Std
ILLD_ILLD_TC23A_TRICORE_CCU6_ICU 			= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/Icu
ILLD_ILLD_TC23A_TRICORE_CCU6_PWMBC 			= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/PwmBc
ILLD_ILLD_TC23A_TRICORE_CCU6_PWMHL 			= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/PwmHl
ILLD_ILLD_TC23A_TRICORE_CCU6_STD 			= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/Std
ILLD_ILLD_TC23A_TRICORE_CCU6_TPWM 			= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/TPwm
ILLD_ILLD_TC23A_TRICORE_CCU6_TIMER 			= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/Timer
ILLD_ILLD_TC23A_TRICORE_TIMERWITHTRIGGER 	= 	./iLLD/iLLD/TC23A/Tricore/Ccu6/TimerWithTrigger
ILLD_ILLD_TC23A_TRICORE_IMPL				=	./iLLD/iLLD/TC23A/Tricore/_Impl
ILLD_ILLD_TC23A_TRICORE_PINMAP				=	./iLLD/iLLD/TC23A/Tricore/_PinMap
ILLD_ILLD_TC23A_TRICORE_CPU_CSTART			=	./iLLD/iLLD/TC23A/Tricore/Cpu/CStart
ILLD_ILLD_TC23A_TRICORE_CPU_IRQ				=	./iLLD/iLLD/TC23A/Tricore/Cpu/Irq
ILLD_ILLD_TC23A_TRICORE_CPU_STD				=	./iLLD/iLLD/TC23A/Tricore/Cpu/Std
ILLD_ILLD_TC23A_TRICORE_CPU_TRAP			=	./iLLD/iLLD/TC23A/Tricore/Cpu/Trap
ILLD_ILLD_TC23A_TRICORE_DMA_DMA				=	./iLLD/iLLD/TC23A/Tricore/Dma/Dma
ILLD_ILLD_TC23A_TRICORE_DMA_STD				=	./iLLD/iLLD/TC23A/Tricore/Dma/Std
ILLD_ILLD_TC23A_TRICORE_DTS_DTS				=	./iLLD/iLLD/TC23A/Tricore/Dts/Dts
ILLD_ILLD_TC23A_TRICORE_DTS_STD				=	./iLLD/iLLD/TC23A/Tricore/Dts/Std
ILLD_ILLD_TC23A_TRICORE_ERAY_ERAY			=	./iLLD/iLLD/TC23A/Tricore/Eray/Eray
ILLD_ILLD_TC23A_TRICORE_ERAY_STD			=	./iLLD/iLLD/TC23A/Tricore/Eray/Std
ILLD_ILLD_TC23A_TRICORE_ETH_PHY_PEF7071		=	./iLLD/iLLD/TC23A/Tricore/Eth/Phy_Pef7071
ILLD_ILLD_TC23A_TRICORE_ETH_STD				=	./iLLD/iLLD/TC23A/Tricore/Eth/Std
ILLD_ILLD_TC23A_TRICORE_FLASH_STD			=	./iLLD/iLLD/TC23A/Tricore/Flash/Std
ILLD_ILLD_TC23A_TRICORE_GPT12_INCRENC		=	./iLLD/iLLD/TC23A/Tricore/Gpt12/IncrEnc
ILLD_ILLD_TC23A_TRICORE_GPT12_STD			=	./iLLD/iLLD/TC23A/Tricore/Gpt12/Std
ILLD_ILLD_TC23A_TRICORE_GTM_STD				=	./iLLD/iLLD/TC23A/Tricore/Gtm/Std
ILLD_ILLD_TC23A_TRICORE_GTM_TRIG			=	./iLLD/iLLD/TC23A/Tricore/Gtm/Trig
ILLD_ILLD_TC23A_TRICORE_MTU_STD				=	./iLLD/iLLD/TC23A/Tricore/Mtu/Std
ILLD_ILLD_TC23A_TRICORE_MULTICAN_CAN		=	./iLLD/iLLD/TC23A/Tricore/Multican/Can
ILLD_ILLD_TC23A_TRICORE_MULTICAN_STD		=	./iLLD/iLLD/TC23A/Tricore/Multican/Std
ILLD_ILLD_TC23A_TRICORE_QSPI_SPIMASTER		=	./iLLD/iLLD/TC23A/Tricore/Qspi/SpiMaster
ILLD_ILLD_TC23A_TRICORE_QSPI_SPISLAVE		=	./iLLD/iLLD/TC23A/Tricore/Qspi/SpiSlave
ILLD_ILLD_TC23A_TRICORE_QSPI_STD			=	./iLLD/iLLD/TC23A/Tricore/Qspi/Std
ILLD_ILLD_TC23A_TRICORE_SENT_SENT			=	./iLLD/iLLD/TC23A/Tricore/Sent/Sent
ILLD_ILLD_TC23A_TRICORE_SENT_STD			=	./iLLD/iLLD/TC23A/Tricore/Sent/Std
ILLD_ILLD_TC23A_TRICORE_SMU_STD				=	./iLLD/iLLD/TC23A/Tricore/Smu/Std
ILLD_ILLD_TC23A_TRICORE_PORT_IO				=	./iLLD/iLLD/TC23A/Tricore/Port/Io
ILLD_ILLD_TC23A_TRICORE_PORT_STD			=	./iLLD/iLLD/TC23A/Tricore/Port/Std
ILLD_ILLD_TC23A_TRICORE_SCU_STD				=	./iLLD/iLLD/TC23A/Tricore/Scu/Std
ILLD_ILLD_TC23A_TRICORE_SRC_STD				=	./iLLD/iLLD/TC23A/Tricore/Src/Std
ILLD_ILLD_TC23A_TRICORE_STM_STD				=	./iLLD/iLLD/TC23A/Tricore/Stm/Std
ILLD_ILLD_TC23A_TRICORE_STM_TIMER			=	./iLLD/iLLD/TC23A/Tricore/Stm/Timer
ILLD_ILLD_TC23A_TRICORE_VADC_ADC			=	./iLLD/iLLD/TC23A/Tricore/Vadc/Adc
ILLD_ILLD_TC23A_TRICORE_VADC_STD			=	./iLLD/iLLD/TC23A/Tricore/Vadc/Std
ILLD_ILLD_TC23A_TRICORE_GTM_TIM_IN			=	./iLLD/iLLD/TC23A/Tricore/Gtm/Tim/In
ILLD_ILLD_TC23A_TRICORE_GTM_TOM_PWM			=	./iLLD/iLLD/TC23A/Tricore/Gtm/Tom/Pwm
ILLD_ILLD_TC23A_TRICORE_GTM_TOM_PWMHL		=	./iLLD/iLLD/TC23A/Tricore/Gtm/Tom/PwmHl
ILLD_ILLD_TC23A_TRICORE_GTM_TOM_TIMER		=	./iLLD/iLLD/TC23A/Tricore/Gtm/Tom/Timer
ILLD_ILLD_TC23A_TRICORE_LIB_DATAHANDLING	=	./iLLD/iLLD/TC23A/Tricore/_Lib/DataHandling
ILLD_ILLD_TC23A_TRICORE_LIB_INTERNALMUX		=	./iLLD/iLLD/TC23A/Tricore/_Lib/InternalMux

ILLD_INFRA_SFR_TC23A						=	./iLLD/Infra/Sfr/TC23A
ILLD_INFRA_SFR_TC23A_REG					=	./iLLD/Infra/Sfr/TC23A/_Reg
ILLD_INFRA_PLATFORM_TRICORE					=	./iLLD/Infra/Platform/Tricore
ILLD_INFRA_PLATFORM							=	./iLLD/Infra/Platform
ILLD_INFRA_PLATFORM_TRICORE_COMPILERS		=	./iLLD/Infra/Platform/Tricore/Compilers

ILLD_SERVICE_CPUGENERIC						=	./iLLD/Service/CpuGeneric
ILLD_SERVICE_UTILITIES						=	./iLLD/Service/CpuGeneric/_Utilities
ILLD_SERVICE_CPUGENERIC_IF					=	./iLLD/Service/CpuGeneric/If
ILLD_SERVICE_CPUGENERIC_STDIF				=	./iLLD/Service/CpuGeneric/StdIf
ILLD_SERVICE_CPUGENERIC_IF_CCU6IF			=	./iLLD/Service/CpuGeneric/If/Ccu6If
ILLD_SERVICE_CPUGENERIC_SYSSE_BSP			=	./iLLD/Service/CpuGeneric/SysSe/Bsp
ILLD_SERVICE_CPUGENERIC_SYSSE_COMM			=	./iLLD/Service/CpuGeneric/SysSe/Comm
ILLD_SERVICE_CPUGENERIC_SYSSE_GENERAL		=	./iLLD/Service/CpuGeneric/SysSe/General
ILLD_SERVICE_CPUGENERIC_SYSSE_MATH			=	./iLLD/Service/CpuGeneric/SysSe/Math
ILLD_SERVICE_CPUGENERIC_SYSSE_TIME			=	./iLLD/Service/CpuGeneric/SysSe/Time

OBJ_DIR				= ./Obj

#Define include directorys to build
INCLUDE 			+= $(GEN)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ASCLIN_ASC)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ASCLIN_LIN)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ASCLIN_SPI)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ASCLIN_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CCU6_ICU)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CCU6_PWMBC)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CCU6_PWMHL)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CCU6_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CCU6_TPWM)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CCU6_TIMER)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_TIMERWITHTRIGGER)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_IMPL)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_PINMAP)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CPU_CSTART)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CPU_IRQ)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CPU_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_CPU_TRAP)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_DMA_DMA)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_DMA_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_DTS_DTS)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_DTS_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ERAY_ERAY)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ERAY_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ETH_PHY_PEF7071)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_ETH_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_FLASH_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GPT12_INCRENC)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GPT12_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GTM_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GTM_TRIG)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_MTU_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_MULTICAN_CAN)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_MULTICAN_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_QSPI_SPIMASTER)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_QSPI_SPISLAVE)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_QSPI_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_SENT_SENT)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_SENT_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_SMU_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_PORT_IO)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_PORT_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_SCU_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_SRC_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_STM_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_STM_TIMER)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_VADC_ADC)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_VADC_STD)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GTM_TIM_IN)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GTM_TOM_PWM)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GTM_TOM_PWMHL)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_GTM_TOM_TIMER)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_LIB_DATAHANDLING)
INCLUDE 			+= $(ILLD_ILLD_TC23A_TRICORE_LIB_INTERNALMUX)

INCLUDE 			+= $(ILLD_INFRA_SFR_TC23A)
INCLUDE 			+= $(ILLD_INFRA_SFR_TC23A_REG)
INCLUDE 			+= $(ILLD_INFRA_PLATFORM_TRICORE)
INCLUDE 			+= $(ILLD_INFRA_PLATFORM)
INCLUDE 			+= $(ILLD_INFRA_PLATFORM_TRICORE_COMPILERS)

INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC)
INCLUDE 			+= $(ILLD_SERVICE_UTILITIES)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_IF)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_STDIF)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_IF_CCU6IF)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_SYSSE_BSP)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_SYSSE_COMM)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_SYSSE_GENERAL)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_SYSSE_MATH)
INCLUDE 			+= $(ILLD_SERVICE_CPUGENERIC_SYSSE_TIME)

#Set search path
vpath % $(INCLUDE)

#Gcc compiler option
C_OPTION 		= -mtc161
C_OPTION 		+= -g
C_OPTION 		+= -O1
C_OPTION 		+= -fno-common
C_OPTION 		+= -fstrict-volatile-bitfields
C_OPTION 		+= -ffunction-sections
C_OPTION 		+= -fdata-sections
C_OPTION 		+= -Wall
C_OPTION 		+= -std=c99
C_OPTION 		+= $(patsubst %,-I%,$(INCLUDE))
                         
#Gcc assembler option
A_OPTION		= $(C_OPTION);
      

#Source files to build
SOURCE				=	Ifx_InterfaceConst.c
SOURCE				+= 	CompilerGnuc.c
SOURCE				+= 	IfxCpu_cfg.c
SOURCE				+= 	IfxCpu_CStart0.c
SOURCE				+= 	IfxCpu_Irq.c
SOURCE				+= 	IfxCpu.c
SOURCE				+= 	IfxCpu_Trap.c
SOURCE				+= 	IfxPort_cfg.c
SOURCE				+= 	IfxPort_PinMap.c
SOURCE				+= 	IfxPort_Io.c
SOURCE				+= 	IfxPort.c
SOURCE				+= 	IfxScu_cfg.c
SOURCE				+= 	IfxScu_PinMap.c
SOURCE				+= 	IfxScuCcu.c
SOURCE				+= 	IfxScuEru.c
SOURCE				+= 	IfxScuWdt.c
SOURCE				+= 	IfxStm_cfg.c
SOURCE				+= 	IfxStm.c
SOURCE				+= 	IfxStm_Timer.c
SOURCE				+= 	Bsp.c
SOURCE				+= 	IfxSrc_cfg.c
SOURCE				+= 	IfxSrc.c
SOURCE				+= 	IfxVadc_cfg.c
SOURCE				+= 	IfxVadc_PinMap.c
SOURCE				+= 	IfxVadc_Adc.c
SOURCE				+= 	IfxVadc.c
SOURCE				+= 	IfxAsclin_cfg.c
SOURCE				+= 	IfxAsclin_PinMap.c
SOURCE				+= 	IfxAsclin_Asc.c
SOURCE				+= 	IfxAsclin_Lin.c
SOURCE				+= 	IfxAsclin_Spi.c
SOURCE				+= 	IfxAsclin.c
SOURCE				+= 	Ifx_Fifo.c
SOURCE				+= 	Ifx_CircularBuffer.c
SOURCE				+= 	Ifx_Shell.c
SOURCE				+= 	Ifx_DateTime.c
SOURCE				+= 	Ifx_Console.c
SOURCE				+= 	IfxStdIf_DPipe.c
SOURCE				+= 	Assert.c
SOURCE				+= 	IfxGtm_cfg.c
SOURCE				+= 	IfxGtm_PinMap.c
SOURCE				+= 	IfxGtm.c
SOURCE				+= 	IfxGtm_Cmu.c
SOURCE				+= 	IfxGtm_Dpll.c
SOURCE				+= 	IfxGtm_Tbu.c
SOURCE				+= 	IfxGtm_Tim.c
SOURCE				+= 	IfxGtm_Tom.c
SOURCE				+= 	IfxGtm_Trig.c
SOURCE				+= 	IfxGtm_Tim_In.c
SOURCE				+= 	IfxGtm_Tom_Pwm.c
SOURCE				+= 	IfxGtm_Tom_PwmHl.c
SOURCE				+= 	IfxGtm_Tom_Timer.c
SOURCE				+= 	IfxStdIf_PwmHl.c
SOURCE				+= 	IfxStdIf_Timer.c
SOURCE				+= 	IfxQspi_cfg.c
SOURCE				+= 	IfxQspi_PinMap.c
SOURCE				+= 	IfxQspi_SpiMaster.c
SOURCE				+= 	IfxQspi_SpiSlave.c
SOURCE				+= 	IfxQspi.c
SOURCE				+= 	SpiIf.c
SOURCE				+= 	IfxDma_cfg.c
SOURCE				+= 	IfxDma_Dma.c
SOURCE				+= 	IfxDma.c
SOURCE				+= 	Ifx_InternalMux.c
SOURCE				+= 	IfxStdIf_Pos.c
SOURCE				+= 	IfxCcu6_cfg.c
SOURCE				+= 	IfxCcu6_PinMap.c
SOURCE				+= 	IfxCcu6_Icu.c
SOURCE				+= 	IfxCcu6_PwmBc.c
SOURCE				+= 	IfxCcu6_PwmHl.c
SOURCE				+= 	IfxCcu6.c
SOURCE				+= 	IfxCcu6_TPwm.c
SOURCE				+= 	IfxCcu6_Timer.c
SOURCE				+= 	IfxCcu6_TimerWithTrigger.c
SOURCE				+= 	Ifx_GlobalResources.c
SOURCE				+= 	Ifx_FftF32_BitReverseTable.c
SOURCE				+= 	Ifx_AngleTrkF32.c
SOURCE				+= 	Ifx_Cf32.c
SOURCE				+= 	Ifx_Crc.c
SOURCE				+= 	Ifx_FftF32.c
SOURCE				+= 	Ifx_FftF32_TwiddleTable.c
SOURCE				+= 	Ifx_IntegralF32.c
SOURCE				+= 	Ifx_LowPassPt1F32.c
SOURCE				+= 	Ifx_RampF32.c
SOURCE				+= 	Ifx_WndF32_BlackmanHarrisTable.c
SOURCE				+= 	Ifx_WndF32_HannTable.c
SOURCE				+= 	Ifx_CircularBuffer.asm
SOURCE				+= 	IfxMtu_cfg.c
SOURCE				+= 	IfxMtu.c
SOURCE				+= 	IfxGpt12_PinMap.c
SOURCE				+= 	IfxGpt12_IncrEnc.c
SOURCE				+= 	IfxGpt12.c
SOURCE				+= 	IfxSmu_cfg.c
SOURCE				+= 	IfxSmu_PinMap.c
SOURCE				+= 	IfxSmu.c
SOURCE				+= 	Ifx_LutAtan2F32.c
SOURCE				+= 	Ifx_LutAtan2F32_Table.c
SOURCE				+= 	Ifx_LutLSincosF32.c
SOURCE				+= 	Ifx_LutLinearF32.c
SOURCE				+= 	Ifx_LutSincosF32.c
SOURCE				+= 	Ifx_LutSincosF32_Table.c
SOURCE				+= 	IfxSent_cfg.c
SOURCE				+= 	IfxSent_PinMap.c
SOURCE				+= 	IfxSent_Sent.c
SOURCE				+= 	IfxSent.c
SOURCE				+= 	IfxDts_Dts.c
SOURCE				+= 	IfxDts.c
SOURCE				+= 	IfxEray_cfg.c
SOURCE				+= 	IfxEray_PinMap.c
SOURCE				+= 	IfxEray_Eray.c
SOURCE				+= 	IfxEray.c
SOURCE				+= 	IfxEth_PinMap.c
SOURCE				+= 	IfxEth_Phy_Pef7071.c
SOURCE				+= 	IfxEth.c
SOURCE				+= 	IfxFlash_cfg.c
SOURCE				+= 	IfxFlash.c
SOURCE				+= 	IfxMultican_cfg.c
SOURCE				+= 	IfxMultican_PinMap.c
SOURCE				+= 	IfxMultican_Can.c
SOURCE				+= 	IfxMultican.c

SOURCE_NAMES = $(notdir $(SOURCE))
BASE_NAMES	 = $(basename $(SOURCE_NAMES))
OBJECTS_NAMES = $(addsuffix .o, $(BASE_NAMES))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJECTS_NAMES))

#Define Rules (make objects)
$(OBJ_DIR)/%.o: %.s
	@echo 'Building file: $<'
	@$(CC) -mcpu=$(MCPU) -c -o $@ $(A_OPTION) $<
	@echo 'Building Success: $@'
	@echo ' '
	
$(OBJ_DIR)/%.o: %.c
	@echo 'Building file: $<'
	@$(CC) -mcpu=$(MCPU) -c -o $@ $(C_OPTION) $<
	@echo 'Building Success: $@'
	@echo ' '

#Build targets
.PHONY: dir all clean 

all: clean dir $(OBJECTS)

dir: 
	@echo make dir...
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR);fi

clean:
	@if test -d $(OBJ_DIR); then rm -r $(OBJ_DIR);fi