#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
#
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := IrReceiver.cpp MSGDecoderControl.cpp EncodeDecodeMSG.cpp
# header files in this project
HEADERS := IrReceiver.hpp PauseDetectionControl.hpp MSGDecoderControl.hpp EncodeDecodeMSG.hpp message.hpp

# other places to look for files for this project
SEARCH  := ../../lib

# set RELATIVE to the next higher directory
# and defer to the Makefile.native there
RELATIVE := $(RELATIVE)../../
include $(RELATIVE)Makefile.due
