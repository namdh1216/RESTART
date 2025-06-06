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
	printf("****야옹이와 수프****\n");
	printf("      /\\_/\\\n /\\  / o o \\\n//\\\\ \\~(*)~/\n`  \\/   ^ / \n   l \\ll ll \n   \\ 'll ll \n    \\)()-())\n");
	printf("야옹이의 이름을 지어주세요:");
	scanf_s("%s", name, sizeof(name));
	printf("야옹이의 이름은 %s입니다.", name);
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
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", Soup);
		printf("CP: %d 포인트\n", CP);
		printf("%s 기분(0~3): %d\n", name, Feelings);
		switch (Feelings) {
		default:
			printf("기분이 매우 나쁩니다.\n");
			break;
		case 1:
			printf("심심해합니다.\n");
			break;
		case 2:
			printf("식빵을 굽습니다.\n");
			break;
		case 3:
			printf("골골송을 부릅니다.\n");
			break;
		}
		printf("집사와의 관계(0~4): %d\n", match);
		switch (match) {
		case 4:
			printf("집사 껌딱지입니다.\n");
			break;
		case 3:
			printf("훌륭한 집사로 인정 받고 있습니다.\n");
			break;
		case 2:
			printf("그럭저럭 쓸 만한 집사입니다.\n");
			break;
		case 1:
			printf("간식 자판기 취급입니다.\n");
			break;
		default:
			printf("곁에 오는 것조차 싫어합니다.\n");
			break;
		}
		printf("==================================================\n");
		Sleep(500);

		catback = cat;

	}
}