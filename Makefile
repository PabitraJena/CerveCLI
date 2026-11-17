CC = gcc
TARGET = a.exe

CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = -lws2_32
CPPFLAGS = -Iinclude

SRCS = main.c $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	@powershell -NoProfile -ExecutionPolicy Bypass -Command "$$files = '$(TARGET) $(OBJS) $(DEPS)'.Split(' '); Remove-Item -LiteralPath $$files -Force -ErrorAction SilentlyContinue"

rebuild: clean all

.PHONY: all clean rebuild