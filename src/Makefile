VERSION = 0.0.3
TARGET = splayer

RM = rm
MKDIR = mkdir
CC = gcc
STD = -std=gnu11
OPTIMIZATION ?= -O1
PLATFORM = linux

DEBUG = -g
OPT = $(OPTIMIZATION)
WARN = -Wall -W -Wno-missing-field-intializers \
       -Werror=deprecated-declarations

FINAL_CFLAGS = $(STD) $(OPT) $(WARN) $(DEBUG) $(CFLAGS)
FINAL_LDFLAGS = $(LDFLAGS)
FINAL_LIBS = -lm -lpthread


FFMPEG_PREFIX ?= ../deps/ffmpeg/$(PLATFORM)/
ifdef FFMPEG_PREFIX
	FFMPEG_CFLAGS = -I$(FFMPEG_PREFIX)/include
	FFMPEG_LDFLAGS = -L$(FFMPEG_PREFIX)/lib
	FFMPEG_LIBS = -lavformat -lavcodec -lavutil -lavfilter -lswscale -lswresample

	FINAL_CFLAGS += $(FFMPEG_CFLAGS)
	FINAL_LDFLAGS += $(FFMPEG_LDFLAGS)
	FINAL_LIBS += $(FFMPEG_LIBS)
endif

CFLAGS = -I./core \
	 -I./demuxer -I./demuxer/modules \
	 -I./tests

SRCS = $(wildcard core/*.c \
       		  demuxer/*.c demuxer/modules/*.c \
       		  tests/*.c)


all:
	@echo "all building ..."
	$(CC) $(SRCS) $(FINAL_CFLAGS) $(FINAL_LDFLAGS) $(FINAL_LIBS) -o $(TARGET).$(VERSION)

clean:
	@echo "cleaning ..."
	$(RM) $(TARGET).$(VERSION)
