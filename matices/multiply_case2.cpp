#include <stdio.h>
#include <time.h>

int row1 = 0;	// first matrix의 행
int col1 = 0;	// first matrix의 열

int row2 = 0;	// second matrix의 행
int col2 = 0;	// second matrix의 열

int result = 0;
int cnt1 = 0;
int index1 = 1;
int cnt2 = 0;
int index2 = 1;

typedef struct {	// 희소행렬을 구조체로
	int row;
	int column;
	int value;
}matrix;

matrix arr1[100] = {};	// 첫번째 matrix의 희소행렬를 구하기 위해 선언
matrix arr2[100] = {};	// 두번째 matrix의 희소행렬을 구하기 위해 선언

int res[100][100] = { 0 };	// 최종결과값이 담겨져 있는 array


//두개의 matrix를 받는 input 함수
void input() {

	printf("<first matrix>");
	printf("\n");
	printf("\n Please Enter Number of rows and columns : ");
	scanf_s("%d %d", &row1, &col1);

	printf("\n please input first matrix: ");
	printf("\n");

	arr1[0].row = row1;
	arr1[0].column = col1;

	for (int i = 0; i < row1; i++) {	// 첫번째 matrix를 희소행렬로 바꾸는 코드
		for (int j = 0; j < col1; j++) {
			scanf_s("%d", &cnt1);
			if (cnt1 == 0) continue;
			arr1[index1].row = i;
			arr1[index1].column = j;
			arr1[index1].value = cnt1;
			index1++;

		}
	}
	arr1[0].value = index1 - 1; // 쌍의 개수

	for (int i = 0; i <= arr1[0].value; i++)	// 희소행렬이 제대로 출력되는지 확인
	{
		printf("%d\t", arr1[i].row);
		printf("%d\t", arr1[i].column);
		printf("%d\n", arr1[i].value);
	}

	printf("\n");
	printf("<second matrix>");
	printf("\n");
	printf("\n Please Enter Number of rows and columns : ");
	scanf_s("%d %d", &row2, &col2);

	printf("\n please input second matrix: ");
	printf("\n");


	// second matrix
	arr2[0].row = row2;
	arr2[0].column = col2;

	for (int i = 0; i < row2; i++) {	// 두번째 matrix를 희소행렬로 바꾸는 코드
		for (int j = 0; j < col2; j++) {
			scanf_s("%d", &cnt2);
			if (cnt2 == 0) continue;
			arr2[index2].row = i;
			arr2[index2].column = j;
			arr2[index2].value = cnt2;
			index2++;

		}
	}
	arr2[0].value = index2 - 1;	// 두번째 matrix에서 0이 아닌 수들의 쌍의 개수

	for (int i = 0; i <= arr2[0].value; i++)	// 희소행렬이 제대로 나오는지 확인하는 코드
	{
		printf("%d\t", arr2[i].row);
		printf("%d\t", arr2[i].column);
		printf("%d\n", arr2[i].value);
	}


	printf("\n");
}

// matrix들의 곱셈과정을 다루는 함수
void multi() {		
	int x = 0;
	int y = 0;
	int res_x = 0;
	int res_y = 0;

	for (int i = 1; i <= arr1[0].value; i++) {	// 이중포문으로 구성
		for (int j = 1; j <= arr2[0].value; j++) {
			if (arr1[i].column == arr2[j].row) {
				x = arr1[i].row;
				y = arr2[j].column;
				res_x = arr1[i].value;
				res_y = arr2[j].value;
				res[x][y] += res_x * res_y;
			}
		}
	}
}

// multiplication 과정을 통해 출력되는 matrix 코드
void output() {	
	printf("multiplication matrtix : ");
	printf("\n");
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			printf("%d\t", res[i][j]);
		}
		printf("\n");
	}
}

//main 함수
int main() {	
	input();
	multi();
	output();
}
