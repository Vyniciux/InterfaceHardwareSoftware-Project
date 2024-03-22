#include "de2i.h"

bool is_b_pressed(int b){

    int fd = open("/dev/mydev", O_RDWR);

    unsigned int data;
    ioctl(fd, RD_PBUTTONS);
	read(fd, &data, 1);

    printf("Leu dos botões: 0x%X\n", data);

    int buttons[4];

    buttons[0]=data%2;
    buttons[1]=(data/2)%2;
    buttons[2]=(data/4)%2;
    buttons[3]=(data/8)%2;

    close(fd);

    return buttons[b];
}

void writing_red_leds(bool *posicoes){

    int fd = open("/dev/mydev", O_RDWR);

    unsigned int data = 0; 
    data += posicoes[17];
    for (int i = 1; i < 17; i++)
    {

        printf ("!! posi = %d\n", posicoes[i]);
        int j = i, var=1;
        while (j > 0)
        {
            var *= posicoes[17-i] * 2;
            j--;
        }
        data+=var;
    }
    printf ("!! data = %u\n", data);
    ioctl(fd, WR_RED_LEDS);
	int retval = write (fd, &data, sizeof(data));

    close(fd);
}

void is_s_pressed(bool *buttons){

    int fd = open("/dev/mydev", O_RDWR);

    unsigned int data;
    ioctl(fd, RD_SWITCHES);
	read(fd, &data, 3);

    //printf("Leu dos switches: 0x%X\n", data);

    buttons[0]=data%2;
    buttons[1]=(data/2)%2;
    buttons[2]=(data/4)%2;
    buttons[3]=(data/8)%2;
    buttons[4]=(data/16)%2;
    buttons[5]=(data/32)%2;
    buttons[6]=(data/64)%2;
    buttons[7]=(data/128)%2;
    buttons[8]=(data/256)%2;
    buttons[9]=(data/512)%2;
    buttons[10]=(data/1024)%2;
    buttons[11]=(data/2048)%2;
    buttons[12]=(data/4096)%2;
    buttons[13]=(data/8192)%2;
    buttons[14]=(data/16384)%2;
    buttons[15]=(data/32768)%2;
    buttons[16]=(data/65463)%2;
    buttons[17]=(data/131072)%2;

    close(fd);

}