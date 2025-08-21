#include "kernel/types.h"
#include "user/user.h"
#include "kernel/reboot.h"

int main(int argc, char* argv[]){
	fprintf(1, "Halting system...\n");
	reboot(SYS_HALT);
	fprintf(2, "Halt failed!\n");
	return 1;
}
