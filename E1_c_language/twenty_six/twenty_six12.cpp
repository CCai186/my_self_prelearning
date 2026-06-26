#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct log_node {
    int line_no;
    char date[20];
    char time[20];
    struct log_node *next;
} *log_link;

void insert_sorted(log_link *head, log_link new_node)
{
    log_link *pnext = head;
    while (*pnext != NULL) {
        int time_cmp = strcmp((*pnext)->time, new_node->time);
        if (time_cmp > 0)
            break;
        if (time_cmp == 0 && strcmp((*pnext)->date, new_node->date) > 0)
            break;
        pnext = &(*pnext)->next;
    }
    new_node->next = *pnext;
    *pnext = new_node;
}

int main(void)
{
    FILE *in = fopen("in.txt", "r");
    if (!in) {
        perror("打开in.txt失败");
        return 1;
    }

    log_link head = NULL;
    int line_no;
    char date[20], time[20];

    while (fscanf(in, "%d %s %s", &line_no, date, time) == 3) {
        log_link node = (log_link)malloc(sizeof(struct log_node));
        node->line_no = line_no;
        strcpy(node->date, date);
        strcpy(node->time, time);
        insert_sorted(&head, node);
    }
    fclose(in);

    FILE *out = fopen("out.txt", "w");
    if (!out) {
        perror("创建输出文件失败");
        return 1;
    }

    int new_no = 1;
    log_link p = head;
    while (p) {
        fprintf(out, "%d %s %s\n", new_no++, p->date, p->time);
        log_link tmp = p;
        p = p->next;
        free(tmp);
    }
    fclose(out);
    printf("排序完成，结果已写入 out.txt\n");
    return 0;
}
