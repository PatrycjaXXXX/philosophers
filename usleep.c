#include <sys/time.h>
#include <stdlib.h> //atoi
#include <stdint.h> // int64_t
#include <unistd.h> //usleep
#include <stdio.h> //printf

int  get_difference(struct timeval start, struct timeval end)
{
  time_t  sec_diff;
  suseconds_t  usec_diff;

  sec_diff = end.tv_sec - start.tv_sec;
  usec_diff = end.tv_usec - start.tv_usec;
  return((int)(sec_diff*1000) + (int)(usec_diff/1000));
}

int main(int ac, char **av)
{
  int64_t         requestet_time;
  struct timeval  start;
  struct timeval  end;
  int             real_time;
    
  if (ac != 2)
    return (-1);
  requestet_time = (int64_t)atoi(av[1]);
  gettimeofday(&start, NULL);
  usleep(requestet_time);
  gettimeofday(&end, NULL);
  real_time = get_difference(strat, end);
  ptintf("requestet: %i, real: %i\n", (int)requestet_time, real_time);
  
  
}
