//202378076유예린
//기말 실기_영화 리스트 관리 프로그램
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct movie //구조체 정의
{
	char name[100];
	int year, YN, c_grade, i_grade;
};
void file(struct movie* list, int p)
{
	FILE* fp = fopen("movieList.txt", "w"); //파일 적기

	for (int i = 0; i < p; i++) //파일에 필드를 하나씩 저장함
	{
		fprintf(fp, "%s ", list[i].name);
		fprintf(fp, "%d ", list[i].year);
		fprintf(fp, "%c ", list[i].YN);
		fprintf(fp, "%d ", list[i].c_grade);
		fprintf(fp, "%d\n", list[i].i_grade);
	}
	// 파일 닫음
	fclose(fp);
}

int add(struct movie* list)
{
	FILE* fp_r = fopen("movieList.txt", "r"); //파일 읽기
	int y = 0, k = 0, m = 0, n = 0, o = 0, p = 3;

	//<몇 개의 영화 정보를 초기값으로 부여>
	strcpy_s(list[0].name, 20, "6 underground");
	list[0].year = 2019, list[0].YN = 'Y', list[0].c_grade = 4, list[0].i_grade = 4;

	strcpy_s(list[1].name, 50, "The Amazing Spider-Man");
	list[1].year = 2012, list[1].YN = 'Y', list[1].c_grade = 4, list[1].i_grade = 5;

	strcpy_s(list[2].name, 10, "Minions");
	list[2].year = 2015, list[2].YN = 'Y', list[2].c_grade = 3, list[2].i_grade = 4;

	int menu;
	do
	{
		printf("\n\nmenu: 1.전체보기 2.삭제하기 3.수정하기 4.추가하기 5.검색하기 6.종료하기 ");
		printf("\nmenu를 선택해주세요. ");
		scanf_s("%d", &menu); //메뉴 입력 받기

		if (menu < 1 || menu > 6) //범위 벗어난 값 입력시 오류메세지 출력 후 다시 입력 받기
		{
			printf("\n입력값이 잘못됐습니다. 다시 입력해주세요.\n");
		}
		if (menu == 1) //1.전체보기 선택
		{
			for (int i = 0; i < 100; i++)
			{
				if (list[i].year != 0 && list[i].YN != 0) //저장된 값이 NUll인 경우 출력 안함
				{
					printf("\n\n%d. %s, %d, %c, My Score(%d, %d)", i, list[i].name, list[i].year, list[i].YN, list[i].c_grade, list[i].i_grade);
				}
			}
		}

		if (menu == 2) //2.삭제하기 선택
		{
			while (1)
			{
				printf("\n삭제할 인덱스를 선택하세요(0~99): ");
				scanf_s("%d", &k); //삭제할 인덱스 입력 받기
				if (k < 0 || k>99) //범위 벗어난 값 입력시 오류메세지 출력 후 다시 입력 받기
				{
					printf("\n입력값이 잘못됐습니다.");
				}
				if (k >= 0 && k <= 99 && list[k].year == 0 && list[k].c_grade == 0 && list[k].i_grade == 0) //내용이 없는 인덱스 선택시 오류메세지 출력 후 다시 입력 받기
				{
					printf("내용이 없는 인덱스입니다. 다른 인덱스를 선택하세요: ");
				}
				if (k >= 0 && k <= 99 && list[k].year != 0)
				{
					list[k].name[0] = 0, list[k].year = 0, list[k].YN = 0; list[k].c_grade = 0, list[k].i_grade = 0; //삭제하기(NULL값(0) 대입)
					printf("\n삭제가 완료됐습니다.");
					break;
				}
			}
		}

		if (menu == 3) //3.수정하기 선택
		{
			while (1)
			{
				printf("\n\n수정할 인덱스를 선택하세요(0~99): ");
				scanf_s("%d", &m);
				if (m < 0 || m>99) //인덱스 범위(0~99) 벗어나면 오류 메세지 출력 및 재입력 요구
				{
					printf("입력값이 잘못됐습니다."); //오류 메세지 출력
				}
				if (m >= 0 && m <= 99 && list[m].year == 0 && list[m].YN == 0 && list[m].c_grade == 0 && list[m].i_grade == 0) //내용이 없는 인덱스 선택시 안내메세지 출력 및 재입력 요구
				{
					printf("내용이 없는 인덱스입니다. 다른 인덱스를 선택하세요: ");
				}
				if (m >= 0 && m <= 99 && list[m].year != 0 && list[m].YN != 0) //범위 안에서 내용 있는 인덱스 선택시 while문 종료
					break;
			}
			printf("\n선택하신 인덱스의 영화 정보는: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			while (1)
			{
				printf("\n수정할 필드를 선택하세요: %d.영화명, %d.개봉연도 %d.관람여부, %d.구성평점, %d.흥미평점)", 1, 2, 3, 4, 5);
				scanf_s("%d", &n); //수정할 필드 입력 받기
				if (n < 1 || n > 5) //1~5사이의 수정할 필드 선택하기. 범위 벗어나면 오류 메세지 출력 후 다시 입력 받기
				{
					printf("입력값이 잘못됐습니다.");
				}
				if (n >= 1 && n <= 5) //범위 내의 값 입력시 while문 종료
					break;
			}

			if (n == 1) //1.영화명 수정하기
			{
				printf("\n수정할 제목을 입력하세요: ");
				scanf_s(" %[^\n]s", &list[m].name, sizeof(list[m].name)); //[^\n]: 공백 포함한 문자열 입력 받기
				printf("\n수정 완료!\n수정된 영화정보: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			}

			if (n == 2) //2.개봉연도 수정하기
			{
				printf("\n개봉연도: 현재 %d", list[m].year); //현재 개봉연도 출력
				printf("\n수정할 개봉연도를 입력하세요: ");
				scanf_s("%d", &list[m].year); //수정할 개봉연도 입력 받기
				printf("\n수정 완료!\n수정된 영화정보: %d. %s, %d, %c, My Score(%d, %d)\n", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			}

			if (n == 3) //3.관람여부 수정하기
			{
				printf("\n관람여부: 현재 %c", list[m].YN); //현재 관람여부 출력하기
				while (1)
				{
					printf("\n수정할 관람여부를 입력하세요(관람 후면 1선택, 관람 전이면 2선택): ");
					scanf_s("%d", &o);
					if (o != 1 && o != 2) //범위를 벗어난 값 입력시 오류 메세지 출력 후 다시 입력 받기
					{
						printf("입력값이 잘못됐습니다.");
					}
					if (o == 1) //관람 후 선택
					{
						list[m].YN = 'Y';
						break;
					}
					else if (o == 2) //관람 전 선택
					{
						list[m].YN = 'N';
						list[m].c_grade = 0; //구성 평점 0 대입
						list[m].i_grade = 0; //흥미 평점 0 대입
						break;
					}
				}
				printf("\n수정 완료!\n수정된 영화정보: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
			}

			if (n == 4) //4.구성평점 수정하기
			{
				printf("\n구성평점: 현재 %d", list[m].c_grade);
				if (list[m].YN == 'N') //관람 전인 영화를 선택하면 구성평점 수정 불가능. 오류 메세지 출력 후 다시 입력 받기
				{
					printf("\n관람 전인 영화입니다. 구성평점을 수정할 수 없습니다.");
				}
				else if (list[m].YN == 'Y') //관람 한 영화 선택시 구성평점 수정 가능
				{
					while (1)
					{
						printf("\n수정할 구성평점을 입력하세요(1~5): ");
						scanf_s("%d", &list[m].c_grade); //수정할 구성평점 입력 받기
						if (list[m].c_grade < 1 || list[m].c_grade >5) //범위 벗어난 값 입력시 오류 메세지 출력 후 다시 입력 받기
						{
							printf("입력값이 잘못됐습니다. ");
						}
						if (list[m].c_grade >= 1 && list[m].c_grade <= 5) //범위 내의 값 입력시 수정된 영화정보 출력
						{
							printf("\n수정 완료!\n수정된 영화정보: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
							break; //while문 종료
						}
					}
				}
			}

			if (n == 5) //5.흥미평점 수정하기
			{
				printf("\n흥미평점: 현재 %d", list[m].i_grade);
				if (list[m].YN == 'N') //관람 전인 영화를 선택하면 구성평점 수정 불가능. 오류 메세지 출력 후 다시 입력 받기
				{
					printf("\n관람 전인 영화입니다. 구성평점을 수정할 수 없습니다.");
				}
				else if (list[m].YN == 'Y') //관람 한 영화 선택시 구성평점 수정 가능
				{
					while (1)
					{
						printf("\n수정할 흥미평점을 입력하세요(1~5): ");
						scanf_s("%d", &list[m].i_grade); //수정할 흥미평점 입력 받기
						if (list[m].i_grade < 1 || list[m].i_grade >5) //범위 벗어난 값 입력시 오류 메세지 출력 후 다시 입력 받기
						{
							printf("입력값이 잘못됐습니다. ");
						}
						if (list[m].i_grade >= 1 && list[m].i_grade <= 5) //범위 내의 값 입력시 수정된 영화정보 출력
							break; //while문 종료
					}
					printf("\n수정 완료!\n수정된 영화정보: %d. %s, %d, %c, My Score(%d, %d)", m, list[m].name, list[m].year, list[m].YN, list[m].c_grade, list[m].i_grade);
				}
			}
		}

		if (menu == 4) //4.추가하기 선택
		{
			printf("영화명을 입력하세요: ");
			scanf_s(" %[^\n]s", &list[p].name, sizeof(list[p].name)); //[^\n] : 공백을 포함한 문자열 입력 받기

			//개봉연도 정수로 입력받기
			printf("\n개봉연도를 입력하세요: ");
			scanf_s("%d", &list[p].year); //개봉연도 입력받기
			//관람여부를 입력받기
			while (1)
			{
				printf("\n관람 여부를 입력하세요(관람 후면 1선택, 관람 전이면 2선택): ");
				scanf_s("%d", &y);
				if (y != 1 && y != 2) //범위 벗어나면 오류메세지 출력 후 다시 입력 받기
				{
					printf("입력값이 잘못됐습니다.");
				}
				if (y == 1) //관람 했으면 구성평점, 흥미평점 입력받기
				{
					list[p].YN = 'Y';
					while (1)
					{
						printf("\n구성평점을 입력하세요(1~5): ");
						scanf_s("%d", &list[p].c_grade); //구성평점 입력 받기
						if (list[p].c_grade < 1 || list[p].c_grade >5) //범위 벗어난 값 입력시 오류 메세지 출력 및 다시 입력 받기
						{
							printf("입력값이 잘못됐습니다. ");
						}
						if (list[p].c_grade >= 1 && list[p].c_grade <= 5) //올바른 범위 내에서 값 입력시 종료
							break;
					}
					while (1)
					{
						printf("\n흥미평점을 입력하세요(1~5): ");
						scanf_s("%d", &list[p].i_grade); //흥미평점 입력 받기
						if (list[p].i_grade < 1 || list[p].i_grade >5) //범위 벗어난 값 입력시 오류 메세지 출력 및 다시 입력 받기
						{
							printf("입력값이 잘못됐습니다. ");
						}
						if (list[p].i_grade >= 1 && list[p].i_grade <= 5) //올바른 범위 내에서 값 입력시 종료
							break;
					}
					break;
				}
				else if (y == 2) //관람 안했으면 0으로 입력하기
				{
					list[p].YN = 'N';
					list[p].c_grade = 0;
					list[p].i_grade = 0;
					break;
				}
			}
			printf("당신이 추가한 영화는: %s, %d, %c, My score(%d, %d)", list[p].name, list[p].year, list[p].YN, list[p].c_grade, list[p].i_grade);
			p++; //int p = 3;이므로 [p]==[3]부터 시작해서 마지막에 p++; >> 다음에 추가하기 선택시 [4]... 앞 인덱스부터 차례대로 추가하기
		}

		if (menu == 5) //5.검색하기 선택
		{
			char search[100]; //검색한 키워드를 담을 배열 search 선언
			int found = 0; //일치하는 키워드의 유무를 나타낼 변수 found 선언
			printf("\n검색 키워드를 입력하세요: ");
			scanf_s("%s", search, sizeof(search)); //검색 키워드 입력받기

			for (int i = 0; i < p; i++) //구조체 배열에 있는 요소와 비교
			{
				if (strstr(list[i].name, search) != NULL) //list[i].name에 search(검색한 키워드)가 없을 경우 NULL값 출력
				{
					printf("검색한 영화정보: %d. %s, %d, %c, (%d, %d)\n", i, list[i].name, list[i].year, list[i].YN, list[i].c_grade, list[i].i_grade);
					found = 1; //일치하는 키워드가 있을 경우 found에 1대입
				}
			}
			if (found == 0) //일치하는 키워드가 없을 경우 "일치하는 키워드가 없습니다" 안내 메세지 출력
				printf("일치하는 키워드가 없습니다.");
		}

		if (menu == 6) //6.종료하기 선택시 안내 메세지 출력 후 프로그램 종료
		{
			file(list, p); //함수 실행
			printf("\n\n프로그램을 종료합니다.\n");
			fclose(fp_r); //파일 닫기
		}

	} while (menu != 6); //6.종료하기 선택시 종료

	return 0;
}

void main()
{
	struct movie list[100] = { 0 }; //구조체 초기화
	add(list);
}