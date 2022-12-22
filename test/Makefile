TARGET	= test.exe

CC			= gcc
CXX			= g++
LD			= $(CXX)

TOPDIR	?= $(CURDIR)
BUILD		= build
INCLDIR	= ../include ../basic/include
SRCDIR	= src

COMMONFLAGS	= -O2
CFLAGS			= $(INCLUDE) $(COMMONFLAGS)
CXXFLAGS		= $(CFLAGS) -std=c++20
LDFLAGS			= -Wl,--gc-sections

%.o: %.c
	@echo $(notdir $<)
	@$(CC) -MP -MMD -MF $*.d $(CFLAGS) -c -o $@ $<

%.o: %.cc
	@echo $(notdir $<)
	@$(CXX) -MP -MMD -MF $*.d $(CXXFLAGS) -c -o $@ $<

ifneq ($(notdir $(CURDIR)), $(BUILD))

CFILES		= $(notdir $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c)))
CXXFILES	= $(notdir $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.cc)))

export OUTPUT		= $(TOPDIR)/$(TARGET)
export OFILES		= $(CFILES:.c=.o) $(CXXFILES:.cc=.o)
export INCLUDE	= $(foreach dir,$(INCLDIR),-I$(TOPDIR)/$(dir))

export VPATH		= \
	$(foreach dir,$(SRCDIR),$(TOPDIR)/$(dir)) \
	$(foreach dir,$(RESDIR),$(TOPDIR)/$(dir))

.PHONY: $(BUILD) all clean re

all: $(BUILD)
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(TOPDIR)/Makefile

$(BUILD):
	@[ -d $@ ] || mkdir -p $@

clean:
	@rm -rf $(TARGET) $(BUILD)

re: clean all

else

DEPENDS	= $(OFILES:.o=.d)

$(OUTPUT): $(OFILES)
	@echo linking...
	@$(LD) $(LDFLAGS) -o $@ $^

-include $(DEPENDS)

endif