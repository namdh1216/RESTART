#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>


int ran(int a, int b) {
	return rand() % a + b;
}


void sp() {
	Sleep(500);
}

int cat = 1;

int main(void) {
	srand((unsigned int)time(NULL));
	char name[50];
	printf("****고양이와 수프 VER2****\n");
	printf(" /\\_/\\  \n");
	printf("( o.o ) \n");
	printf(" > ^ <  \n");
	printf("야옹이의 이름을 지어주세요:");
	scanf_s("%s", name, sizeof(name));
	printf("야옹이의 이름은 %s입니다.", name);
	Sleep(1000); system("cls");

	int RE = 2;
	int Move;
	int Soup = 0;
	int CP = 0;
	int Feelings = 3;



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
		printf("집사와의 관계(0~4): %d\n", RE);
		switch (RE) {
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

		//기분 나빠지는 로직
		int DiceRoll = ran(6, 1);
		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다. 고양이니까?\n", RE, 6 - RE);
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이(가) 나왔습니다.\n", DiceRoll);
		if (DiceRoll <= 6 - RE) {
			int 기분 = Feelings;
			if (Feelings <= 0) {
				printf("더이상 기분이 나빠지지 않습니다.: ");
			}
			else {
				Feelings--;
				printf("%s의 기분이 나빠집니다: ", name);
			}
			printf("%d->%d\n", 기분, Feelings);
		}
		
	}
}