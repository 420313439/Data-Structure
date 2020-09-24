// 单链表
// gcc single-linked-node.c -g -Wall

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

/***** 函数声明 *****/
// 初始化头结点
extern struct Node *init(int val);

// 添加节点到链表末尾
extern struct Node *append(struct Node *head, int val);

// 弹出链表末尾节点
extern int pop(struct Node *head);

// 寻找节点
extern struct Node *search(struct Node *head, int val);

// 打印链表
extern void print_node(struct Node *head);
/***** 函数声明结束 *****/


/* 初始化头结点 */
struct Node *init(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    return node;
}


/* 打印链表 */
void print_node(struct Node *head)
{
    // 如果head不为空，则遍历下一个节点
    while (head != NULL) {
        printf("%d --> ", head->val);
        head = head->next;
    }
    puts("NULL");
}


/* 添加节点到链表末尾 */
struct Node *append(struct Node *head, int val)
{
    struct Node *node = head;

    // 如果head为空，不允许添加
    if (head == NULL)
        puts("Can\'t append a Node to an empty Node");

    // 遍历到链表的末尾（非NULL）
    while (head->next != NULL)
        head = head->next;

    // 把末尾元素的next指针指向新节点
    struct Node *new_node = init(val);
    head->next = new_node;
    
    return node;
}


/* 寻找节点 */
struct Node *search(struct Node *head, int val)
{
    if (head == NULL)
        puts("Empty Node");

    while (head != NULL && val != head->val)
        head = head->next;

    if (head == NULL)
        puts("value not found");
    else if (val == head->val)
        puts("value found!");
    
    return head;
}


/* 弹出链表末尾节点 */
int pop(struct Node *head)
{
    //struct Node *head = *phead;
    struct Node *pre_head;

    if (head == NULL)
        puts("Empty Node");

    while (head->next != NULL) {
        pre_head = head;
        head = head->next;
    }

    int val = head->val;
    pre_head->next = NULL;
    free(head);

    return val;
}



/* main函数 */
int main(void)
{
    struct Node *head = init(0);

    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);

    print_node(head);
    int val = pop(head);
    printf("val = %d\n", val);
    print_node(head);

    printf("%d\n", search(head, 2)->val);

    return 0;
}