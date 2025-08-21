#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "reboot.h"

/*
                test@100000 {
                        phandle = <0x08>;
                        reg = <0x00 0x100000 0x00 0x1000>;
                        compatible = "sifive,test1\0sifive,test0\0syscon";
                };
*/

/*
        poweroff {
                value = <0x5555>;
                offset = <0x00>;
                regmap = <0x08>;
                compatible = "syscon-poweroff";
        };

        reboot {
                value = <0x7777>;
                offset = <0x00>;
                regmap = <0x08>;
                compatible = "syscon-reboot";
        };
*/
// 0x5555 to poweroff
// 0x7777 to reboot

uint64
sys_reboot(void)
{
	int rebootType;
	argint(0, &rebootType);

	switch(rebootType){
		case SYS_POWEROFF:
			*RBCTRL = 0x5555;
			return 0;
		case SYS_REBOOT:
			*RBCTRL = 0x7777;
			return 0;
		case SYS_HALT:
			panic("System halted normally.");
			return 0;
		default:
			return -1;
	}
}
