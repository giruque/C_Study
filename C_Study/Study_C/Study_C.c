#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Lesson_1.h"
#include <stdarg.h>

#pragma region "파일 분리 예시"

void test_swap()
{
	int a = 1;
	int b = 2;

	swap(&a, &b);

	printf("%d", b);
}

#pragma endregion

#pragma region "이전 데이터"

void two_dimensional_array()
{
	int numArr[3][4] =
	{
	{11,22,33,44},
	{55,66,77,88},
	{99,110,121,132}
	};

	printf("%d\n", numArr[0][0]);
	printf("%d\n", numArr[1][2]);
	printf("%d\n", numArr[2][0]);
	printf("%d\n", numArr[2][3]);
}

void two_dimensional_array_init()
{
	int numArr[3][4] = { 0 , };

	printf("%d\n", numArr[0][0]);
	printf("%d\n", numArr[1][2]);
	printf("%d\n", numArr[2][0]);
	printf("%d\n", numArr[2][3]);
}

void two_dimensional_array_size()
{
	int numArr[3][4] = {
		{11,22,33,44},
		{55,66,77,88},
		{99,110,121,132}
	};

	printf("%d\n", sizeof(numArr));

	int col = sizeof(numArr[0]) / sizeof(int);
	int row = sizeof(numArr) / sizeof(numArr[0]);

	printf("%d\n", col);
	printf("%d\n", row);
}

void two_dimensional_array_for()
{
	int numArr[3][4] = {
		{11,22,33,44},
		{55,66,77,88},
		{99,110,121,132}
	};

	int col = sizeof(numArr[0]) / sizeof(int);   //가로 줄
	int row = sizeof(numArr) / sizeof(numArr[0]); //세로 줄

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", numArr[i][j]);
		}
		printf("\n");
	}
}

void two_dimensional_array_for_reverse()
{
	int numArr[3][4] = {
	{11,22,33,44},
	{55,66,77,88},
	{99,110,121,132}
	};

	int col = sizeof(numArr[0]) / sizeof(int);   //가로 줄
	int row = sizeof(numArr) / sizeof(numArr[0]); //세로 줄

	for (int i = row - 1; i >= 0; i--)
	{
		for (int j = col - 1; j >= 0; j--)
		{
			printf("%d ", numArr[i][j]);
		}
		printf("\n");
	}
}

void pointer_to_two_dimensional_array()
{
	int numArr[3][4] = {    // 세로 3, 가로 4 크기의 int형 2차원 배열 선언
	{ 11, 22, 33, 44 },
	{ 55, 66, 77, 88 },
	{ 99, 110, 121, 132 }
	};

	int(*numptr)[4] = numArr;

	printf("%p\n", *numptr);
	printf("%d\n", numptr[2][1]);
	printf("%d\n", sizeof(numArr));
	printf("%d\n", sizeof(numptr));
}

void three_dimensional_array()
{
	int numArr[2][3][4] = {
	{
		{11,22,33,44},
		{55,66,77,88},
		{99,110,121,132}
	},
	{
		{111,222,333,444},
		{555,666,777,888},
		{999,1111,1222,1333}
	}
	};

	int(*numptr)[4] = numArr;

	printf("%d", numArr[1][1][1]);
}

void practice_principal_diagonal_of_matrix()
{
	int matrix[8][8] = {
		{  1,  2,  3,  4,  5,  6,  7,  8 },
		{  9, 10, 11, 12, 13, 14, 15, 16 },
		{ 17, 18, 19, 20, 21, 22, 23, 24 },
		{ 25, 26, 27, 28, 29, 30, 31, 32 },
		{ 33, 34, 35, 36, 37, 38, 39, 40 },
		{ 41, 42, 43, 44, 45, 46, 47, 48 },
		{ 49, 50, 51, 52, 53, 54, 55, 56 },
		{ 57, 58, 59, 60, 61, 62, 63, 64 }
	};

	int col = sizeof(matrix[0]) / sizeof(int);
	int row = sizeof(matrix) / sizeof(matrix[0]);

	printf("%d %d\n", col, row);

	for (int i = 0; i < row; i++)
	{
		for (int j = i; j <= i; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}

void judge_transpose_of_matrix()
{
	int matrix[5][5];

	scanf("%d %d %d %d %d",
		&matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3], &matrix[0][4]);
	scanf("%d %d %d %d %d",
		&matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3], &matrix[1][4]);
	scanf("%d %d %d %d %d",
		&matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3], &matrix[2][4]);
	scanf("%d %d %d %d %d",
		&matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3], &matrix[3][4]);
	scanf("%d %d %d %d %d",
		&matrix[4][0], &matrix[4][1], &matrix[4][2], &matrix[4][3], &matrix[4][4]);

	int col = sizeof(matrix[0]) / sizeof(int);
	int row = sizeof(matrix) / sizeof(matrix[0]);

	for (int i = row - 1; i >= 0; i--)
	{
		printf("%d ", matrix[i][i]);
	}
}

void pointer_like_array()
{
	int* numptr = malloc(sizeof(int) * 10);
	printf("%d\n", sizeof(int) * 10); //4바이트 = 32비트
	printf("%d\n", sizeof(*numptr)); //4바이트 = 32비트


	numptr[0] = 20;    //0001 0100 8비트
	numptr[1] = 20;
	numptr[2] = 20;
	numptr[3] = 20;

	printf("%d\n", sizeof(numptr[20]));
	printf("%d\n", numptr[30]);

	free(numptr);

}

void pointer_scanf_like_array()
{
	int size;
	scanf("%d", &size);

	int* numptr = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		numptr[i] = i;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d\n", numptr[i]);
	}

	free(numptr);
}

void pointer_like_two_dimentional_array()
{
	//int*m=malloc(sizeof(int));
	int** m = malloc(sizeof(int*) * 3);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼
										   // 동적 메모리 할당. 배열의 세로

	for (int i = 0; i < 3; i++)            // 세로 크기만큼 반복
	{
		m[i] = malloc(sizeof(int) * 4);    // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
										   // 배열의 가로
	}

	m[0][0] = 1;    // 세로 인덱스 0, 가로 인덱스 0인 요소에 값 할당
	m[2][0] = 5;    // 세로 인덱스 2, 가로 인덱스 0인 요소에 값 할당
	m[2][3] = 2;    // 세로 인덱스 2, 가로 인덱스 3인 요소에 값 할당

	printf("%d\n", m[0][0]);    // 1: 세로 인덱스 0, 가로 인덱스 0인 요소의 값 출력
	printf("%d\n", m[2][0]);    // 5: 세로 인덱스 2, 가로 인덱스 0인 요소의 값 출력
	printf("%d\n", m[2][3]);    // 2: 세로 인덱스 2, 가로 인덱스 3인 요소의 값 출력

	for (int i = 0; i < 3; i++)    // 세로 크기만큼 반복
	{
		free(m[i]);                // 2차원 배열의 가로 공간 메모리 해제
	}

	free(m);    // 2차원 배열의 세로 공간 메모리 해제

}

void pointer_scanf_like_two_dimensional_array()
{
	int row, col;

	scanf("%d %d", &row, &col);

	int** m = malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		m[i] = malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m[i][j] = i + j;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", m[i][j]);

		printf("\n");
	}

	for (int i = 0; i < row; i++)
	{
		free(m[i]);
	}

	free(m);


}

void practice_pointer_like_three_dimensional_array()
{
	long long*** m = malloc(sizeof(long long**) * 2);


	for (int i = 0; i < 2; i++)
	{
		m[i] = malloc(sizeof(long long*) * 3);


		for (int j = 0; j < 3; j++)
		{
			m[i][j] = malloc(sizeof(long long) * 5);
		}
	}

	m[1][2][4] = 100;

	printf("%lld\n", m[1][2][4]);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			free(m[i][j]);
		}
		free(m[i]);
	}
}

