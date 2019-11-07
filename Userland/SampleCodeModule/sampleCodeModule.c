/* sampleCodeModule.c */

char * v = (char*)0xB8000 + 40;
static int var1 = 0;
static int var2 = 0;

extern void syscall(int, int, char*, int);

int main() {
	
	//syscall(4, 1, "hola", 4);

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}

//El Barto
