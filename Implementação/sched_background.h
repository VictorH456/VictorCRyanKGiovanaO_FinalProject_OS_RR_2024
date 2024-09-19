// include/linux/sched_background.h

#ifndef _LINUX_SCHED_BACKGROUND_H
#define _LINUX_SCHED_BACKGROUND_H

#include <linux/list.h>

struct background_rq {
    struct list_head queue; // Lista de tarefas SCHED_BACKGROUND
    int nr_running;         // Número de tarefas em execução
};

#endif // _LINUX_SCHED_BACKGROUND_H

