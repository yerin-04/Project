//202378076������
//�⸻ �Ǳ�_��ȭ ����Ʈ ���� ���α׷�
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct movie //����ü ����
{
	char name[100];
	int year, YN, c_grade, i_grade;
};
void file(struct movie* list, int p)
{
	FILE* fp = fopen("movieList.txt", "w"); //���� ����

	for (int i = 0; i < p; i++) //���Ͽ� �ʵ带 �ϳ��� ������
	{
		fprintf(fp, "%s ", list[i].name);
		fprintf(fp, "%d ", list[i].year);
		fprintf(fp, "%c ", list[i].YN);
		fprintf(fp, "%d ", list[i].c_grade);
		fprintf(fp, "%d\n", list[i].i_grade);
	}
	// ���� ����
	fclose(fp);
}

int add(struct movie* list)
{
	FILE* fp_r = fopen("movieList.txt", "r"); //���� �б�
	int y = 0, k = 0, m = 0, n = 0, o = 0, p = 3;

	//<�� ���� ��ȭ ������ �ʱⰪ���� �ο�>
	strcpy_s(list[0].name, 20, "6 underground");
	list[0].year = 2019, list[0].YN = 'Y', list[0].c_grade = 4, list[0].i_grade = 4;

	strcpy_s(list[1].name, 50, "The Amazing Spider-Man");
	list[1].year = 2012, list[1].YN = 'Y', list[1].c_grade = 4, list[1].i_grade = 5;

	strcpy_s(list[2].name, 10, "Minions");
	list[2].year = 2015, list[2].YN = 'Y', list[2].c_grade = 3, list[2].i_grade = 4;

	int menu;
	do
	{
		printf("\n\nmenu: 1.��ü���� 2.�����ϱ� 3.�����ϱ� 4.�߰��ϱ� 5.�˻��ϱ� 6.�����ϱ� ");
		printf("\nmenu�� �������ּ���. ");
		scanf_s("%d", &menu); //�޴� �Է� �ޱ�

		if (menu < 1 || menu > 6) //���� ��� �� �Է½� �����޼��� ��� �� �ٽ� �Է� �ޱ�
		{
			printf("\n�Է°��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
		}
		if (menu == 1) //1.��ü���� ����
		{
			for (int i = 0; i < 100; i++)
			{
				if (list[i].year != 0 && list[i].YN != 0) //����� ���� NUll�� ��� ��� ����
				{
					printf("\n\n%d. %s, %d, %c, My Score(%d, %d)", i, list[i].name, list[i].year, list[i].YN, list[i].c_grade, list[i].i_grade);
				}
			}
		}

		if (menu == 2) //2.�����ϱ� ����
		{
			while (1)
			{
				printf("\n������ �ε����� �����ϼ���(0~99): ");
				scanf_s("%d", &k); //������ �ε��� �Է� �ޱ�
				if (k < 0 || k>99) //���� ��� �� �Է½� �����޼��� ��� �� �ٽ� �Է� �ޱ�
				{
					printf("\n�Է°��� �߸��ƽ��ϴ�.");
				}
				if (k >= 0 && k <= 99 && list[k].year == 0 && list[k].c_grade == 0 && list[k].i_grade == 0) //������ ���� �ε��� ���ý� �����޼��� ��� �� �ٽ� �Է� �ޱ�
				{
					printf("������ ���� �ε����Դϴ�. �ٸ� �ε����� �����ϼ���: ");
				}
				if (k >= 0 && k <= 99 && list[k].year != 0)
				{
					list[k].name[0] = 0, list[k].year = 0, list[k].YN = 0; list[k].c_grade = 0, list[k].i_grade = 0; //�����ϱ�(NULL��(0) ����)
					printf("\n������ �Ϸ�ƽ��ϴ�.");
					break;
				}
			}
		}

		if (menu == 3) //3.�����ϱ� ����
		{
			while (1)
			{
				printf("\n\n������ �ε����� �����ϼ���(0~99): ");
				scanf_s("%d", &m);
				if (m < 0 || m>99) //�ε��� ����(0~99) ����� ���� �޼��� ��� �� ���Է� �䱸
				{
					printf("�Է°��� �߸��ƽ��ϴ�."); //���� �޼��� ���
				}
				if (m >= 0 && m <= 99 && list[m].year == 0 && list[m].YN == 0 && list[m].c_grade == 0 && list[m].i_grade == 0) //������ ���� �ε��� ���ý� �ȳ��޼��� ��� �� ���Է� �䱸
				{
					printf("������ ���� �ε����Դϴ�. �ٸ� �ε����� �����ϼ���: ");
				}
				if (m >= 0 && m <= 99 && list[m].year != 0 && list[m].YN != 0) //���� �ȿ��� ���� �ִ� �ε��� ���ý� while�� ����
					break;
			}
			printf("\n�����Ͻ� �ε����� ��ȭ ������: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			while (1)
			{
				printf("\n������ �ʵ带 �����ϼ���: %d.��ȭ��, %d.�������� %d.��������, %d.��������, %d.�������)", 1, 2, 3, 4, 5);
				scanf_s("%d", &n); //������ �ʵ� �Է� �ޱ�
				if (n < 1 || n > 5) //1~5������ ������ �ʵ� �����ϱ�. ���� ����� ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
				{
					printf("�Է°��� �߸��ƽ��ϴ�.");
				}
				if (n >= 1 && n <= 5) //���� ���� �� �Է½� while�� ����
					break;
			}

			if (n == 1) //1.��ȭ�� �����ϱ�
			{
				printf("\n������ ������ �Է��ϼ���: ");
				scanf_s(" %[^\n]s", &list[m].name, sizeof(list[m].name)); //[^\n]: ���� ������ ���ڿ� �Է� �ޱ�
				printf("\n���� �Ϸ�!\n������ ��ȭ����: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			}

			if (n == 2) //2.�������� �����ϱ�
			{
				printf("\n��������: ���� %d", list[m].year); //���� �������� ���
				printf("\n������ ���������� �Է��ϼ���: ");
				scanf_s("%d", &list[m].year); //������ �������� �Է� �ޱ�
				printf("\n���� �Ϸ�!\n������ ��ȭ����: %d. %s, %d, %c, My Score(%d, %d)\n", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			}

			if (n == 3) //3.�������� �����ϱ�
			{
				printf("\n��������: ���� %c", list[m].YN); //���� �������� ����ϱ�
				while (1)
				{
					printf("\n������ �������θ� �Է��ϼ���(���� �ĸ� 1����, ���� ���̸� 2����): ");
					scanf_s("%d", &o);
					if (o != 1 && o != 2) //������ ��� �� �Է½� ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
					{
						printf("�Է°��� �߸��ƽ��ϴ�.");
					}
					if (o == 1) //���� �� ����
					{
						list[m].YN = 'Y';
						break;
					}
					else if (o == 2) //���� �� ����
					{
						list[m].YN = 'N';
						list[m].c_grade = 0; //���� ���� 0 ����
						list[m].i_grade = 0; //��� ���� 0 ����
						break;
					}
				}
				printf("\n���� �Ϸ�!\n������ ��ȭ����: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			}

			if (n == 4) //4.�������� �����ϱ�
			{
				printf("\n��������: ���� %d", list[m].c_grade);
				if (list[m].YN == 'N') //���� ���� ��ȭ�� �����ϸ� �������� ���� �Ұ���. ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
				{
					printf("\n���� ���� ��ȭ�Դϴ�. ���������� ������ �� �����ϴ�.");
				}
				else if (list[m].YN == 'Y') //���� �� ��ȭ ���ý� �������� ���� ����
				{
					while (1)
					{
						printf("\n������ ���������� �Է��ϼ���(1~5): ");
						scanf_s("%d", &list[m].c_grade); //������ �������� �Է� �ޱ�
						if (list[m].c_grade < 1 || list[m].c_grade >5) //���� ��� �� �Է½� ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
						{
							printf("�Է°��� �߸��ƽ��ϴ�. ");
						}
						if (list[m].c_grade >= 1 && list[m].c_grade <= 5) //���� ���� �� �Է½� ������ ��ȭ���� ���
						{
							printf("\n���� �Ϸ�!\n������ ��ȭ����: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
							break; //while�� ����
						}
					}
				}
			}

			if (n == 5) //5.������� �����ϱ�
			{
				printf("\n�������: ���� %d", list[m].i_grade);
				if (list[m].YN == 'N') //���� ���� ��ȭ�� �����ϸ� �������� ���� �Ұ���. ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
				{
					printf("\n���� ���� ��ȭ�Դϴ�. ���������� ������ �� �����ϴ�.");
				}
				else if (list[m].YN == 'Y') //���� �� ��ȭ ���ý� �������� ���� ����
				{
					while (1)
					{
						printf("\n������ ��������� �Է��ϼ���(1~5): ");
						scanf_s("%d", &list[m].i_grade); //������ ������� �Է� �ޱ�
						if (list[m].i_grade < 1 || list[m].i_grade >5) //���� ��� �� �Է½� ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
						{
							printf("�Է°��� �߸��ƽ��ϴ�. ");
						}
						if (list[m].i_grade >= 1 && list[m].i_grade <= 5) //���� ���� �� �Է½� ������ ��ȭ���� ���
							break; //while�� ����
					}
					printf("\n���� �Ϸ�!\n������ ��ȭ����: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
				}
			}
		}

		if (menu == 4) //4.�߰��ϱ� ����
		{
			printf("��ȭ���� �Է��ϼ���: ");
			scanf_s(" %[^\n]s", &list[p].name, sizeof(list[p].name)); //[^\n] : ������ ������ ���ڿ� �Է� �ޱ�

			//�������� ������ �Է¹ޱ�
			printf("\n���������� �Է��ϼ���: ");
			scanf_s("%d", &list[p].year); //�������� �Է¹ޱ�
			//�������θ� �Է¹ޱ�
			while (1)
			{
				printf("\n���� ���θ� �Է��ϼ���(���� �ĸ� 1����, ���� ���̸� 2����): ");
				scanf_s("%d", &y);
				if (y != 1 && y != 2) //���� ����� �����޼��� ��� �� �ٽ� �Է� �ޱ�
				{
					printf("�Է°��� �߸��ƽ��ϴ�.");
				}
				if (y == 1) //���� ������ ��������, ������� �Է¹ޱ�
				{
					list[p].YN = 'Y';
					while (1)
					{
						printf("\n���������� �Է��ϼ���(1~5): ");
						scanf_s("%d", &list[p].c_grade); //�������� �Է� �ޱ�
						if (list[p].c_grade < 1 || list[p].c_grade >5) //���� ��� �� �Է½� ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
						{
							printf("�Է°��� �߸��ƽ��ϴ�. ");
						}
						if (list[p].c_grade >= 1 && list[p].c_grade <= 5) //�ùٸ� ���� ������ �� �Է½� ����
							break;
					}
					while (1)
					{
						printf("\n��������� �Է��ϼ���(1~5): ");
						scanf_s("%d", &list[p].i_grade); //������� �Է� �ޱ�
						if (list[p].i_grade < 1 || list[p].i_grade >5) //���� ��� �� �Է½� ���� �޼��� ��� �� �ٽ� �Է� �ޱ�
						{
							printf("�Է°��� �߸��ƽ��ϴ�. ");
						}
						if (list[p].i_grade >= 1 && list[p].i_grade <= 5) //�ùٸ� ���� ������ �� �Է½� ����
							break;
					}
					break;
				}
				else if (y == 2) //���� �������� 0���� �Է��ϱ�
				{
					list[p].YN = 'N';
					list[p].c_grade = 0;
					list[p].i_grade = 0;
					break;
				}
			}
			printf("����� �߰��� ��ȭ��: %s, %d, %c, My score(%d, %d)", list[p].name, list[p].year, list[p].YN, list[p].c_grade, list[p].i_grade);
			p++; //int p = 3;�̹Ƿ� [p]==[3]���� �����ؼ� �������� p++; >> ������ �߰��ϱ� ���ý� [4]... �� �ε������� ���ʴ�� �߰��ϱ�
		}

		if (menu == 5) //5.�˻��ϱ� ����
		{
			char search[100]; //�˻��� Ű���带 ���� �迭 search ����
			int found = 0; //��ġ�ϴ� Ű������ ������ ��Ÿ�� ���� found ����
			printf("\n�˻� Ű���带 �Է��ϼ���: ");
			scanf_s("%s", search, sizeof(search)); //�˻� Ű���� �Է¹ޱ�

			for (int i = 0; i < p; i++) //����ü �迭�� �ִ� ��ҿ� ��
			{
				if (strstr(list[i].name, search) != NULL) //list[i].name�� search(�˻��� Ű����)�� ���� ��� NULL�� ���
				{
					printf("�˻��� ��ȭ����: %d. %s, %d, %c, (%d, %d)\n", i, list[i].name, list[i].year, list[i].YN, list[i].c_grade, list[i].i_grade);
					found = 1; //��ġ�ϴ� Ű���尡 ���� ��� found�� 1����
				}
			}
			if (found == 0) //��ġ�ϴ� Ű���尡 ���� ��� "��ġ�ϴ� Ű���尡 �����ϴ�" �ȳ� �޼��� ���
				printf("��ġ�ϴ� Ű���尡 �����ϴ�.");
		}

		if (menu == 6) //6.�����ϱ� ���ý� �ȳ� �޼��� ��� �� ���α׷� ����
		{
			file(list, p); //�Լ� ����
			printf("\n\n���α׷��� �����մϴ�.\n");
			fclose(fp_r); //���� �ݱ�
		}

	} while (menu != 6); //6.�����ϱ� ���ý� ����

	return 0;
}

void main()
{
	struct movie list[100] = { 0 }; //����ü �ʱ�ȭ
	add(list);
}