void judge_pointer_dimensional()
{
	int col;

	scanf("%d", &col);

	int row = col;

	int** ptr = malloc(sizeof(int*) * row);

	for (int i = 0; i < col; i++)
	{
		ptr[i] = malloc(sizeof(int) * col);
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
			{
				ptr[i][j] = 1;
			}
			else
				ptr[i][j] = 0;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d", ptr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
#pragma endregion

#pragma region "39강 끝나고 다시보기"

void test_str()                             // 다시 보기
{
	const int str_length = 10;
	char* str = (char*)malloc(sizeof(char) * str_length + 1);

	printf("str(%d) : ", str_length);
	scanf_s("%[^\n]s", str, sizeof(char) * str_length + 1);

	printf("result : %s", str);
}

void test_str_39()
{
	int line_count = 0;
	int line_length = 0;
	printf("line_count : ");
	scanf_s("%d", &line_count);

	printf("line_length : ");
	scanf_s("%d", &line_length);


	char** matrix = (char**)malloc(sizeof(char*) * line_count);

	for (int i = 0; i < line_count; i++)
	{
		matrix[i] = (char*)malloc(sizeof(char) * (line_length + 1));
		memset(matrix[i], 0, sizeof(char) * (line_length + 1));
	}

	for (int i = 0; i < line_count; i++)
	{
		printf("[%d] input : ", i + 1);
		scanf_s("%s", matrix[i], sizeof(matrix[i]));
	}

	for (int i = 0; i < line_count; i++)
	{
		printf("[%d] %s\n", i + 1, matrix[i]);
	}

	for (int i = 0; i < line_count; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void judge_mine_finder()
{
	int m;	//int m 선언 (세로)
	int n; // int n 선언 (가로)
	int count = 0;

	scanf("%d %d", &m, &n);	//입력받아서 세로,가로 크기 입력


	char** matrix = malloc(sizeof(char) * m); //2중포인터선언=1중포인터 char*세로크기 

	for (char i = 0; i < m; i++)	// 세로줄만큼 반복
	{
		matrix[i] = malloc(sizeof(char) * (n + 1));	// 가로줄 하나씩 메모리 할당
	}

	for (char i = 0; i < m; i++) // 세로줄 만큼 반복
	{
		scanf("%s", matrix[i]); // 가로줄 하나당 입력받은 값 입력
	}

	for (char i = 0; i < m; i++)
	{
		for (char j = 0; j < m; j++)
		{
			if (matrix[i][j] == '*')
			{
				printf("*");
			}
			else
			{
				if (matrix[i][j - 1] == '*' || matrix[i][j + 1] == '*' || matrix[i - 1][j] == '*' || matrix[i + 1][j] == '*' || i >= 0 || i < m || j >= 0 || j < n)
				{
					printf("%d", count += 1);
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

#pragma endregion

#pragma region "39강 문자열 사용하기"
void string_pointer_element()
{
	char* s1 = "hello";

	printf("%c\n", s1[1]);
	printf("%c\n", s1[4]);
	printf("%c\n", s1[5]);
}

void string_pointer_element_assign_error()
{
	char* s1 = "hello";

	s1[0] = 'A';

	printf("%c\n", s1[0]);
}

void string_array_omit_size()
{
	char s1[] = "hello";


	printf("%s\n", s1);    // Hello: %s로 문자열 출력
}

void string_array_element()
{
	char s1[10] = "hello";

	printf("%c\n", s1[1]);
	printf("%c\n", s1[4]);
	printf("%c\n", s1[5]);
}

void string_array_element_assign()
{
	char s1[10] = "hello";

	s1[0] = 'A';

	printf("%s\n", s1);
}

void practice_string()
{
	char* s1 = "beethoven 9th Symphony";

	printf("%s", s1);
}

void practice_string_array_element()
{
	char s1[30] = "Beethoven 9th Symphnoy";

	printf("%c\n", s1[10]);
}

void judge_string()
{
	char* s1 = "Beethoven\n9th\nSymphony";

	printf("%s\n", s1);
}

#pragma endregion

#pragma region "40강 입력 값을 문자열에 저장하기"

void scanf_string_array()
{
	char s1[10];

	printf("문자열을 입력하세요: ");
	scanf("%s", s1);

	printf("%s\n", s1);
}

void scanf_string_with_space()
{
	char s1[30];

	printf("문자열을 입력하세요: ");
	scanf("%[^\n]s", s1);    // 공백까지 포함하여 문자열 입력받기

	printf("%s\n", s1);
}

void scanf_string_pointer_memory()
{
	char* s1 = malloc(sizeof(char) * 10);  // 문자열 포인터에 저장하려면 메모리 할당 필수

	printf("문자열 입력하세요: ");
	scanf("%s", s1);

	printf("%s\n", s1);

	free(s1);
}

void scanf_two_string_array()
{
	char s1[10];
	char s2[20];

	printf("문자열을 2개 입력하세요: ");
	scanf("%s %s", s1, s2);

	printf("%s\n", s1);
	printf("%s\n", s2);
}

void practice_scanf_string_pointer_memory()
{
	char* s1 = malloc(sizeof(char) * 10);
	printf("문자 입력: ");
	scanf("%s", s1);

	printf("%s", s1);

	free(s1);
}

void practice_scanf_three_string_pointer_memory()
{
	char* s1 = malloc(sizeof(char) * 10);
	char* s2 = malloc(sizeof(char) * 10);
	char* s3 = malloc(sizeof(char) * 10);

	printf("문자열을 세 개 입력하세요: ");
	scanf("%s %s %s", s1, s2, s3);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);

	free(s1);
	free(s2);
	free(s3);

}

void judge_scanf_four_string()
{
	char* s1 = malloc(sizeof(char) * 31);
	char* s2 = malloc(sizeof(char) * 31);
	char* s3 = malloc(sizeof(char) * 31);
	char* s4 = malloc(sizeof(char) * 31);

	scanf("%s %s %s %s", s1, s2, s3, s4);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s", s4);

	free(s1);
	free(s2);
	free(s3);
	free(s4);

}
#pragma endregion

#pragma region "41강 문자열 길이 구하고 비교하기"

void string_length()
{
	char* s1 = "hello";
	char* s2 = "hello";

	printf("%d\n", strlen(s1));
	printf("%d\n", strlen(s2));

}

void string_compare_abc()
{
	// aaa는 ASCII 코드로 97 97 97
	// aab는 ASCII 코드로 97 97 98
	// aac는 ASCII 코드로 97 97 99


	printf("%d\n", strcmp("aaa", "aaa"));
	printf("%d\n", strcmp("aab", "aaa"));
	printf("%d\n", strcmp("aab", "aac"));
}

void string_scanf_compare()
{
	char s1[20];
	char s2[20];

	printf("문자열 두 개를 입력하세요: ");
	scanf("%s %s", s1, s2);

	int ret = strcmp(s1, s2);

	switch (ret)
	{
	case 0:
		printf("두 문자열이 같음\n");
		break;

	case 1:
		printf("%s보다 %s가 큼\n", s2, s1);
		break;

	case -1:
		printf("%s보다 %s가 큼\n", s1, s2);
		break;
	}

}

void practice_string_length()
{
	char* s1 = "C language";

	printf("%d\n", strlen(s1));

}

void practice_string_compare()
{
	char* s1 = "Pachelbel Canon";
	char* s2 = "Pachelbel Canon";

	int ret = strcmp(s1, s2);

	printf("%d", ret);

}

void judge_string_scanf_printf()
{
	char s1[31];

	scanf("%s", s1);
	printf("%d", strlen(s1));

}

void judge_string_compare()
{
	char c1[31];
	char c2[31];

	scanf("%s %s", c1, c2);

	int ret = strcmp(c1, c2);

	printf("%d", ret);

}

#pragma endregion

#pragma region "42강 문자열 복사하고 붙이기"

void string_copy_array_to_array()
{
	char s1[10] = "Hello";
	char s2[10];

	strcpy(s2, s1);

	printf("%s\n", s2);

}

void string_copy_pointer_to_pointer_error()
{
	char* s1 = "Hello";
	char* s2 = "";

	strcpy(s2, s1);

	printf("%s\n", s2);

}

void string_copy_pointer_to_memory()
{
	char* s1 = "Hello";
	char* s2 = malloc(sizeof(char) * 10);

	strcpy(s2, s1);
	printf("%s\n", s2);

	free(s2);

}

void string_concatenate_array_to_array()
{
	char s1[10] = "world";
	char s2[20] = "Hello";

	strcat(s2, s1);

	printf("%s\n", s2);

}

void string_concatenate_pointer_to_pointer_error()
{
	char* s1 = "world";
	char* s2 = "Hello";

	strcat(s2, s1);

	printf("%s\n", s1);
}

void string_concatenate_pointer_to_memory()
{
	char* s1 = "world";
	char* s2 = malloc(sizeof(char) * 20);

	strcpy(s2, "hello");
	strcat(s2, s1);

	printf("%s\n", s2);
	printf("%s\n", s1);

	free(s2);
}

void string_copy_array_to_memory()
{
	char s1[10] = "hello";
	char* s2 = malloc(sizeof(char) * 10);

	strcpy(s2, s1);
	printf("%s\n", s2);

	free(s2);
}

void string_concatenate_array_to_memory()
{
	char s1[10] = "world";
	char* s2 = malloc(sizeof(char) * 20);

	strcpy(s2, "hello");

	printf("%s\n", s2);

	strcat(s2, s1);

	printf("%s\n", s2);

	free(s2);
}

void practice_string_copy_pointer_to_array()
{
	char* sourceStr = "C Language";
	char targetStr[20];

	strcpy(targetStr, sourceStr);

	printf("%s\n", targetStr);
	printf("%s\n", sourceStr);
}

void practice_string_pointer_to_memory()
{
	char* sourceStr = "The Little Prince";
	char* targetStr = malloc(sizeof(char) * 20);

	strcpy(targetStr, sourceStr);

	printf("%s\n", targetStr);

	free(targetStr);
}

void practice_string_concatenate_array_to_array()
{
	char sourceStr[20] = " 9th Symphony";
	char targetStr[40] = "Beethoven";

	strcat(targetStr, sourceStr);

	printf("%s\n", targetStr);

}

void practice_string_concatenate_pointer_to_memory()
{
	char* sourceStr = " Wonderland";
	char* targetStr = malloc(sizeof(char) * 30);

	strcpy(targetStr, "Alice in");
	strcat(targetStr, sourceStr);

	printf("%s\n", targetStr);

	free(targetStr);
}

void judge_string_copy_array_to_array()
{
	const char* SourceStr = "Beethoven";
	char Str1[31];
	char Str2[31];

	strcpy(Str1, SourceStr);
	strcpy(Str2, Str1);

	printf("%s\n", Str1);
	printf("%s\n", Str2);
}

void judge_string_concatenate()
{
	const char* SourceStr = "th";
	char targetStr[40];

	scanf("%s", targetStr);

	strcat(targetStr, SourceStr);

	printf("%s\n", targetStr);

}
#pragma endregion

#pragma region "43강 문자열 만들기"

void string_format_array()
{
	char s1[20];
	sprintf(s1, "hello, %s", "world");
	printf("%s\n", s1);
}

void string_format_char_int_float_array()
{
	char s1[30];

	sprintf(s1, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);

	printf("%s\n", s1);
}

void string_format_memory()
{
	char* Str1 = malloc(sizeof(char) * 20);

	sprintf(Str1, "hello, %s", "world!");

	printf("%s\n", Str1);

	free(Str1);
}

void string_format_char_int_float_memory()
{
	char* s1 = malloc(sizeof(char) * 30);

	sprintf(s1, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);

	printf("%s\n", s1);

	free(s1);

}

void practice_string_format_array()
{
	char s1[20];

	sprintf(s1, "%dth %s", 9, "Symphony");

	printf("%s\n", s1);

}

void practice_string_format_int_char_array()
{
	char s1[20];
	sprintf(s1, "%d %d %d %c %d", 10, 20, 30, 'c', 99);
	printf("%s\n", s1);

}

void judge_string_format_ordinal()
{

	int number;
	char name[31], result[40];
	char* ordinal;

	printf("1~7사이 숫자와 30이하의 문자를 입력하세요: ");
	scanf("%d %s", &number, name);

	if (number == 1)
		ordinal = "th";
	else
		ordinal = "nd";

	sprintf(result, "%d%s %s", number, ordinal, name);
	printf("%s\n", result);

}

#pragma endregion

#pragma region "44강 문자열 검사하기"

void string_find_character()
{
	char s1[30] = "A Garden Diary";  // 크기가 30인 char형 배열을 선언하고 문자열 할당

	char* ptr = strchr(s1, 'a');     // 'a'로 시작하는 문자열 검색, 포인터 반환

	while (ptr != NULL)              // 검색된 문자열이 없을 때까지 반복
	{
		printf("%s\n", ptr);         // 검색된 문자열 출력
		ptr = strchr(ptr + 1, 'a');  // 포인터에 1을 더하여 a 다음부터 검색
	}
}

void string_find_from_the_right_character()
{
	char s1[30] = "A Garden Diary";

	char* ptr = strrchr(s1, 'a');

	printf("%s\n", ptr);
}

void string_find_string()
{
	char s1[30] = "A Garden Diary";
	char* ptr = strstr(s1, "den");
	printf("%s\n", ptr);

}

void string_find_string_while()
{
	char s1[100] = "A Garden Diary A Garden Diary A Garden Diary";

	char* ptr = strstr(s1, "den");

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strstr(ptr + 1, "den");
	}
}

void practice_string_find_character()
{
	char s1[30] = "Alice in Wonderland";

	char* ptr = strchr(s1, 'n');

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strchr(ptr + 1, 'n');
	}
}

void practice_string_find_from_the_right_character()
{
	char s1[30] = "The Little Prince";

	char* ptr = strrchr(s1, 'i');

	printf("%s\n", ptr);
}

void judge_string_find()
{
	char SourceString[1001];
	int blank_count = 0;
	scanf("%[^\n]s", SourceString);

	char* ptr = strchr(SourceString, ' ');

	while (ptr != NULL)
	{
		ptr = strchr(ptr + 1, ' ');
		blank_count++;
	}
	printf("%d", blank_count);
}
#pragma endregion

#pragma region "44강 예제"

/**
 * 문제
 * 5줄의 문자열을 입력받아 공백의 갯수를 출력하시오.
 * 입력
 * Dickens begins his novel, A Tale of Two Cities, in 1770, by describing the release of Doctor Manette from Bastille, before taking the story to 1793 and early 1794. In this time span, the narrative covers a broad story.
 * In a larger view, this novel begins in 1757, while its final scene looks forward to the situation of the post-revolutionary Paris.
 * This story has a historical context, which Dickens has organized around various events that occurred during the French Revolution.
 * He has drawn historical features from major events, including the fall of Bastille, the September Massacres, and the Reign of Terror.
 * This backdrop is the story’s context.
 *
 * 출력
 * NumberOfSpace : ???
 */
void check_number_of_space()
{
	const int height = 5;
	const int maxLength = 255;
	int spaceCount = 0;
	bool exitOuterLoop = false;

	char** context = malloc(sizeof(char*) * height);

	for (int i = 0; i < height; i++)
	{
		context[i] = (char*)malloc(sizeof(char) * (maxLength + 1));
		memset(context[i], 0, sizeof(char) * (maxLength + 1));
	}

	printf("문장 5개 입력하세요\n");

	for (int i = 0; i < height; i++)
	{
		scanf("%[^\n]s", context[i]);
		rewind(stdin);
	}

	for (int i = 0; i < height; i++)
	{
		char* checker = strchr(context[i], ' ');

		while (checker != NULL)
		{
			spaceCount++;
			checker = strchr(checker + 1, ' ');
		}
	}

	printf("NumberOfSpace : %d\n", spaceCount);

	for (int i = 0; i < height; i++)
	{
		free(context[i]);
	}
	free(context);
}

/*
* 문제1. 아래의 TYPE을 알맞게 변경하시오.
* 문제2. 공백의 갯수를 계산하는 부분에 내용을 완성하시오.
*/
int CheckNumberOfSpace(char* InStr)
{
	int spaceCount = 0;

	char* checker = strchr(InStr, ' ');

	while (checker != NULL)
	{
		spaceCount++;
		checker = strchr(checker + 1, ' ');
	}

	return spaceCount;
}

void CheckNumberRunner()
{
	const int height = 5;
	const int maxLength = 255;
	int spaceCount = 0;

	char** context = (char**)malloc(sizeof(char*) * height);

	for (int i = 0; i < height; i++)
	{
		context[i] = (char*)malloc(sizeof(char) * maxLength + 1);
		memset(context[i], 0, sizeof(char) * maxLength + 1);
	}

	for (int i = 0; i < height; i++)
	{
		printf("[%d] ", i);
		scanf("%[^\n]s", context[i]);
		rewind(stdin);
	}

	for (int i = 0; i < height; i++)
	{
		spaceCount += CheckNumberOfSpace(context[i]);
	}

	printf("NumberOfSpace : %d\n", spaceCount);
}

#pragma endregion

#pragma region "45강 문자열 자르기"

void string_tokenize_array()
{
	char SourceStr[30] = "The Little Prince";

	char* checker = strtok(SourceStr, " ");

	while (checker != NULL)
	{
		printf("%s\n", checker);
		checker = strtok(NULL, " ");
	}
}

void string_tokenzie_pointer_error()
{
	char* SourceStr = "The Little Prince";	//포인터 읽기 전용이라 안됨, 동적 메모리 필요
	char* checker = strtok(SourceStr, " ");

	while (checker != NULL)
	{
		printf("%s\n", checker);
		checker = strtok(NULL, " ");
	}
}

void string_tokenize_memory()
{
	char* SourceStr = malloc(sizeof(char) * 30);
	strcpy(SourceStr, "The Little Prince");

	char* checker = strtok(SourceStr, " ");

	while (checker != NULL)
	{
		printf("%s\n", checker);
		checker = strtok(NULL, " ");
	}

	free(SourceStr);
}

void String_tokenize_timestamp()
{
	char SourceStr[30] = "2015-06-10T15:32:19";

	char* checker = strtok(SourceStr, "-T:");

	while (checker != NULL)
	{
		printf("%s\n", checker);
		checker = strtok(NULL, "-T:");
	}
}

void string_tokenize_store_array()
{
	char SourceStr[30] = "The Little Prince";
	char* StoreArray[10] = { NULL, };
	char* checker = strtok(SourceStr, " ");
	int i = 0;

	while (checker != NULL)
	{
		StoreArray[i] = checker;
		i++;
		checker = strtok(NULL, " ");
	}

	for (int i = 0; i < 10; i++)
	{
		if (StoreArray[i] != NULL)
			printf("%s\n", StoreArray[i]);
	}
}

void practice_string_tokenize_array()
{
	char SourceStr[40] = "Alice's Adventures in Wonderland";
	char* checker = strtok(SourceStr, " ");

	while (checker != NULL)
	{
		printf("%s\n", checker);
		checker = strtok(NULL, " ");
	}
}

void judge_string_tokenize()
{
	char SourceStr[61] = { NULL, };
	scanf("%s", SourceStr);

	char* checker = strtok(SourceStr, ".");

	while (checker != NULL)
	{
		printf("%s\n", checker);
		checker = strtok(NULL, ".");
	}
}

void judge_string_tokenize_word()
{
	char SourceStr[1001] = { NULL, };
	int i = 0;
	int count = 0;
	int ret;

	scanf("%[^\n]s", SourceStr);

	char* storeArray[1001] = { NULL, };
	char* checker = strtok(SourceStr, " ,.");

	while (checker != NULL)
	{
		storeArray[i] = checker;
		i++;
		checker = strtok(NULL, " ,.");
	}

	for (int i = 0; i < 1001; i++)
	{
		if (storeArray[i] != NULL)
		{
			ret = strcmp(storeArray[i], "the");
			if (ret == 0)
			{
				count++;
			}
		}
	}
	printf("%d", count);
}

#pragma endregion

#pragma region "46강 문자열과 숫자를 서로 변환하기"

void ascii_string_to_intergerc()
{
	char* SourceStr = "283";
	int num1;

	num1 = atoi(SourceStr);

	printf("%d\n", num1);
}

void string_to_long()
{
	char* SourceStr = "0xaf10";
	int num1;

	num1 = strtol(SourceStr, NULL, 16);

	printf("%x %d\n", num1, num1);
}

void string_to_long_multiple_integers()
{
	char SourceStr = "0xaf10 42 0x27c 9952";
	int num1;
	int num2;
	int num3;
	int num4;
	char* end;

	num1 = strtol(SourceStr, &end, 16);
	num2 = strtol(end, &end, 10);
	num3 = strtol(end, &end, 16);
	num4 = strtol(end, NULL, 10);

	printf("%x\n", num1);
	printf("%d\n", num2);
	printf("%X\n", num3);
	printf("%d\n", num4);
}

void ascii_string_to_float()
{
	char* SourceStr = "35.283672";
	float num1;

	num1 = atof(SourceStr);

	printf("%f\n", num1);

}

void ascii_string_exponetial_notation_to_float()
{
	char* SourceStr = "3.e5";
	float num1;

	num1 = atof(SourceStr);

	printf("%e %f\n", num1, num1);

}

void string_to_flat_multiple_real_numbers()
{
	char* SourceStr = "35.283672 3.e5 9.81772 7.e-5";
	float num1;
	float num2;
	float num3;
	float num4;
	char* end;

	num1 = strtof(SourceStr, &end);
	num2 = strtof(end, &end);
	num3 = strtof(end, &end);
	num4 = strtof(end, NULL);

	printf("%f\n", num1);
	printf("%e\n", num2);
	printf("%f\n", num3);
	printf("%e\n", num4);
}

void integer_to_string()
{
	char s1[10];
	int num1 = 283;

	sprintf(s1, "%d", num1);

	printf("%s\n", s1);
}

void interger_to_hex_string()
{
	char s1[10];
	int num1 = 283;

	sprintf(s1, "0x%x", num1);

	printf("%s\n", s1);
}

void real_number_to_string()
{
	char s1[10];
	float num1 = 38.972340f;

	sprintf(s1, "%f", num1);

	printf("%s\n", s1);
}

void real_number_to_expoential_notation_string()
{
	char s1[20];
	float num1 = 38.972340f;

	sprintf(s1, "%e", num1);

	printf("%s\n", s1);

}

#pragma endregion

#pragma region "47강 회문 판별과 N-gram 만들기"

void palindrome()
{
	char word[30];
	int length;
	bool isPalindrome = true;

	printf("단어를 입력바람\n");
	scanf("%s", word);

	length = strlen(word);

	for (int i = 0; i < length / 2; i++)
	{
		if (word[i] != word[length - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}
	printf("%d\n", isPalindrome);
}

void two_gram_character()
{
	char text[30] = "hello";
	int length;

	length = strlen(text);

	for (int i = 0; i < length - 1; i++)
	{
		printf("%c%c\n", text[i], text[i + 1]);
	}
}

void two_gram_word()
{
	char text[100] = "this is c language";
	char* tokens[30] = { NULL, };
	int count = 0;

	char* checker = strtok(text, " ");

	while (checker != NULL)
	{
		tokens[count] = checker;
		count++;
		checker = strtok(NULL, " ");
	}
	for (int i = 0; i < count - 1; i++)
	{
		printf("%s %s\n", tokens[i], tokens[i + 1]);
	}

	free(tokens);

}

void practice_integer_palindrome()
{
	long long num1;
	char text[30];

	printf("정수를 입력하세요\n ");
	scanf("%lld", &num1);

	sprintf(text, "%lld", num1);

	int length;

	length = strlen(text);

	bool ispalindrome = true;

	//int begin = 0;
	//int end = length - 1;

	//while (begin < end)
	//{
	//	if (text[begin] != text[end])
	//	{
	//		ispalindrome = false;
	//		break;
	//	}
	//	begin++;
	//	end--;
	//}

	for (int i = 0; i < length - 1; i++)
	{
		if (text[i] != text[length - 1 - i])
		{
			ispalindrome = false;
			break;
		}
	}
	printf("%d\n", ispalindrome);
}

void practice_4_gram_character()
{

	char* text = malloc(sizeof(char) * 30);
	memset(text, 0, sizeof(char) * 30);

	int length;
	int n = 4;

	printf("문자열 입력바람\n");
	scanf("%s", text);

	length = strlen(text);

	if (length < n)
	{
		printf("Wrong\n");
	}
	else
	{
		for (int i = 0; i < length - (n - 1); i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%c", text[i + j]);
			}

			printf("\n");
		}
	}

}

void judge_gram_check()
{
	char inputtext[29] = { NULL, };
	char* storeblank[29] = { NULL, };

	char* finaltext = malloc(sizeof(char) * 29);
	memset(finaltext, 0, sizeof(char) * 29);

	int i = 0;
	int length = 0;

	bool ispalindrom = true;

	printf("30이하의 영문 문자열을 입력하세요\n");
	scanf("%[^\n]s", inputtext);

	char* checker = strtok(inputtext, " ");

	while (checker != NULL)
	{
		storeblank[i] = checker;
		checker = strtok(NULL, " ");
		i++;
	}

	for (int i = 0; i < 29; i++)
	{
		if (storeblank[i] != NULL)
			strcat(finaltext, storeblank[i]);
	}

	length = strlen(finaltext);

	for (int i = 0; i < length / 2; i++)
	{
		if (finaltext[i] != finaltext[length - 1 - i])
		{
			ispalindrom = false;
			break;
		}
	}

	printf("%d", ispalindrom);

}

void judge_grame_test()
{
	int rule = 0;
	char inputdata[10] = { NULL, };
	int length = 0;

	printf("정수와 10이하의 문자열을 입력하세요\n");
	scanf("%d %s", &rule, inputdata);

	length = strlen(inputdata);

	if (length < rule)
	{
		printf("wrong\n");
	}

	for (int j = 0; j < length - rule + 1; j++)
	{
		printf("%c%c%c\n", inputdata[j], inputdata[j + 1], inputdata[j + 2]);
	}

	printf("%\n");
}

#pragma endregion

#pragma region "48강 구조체 사용하기"

#pragma region struct
struct person {
	char name[20];
	int age;
	char address[100];
} p1;

void struct_use()
{
	struct person p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);
}

void struct_variable()
{
	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);
}

void struct_init()
{
	struct person p1 = { .name = "홍길동", .age = 30, .address = "서울시 용산구 한남동" };

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	struct person p2 = { "고길동", 40, "길" };

	printf("이름: %s\n", p2.name);
	printf("나이: %d\n", p2.age);
	printf("주소: %s\n", p2.address);
}

#pragma endregion

#pragma region typedef struct
typedef struct _person {
	char name[20];
	int age;
	char address[100];
} person;

void use_typedef()
{
	person pp1;

	strcpy(pp1.name, "왕길우");
	pp1.age = 30;
	strcpy(pp1.address, "구로");

	printf("이름: %s\n", pp1.name);
	printf("나이: %d\n", pp1.age);
	printf("주소: %s\n", pp1.address);
}
#pragma endregion

#pragma region anonymouse_struct

typedef struct {
	char name[20];
	int age;
	char address[100];
}pperson;

void anonymous_struct()
{
	pperson ppp1;

	strcpy(ppp1.name, "왕귤");
	ppp1.age = 30;
	strcpy(ppp1.address, "구로");

	printf("이름: %s\n", ppp1.name);
	printf("나이: %d\n", ppp1.age);
	printf("주소: %s\n", ppp1.address);
}
#pragma endregion

#pragma region practice_struct

struct point2d {
	int x;
	int y;
};

void practice_struct()
{
	struct point2d p1;
	p1.x = 10;
	p1.y = 20;

	printf("%d %d\n", p1.x, p1.y);
}
#pragma endregion

#pragma region practice typedef_struct

typedef struct Point_2d_typedef_f {
	int x;
	int y;
}Point_2d_typedef;

void practice_typedef_struct()
{
	Point_2d_typedef p1;

	p1.x = 10;
	p1.y = 20;

	printf("%d %d\n", p1.x, p1.y);
}
#pragma endregion

#pragma region judge_deciare_struct_dashboard

struct DashBoard {
	int speed;
	char fuel;
	float mileage;
	int engineTemp;
	int rpm;
};

void judge_deciare_struct_dashboard()
{
	struct DashBoard d1;

	d1.speed = 80;
	d1.fuel = "F";
	d1.mileage = 5821.442871f;
	d1.engineTemp = 200;
	d1.rpm = 1830;

	printf("Speed: %dkm/h\n", d1.speed);
	printf("Fuel: %c\n", d1.fuel);
	printf("Mileage: %fkm\n", d1.mileage);
	printf("Engine temp: %d℃\n", d1.engineTemp);
	printf("RPM: %d\n", d1.rpm);
}

#pragma endregion

#pragma region judge_define_struct_dashboard

typedef struct dashboard02 {
	int speed;
	char fuel;
	float mileage;
	int engineTemp;
	int rpm;
}dashboard03;

void judge_define_struct_dashboard()
{
	dashboard03 d1;

	d1.speed = 80;
	d1.fuel = 'F';
	d1.mileage = 5821.442871f;
	d1.engineTemp = 200;
	d1.rpm = 1830;

	printf("Speed: %dkm/h\n", d1.speed);
	printf("Fuel: %c\n", d1.fuel);
	printf("Mileage: %fkm\n", d1.mileage);
	printf("Engine temp: %d℃\n", d1.engineTemp);
	printf("RPM: %d\n", d1.rpm);
}

#pragma endregion

#pragma endregion

#pragma region "49강 구조체 포인터 사용하기"

#pragma region struct_alloc_memory

struct Personn {
	char name[20];
	int age;
	char address[100];
};

void alloc_memory_struct()
{
	struct Personn* p1 = malloc(sizeof(struct Personn));

	strcpy(p1->name, "황귤");
	p1->age = 30;
	strcpy(p1->address, "구로");

	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);

	free(p1);
}

#pragma endregion

#pragma region "포인터 스트럭트 역참조" struct_member_dereference

struct Data {
	char c1;
	int* numptr;
};

void struct_member_dereference()
{
	int num1 = 10;			// num1 int형 변수 선언하고 10 할당
	struct Data d1;         //struct 변수 d1으로 선언
	struct Data* d2 = malloc(sizeof(struct Data));    // struct 변수 포인터 d2로 선언하고 메모리 할당

	d1.numptr = &num1;       // Data struct를 d1으로 호출해서 num1의 값을 numptr포인터의 값에 할당
	d2->numptr = &num1;		// Data struct를 포인터d2로 호출해서 num1의 값을 numptr포인터의 값에 할당

	printf("%d\n", *d1.numptr);	//d1으로 호출해서 numptr값 출력
	printf("%d\n", *d2->numptr); //d2포인터로 호출해서 numptr가 가르키는 값(int num1) 출력

	d2->c1 = 'a';		// 포인터d2로 호출해서 c1에 a 할당
	printf("%c\n", (*d2).c1);	//포인터 d2 호출해서 c1출력
	printf("%d\n", *(*d2).numptr);		//포인터d2의 포인터 numptr출력?
	printf("%d\n", *(d2->numptr));		//(포인터d2로 호출 numptr이 가르키는 값 = num1)을 

	free(d2); // 메모리 해제
}

#pragma endregion

#pragma region "구조체 별칭"

typedef struct _persoon {
	char name[20];
	int age;
	char address[100];
}persoon;

void struct_typedef_alloc_memory()
{
	persoon* p1 = malloc(sizeof(persoon));

	strcpy(p1->name, "황귤귤");
	p1->age = 30;
	strcpy(p1->address, "서울");

	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);

	free(p1);
}

#pragma endregion

#pragma region "malloc없이 구조체 포인터 사용법: &사용"

struct ppeerson {
	char name[20];
	int age;
	char address[100];
};

void pointer_to_struct()
{
	struct ppeerson p1;
	struct ppeerson* ptr;

	ptr = &p1;

	ptr->age = 30;

	printf("나이: %d\n", p1.age);      // 나이: 30: 구조체 변수의 멤버 값 출력
	printf("나이: %d\n", ptr->age);    // 나이: 30: 구조체 포인터의 멤버 값 출력
}

#pragma endregion

#pragma region "연습문제 학생정보"

struct Student_practice {
	char name[20];
	int grade;
	int class;
	float average;
};

void practice_student()
{
	struct Student_practice* S1 = malloc(sizeof(struct Student_practice));

	strcpy(S1->name, "고길동");
	S1->grade = 1;
	S1->class = 3;
	S1->average = 65.389999f;

	printf("이름: %s\n", S1->name);
	printf("학년: %d\n", S1->grade);
	printf("반: %d\n", S1->class);
	printf("평균점수: %f\n", S1->average);

	free(S1);
}

#pragma endregion

#pragma region "연습문제 3차원 좌표 구조체 포인터에 메모리 할당하기"

typedef struct _Point3D {
	float x;
	float y;
	float z;
} Point3D;


void Practice_typedef_struct_alloc_moemory()
{
	Point3D* p1 = malloc(sizeof(Point3D));

	p1->x = 10.0f;
	p1->y = 20.0f;
	p1->z = 30.0f;

	printf("%f %f %f\n", p1->x, p1->y, p1->z);

	free(p1);
}

#pragma endregion

#pragma region "연습문제 구조체 포인터에 구조체 주소 할당하기"

struct practice_Item {
	char name[100];
	int price;
	bool limited;
};

void practice_pointer_to_struct()
{
	struct practice_Item Item1 = { "베를린 필하모닉 베토벤 교향곡 전집", 100000,false };
	struct practice_Item* ptr = malloc(sizeof(struct practice_Item));

	ptr = &Item1;

	ptr->limited = true;

	if (ptr->limited == true)
		printf("한정판\n");
	else
		printf("일반판\n");

}

#pragma endregion

#pragma region judge_struct_alloc_memory

struct judge_person {
	char name[20];
	int age;
	char address[100];
};

typedef struct {
	char name[20];
	int number;
	int displacement;
}Car;

void judge_struct_alloc_memory()
{
	struct judge_person* p1 = malloc(sizeof(struct judge_person));
	strcpy(p1->name, "고길동");
	p1->age = 40;
	strcpy(p1->address, "서울시 서초구 반포동");

	Car* c1 = malloc(sizeof(Car));
	strcpy(c1->name, "스텔라");
	c1->number = 3421;
	c1->displacement = 2000;

	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);

	printf("자동차 이름: %s\n", c1->name);
	printf("자동차 번호: %d\n", c1->number);
	printf("배기량: %dcc\n", c1->displacement);

	free(p1);
	free(c1);
}

#pragma endregion

#pragma region judge_pointer_to_struct

struct judge_Point3D_48 {
	float x;
	float y;
	float z;
};

void judge_pointer_to_struct()
{
	struct judge_Point3D_48 p1 = { 10.0f,20.0f,30.0f };
	struct judge_point3D_48* ptr;

	ptr = &p1;

	//printf("%f %f %f\n", ptr->x, ptr->y, ptr->z);          //안됨
	printf("%f %f %f\n", p1.x, p1.y, p1.z);
}

#pragma endregion

#pragma endregion

#pragma region "50강 두 점 사이에 거리 구하기"

#pragma region "삼각형"

struct Point2D_50 {
	int x;
	int y;
};

int two_point_distacne()
{
	struct Point2D_50 p1;
	struct Point2D_50 p2;

	p1.x = 30;
	p1.y = 20;

	p2.x = 60;
	p2.y = 50;

	int a = p2.x - p1.y;
	int b = p2.y - p2.y;

	double c = sqrt(pow(a, 2) + pow(b, 2));
	printf("%f\n", c);
}

#pragma endregion

#pragma region "사각형"

struct Rectangle_50 {
	int x1, y1;
	int x2, y2;
};

int practice_area_of_rectangle()
{
	struct Rectangle_50 rect;
	int area;

	rect.x1 = 20;
	rect.y1 = 20;
	rect.x2 = 40;
	rect.y2 = 30;

	area = (rect.x2 - rect.x1) * (rect.y2 - rect.y1);

	printf("%d\n", area);
}

#pragma endregion

#pragma region "퀴즈_두 점 사이의 거리 구하기"

struct Point2D_50_quiz {
	int x;
	int y;
};

void judge_two_point_distance()
{
	struct Point2D_50_quiz p1;
	struct Point2D_50_quiz p2;
	double distance;

	scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);

	int a = (p2.x - p1.x);
	int b = (p2.y - p1.y);

	distance = sqrt(pow(a, 2) + pow(b, 2));

	printf("%f\n", distance);
}

#pragma endregion

#pragma endregion

#pragma region "51강 구조체 멤버 정렬 사용하기"

#pragma region struct_sizeof

struct PacketHeader {

	char flags; // 1바이트
	int seq; //4바이트
	long long pp;
};

void struct_sizeof()
{
	struct PacketHeader header;

	printf("%d\n", sizeof(header.flags));           // 1: char는 1바이트
	printf("%d\n", sizeof(header.seq));             // 4: int는 4바이트
	printf("%d\n", sizeof(header));					// 8: 구조체 전체 크기는 8바이트
	printf("%d\n", sizeof(struct PacketHeader));    // 8: 구조체 이름으로 크기 구하기
}

#pragma endregion

#pragma region struct_offset

struct PacketHeader_51 {
	char flags;
	int seq;
	long long pp;
};

void struct_offset()
{
	struct PacketHeader_51 header;

	printf("%d\n", offsetof(struct PacketHeader_51, flags));    // 0
	printf("%d\n", offsetof(struct PacketHeader_51, seq));      // 4
	printf("%d\n", offsetof(struct PacketHeader_51, pp));

	printf("\n%d\n", sizeof(header.flags));
	printf("%d\n", sizeof(header.seq));
	printf("%d\n", sizeof(header.pp));
	printf("%d\n", sizeof(struct PacketHeader_51));
}

#pragma endregion

#pragma region "구조체 정렬 피하기"

#pragma pack (push,1)
struct PacketHeader_struct_align {
	char flags;
	int seq;
};
#pragma pack(pop)

void struct_align()
{
	struct PacketHeader_struct_align header;

	printf("%d\n", sizeof(header.flags));
	printf("%d\n", sizeof(header.seq));
	printf("%d\n", sizeof(header));

	printf("%d\n", offsetof(struct PacketHeader_struct_align, flags));    // 0
	printf("%d\n", offsetof(struct PacketHeader_struct_align, seq));      // 1

}

#pragma endregion

#pragma region "quiz 구조체 크기 구하기"

struct CompressHeader_51_practice {
	char flags;
	int version;
};

void practice_struct_sizeof()
{
	struct CompressHeader_51_practice header;

	printf("%d\n", sizeof(header));
}

#pragma endregion

#pragma region "quiz 패킷 크기 조절하기"

#pragma pack(push, 1)
struct Packet_51_practice_struct_align {
	short legnth;
	int seq;
};
#pragma pack(pop)

void practice_struct_align()
{
	struct Packet_51_practice_struct_align pkt;

	printf("%d\n", sizeof(pkt));
	printf("%d\n", sizeof(short));
}
#pragma endregion

#pragma region "심사문제 암호화 헤더 크기 구하기"

struct EncryptionHeader {
	char flags;
	int four;
	int five;
};

void judge_struct_sizeof()
{
	struct EncryptionHeader header;

	printf("%d\n", sizeof(header));
}

#pragma endregion

#pragma region "심사문제 패킷 크기 조절하기"

#pragma pack(push,1)
struct Packet_51_judge_struct_align {
	char some;
	char thing;
	char voice;
};
#pragma pack(pop)

void judge_struct_align()
{
	struct Packet_51_judge_struct_align pkt;

	printf("%d\n", sizeof(pkt));
}

#pragma endregion

#pragma endregion

#pragma region "52강 구조체와 메모리 활용하기"

#pragma region "구조체 변수 초기화"

struct variable_memory_set {
	int x;
	int y;
};

void struct_variable_memory_set()
{
	struct variable_memory_set p1;

	memset(&p1, 0, sizeof(struct variable_memory_set));

	printf("%d %d\n", p1.x, p1.y);
}

#pragma endregion

#pragma region "구조체 포인터 초기화"

struct pointer_memory_set {
	int x;
	int y;
};

void struct_pointer_memory_set()
{
	struct pointer_memory_set* p1 = malloc(sizeof(struct pointer_memory_set));
	memset(p1, 0, sizeof(struct pointer_memory_set));

	printf("%d %d\n", p1->x, p1->y);

	free(p1);
}

#pragma endregion

#pragma region "구조체 메모리 복사하기"

#pragma variable_memory_copy

struct Point2D_variable_memory_copy {
	int x;
	int y;
};

void struct_variable_memory_copy()
{
	struct Point2D_variable_memory_copy p1;
	struct Point2D_variable_memory_copy p2;

	p1.x = 10;
	p1.y = 20;

	memcpy(&p2, &p1, sizeof(struct Point2D_variable_memory_copy));

	printf("%d %d\n", p2.x, p2.y);
}

#pragma endregion

#pragma region "동적 메모리끼리 복사하기"

struct Point2D_struct_pointer_memory_copy {
	int x;
	int y;
};

void struct_pointer_memory_copy()
{
	struct Point2D_struct_pointer_memory_copy* p1 = malloc(sizeof(struct Point2D_struct_pointer_memory_copy));
	struct Point2D_struct_pointer_memory_copy* p2 = malloc(sizeof(struct Point2D_struct_pointer_memory_copy));

	p1->x = 10;
	p1->y = 20;

	memcpy(p2, p1, sizeof(struct Point2D_struct_pointer_memory_copy));

	printf("%d %d\n", p2->x, p2->y);

	free(p2);
	free(p1);

}

#pragma endregion

#pragma region "연습문제 2차원 좌표 초기화하기"

struct Point2D_struct_memory_set {
	int x;
	int y;
};

void practice_struct_memory_set()
{
	struct Point2D_struct_memory_set p;
	struct Point2D_struct_memory_set* ptr = malloc(sizeof(struct Point2D_struct_memory_set));

	memset(&p, 0, sizeof(struct Point2D_struct_memory_set));
	memset(ptr, 0, sizeof(struct Point2D_struct_memory_set));

	printf("%d %d %d %d\n", p.x, p.y, ptr->x, ptr->y);

	free(ptr);
}

#pragma endregion

#pragma region "연습뮨제 2차원 좌표 복제하기"

struct Point_struct_memory_copy {
	int x;
	int y;
};

void practice_struct_memory_copy()
{
	struct Point_struct_memory_copy p1;
	struct Point_struct_memory_copy* p2 = malloc(sizeof(struct Point_struct_memory_copy));

	p1.x = 10;
	p1.y = 20;

	memcpy(p2, &p1, sizeof(struct Point_struct_memory_copy));

	printf("%d %d\n", p2->x, p2->y);

	free(p2);
}

#pragma endregion

#pragma region "심사문제 인적정보 삭제하기"

struct Person_52 {
	char name[20];
	int age;
	char address[100];
};

void judge_struct_memory()
{
	struct Person_52 p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시");

	memset(&p1, 0, sizeof(struct Person_52));

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

}

#pragma endregion

#pragma region "인적정보 복사하기"

struct person_51_memory_copy {
	char name[20];
	int age;
	char address[100];
};

void judge_struct_memory_copy()
{
	struct person_51_memory_copy* p1 = malloc(sizeof(struct person_51_memory_copy));
	struct person_51_memory_copy p2;

	strcpy(p1->name, "고길동");
	p1->age = 40;
	strcpy(p1->address, "서울시");

	memcpy(&p2, p1, sizeof(struct person_51_memory_copy));

	printf("이름: %s\n", p2.name);
	printf("나이: %d\n", p2.age);
	printf("주소: %s\n", p2.address);

	free(p1);
}

#pragma endregion

#pragma endregion

#pragma region "53강 구조체 배열 사용하기"

#pragma region struct_array

struct Point2D_struct_array {
	int x;
	int y;
};

void struct_array()
{
	struct Point2D_struct_array p[3];

	p[0].x = 10;
	p[0].y = 20;
	p[1].x = 30;
	p[1].y = 40;
	p[2].x = 50;
	p[2].y = 60;

	printf("%d %d\n", p[0].x, p[0].y);
	printf("%d %d\n", p[1].x, p[1].y);    // 30 40
	printf("%d %d\n", p[2].x, p[2].y);    // 50 60
}

#pragma endregion

#pragma region struct_array_init

struct Point2D_struct_array_init {
	int x;
	int y;
};

void struct_array_init()
{
	struct Point2D_struct_array_init p1[3] = { {.x = 10, .y = 20},{.x = 30,.y = 40},{.x = 50,.y = 60} };

	printf("%d %d\n", p1[0].x, p1[0].y);
	printf("%d %d\n", p1[1].x, p1[1].y);
	printf("%d %d\n", p1[2].x, p1[2].y);

	struct Point2D_struct_array_init p2[3] = { {10,20},{30,40},{50,60} };

	printf("%d %d\n", p2[0].x, p2[0].y);
	printf("%d %d\n", p2[1].x, p2[1].y);
	printf("%d %d\n", p2[2].x, p2[2].y);

}

#pragma endregion

#pragma region "구조체 포인터 배열 선언하기"

struct Point2D_struct_pointer_array {
	int x;
	int y;
};

void struct_pointer_array()
{
	struct Point2D_struct_pointer_array* p[3];

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D_struct_pointer_array*); i++)
	{
		p[i] = malloc(sizeof(struct Point2D_struct_pointer_array));
	}

	p[0]->x = 10;
	p[0]->y = 20;
	p[1]->x = 30;
	p[1]->y = 40;
	p[2]->x = 50;
	p[2]->y = 60;

	printf("%d %d\n", p[0]->x, p[0]->y);
	printf("%d %d\n", p[1]->x, p[1]->y);    // 30 40
	printf("%d %d\n", p[2]->x, p[2]->y);    // 50 60

	printf("%d %d", sizeof(p), sizeof(struct Point2D_struct_pointer_array*));

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D_struct_pointer_array*); i++)
	{
		free(p[i]);
	}

}

