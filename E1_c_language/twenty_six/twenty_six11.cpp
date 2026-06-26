#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} *link;

link create_circle(int n)
{
    link head = (link)malloc(sizeof(struct node));
    head->num = 1;
    link tail = head;

    for (int i = 2; i <= n; i++) {
        link p = (link)malloc(sizeof(struct node));
        p->num = i;
        tail->next = p;
        tail = p;
    }
    tail->next = head;
    return head;
}

int main(void)
{
    int n = 5;   // 总人数
    int m = 3;   // 数到几出局

    link curr = create_circle(n);
    link prev = NULL;

    printf("被杀顺序：");
    while (curr->next != curr) {
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        printf("%d ", curr->num);
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }

    printf("\n幸存者编号：%d\n", curr->num);
    free(curr);
    return 0;
}
