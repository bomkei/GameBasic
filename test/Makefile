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

LDFLAGS			= \
	-Wl,--gc-sections \
	-L../basic -lscript

INCLUDE	= $(foreach dir,$(INCLDIR),-I$(TOPDIR)/$(dir))

CFILES		= $(wildcard $(SRCDIR)/*.c)
CXXFILES	= $(wildcard $(SRCDIR)/*.cc)
OFILES		= \
	$(patsubst %.c, $(BUILD)/%.o, $(notdir $(CFILES))) \
	$(patsubst %.cc, $(BUILD)/%.o, $(notdir $(CXXFILES)))

$(BUILD)/%.o: $(SRCDIR)/%.c
	@echo $(notdir $<)
	@$(CC) -MP -MMD -MF $*.d $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: $(SRCDIR)/%.cc
	@echo $(notdir $<)
	@$(CXX) -MP -MMD -MF $*.d $(CXXFLAGS) -c -o $@ $<

.PHONY: $(BUILD) all clean re

all: $(BUILD) $(TARGET)

$(TARGET): $(OFILES)
	@echo linking...
	@$(LD) $(LDFLAGS) -o $@ $^

$(BUILD):
	@[ -d $@ ] || mkdir -p $@

clean:
	@rm -rf $(TARGET) $(BUILD)

re: clean all