#pragma endregion

#pragma region "연습문제 2차원 좌표 출력하기"

struct Point2D_practice_struct_array {
	int x;
	int y;
};

void practice_struct_array()
{
	struct Point2D_practice_struct_array p[3];

	p[0].x = 10;
	p[0].y = 20;
	p[1].x = 30;
	p[1].y = 40;
	p[2].x = 50;
	p[2].y = 60;

	printf("%d %d\n", sizeof(p), sizeof(struct Point2D_practice_struct_array));

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D_practice_struct_array); i++)
	{
		printf("%d %d\n", p[i].x, p[i].y);
	}
}

#pragma endregion

#pragma region "연습문제 인적 정보를 초기화하기"

struct Person_53_struct_pointer_array {
	char name[20];
	int age;
	char address[100];
};

void practice_struct_pointer_array()
{
	struct Person_53_struct_pointer_array* p[3000];

	for (int i = 0; i < sizeof(p) / sizeof(struct Person_53_struct_pointer_array*); i++)
	{
		p[i] = malloc(sizeof(struct Person_53_struct_pointer_array));
		memset(p[i], 0, sizeof(struct Person_53_struct_pointer_array));
	}

	printf("%d\n", p[2000]->age);

	for (int i = 0; i < sizeof(p) / sizeof(struct Person*); i++)
	{
		free(p[i]);
	}

}

