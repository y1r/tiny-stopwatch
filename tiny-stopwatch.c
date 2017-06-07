#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>

#include <unistd.h>
#include <signal.h>

#define N 256

unsigned int elapsed_time = 0;

void sig_handler( int sig );

int main(int argc, char *argv[]){
    time_t current;
    struct tm *timeptr;
    char time_string[N];

    if( argc == 2 )
        elapsed_time = atoi(argv[1]);

    if( SIG_ERR == signal( SIGINT, sig_handler ) )
    {
        printf("failed to set signal handler\n");
        exit(EXIT_FAILURE);
    }

    while( true )
    {
        current = time(NULL);
        timeptr = localtime(&current);
        strftime( time_string, N, "%F %T", timeptr );
        int h = elapsed_time / (60*60);
        int m = ( elapsed_time / 60 ) % 60;
        int s = elapsed_time % 60;
        printf( "%s %02u:%02u:%02u", time_string, h, m, s );
        fflush(stdout);
        elapsed_time++;
        sleep(1);
        putchar('\r');
    }

    return 0;
}

void sig_handler( int sig )
{
    switch(sig){
        case SIGINT:
            printf("\n\n%u\n", elapsed_time);
            exit(EXIT_SUCCESS);
    }
}
