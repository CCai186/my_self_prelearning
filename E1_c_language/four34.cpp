#include <stdio.h>
int main(void)
{
	int x4=4,y4=4,z4=2;
	if (x4<3 && y4>3) {
		printf("Test OK!\n");
	}
	// 去掉了第二个条件
	else if (z4>3 && x4>=3) {
		printf("Test OK!\n");
	}
	else if (z4<=3 && y4>=3) {
		printf("Test OK!\n");
	}
	else {
		printf("Test failed!\n");
	}
	return 0;
}