#pragma endregion

#pragma region "심사문제 선의 길이 구하기"

struct Point2D_judge_line_length {
	int x;
	int y;
};

void judge_line_length()
{
	struct Point2D_judge_line_length p[4];
	double length = 0.0f;

	scanf("%d %d %d %d %d %d %d %d",
		&p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y);

	int length1 = (p[1].x - p[0].x) + (p[2].x - p[1].x) + (p[3].x - p[2].x);
	int length2 = (p[1].y - p[0].y) + (p[2].y - p[1].y) + (p[3].y - p[2].y);

	length = sqrt(pow(length1, 2) + pow(length2, 2));


	printf("%f\n", length);
}

#pragma endregion

#pragma region "심사문제 나이가 가장 많은 사람 찾기"

struct Person_53_judge_oldest {
	char name[30];
	int age;
};

void judge_oldest()
{
	struct Person_53_judge_oldest* p[5];

	for (int i = 0; i < sizeof(p) / sizeof(struct Person_53_judge_oldest*); i++)
	{
		p[i] = malloc(sizeof(struct Person_53_judge_oldest));
		memset(p[i], 0, sizeof(struct Person_53_judge_oldest));
	}

	for (int i = 0; i < sizeof(p) / sizeof(struct Person_53_judge_oldest*); i++)
	{
		printf("%d번째 사람: ", i + 1);
		scanf("%s %d", p[i]->name, &p[i]->age);
	}

	char oldest[10];
	strcpy(oldest, p[0]->name);

	for (int i = 0; i < (sizeof(p) / sizeof(struct Person_53_judge_oldest*)) - 1; i++)
	{
		if (p[i]->age < p[i + 1]->age && p[0]->age < p[i + 1]->age)
		{
			strcpy(oldest, p[i + 1]->name);
		}
	}

	printf("%s", oldest);

	for (int i = 0; i < sizeof(p) / sizeof(struct Person*); i++)
	{
		free(p[i]);
	}
}

#pragma endregion

#pragma endregion

#pragma region "54강 공용체 사용하기"

#pragma region union_01

union Box_01 {
	short candy;
	float snack;
	char doll[8];
};

void union_01()
{
	union Box_01 b1;

	printf("%d\n", sizeof(b1));

	strcpy(b1.doll, "bear");

	printf("%d\n", b1.candy);
	printf("%f\n", b1.snack);
	printf("%s\n", b1.doll);
}

#pragma endregion

#pragma region union_endian_02

union Data_02 {
	char c1;
	short num1;
	int num2;
};

void union_endian_02()
{
	union Data_02 d1;

	d1.num2 = 0x12345678;

	printf("0x%x\n", d1.num2);
	printf("0x%x\n", d1.num1);
	printf("0x%x\n", d1.c1);

	printf("%d\n", sizeof(d1));
}

#pragma endregion

#pragma region "공용체 포인터를 선언하고 메모리 할당하기"

union box_03 {
	short candy;
	float snack;
	char doll[8];
};

void union_alloc_memory_03()
{
	union box_03* b1 = malloc(sizeof(union box_03));

	printf("%d\n", sizeof(union box_03));

	strcpy(b1->doll, "bear");

	printf("%d\n", b1->candy);
	printf("%f\n", b1->snack);
	printf("%s\n", b1->doll);

	free(b1);
}

#pragma region pointer_to_union

union Box_04 {
	short candy;
	float snack;
	char doll[8];
};

void pointer_to_union()
{
	union Box_04 b1;
	union Box_04* ptr;

	ptr = &b1;

	strcpy(ptr->doll, "bear");

	printf("%d\n", ptr->candy);
	printf("%f\n", ptr->snack);
	printf("%s\n", ptr->doll);
}

#pragma endregion

#pragma endregion

#pragma region practice_union

union Data_practice_01 {
	short num1;
	char c1;
};

void practice_union()
{
	union Data_practice_01 d1;
	d1.num1 = 0x5678;
	printf("0x%x 0x%x\n", d1.num1, d1.c1);
}

#pragma endregion

#pragma region practice_union_alloc_memory

union Data_practice_02 {
	short num1;
	int num2;
};

void practice_union_alloc_memory()
{
	union Data_practice_02* d1 = malloc(sizeof(union Data_practice_02));

	d1->num2 = 1;
	printf("%d %d\n", d1->num1, d1->num2);

	free(d1);
}

#pragma endregion

#pragma region "심사문제 정수데이터 공용체 사용하기"

union Data_judge_union {
	int num1;
	char c1;
};

void judge_union()
{
	union Data_judge_union d1;

	d1.num1 = 0x1111;

	printf("0x%x %d\n", d1.c1, sizeof(d1));
}

#pragma endregion

#pragma region "심사문제 공용체 포인터 사용하기"

union Data_judge_union_alloc_memory {
	short num1;
	int num2;
};

void judge_union_alloc_memory()
{
	union Data_judge_union_alloc_memory* d1 = malloc(sizeof(union Data_judge_union_alloc_memory));

	d1->num2 = 0x11111111;

	printf("0x%x 0x%x\n", d1->num1, d1->num2);

	free(d1);
}

#pragma endregion

#pragma endregion

#pragma region "55강 구조체와 공용체 활용하기"

#pragma region "구조체 안에서 구조체 멤버 사용하기"

struct Phone_55_01 {
	int areacode;
	unsigned long long number;
};

struct Person_55_01 {
	char name[20];
	int age;
	struct Phone_55_01 phone;
};

void struct_variable_in_struct()
{
	struct Person_55_01 p1;

	p1.phone.areacode = 82;
	p1.phone.number = 3045671234;

	printf("%d %llu\n", p1.phone.areacode, p1.phone.number);
}

#pragma endregion

#pragma region "구조체 변수를 선안하는 동시에 초기화하기"

struct Phone_55_02 {
	int areacode;
	unsigned long long number;
};

struct Person_55_02 {
	char name[20];
	int age;
	struct Phone_55_02 phone;
};

void struct_variable_in_struct_init()
{
	struct Person_55_02 p1 = { .name = "Andrew", .age = 25,{.areacode = 82, .number = 3045671} };

	printf("%d %llu\n", p1.phone.areacode, p1.phone.number);

	struct Person_55_02 p2 = { "Maria", 19, {28,88888} };

	printf("%d %llu\n", p2.phone.areacode, p2.phone.number);
}

#pragma endregion

#pragma region "구조체 안의 구조체 멤버에 메모리 할당하기"

#pragma region type1

struct Phone_55_3 {
	int areacode;
	unsigned long long number;
};

struct Person_55_3 {
	char name[20];
	int age;
	struct Phone_55_3 phone;
};

void struct_variable_in_struct_alloc_memory()
{
	struct Person_55_3* p1 = malloc(sizeof(struct Person_55_3));

	p1->phone.areacode = 82;
	p1->phone.number = 4545;

	printf("%d %llu\n", p1->phone.areacode, p1->phone.number);

	free(p1);

}

#pragma endregion

#pragma region type2

struct Phone_55_4 {
	int areacode;
	unsigned long long number;
};

struct Person_55_4 {
	char name[20];
	int age;
	struct Phone_55_4* phone;
};

void struct_pointer_in_struct_alloc_memory()
{
	struct Person_55_4* p1 = malloc(sizeof(struct Person_55_4));
	p1->phone = malloc(sizeof(struct Phone_55_4));

	p1->phone->areacode = 82;
	p1->phone->number = 2432;

	printf("%d %llu\n", p1->phone->areacode, p1->phone->number);

	free(p1->phone);
	free(p1);

}

#pragma endregion

#pragma endregion

#pragma region "55.3 익명 구조체와 익명 공용체 활용하기"  

struct Vector3_55_3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float v[3];
	};
};

void anonymous_struct_union()
{
	struct Vector3_55_3 pos;

	for (int i = 0; i < 3; i++)
	{
		pos.v[i] = 1.0f;
	}

	printf("%f %f %f\n", pos.x, pos.y, pos.z);
}

#pragma endregion

#pragma region "55.5 연습문제: 게임캐릭터 구조체 만들기"

struct Stats_practice {
	float health;
	float healthRegen;
	unsigned int mana;
	float manaRegen;
	float range;
	float attackDamage;
	float armor;
	float attackSpeed;
	float magicResist;
	unsigned int movementSpeed;
};

struct Champion {
	char name[20];
	float abilityPower;
	struct Stats_practice stats;
};

void practice_define_struct_champion()
{
	struct Champion lux;

	strcpy(lux.name, "Lux");
	lux.stats.health = 477.72f;
	lux.stats.healthRegen = 1.08f;
	lux.stats.mana = 334;
	lux.stats.manaRegen = 1.24f;
	lux.stats.range = 550;
	lux.stats.attackDamage = 55.5f;
	lux.stats.attackSpeed = 0.625f;
	lux.stats.armor = 18.72f;
	lux.stats.magicResist = 30;
	lux.stats.movementSpeed = 330;
	lux.abilityPower = 0;

	printf("%u %f\n", lux.stats.mana, lux.stats.manaRegen);
}

#pragma endregion

#pragma region "심사문제 : 게임캐릭터 구조체 사용하기"

struct Stats_55_judge {
	float health;
	float healthRegen;
	unsigned int mana;
	float manaRegen;
	float range;
	float attackDamage;
	float armor;
	float attackSpeed;
	float magicResist;
	unsigned int movementSpeed;
};

struct Champion_55_judge {
	char name[20];
	struct Stats_55_judge stats;
	float abilityPower;
};

void judge_declare_struct_champion()
{
	struct Champion_55_judge swain;

	strcpy(swain.name, "swain");
	swain.stats.health = 463.0f;
	swain.stats.healthRegen = 1.48f;
	swain.stats.mana = 290;
	swain.stats.manaRegen = 1.49f;
	swain.stats.range = 500;
	swain.stats.attackDamage = 52.0f;
	swain.stats.attackSpeed = 0.625f;
	swain.stats.armor = 20.0f;
	swain.stats.magicResist = 30;
	swain.stats.movementSpeed = 335;
	swain.abilityPower = 0;

	printf("%s %f\n", swain.name, swain.stats.health);
}

#pragma endregion

#pragma region "심사문제: 게임캐릭터 구조체 포인터 사용하기"

struct Stats_55_judge_2 {
	float health;
	float healthRegen;
	unsigned int mana;
	float manaRegen;
	float range;
	float attackDamage;
	float armor;
	float attackSpeed;
	float magicResist;
	unsigned int movementSpeed;
};

struct Champion_55_judge_2 {
	char name[20];
	struct Stats_55_judge_2* stats;
	float abilityPower;
};

void judge_alloc_memory_struct_champion()
{
	struct Champion_55_judge_2* swain = malloc(sizeof(struct Champion_55_judge_2));
	swain->stats = malloc(sizeof(struct Stats_55_judge_2));

	strcpy(swain->name, "swain");
	swain->stats->health = 463.0f;

	printf("%s %f\n", swain->name, swain->stats->health);

	free(swain->stats);
	free(swain);

}

#pragma endregion

#pragma region "심사문제 장치 옵션 구조체 만들기"

struct DeviceOption_judge_55 {
	union {
		struct {
			unsigned char boot;
			unsigned char interrupt;
		};
		short option;
	};
};

