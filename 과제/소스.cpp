#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 15
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

int random(int a, int b) {
	return rand() % a + b;
}

void sp() {
	Sleep(500);
}

int cat = 1;

int main(void) {
	srand((unsigned int)time(NULL));
	char name[50];
	printf("****�߿��̿� ����****\n");
	printf("      /\\_/\\\n /\\  / o o \\\n//\\\\ \\~(*)~/\n`  \\/   ^ / \n   l \\ll ll \n   \\ 'll ll \n    \\)()-())\n");
	printf("�߿����� �̸��� �����ּ���:");
	scanf_s("%s", name, sizeof(name));
	printf("�߿����� �̸��� %s�Դϴ�.", name);
	Sleep(1000); system("cls");



	int match = 2;
	int Move;
	int Soup = 0;
	int catback;
	int Choice;
	int CP = 0;
	int Feelings = 3;
	int S = random(BWL_POS, HME_POS);
	int T = random(BWL_POS, HME_POS);
	int Tset = 0;
	int Sset = 0;

	while (1) {
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", Soup);
		printf("CP: %d ����Ʈ\n", CP);
		printf("%s ���(0~3): %d\n", name, Feelings);
		switch (Feelings) {
		default:
			printf("����� �ſ� ���޴ϴ�.\n");
			break;
		case 1:
			printf("�ɽ����մϴ�.\n");
			break;
		case 2:
			printf("�Ļ��� �����ϴ�.\n");
			break;
		case 3:
			printf("������ �θ��ϴ�.\n");
			break;
		}
		printf("������� ����(0~4): %d\n", match);
		switch (match) {
		case 4:
			printf("���� �������Դϴ�.\n");
			break;
		case 3:
			printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
			break;
		case 2:
			printf("�׷����� �� ���� �����Դϴ�.\n");
			break;
		case 1:
			printf("���� ���Ǳ� ����Դϴ�.\n");
			break;
		default:
			printf("�翡 ���� ������ �Ⱦ��մϴ�.\n");
			break;
		}
		printf("==================================================\n");
		Sleep(500);

		catback = cat;

	}
}