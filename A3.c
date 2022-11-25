#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct node{
    struct node *next;
};
struct head{
    int count;
    struct node *start;
};
void create(struct head st[]){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->next = NULL;

    if(st[3].count == SIZE)
    {
        printf("\nNo more consumers can be allowed.\n");
        return;
    }
    for (int i = 0; i < 3;i++)
    {
        if(st[i].count < SIZE)
        {
            if(st[i].count == 0)
            {
                st[i].count++;
                st[i].start = n;
            }
            else
            {
                struct node *temp = st[i].start;
                while(temp -> next != NULL)
                    temp = temp->next;
                temp->next = n;
                st[i].count++;
            }
            break;
        }
    }
}
void conEnter(struct head st[])
{
    if(st[0].count == 0)
    {
        printf("\nNo consumers available in queue.\n");
        return;
    }
    for (int i = 0; i < 3;i++)
    {
        if(i == 0)
        {
            struct node *temp = st[i].start;
            st[i].start = temp->next;
            free(temp);
            st[i].count--;
        }
        else if(st[i].count > 1)
        {
            struct node *temp = st[i].start;
            st[i].start = temp->next;
            temp->next = NULL;
            struct node *t = st[i - 1].start;
            while(t -> next != NULL)
                t = t->next;
            t = temp;
            st[i].count--;
            st[i - 1].count++;
        }
    }
}
int main(){
    struct head st[3];
    for (int i = 0; i < 3;i++){
        st[i].count = 0;
        st[i].start = NULL;
    }
    int n = 1, ch;
    while(n == 1){
        printf("Choose: \n");
        printf("1. Add consumers \n");
        printf("2. Check the crowd\n");
        printf("3. Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:{
                create(st);
                break;
            }
            case 2:{
                conEnter(st);
                break;
            }
            case 3:{
                exit(0);
                break;
            }
        }
        printf("If you want to continue, Press 1 or 0 - ");
        scanf("%d", &n);
        if(n == 0)
            exit(0);
    }
}
