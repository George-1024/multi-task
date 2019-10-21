
/* Simple task test. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "switch.h"


void * sp0;
void * sp1;
void * sp2;
void * sp3;



int stack[900];

void task_1(void *arg, void *context);
void task_2(void *arg, void *context);
void task_3(void *arg, void *context);

void debug_stack(int bottom, int top)
{
	int i = 0;
	for(i = bottom; i<top; i++)
	  printf("stack[%d]=%x\n",i,stack[i]);
}


void task_1(void *arg, void *context)
{
	printf("task_1 started\n");
    while(1)
    {
        printf("switching to task_2\n");
        switch_frame(&sp1, sp2, 0);
        printf("task_1 in control\n");
    }
}

void task_2(void *arg, void *context)
{
    printf("task_2 started\n");
	sp3 = create_frame(&stack[600], (frame_action_t)task_3, 0);
    while(1)
    {
        printf("switching to task_0\n");
        switch_frame(&sp2, sp3, 0);
        printf("task_2 in control\n");
    }
}

void task_3(void *arg, void *context)
{
    printf("task_3 started\n");
    while(1)
    {
        printf("switching to task_0\n");
        switch_frame(&sp3, sp0, 0);
        printf("task_2 in control\n");
    }
}

int main(int argc, char **argv)
{
	
    sp1 = create_frame(&stack[200], (frame_action_t)task_1, 0);
    sp2 = create_frame(&stack[400], (frame_action_t)task_2, 0);

	debug_stack(150, 200);
    while(1)
    {
        printf("switching to task_1\n");
		//void * switch_frame(void **old_frame,void *new_frame, void *arg);
		switch_frame(&sp0, sp1, 0);
        printf("task_0 in control\n");
    }
	
}
