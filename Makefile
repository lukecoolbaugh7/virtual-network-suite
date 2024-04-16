CFLAGS = -I
CFLAGS += -Werror=return-type

LDLIBS = -lpthread

HEADERS = sys_utils.h tap_utils.h
TARGET = vport 
OBJS = vport.o tap_utils.o 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(TARGET)