#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Lesson_1.h"
#include <stdarg.h>

#pragma region "���� �и� ����"

void test_swap()
{
	int a = 1;
	int b = 2;

	swap(&a, &b);

	printf("%d", b);
}

#pragma endregion

#pragma region "���� ������"

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

	int col = sizeof(numArr[0]) / sizeof(int);   //���� ��
	int row = sizeof(numArr) / sizeof(numArr[0]); //���� ��

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

	int col = sizeof(numArr[0]) / sizeof(int);   //���� ��
	int row = sizeof(numArr) / sizeof(numArr[0]); //���� ��

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
	int numArr[3][4] = {    // ���� 3, ���� 4 ũ���� int�� 2���� �迭 ����
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
	printf("%d\n", sizeof(int) * 10); //4����Ʈ = 32��Ʈ
	printf("%d\n", sizeof(*numptr)); //4����Ʈ = 32��Ʈ


	numptr[0] = 20;    //0001 0100 8��Ʈ
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
	int** m = malloc(sizeof(int*) * 3);   // ���� �����Ϳ� (int ������ ũ�� * ���� ũ��)��ŭ
										   // ���� �޸� �Ҵ�. �迭�� ����

	for (int i = 0; i < 3; i++)            // ���� ũ�⸸ŭ �ݺ�
	{
		m[i] = malloc(sizeof(int) * 4);    // (int ũ�� * ���� ũ��)��ŭ ���� �޸� �Ҵ�.
										   // �迭�� ����
	}

	m[0][0] = 1;    // ���� �ε��� 0, ���� �ε��� 0�� ��ҿ� �� �Ҵ�
	m[2][0] = 5;    // ���� �ε��� 2, ���� �ε��� 0�� ��ҿ� �� �Ҵ�
	m[2][3] = 2;    // ���� �ε��� 2, ���� �ε��� 3�� ��ҿ� �� �Ҵ�

	printf("%d\n", m[0][0]);    // 1: ���� �ε��� 0, ���� �ε��� 0�� ����� �� ���
	printf("%d\n", m[2][0]);    // 5: ���� �ε��� 2, ���� �ε��� 0�� ����� �� ���
	printf("%d\n", m[2][3]);    // 2: ���� �ε��� 2, ���� �ε��� 3�� ����� �� ���

	for (int i = 0; i < 3; i++)    // ���� ũ�⸸ŭ �ݺ�
	{
		free(m[i]);                // 2���� �迭�� ���� ���� �޸� ����
	}

	free(m);    // 2���� �迭�� ���� ���� �޸� ����

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

#pragma region "39�� ������ �ٽú���"

void test_str()                             // �ٽ� ����
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
	int m;	//int m ���� (����)
	int n; // int n ���� (����)
	int count = 0;

	scanf("%d %d", &m, &n);	//�Է¹޾Ƽ� ����,���� ũ�� �Է�


	char** matrix = malloc(sizeof(char) * m); //2�������ͼ���=1�������� char*����ũ�� 

	for (char i = 0; i < m; i++)	// �����ٸ�ŭ �ݺ�
	{
		matrix[i] = malloc(sizeof(char) * (n + 1));	// ������ �ϳ��� �޸� �Ҵ�
	}

	for (char i = 0; i < m; i++) // ������ ��ŭ �ݺ�
	{
		scanf("%s", matrix[i]); // ������ �ϳ��� �Է¹��� �� �Է�
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

#pragma region "39�� ���ڿ� ����ϱ�"
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


	printf("%s\n", s1);    // Hello: %s�� ���ڿ� ���
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

#pragma region "40�� �Է� ���� ���ڿ��� �����ϱ�"

void scanf_string_array()
{
	char s1[10];

	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%s", s1);

	printf("%s\n", s1);
}

void scanf_string_with_space()
{
	char s1[30];

	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%[^\n]s", s1);    // ������� �����Ͽ� ���ڿ� �Է¹ޱ�

	printf("%s\n", s1);
}

void scanf_string_pointer_memory()
{
	char* s1 = malloc(sizeof(char) * 10);  // ���ڿ� �����Ϳ� �����Ϸ��� �޸� �Ҵ� �ʼ�

	printf("���ڿ� �Է��ϼ���: ");
	scanf("%s", s1);

	printf("%s\n", s1);

	free(s1);
}

void scanf_two_string_array()
{
	char s1[10];
	char s2[20];

	printf("���ڿ��� 2�� �Է��ϼ���: ");
	scanf("%s %s", s1, s2);

	printf("%s\n", s1);
	printf("%s\n", s2);
}

void practice_scanf_string_pointer_memory()
{
	char* s1 = malloc(sizeof(char) * 10);
	printf("���� �Է�: ");
	scanf("%s", s1);

	printf("%s", s1);

	free(s1);
}

void practice_scanf_three_string_pointer_memory()
{
	char* s1 = malloc(sizeof(char) * 10);
	char* s2 = malloc(sizeof(char) * 10);
	char* s3 = malloc(sizeof(char) * 10);

	printf("���ڿ��� �� �� �Է��ϼ���: ");
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

#pragma region "41�� ���ڿ� ���� ���ϰ� ���ϱ�"

void string_length()
{
	char* s1 = "hello";
	char* s2 = "hello";

	printf("%d\n", strlen(s1));
	printf("%d\n", strlen(s2));

}

void string_compare_abc()
{
	// aaa�� ASCII �ڵ�� 97 97 97
	// aab�� ASCII �ڵ�� 97 97 98
	// aac�� ASCII �ڵ�� 97 97 99


	printf("%d\n", strcmp("aaa", "aaa"));
	printf("%d\n", strcmp("aab", "aaa"));
	printf("%d\n", strcmp("aab", "aac"));
}

void string_scanf_compare()
{
	char s1[20];
	char s2[20];

	printf("���ڿ� �� ���� �Է��ϼ���: ");
	scanf("%s %s", s1, s2);

	int ret = strcmp(s1, s2);

	switch (ret)
	{
	case 0:
		printf("�� ���ڿ��� ����\n");
		break;

	case 1:
		printf("%s���� %s�� ŭ\n", s2, s1);
		break;

	case -1:
		printf("%s���� %s�� ŭ\n", s1, s2);
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

#pragma region "42�� ���ڿ� �����ϰ� ���̱�"

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

#pragma region "43�� ���ڿ� �����"

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

	printf("1~7���� ���ڿ� 30������ ���ڸ� �Է��ϼ���: ");
	scanf("%d %s", &number, name);

	if (number == 1)
		ordinal = "th";
	else
		ordinal = "nd";

	sprintf(result, "%d%s %s", number, ordinal, name);
	printf("%s\n", result);

}

#pragma endregion

#pragma region "44�� ���ڿ� �˻��ϱ�"

void string_find_character()
{
	char s1[30] = "A Garden Diary";  // ũ�Ⱑ 30�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�

	char* ptr = strchr(s1, 'a');     // 'a'�� �����ϴ� ���ڿ� �˻�, ������ ��ȯ

	while (ptr != NULL)              // �˻��� ���ڿ��� ���� ������ �ݺ�
	{
		printf("%s\n", ptr);         // �˻��� ���ڿ� ���
		ptr = strchr(ptr + 1, 'a');  // �����Ϳ� 1�� ���Ͽ� a �������� �˻�
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

#pragma region "44�� ����"

/**
 * ����
 * 5���� ���ڿ��� �Է¹޾� ������ ������ ����Ͻÿ�.
 * �Է�
 * Dickens begins his novel, A Tale of Two Cities, in 1770, by describing the release of Doctor Manette from Bastille, before taking the story to 1793 and early 1794. In this time span, the narrative covers a broad story.
 * In a larger view, this novel begins in 1757, while its final scene looks forward to the situation of the post-revolutionary Paris.
 * This story has a historical context, which Dickens has organized around various events that occurred during the French Revolution.
 * He has drawn historical features from major events, including the fall of Bastille, the September Massacres, and the Reign of Terror.
 * This backdrop is the story��s context.
 *
 * ���
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

	printf("���� 5�� �Է��ϼ���\n");

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
* ����1. �Ʒ��� TYPE�� �˸°� �����Ͻÿ�.
* ����2. ������ ������ ����ϴ� �κп� ������ �ϼ��Ͻÿ�.
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

#pragma region "45�� ���ڿ� �ڸ���"

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
	char* SourceStr = "The Little Prince";	//������ �б� �����̶� �ȵ�, ���� �޸� �ʿ�
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

#pragma region "46�� ���ڿ��� ���ڸ� ���� ��ȯ�ϱ�"

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

#pragma region "47�� ȸ�� �Ǻ��� N-gram �����"

void palindrome()
{
	char word[30];
	int length;
	bool isPalindrome = true;

	printf("�ܾ �Է¹ٶ�\n");
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

	printf("������ �Է��ϼ���\n ");
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

	printf("���ڿ� �Է¹ٶ�\n");
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

	printf("30������ ���� ���ڿ��� �Է��ϼ���\n");
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

	printf("������ 10������ ���ڿ��� �Է��ϼ���\n");
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

#pragma region "48�� ����ü ����ϱ�"

#pragma region struct
struct person {
	char name[20];
	int age;
	char address[100];
} p1;

void struct_use()
{
	struct person p1;

	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "����� ��걸 �ѳ���");

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);
}

void struct_variable()
{
	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "����� ��걸 �ѳ���");

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);
}

void struct_init()
{
	struct person p1 = { .name = "ȫ�浿", .age = 30, .address = "����� ��걸 �ѳ���" };

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);

	struct person p2 = { "��浿", 40, "��" };

	printf("�̸�: %s\n", p2.name);
	printf("����: %d\n", p2.age);
	printf("�ּ�: %s\n", p2.address);
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

	strcpy(pp1.name, "�ձ��");
	pp1.age = 30;
	strcpy(pp1.address, "����");

	printf("�̸�: %s\n", pp1.name);
	printf("����: %d\n", pp1.age);
	printf("�ּ�: %s\n", pp1.address);
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

	strcpy(ppp1.name, "�ձ�");
	ppp1.age = 30;
	strcpy(ppp1.address, "����");

	printf("�̸�: %s\n", ppp1.name);
	printf("����: %d\n", ppp1.age);
	printf("�ּ�: %s\n", ppp1.address);
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
	printf("Engine temp: %d��\n", d1.engineTemp);
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
	printf("Engine temp: %d��\n", d1.engineTemp);
	printf("RPM: %d\n", d1.rpm);
}

#pragma endregion

#pragma endregion

#pragma region "49�� ����ü ������ ����ϱ�"

#pragma region struct_alloc_memory

struct Personn {
	char name[20];
	int age;
	char address[100];
};

void alloc_memory_struct()
{
	struct Personn* p1 = malloc(sizeof(struct Personn));

	strcpy(p1->name, "Ȳ��");
	p1->age = 30;
	strcpy(p1->address, "����");

	printf("�̸�: %s\n", p1->name);
	printf("����: %d\n", p1->age);
	printf("�ּ�: %s\n", p1->address);

	free(p1);
}

#pragma endregion

#pragma region "������ ��Ʈ��Ʈ ������" struct_member_dereference

struct Data {
	char c1;
	int* numptr;
};

void struct_member_dereference()
{
	int num1 = 10;			// num1 int�� ���� �����ϰ� 10 �Ҵ�
	struct Data d1;         //struct ���� d1���� ����
	struct Data* d2 = malloc(sizeof(struct Data));    // struct ���� ������ d2�� �����ϰ� �޸� �Ҵ�

	d1.numptr = &num1;       // Data struct�� d1���� ȣ���ؼ� num1�� ���� numptr�������� ���� �Ҵ�
	d2->numptr = &num1;		// Data struct�� ������d2�� ȣ���ؼ� num1�� ���� numptr�������� ���� �Ҵ�

	printf("%d\n", *d1.numptr);	//d1���� ȣ���ؼ� numptr�� ���
	printf("%d\n", *d2->numptr); //d2�����ͷ� ȣ���ؼ� numptr�� ����Ű�� ��(int num1) ���

	d2->c1 = 'a';		// ������d2�� ȣ���ؼ� c1�� a �Ҵ�
	printf("%c\n", (*d2).c1);	//������ d2 ȣ���ؼ� c1���
	printf("%d\n", *(*d2).numptr);		//������d2�� ������ numptr���?
	printf("%d\n", *(d2->numptr));		//(������d2�� ȣ�� numptr�� ����Ű�� �� = num1)�� 

	free(d2); // �޸� ����
}

#pragma endregion

#pragma region "����ü ��Ī"

typedef struct _persoon {
	char name[20];
	int age;
	char address[100];
}persoon;

void struct_typedef_alloc_memory()
{
	persoon* p1 = malloc(sizeof(persoon));

	strcpy(p1->name, "Ȳ�ֱ�");
	p1->age = 30;
	strcpy(p1->address, "����");

	printf("�̸�: %s\n", p1->name);
	printf("����: %d\n", p1->age);
	printf("�ּ�: %s\n", p1->address);

	free(p1);
}

#pragma endregion

#pragma region "malloc���� ����ü ������ ����: &���"

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

	printf("����: %d\n", p1.age);      // ����: 30: ����ü ������ ��� �� ���
	printf("����: %d\n", ptr->age);    // ����: 30: ����ü �������� ��� �� ���
}

#pragma endregion

#pragma region "�������� �л�����"

struct Student_practice {
	char name[20];
	int grade;
	int class;
	float average;
};

void practice_student()
{
	struct Student_practice* S1 = malloc(sizeof(struct Student_practice));

	strcpy(S1->name, "��浿");
	S1->grade = 1;
	S1->class = 3;
	S1->average = 65.389999f;

	printf("�̸�: %s\n", S1->name);
	printf("�г�: %d\n", S1->grade);
	printf("��: %d\n", S1->class);
	printf("�������: %f\n", S1->average);

	free(S1);
}

#pragma endregion

#pragma region "�������� 3���� ��ǥ ����ü �����Ϳ� �޸� �Ҵ��ϱ�"

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

#pragma region "�������� ����ü �����Ϳ� ����ü �ּ� �Ҵ��ϱ�"

struct practice_Item {
	char name[100];
	int price;
	bool limited;
};

void practice_pointer_to_struct()
{
	struct practice_Item Item1 = { "������ ���ϸ�� ���亥 ����� ����", 100000,false };
	struct practice_Item* ptr = malloc(sizeof(struct practice_Item));

	ptr = &Item1;

	ptr->limited = true;

	if (ptr->limited == true)
		printf("������\n");
	else
		printf("�Ϲ���\n");

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
	strcpy(p1->name, "��浿");
	p1->age = 40;
	strcpy(p1->address, "����� ���ʱ� ������");

	Car* c1 = malloc(sizeof(Car));
	strcpy(c1->name, "���ڶ�");
	c1->number = 3421;
	c1->displacement = 2000;

	printf("�̸�: %s\n", p1->name);
	printf("����: %d\n", p1->age);
	printf("�ּ�: %s\n", p1->address);

	printf("�ڵ��� �̸�: %s\n", c1->name);
	printf("�ڵ��� ��ȣ: %d\n", c1->number);
	printf("��ⷮ: %dcc\n", c1->displacement);

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

	//printf("%f %f %f\n", ptr->x, ptr->y, ptr->z);          //�ȵ�
	printf("%f %f %f\n", p1.x, p1.y, p1.z);
}

#pragma endregion

#pragma endregion

#pragma region "50�� �� �� ���̿� �Ÿ� ���ϱ�"

#pragma region "�ﰢ��"

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

#pragma region "�簢��"

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

#pragma region "����_�� �� ������ �Ÿ� ���ϱ�"

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

#pragma region "51�� ����ü ��� ���� ����ϱ�"

#pragma region struct_sizeof

struct PacketHeader {

	char flags; // 1����Ʈ
	int seq; //4����Ʈ
	long long pp;
};

void struct_sizeof()
{
	struct PacketHeader header;

	printf("%d\n", sizeof(header.flags));           // 1: char�� 1����Ʈ
	printf("%d\n", sizeof(header.seq));             // 4: int�� 4����Ʈ
	printf("%d\n", sizeof(header));					// 8: ����ü ��ü ũ��� 8����Ʈ
	printf("%d\n", sizeof(struct PacketHeader));    // 8: ����ü �̸����� ũ�� ���ϱ�
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

#pragma region "����ü ���� ���ϱ�"

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

#pragma region "quiz ����ü ũ�� ���ϱ�"

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

#pragma region "quiz ��Ŷ ũ�� �����ϱ�"

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

#pragma region "�ɻ繮�� ��ȣȭ ��� ũ�� ���ϱ�"

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

#pragma region "�ɻ繮�� ��Ŷ ũ�� �����ϱ�"

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

#pragma region "52�� ����ü�� �޸� Ȱ���ϱ�"

#pragma region "����ü ���� �ʱ�ȭ"

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

#pragma region "����ü ������ �ʱ�ȭ"

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

#pragma region "����ü �޸� �����ϱ�"

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

#pragma region "���� �޸𸮳��� �����ϱ�"

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

#pragma region "�������� 2���� ��ǥ �ʱ�ȭ�ϱ�"

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

#pragma region "�������� 2���� ��ǥ �����ϱ�"

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

#pragma region "�ɻ繮�� �������� �����ϱ�"

struct Person_52 {
	char name[20];
	int age;
	char address[100];
};

void judge_struct_memory()
{
	struct Person_52 p1;

	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "�����");

	memset(&p1, 0, sizeof(struct Person_52));

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);

}

#pragma endregion

#pragma region "�������� �����ϱ�"

struct person_51_memory_copy {
	char name[20];
	int age;
	char address[100];
};

void judge_struct_memory_copy()
{
	struct person_51_memory_copy* p1 = malloc(sizeof(struct person_51_memory_copy));
	struct person_51_memory_copy p2;

	strcpy(p1->name, "��浿");
	p1->age = 40;
	strcpy(p1->address, "�����");

	memcpy(&p2, p1, sizeof(struct person_51_memory_copy));

	printf("�̸�: %s\n", p2.name);
	printf("����: %d\n", p2.age);
	printf("�ּ�: %s\n", p2.address);

	free(p1);
}

#pragma endregion

#pragma endregion

#pragma region "53�� ����ü �迭 ����ϱ�"

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

#pragma region "����ü ������ �迭 �����ϱ�"

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

#pragma region "�������� 2���� ��ǥ ����ϱ�"

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

#pragma region "�������� ���� ������ �ʱ�ȭ�ϱ�"

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

#pragma region "�ɻ繮�� ���� ���� ���ϱ�"

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

#pragma region "�ɻ繮�� ���̰� ���� ���� ��� ã��"

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
		printf("%d��° ���: ", i + 1);
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

#pragma region "54�� ����ü ����ϱ�"

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

#pragma region "����ü �����͸� �����ϰ� �޸� �Ҵ��ϱ�"

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

#pragma region "�ɻ繮�� ���������� ����ü ����ϱ�"

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

#pragma region "�ɻ繮�� ����ü ������ ����ϱ�"

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

#pragma region "55�� ����ü�� ����ü Ȱ���ϱ�"

#pragma region "����ü �ȿ��� ����ü ��� ����ϱ�"

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

#pragma region "����ü ������ �����ϴ� ���ÿ� �ʱ�ȭ�ϱ�"

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

#pragma region "����ü ���� ����ü ����� �޸� �Ҵ��ϱ�"

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

#pragma region "55.3 �͸� ����ü�� �͸� ����ü Ȱ���ϱ�"  

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

#pragma region "55.5 ��������: ����ĳ���� ����ü �����"

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

#pragma region "�ɻ繮�� : ����ĳ���� ����ü ����ϱ�"

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

#pragma region "�ɻ繮��: ����ĳ���� ����ü ������ ����ϱ�"

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

#pragma region "�ɻ繮�� ��ġ �ɼ� ����ü �����"

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

#pragma region "56�� ����ü ��Ʈ �ʵ� ����ϱ�"

#pragma region "56.1 ����ü ��Ʈ �ʵ带 ����� ����ϱ�"

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

#pragma region "56.2 ��Ʈ �ʵ�� ����ü �Բ� ����ϱ�"

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

#pragma region "��������: ����ü�� �÷��� ��Ʈ �ʵ� �����"

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

#pragma region "��������: ����ü�� ����ü�� �÷��� ��Ʈ �ʵ� �����"

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

#pragma region "�ɻ繮��: ����ü�� �÷��� ��Ʈ �ʵ� �����"

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

#pragma region "�ɻ繮��: ����ü�� ����ü�� �÷��� ��Ʈ �ʵ� �����"

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

#pragma region "57�� ������ ����ϱ�"

#pragma region "������ �����ϱ�"

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

#pragma region "�������� switch�� Ȱ���ϱ�"

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

#pragma region "�������� for�� Ȱ���ϱ�"

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

#pragma region "57.5 ��������: ��ġ ���� �����ϱ�"

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

#pragma region "57.6 ��������: ���� ĳ���� ��ų ó���ϱ�"

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
		printf("������\n");
		break;
	case SilverBolts:
		printf("��ȭ��\n");
		break;
	case Condemn:
		printf("����\n");
		break;
	case FinalHour:
		printf("������ �ð�\n");
		break;
	default:
		break;
	}
}

#pragma endregion

#pragma region "57.7 ��������: �� ����ϱ�"

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

#pragma region "57.8 �ɻ繮��: �������� ���� �����ϱ�"

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

#pragma region "57.9 �ɻ繮��; ���� ĳ���� ��ų ó���ϱ�"

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
		printf("�ϰ� �ʻ�\n");
		break;
	case Meditation:
		printf("���\n");
		break;
	case WujuStyle:
		printf("���ַ� �˼�\n");
		break;
	case Highlander:
		printf("������ ����\n");
		break;
	default:
		break;
	}
}

#pragma endregion

#pragma region "57.10 �ɻ繮��: �����̽� Ÿ�� ����ϱ�"

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

#pragma region "58�� �ڷ��� ��ȯ�ϱ�"

void type_conversion_variable()
{
	int num1 = 32;
	int num2 = 7;
	float num3;

	num3 = num1 / num2;      // ������ ��� �߻�
	printf("%f\n", num3);    // 4.000000

	num3 = (float)num1 / num2;    // num1�� float�� ��ȯ
	printf("%f\n", num3);         // 4.571429
}

void type_conversion_pointer()
{
	int* numPtr = malloc(sizeof(int));    // 4����Ʈ��ŭ �޸� �Ҵ�
	char* cPtr;

	*numPtr = 0x12345678;

	cPtr = (char*)numPtr;     // int ������ numPtr�� char �����ͷ� ��ȯ. �޸� �ּҸ� �����

	printf("0x%x\n", *cPtr);   // 0x78: ���� �ڸ��� 1����Ʈ�� �������Ƿ� 0x78

	free(numPtr);    // ���� �޸� ����
}

//void type_conversion_pointer_invalid_value()
//{
//	short* numPtr1 = malloc(sizeof(short));    // 2����Ʈ��ŭ �޸� �Ҵ�
//	int* numPtr2;
//
//	*numPtr1 = 0x1234;
//
//	numPtr2 = (int*)numPtr1;    // short ������ numPtr1�� int �����ͷ� ��ȯ. �޸� �ּҸ� �����
//
//	printf("0x%x\n", *numPtr2);    // 0xfdfd1234: ���� �޸𸮸� ħ���Ͽ� ���� ������
//								   // 0xfdfd�� ��Ȳ�� ���� ���� �޶��� �� ����
//
//	free(numPtr1);    // ���� �޸� ����
//}

void type_conversion_pointer_dereference()
{
	int* numptr = malloc(sizeof(int));
	char* cptr;
	*numptr = 0x12345678;

	printf("0x%x\n", *(char*)numptr);

	free(numptr);
}

void type_conversion_void_pointer() // void ������ ��ȯ�ϱ�, void pointer �ڷ��� ���������
{
	int num1 = 10;
	float num2 = 3.5f;
	char c1 = 'a';
	void* ptr;

	ptr = &num1;    // num1�� �޸� �ּҸ� void ������ ptr�� ����
	// printf("%d\n", *ptr);         // ������ ����
	printf("%d\n", *(int*)ptr);     // 10: void �����͸� int �����ͷ� ��ȯ�� �� ������

	ptr = &num2;    // num2�� �޸� �ּҸ� void ������ ptr�� ����
	// printf("%f\n", *ptr);         // ������ ����
	printf("%f\n", *(float*)ptr);   // 3.500000: void �����͸� float �����ͷ� ��ȯ�� �� ������

	ptr = &c1;      // c1�� �޸� �ּҸ� void ������ ptr�� ����
	// printf("%c\n", *ptr);         // ������ ����
	printf("%c\n", *(char*)ptr);    // a: void �����͸� char �����ͷ� ��ȯ�� �� ������
}

#pragma region "����ü ������ ��ȯ�ϱ�"

struct data_58_4 {
	char c1;
	int num1;
};

void type_conversion_struct_pointer()
{
	struct data_58_4* d1 = malloc(sizeof(struct data_58_4));    // �����Ϳ� ����ü ũ�⸸ŭ �޸� �Ҵ�
	void* ptr;    // void ������ ����

	d1->c1 = 'a';
	d1->num1 = 10;

	ptr = d1;    // void �����Ϳ� d1 �Ҵ�. ������ �ڷ����� �޶� ������ ��� �߻����� ����.

	printf("%c\n", ((struct data_58_4*)ptr)->c1);      // 'a' : ����ü �����ͷ� ��ȯ�Ͽ� ����� ����
	printf("%d\n", ((struct data_58_4*)ptr)->num1);    // 10  : ����ü �����ͷ� ��ȯ�Ͽ� ����� ����

	free(d1);    // ���� �޸� ����

}

#pragma endregion

#pragma region "����ü ������ ��Ī"

typedef struct data_58_4_2 {
	char c1;
	int num1;
}data_588, * pdata;

void type_conversion_typedef_struct()
{
	pdata d1 = malloc(sizeof(pdata));    // ����ü ������ ��Ī���� ������ ����
	void* ptr;   // void ������ ����

	d1->c1 = 'a';
	d1->num1 = 10;

	ptr = d1;    // void �����Ϳ� d1 �Ҵ�. ������ �ڷ����� �޶� ������ ��� �߻����� ����.

	printf("%c\n", ((data_588*)ptr)->c1);     // 'a' : ����ü ��Ī�� �����ͷ� ��ȯ
	printf("%d\n", ((pdata)ptr)->num1);    // 10  : ����ü ������ ��Ī���� ��ȯ

	free(d1);    // ���� �޸� ����
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

#pragma region "58.9 ��������: ����ü ������ ��ȯ�ϱ�"

struct Person_58_9 {
	char name[20];
	int age;
};

void practice_type_conversion_void_pointer()
{
	struct Person_58_9* p1 = malloc(sizeof(struct Person_58_9));
	void* ptr;

	strcpy(p1->name, "��浿");
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

#pragma region "�ɻ繮��: ����ü ������ ��ȯ�ϱ�"

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

#pragma region "59�� ������ ���� ����ϱ�"

#pragma region  "59.1�� ������ �������� �޸� �ּ� �����ϱ�"

void pointer_add()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = numArr;    // �迭 ù ��° ����� �޸� �ּҸ� �����Ϳ� ����

	numPtrB = numPtrA + 1;    // ������ ����
	numPtrC = numPtrA + 2;    // ������ ����

	printf("%p\n", numPtrA);    // 00A3FC00: �޸� �ּ�. ��ǻ�͸���, ������ ������ �޶���
	printf("%p\n", numPtrB);    // 00A3FC04: sizeof(int) * 1�̹Ƿ� numPtrA���� 4�� ������
	printf("%p\n", numPtrC);    // 00A3FC08: sizeof(int) * 2�̹Ƿ� numPtrA���� 8�� ������

	// ������ ������ ������ �ڷ����� ũ��(int)��ŭ ���� ��

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

	printf("%p\n", numPtrA);    // 00A3FC08: �޸� �ּ�. ��ǻ�͸���, ������ ������ �޶���
	printf("%p\n", numPtrB);    // 00A3FC04: sizeof(int) * -1�̹Ƿ� numPtrA���� 4�� ������
	printf("%p\n", numPtrC);    // 00A3FC00: sizeof(int) * -2�̹Ƿ� numPtrA���� 8�� ������

}

void pointer_increment_decrement()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];    // �迭 �� ��° ����� �ּҸ� �����Ϳ� ����
	numPtrB = numPtrA;
	numPtrC = numPtrA;

	numPtrB++;
	numPtrC--;

	printf("%p\n", numPtrA);    // 00A3FC08: �޸� �ּ�. ��ǻ�͸���, ������ ������ �޶���
	printf("%p\n", numPtrB);    // 00A3FC0C: sizeof(int) * 1�̹Ƿ� numPtrA���� 4�� ������
	printf("%p\n", numPtrC);    // 00A3FC04: sizeof(int) * -1�̹Ƿ� numPtrA���� 4�� ������

}

#pragma endregion

#pragma region "59.2�� ������ ����� ������ ����ϱ�"

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

	printf("%d\n", *(numPtrA + 1));    // 22: numPtrA���� ���������� 4����Ʈ��ŭ ������
									   // �޸𸮿� �ּҿ� ����. numArr[1]�� ����

	printf("%d\n", *(numPtrA + 2));    // 33: numPtrA���� ���������� 8����Ʈ��ŭ ������
									   // �޸𸮿� �ּҿ� ����. numArr[2]�� ����

	//��ȣ�� �ȹ����ָ� ���� ������ �� ���� ������
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

#pragma region "59.3�� void�����ͷ� ������ �����ϱ�"

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

#pragma region "59.4�� ����ü �����ͷ� ������ �����ϱ�"

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
	void* ptr = malloc(sizeof(struct Data_59_4_2) * 3);    // ����ü 3�� ũ�⸸ŭ ���� �޸� �Ҵ�
	struct Data_59_4_2 d[3];

	((struct Data_59_4_2*)ptr)->num1 = 10;        // ������ �������� �޸𸮿� �� ����
	((struct Data_59_4_2*)ptr)->num2 = 20;        // ������ �������� �޸𸮿� �� ����

	((struct Data_59_4_2*)ptr + 1)->num1 = 30;    // ������ �������� �޸𸮿� �� ����
	((struct Data_59_4_2*)ptr + 1)->num2 = 40;    // ������ �������� �޸𸮿� �� ����

	((struct Data_59_4_2*)ptr + 2)->num1 = 50;    // ������ �������� �޸𸮿� �� ����
	((struct Data_59_4_2*)ptr + 2)->num2 = 60;    // ������ �������� �޸𸮿� �� ����

	memcpy(d, ptr, sizeof(struct Data_59_4_2) * 3);    // ���� �޸𸮰� ����ü �迭�� ���¿� ������ 
													   // Ȯ���ϱ� ���� ���� �޸��� ������ ����ü �迭�� ����

	printf("%d %d\n", d[1].num1, d[1].num2);    // 30 40: ����ü �迭�� ��� ���
	printf("%d %d\n", ((struct Data_59_4_2*)ptr + 2)->num1, ((struct Data_59_4_2*)ptr + 2)->num2);
	// 50 60: ������ �������� �޸��� �� ���

	free(ptr);    // ���� �޸� ����

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

#pragma region "59.8 ��������: ����ü �����Ϳ� ������ ����"

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

#pragma region "59.11 �ɻ繮��: ����ü �����ͷ� ������ �����ϱ�"

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

#pragma region "60�� �Լ� ����ϱ�"

void hello_60()
{
	printf("Hello, wolrd!\n");
}

void function()
{
	hello_60();
}

#pragma region "�Լ� ����� ���� �����ϱ�"

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

#pragma region "����� ���"

void hello_60_3()
{
	printf("Hello,world!\n");
}

void main_60_3()
{
	hello_60_3();
}

#pragma endregion

#pragma region "60.5 ��������: �Լ� ȣ���ϱ�"

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

#pragma region "60.6 ��������: �Լ� �����ϱ�"

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

#pragma region "60.7 �ɻ繮��: �Լ� �����ϱ�"

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

#pragma region "60.8 �ɻ繮��: �Լ� �����ϱ�"

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

#pragma region "61�� �Լ����� ��ȯ�� ����ϱ�"

#pragma region return_integer

int one_611_1()
{
	return 1;
}

void main_611_1()
{
	int num1;
	num1 = one_611_1();		// int���� ��ȯ�����Ƿ� int�� ������ ����
	printf("%d\n", num1);
}

#pragma endregion 

#pragma region "�Լ����� �Ǽ�, �Ұ� ��ȯ"

float realNumber_6112()    // ��ȯ���� float���� realNumber �Լ� ����
{
	return 1.234567f;    // 1.234567: float���� ��ȯ
}

bool truth_6112()    // ��ȯ���� bool���� truth �Լ� ����
{
	return true;    // true: bool���� ��ȯ
}

void main_6112()
{
	float num1;
	bool b1;

	num1 = realNumber_6112();    // float���� ��ȯ�����Ƿ� float�� ������ ����
	b1 = truth_6112();           // bool���� ��ȯ�����Ƿ� bool�� ������ ����

	printf("%f\n", num1);   // 1.234567
	printf("%d\n", b1);     // 1

	return 0;
}

#pragma endregion

#pragma region "��ȯ���� �ڷ����� �ڷ��� ��ȯ"

int one_6113()
{
	float a = 1.1f;
	return (int)a;  // a�� int�� ��ȯ�Ͽ� ��ȯ
}

void main_6113()
{
	int num1;

	num1 = one_6113(); // int���� ��ȯ�����Ƿ� int�� ������ ����

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

#pragma region "61.2 ������ ��ȯ�ϱ�"

#pragma region "�߸��� ���"

int* ten_612() // �߸��� ���
{
	int num1 = 10;   // num1�� �Լ� ten�� ������ �����

	return &num1;    // �Լ����� ���� ������ �ּҸ� ��ȯ�ϴ� ���� �߸��� ���
} //        �� warning C4172: ���� ���� �Ǵ� �ӽ� ������ �ּҸ� ��ȯ�ϰ� �ֽ��ϴ�.


void main_612()
{
	int* numPtr;

	numPtr = ten_612();    // �Լ��� ȣ���ϰ� ��ȯ���� numPtr�� ����

	printf("%d\n", *numPtr);    // 10: ���� ������ ������ �̹� ����� ������ ����ϰ� ����
}

#pragma endregion

int* ten_6122()
{
	int* numPtr = malloc(sizeof(int));    // int ũ�⸸ŭ ���� �޸� �Ҵ�

	*numPtr = 10;    // �������� 10 ����

	return numPtr;   // ������ ��ȯ. malloc���� �޸𸮸� �Ҵ��ϸ� �Լ��� ������ ������� ����
}

void main_6122()
{
	int* numPtr;

	numPtr = ten_6122();    // �Լ��� ȣ���ϰ� ��ȯ���� numPtr�� ����

	printf("%d\n", *numPtr);    // 10: �޸𸮸� �����ϱ� ������ ������

	free(numPtr);    // �ٸ� �Լ����� �Ҵ��� �޸𸮶� �ݵ�� �����ؾ� ��

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

#pragma region "61.3 void ������ ��ȯ�ϱ�"

void* allocMemory_6131()
{
	void* ptr = malloc(100);

	return ptr;
}

void main_613()
{
	char* s1 = allocMemory_6131();  // void �����͸� char �����Ϳ� �־ 
	strcpy(s1, "Hello, world!");
	printf("%s\n", s1);
	free(s1);

	int* numPtr1 = allocMemory_6131(); // void �����͸� int �����Ϳ� �־
	numPtr1[0] = 10;
	numPtr1[1] = 20;
	printf("%d %d\n", numPtr1[0], numPtr1[1]);
	free(numPtr1);
}

#pragma endregion

#pragma region "61.4 ����ü�� ����ü ������ ��ȯ�ϱ�"

#pragma region case1 "�޸� �Ҵ�x"

struct Person_614 {
	char name[20];
	int age;
	char address[100];
};

struct Person_614 getPerson_614() // Person ����ü�� ��ȯ�ϴ� getPerson �Լ�
{
	struct Person_614 p;

	strcpy(p.name, "ȫ�浿");
	p.age = 30;
	strcpy(p.address, "����� ��걸 �ѳ���");

	return p;
}

void main_614()
{
	struct Person_614 p1;
	p1 = getPerson_614();	// ��ȯ�� ����ü ������ ������ p1�� ��� �����

	printf("�̸�:%s\n", p1.name);
	printf("����:%d\n", p1.age);
	printf("�ּ�:%s\n", p1.address);
}

#pragma endregion

#pragma region case2 "�޸� �Ҵ�"

struct Person_6142 {
	char name[20];
	int age;
	char address[100];
};

struct Person_6142* allocPerson_6142()
{
	struct Person_6142* p = malloc(sizeof(struct Person_6142));

	strcpy(p->name, "ȫ�浿");
	p->age = 30;
	strcpy(p->address, "����� ��걸 �ѳ���");

	return p;
}

void main_6142()
{
	struct Person_6142* p1;
	p1 = allocPerson_6142();

	printf("�̸�: %s\n", p1->name);
	printf("����: %d\n", p1->age);
	printf("�ּ�: %s\n", p1->address);

	free(p1);
}

#pragma endregion

#pragma endregion

#pragma region "61.6 ��������: ���� ĳ���� �ɷ�ġ �Լ� �����"

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

#pragma region "61.7 ��������: ���ڿ� ������ ��ȯ�ϱ�"

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

#pragma region "61.8 ��������: �޸� �Ҵ� �Լ� �����"

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

#pragma region "61.9 ��������: ���� ���� �Լ� �����"

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

#pragma region "61.10 �ɻ繮��: ���� ĳ���� �ɷ�ġ �Լ� �����"

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

#pragma region "61.11 �ɻ繮��: ���ڿ� ������ ��ȯ�ϱ�"

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

#pragma region "61.12 �ɻ繮��: �޸� �Ҵ� �Լ� �����"

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

#pragma region "61.13 �ɻ繮��: 2���� ���� �����"

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

#pragma region "62�� �Լ����� �Ű����� ����ϱ�"

#pragma region "�Ű� ���� ����ϱ�"

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

#pragma region "���� �Լ� �����"

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

#pragma region "����ſ��� �Ű������� ��ȯ�� Ȯ���ϱ�"

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

#pragma region "62.5 ��������: ���� �Ű����� ����ϱ�"

void printType_625(char type)
{
	printf("Type %c\n", type);
}

void main_625()
{
	printType_625('x');
}

#pragma endregion

#pragma region "62.6 ��������: ���� �Լ� �����"

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

#pragma region "62.7 �ɻ繮��: ���� ĳ���� �ɷ�ġ ���� �Լ� �����"

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

#pragma region "62.8 �ɻ繮��: ���� �Լ� �����"

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

#pragma region "62.9 �ɻ繮��: 3���� ���� �����"

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

#pragma region "63�� �Լ����� ������ �Ű����� ����ϱ�"

#pragma region "�Ű������� �Լ� �ٱ��� �����ʹ� ���x"

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

	printf("%d %d\n", num1, num2); // ó�� ������ 10�� 20�� ���
	// �Ű������� ���� �����ϴ� ���Ҹ� �� �� �Լ� �ٱ��� �����ʹ� ����� �����ϴ�.
}

#pragma endregion

#pragma region "�Ű����� ������ ���"

void swapNumber_6312(int* first, int* second) //int ������ �Ű����� ����
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

	swapNumber_6312(&num1, &num2); // &�� ����Ͽ� num1�� num2�� �޸� �ּҸ� �־���

	printf("%d %d\n", num1, num2); // 20 10: swapNumber�� ���ؼ� num1�� num2�� ���� ���� �ٲ�
}

#pragma endregion

#pragma region "63.2 void ������ �Ű����� ����ϱ�"

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

#pragma region "63.3 ���� ������ �Ű����� ����ϱ�"

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

#pragma region "63.4 ���ڿ� �Ű����� ����ϱ�"

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

#pragma region "63.6 ��������: �Լ����� ��ȯ������ �� �� ��, �Ű������� �� �� �� ������"

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

#pragma region "63.7 ��������: �Լ����� ��� �����"

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

#pragma region "63.8 ��������: ���ڿ� �Ű����� ����ϱ�"

void compareString_638(char* a, char* b)
{
	if (strcmp(a, b) == 0)
		printf("����");
	else
		printf("�ٸ�");
}

void main_638()
{
	char* s1 = malloc(sizeof(char) * 10);

	strcpy(s1, "Venus");

	compareString_638(s1, "Venus");

	free(s1);
}

#pragma endregion

#pragma region "63.9 �ɻ繮��: ��� �������� ���ϴ� �Լ� �����"

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

#pragma region "63.10 �ɻ繮��: �Լ����� �޸𸮸� �Ҵ��Ͽ� �迭 �����"

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

#pragma region "63.11 �ɻ繮��: ���ڿ� �Ű����� ����ϱ�"

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

#pragma region "64�� �Լ����� �迭 �Ű����� ����ϱ�"

#pragma region "64.1 �迭 �Ű����� ����ϱ�"

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

	// �迭�� �޸� �ּҸ� �����߱� ������ �����δ� �ٱ��� �ִ� �迭�� ��Ұ� �ٲ�����ϴ�.
}

#pragma endregion
// �Ű������� arr[]�� ���� �����ߴٸ� arr�� �������Դϴ�.
// �迭�� �޸� �ּҸ� �����߱� ������ �����δ� �ٱ��� �ִ� �迭�� ��Ұ� �ٲ�����ϴ�.

#pragma region parameter_pointer "���ȣ ��� ������"

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

#pragma region "�迭���� Ư�� ����� ���� ���� �ٲٱ�"

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

#pragma region "���� ���ͷ� ����Ͽ� �迭�� ���� �������� �ʱ�"

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

//#pragma region "�Լ��� �迭 �Ű��������� ����� �ּ� ���� �����ϱ�(static)"
//// vs2015������ ����� �� ������ gcc, clang������ ����
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
//	// ��� ������ 5���̹Ƿ� OK
//	printArray(numArr1, sizeof(numArr1) / sizeof(int));
//
//	int numArr2[3] = { 1, 2, 3 };
//
//	// ��� ������ 3���̹Ƿ� ���
//	printArray(numArr2, sizeof(numArr1) / sizeof(int));
//}
//
//#pragma endregion
//
//#pragma endregion
//

#pragma endregion

#pragma region "64.2 2���� �迭 �Ű����� ����ϱ�"

#pragma region"�迭 �Ἥ"

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

#pragma region "������ �Ἥ"

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

#pragma region "���� ���ͷ� �Ἥ"

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

#pragma region "64.6 �ɻ繮��: �迭 �Ű����� ����ϱ�"

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

#pragma region "64.7 �ɻ繮��: ��ġ��� �����"

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

#pragma region "65�� �Լ����� ����ü �Ű����� ����ϱ�"

#pragma region "65.1 ����ü �Ű����� ����ϱ�"

#pragma region parameter_struct

struct Person_651 {
	char name[20];
	int age;
	char address[100];
};

void printPerson_651(struct Person_651 p)
{
	// ����ü �Ű����� ����� �� ���
	printf("�̸�: %s\n", p.name);       // �̸�: ȫ�浿
	printf("����: %d\n", p.age);        // ����: 30
	printf("�ּ�: %s\n", p.address);    // �ּ�: ����� ��걸 �ѳ���
}

void main_651()
{
	struct Person_651 p1;

	strcpy(p1.name, "�ձ�");
	p1.age = 30;
	strcpy(p1.address, "����");

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
	printf("�̸�: %s\n", p.name);
	printf("����: %d\n", p.age);
	printf("�ּ�: %s\n", p.address);
}

void main_6512()
{
	printPerson_6512((struct Person_6512) { .name = "ȫ�浿", .age = 30, .address = "����" });
}

#pragma endregion

#pragma region "�Ű������� ���� ����ü ����� ���� �����ص� �Լ� �ٱ��� ����x"

struct Person_6513 {
	char name[20];
	int age;
	char address[100];
};

void setPerson_6513(struct Person_6513 p)    // ��ȯ�� ����, ����ü �Ű����� �� �� ����
{
	// �Ű������� ���� ����ü ����� �� ����
	strcpy(p.name, "��浿");
	p.age = 40;
	strcpy(p.address, "����� ���ʱ� ������");
}

void main_6513()
{
	struct Person_6513 p1;

	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "����� ��걸 �ѳ���");

	setPerson_6513(p1);    // �Լ��� ȣ���� �� ����ü ���� ����, ����� �����

	// setPerson���� ������ ���� ������ ��ġ�� ����
	printf("�̸�: %s\n", p1.name);       // �̸�: ȫ�浿
	printf("����: %d\n", p1.age);        // ����: 30
	printf("�ּ�: %s\n", p1.address);    // �ּ�: ����� ��걸 �ѳ���

}

#pragma endregion

#pragma endregion

#pragma region "65.2 ����ü ������ �Ű����� ����ϱ�"

struct Person6521 {
	char name[20];
	int age;
	char address[100];
};

void setPerson6521(struct Person6521* p)    // ��ȯ�� ����, ����ü ������ �Ű����� �� �� ����
{
	// �Ű������� ���� �����Ϳ��� ����ü ����� �� ����
	strcpy(p->name, "��浿");
	p->age = 40;
	strcpy(p->address, "����� ���ʱ� ������");
}

void main6521()
{
	struct Person6521 p1;

	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "����� ��걸 �ѳ���");

	setPerson6521(&p1);    // �Լ��� ȣ���� �� ����ü ������ �޸� �ּҸ� ����

	// setPerson���� ������ ���� ��µ�
	printf("�̸�: %s\n", p1.name);       // �̸�: ��浿
	printf("����: %d\n", p1.age);        // ����: 40
	printf("�ּ�: %s\n", p1.address);    // �ּ�: ����� ���ʱ� ������
}

#pragma endregion

#pragma region "���� ���ͷ� ����ϱ�"

struct Person_6522 {
	char name[20];
	int age;
	char address[100];
};

void printPerson_6522(struct Person_6522* p)
{
	printf("�̸�: %s\n", p->name);
	printf("����: %d\n", p->age);
	printf("�ּ�: %s\n", p->address);
}

void main_6522()
{
	// ���� ���ͷ� ������� ����ü�� �Ѱ���
	printPerson_6522(&(struct Person_6522) { .name = "ȫ�浿", .age = 30, .address = "����� ��걸 �ѳ���" });

	// ���� ���ͷ� ������� ����ü�� �Ѱ���. ��� �̸� ����
	printPerson_6522(&(struct Person_6522) { "��浿", 40, "����� ���ʱ� ������" });
}

#pragma endregion

#pragma region "����ü ��Ī ����ϱ�"

typedef struct Person_6523 {
	char name[20];
	int age;
	char address[100];
}Person, * PPerson_6523;

void setPerson_6523(PPerson_6523 p)
{
	strcpy(p->name, "��浿");
	p->age = 40;
	strcpy(p->address, "����� ���ʱ� ������");
}

#pragma endregion

#pragma region "����ü�� �������� �Ű������� ����ϱ�"

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

#pragma region "65.5 ��������: ��ǥ ���� �Լ� �����"

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

#pragma region "65.6 �ɻ繮��: �� �� ������ �Ÿ��� ���ϴ� �Լ� �����"

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

#pragma region "65.7 �ɻ繮��: ��ǥ�� �̵���Ű�� �Լ� �����"

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

#pragma region "66�� �Լ����� ���� ���� ����ϱ�"

#pragma region "66.1 ���� ���� �Լ� �����"

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
	va_list ap;    // ���� ���� ��� ������

	va_start(ap, args);    // ���� ���� ��� ������ ����
	for (int i = 0; i < args; i++)    // ���� ���� ������ŭ �ݺ�
	{
		int num = va_arg(ap, int);    // int ũ�⸸ŭ ���� ���� ��� �����Ϳ��� ���� ������
									  // ap�� int ũ�⸸ŭ ���������� �̵�
		printf("%d ", num);           // ���� ���� �� ���
	}
	va_end(ap);    // ���� ���� ��� �����͸� NULL�� �ʱ�ȭ

	printf("\n");    // �ٹٲ�
}

void main_6612()
{
	printNumber_6612(1, 10);                // �μ� ���� 1��
	printNumber_6612(2, 10, 20);            // �μ� ���� 2��
	printNumber_6612(3, 10, 20, 30);        // �μ� ���� 3��
	printNumber_6612(4, 10, 20, 30, 40);    // �μ� ���� 4��
}

#pragma endregion

#pragma region "66.2 �ڷ����� �ٸ� ���� ���� �Լ� �����"

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

#pragma region "66.5 ��������: �ڷ����� �ٸ� ���� ������ �� ���ϱ�"

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

#pragma region "66.6 �ɻ繮��: ���� ������ �� ���ϱ�"

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

#pragma region "66.7 �ɻ繮��: ���� ������ ���� �� ���ϱ�"

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
			va_arg(ap, double);    // va_arg�� �ؾ� �������� �Ѿ
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

#pragma region "67�� �Լ����� ���ȣ�� ����ϱ�"

#pragma region "67.1 ���ȣ�� ����ϱ�"

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

#pragma region "67.2 ���ȣ��� ���丮�� ���ϱ�"

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

#pragma region "67.5 ��������: ���ȣ��� 1���� 100������ �� ���ϱ�"

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

#pragma region "67.6 �ɻ繮��: ���ȣ��� �Ǻ���ġ �� ���ϱ�"

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

#pragma region "67.7 �ɻ繮�� : ���ȣ��� 1���� n���� �� ���ϱ�"

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

#pragma region "68�� �Լ� ������ ����ϱ�"

#pragma region "68.1 �Լ� ������ �����"

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
	void (*fp)();   // ��ȯ���� �Ű������� ���� �Լ� ������ fp ����

	fp = hello_6811;     // hello �Լ��� �޸� �ּҸ� �Լ� ������ fp�� ����
	fp();           // Hello, world!: �Լ� �����ͷ� hello �Լ� ȣ��

	fp = bonjour_6811;   // bonjour �Լ��� �޸� �ּҸ� �Լ� ������ fp�� ����
	fp();           // bonjour le monde!: �Լ� �����ͷ� bonjour �Լ� ȣ��
}

#pragma endregion

#pragma region "68.2 ��ȯ���� �Ű������� �ִ� �Լ� ������ �����"

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

#pragma region "68.4 ��������: �Լ� ������ �����"

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

#pragma region "68.5 �ɻ繮��: ��ȯ���� �Ű������� �ִ� �Լ� ������ �����"

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

#pragma region "69�� �Լ� ������ Ȱ���ϱ�"

#pragma region "69.1 �Լ� ������ �迭 ����ϱ�"

#pragma region "switch �̿�"

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

	printf("�Լ���ȣ�� ����� ���� �Է��ϼ���\n");
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

#pragma region "�Լ� ������ �迭"

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

	printf("�Լ���ȣ�� ����� ���� �Է��ϼ���\n");
	scanf("%d %d %d", &funcNumber, &num1, &num2);

	printf("%d\n", fp[funcNumber](num1, num2));
}

#pragma endregion

#pragma endregion

#pragma region "69.2 �Լ� �����͸� ����ü ����� ����ϱ�"




int main()
{
	main_6911();

	return 0;
}

