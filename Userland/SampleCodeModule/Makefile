include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
ASMSOURCES=$(wildcard asm/*.asm)
ASMOBJECTS=$(ASMSOURCES:.asm=.o)
ASMEXECUTABLE=$(ASMOBJECTS:.o=)

all: $(MODULE) compile linkedit

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld _loader.c $(SOURCES) -o ../$(MODULE)

compile:
	$(ASM) $(ASMFLAGS) $(ASMSOURCES)

linkedit:
	$(LD) $(ASMLINKEDITFLAGS) -o $(ASMEXECUTABLE) $(ASMOBJECTS)

clean:
	rm -rf asm/*.o *.o 

.PHONY: all clean print
