#include <stdio.h>

int status = 0;								//現在の特化ステータス値
int status_limit = 0;						//現在の特化ステータス上限
int jukurendo = 0;							//現在の特化ステータスに対応する熟練度(歌唱力or安定感or表現力or集中力)
int danketsuryoku = 0;						//現在の団結力の値
int status_count = 0;						//特化ステータスの成長回数
int status_limit_count = 0;					//特化ステータス上限の成長回数
int required_status_point = 0;				//ステータスの次の成長に必要な熟練度(歌唱力or安定感or表現力or集中力)
int required_limit_point = 0;				//ステータス上限の次の成長に必要な熟練度(歌唱力or安定感or表現力or集中力)
int required_status_danketsuryoku_point = 0;//ステータスの次の成長に必要な団結力
int required_limit_danketsuryoku_point = 0;	//ステータス上限の次の成長に必要な団結力
int retry_flag = 0;							//繰り返し実行用フラグ

int initial_danketsuryoku = 0;				//団結力の初期値

/*特化ステータスor上限の次の成長に必要な熟練度と団結力の値を返す関数*/
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
	while (1) {	//繰り返し実行用のwhileループ
		while(1){	//入力値検証用のwhileループ
			printf("以下の書式で6個のパラメータ情報を入力してください\n");
			printf("現在の特化ステータス 現在の特化ステータス上限 特化熟練度 団結力 現在の特化ステータス成長回数 現在の上限成長回数\n\n");
			scanf_s("%d %d %d %d %d %d", &status, &status_limit, &jukurendo, &danketsuryoku, &status_count, &status_limit_count);
			if ((0 <= status && status <= 5000)								//特化ステータスの値が範囲内かどうか
				&& (500 <= status_limit && status_limit <=5000)				//特化ステータス上限の値が範囲内かどうか
				&& (0 <= jukurendo && jukurendo <= 9999)					//熟練度の値(歌唱力or安定感or表現力or集中力)が範囲内かどうか
				&& (0 <= danketsuryoku && danketsuryoku <= 9999)			//団結力の値が範囲内かどうか
				&& (0 <= status_count && status_count <=230)				//特化ステータスの値が範囲内かどうか
				&& (0 <= status_limit_count && status_limit_count <= 140)){	//特化ステータス上限値の値が範囲内かどうか
			break;
			}
			else {
				scanf_s("%*[^\n]");
				scanf_s("%*c");
				printf("正しい情報を入力してください\n");
				status = 0;
				status_limit = 0;
				jukurendo = 0;
				danketsuryoku = 0;
				status_count = 0;
				status_limit_count = 0;
			}
		}
		initial_danketsuryoku = danketsuryoku;

		while ((jukurendo - required_status_point >= 0 && danketsuryoku - required_status_danketsuryoku_point >= 0)							//ステータスが成長できる
			|| (jukurendo - required_limit_point >= 0 && danketsuryoku - required_limit_danketsuryoku_point >=0)&&(status_count < 230)) {	//orステータス上限値が成長できる場合実行

			//ステータスとステータス上限値の次の成長に必要な必要熟練度pt及び必要団結力を求める
			required_point(status_count, required_status_point, required_status_danketsuryoku_point, &status_count, &required_status_point, &required_status_danketsuryoku_point);
			required_point(status_limit_count, required_limit_point, required_limit_danketsuryoku_point, &status_limit_count, &required_limit_point, &required_limit_danketsuryoku_point);
			//printf("テスト表示%d %d %d %d %d %d\n",status_count, required_status_point, required_status_danketsuryoku_point, status_limit_count, required_limit_point, required_limit_danketsuryoku_point);
			//printf("テスト表示%d %d %d %d %d %d\n", status, status_limit, jukurendo, required_status_point, danketsuryoku, required_status_danketsuryoku_point);
			if (((status + 10) <= status_limit)									//特化ステータスが上限値-10の値で成長できる
				&& ((jukurendo - required_status_point) >= 0)					//かつ、特化ステータスの成長に必要な熟練度ptを保持している
				&& ((danketsuryoku - required_status_danketsuryoku_point) >= 0) //かつ、特化ステータスの成長に必要な団結力ptを保持している
				&& (status_count < 230)) {										//かつ、特化ステータスの成長回数が230回(カンスト)未満の場合、実行
				//puts("ステータス成長分岐\n");
				status = status + 10;
				jukurendo = jukurendo - required_status_point;
				danketsuryoku = danketsuryoku - required_status_danketsuryoku_point;
				status_count++;
			}
			else if (((jukurendo - required_limit_point) >= 0)					//上のif文が実行されず、特化ステータス上限値の成長に必要な熟練度ptを保持している
				&&((status_limit - status) <= 10)								//かつ、現在の特化ステータスと上限値の差が10以下
				&& ((jukurendo - 2*required_status_point)>=0)					//かつ、熟練度が2回の成長で枯渇しない
				&& ((danketsuryoku - required_limit_danketsuryoku_point) >= 0)  //かつ、特化ステータス上限値の成長に必要な団結力ptを保持している
				&& (status_limit_count < 140)) {								//かつ、特化ステータス上限の成長回数が140回(カンスト)未満の場合、実行
				//puts("上限成長分岐\n");
				status_limit = status_limit + 10;
				jukurendo = jukurendo - required_limit_point;
				danketsuryoku = danketsuryoku - required_limit_danketsuryoku_point;
				status_limit_count++;

			}
			else if((status < status_limit)										//上記のif文、else if文が実行されず、現在の特化ステータス値が上限値以下
				&& ((jukurendo - required_status_point) >= 0)					//特化ステータスの成長に必要な熟練度ptを保持している
				&& ((danketsuryoku - required_status_danketsuryoku_point) >= 0) //かつ、特化ステータスの成長に必要な団結力ptを保持している
				&& (status_count < 230)){										//かつ、特化ステータスの成長回数が230回(カンスト)未満の場合、実行
				//puts("ステータス成長分岐(これ以上上限を上げても意味がなく、上限値で打ち止めになる場合)\n");
				status = status_limit;
				jukurendo = jukurendo - required_status_point;
				danketsuryoku = danketsuryoku - required_status_danketsuryoku_point;
				status_count++;
			}
			else {
				//puts("Break分岐(無限ループ防止用)\n");
				break;
			}

		}
		printf("最終的な最大ステータス情報は\n");
		printf("特化ステータス:%d\n", status);
		printf("特化上限:%d\n", status_limit);
		printf("累計特化ステータス成長回数:%d\n", status_count);
		printf("累計特化上限成長回数:%d\n", status_limit_count);
		printf("残り熟練度:%d\n", jukurendo);
		printf("残り団結力:%d\n", danketsuryoku);
		
		retry_flag = 0;
		printf("\n\"1\"かそれ以外の数値を入力してください\n1:もう1回実行する。\nそれ以外の数値:プログラムを終了する。\n");
		scanf_s("%d", &retry_flag);
		if (retry_flag != 1) {
			break;
		}

		printf("SP変換可能回数:%d\n",danketsuryoku / 30);
		printf("SP変換値:%d\n", danketsuryoku / 30*10);
		printf("SP変換後残り団結力:%d\n", initial_danketsuryoku - 30*(danketsuryoku / 30));
		printf("上記を目安にSPに変換、上限パネルを解放した後もう一度実行してください\n");
		puts("--------------------------------------------");

	}
}