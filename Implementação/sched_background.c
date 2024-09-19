// kernel/sched/sched_background.c

#include "sched.h"

// Função para inicializar a estrutura background_rq
void init_rq_background(struct rq *rq)
{
    INIT_LIST_HEAD(&rq->background.queue);
    rq->background.nr_running = 0;
}

// Função para adicionar tarefa à fila de background
void enqueue_task_background(struct rq *rq, struct task_struct *p, int flags)
{
    add_nr_running(rq, 1);
    list_add_tail(&p->tasks, &rq->background.queue);  // Corrigido para 'tasks'
}

// Função para remover tarefa da fila de background
void dequeue_task_background(struct rq *rq, struct task_struct *p, int flags)
{
    sub_nr_running(rq, 1);
    list_del(&p->tasks);  // Corrigido para 'tasks'
}

// Função para escolher a próxima tarefa de background
struct task_struct *pick_next_task_background(struct rq *rq)
{
    struct task_struct *next = NULL;

    if (rq->background.nr_running == 0)
        return NULL;

    list_for_each_entry(next, &rq->background.queue, tasks) {  // Corrigido para 'tasks'
        return next;
    }

    return NULL;
}

const struct sched_class background_sched_class = {
    .enqueue_task       = enqueue_task_background,
    .dequeue_task       = dequeue_task_background,
    .pick_next_task     = pick_next_task_background,
    // Outras funções podem ser implementadas conforme necessário
};

EXPORT_SYMBOL(pick_next_task_background);

