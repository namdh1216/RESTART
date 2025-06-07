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
int 스크래쳐위치 = -1;
int 캣타워위치 = -1;
int 스크래쳐설치됨 = 0;
int 캣타워설치됨 = 0;
char 이름[50];
int 기분, 친밀도;

void 집그리기() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 공간크기; j++) {
			if (j == 0 || j == 공간크기 - 1 || i == 0 || i == 3) {
				printf("#");
			}
			else if (i == 1 && j == 집위치) {
				printf("H");
			}
			else if (i == 1 && j == 냄비위치) {
				printf("B");
			}
			else if (i == 2 && j == 이전위치 && 이전위치 != 고양이위치) {
				printf(".");
			}
			else if (i == 2 && j == 고양이위치) {
				printf("C");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
void 상호작용() {
	int 선택;

	if (스크래쳐설치됨 && !캣타워설치됨) {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1. 긁어 주기\n2. 장난감 쥐로 놀아주기\n");
	}
	else if (!스크래쳐설치됨 && 캣타워설치됨) {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1. 긁어 주기\n2. 장난감 쥐로 놀아주기\n");
	}
	else if (스크래쳐설치됨 && 캣타워설치됨) {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1. 긁어 주기\n2. 장난감 쥐로 놀아주기\n3. 레이저 포인터로 놀아주기\n");
	}
	else {
		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1. 긁어 주기\n");
	}

	do {
		printf(">> ");
		scanf_s("%d", &선택);
	} while (선택 < 0 || 선택 > 3);

	if (선택 == 0) {
		printf("아무것도 하지 않았습니다.\n");
		if (기분 > 0) {
			기분--;
			printf("기분이 나빠졌습니다.\n");
		}
	}
	else if (선택 == 1) {
		printf("%s의 턱을 긁어주었습니다.\n", 이름);
		printf("기분은 그대로입니다.\n");
	}
	else if (선택 == 2) {
		if (기분 < 3) {
			기분++;
			printf("장난감 쥐로 놀아주어 기분이 좋아졌습니다.\n");
		}
		else {
			printf("이미 기분이 최고입니다.\n");
		}
	}
	else if (선택 == 3) {

		if (기분 <= 1) {
			기분 += 2;
			printf("레이저 포인터로 놀아주어 기분이 많이 좋아졌습니다.\n");
		}
		else if (기분 == 2) {
			기분++;
			printf("레이저 포인터로 놀아주어 기분이 제법 좋아졌습니다.\n");
		}
		else {
			printf("이미 기분이 최고입니다.\n");
		}
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
	do {
		스크래쳐위치 = ran(공간크기 - 3, 집위치 + 1);
		캣타워위치 = ran(공간크기 - 3, 집위치 + 1);
	} while (스크래쳐위치 == 캣타워위치 || 스크래쳐위치 == 냄비위치 || 캣타워위치 == 냄비위치);

	스크래쳐설치됨 = 1;
	캣타워설치됨 = 1;


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

		// 이전 위치 저장
		이전위치 = 고양이위치;

		// 기분에 따른 이동
		if (기분 == 0) {
			if (고양이위치 == 집위치) {
				printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", 이름);
			}
			else {
				printf("기분이 나쁜 %s은(는) 집으로 향합니다.\n", 이름);
				고양이위치--;
			}
		}
		else if (기분 == 1) {
			printf("%s은(는) 심심해합니다.\n", 이름);
		}
		else if (기분 == 2) {
			printf("%s은(는) 기분 좋게 식빵을 굽고 있습니다.\n", 이름);
		}
		else if (기분 == 3) {
			if (고양이위치 < 냄비위치) {
				printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", 이름);
				고양이위치++;
			}
			else {
				printf("움직이지 않았습니다.\n");
			}
		}

		if (고양이위치 == 스크래쳐위치 && 스크래쳐설치됨) {
			printf("%s은(는) 스크래쳐를 긁고 놀았습니다.\n", 이름);
			if (기분 < 3) {
				printf("기분이 조금 좋아졌습니다.\n");
				기분++;
			}
			else {
				printf("기분이 최고조입니다.\n");
			}
		}

		if (고양이위치 == 캣타워위치 && 캣타워설치됨) {
			printf("%s은(는) 캣타워를 뛰어다닙니다.\n", 이름);
			if (기분 <= 1) {
				printf("기분이 제법 좋아졌습니다.\n");
				기분 += 2;
			}
			else if (기분 == 2) {
				printf("기분이 제법 좋아졌습니다.\n");
				기분++;
			}
			else {
				printf("기분이 최고조입니다.\n");
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
	
		// 방 구조 출력
		printf("\n[방 구조]\n");
		집그리기();
		//상호작용 멘트 출력
		상호작용();
		// CP 생산
		int 생산량 = 큰값(0, 기분 - 1) + 친밀도;
		CP += 생산량;
		printf("기분과 친밀도에 따라 CP가 %d 포인트 생산되었습니다.\n", 생산량);
		printf("현재 보유 CP: %d 포인트\n", CP);


		sp();
		break;

	}
	
}
