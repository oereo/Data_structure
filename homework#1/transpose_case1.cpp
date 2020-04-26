#include <stdio.h>
#include <time.h>

int arr[100][100] = {};
int trans[100][100] = {};
int row = 0;
int col = 0;


// matrix의 elements를 input하는 함수
void input() {
	

	printf("\n Please Enter Number of rows and columns : ");
	scanf_s("%d %d", &row, &col);
	
	printf("\n please input : ");
	printf("\n");

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\n");
}


//transpose를 하는 함수
void transpose() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			trans[j][i] = arr[i][j];
		}
	}

}


//출력 함수
void output() {


	printf("\n");
	printf("transpose matrix : ");
	printf("\n");

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%d\t", trans[i][j]);
		}
		printf("\n");
	}


}

int main() {


	//실행시간 측정하기 위한 코드
	time_t start, finish;
	double timer;

	start = time(NULL);

	input();
	transpose();
	output();

	finish = time(NULL);
	timer = (double)(finish - start);
	printf("걸린시간 : ");
	printf("%f", timer/CLOCKS_PER_SEC);

}