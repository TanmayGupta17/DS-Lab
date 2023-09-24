#include <stdio.h>
#include <stdlib.h>
#define size 100

int s1[size], s2[size];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int x)
{
    if (top1 == size - 1)
    {
        printf("Stack is Full");
    }
    else
    {
        s1[++top1] = x;
    }
}

int pop1()
{
    if (top1 == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        int a = s1[top1];
        top1--;
        return a;
    }
}

void push2(int x)
{
    if (top2 == size - 1)
    {
        printf("Stack is Full");
    }
    else
    {
        s2[++top2] = x;
    }
}

int pop2()
{
    if (top2 == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        int a = s2[top2];
        top2--;
        return a;
    }
}

void Enqueue(int a)
{
    push1(a);
    count++;
}

void Dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int n = pop1();
            push2(n);
        }
        int b = pop2();
        printf("%d was dequeued\n", b);
        count--;
        for (int i = 0; i < count; i++)
        {
            int y = pop2();
            push1(y);
        }
    }
}

void display()
{
    for (int i = 0; i <= top1; i++)
    {
        printf("%d\t", s1[i]);
    }
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Dequeue();
    Enqueue(40);
    display();
}