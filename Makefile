TARGET=biochksum

all:
	cc -g -Wall -O2 -o ${TARGET} *.[ch]

.PHONY: clean
clean:
	rm -f ${TARGET}.o ${TARGET}
