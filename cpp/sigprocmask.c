/**
 * @FileName    sigprocmask_sigsuspend.c
 * @Describe    A simple example for using sigprocmask and sigsuspend functions in linux.
 * @Author      vfhky 2016-02-29 11:21 https://typecodes.com/cseries/sigprocmasksigsuspendapp.html
 * @Compile     gcc sigprocmask_sigsuspend.c -o sigprocmask_sigsuspend
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

//Signal handle function.
void sig_handler( int signal )
{
    printf( "Receive signal=[%d].\n", signal );
    return;
}

int main( int argc, char *argv[] )
{
    printf( "getpid=[%d].\n", getpid() );
    int i = 0;

    //Register a signal.
    struct sigaction new_act;
    sigemptyset( &new_act.sa_mask );
    new_act.sa_handler = sig_handler;
    new_act.sa_flags = 0;
    sigaction( SIGUSR1, &new_act, 0 );
    sigaction( SIGUSR2, &new_act, 0 );
    sigaction( SIGINT, &new_act, 0 );

    //Add SIGINT, SIGUSR1/SIGUSR2 signals to the signal-set of new_set.
    sigset_t new_set, old_set;
    sigemptyset( &new_set );
    sigaddset( &new_set, SIGINT );              //2
    sigaddset( &new_set, SIGUSR1 );             //10
    //sigaddset( &new_set, SIGUSR2 );           //12

    /**
     * Repalce the old mask set with the new mask set.Thus the process will block the signal of SIGINT and SIGUSR1, 
     * but it will excute the function of sig_handler when the signal such as SIGUSR2 other than SIGINT, SIGUSR1 arrives.
     */
    sigprocmask( SIG_SETMASK, &new_set, &old_set );

    //Add SIGUSR1 and SIGUSR2 signals to the signal-set of pendmask.
    sigset_t pendmask;
    sigemptyset( &pendmask );
    sigaddset( &pendmask, SIGUSR1 );            //10
    sigaddset( &pendmask, SIGUSR2 );            //12

    //Replaces the signal mask of the process with pendmask temporarily and suspends the process until delivery of a signal whose action is to invoke a signal handler or to terminate a process.
    i = sigsuspend( &pendmask );
    printf( "Sigsuspend returned with value[%d].\n", i );
    if( errno == EINTR )
    {
        printf( "[%d]Interrupted by a signal.\n", errno );
    }

    while(1)
    {
        printf( "--while.\n" );
        sleep(3);
    }
    return 0;
}