void judge_define_struct_device_option()
{
	struct DeviceOption_judge_55 opt;

	opt.boot = 0x22;
	opt.interrupt = 0x11;

	printf("0x%x\n", opt.option);
}

#pragma endregion

#pragma endregion

#pragma region "56강 구조체 비트 필드 사용하기"

#pragma region "56.1 구조체 비트 필드를 만들고 사용하기"

struct Flags_56_1 {
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 7;
};

void struct_bit_field()
{
	struct Flags_56_1 f1;

	f1.a = 1;
	f1.b = 15;
	f1.c = 255;

	printf("%u\n", f1.a);
	printf("%u\n", f1.b);
	printf("%u\n", f1.c);

	printf("%d", sizeof(struct Flags_56_1));
}

#pragma endregion

#pragma region "56.2 비트 필드와 공용체 함께 사용하기"

struct flags_56_2 {
	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 2;
			unsigned short c : 7;
			unsigned short d : 4;
		};
		unsigned short e;
	};
};


void struct_union_bit_field()
{
	struct flags_56_2 f1 = { 0, };

	f1.a = 4;     //  4: 0000 0100
	f1.b = 2;     //  2: 0000 0010
	f1.c = 80;    // 80: 0101 0000
	f1.d = 15;    // 15: 0000 1111

	printf("%d\n", sizeof(struct flags_56_2));
	printf("%u\n", f1.e);
	printf("%d\n", sizeof(int));
}

#pragma endregion

#pragma region "연습문제: 구조체로 플래그 비트 필드 만들기"

struct Flags_56_practice_01 {

	unsigned short a : 3;
	unsigned short b : 1;
	unsigned short c : 6;
};

void practice_struct_bit_field()
{
	struct Flags_56_practice_01 f1;

	f1.a = 0xffffffff;
	f1.b = 0xffffffff;
	f1.c = 0xffffffff;

	printf("%u %u %u\n", f1.a, f1.b, f1.c);
}

#pragma endregion

#pragma region "연습문제: 구조체와 공용체로 플래그 비트 필드 만들기"

struct Flags_56_practice_2 {
	union {
		struct {
			unsigned short a : 4;
			unsigned short b : 2;
			unsigned short c : 2;
			unsigned short d : 8;

		};
		unsigned short e;
	};
};

void practice_struct_union_bit_field()
{
	struct Flags_56_practice_2 f1 = { 0, };

	f1.a = 8;
	f1.b = 2;
	f1.c = 2;
	f1.d = 128;

	printf("%u\n", f1.e);

}

#pragma endregion

#pragma region "심사문제: 구조체로 플래그 비트 필드 만들기"

struct Flags_judge_01 {

	unsigned short a : 4;
	unsigned short b : 7;
	unsigned short c : 3;
};

void judge_struct_bit_field()
{
	struct Flags_judge_01 f1;

	f1.a = 0xffffffff;
	f1.b = 0xffffffff;
	f1.c = 0xffffffff;

	printf("%u %u %u\n", f1.a, f1.b, f1.c);
}

#pragma endregion

#pragma region "심사문제: 구조체와 공용체로 플래그 비트 필드 만들기"

struct Flags_judge_02 {
	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 4;
			unsigned short c : 7;
			unsigned short d : 2;
		};
		unsigned short e;
	};
};

void judge_struct_union_bit_field()
{
	struct Flags_judge_02 f1 = { 0, };

	f1.a = 4;
	f1.b = 8;
	f1.c = 64;
	f1.d = 3;

	printf("%u\n", f1.e);
}

#pragma endregion

#pragma endregion

#pragma region "57강 열거형 사용하기"

#pragma region "열거형 정의하기"

enum DayOfWeek {
	sunday = 0,
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday
};

void enum_57_1()
{
	enum DayOfWeek week;
	week = tuesday;

	printf("%d\n", week);
}

#pragma endregion

#pragma region "열거형을 switch에 활용하기"

enum LuxSkill {
	LightBinding = 1,
	PrismaticBarrier,
	LucentSingularity,
	FinalSpark
};

void enum_switch()
{
	enum LuxSkill skill;

	skill = LightBinding;

	switch (skill)
	{
	case LightBinding:
		printf("LightBinding\n");
		break;

	case PrismaticBarrier:
		printf("PrismaticBarrier\n");
		break;
	case LucentSingularity:
		printf("LucentSingularity\n");
		break;
	case FinalSpark:
		printf("FinalSpark\n");
		break;
	default:
		break;
	}
}

#pragma endregion

#pragma region "열거형을 for에 활용하기"

typedef enum DayOfWeek_57_3 {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	DayOfWeekCount
} DayOfWeek_57_3;

void enum_for()
{
	for (DayOfWeek_57_3 i = Sunday; i < DayOfWeekCount; i++)
	{
		printf("%d\n", i);
	}
}

#pragma endregion

#pragma region "57.5 연습문제: 장치 종류 정의하기"

enum DEVICE_TYPE {
	DEVICE_PCI_EC = 2,
	DEVICE_IEEE1394,
	DEVICE_USB
};

void practice_enum()
{
	enum DEVICE_TYPE type;
	type = DEVICE_IEEE1394;

	printf("%d\n", type);
}

#pragma endregion

#pragma region "57.6 연습문제: 게임 캐릭터 스킬 처리하기"

enum VayneSkill {
	Tumble = 1,
	SilverBolts,
	Condemn,
	FinalHour
};

void practice_enum_switch()
{
	enum VayneSkill skill;

	skill = Tumble;

	switch (skill)
	{
	case Tumble:
		printf("구르기\n");
		break;
	case SilverBolts:
		printf("은화살\n");
		break;
	case Condemn:
		printf("선고\n");
		break;
	case FinalHour:
		printf("결전의 시간\n");
		break;
	default:
		break;
	}
}

#pragma endregion

#pragma region "57.7 연습문제: 월 출력하기"

typedef enum Month_57_7 {
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec,
	MonthCount
}Month;

void practice_enum_for()
{
	for (Month i = Jan; i < MonthCount; i++)
	{
		printf("%d ", i);
	}
}

#pragma endregion

#pragma region "57.8 심사문제: 프로토콜 종류 정의하기"

enum PROTOCOL_TYPE_57_8 {
	a = 1,
	b,
	c,
	PROTOCOL_IP,
	PROTOCOL_UDP,
	PROTOCOL_TCP
};

void judge_enum()
{
	enum PROTOCOL_TYPE_57_8 p1, p2, p3;

	p1 = PROTOCOL_TCP;
	p2 = PROTOCOL_UDP;
	p3 = PROTOCOL_IP;

	printf("%d %d %d\n", p1, p2, p3);
}

#pragma endregion

#pragma region "57.9 심사문제; 게임 캐릭터 스킬 처리하기"

enum MasterYiSkill {
	AlphaStrike = 1,
	Meditation,
	WujuStyle,
	Highlander
};

void judge_enum_switch()
{
	enum MasterYiSkill skill;

	skill = Meditation;

	switch (skill)
	{
	case AlphaStrike:
		printf("일격 필살\n");
		break;
	case Meditation:
		printf("명상\n");
		break;
	case WujuStyle:
		printf("우주류 검술\n");
		break;
	case Highlander:
		printf("최후의 전사\n");
		break;
	default:
		break;
	}
}

#pragma endregion

#pragma region "57.10 심사문제: 인퍼이스 타입 출력하기"

typedef enum INTERFACE_TYPE_57_10 {
	InterfaceTypeUndefined = -1,
	Internal,
	Isa,
	Eisa,
	MicroChannel,
	TurboChannel,
	PCIBus,
	VMEBus,
	NuBus,
	PCMCIABus,
	CBus,
	MPIBus,
	MPSABus,
	ProcessorInternal,
	InternalPowerBus,
	PNPISABus,
	PNPBus,
	MaximumInterfaceType
} INTERFACE_TYPE_57_10, * PINTERFACE_TYPE;

void judge_enum_for()
{
	for (INTERFACE_TYPE_57_10 i = Internal; i < MaximumInterfaceType; i++)
	{
		printf("%d ", i);
	}
}

#pragma endregion

#pragma endregion

#pragma region "58강 자료형 변환하기"

void type_conversion_variable()
{
	int num1 = 32;
	int num2 = 7;
	float num3;

	num3 = num1 / num2;      // 컴파일 경고 발생
	printf("%f\n", num3);    // 4.000000

	num3 = (float)num1 / num2;    // num1을 float로 변환
	printf("%f\n", num3);         // 4.571429
}

void type_conversion_pointer()
{
	int* numPtr = malloc(sizeof(int));    // 4바이트만큼 메모리 할당
	char* cPtr;

	*numPtr = 0x12345678;

	cPtr = (char*)numPtr;     // int 포인터 numPtr을 char 포인터로 변환. 메모리 주소만 저장됨

	printf("0x%x\n", *cPtr);   // 0x78: 낮은 자릿수 1바이트를 가져오므로 0x78

	free(numPtr);    // 동적 메모리 해제
}

//void type_conversion_pointer_invalid_value()
//{
//	short* numPtr1 = malloc(sizeof(short));    // 2바이트만큼 메모리 할당
//	int* numPtr2;
//
//	*numPtr1 = 0x1234;
//
//	numPtr2 = (int*)numPtr1;    // short 포인터 numPtr1을 int 포인터로 변환. 메모리 주소만 저장됨
//
//	printf("0x%x\n", *numPtr2);    // 0xfdfd1234: 옆의 메모리를 침범하여 값을 가져옴
//								   // 0xfdfd는 상황에 따라서 값이 달라질 수 있음
//
//	free(numPtr1);    // 동적 메모리 해제
//}

void type_conversion_pointer_dereference()
{
	int* numptr = malloc(sizeof(int));
	char* cptr;
	*numptr = 0x12345678;

	printf("0x%x\n", *(char*)numptr);

	free(numptr);
}

void type_conversion_void_pointer() // void 포인터 변환하기, void pointer 자료형 맞춰줘야함
{
	int num1 = 10;
	float num2 = 3.5f;
	char c1 = 'a';
	void* ptr;

	ptr = &num1;    // num1의 메모리 주소를 void 포인터 ptr에 저장
	// printf("%d\n", *ptr);         // 컴파일 에러
	printf("%d\n", *(int*)ptr);     // 10: void 포인터를 int 포인터로 변환한 뒤 역참조

	ptr = &num2;    // num2의 메모리 주소를 void 포인터 ptr에 저장
	// printf("%f\n", *ptr);         // 컴파일 에러
	printf("%f\n", *(float*)ptr);   // 3.500000: void 포인터를 float 포인터로 변환한 뒤 역참조

	ptr = &c1;      // c1의 메모리 주소를 void 포인터 ptr에 저장
	// printf("%c\n", *ptr);         // 컴파일 에러
	printf("%c\n", *(char*)ptr);    // a: void 포인터를 char 포인터로 변환한 뒤 역참조
}

#pragma region "구조체 포인터 변환하기"

struct data_58_4 {
	char c1;
	int num1;
};

void type_conversion_struct_pointer()
{
	struct data_58_4* d1 = malloc(sizeof(struct data_58_4));    // 포인터에 구조체 크기만큼 메모리 할당
	void* ptr;    // void 포인터 선언

	d1->c1 = 'a';
	d1->num1 = 10;

	ptr = d1;    // void 포인터에 d1 할당. 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음.

	printf("%c\n", ((struct data_58_4*)ptr)->c1);      // 'a' : 구조체 포인터로 변환하여 멤버에 접근
	printf("%d\n", ((struct data_58_4*)ptr)->num1);    // 10  : 구조체 포인터로 변환하여 멤버에 접근

	free(d1);    // 동적 메모리 해제

}

#pragma endregion

#pragma region "구조체 포인터 별칭"

typedef struct data_58_4_2 {
	char c1;
	int num1;
}data_588, * pdata;

void type_conversion_typedef_struct()
{
	pdata d1 = malloc(sizeof(pdata));    // 구조체 포인터 별칭으로 포인터 선언
	void* ptr;   // void 포인터 선언

	d1->c1 = 'a';
	d1->num1 = 10;

	ptr = d1;    // void 포인터에 d1 할당. 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음.

	printf("%c\n", ((data_588*)ptr)->c1);     // 'a' : 구조체 별칭의 포인터로 변환
	printf("%d\n", ((pdata)ptr)->num1);    // 10  : 구조체 포인터 별칭으로 변환

	free(d1);    // 동적 메모리 해제
}

#pragma endregion

void practice_area_of_triangle()
{
	int base = 21;
	int height = 13;
	float area;

	area = ((float)base * height) / 2;
	printf("%f\n", area);
}

void practice_type_conversion_pointer()
{
	int* numptr1 = malloc(sizeof(int));
	short* numptr2;

	*numptr1 = 0x11223344;

	numptr2 = (short*)numptr1;

	printf("0x%x\n", *numptr2);

	free(numptr1);
}

#pragma region "58.9 연습문제: 구조체 포인터 변환하기"

struct Person_58_9 {
	char name[20];
	int age;
};

void practice_type_conversion_void_pointer()
{
	struct Person_58_9* p1 = malloc(sizeof(struct Person_58_9));
	void* ptr;

	strcpy(p1->name, "고길동");
	p1->age = 40;

	ptr = p1;

	printf("%s %d\n", ((struct Person_58_9*)ptr)->name, ((struct Person_58_9*)ptr)->age);

}

#pragma endregion

void judge_type_conversion_variable()
{
	float num1;
	int num2;

	scanf("%f", &num1);

	num2 = (int)num1;

	printf("%d\n", num2);
}

void judge_type_conversion_pointer()
{
	unsigned long long* numPtr1 = malloc(sizeof(unsigned long long));
	unsigned int* numPtr2;

	scanf("%llx", numPtr1);

	numPtr2 = (int*)numPtr1;
	printf("0x%x\n", *numPtr2);

	free(numPtr1);

}

void judge_type_conversion_void_pointer()
{
	long double* numPtr1 = malloc(sizeof(long double));
	void* ptr;

	scanf("%Lf", numPtr1);

	ptr = numPtr1;

	printf("%Lf\n", *(long double*)ptr);

	free(numPtr1);
}

#pragma region "심사문제: 구조체 포인터 변환하기"

struct Stats_58_judge {
	float health;
	float healthRegen;
	unsigned int mana;
	float manaRegen;
	float range;
	float attackDamage;
	float armor;
	float attackSpeed;
	float magicResist;
	unsigned int movementSpeed;
};

void judge_type_conversion_struct_pointer()
{
	void* ptr = malloc(sizeof(struct Stats_58_judge));
	struct Stats_58_judge st;

	scanf("%u %u", &st.mana, &st.movementSpeed);

	memcpy(ptr, &st, sizeof(struct Stats_58_judge));
	st.mana = 0;
	st.movementSpeed = 0;

	printf("%d\n", ((struct Stats_58_judge*)ptr)->mana);
	printf("%d\n", ((struct Stats_58_judge*)ptr)->movementSpeed);

	free(ptr);
}

#pragma endregion

#pragma endregion

#pragma region "59강 포인터 연산 사용하기"

#pragma region  "59.1강 포인터 연산으로 메모리 주소 조작하기"

void pointer_add()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = numArr;    // 배열 첫 번째 요소의 메모리 주소를 포인터에 저장

	numPtrB = numPtrA + 1;    // 포인터 연산
	numPtrC = numPtrA + 2;    // 포인터 연산

	printf("%p\n", numPtrA);    // 00A3FC00: 메모리 주소. 컴퓨터마다, 실행할 때마다 달라짐
	printf("%p\n", numPtrB);    // 00A3FC04: sizeof(int) * 1이므로 numPtrA에서 4가 증가함
	printf("%p\n", numPtrC);    // 00A3FC08: sizeof(int) * 2이므로 numPtrA에서 8이 증가함

	// 포인터 연산은 포인터 자료형의 크기(int)만큼 연산 됨

}

void pointer_sub()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];
	numPtrB = numPtrA - 1;
	numPtrC = numPtrA - 2;

	printf("%p\n", numPtrA);    // 00A3FC08: 메모리 주소. 컴퓨터마다, 실행할 때마다 달라짐
	printf("%p\n", numPtrB);    // 00A3FC04: sizeof(int) * -1이므로 numPtrA에서 4가 감소함
	printf("%p\n", numPtrC);    // 00A3FC00: sizeof(int) * -2이므로 numPtrA에서 8이 감소함

}

