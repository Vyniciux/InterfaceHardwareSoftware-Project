#include <stdio.h>	/* printf */
#include <stdlib.h>	/* malloc, atoi, rand... */
#include <string.h>	/* memcpy, strlen... */
#include <stdint.h>	/* uints types */
#include <sys/types.h>	/* size_t ,ssize_t, off_t... */
#include <unistd.h>	/* close() read() write() */
#include <fcntl.h>	/* open() */
#include <sys/ioctl.h>	/* ioctl() */
#include <errno.h>	/* error codes */

// ioctl commands defined for the pci driver header
#include "ioctl_cmds.h"

int main(int argc, char** argv)
{
	printf("hello world\n");
	
	int fd, retval;
	fd = open("/dev/mydev", O_RDWR);

	if (fd < 0) {
		printf("Error opening file %d\n", fd);
	}else{
		printf("Succes opening file %d\n", fd);
	}

	unsigned int data = 0xFF;

	data = 0x33;
	ioctl(fd, WR_GREEN_LEDS);
	retval = write(fd, &data, sizeof(data));
	printf("wrote 0x%X, %d bytes in green leds\n", data, retval);

	data = 0x0;
	ioctl(fd, WR_RED_LEDS);
	retval = write(fd, &data, sizeof(data));
	printf("wrote 0x%X, %d bytes in red leds\n", data, retval);

	data = 0xFFFFFFFF;
	ioctl(fd, WR_R_DISPLAY);
	retval = write(fd, &data, sizeof(data));
	printf("wrote 0x%X, %d bytes in l display\n", data, retval);

	data = 0xFFFFFFFF;
	ioctl(fd, WR_L_DISPLAY);
	retval = write(fd, &data, sizeof(data));
	printf("wrote 0x%X, %d bytes in r display\n", data, retval);
	
	unsigned int long long data2;
	ioctl(fd, RD_SWITCHES);
	retval = read(fd, &data2, 1);
	printf("Leu dos switches: 0x%llu\n", data2);


	ioctl(fd, RD_PBUTTONS);
	retval = read(fd, &data2, 1);

	if(data2 != 0xFF){

		printf("Pressed!\n");
		
	}		
	printf("Leu dos botões: 0x%X\n", data2);

	close(fd);
	return 0;
}
