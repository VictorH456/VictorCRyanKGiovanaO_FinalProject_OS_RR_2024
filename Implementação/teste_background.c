#include <stdio.h>
#include <sched.h>
#include <unistd.h>

#define SCHED_BACKGROUND 7  // Defina o valor que você deu para SCHED_BACKGROUND

int main() {
    struct sched_param param;
    param.sched_priority = 0;

    // Tentar definir a política SCHED_BACKGROUND
    if (sched_setscheduler(0, SCHED_BACKGROUND, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("SCHED_BACKGROUND aplicada com sucesso!\n");
    return 0;
}
/*
gcc -o test_sched_background test_sched_background.c
sudo ./test_sched_background
*/
