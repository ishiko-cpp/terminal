# This file was automatically generated by bakefile.
#
# Any manual changes will be lost if it is regenerated,
# modify the source .bkl file instead if possible.

# You may define standard make variables such as CFLAGS or
# CXXFLAGS to affect the build. For example, you could use:
#
#      make CXXFLAGS=-g
#
# to build with debug information. The full list of variables
# that can be used by this makefile is:
# AR, CC, CFLAGS, CPPFLAGS, CXX, CXXFLAGS, LD, LDFLAGS, MAKE, RANLIB.

# You may also specify config=Debug|Release
# or their corresponding lower case variants on make command line to select
# the corresponding default flags values.
ifeq ($(config),debug)
override config := Debug
endif
ifeq ($(config),release)
override config := Release
endif
ifeq ($(config),Debug)
override CPPFLAGS += -DDEBUG
override CFLAGS += -g -O0
override CXXFLAGS += -g -O0
override LDFLAGS += -g
else ifeq ($(config),Release)
override CPPFLAGS += -DNDEBUG
override CFLAGS += -O2
override CXXFLAGS += -O2
else ifneq (,$(config))
$(warning Unknown configuration "$(config)")
endif
#
# Additionally, this makefile is customizable with the following
# settings:
#
#      ISHIKO_CPP_BOOST_ROOT  Path to the Boost installation
#      ISHIKO_CPP_TYPES_ROOT  Path to the Ishiko/C++ Types installation

# Use "make RANLIB=''" for platforms without ranlib.
RANLIB ?= ranlib

CC := cc
CXX := c++

_true  := true
_false :=
_not    = $(if $(1),$(_false),$(_true_))
_equal  = $(and $(findstring $(1),$(2)),$(findstring $(2),$(1)))


# The directory for the build files, may be overridden on make command line.
builddir = .

ifneq ($(builddir),.)
_builddir := $(if $(findstring $(abspath $(builddir)),$(builddir)),,../../)$(builddir)/../gnumake/
_builddir_error := $(shell mkdir -p $(_builddir) 2>&1)
$(if $(_builddir_error),$(error Failed to create build directory: $(_builddir_error)))
endif

# ------------
# Configurable settings:
# 

# Path to the Boost installation
ISHIKO_CPP_BOOST_ROOT ?= $(BOOST_ROOT)
# Path to the Ishiko/C++ Types installation
ISHIKO_CPP_TYPES_ROOT ?= $(ISHIKO_CPP_ROOT)/types

# ------------

all: ../bakefile/../../lib/lib$(if $(call _equal,$(config),Debug),IshikoTerminal-d,IshikoTerminal).a

../bakefile/../../lib/lib$(if $(call _equal,$(config),Debug),IshikoTerminal-d,IshikoTerminal).a: $(_builddir)IshikoTerminal_TerminalOutput.o
	$(AR) rc $@ $(_builddir)IshikoTerminal_TerminalOutput.o
	$(RANLIB) $@

$(_builddir)IshikoTerminal_TerminalOutput.o: ../../src/TerminalOutput.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I../../include/Ishiko/Terminal -std=c++11 ../../src/TerminalOutput.cpp

clean:
	rm -f $(_builddir)*.o
	rm -f $(_builddir)*.d
	rm -f ../bakefile/../../lib/lib$(if $(call _equal,$(config),Debug),IshikoTerminal-d,IshikoTerminal).a

.PHONY: all clean

# Dependencies tracking:
-include $(_builddir)*.d
