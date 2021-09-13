#include "Lesson_1.h"

void swap(int* num1, int* num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


// 헤더에 정의된 내용을 c에서 구현하고 
// 컴파일과정에서
// c에 구현한 내용을 참조하여
// 바이너리 파일로 작성됨

// 헤더파일에 입력하는 것, 불러오는 것 모두 #include " " 사용
// {}로 구분
// ->함수명 조심!