void pointer_increment_decrement()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];    // 배열 세 번째 요소의 주소를 포인터에 저장
	numPtrB = numPtrA;
	numPtrC = numPtrA;

	numPtrB++;
	numPtrC--;

	printf("%p\n", numPtrA);    // 00A3FC08: 메모리 주소. 컴퓨터마다, 실행할 때마다 달라짐
	printf("%p\n", numPtrB);    // 00A3FC0C: sizeof(int) * 1이므로 numPtrA에서 4가 증가함
	printf("%p\n", numPtrC);    // 00A3FC04: sizeof(int) * -1이므로 numPtrA에서 4가 감소함

}

#pragma endregion

#pragma region "59.2강 포인터 연산과 역참조 사용하기"

void pointer_dereference()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = numArr;
	numPtrB = numPtrA + 1;
	numPtrC = numPtrA + 2;

	printf("%d\n", *numPtrB);
	printf("%d\n", *numPtrC);
}

pointer_add_dereference()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;

	numPtrA = numArr;

	printf("%d\n", *(numPtrA + 1));    // 22: numPtrA에서 순방향으로 4바이트만큼 떨어진
									   // 메모리에 주소에 접근. numArr[1]과 같음

	printf("%d\n", *(numPtrA + 2));    // 33: numPtrA에서 순방향으로 8바이트만큼 떨어진
									   // 메모리에 주소에 접근. numArr[2]와 같음

	//괄호로 안묶어주면 값을 가져온 후 덧셈 연산함
}

void pointer_inc_dec_dereference()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];

	numPtrB = numPtrA;
	numPtrC = numPtrA;

	printf("%d\n", *(++numPtrB));
	printf("%d\n", *(--numPtrC));
}

#pragma endregion

#pragma region "59.3강 void포인터로 포인터 연산하기"

void void_pointer_arithmetic()
{
	void* ptr = malloc(100);

	printf("%p\n", ptr);
	printf("%p\n", (int*)ptr + 1);
	printf("%p\n", (int*)ptr - 1);

	void* ptr2 = ptr;
	printf("%p\n", ++(int*)ptr2);
	printf("%p\n", --(int*)ptr2);

	printf("%p\n", ((int*)ptr2)++);
	printf("%p\n", ((int*)ptr2)--);

	free(ptr);
}

#pragma endregion

#pragma region "59.4강 구조체 포인터로 포인터 연산하기"

#pragma region struct_pointer_add

struct Data_59_4_1 {
	int num1;
	int num2;
};

void struct_pointer_add()
{
	struct Data_59_4_1 d[3] = { {10,20},{30,40},{50,60} };
	struct Data_59_4_1* ptr;

	ptr = d;
	printf("%d %d\n", (ptr + 1)->num1, (ptr + 1)->num2);
	printf("%d %d\n", (ptr + 2)->num1, (ptr + 2)->num2);
}

#pragma endregion

#pragma region struct_void_pointer_add

struct Data_59_4_2 {
	int num1;
	int num2;
};

void struct_void_pointer_add()
{
	void* ptr = malloc(sizeof(struct Data_59_4_2) * 3);    // 구조체 3개 크기만큼 동적 메모리 할당
	struct Data_59_4_2 d[3];

	((struct Data_59_4_2*)ptr)->num1 = 10;        // 포인터 연산으로 메모리에 값 저장
	((struct Data_59_4_2*)ptr)->num2 = 20;        // 포인터 연산으로 메모리에 값 저장

	((struct Data_59_4_2*)ptr + 1)->num1 = 30;    // 포인터 연산으로 메모리에 값 저장
	((struct Data_59_4_2*)ptr + 1)->num2 = 40;    // 포인터 연산으로 메모리에 값 저장

	((struct Data_59_4_2*)ptr + 2)->num1 = 50;    // 포인터 연산으로 메모리에 값 저장
	((struct Data_59_4_2*)ptr + 2)->num2 = 60;    // 포인터 연산으로 메모리에 값 저장

	memcpy(d, ptr, sizeof(struct Data_59_4_2) * 3);    // 동적 메모리가 구조체 배열의 형태와 같은지 
													   // 확인하기 위해 동적 메모리의 내용을 구조체 배열에 복사

	printf("%d %d\n", d[1].num1, d[1].num2);    // 30 40: 구조체 배열의 멤버 출력
	printf("%d %d\n", ((struct Data_59_4_2*)ptr + 2)->num1, ((struct Data_59_4_2*)ptr + 2)->num2);
	// 50 60: 포인터 연산으로 메모리의 값 출력

	free(ptr);    // 동적 메모리 해제

}

#pragma endregion

#pragma endregion

void practice_pointer_add()
{
	int* numPtrA = NULL;

	printf("%p\n", numPtrA + 2);
	printf("%p\n", numPtrA + 5);
}

void practice_pointer_arithmetic_dereference()
{
	int numArr[5] = { 11,22,33,44,55 };
	int* numPtrA;
	void* ptr;

	numPtrA = &numArr[2];
	ptr = numArr;

	printf("%d\n", *(numPtrA + 2));
	printf("%d\n", *((int*)ptr + 1));
}

#pragma region "59.8 연습문제: 구조체 포인터와 포인터 연산"

struct Point2D_59_8 {
	int x;
	int y;
};

void practice_struct_pointer_add()
{
	struct Point2D_59_8 p[3] = { {10,20},{30,40},{50,60} };
	struct Point2D_59_8* ptr;

	ptr = p;

	printf("%d %d\n", (ptr + 1)->x, (ptr + 2)->y);

}

#pragma endregion

void judge_pointer_add()
{
	short* numPtrA;
	short* numPtrB;
	short* numPtrC;

	scanf("%p", &numPtrA);

	numPtrB = numPtrA + 3;
	numPtrC = numPtrA + 5;

	printf("%X\n", numPtrB);
	printf("%X\n", numPtrC);
}

void judge_pointer_add_dereference()
{
	int numArr1[3] = { 0, };
	long long numArr2[3] = { 0, };
	int* numPtr = malloc(sizeof(int) * 3);
	void* ptr = malloc(sizeof(long long) * 3);
	int num1;
	long long num2;

	scanf("%d %d %d %lld %lld %lld",
		&numArr1[0], &numArr1[1], &numArr1[2],
		&numArr2[0], &numArr2[1], &numArr2[2]
	);

	memcpy(numPtr, numArr1, sizeof(int) * 3);
	memcpy(ptr, numArr2, sizeof(long long) * 3);
	numArr1[0] = numArr1[1] = numArr1[2] = 0;
	numArr2[0] = numArr2[1] = numArr2[2] = 0;

	num1 = *(numPtr + 2);
	num2 = *((long long*)ptr + 1);


	printf("%d %lld\n", num1, num2);

	free(ptr);
	free(numPtr);
}

#pragma region "59.11 심사문제: 구조체 포인터로 포인터 연산하기"

struct Point3D_59_11 {
	float x;
	float y;
	float z;
};

void judge_struct_pointer_add()
{
	void* ptr = malloc(sizeof(struct Point3D_59_11) * 3);
	struct Point3D_59_11 p[3];
	float result1, result2;

	scanf("%f %f %f %f %f %f %f %f %f",
		&p[0].x, &p[0].y, &p[0].z,
		&p[1].x, &p[1].y, &p[1].z,
		&p[2].x, &p[2].y, &p[2].z
	);

	memcpy(ptr, p, sizeof(struct Point3D_59_11) * 3);
	memset(p, 0, sizeof(struct Point3D_59_11) * 3);

	result1 = (((struct Point3D_59_11*)ptr + 1)->x);
	result2 = (((struct Point3D_59_11*)ptr + 2)->z);

	printf("%.1f %.1f\n", result1, result2);

	free(ptr);

}

#pragma endregion

#pragma endregion

#pragma region "60강 함수 사용하기"

void hello_60()
{
	printf("Hello, wolrd!\n");
}

void function()
{
	hello_60();
}

#pragma region "함수 선언과 정의 구분하기"

void hello_60_2();

void main_60_2()
{
	hello_60_2();
}

void hello_60_2()
{
	printf("Hello,world!\n");
}

#pragma endregion

#pragma region "디버그 사용"

void hello_60_3()
{
	printf("Hello,world!\n");
}

void main_60_3()
{
	hello_60_3();
}

#pragma endregion

#pragma region "60.5 연습문제: 함수 호출하기"

void printName_60_5()
{
	printf("Beethoven\n");
}

void printOrdinal_60_5()
{
	printf("9th\n");
}

void main_60_5()
{
	printName_60_5();
	printOrdinal_60_5();
}

#pragma endregion

#pragma region "60.6 연습문제: 함수 정의하기"

void printHostname_60_6();
void printIPAddress_60_6();

void main_60_6()
{
	printHostname_60_6();
	printIPAddress_60_6();
}

void printHostname_60_6()
{
	printf("Saturn\n");
}

void printIPAddress_60_6()
{
	printf("192.168.10.6");
}

#pragma endregion

#pragma region "60.7 심사문제: 함수 정의하기"

void printfIPAddress_60_7()
{
	printf("192.168.10.5\n");
}

void printHostname_60_7()
{
	printf("Jupiter");
}

void main_60_7()
{
	printfIPAddress_60_7();
	printHostname_60_7();
}

#pragma endregion

#pragma region "60.8 심사문제: 함수 선언하기"

void printName_60_8();
void printOrdinal_60_8();

void main_60_8()
{
	printName_60_8();
	printOrdinal_60_8();
}

void printName_60_8()
{
	printf("Beethoven\n");
}

void printOrdinal_60_8()
{
	printf("9th Symphony\n");
}

#pragma endregion

#pragma endregion

#pragma region "61강 함수에서 반환값 사용하기"

#pragma region return_integer

int one_611_1()
{
	return 1;
}

void main_611_1()
{
	int num1;
	num1 = one_611_1();		// int형을 반환했으므로 int형 변수에 저장
	printf("%d\n", num1);
}

#pragma endregion 

#pragma region "함수에서 실수, 불값 반환"

float realNumber_6112()    // 반환값이 float형인 realNumber 함수 정의
{
	return 1.234567f;    // 1.234567: float형을 반환
}

bool truth_6112()    // 반환값이 bool형인 truth 함수 정의
{
	return true;    // true: bool형을 반환
}

void main_6112()
{
	float num1;
	bool b1;

	num1 = realNumber_6112();    // float형을 반환했으므로 float형 변수에 저장
	b1 = truth_6112();           // bool형을 반환했으므로 bool형 변수에 저장

	printf("%f\n", num1);   // 1.234567
	printf("%d\n", b1);     // 1

	return 0;
}

#pragma endregion

#pragma region "반환값의 자료형과 자료형 변환"

int one_6113()
{
	float a = 1.1f;
	return (int)a;  // a를 int로 변환하여 반환
}

void main_6113()
{
	int num1;

	num1 = one_6113(); // int형을 반환했으므로 int형 변수에 저장

	printf("%d\n", num1);
}

float onepointone_6113()
{
	return 1.1f;
}

void main_61132()
{
	int num1;

	num1 = (int)onepointone_6113();

	printf("%d\n", num1);
}

#pragma endregion

#pragma region "61.2 포인터 반환하기"

#pragma region "잘못된 방법"

int* ten_612() // 잘못된 방법
{
	int num1 = 10;   // num1은 함수 ten이 끝나면 사라짐

	return &num1;    // 함수에서 지역 변수의 주소를 반환하는 것은 잘못된 방법
} //        ↑ warning C4172: 지역 변수 또는 임시 변수의 주소를 반환하고 있습니다.


void main_612()
{
	int* numPtr;

	numPtr = ten_612();    // 함수를 호출하고 반환값을 numPtr에 저장

	printf("%d\n", *numPtr);    // 10: 값이 나오긴 하지만 이미 사라진 변수를 출력하고 있음
}

#pragma endregion

int* ten_6122()
{
	int* numPtr = malloc(sizeof(int));    // int 크기만큼 동적 메모리 할당

	*numPtr = 10;    // 역참조로 10 저장

	return numPtr;   // 포인터 반환. malloc으로 메모리를 할당하면 함수가 끝나도 사라지지 않음
}

void main_6122()
{
	int* numPtr;

	numPtr = ten_6122();    // 함수를 호출하고 반환값을 numPtr에 저장

	printf("%d\n", *numPtr);    // 10: 메모리를 해제하기 전까지 안전함

	free(numPtr);    // 다른 함수에서 할당한 메모리라도 반드시 해제해야 함

}

char* helloLiteral()
{
	char* s1 = "Hello, world!";

	return s1;
}

char* helloDynamicMemory()
{
	char* s1 = malloc(sizeof(char) * 20);

	strcpy(s1, "Hello, world!");

	return s1;
}

void main_6123()
{
	char* s1;
	char* s2;

	s1 = helloLiteral();
	s2 = helloDynamicMemory();

	printf("%s\n", s1);
	printf("%s\n", s2);

	free(s2);
}

#pragma endregion

#pragma region "61.3 void 포인터 반환하기"

void* allocMemory_6131()
{
	void* ptr = malloc(100);

	return ptr;
}

void main_613()
{
	char* s1 = allocMemory_6131();  // void 포인터를 char 포인터에 넣어서 
	strcpy(s1, "Hello, world!");
	printf("%s\n", s1);
	free(s1);

	int* numPtr1 = allocMemory_6131(); // void 포인터를 int 포인터에 넣어서
	numPtr1[0] = 10;
	numPtr1[1] = 20;
	printf("%d %d\n", numPtr1[0], numPtr1[1]);
	free(numPtr1);
}

#pragma endregion

#pragma region "61.4 구조체와 구조체 포인터 반환하기"

#pragma region case1 "메모리 할당x"

struct Person_614 {
	char name[20];
	int age;
	char address[100];
};

struct Person_614 getPerson_614() // Person 구조체를 반환하는 getPerson 함수
{
	struct Person_614 p;

	strcpy(p.name, "홍길동");
	p.age = 30;
	strcpy(p.address, "서울시 용산구 한남동");

	return p;
}

void main_614()
{
	struct Person_614 p1;
	p1 = getPerson_614();	// 반환된 구조체 변수의 내용이 p1로 모두 복사됨

	printf("이름:%s\n", p1.name);
	printf("나이:%d\n", p1.age);
	printf("주소:%s\n", p1.address);
}

#pragma endregion

#pragma region case2 "메모리 할당"

struct Person_6142 {
	char name[20];
	int age;
	char address[100];
};

struct Person_6142* allocPerson_6142()
{
	struct Person_6142* p = malloc(sizeof(struct Person_6142));

	strcpy(p->name, "홍길동");
	p->age = 30;
	strcpy(p->address, "서울시 용산구 한남동");

	return p;
}

void main_6142()
{
	struct Person_6142* p1;
	p1 = allocPerson_6142();

	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);

	free(p1);
}

#pragma endregion

#pragma endregion

#pragma region "61.6 연습문제: 게임 캐릭터 능력치 함수 만들기"

int getMana_616()
{
	return 222;
}

float getAttackSpeed_616()
{
	return 0.679;
}

bool isMelee_616()
{
	return true;
}

void main_616()
{
	int mana;
	float attackSpeed;
	bool melee;

	mana = getMana_616();
	attackSpeed = getAttackSpeed_616();
	melee = isMelee_616();

	printf("%d\n", mana);
	printf("%f\n", attackSpeed);
	printf("%d\n", melee);
}

#pragma endregion

#pragma region "61.7 연습문제: 문자열 포인터 반환하기"

char* getName_617()
{
	char* str = malloc(sizeof(char) * 20);

	strcpy(str, "Mars");

	return str;
}

void main_617()
{
	char* name;

	name = getName_617();

	printf("%s\n", name);

	free(name);
}

#pragma endregion

#pragma region "61.8 연습문제: 메모리 할당 함수 만들기"

void* allocMemory()
{
	void* ptr = malloc(sizeof(char) * 10);
	return ptr;
}

void main_618()
{
	char* s1;
	s1 = allocMemory();
	strcpy(s1, "Uranus");
	printf("%s\n", s1);
	free(s1);
}

#pragma endregion

#pragma region "61.9 연습문제: 인적 정보 함수 만들기"

struct Person_619 {
	char name[20];
	int age;
};

struct Person_619* allocPerson_619()
{
	struct Person_619* p = malloc(sizeof(struct Person_619));
	strcpy(p->name, "Kayle");
	p->age = 22;
}

void main_619()
{
	struct Person_619* p1;
	p1 = allocPerson_619();

	printf("%s\n", p1->name);
	printf("%d\n", p1->age);

	free(p1);
}

#pragma endregion

#pragma region "61.10 심사문제: 게임 캐릭터 능력치 함수 만들기"

float getArmor_6110()
{
	return 20.5;
}

bool hasSlowSkill_6110()
{
	return false;
}

