#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define MAX_ROW 13
#define START_POINT 0
#define END_POINT 0
#define MAX_C0L 17
bool visit[MAX_ROW][MAX_C0L];
int temp = 0;
int key_value;


short maze[MAX_ROW][MAX_C0L] = {

  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

  {1,START_POINT,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},

  {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},

  {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},

  {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},

  {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},

  {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},

  {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},

  {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},

  {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},

  {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},

  {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,END_POINT,1},

  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct {
	int row;
	int col;
}vertex;

int dR[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dC[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

bool isOutOfRange(vertex ver) {
	return ver.row < 0 || ver.row >= MAX_ROW || ver.col < 0 || ver.col >= MAX_C0L;

}

bool isNotRoom(vertex ver) {
	return maze[ver.row][ver.col] != 0;
}

bool isVisited(vertex ver) {
	return visit[ver.row][ver.col];
}

void goDFS(vertex ver) {
	//visit[ver.row][ver.col] = true;

	if (maze[ver.row][ver.col] == 0) {
		if (ver.row == 11 && ver.col == 15) {
			temp = 1;

			//printf("\n");
		}
		else if (maze[ver.row][ver.col] == 0) {
			maze[ver.row][ver.col] = 1;
			//if (temp == 0){
			for (int i = 0; i < 8; i++) {
				vertex nowVer = { ver.row + dR[i], ver.col + dC[i] };
				if (isOutOfRange(nowVer)) continue;
				if (isNotRoom(nowVer)) continue;
				if (isVisited(nowVer)) continue;
				//printf("{%d, %d}", nowVer.row, nowVer.col);
				if (temp == 0) {
					goDFS(nowVer);
				}


			}
			//}

			maze[ver.row][ver.col] = 0;
		}
	}
	if (temp == 1) {

		if (key_value == 49) {
			//printf("1\n");
			printf("(%d, %d)", ver.row, ver.col);
		}
		maze[ver.row][ver.col] = 8;
	}


}

int input() {
	printf("Our maze!! Let's start!!!\n\n");
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_C0L; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------------------------\n");
	printf("Please push the number\n");
	printf("--------------------------------------------------\n");
	printf("1. Search a maze\n");
	printf("2. Print a successful path\n");
	printf("0. Quit this program\n");
	printf("--------------------------------------------------\n");


}
int output() {
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_C0L; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("success!!!!!");
}

int main() {
	input();
	key_value = _getch();
	vertex ver = { 1,1 };

	goDFS(ver);

	printf("\n");
	if (key_value == 50) {
		printf("2\n");
		output();
	}
}