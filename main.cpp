#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int status = 0;
int status_limit = 0;
int jukurendo = 0;
int danketsuryoku = 0;
int status_count = 0;
int status_limit_count = 0;
int requrired_status_point = 0;
int requrired_limit_point = 0;
int requrired_status_danketsuryoku_point = 0;
int requrired_limit_danketsuryoku_point = 0;

int required_point(int count, int point, int danketsuryoku_point,int *p_count,int *p_point, int *p_danketsuryoku_point){
	if (0 <= count && count <30) {
		point = 10;
		danketsuryoku_point = 0;
	}
	else if (30 <= count && count < 60) {
		point = 15;
		danketsuryoku_point = 0;
	}
	else if (60 <= count && count < 90) {
		point = 20;
		danketsuryoku_point = 1;
	}
	else if (90 <= count && count < 120) {
		point = 30;
		danketsuryoku_point = 2;
	}
	else if (120 <= count && count < 150) {
		point = 40;
		danketsuryoku_point = 3;
	}
	else if (150 <= count && count < 230) {
		point = 50;
		danketsuryoku_point = 4;
	}
	*p_count = count;
	*p_point = point;
	*p_danketsuryoku_point = danketsuryoku_point;
	return 0;
}

int main(void) {
	printf("以下の書式で情報を入力してください\n");
	printf("現在の特化ステータス 現在の特化ステータス上限 特化熟練度 団結力 現在の特化ステータス成長回数 現在の上限成長回数\n\n");
	(void)scanf("%d %d %d %d %d %d", &status, &status_limit, &jukurendo, &danketsuryoku, &status_count, &status_limit_count);

	while ((jukurendo - requrired_status_point >= 0 && danketsuryoku - requrired_status_danketsuryoku_point >= 0) || (jukurendo - requrired_limit_point >= 0 && danketsuryoku - requrired_limit_danketsuryoku_point >=0)&&(status_count < 230)) {
		required_point(status_count, requrired_status_point, requrired_status_danketsuryoku_point, &status_count, &requrired_status_point, &requrired_status_danketsuryoku_point);
		required_point(status_limit_count, requrired_limit_point, requrired_limit_danketsuryoku_point, &status_limit_count, &requrired_limit_point, &requrired_limit_danketsuryoku_point);
		//printf("テスト表示%d %d %d %d %d %d\n",status_count, requrired_status_point, requrired_status_danketsuryoku_point, status_limit_count, requrired_limit_point, requrired_limit_danketsuryoku_point);
		if (((status + 10) <= status_limit) && ((jukurendo - requrired_status_point) >= 0) && ((danketsuryoku - requrired_status_danketsuryoku_point) >= 0)) {
			//puts("テスト分岐1\n");
			status = status + 10;
			jukurendo = jukurendo - requrired_status_point;
			danketsuryoku = danketsuryoku - requrired_status_danketsuryoku_point;
			status_count++;
		}
		else if (((jukurendo - requrired_limit_point) >= 0) && ((danketsuryoku - requrired_limit_danketsuryoku_point) >= 0) && (status_count < 230)) {
			//puts("テスト分岐2\n");
			status_limit = status_limit + 10;
			jukurendo = jukurendo - requrired_limit_point;
			danketsuryoku = danketsuryoku - requrired_limit_danketsuryoku_point;
			status_limit_count++;
		}
		else if((status < status_limit) && ((jukurendo - requrired_status_point) >= 0) && ((danketsuryoku - requrired_status_danketsuryoku_point) >= 0)&&(status_count < 230)){
			//puts("テスト分岐3\n");
			status = status_limit;
			jukurendo = jukurendo - requrired_status_point;
			danketsuryoku = danketsuryoku - requrired_status_danketsuryoku_point;
			status_count++;
		}
	}
	printf("最終的なステータス情報は\n");
	printf("特化ステータス：%d\n", status);
	printf("特化上限：%d\n", status_limit);
	printf("累計特化ステータス成長回数:%d\n", status_count);
	printf("累計特化上限成長回数:%d\n", status_limit_count);
	printf("残り熟練度：%d\n", jukurendo);
	printf("残り団結力：%d\n", danketsuryoku);

	int enter;
	scanf("%d", &enter);
}