void main_6110()
{
	float armor;
	bool slow;

	armor = getArmor_6110();
	slow = hasSlowSkill_6110();

	printf("%f\n", armor);
	printf("%s\n", slow == true ? "true" : "false");
}

#pragma endregion

#pragma region "61.11 심사문제: 문자열 포인터 반환하기"

struct getName_6111 {
	char name[20];
};

struct getName_6111* getName_6111()
{
	struct getName_6111* p = malloc(sizeof(struct getName_6111));
	strcpy(p->name, "Neptune");
}

void main_6111()
{
	char* name;

	name = getName_6111();

	printf("%s\n", name);

	free(name);
}

#pragma endregion

#pragma region "61.12 심사문제: 메모리 할당 함수 만들기"

void* allocMemory_6112()
{
	void* ptr = malloc(100);
	return ptr;
}

void main_6112_judge()
{
	char* name;
	float* stats;

	name = allocMemory_6112();
	strcpy(name, "Mercury");
	printf("%s\n", name);
	free(name);

	stats = allocMemory_6112();
	stats[0] = 87.969f;
	stats[1] = 115.8776f;
	printf("%f %f\n", stats[0], stats[1]);
	free(stats);
}

#pragma endregion

#pragma region "61.13 심사문제: 2차원 정보 만들기"

struct Point2D_6113 {
	int x;
	int y;
};

struct Point2D_6113* allocPoint2D_6113()
{
	struct Point2D_6113* ptr = malloc(sizeof(struct Point2D_6113));
	ptr->x = 90;
	ptr->y = 75;
}

void main_6113_judge()
{
	struct Point2D_6113* pos1;
	pos1 = allocPoint2D_6113();
	printf("%d %d\n", pos1->x, pos1->y);
	free(pos1);
}

#pragma endregion

#pragma endregion

#pragma region "62강 함수에서 매개변수 사용하기"

#pragma region "매개 변수 사용하기"

void helloNumber_621(int num1)
{
	printf("Hello, %d\n", num1);
}

void main_621()
{
	helloNumber_621(10);
	helloNumber_621(20);
}

#pragma endregion

#pragma region "덧셈 함수 만들기"

int add(int a, int b)
{
	return a + b;
}

void main_622()
{
	int num1;

	num1 = add(10, 20);

	printf("%d\n", num1);
}

#pragma endregion

#pragma region "디버거에서 매개변수와 반환값 확인하기"

int add_623(int a, int b)
{
	return a + b;
}

void main_623()
{
	int num1;

	num1 = add(10, 20);

	printf("%d\n", num1);
}

#pragma endregion

#pragma region "62.5 연습문제: 문자 매개변수 사용하기"

void printType_625(char type)
{
	printf("Type %c\n", type);
}

void main_625()
{
	printType_625('x');
}

#pragma endregion

#pragma region "62.6 연습문제: 뺄셈 함수 만들기"

float sub(float a, float b)
{
	return a - b;
}

void main_626()
{
	float num1;

	num1 = sub(1.0f, 0.1f);

	printf("%f\n", num1);
}

#pragma endregion

#pragma region "62.7 심사문제: 게임 캐릭터 능력치 설정 함수 만들기"

float setAttackSpeed_627(float a)
{
	printf("Attack Speed: %f\n", a);
}

void main_627()
{
	setAttackSpeed_627(0.638f);
	setAttackSpeed_627(1.23f);
}

#pragma endregion

#pragma region "62.8 심사문제: 덧셈 함수 만들기"

long long add_628(long long a, long long b)
{
	return a + b;
}

void main_628()
{
	long long num1, num2;

	scanf("%lld %lld", &num1, &num2);

	printf("%lld\n", add_628(num1, num2));
}

#pragma endregion

#pragma region "62.9 심사문제: 3차원 정보 만들기"

struct Point3D_629 {
	float x;
	float y;
	float z;
};

struct Point3D_629* allocPoint3D_629(float x, float y, float z)
{
	struct Point3D_629* ptr = malloc(sizeof(struct Point3D_629));
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
}

void main_629()
{
	float x, y, z;
	struct Point3D_629* pos1;

	scanf("%f %f %f", &x, &y, &z);

	pos1 = allocPoint3D_629(x, y, z);

	printf("%f %f %f\n", pos1->x, pos1->y, pos1->z);

	free(pos1);
}

#pragma endregion

#pragma endregion

#pragma region "63강 함수에서 포인터 매개변수 사용하기"

#pragma region "매개변수는 함수 바깥의 변수와는 상관x"

void swapNumber_631(int first, int second)
{
	int temp;

	temp = first;
	first = second;
	second = temp;
}

void main_631()
{
	int num1 = 10;
	int num2 = 20;

	swapNumber_631(num1, num2);

	printf("%d %d\n", num1, num2); // 처음 저장한 10과 20이 출력
	// 매개변수는 값을 전달하는 역할만 할 뿐 함수 바깥의 변수와는 상관이 없습니다.
}

#pragma endregion

#pragma region "매개변수 포인터 사용"

void swapNumber_6312(int* first, int* second) //int 포인터 매개변수 지정
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;

}

void main_6312()
{
	int num1 = 10;
	int num2 = 20;

	swapNumber_6312(&num1, &num2); // &를 사용하여 num1과 num2의 메모리 주소를 넣어줌

	printf("%d %d\n", num1, num2); // 20 10: swapNumber에 의해서 num1과 num2의 값이 서로 바뀜
}

#pragma endregion

#pragma region "63.2 void 포인터 매개변수 사용하기"

enum Type_632 {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT
};

void swapValuve_632(void* ptr1, void* ptr2, enum Type_632 t)
{
	switch (t)
	{
	case TYPE_CHAR:
	{
		char temp;
		temp = *(char*)ptr1;
		*(char*)ptr1 = *(char*)ptr2;
		*(char*)ptr2 = temp;
		break;
	}
	case TYPE_INT:
	{
		int temp;
		temp = *(int*)ptr1;
		*(int*)ptr1 = *(int*)ptr2;
		*(int*)ptr2 = temp;
		break;
	}
	case TYPE_FLOAT:
	{
		float temp;
		temp = *(float*)ptr1;
		*(float*)ptr1 = *(float*)ptr2;
		*(float*)ptr2 = temp;
		break;
	}
	}
}

void main_632()
{
	char c1 = 'a';
	char c2 = 'b';
	swapValuve_632(&c1, &c2, TYPE_CHAR);
	printf("%c %c\n", c1, c2);

	int num1 = 10;
	int num2 = 20;
	swapValuve_632(&num1, &num2, TYPE_INT);
	printf("%d %d\n", num1, num2);

	float num3 = 1.234567f;
	float num4 = 7.654321f;
	swapValuve_632(&num3, &num4, TYPE_FLOAT);
	printf("%f %f\n", num3, num4);
}

#pragma endregion

#pragma region "63.3 이중 포인터 매개변수 사용하기"

void allocMemory_633(void** ptr, int size)
{
	*ptr = malloc(size);
}

void main_633()
{
	long long* numptr;
	allocMemory_633((void**)&numptr, sizeof(long long));

	*numptr = 10;
	printf("%lld\n", *numptr);

	free(numptr);
}

#pragma endregion

#pragma region "63.4 문자열 매개변수 사용하기"

#pragma region prameter_char_pointer

void helloString_634(char* s1)
{
	printf("Hello, %s\n", s1);
}

void main_634()
{
	helloString_634("world!");
}

#pragma endregion

#pragma region parameter_char_array_argument

void helloString_6342(char* s1)
{
	printf("Hello, %s\n", s1);
}

void main_6342()
{
	char s1[10] = "world!";

	helloString_6342(s1);
}

#pragma endregion

#pragma region parameter_char_array

void helloString_6343(char s1[])
{
	printf("Hello, %s\n", s1);
}

void main_6343()
{
	char s1[10] = "world!";
	helloString_6343(s1);

	helloString_6343("world!");
}

#pragma endregion

#pragma endregion

#pragma region "63.6 연습문제: 함수에서 반환값으로 값 한 개, 매개변수로 값 두 개 꺼내기"

int getNumber_636(int* a, int* b)
{
	*a = *a + 10;
	*b = *b + 20;
	int result = *a + *b;
	return result;
}

void main_636()
{
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	result = getNumber_636(&num1, &num2);

	printf("%d %d %d\n", num1, num2, result);
}

#pragma endregion

#pragma region "63.7 연습문제: 함수에서 행렬 만들기"

void allocMatrix_637(void*** ptr, int a, int b, int size)
{
	*ptr = malloc(sizeof(void*) * a);

	for (int i = 0; i < a; i++)
	{
		(*ptr)[i] = malloc(size * b);
	}
}

void freeMatrix_637(void*** ptr, int a)
{
	for (int i = 0; i < a; i++)
	{
		free((*ptr[i]));
	}

	free(*ptr);
}

void main_637()
{
	short** matrix;
	allocMatrix_637(&matrix, 3, 3, sizeof(short));

	matrix[0][2] = 10;
	matrix[1][1] = 20;

	printf("%d %d\n", matrix[0][2], matrix[1][1]);

	freeMatrix_637(&matrix, 3);
}

#pragma endregion //??

#pragma region "63.8 연습문제: 문자열 매개변수 사용하기"

void compareString_638(char* a, char* b)
{
	if (strcmp(a, b) == 0)
		printf("같음");
	else
		printf("다름");
}

void main_638()
{
	char* s1 = malloc(sizeof(char) * 10);

	strcpy(s1, "Venus");

	compareString_638(s1, "Venus");

	free(s1);
}

#pragma endregion

#pragma region "63.9 심사문제: 몫과 나머지를 구하는 함수 만들기"

int getQuotientAndRemainder_639(int num1, int num2, int* remainder)
{
	int a = (num1 / num2);

	*remainder = num1 % num2;

	return a;
}

void main_639()
{
	int num1;
	int num2;
	int quotient;
	int remainder;

	scanf("%d %d", &num1, &num2);
	quotient = getQuotientAndRemainder_639(num1, num2, &remainder);

	printf("%d %d", quotient, remainder);
}

#pragma endregion

#pragma region "63.10 심사문제: 함수에서 메모리를 할당하여 배열 만들기"

allocArray_6310(void** ptr, int a, int size)
{
	*ptr = malloc(size * a);
}

int main_6310()
{
	long long* numArr1;
	int* numArr2;

	allocArray_6310((void**)&numArr1, 10, sizeof(long long));
	allocArray_6310((void**)&numArr2, 3, sizeof(int));

	scanf("%lld %d", &numArr1[9], &numArr2[2]);
	printf("%lld %d\n", numArr1[9], numArr2[2]);

	free(numArr2);
	free(numArr1);

	return 0;
}

#pragma endregion

#pragma region "63.11 심사문제: 문자열 매개변수 사용하기"

void printFullName_6311(char* family, char* given)
{
	printf("%s %s", family, given);
}

void main_6311()
{
	char familyName[31];
	char givenName[31];

	scanf("%s %s", familyName, givenName);

	printFullName_6311(familyName, givenName);
}

#pragma endregion

#pragma endregion

#pragma region "64강 함수에서 배열 매개변수 사용하기"

#pragma region "64.1 배열 매개변수 사용하기"

#pragma region parameter_array

void printArray(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void main_6410()
{
	int numArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printArray(numArr, sizeof(numArr) / sizeof(int));
}

#pragma endregion

#pragma region parameter_array_set_element

void setElement_6411(int arr[])
{
	arr[2] = 300;
}

void main_6411()
{
	int numArr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	setElement_6411(numArr);

	printf("%d\n", numArr[2]);

	// 배열의 메모리 주소를 전달했기 때문에 실제로는 바깥에 있는 배열의 요소가 바뀌었습니다.
}

#pragma endregion
// 매개변수를 arr[]과 같이 지정했다면 arr은 포인터입니다.
// 배열의 메모리 주소를 전달했기 때문에 실제로는 바깥에 있는 배열의 요소가 바뀌었습니다.

#pragma region parameter_pointer "대괄호 대신 포인터"

void printArray_6412(int* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void main_6412()
{
	int numArr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printArray_6412(numArr, sizeof(numArr) / sizeof(int));

}

#pragma endregion

#pragma region "배열에서 특정 요소의 값을 서로 바꾸기"

void swapElemnet_6413(int arr[], int first, int second)
{
	int temp;

	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void main_6413()
{
	int numArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	swapElemnet_6413(numArr, 0, 1);
	printf("%d %d\n", numArr[0], numArr[1]);
}

#pragma endregion

#pragma region "복합 리터럴 사용하여 배열을 따로 선언하지 않기"

void printArray_6414(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void main_6414()
{
	printArray_6414((int[]) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
}

#pragma endregion

//#pragma region "함수의 배열 매개변수에서 요소의 최소 개수 지정하기(static)"
//// vs2015에서는 사용할 수 없으며 gcc, clang에서만 지원
//
//void printarray_6415(int arr[static 5], int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void main_6415()
//{
//	int numArr1[5] = { 1, 2, 3, 4, 5 };
//
//	// 요소 개수가 5개이므로 OK
//	printArray(numArr1, sizeof(numArr1) / sizeof(int));
//
//	int numArr2[3] = { 1, 2, 3 };
//
//	// 요소 개수가 3개이므로 경고
//	printArray(numArr2, sizeof(numArr1) / sizeof(int));
//}
//
//#pragma endregion
//
//#pragma endregion
//

#pragma endregion

#pragma region "64.2 2차원 배열 매개변수 사용하기"

#pragma region"배열 써서"

void print2DArray_6421(int arr[][5], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void main_6421()
{
	int numArr[2][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10}
	};

	int col = sizeof(numArr[0]) / sizeof(int);
	int row = sizeof(numArr) / sizeof(numArr[0]);

	print2DArray_6421(numArr, col, row);
}

#pragma endregion

#pragma region "포인터 써서"

void print2DArray_6422(int(*arr)[5], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void main_6422()
{
	int numArr[2][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10}
	};

	int col = sizeof(numArr[0]) / sizeof(int);
	int row = sizeof(numArr) / sizeof(numArr[0]);

	print2DArray_6422(numArr, col, row);

}

#pragma endregion

#pragma region "복합 리터럴 써서"

void print2DArray_6423(int(*arr)[5], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void main_6423()
{
	print2DArray_6423((int[2][5]) { {1, 2, 3, 4, 5}, { 6,7,8,9,10 } }, 5, 2);
}

#pragma endregion

#pragma endregion

#pragma region "64.6 심사문제: 배열 매개변수 사용하기"

void printReverse_judge6461(int arr[10], int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		printf("%d\n", arr[i]);
	}
}

void main_judge6461()
{
	int numArr[10];

	scanf("%d %d %d %d %d %d %d %d %d %d",
		&numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4],
		&numArr[5], &numArr[6], &numArr[7], &numArr[8], &numArr[9]
	);

	printReverse_judge6461(numArr, sizeof(numArr) / sizeof(int));
}

#pragma endregion

#pragma region "64.7 심사문제: 전치행렬 만들기"

void transpose647(int matrix[][4], int size)
{
	int trans[4][4] = { 0, };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			trans[j][i] = matrix[i][j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = trans[i][j];
		}
	}
}

void main_judge647()
{
	int matrix[4][4];

	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		&matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3],
		&matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3],
		&matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3],
		&matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3]
	);

	int n = sizeof(matrix[0]) / sizeof(int);

	transpose647(matrix, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)

		{
			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}
}

#pragma endregion

#pragma endregion

#pragma region "65강 함수에서 구조체 매개변수 사용하기"

#pragma region "65.1 구조체 매개변수 사용하기"

#pragma region parameter_struct

struct Person_651 {
	char name[20];
	int age;
	char address[100];
};

void printPerson_651(struct Person_651 p)
{
	// 구조체 매개변수 멤버의 값 출력
	printf("이름: %s\n", p.name);       // 이름: 홍길동
	printf("나이: %d\n", p.age);        // 나이: 30
	printf("주소: %s\n", p.address);    // 주소: 서울시 용산구 한남동
}

void main_651()
{
	struct Person_651 p1;

	strcpy(p1.name, "왕귤");
	p1.age = 30;
	strcpy(p1.address, "구로");

	printPerson_651(p1);
}

#pragma endregion

#pragma region compound_literal_struct

struct Person_6512 {
	char name[20];
	int age;
	char address[100];
};

void printPerson_6512(struct Person_6512 p)
{
	printf("이름: %s\n", p.name);
	printf("나이: %d\n", p.age);
	printf("주소: %s\n", p.address);
}

void main_6512()
{
	printPerson_6512((struct Person_6512) { .name = "홍길동", .age = 30, .address = "구로" });
}

#pragma endregion

#pragma region "매개변수로 받은 구조체 멤버의 값을 변경해도 함수 바깥에 영향x"

