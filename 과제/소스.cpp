#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH  20
#define ROOM_HEIGHT 4

char room[4][20] = {
    "###############",
    "#H           B#",
    "#.            #",
    "###############"
};

int catX = 1; // 가로 방향
int catY = 2; // 세로 방향
int cp = 0;
int 기분 = 3;
int 스프수 = 0;
int 친밀도 = 2;
int 상호작용 = 0;
int hasScratcher = 0;
int hasCatTower = 0;

int main(void) {
    char catName[100];
    printf("***야옹이와 스프***\n");
    printf("  /\\_/\\  \n");
    printf(" ( -.- ) \n");
    printf("  > ^ <  \n");

    printf("야옹이의 이름을 정해주세요>> ");
    scanf_s("%s", catName, (unsigned)sizeof(catName));
    printf("야옹이의 이름은 %s입니다.\n", catName);
    Sleep(1000);
    system("cls");

    while (1) {
        // 상태 출력
        printf("============현재상태===========\n");
        printf("지금까지 만든 수프의 개수: %d개\n", 스프수);
        printf("CP: %d 포인트\n", cp);
        printf("%s 기분(0~3): %d\n", catName, 기분);
        switch (기분) {
        case 0: printf("기분이 매우 나쁩니다.\n"); break;
        case 1: printf("심심해합니다.\n"); break;
        case 2: printf("식빵을 굽습니다.\n"); break;
        case 3: printf("골골송을 부릅니다.\n"); break;
        }
        printf("집사와의 관계(0~4): %d\n", 친밀도);
        switch (친밀도) {
        case 0: printf("곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf("간식 자판기 취급입니다.\n"); break;
        case 2: printf("그럭저럭 쓸만한 집사입니다.\n"); break;
        case 3: printf("훌륭한 집사로 인정받고 있습니다.\n"); break;
        case 4: printf("집사 껌딱지입니다.\n"); break;
        default: printf("잘못된 친밀도 값입니다.\n"); break;
        }
        printf("===============================\n\n");
        Sleep(500);

        // 기분 나빠짐 로직
        printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다...고양이니까?\n", 친밀도, 6 - 친밀도);
        printf("주사위를 굴립니다. 또르르...\n");
        srand((unsigned int)time(NULL));
        int 주사위 = rand() % 6 + 1;
        printf("%d이(가) 나왔습니다.\n", 주사위);
        if (주사위 <= (6 - 친밀도)) {
            if (기분 > 0) {
                printf("%s의 기분이 나빠집니다: %d -> %d\n", catName, 기분, 기분 - 1);
                기분--;
            }
            else {
                printf("기분은 이미 최악입니다...\n");
            }
        }
        else {
            printf("기분은 그대로입니다.\n");
        }

        // 이동
        if (기분 == 0) {
            for (int x = 0; x < ROOM_WIDTH; x++) {
                if (room[catY][x] == 'H') {
                    if (catX < x) catX++;
                    else if (catX > x) catX--;
                    else printf("%s은(는) 집에서 쉬고 있습니다.\n", catName);
                    printf("%s은(는) 기분이 매우 나빠서 집으로 향합니다.\n", catName);
                    break;
                }
            }
        }
        else if (기분 == 1) {
            printf("%s은(는) 심심해서 놀잇감을 찾고 있습니다...\n", catName);
            if (hasScratcher) {
                for (int x = 0; x < ROOM_WIDTH; x++) {
                    if (room[catY][x] == 'S') {
                        if (catX < x) catX++;
                        else if (catX > x) catX--;
                        else {
                            printf("%s은(는) 스크래처를 긁고 놀았습니다. 기분이 조금 좋아졌습니다: %d -> %d\n", catName, 기분, 기분 + 1);
                            if (기분 < 3) 기분++;
                        }
                        break;
                    }
                }
            }
            else if (hasCatTower) {
                for (int x = 0; x < ROOM_WIDTH; x++) {
                    if (room[catY][x] == 'T') {
                        if (catX < x) catX++;
                        else if (catX > x) catX--;
                        else {
                            printf("%s은(는) 캣타워를 뛰어다닙니다. 기분이 제법 좋아졌습니다: %d -> %d\n", catName, 기분, 기분 + 2);
                            기분 += 2;
                            if (기분 > 3) 기분 = 3;
                        }
                        break;
                    }
                }
            }
            else {
                printf("놀 거리가 없어서 기분이 매우 나빠집니다: %d -> ", 기분);
                기분 = 0;
                printf("%d\n", 기분);
            }
        }
        else if (기분 == 2) {
            printf("%s은(는) 기분 좋게 식빵을 굽고 있습니다.\n", catName);
        }
        else if (기분 == 3) {
            for (int x = 0; x < ROOM_WIDTH; x++) {
                if (room[catY][x] == 'B') {
                    if (catX < x) catX++;
                    else if (catX > x) catX--;
                    else {
                        스프수++;
                        printf("%s은(는) 골골송을 부르며 수프를 만들었습니다! 총 %d개\n", catName, 스프수);
                    }
                    printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", catName);
                    break;
                }
            }
        }

        // 방 출력
        for (int y = 0; y < ROOM_HEIGHT; y++) {
            for (int x = 0; room[y][x] != '\0'; x++) {
                if (x == catX && y == catY)
                    printf("C");
                else
                    printf("%c", room[y][x]);
            }
            printf("\n");
        }

        // 상호작용
        printf("어떤상호작용을하시겠습니까?   0.아무것도하지않음 1.긁어주기>> ");
        scanf_s("%d", &상호작용);

        while (상호작용 != 0 && 상호작용 != 1) {
            printf("어떤 상호작용을 하시겠습니까? 0. 아무것도 하지 않음  1. 긁어주기 >> ");
            scanf_s("%d", &상호작용);
            if (상호작용 != 0 && 상호작용 != 1) {
                printf("잘못된 선택입니다. 0 또는 1을 입력하세요.\n");
            }
        }

        if (상호작용 == 0) {
            printf("아무것도하지않습니다.\n4/6의확률로친밀도가떨어집니다.\n주사위를굴립니다. 또르륵...\n");
            주사위 = rand() % 6 + 1;
            printf("%d가 나왔습니다!\n", 주사위);
            if (주사위 <= 4) {
                printf("친밀도가 하락합니다...\n");
                if (--친밀도 < 0) 친밀도 = 0;
            }
            else {
                printf("다행히 친밀도가 떨어지지 않았습니다.\n");
            }
        }
        else {
            printf("%s의 턱을 긁어주었습니다.\n2/6의확률로친밀도가높아집니다.\n주사위를굴립니다. 또르륵...\n", catName);
            주사위 = rand() % 6 + 1;
            printf("%d가 나왔습니다!\n", 주사위);
            if (주사위 >= 5) {
                printf("친밀도가 상승합니다!\n");
                if (++친밀도 > 4) 친밀도 = 4;
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
        }

        Sleep(1000);
    }

    return 0;
}
