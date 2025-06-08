#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define 공간크기 15
#define 집위치 1
#define 냄비위치 (공간크기 - 2)
#define 큰값(a, b) ((a) >= (b) ? (a) : (b))

int ran(int a, int b) {
	return rand() % a + b;
}

void sp() {
	Sleep(500);
}

int 고양이위치 = 집위치;
int 이전위치;
char 이름[50];
int 기분, 친밀도;
int CP = 0;
int 쥐장난감구매함;
int 스크 = ran(냄비위치 - 1, 집위치 + 1);
int 캣타 = ran(냄비위치 - 1, 집위치 + 1);
int 캣타워유무 = 0;
int 스크유무 = 0;
int 레이저유무 = 0;
int 쥐유무 = 0;
int 구매;

void 이동로직() {
	if (기분 == 0) {
		if (이전위치 == 집위치) {
			printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", 이름);
			if (기분 < 3) {
				기분++;
			} 
		}
		else {
			printf("기분이 나쁜 %s은(는) 집으로 향합니다.\n", 이름);
			고양이위치--;
		}
	}
	else if (기분 == 1) {
		
		if (스크유무 != 0 && 캣타워유무 != 0) {
			int temp;
			if (abs(고양이위치 - 캣타) > abs(고양이위치 - 스크)) {
				 
				temp = 1;
			}
			else {
			
				temp = 0;
			}

		
			if (temp == 1 && 고양이위치 != 캣타) {
				printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", 이름);
				if (고양이위치 > 캣타) {
					고양이위치--;
				}
				else if (고양이위치 < 캣타) {
					고양이위치++;
				}
			}
			else if (temp == 0 && 고양이위치 != 스크) {
				printf("%s은(는) 심심해서 스크래쳐 쪽으로 이동합니다.\n", 이름);
				if (고양이위치 > 스크) {
					고양이위치--;
				}
				else if (고양이위치 < 스크) {
					고양이위치++;
				}
			}
		}
		
		else {
			printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
			if (기분 > 0) {
				기분--;
			}
		}




	}
	
}

void CP상점() {
	// CP상점
	printf("\n상점에서 물건을 살 수 있습니다.\n");
	printf("어떤 물건을 구매할까요?\n");
	printf("0. 아무 것도 사지 않는다.\n");
	printf("1. 장난감 쥐: 1 CP%s\n", 쥐유무 ? " (품절)" : "");
	printf("2. 레이저 포인터: 2 CP%s\n", 레이저유무 ? " (품절)" : "");
	printf("3. 스크래처: 4 CP%s\n", 스크유무 ? " (품절)" : "");
	printf("4. 캣 타워: 6 CP%s\n", 캣타워유무 ? " (품절)" : "");
	do {
		printf(">> ");
		scanf_s("%d", &구매);
	} while (구매 < 0 || 구매 > 4);

	if (구매 == 0) {
		printf("아무것도 구매하지 않았습니다.");
	}
	else if (구매 == 1 && !쥐유무) {
		if (CP >= 1) {
			CP--;
			쥐유무 = 1;
			printf("장난감 쥐를 구매했습니다. 보유 CP %d 포인트\n", CP);
		}
		else printf("CP가 부족합니다.\n");
	}
	else if (구매 == 2 && !레이저유무) {
		if (CP >= 2) {
			CP -= 2;
			레이저유무 = 1;
			printf("레이저 포인터를 구매했습니다. 보유 CP %d 포인트\n", CP);
		}
		else printf("CP가 부족합니다.\n");
	}
	else if (구매 == 3 && !스크유무) {
		if (CP >= 4) {
			스크유무 = 1;
			CP -= 4;
			printf("스크래처를 구매했습니다. 보유 CP %d 포인트\n", CP);
			do {
				스크 = ran(냄비위치 - 1, 집위치 + 1);
			} while (스크 == 캣타);
		}
		else printf("CP가 부족합니다.\n");
	}
	else if (구매 == 4 && !캣타워유무) {
		if (CP >= 6) {
			캣타워유무 = 1;
			CP -= 6;
			printf("캣 타워를 구매했습니다. 보유 CP %d 포인트\n", CP);
			do {
				캣타 = ran(냄비위치 - 1, 집위치 + 1);
			} while (스크 == 캣타);
		}
		else printf("CP가 부족합니다.\n");
	}
	else if (캣타워유무 == 1 || 스크유무 == 1 || 쥐유무 == 1 || 레이저유무 == 1) {
		printf("이미 구매한 물건입니다.\n");
	}
	
}

