#include<unistd.h>
#include<sys/reboot.h>

int main () {
    sync();
    reboot(RB_AUTOBOOT);

    return 0;
}