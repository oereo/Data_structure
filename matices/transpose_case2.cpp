#include <stdio.h>
#include <time.h>

//int arr[100][100] = {};
//int trans[100][100] = {};
int res_row = 0;
int res_col = 0;

typedef struct {
	int row;
	int column;
	int value;
}matrix;

matrix arr[100] = {};
matrix trans[100] = {};
int result[100][100] = { 0 };


void input() {

	int cnt = 0;
	int index = 1; // index값 위치
	printf("\n Please Enter Number of rows and columns : ");
	scanf_s("%d %d", &res_row, &res_col);

	arr[0].row = res_row; // arr의 인덱스 첫번째에는 원소의 개수가 들어갑니다.
	arr[0].column = res_col; 
	printf("input the matrix : ");
	printf("\n");
	for (int i = 0; i < res_row; i++) {
		for (int j = 0; j < res_col; j++) {
			scanf_s("%d", &cnt);
			if (cnt == 0) 
				continue;
			arr[index].row = i;
			arr[index].column = j;
			arr[index].value = cnt;
			index++;
		}
	}
	arr[0].value = index - 1; // 총원소의 개수

	/*for (int i = 0; i <= arr[0].value; i++)
	{
		printf("%d\t", arr[i].row);
		printf("%d\t", arr[i].column);
		printf("%d\n", arr[i].value);
	}*/
	printf("\n");
}

void transpose(matrix arr[], matrix trans[]) {

	int temp[100] = { 0 };
	int	pos[100] = {0};
	int j = 0;

	trans[0].row = arr[0].column;
	trans[0].column = arr[0].row;
	trans[0].value = arr[0].value;

	if (arr[0].value > 0) { // 원소가 있을시{
		for (int i = 0; i < arr[0].column; i++) {
			temp[i] = 0;
		}
		
		for (int i = 1; i <= arr[0].value; i++) {
			temp[arr[i].column]++;
			
		}
		pos[0] = 1;

		for (int i = 1; i < arr[0].column; i++) {
			pos[i] = pos[i - 1] + temp[i - 1];
		}

		for (int i = 1; i <= arr[0].value; i++) {
			
			j = pos[arr[i].column]++;
			trans[j].row = arr[i].column;
			trans[j].column = arr[i].row;
			trans[j].value = arr[i].value;
		}

	}
}
void output() {

	printf("\n");
	printf("transpose matrix : ");
	printf("\n");

	for (int i = 1; i <= arr[0].value; i++) {
		result[trans[i].row][trans[i].column] = trans[i].value;
		
	}
	/*for (int i = 0; i <= arr[0].value; i++)
	{
		printf("%d\t", trans[i].row);
		printf("%d\t", trans[i].column);
		printf("%d\n", trans[i].value);
	}*/

	for (int i = 0; i < res_row; i++) {
		for (int j = 0; j < res_col; j++) {
			printf("%d", result[i][j]);
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
	transpose(arr, trans);
	output();

	finish = time(NULL);
	timer = (double)(finish - start);
	printf("걸린시간 : ");
	printf("%f", timer / CLOCKS_PER_SEC);


}