void 상호작용() {
	int 선택;
	if (캣타워유무 == 1 && 스크유무 == 0) {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n2.장난감 쥐로 놀아주기\n");
		do {
			printf(">> ");
			scanf_s("%d", &선택);
		} while (선택 != 0 && 선택 != 1 && 선택 != 2);
	}
	else if (스크유무 == 1 && 캣타워유무 == 0) {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n2.장난감 쥐로 놀아주기\n");
		do {
			printf(">> ");
			scanf_s("%d", &선택);
		} while (선택 != 0 && 선택 != 1 && 선택 != 2);
	}
	else if (캣타워유무 == 1 && 스크유무 == 1) {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n2.장난감 쥐로 놀아주기\n3.레이저 포인터로 놀아 주기\n");
		do {
			printf(">> ");
			scanf_s("%d", &선택);
		} while (선택 != 0 && 선택 != 1 && 선택 != 2 && 선택 != 3);
	}
	else {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n");
		do {
			printf(">> ");
			scanf_s("%d", &선택);
		} while (선택 != 0 && 선택 != 1);
	}

	//아무것도 안하기
	if (선택 == 0) {
		printf("아무것도 하지 않습니다.\n");
		Sleep(500);
		int feel2 = 기분;
		if (기분 == 0) {
			printf("기분이 너무 좋지 않습니다.\n");
			printf("이미 최하치 입니다.\n");
		}
		else {
			기분--;
			printf("%s의 기분이 나빠졌습니다:%d -> %d.\n", 이름, feel2, 기분);
		}
		Sleep(500);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(500);
		int Dice = ran(6, 1);
		printf("%d이(가) 나왔습니다.!\n", Dice);
		Sleep(500);
		if (Dice <= 5) {
			if (친밀도 > 0) {
				printf("집사와의 관계가 나빠집니다.\n");
				친밀도--;
				Sleep(500);
			}
			else {
				printf("친밀도가 더 이상 내려가지 않습니다.\n");
				Sleep(500);
			}

		}
		else {
			printf("다행히 친밀도가 떨어지지 않았습니다.\n");
			Sleep(500);
		}
		printf("현재 친밀도: %d\n", 친밀도);
		Sleep(500);

	}
	else if (선택 == 1) { 

		printf("%s의 턱을 긁어주었습니다.\n", 이름);
		Sleep(500);
		printf("%s의 기분은 그대로입니다: %d\n", 이름, 기분);
		Sleep(500);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(500);
		int Dice = ran(6, 1);
		printf("%d이(가) 나왔습니다.!\n", Dice);
		Sleep(500);
		if (Dice >= 5) {
			if (친밀도 < 4) {
				printf("친밀도가 높아집니다.\n");
				친밀도++;
				Sleep(500);
			}
			else {
				printf("친밀도는 최대치입니다.\n");
				Sleep(500);
			}
		}
		else {
			printf("친밀도는 그대로입니다.\n");
			Sleep(500);
		}
		printf("현재 친밀도: %d\n", 친밀도);
	}
	else if (선택 == 2) { 
		if (기분 == 3) {
			printf("기분이 이미 최고조입니다.\n");
		}
		else {
			int feel2 = 기분;
			기분++;
			printf("장난감 쥐로 %s와 놀아 주었습니다. %s의 기분이 좋아졌습니다:%d -> %d.\n", 이름, 이름, feel2, 기분);
		}
		Sleep(500);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(500);
		int Dice = ran(6, 1);
		printf("%d이(가) 나왔습니다.!\n", Dice);
		Sleep(500);
		if (Dice >= 4) {
			if (친밀도 < 4) {
				printf("친밀도가 높아집니다.\n");
				친밀도++;
				Sleep(500);
			}
			else {
				printf("친밀도는 최대치입니다.\n");
				Sleep(500);
			}
		}
		else {
			printf("친밀도는 그대로입니다.\n");
			Sleep(500);
		}
		printf("현재 친밀도: %d\n", 친밀도);

	}
	else if (선택 == 3) { 
		if (기분 == 1) {
			int feel2 = 기분;
			기분 += 2;
			printf("레이저 포인트로 %s와 신나게 놀아 주었습니다. %s의 기분이 꽤 좋아졌습니다:%d -> %d.\n", 이름, 이름, feel2, 기분);
		}
		else if (기분 == 2) {
			int feel2 = 기분;
			기분++;
			printf("레이저 포인트로 %s와 신나게 놀아 주었습니다. %s의 기분이 꽤 좋아졌습니다:%d -> %d.\n", 이름, 이름, feel2, 기분);
		}
		else {
			printf("기분이 이미 최고조입니다.\n");
		}
		Sleep(500);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(500);
		int Dice = ran(6, 1);
		printf("%d이(가) 나왔습니다.!\n", Dice);
		Sleep(500);
		if (Dice >= 2) {
			if (친밀도 < 4) {
				printf("친밀도가 높아집니다.\n");
				친밀도++;
				Sleep(500);
			}
			else {
				printf("친밀도는 최대치입니다.\n");
				Sleep(500);
			}
		}
		else {
			printf("친밀도는 그대로입니다.\n");
			Sleep(500);
		}
		printf("현재 친밀도: %d\n", 친밀도);

	}
}


