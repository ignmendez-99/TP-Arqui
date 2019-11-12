include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
ASMSOURCES=$(wildcard asm/*.asm)
ASMOBJECTS=$(ASMSOURCES:.asm=.o)
ASMEXECUTABLE=$(ASMOBJECTS:.o=)

all: $(MODULE) 

$(MODULE): $(SOURCES) $(ASMOBJECTS) $(ASMEXECUTABLE)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld _loader.c $(SOURCES) -o ../$(MODULE)

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

% : %.o
	$(LD) $(ASMLINKEDITFLAGS) -o $@ $<

clean:
	rm -rf asm/*.o *.o 

.PHONY: all clean print
