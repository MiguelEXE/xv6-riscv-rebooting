#include "kernel/types.h"
#include "user/user.h"
#include "kernel/reboot.h"

int main(int argc, char* argv[]){
	fprintf(1, "Rebooting system...\n");
	reboot(SYS_REBOOT);
	fprintf(2, "Reboot failed!\n");
	return 1;
}