int main(void) {
	srand((unsigned int)time(NULL));
	char 이름[50];
	printf("****고양이와 수프 VER2****\n");
	printf(" /\\_/\\  \n");
	printf("( o.o ) \n");
	printf(" > ^ <  \n");
	printf("야옹이의 이름을 지어주세요:");
	scanf_s("%s", 이름, sizeof(이름));
	printf("야옹이의 이름은 %s입니다.\n", 이름);
	Sleep(1000);
	system("cls");



	int 친밀도 = 2;
	int 수프 = 0;
	int CP = 0;
	int 기분 = 3;

	while (1) {
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", 수프);
		printf("CP: %d 포인트\n", CP);
		printf("%s 기분(0~3): %d\n", 이름, 기분);
		switch (기분) {
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
		printf("집사와의 관계(0~4): %d\n", 친밀도);
		switch (친밀도) {
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
		이전위치 = 고양이위치;

		// 기분 나빠짐
		int 주사위 = ran(6, 1);
		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다. 고양이니까?\n", 친밀도, 6 - 친밀도);
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이(가) 나왔습니다.\n", 주사위);
		if (주사위 <= 6 - 친밀도) {
			int 이전 = 기분;
			if (기분 > 0) {
				기분--;
				printf("%s의 기분이 나빠집니다: %d → %d\n", 이름, 이전, 기분);
			}
			else {
				printf("더 이상 기분이 나빠지지 않습니다.\n");
			}
		}





		// 수프 만들기
		if (고양이위치 == 냄비위치) {
			int 종류 = ran(3, 0);
			switch (종류) {
			case 0: 
				printf("%s이(가) 브로콜리 수프를 만들었습니다!\n", 이름);
				break;
			case 1:
				printf("%s이(가) 감자 수프를 만들었습니다!\n", 이름);
				break;
			case 2: 
				printf("%s이(가) 양송이 수프를 만들었습니다!\n", 이름); 
				break;
			}
			수프++;
		}
		printf("\n");
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 공간크기; j++) {

				if (j == 0 || j == 공간크기 - 1 || i == 0 || i == 3) {
					printf("#");
				}
				else if (i == 1 && j == 냄비위치) {
					printf("B");
				}
				else if (i == 집위치 && j == 1) {
					printf("H");
				}
				else if (i == 2 && j == 이전위치 && 이전위치 != 고양이위치) {
					printf(".");
				}
				else if (i == 2 && j == 고양이위치) {
					printf("C");
				}
				else if (캣타워유무 == 1 && i == 1 && j == 캣타) {
					printf("T");
				}
				else if (스크유무 == 1 && i == 1 && j == 스크) {
					printf("S");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");

		}

		//상호작용 멘트 출력
		상호작용();
		// CP 생산
		int 생산량 = 큰값(0, 기분 - 1) + 친밀도;
		CP += 생산량;
		printf("기분과 친밀도에 따라 CP가 %d 포인트 생산되었습니다.\n", 생산량);
		printf("현재 보유 CP: %d 포인트\n", CP);
		CP상점();

		sp();
		

	}
	
}