struct Person_6513 {
	char name[20];
	int age;
	char address[100];
};

void setPerson_6513(struct Person_6513 p)    // 반환값 없음, 구조체 매개변수 한 개 지정
{
	// 매개변수로 받은 구조체 멤버의 값 변경
	strcpy(p.name, "고길동");
	p.age = 40;
	strcpy(p.address, "서울시 서초구 반포동");
}

void main_6513()
{
	struct Person_6513 p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	setPerson_6513(p1);    // 함수를 호출할 때 구조체 변수 전달, 멤버가 복사됨

	// setPerson에서 변경한 값은 영향을 미치지 않음
	printf("이름: %s\n", p1.name);       // 이름: 홍길동
	printf("나이: %d\n", p1.age);        // 나이: 30
	printf("주소: %s\n", p1.address);    // 주소: 서울시 용산구 한남동

}

#pragma endregion

#pragma endregion

#pragma region "65.2 구조체 포인터 매개변수 사용하기"

struct Person6521 {
	char name[20];
	int age;
	char address[100];
};

void setPerson6521(struct Person6521* p)    // 반환값 없음, 구조체 포인터 매개변수 한 개 지정
{
	// 매개변수로 받은 포인터에서 구조체 멤버의 값 변경
	strcpy(p->name, "고길동");
	p->age = 40;
	strcpy(p->address, "서울시 서초구 반포동");
}

void main6521()
{
	struct Person6521 p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	setPerson6521(&p1);    // 함수를 호출할 때 구조체 변수의 메모리 주소를 전달

	// setPerson에서 변경한 값이 출력됨
	printf("이름: %s\n", p1.name);       // 이름: 고길동
	printf("나이: %d\n", p1.age);        // 나이: 40
	printf("주소: %s\n", p1.address);    // 주소: 서울시 서초구 반포동
}

#pragma endregion

#pragma region "복합 리터럴 사용하기"

struct Person_6522 {
	char name[20];
	int age;
	char address[100];
};

void printPerson_6522(struct Person_6522* p)
{
	printf("이름: %s\n", p->name);
	printf("나이: %d\n", p->age);
	printf("주소: %s\n", p->address);
}

void main_6522()
{
	// 복합 리터럴 방식으로 구조체를 넘겨줌
	printPerson_6522(&(struct Person_6522) { .name = "홍길동", .age = 30, .address = "서울시 용산구 한남동" });

	// 복합 리터럴 방식으로 구조체를 넘겨줌. 멤버 이름 생략
	printPerson_6522(&(struct Person_6522) { "고길동", 40, "서울시 서초구 반포동" });
}

#pragma endregion

#pragma region "구조체 별칭 사용하기"

typedef struct Person_6523 {
	char name[20];
	int age;
	char address[100];
}Person, * PPerson_6523;

void setPerson_6523(PPerson_6523 p)
{
	strcpy(p->name, "고길동");
	p->age = 40;
	strcpy(p->address, "서울시 서초구 반포동");
}

#pragma endregion

#pragma region "공용체와 열거형을 매개변수로 사용하기"

union Box_6524 {
	short candy;
	float snack;
	char doll[8];
};

enum BOX_TYPE_6524 {
	BOX_PAPER = 0,
	BOX_WOOD,
	BOX_PLASTIC
};

void printBox_6524(union Box_6524 BOX_6524)
{
	printf("%d\n", BOX_6524.candy);
}

void printBoxType_6524(enum BOX_TYPE_6524 boxtype_6524)
{
	printf("%d\n", boxtype_6524);
}

void main_6524()
{
	union Box_6524 box;
	enum BOX_TYPE_6524 boxType;

	box.candy = 10;
	boxType = BOX_PLASTIC;

	printBox_6524(box);
	printBoxType_6524(boxType);
}

#pragma endregion

#pragma region "65.5 연습문제: 좌표 설정 함수 만들기"

struct Point2D_6551 {
	int x;
	int y;
};

void setPoint2D_6551(struct Point2D_6551* p, int a, int b)
{
	p->x = a;
	p->y = b;
}

void main_6551()
{
	struct Point2D_6551* p1 = malloc(sizeof(struct Point2D_6551));

	setPoint2D_6551(p1, 10, 20);

	printf("%d %d\n", p1->x, p1->y);

	free(p1);
}

#pragma endregion

#pragma region "65.6 심사문제: 두 점 사이의 거리를 구하는 함수 만들기"

struct Point2D_6561 {
	int x;
	int y;
};

double getDistance_6561(struct Point2D_6561 p1, struct Point2D_6561 p2)
{
	int a = p2.x - p1.y;
	int b = p2.y - p1.y;

	double c = sqrt(pow(a, 2) + pow(b, 2));

	return c;
}

void main_6561()
{
	struct Point2D_6561 p1;
	struct Point2D_6561 p2;

	scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);

	printf("%f\n", getDistance_6561(p1, p2));
}

#pragma endregion

#pragma region "65.7 심사문제: 좌표를 이동시키는 함수 만들기"

struct Point2D_6571 {
	int x;
	int y;
};

void movePoint2D_6571(struct Point2D_6571* p, int a, int b)
{
	p->x = (p->x) + a;
	p->y = (p->y) + b;
}

void main_6571()
{
	struct Point2D_6571 p1;
	int offsetX, offsetY;

	scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

	movePoint2D_6571(&p1, offsetX, offsetY);

	printf("%d %d\n", p1.x, p1.y);
}

#pragma endregion

#pragma endregion

#pragma region "66강 함수에서 가변 인자 사용하기"

#pragma region "66.1 가변 인자 함수 만들기"

void printNumbers_6611(int args, ...)
{
	printf("%d ", args);
}

void main_6611()
{
	printNumbers_6611(1, 10);              // 1
	printNumbers_6611(2, 10, 20);		   // 2
	printNumbers_6611(3, 10, 20, 30);	   // 3
	printNumbers_6611(4, 10, 20, 30, 40);  // 4
}

void printNumber_6612(int args, ...)
{
	va_list ap;    // 가변 인자 목록 포인터

	va_start(ap, args);    // 가변 인자 목록 포인터 설정
	for (int i = 0; i < args; i++)    // 가변 인자 개수만큼 반복
	{
		int num = va_arg(ap, int);    // int 크기만큼 가변 인자 목록 포인터에서 값을 가져옴
									  // ap를 int 크기만큼 순방향으로 이동
		printf("%d ", num);           // 가변 인자 값 출력
	}
	va_end(ap);    // 가변 인자 목록 포인터를 NULL로 초기화

	printf("\n");    // 줄바꿈
}

void main_6612()
{
	printNumber_6612(1, 10);                // 인수 개수 1개
	printNumber_6612(2, 10, 20);            // 인수 개수 2개
	printNumber_6612(3, 10, 20, 30);        // 인수 개수 3개
	printNumber_6612(4, 10, 20, 30, 40);    // 인수 개수 4개
}

#pragma endregion

#pragma region "66.2 자료형이 다른 가변 인자 함수 만들기"

void printValues_6621(char* types, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, types);

	while (types[i] != '\0')
	{
		switch (types[i])
		{
		case 'i':
			printf("%d ", va_arg(ap, int));

			break;

		case 'd':
			printf("%f ", va_arg(ap, double));

			break;

		case 'c':
			printf("%c ", va_arg(ap, char));

			break;

		case 's':
			printf("%s ", va_arg(ap, char*));

			break;

		default:
			break;
		}
		i++;
	}
	va_end(ap);

	printf("\n");
}

void main_6621()
{
	printValues_6621("i", 10);
	printValues_6621("ci", 'a', 10);
	printValues_6621("dci", 1.234567, 'a', 10);
	printValues_6621("sicd", "Hello, world!", 10, 'a', 1.234567);
}

#pragma endregion

#pragma region "66.5 연습문제: 자료형이 다른 가변 인자의 합 구하기"

long long getsum_6651(char* types, ...)
{
	va_list ap;
	int i = 0;
	long long result = 0;

	va_start(ap, types);
	while (types[i] != '\0')
	{
		switch (types[i])
		{
		case 's':
			result += atoi(va_arg(ap, char*));
			break;
		case 'i':
			result += va_arg(ap, int);
			break;
		default:
			break;
		}
		i++;
	}
	va_end(ap);

	return result;
}

void main_6651()
{
	printf("%lld\n", getsum_6651("siis", "12", 30000, 500000, "300"));
	printf("%lld\n", getsum_6651("ssi", "150", "150", 100));
}

#pragma endregion

#pragma region "66.6 심사문제: 가변 인자의 합 구하기"

int sum_6661(int args, ...)
{
	int result = 0;

	va_list ap;

	va_start(ap, args);

	for (int i = 0; i < args; i++)
	{
		result += va_arg(ap, int);
	}

	va_end(ap);

	return result;
}

void main_6661()
{
	int num1, num2;
	int num3, num4, num5;

	scanf("%d %d", &num1, &num2);
	scanf("%d %d %d", &num3, &num4, &num5);

	printf("%d\n", sum_6661(2, num1, num2));
	printf("%d\n", sum_6661(3, num3, num4, num5));

	return 0;
}

#pragma endregion

#pragma region "66.7 심사문제: 가변 인자의 정수 합 구하기"

int getSum_6671(char* types, ...)
{
	va_list ap;
	int i = 0;
	int result = 0;

	va_start(ap, types);

	while (types[i] != '\0')
	{
		switch (types[i])
		{
		case 'i':
			result += va_arg(ap, int);
			break;

		case 'd':
			va_arg(ap, double);    // va_arg를 해야 다음으로 넘어감
			break;

		case 's':
			va_arg(ap, char*);
			break;

		default:
			break;
		}
		i++;
	}
	va_end(ap);
	return result;
}

void main_6671()
{
	int num1, num2, num3;

	scanf("%d %d %d", &num1, &num2, &num3);

	printf("%d\n", getSum_6671("isi", num1, "C", 10));
	printf("%d\n", getSum_6671("sdsi", "Hello, world!", 5.3, "A", num2));
	printf("%d\n", getSum_6671("iiss", 25, 38, "k", "R"));
	printf("%d\n", getSum_6671("sidii", "Hello, C", num3, 2.234567, 878, 1291));
}

#pragma endregion

#pragma endregion

#pragma region "67강 함수에서 재귀호출 사용하기"

#pragma region "67.1 재귀호출 사용하기"

//#pragma region recursive_function_error
//
//	void hello_6711()
//	{
//		printf("Hello, world!\n");
//
//		hello_6711();
//	}
//
//	void main_6711()
//	{
//		hello_6711();
//	}
//
//#pragma endregion

#pragma region recursive_function_exit_condition

void hello_6712(int count)
{
	if (count == 0)
	{
		return;
	}

	printf("Hello, world! %d\n", count);

	hello_6712(--count);
}

void main_6712()
{
	hello_6712(5);
}

#pragma endregion

#pragma endregion

#pragma region "67.2 재귀호출로 팩토리얼 구하기"

int factorial_6721(int n)
{
	if (n == 1)
		return 1;

	return n * factorial_6721(n - 1);
}

void main_6721()
{
	printf("%d", factorial_6721(6));
}

#pragma endregion

#pragma region "67.5 연습문제: 재귀호출로 1부터 100까지의 합 구하기"

int sum_6751(int n)
{
	if (n == 1)
		return 1;

	return n + sum_6751(n - 1);
}

void main_6751()
{
	printf("%d", sum_6751(100));
}

#pragma endregion

#pragma region "67.6 심사문제: 재귀호출로 피보나치 수 구하기"

int fib_6761(int n)
{
	if (n <= 1)
		return n;

	return fib_6761(n - 2) + fib_6761(n - 1);
}


void main_6761()
{
	int num1;

	scanf("%d", &num1);

	printf("%d\n", fib_6761(num1));
}

#pragma endregion

#pragma region "67.7 심사문제 : 재귀호출로 1부터 n까지 합 구하기"

int sum_6771(int n)
{
	if (n == 1)
		return 1;

	return n + sum_6771(n - 1);
}

void main_6771()
{
	int n = 0;

	scanf("%d", &n);

	printf("%d\n", sum_6771(n));

}

#pragma endregion

#pragma endregion

#pragma region "68강 함수 포인터 사용하기"

#pragma region "68.1 함수 포인터 만들기"

void hello_6811()
{
	printf("Hello, world!\n");
}

void bonjour_6811()
{
	printf("bonjour le monde!\n");
}

void main_6811()
{
	void (*fp)();   // 반환값과 매개변수가 없는 함수 포인터 fp 선언

	fp = hello_6811;     // hello 함수의 메모리 주소를 함수 포인터 fp에 저장
	fp();           // Hello, world!: 함수 포인터로 hello 함수 호출

	fp = bonjour_6811;   // bonjour 함수의 메모리 주소를 함수 포인터 fp에 저장
	fp();           // bonjour le monde!: 함수 포인터로 bonjour 함수 호출
}

#pragma endregion

#pragma region "68.2 반환값과 매개변수가 있는 함수 포인터 만들기"

int add_6821(int a, int b)
{
	return a + b;
}

int mul_6821(int a, int b)
{
	return a * b;
}

void main_6821()
{
	int(*fp)(int, int);

	fp = add_6821;
	printf("%d\n", fp(10, 20));

	fp = mul_6821;
	printf("%d\n", fp(10, 20));
}

#pragma endregion

#pragma region "68.4 연습문제: 함수 포인터 만들기"

void hello_6841()
{
	printf("Hello, ");
}

void numberToString_6841(int n, char* buffer)
{
	sprintf(buffer, "%d", n);
}

void main_6841()
{
	char(*fp1)();
	int(*fp2)();

	char buffer[20];

	fp1 = hello_6841;
	fp2 = numberToString_6841;

	fp1();
	fp2(100, buffer);
	printf("%s\n", buffer);
}

#pragma endregion

#pragma region "68.5 심사문제: 반환값과 매개변수가 있는 함수 포인터 만들기"

int add_685(int* a, int* b)
{
	return *a + *b;
}

int sub_685(int* a, int* b)
{
	return *a - *b;
}

int mul_685(int* a, int* b)
{
	return *a * *b;
}

int div_685(int* a, int* b)
{
	return *a / *b;
}

void main_685()
{
	char funcName[10];
	int num1, num2;

	scanf("%s %d %d", funcName, &num1, &num2);

	int (*fp)(int*, int*);

	fp = NULL;

	if (strcmp(funcName, "add_685") == 0)
	{
		fp = add_685;
	}

	else if (strcmp(funcName, "sub_685") == 0)
	{
		fp = sub_685;
	}

	else if (strcmp(funcName, "mul_685") == 0)
	{
		fp = mul_685;
	}

	else if (strcmp(funcName, "div_685") == 0)
	{
		fp = div_685;
	}

	printf("%d\n", fp(&num1, &num2));
}

#pragma endregion

#pragma endregion

#pragma region "69강 함수 포인터 활용하기"

#pragma region "69.1 함수 포인터 배열 사용하기"

#pragma region "switch 이용"

int add_6911(int a, int b)
{
	return a + b;
}

int sub_6911(int a, int b)
{
	return a - b;
}

int mul_6911(int a, int b)
{
	return a * b;
}

int div_6911(int a, int b)
{
	return a / b;
}

void main_6911()
{
	int funcNumber;
	int num1, num2;
	int(*fp)(int, int) = NULL;

	printf("함수번호와 계산할 값을 입력하세요\n");
	scanf("%d %d %d", &funcNumber, &num1, &num2);

	switch (funcNumber)
	{
	case 0:
		fp = add_6911;
		break;
	case 1:
		fp = sub_6911;
		break;
	case 2:
		fp = mul_6911;
		break;
	case 3:
		fp = div_6911;
		break;
	}

	printf("%d\n", fp(num1, num2));
}

#pragma endregion

#pragma region "함수 포인터 배열"

int add_6912(int a, int b)
{
	return a + b;
}

int sub_6912(int a, int b)
{
	return a - b;
}

int mul_6912(int a, int b)
{
	return a * b;
}

int div_6912(int a, int b)
{
	return a / b;
}

void main_6912()
{
	int funcNumber;
	int num1, num2;
	int(*fp[4])(int, int);

	fp[0] = add_6912;
	fp[1] = sub_6912;
	fp[2] = mul_6912;
	fp[3] = div_6912;

	printf("함수번호와 계산할 값을 입력하세요\n");
	scanf("%d %d %d", &funcNumber, &num1, &num2);

	printf("%d\n", fp[funcNumber](num1, num2));
}

#pragma endregion

#pragma endregion

#pragma region "69.2 함수 포인터를 구조체 멤버로 사용하기"




int main()
{
	main_6911();

	return 0;
}

