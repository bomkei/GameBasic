TARGET	= gamebasic.exe

CC			= gcc
CXX			= g++
LD			= $(CXX)

TOPDIR	?= $(CURDIR)
BUILD		= build

SCRIPTDIR	= $(TOPDIR)/basic
TESTDIR		= $(TOPDIR)/test

INCLDIR	= include \
	basic/include

SRCDIR	= src \
	src/Wrapper \
	src/WrapperImpl

RESDIR	= res

COMMONFLAGS	= -O2 -DUNICODE
RCFLAGS			= $(INCLUDE) -c 65001
CFLAGS			= $(INCLUDE) $(COMMONFLAGS)
CXXFLAGS		= $(CFLAGS) -std=c++20
LDFLAGS			= -Wl,--gc-sections -mwindows -municode

%.o: %.c
	@echo $(notdir $<)
	@$(CC) -MP -MMD -MF $*.d $(CFLAGS) -c -o $@ $<

%.o: %.cc
	@echo $(notdir $<)
	@$(CXX) -MP -MMD -MF $*.d $(CXXFLAGS) -c -o $@ $<

%.o: %.rc
	@echo $(notdir $<)
	@windres $(RCFLAGS) $< $@

ifneq ($(notdir $(CURDIR)), $(BUILD))

CFILES		= $(notdir $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c)))
CXXFILES	= $(notdir $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.cc)))
RCFILES		= $(notdir $(foreach dir,$(RESDIR),$(wildcard $(dir)/*.rc)))

export OUTPUT		= $(TOPDIR)/$(TARGET)
export OFILES		= $(CFILES:.c=.o) $(CXXFILES:.cc=.o) $(RCFILES:.rc=.o)
export INCLUDE	= $(foreach dir,$(INCLDIR),-I$(TOPDIR)/$(dir))

export VPATH		= \
	$(foreach dir,$(SRCDIR),$(TOPDIR)/$(dir)) \
	$(foreach dir,$(RESDIR),$(TOPDIR)/$(dir))

.PHONY: $(BUILD) all clean re basic test

all: basic $(BUILD)
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(TOPDIR)/Makefile

$(BUILD):
	@[ -d $@ ] || mkdir -p $@

clean:
	@rm -rf $(TARGET) $(BUILD) \
		$(SCRIPTDIR)/$(BUILD) $(TESTDIR)/$(BUILD) \
		$(SCRIPTDIR)/script.dll $(TESTDIR)/test.exe

re: clean all

basic:
	@$(MAKE) --no-print-directory -C $(SCRIPTDIR) -f $(SCRIPTDIR)/Makefile

test:
	@$(MAKE) --no-print-directory -C $(TESTDIR) -f $(TESTDIR)/Makefile
	@echo ==============================================
	@$(TESTDIR)/test.exe

else

DEPENDS	= $(OFILES:.o=.d)

$(OUTPUT): $(OFILES)
	@echo linking...
	@$(LD) $(LDFLAGS) -o $@ $^

-include $(DEPENDS)

endif