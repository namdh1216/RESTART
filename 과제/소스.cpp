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

int catX = 1; // ���� ����
int catY = 2; // ���� ����
int cp = 0;
int ��� = 3;
int ������ = 0;
int ģ�е� = 2;
int ��ȣ�ۿ� = 0;
int hasScratcher = 0;
int hasCatTower = 0;

int main(void) {
    char catName[100];
    printf("***�߿��̿� ����***\n");
    printf("  /\\_/\\  \n");
    printf(" ( -.- ) \n");
    printf("  > ^ <  \n");

    printf("�߿����� �̸��� �����ּ���>> ");
    scanf_s("%s", catName, (unsigned)sizeof(catName));
    printf("�߿����� �̸��� %s�Դϴ�.\n", catName);
    Sleep(1000);
    system("cls");

    while (1) {
        // ���� ���
        printf("============�������===========\n");
        printf("���ݱ��� ���� ������ ����: %d��\n", ������);
        printf("CP: %d ����Ʈ\n", cp);
        printf("%s ���(0~3): %d\n", catName, ���);
        switch (���) {
        case 0: printf("����� �ſ� ���޴ϴ�.\n"); break;
        case 1: printf("�ɽ����մϴ�.\n"); break;
        case 2: printf("�Ļ��� �����ϴ�.\n"); break;
        case 3: printf("������ �θ��ϴ�.\n"); break;
        }
        printf("������� ����(0~4): %d\n", ģ�е�);
        switch (ģ�е�) {
        case 0: printf("�翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf("���� ���Ǳ� ����Դϴ�.\n"); break;
        case 2: printf("�׷����� ������ �����Դϴ�.\n"); break;
        case 3: printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n"); break;
        case 4: printf("���� �������Դϴ�.\n"); break;
        default: printf("�߸��� ģ�е� ���Դϴ�.\n"); break;
        }
        printf("===============================\n\n");
        Sleep(500);

        // ��� ������ ����
        printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�...����̴ϱ�?\n", ģ�е�, 6 - ģ�е�);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        srand((unsigned int)time(NULL));
        int �ֻ��� = rand() % 6 + 1;
        printf("%d��(��) ���Խ��ϴ�.\n", �ֻ���);
        if (�ֻ��� <= (6 - ģ�е�)) {
            if (��� > 0) {
                printf("%s�� ����� �������ϴ�: %d -> %d\n", catName, ���, ��� - 1);
                ���--;
            }
            else {
                printf("����� �̹� �־��Դϴ�...\n");
            }
        }
        else {
            printf("����� �״���Դϴ�.\n");
        }

        // �̵�
        if (��� == 0) {
            for (int x = 0; x < ROOM_WIDTH; x++) {
                if (room[catY][x] == 'H') {
                    if (catX < x) catX++;
                    else if (catX > x) catX--;
                    else printf("%s��(��) ������ ���� �ֽ��ϴ�.\n", catName);
                    printf("%s��(��) ����� �ſ� ������ ������ ���մϴ�.\n", catName);
                    break;
                }
            }
        }
        else if (��� == 1) {
            printf("%s��(��) �ɽ��ؼ� ���հ��� ã�� �ֽ��ϴ�...\n", catName);
            if (hasScratcher) {
                for (int x = 0; x < ROOM_WIDTH; x++) {
                    if (room[catY][x] == 'S') {
                        if (catX < x) catX++;
                        else if (catX > x) catX--;
                        else {
                            printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�. ����� ���� ���������ϴ�: %d -> %d\n", catName, ���, ��� + 1);
                            if (��� < 3) ���++;
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
                            printf("%s��(��) ĹŸ���� �پ�ٴմϴ�. ����� ���� ���������ϴ�: %d -> %d\n", catName, ���, ��� + 2);
                            ��� += 2;
                            if (��� > 3) ��� = 3;
                        }
                        break;
                    }
                }
            }
            else {
                printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�: %d -> ", ���);
                ��� = 0;
                printf("%d\n", ���);
            }
        }
        else if (��� == 2) {
            printf("%s��(��) ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n", catName);
        }
        else if (��� == 3) {
            for (int x = 0; x < ROOM_WIDTH; x++) {
                if (room[catY][x] == 'B') {
                    if (catX < x) catX++;
                    else if (catX > x) catX--;
                    else {
                        ������++;
                        printf("%s��(��) ������ �θ��� ������ ��������ϴ�! �� %d��\n", catName, ������);
                    }
                    printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", catName);
                    break;
                }
            }
        }

        // �� ���
        for (int y = 0; y < ROOM_HEIGHT; y++) {
            for (int x = 0; room[y][x] != '\0'; x++) {
                if (x == catX && y == catY)
                    printf("C");
                else
                    printf("%c", room[y][x]);
            }
            printf("\n");
        }

        // ��ȣ�ۿ�
        printf("���ȣ�ۿ����Ͻðڽ��ϱ�?   0.�ƹ��͵��������� 1.�ܾ��ֱ�>> ");
        scanf_s("%d", &��ȣ�ۿ�);

        while (��ȣ�ۿ� != 0 && ��ȣ�ۿ� != 1) {
            printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�? 0. �ƹ��͵� ���� ����  1. �ܾ��ֱ� >> ");
            scanf_s("%d", &��ȣ�ۿ�);
            if (��ȣ�ۿ� != 0 && ��ȣ�ۿ� != 1) {
                printf("�߸��� �����Դϴ�. 0 �Ǵ� 1�� �Է��ϼ���.\n");
            }
        }

        if (��ȣ�ۿ� == 0) {
            printf("�ƹ��͵������ʽ��ϴ�.\n4/6��Ȯ����ģ�е����������ϴ�.\n�ֻ����������ϴ�. �Ǹ���...\n");
            �ֻ��� = rand() % 6 + 1;
            printf("%d�� ���Խ��ϴ�!\n", �ֻ���);
            if (�ֻ��� <= 4) {
                printf("ģ�е��� �϶��մϴ�...\n");
                if (--ģ�е� < 0) ģ�е� = 0;
            }
            else {
                printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
        }
        else {
            printf("%s�� ���� �ܾ��־����ϴ�.\n2/6��Ȯ����ģ�е����������ϴ�.\n�ֻ����������ϴ�. �Ǹ���...\n", catName);
            �ֻ��� = rand() % 6 + 1;
            printf("%d�� ���Խ��ϴ�!\n", �ֻ���);
            if (�ֻ��� >= 5) {
                printf("ģ�е��� ����մϴ�!\n");
                if (++ģ�е� > 4) ģ�е� = 4;
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }

        Sleep(1000);
    }

    return 0;
}
