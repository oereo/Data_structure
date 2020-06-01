#include <stdio.h>
#include <time.h>

int arr1[100][100] = {};
int arr2[100][100] = {};
int arr3[100][100] = {};
int row1 = 0;
int col1 = 0;
int row2 = 0;
int col2 = 0;
int result = 0;


//입력함수
void input() {

	printf("<first matrix>");
	printf("\n");
	printf("\n Please Enter Number of rows and columns : ");
	scanf_s("%d %d", &row1, &col1);

	printf("\n please input first matrix: ");
	printf("\n");

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			scanf_s("%d", &arr1[i][j]);
		}
	}
	printf("\n");
	printf("\n please input first matrix: ");
	printf("\n");
	printf("\n Please Enter Number of rows and columns : ");
	scanf_s("%d %d", &row2, &col2);

	printf("\n please input second matrix: ");
	printf("\n");

	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < col2; j++) {
			scanf_s("%d", &arr2[i][j]);
		}
	}
	

	printf("\n");
}


//3중 for문으로 곱셈연산하는 함수
void multiply() {
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			for (int k = 0; k < row2; k++) {
				result = result + arr1[i][k] * arr2[k][j];
			}

			arr3[i][j] = result;
			result = 0;
		}
	}
}


//출력함수
void output() {
	printf("multiplication matrtix : ");
	printf("\n");
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			printf("%d \t", arr3[i][j]);
		}
		printf("\n");
	}
}

int main() {

	//시간체크
	time_t start, finish;
	double timer;

	start = time(NULL);

	input();
	if (col1 != row2) {		// multiplication이 안되는 조건
		printf("impossible");
	}
	else {
		multiply();
		output();
	}
	
	finish = time(NULL);
	timer = (double)(finish - start);
	printf("걸린시간 : ");
	printf("%f", timer / CLOCKS_PER_SEC);

}
