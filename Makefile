DISTRIBUTABLES += $(wildcard LICENSE*) res
RACK_DIR ?= ../..

SHELL:=/bin/bash -O extglob

FLAGS = \
    -Wno-deprecated-declarations \
	-O0 \
	-Werror=implicit-function-declaration \
	-Isrc \
	-Ilib/oscpack \

SOURCES = \
	$(wildcard src/*.cpp) \

MACHINE = $(shell $(CC) -dumpmachine)
ifneq (, $(findstring mingw, $(MACHINE)))
	LDFLAGS += -lws2_32 -lwinmm
else
endif

FLAGS := $(filter-out -MMD,$(FLAGS))

include $(RACK_DIR)/plugin.mk
