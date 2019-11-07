#include <time.h>
#include <stdint.h>
#include <naiveConsole.h>
#include <syscall.h>

#include <video_driver.h>

static void int_20();
static void int_80();
//int averiguo_que_syscall_es();
static void int_21();
void timer_handler();
int getKey();


void irqDispatcher(uint64_t irq) {
	switch (irq) {
		case 0:  // si le vino el numero 0, significa que esta interrumpiendo algo desde el IRQ 0 (es el Timer Tick)
			int_20();			
			break;
		case 0x21: // esta bien que este esta linea?? ya que para mi solamente puede venir con los valores 1-5 (de los IRQ)
		case 1:
			int_21();
			break;
		case 0x80:     // mirar comentario de la funcion _irq80Handler en el archivo interrupts.asm
			int_80();
			break;
	}
	return;
}

void int_20() {   //TIMER TICK
	timer_handler();
}


char get_char() {   // no se si está bien que esta funcion esté acá. en el ejemplo del Drive ponia esta sola funcion en un archivo a parte
					// llamado keyboard_driver.c
	char map[] = { '\0', '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', '¿', '\b',
					'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\0', '+', '\n',
					'\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'ñ', '{', '|', '\0',
					'}', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', '\0', '\0', '\0', ' '};
	int len = sizeof(map);
	char k = getKey();
	if (k>0  &&  k<len  &&  map[k]!='\0')
		return map[k];
	return -1;
}

void int_21() {  // TECLADO
	ncClear();
	char letra = get_char();
	drawChar(100, 100, letra, 10, 0xFFFFFF, 0x00FF00);

	//ncPrintChar(letra);
     
     /* CODIGO DE HORACIO
	ncNewline();
	ncPrint("esperando tecla");
    
	int i = getKey();
	int teclaHex = i;
	int teclaHexAnterior = i;
	ncNewline();
	ncPrint("tecla Recibida");
	ncNewline();
    ncPrintHex (teclaHex);
	for (int j=1 ; j < 1000 ; j++) {         
		j=getKey();
		teclaHex = j;
		if(teclaHex != teclaHexAnterior) {       
			ncPrintHex (teclaHex);
			teclaHexAnterior = teclaHex;
		}      
	}
	*/
}


void int_80(){
	int a = averiguo_que_syscall_es();
	switch(a){
		case 4:{
			int b = averiguo_que_salida_es();
			switch(b){
				case 1:{
					char* c = consigo_buffer();
					ncClear();
					ncPrint(c);
				}
			}
		}
	}
}