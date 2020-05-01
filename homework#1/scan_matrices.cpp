#include <stdio.h>
#include <conio.h>

int row = 0;
int col = 0;
int index_row = 0;
int index_col = 0;
int value = 0;
int check = 0;
int result[100][100] = { 0 };

void input() {

	int key_value;
	
	// y = 79 , n = 6e

	printf("Enter the sparse Matrices (row, Coulmn) : ");
	scanf_s("%d %d", &row, &col);
	printf("Enter the element (pos, val) \n");
	printf("row \t column \t value : ");
	
	scanf_s("%d %d %d", &index_row, &index_col, &value);	
	result[index_row][index_col] = value;

	while (check == 0) { // 진행을 계속할지 여부를 묻는 코드 
	printf("Continue(y or n) : ");
		key_value = _getch(); // 키보드키값을 가져옴
		if (key_value == 0x79) { // y일때
			printf("\n");
			printf("row \t column \t value : ");
			scanf_s("%d %d %d", &index_row, &index_col, &value);
			result[index_row][index_col] = value;
			
		}
		else if(key_value == 0x6e) { // n일때
			check = 1; // while문 빠져나옴
			printf("\n");
		}
	}
}

void output() { // sparse matrix 출력코드
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d \t", result[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init() { // 3번 sparse matrix의 scan이 이루어져야 되기 때문에 출력하고 초기화
	check = 0; // while문을 나오면서 1로 된 check값도 초기화
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = 0;
		}
	}
}

int main() {
	
	for (int i = 0; i < 3; i++) { // 3번동안 반복
		input();
		output();
		init();
	}
	
}