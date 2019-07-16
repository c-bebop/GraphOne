#include "communicator.h"
#include "graph.h"

void create_2d_comm()
{
    // extract the original group handle
    int group_count = _numtasks - 1;
    int *ranks1 = (int*)malloc(sizeof(int)*group_count);

    for (int i = 0; i < group_count; ++i) {
        ranks1[i] = i+1;
    }
    MPI_Group  orig_group, analytics_group;
    
    MPI_Comm_group(MPI_COMM_WORLD, &orig_group);
    MPI_Group_incl(orig_group, group_count, ranks1, &analytics_group);

    //create new communicator 
    MPI_Comm_create(MPI_COMM_WORLD, analytics_group, &_analytics_comm);
}

void create_1d_comm()
{
    // extract the original group handle
    int group_count = _numtasks - 1;
    int *ranks1 = (int*)malloc(sizeof(int)*group_count);

    for (int i = 0; i < group_count; ++i) {
        ranks1[i] = i+1;
    }
    MPI_Group  orig_group, analytics_group;
    
    MPI_Comm_group(MPI_COMM_WORLD, &orig_group);
    //if (_rank > 0) { }
    MPI_Group_incl(orig_group, group_count, ranks1, &analytics_group);

    //create new communicator 
    MPI_Comm_create(MPI_COMM_WORLD, analytics_group, &_analytics_comm);
    
}
