#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main() {
    struct timeval start, end;
    struct rusage usage;

    // Marca o início do tempo
    gettimeofday(&start, NULL);

    // Processo simulado (intensivo em CPU)
    for (long i = 0; i < 1000000000; i++);

    // Marca o fim do tempo
    gettimeofday(&end, NULL);

    // Tempo de uso do sistema e do usuário
    getrusage(RUSAGE_SELF, &usage);

    // Calcula o tempo decorrido
    long seconds = end.tv_sec - start.tv_sec;
    long micros = ((seconds * 1000000) + end.tv_usec) - start.tv_usec;

    printf("Tempo de wallclock: %ld microssegundos\n", micros);
    printf("Tempo de usuário: %ld microssegundos\n", usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec);
    printf("Tempo de sistema: %ld microssegundos\n", usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec);

    return 0;
}

