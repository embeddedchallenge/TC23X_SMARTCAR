#GCC MakeFile

#iLLD Sw Path 
include ./2_ILLD/Config/iLLD_Config.mk

#Define Target 
TARGET	= TC237_SMARTCAR
TARGET_ELE	= ./Debug/Exe/$(TARGET).elf
TARGET_MAP  = ./Debug/Exe/$(TARGET).map

#Define core ofr the micro
MCPU = tc23xx

#Use Gcc for arm compiler otherwise Gcc for c compiler
TCPREFIX 	= tricore
CC 			= $(TCPREFIX)-gcc
AS			= $(TCPREFIX)-gcc
LD 			= $(TCPREFIX)-gcc
OBJCOPY 	= $(TCPREFIX)-objcopy

#Directorys of source to build
DEBUG_DIR			= ./Debug
EXE_DIR 			= $(DEBUG_DIR)/Exe
OBJ_DIR				= $(DEBUG_DIR)/Obj

#Define include directorys to build
INCLUDE 			+= ./0_Src/App_Layer
INCLUDE 			+= ./0_Src/App_Layer/Scheduler
INCLUDE 			+= ./0_Src/Middle_Layer
INCLUDE 			+= ./0_Src/Driver_Layer

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
      
#Gcc Linker option
L_OPTION		= -mtc161
L_OPTION		+= -Wl,-Map,$(TARGET_MAP)
L_OPTION		+= -Wl,--gc-sections
L_OPTION		+= -Wl,-n
L_OPTION		+= -T./1_ToolEnv/0_Build/1_Config/Config_Tricore_Gnuc/Lcf_Gnuc_Tricore_Tc.lsl

#App Source files to build
SOURCE				+= 	Main.c
SOURCE				+= 	Scheduler.c

SOURCE				+= 	Middle_Stm.c

SOURCE				+= 	Driver_Sys.c
SOURCE				+= 	Driver_Stm.c
SOURCE				+= 	Driver_Watchdog.c

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
.PHONY: dir all build clean total

all: dir build

total: clean illd dir build

illd : 
	$(MAKE) -C 2_ILLD

dir: 
	@echo make dir...
	@if test ! -d $(DEBUG_DIR); then mkdir -p $(DEBUG_DIR);fi
	@if test ! -d $(EXE_DIR); then mkdir -p $(EXE_DIR);fi
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR);fi
		
build : $(OBJECTS)
	@echo /****Linking****/
	$(LD) -mcpu=$(MCPU) -o $(TARGET_ELE) $^ $(ILLD_OBJECTS) $(L_OPTION) $(LIBS) 
	@echo /****Linking Success****/

clean:
	@if test -d $(DEBUG_DIR); then rm -r $(DEBUG_DIR);fi