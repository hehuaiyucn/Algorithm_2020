#include<stdio.h>


// 我国古代数学家张丘建在《算经》一书中提出的数学问题：
// 鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。
// 百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？

void hundredFowlsMoneys() {
	int x, y, z;
	for (x = 0; x <= 20; x++) {
		for (y = 0; y <= 33; y++) {
			z = 100 - x - y;
			if (z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100) {
				printf("������%d,��ĸ��%d,������%d\n", x, y, z);
			}
		}
	}
}

//int main() {
//	hundredFowlsMoneys();
//	return 0;
//}