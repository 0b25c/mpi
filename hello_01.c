#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define MASTER 0

int main(int argc, char *argv[]){

    int numOftasks, taskid, len;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numOftasks);
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid);

    MPI_Get_processor_name(hostname, &len);

    printf("GEIA SOU apo ton TASK %d ON %s !\n",taskid,hostname);

    if(taskid == MASTER)
       printf("MASTER: O Arithmos twn MPI task einai: %d\n",numOftasks);

    MPI_Finalize();
}
