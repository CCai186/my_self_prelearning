#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int top = 0;

void push(struct point p) { stack[top++] = p; }
struct point pop(void) { return stack[--top]; }
int is_empty(void) { return top == 0; }

int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

void visit(int row, int col, struct point pre)
{
    struct point visit_point = { row, col };
    maze[row][col] = 2;
    predecessor[row][col] = pre;
    push(visit_point);
}

int main(void)
{
    struct point p = { 0, 0 };
    maze[p.row][p.col] = 2;
    push(p);    
    
    while (!is_empty()) {
        p = pop();
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
            break;
        if (p.col+1 < MAX_COL && maze[p.row][p.col+1] == 0)
            visit(p.row, p.col+1, p);
        if (p.row+1 < MAX_ROW && maze[p.row+1][p.col] == 0)
            visit(p.row+1, p.col, p);
        if (p.col-1 >= 0 && maze[p.row][p.col-1] == 0)
            visit(p.row, p.col-1, p);
        if (p.row-1 >= 0 && maze[p.row-1][p.col] == 0)
            visit(p.row-1, p.col, p);
    }

    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        struct point path[256];
        int path_len = 0;

        while (1) {
            path[path_len++] = p;
            if (predecessor[p.row][p.col].row == -1)
                break;
            p = predecessor[p.row][p.col];
        }

        printf("正向路线：\n");
        for (int i = path_len - 1; i >= 0; i--) {
            printf("(%d, %d)\n", path[i].row, path[i].col);
        }
    } else {
        printf("No path!\n");
    }

    return 0;
}