// Write a program to implement round robin scheduling concept using a linked list.
// Each node represents a process with attributes as& lt;PID, CPU_time& gt;.A quantum time T
// will be input by the user.A process will be executed(when user wants) for quantum
// time Tand the CPU_time will be updated with CPU_time T, and the current process
// node is deleted from the beginningand added to the end of the list.If the updated
// CPU_time is& lt; = 0, then the process is deleted from the list.After a process is executed
// for T time, the the next process in the queue is executed upon user choice.The entire
// process gets completed when all process nodes are deleted.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    char* PID;
    float CPU_time;
    struct node* next;
};

void create(char PID[20], float CPU_time, struct node** start)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->PID = PID;
    node->CPU_time = CPU_time;
    node->next = NULL;

    if ((*start) == NULL) {
        printf("null");
        (*start) = node;
    }

    else
    {
        struct node* temp = (*start);
        while (temp->next != NULL) {
            printf("%s\n", temp->PID);

            temp = temp->next;
        }
        temp->next = node;
    }
}

void execute(float CPU_time, struct node** start)
{
    if (CPU_time <= 0)
    {
        *start = (*start)->next;
        return;
    }

    struct node* node = *start;
    (*start)->CPU_time = CPU_time;
    *start = (*start)->next;
    struct node* temp = *start;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    node->next = NULL;
}

void display(struct node* start)
{
    struct node* temp = start;
    while (temp)
    {
        printf("\nPID : %s\tCPU Time : %f\t", temp->PID, temp->CPU_time);
        temp = temp->next;
    }
}

int terminate(struct node* start)
{
    if (!start)
        return 0;
    return 1;
}

void main()
{
    struct node* start = NULL;
    int flag = 1;
    while (flag)
    {
        int ch;
        printf("\n\nMENU");
        printf("\n1. Add Process\n2.Execute Process\n3. Display Processes\nEnter Choice : ");
        scanf("%d", &ch);

        float CPU_time;
        switch (ch)
        {
            char PID[20];
        case 1:
            printf("Enter PID : ");
            scanf("%s", &PID);
            printf("Enter CPU_time : ");
            scanf("%f", &CPU_time);
            create(PID, CPU_time, &start);
            break;

        case 2:
            if (!start)
            {
                printf("No Process Found");
                continue;
            }
            printf("Enter updated CPU_time for process %s : ", start->PID);
            scanf("%f", &CPU_time);
            execute(CPU_time, &start);
            flag = terminate(start);
            break;

        case 3:
            display(start);
            break;

        default:
            printf("INVALID INPUt");
        }
    }

}