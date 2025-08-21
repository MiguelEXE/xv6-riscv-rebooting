#include "kernel/types.h"
#include "user/user.h"
#include "kernel/reboot.h"

int main(int argc, char* argv[]){
	fprintf(1, "Powering off system...\n");
	reboot(SYS_POWEROFF);
	fprintf(2, "Powering off failed!\n");
	return 1;
}
