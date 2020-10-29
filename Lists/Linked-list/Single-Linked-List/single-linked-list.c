// 单链表
// gcc single-linked-node.c -g -Wall -O3 -o a.out

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

/***** 函数声明开始 *****/
// 初始化头结点
extern struct Node *init(int val);

// 添加节点到链表末尾
extern struct Node *append(struct Node *head, int val);

// 弹出链表末尾节点
extern struct Node *pop(struct Node *head);

// 寻找节点
extern struct Node *search(struct Node *head, int val);

// 插入节点
extern struct Node *insert(struct Node *head, int target_val, int val);

// 删除节点
extern struct Node *delete(struct Node *head, int val);

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
    struct Node *node = head;

    if (node == NULL) {
        puts("search(): Empty Node");
        return NULL;
    }

    while (node != NULL && val != node->val)
        node = node->next;
    if (val == node->val)
        return node;
    else
        return NULL;
}


/* 弹出链表末尾节点 */
struct Node *pop(struct Node *head)
{
    //struct Node *head = *phead;
    struct Node *node = head;
    struct Node *pre_head = NULL;

    if (node == NULL)
        puts("pop(): Empty List");

    while (node->next != NULL) {
        pre_head = node;
        node = node->next;
    }

    pre_head->next = NULL;
    free(node);

    return head;
}


/* 把val插入到值为target_val的节点之后 */
struct Node *insert(struct Node *head, int target_val, int val)
{
    struct Node *target_node = search(head, target_val);
    struct Node *new_node = init(val);

    if (target_node == NULL) {
        printf("insert(): No Such Node with %d", target_val);
        return NULL;
    }    

    new_node->next = target_node->next;
    target_node->next = new_node;

    return head;
}


/* 删除值为val的节点 */
struct Node *delete(struct Node *head, int val)
{
    struct Node *node = head;
    struct Node *pre_node = NULL;
    struct Node *target_node = search(head, val);

    if (node == NULL) {
        puts("delete(): Empty list");
        return NULL;
    }

    // first node eq..
    if (node == target_node) {
        head = node->next;
        free(node);
        return head;
    }

    // 2nd after...
    while (node != target_node && node != NULL) {
        pre_node = node;
        node = node->next;
    }

    if (node == target_node) {
        pre_node->next = node->next;
        free(node);
    }

    return head;
}

/* main函数 */
int main(void)
{
    struct Node *head = init(0);

    append(head, 1);
    append(head, 2);
    append(head, 3);
    print_node(head);
    
    pop(head);
    print_node(head);

    insert(head, 1, 4);
    print_node(head);

    insert(head, 0, 5);
    print_node(head);

    head = delete(head, 0);
    print_node(head);

    return 0;
}