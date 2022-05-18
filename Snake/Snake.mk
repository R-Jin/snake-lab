##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Snake
ConfigurationName      :=Debug
WorkspacePath          :=/home/bottle/code/mop/codelite/Snake
ProjectPath            :=/home/bottle/code/mop/codelite/Snake/Snake
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ryan Jin
Date                   :=17/05/22
CodeLitePath           :=/home/bottle/.codelite
LinkerName             :=/usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-g++
SharedObjectLinkerName :=/usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Snake.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -T$(ProjectPath)/md407-ram.x -L$(ARM_V6LIB) -L$(ARM_GCC_V6LIB) -nostdlib -nostartfiles
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)gcc 
ArLibs                 :=  "gcc" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-ar rcu
CXX      := /usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-g++
CC       := /usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-gcc
CXXFLAGS :=  -g -O0 -W $(Preprocessors)
CFLAGS   :=  -g -O0 -w -mthumb -march=armv6-m  -mfloat-abi=soft -std=c99 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
ARM_V6LIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v6-m/nofp
ARM_GCC_V6LIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/thumb/v6-m/nofp
ARM_M4SFPLIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v7e-m+fp/softfp
ARM_GCC_M4SFPLIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m+fp/softfp
ARM_M4HFPLIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v7e-m+fp/hard
ARM_GCC_M4HFPLIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m+fp/hard
Objects0=$(IntermediateDirectory)/utils_display.c$(ObjectSuffix) $(IntermediateDirectory)/utils_input.c$(ObjectSuffix) $(IntermediateDirectory)/structs_sprite.c$(ObjectSuffix) $(IntermediateDirectory)/utils_delay.c$(ObjectSuffix) $(IntermediateDirectory)/structs_snake.c$(ObjectSuffix) $(IntermediateDirectory)/startup.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	/usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-objcopy -S -O srec  Debug/Snake Debug/Snake.s19
	/usr/share/codelite/tools/gcc-arm/bin/arm-none-eabi-objdump -D -S Debug/Snake > Debug/Snake.lst
	@echo Done

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/utils_display.c$(ObjectSuffix): utils/display.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_display.c$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_display.c$(DependSuffix) -MM utils/display.c
	$(CC) $(SourceSwitch) "/home/bottle/code/mop/codelite/Snake/Snake/utils/display.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_display.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_display.c$(PreprocessSuffix): utils/display.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_display.c$(PreprocessSuffix) utils/display.c

$(IntermediateDirectory)/utils_input.c$(ObjectSuffix): utils/input.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_input.c$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_input.c$(DependSuffix) -MM utils/input.c
	$(CC) $(SourceSwitch) "/home/bottle/code/mop/codelite/Snake/Snake/utils/input.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_input.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_input.c$(PreprocessSuffix): utils/input.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_input.c$(PreprocessSuffix) utils/input.c

$(IntermediateDirectory)/structs_sprite.c$(ObjectSuffix): structs/sprite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/structs_sprite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/structs_sprite.c$(DependSuffix) -MM structs/sprite.c
	$(CC) $(SourceSwitch) "/home/bottle/code/mop/codelite/Snake/Snake/structs/sprite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/structs_sprite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/structs_sprite.c$(PreprocessSuffix): structs/sprite.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/structs_sprite.c$(PreprocessSuffix) structs/sprite.c

$(IntermediateDirectory)/utils_delay.c$(ObjectSuffix): utils/delay.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_delay.c$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_delay.c$(DependSuffix) -MM utils/delay.c
	$(CC) $(SourceSwitch) "/home/bottle/code/mop/codelite/Snake/Snake/utils/delay.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_delay.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_delay.c$(PreprocessSuffix): utils/delay.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_delay.c$(PreprocessSuffix) utils/delay.c

$(IntermediateDirectory)/structs_snake.c$(ObjectSuffix): structs/snake.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/structs_snake.c$(ObjectSuffix) -MF$(IntermediateDirectory)/structs_snake.c$(DependSuffix) -MM structs/snake.c
	$(CC) $(SourceSwitch) "/home/bottle/code/mop/codelite/Snake/Snake/structs/snake.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/structs_snake.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/structs_snake.c$(PreprocessSuffix): structs/snake.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/structs_snake.c$(PreprocessSuffix) structs/snake.c

$(IntermediateDirectory)/startup.c$(ObjectSuffix): startup.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/startup.c$(ObjectSuffix) -MF$(IntermediateDirectory)/startup.c$(DependSuffix) -MM startup.c
	$(CC) $(SourceSwitch) "/home/bottle/code/mop/codelite/Snake/Snake/startup.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/startup.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/startup.c$(PreprocessSuffix): startup.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/startup.c$(PreprocessSuffix) startup.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


