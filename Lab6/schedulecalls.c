/* Change to the SCHED_RR policy and the highest priority, then */
/* lowest priority, then back to the original policy and priority. */

#include <unistd.h>
#include <sched.h>
#include <stdio.h>
main ()
{
struct sched_param param;  //copy sched_param structure to param
struct timespec rr_interval;  //copy timespec structure to rr_interval
int my_pid = 0;
int old_policy, new_policy, old_priority;
int low_priority, high_priority;

/* Determine the round-robin quantum */
sched_rr_get_interval(my_pid, &rr_interval);
printf("Round-robin quantum is %lu seconds, %ld nanoseconds\n",rr_interval.tv_nsec);

/* Get parameters to use later. Do this now */
/* Avoid overhead during time-critical phases.*/
high_priority = sched_get_priority_max(SCHED_RR);
printf("High Priority %d\n",high_priority);
low_priority = sched_get_priority_min(SCHED_RR);
printf("Low Priority %d\n",low_priority);


/* Save the old policy for when it is restored. */
old_policy = sched_getscheduler(my_pid);
printf("Old Policy is %d\n",old_policy);

/* Get all fields of the param structure. This is where */
/* fields other than priority get filled in. */
sched_getparam(my_pid, &param);
printf("Scheduler parameters %d\n",param.sched_priority);

/* Keep track of the old priority. */
old_priority = param.sched_priority;

int fork_value, try_cnt, tmp_nbr;
fork_value = fork();                                               //create new process
if(fork_value == -1)                                               //check for error
    printf("Child was not created sucessfully");
if(fork_value == 0)
    printf("Child PID is %d\n",getpid());

/* Change to SCHED_RR, highest priority. The param */
/* fields other than priority get used here.*/
param.sched_priority = high_priority;
sched_setscheduler(my_pid, SCHED_RR, &param);
printf("Scheduler parameters %d\n",param.sched_priority);

/* CPU intensive code, new process will run this */ 
for (try_cnt = 0; try_cnt < 100; try_cnt++) 
/* Perform some CPU-intensive operations */ 
{ 
    for(int loop_cnt = 0; loop_cnt < 1000000; loop_cnt++) 
    { 
        tmp_nbr+=loop_cnt; 
        tmp_nbr-=loop_cnt; 
    } 
} 
printf("Completed test %d\n",try_cnt);

/* Print the value associated with the RR policy */
new_policy = sched_getscheduler(my_pid);
printf("New Policy is %d\n",new_policy);

/* Change to SCHED_RR, lowest priority. The param */
/* fields other than priority get used here, too. */
param.sched_priority = low_priority;
sched_setparam(my_pid, &param);

/* Restore original policy, parameters. Again, other */
/* param fields are used here. */
param.sched_priority = old_priority;
sched_setscheduler(my_pid, old_policy, &param);
return(0);
}
