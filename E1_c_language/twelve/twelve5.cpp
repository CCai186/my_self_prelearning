#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define MAX_QUEUE 5

struct point {
    int row, col;
};

struct point queue[MAX_QUEUE];
int head = 0;
int tail = 0;

// 判空
int is_empty(void) {
    return head == tail;
}

// 判满
int is_full(void) {
    return (tail + 1) % MAX_QUEUE == head;
}

// 入队
void enqueue(struct point p) {
    if (is_full()) {
        printf("队列溢出！\n");
        return;
    }
    queue[tail] = p;
    tail = (tail + 1) % MAX_QUEUE;
}

// 出队
struct point dequeue(void) {
    struct point p = queue[head];
    head = (head + 1) % MAX_QUEUE;
    return p;
}

int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

int main(void)
{
    struct point start = {0, 0};
    maze[start.row][start.col] = 2;
    enqueue(start);

    int found = 0;

    while (!is_empty()) {
        struct point p = dequeue();

        // 到达终点
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
            found = 1;
            break;
        }

        // 向右探索
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0) {
            maze[p.row][p.col + 1] = 2;
            struct point next = {p.row, p.col + 1};
            enqueue(next);
        }
        // 向下探索
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0) {
            maze[p.row + 1][p.col] = 2;
            struct point next = {p.row + 1, p.col};
            enqueue(next);
        }
        // 向左探索
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0) {
            maze[p.row][p.col - 1] = 2;
            struct point next = {p.row, p.col - 1};
            enqueue(next);
        }
        // 向上探索
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0) {
            maze[p.row - 1][p.col] = 2;
            struct point next = {p.row - 1, p.col};
            enqueue(next);
        }
    }

    if (found) {
        printf("有路能到达终点\n");
    } else {
        printf("没有路能到达终点\n");
    }

    return 0;
}