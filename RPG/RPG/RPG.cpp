// RPG.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "header.h"
#include "time.h"

//キャラクターの構造体宣言
struct param
{
	char name[8];
	int life, attack, defense;
};

//main関数
int main(void)
{
	struct param you1 = { "You", 100, 100, 100 };
	struct param you2 = { "You", 200, 100, 100 };
	struct param you3 = { "You", 300, 100, 100 };
	struct param enemy1 = { "Devil", 200, 100, 50 };
	struct param enemy2 = { "Demon", 500, 100, 50 };
	struct param enemy3 = { "Satan", 1000, 100, 50 };

	//STAGE1
	printf("%s が現れた!\n", enemy1.name);
	for (; ; )
	{
		int command;
		FILE* fp;
		time_t timer;
		struct tm *local;
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
		printf("\n");
		printf("%s: ライフ=%d, 攻撃力=%d, 防御力=%d\n", you1.name, you1.life, you1.attack, you1.defense);
		printf("%s: ライフ=%d, 攻撃力=%d, 防御力=%d\n", enemy1.name, enemy1.life, enemy1.attack, enemy1.defense);
		printf("(0) 攻撃\n(1) 力を溜める\n(2) 回復\n");
		printf("Command:");
		scanf("%d", &command);
		act(&you1, &enemy1, command);

		if (enemy1.life <= 0)
		{
			printf("\n");
			printf("%s は倒れた!\n", enemy1.name);
			printf("%s のライフが100増えた!\n", you1.name);
			printf("\n");
			printf("--------------------------------------------------------\n");
			printf("\n");
			printf("STAGE1 CLEAR!!\n");
			printf("\n");
			printf("--------------------------------------------------------\n");

			fp = fopen("result.txt","a");
			if (fp == NULL) {
				printf("ファイルを開けませんでした\n");
				exit(1);
			}
			else {
				fputs("STAGE1 CLEAR\n", fp);

				//現在時刻の取得
				timer = time(NULL);
				//自身の時刻に変換
				local = localtime(&timer);

				year = local->tm_year + 1900;
				month = local->tm_mon + 1;
				day = local->tm_mday;
				hour = local->tm_hour;
				minute = local->tm_min;
				second = local->tm_sec;

				fprintf(fp,"%d年%d月%d日 %d時%d分%d秒保存\n", year, month, day, hour, minute, second);
				printf("戦闘結果を保存しました\n");
			}
			fclose(fp);

			//STAGE2
			printf("%s が現れた!\n", enemy2.name);
			for (; ; )
			{
				printf("\n");
				printf("%s: ライフ=%d, 攻撃力=%d, 防御力=%d\n", you2.name, you2.life, you2.attack, you2.defense);
				printf("%s: ライフ=%d, 攻撃力=%d, 防御力=%d\n", enemy2.name, enemy2.life, enemy2.attack, enemy2.defense);
				printf("(0) 攻撃\n(1) 力を溜める\n(2) 回復\n");
				printf("Command:");
				scanf("%d", &command);
				act(&you2, &enemy2, command);
				if (enemy2.life <= 0)
				{
					printf("\n");
					printf("%s は倒れた!\n", enemy2.name);
					printf("%s のライフが100増えた!\n", you2.name);
					printf("\n");
					printf("--------------------------------------------------------\n");
					printf("\n");
					printf("STAGE2 CLEAR!!\n");
					printf("\n");
					printf("--------------------------------------------------------\n");

					fp = fopen("result.txt", "a");
					if (fp == NULL) {
						printf("ファイルを開けませんでした\n");
						exit(1);
					}
					else {
						fputs("STAGE2 CLEAR\n", fp);

						timer = time(NULL);
						local = localtime(&timer);

						year = local->tm_year + 1900;
						month = local->tm_mon + 1;
						day = local->tm_mday;
						hour = local->tm_hour;
						minute = local->tm_min;
						second = local->tm_sec;

						fprintf(fp, "%d年%d月%d日 %d時%d分%d秒保存\n", year, month, day, hour, minute, second);
						printf("戦闘結果を保存しました\n");
					}
					fclose(fp);

					//FINAL STAGE
					printf("%s が現れた!\n", enemy3.name);
					for (; ; )
					{
						printf("\n");
						printf("%s: ライフ=%d, 攻撃力=%d, 防御力=%d\n", you3.name, you3.life, you3.attack, you3.defense);
						printf("%s: ライフ=%d, 攻撃力=%d, 防御力=%d\n", enemy3.name, enemy3.life, enemy3.attack, enemy3.defense);
						printf("(0) 攻撃\n(1) 力を溜める\n(2) 回復\n");
						printf("Command:");
						scanf("%d", &command);
						act(&you3, &enemy3, command);
						if (enemy3.life <= 0)
						{
							printf("\n");
							printf("%s は倒れた!\n", enemy3.name);
							printf("\n");
							printf("--------------------------------------------------------\n");
							printf("\n");
							printf("FINAL STAGE CLEAR!!\n");
							printf("\n");
							printf("--------------------------------------------------------\n");

							fp = fopen("result.txt", "a");
							if (fp == NULL) {
								printf("ファイルを開けませんでした\n");
								exit(1);
							}
							else {
								fputs("FINAL STAGE CLEAR\n", fp);

								timer = time(NULL);
								local = localtime(&timer);

								year = local->tm_year + 1900;
								month = local->tm_mon + 1;
								day = local->tm_mday;
								hour = local->tm_hour;
								minute = local->tm_min;
								second = local->tm_sec;

								fprintf(fp, "%d年%d月%d日 %d時%d分%d秒保存\n", year, month, day, hour, minute, second);
								fputs("\n", fp);
								printf("戦闘結果を保存しました\n");
							}
							fclose(fp);

							return 0;
						}
						act(&enemy3, &you3, rand() % 3);
						if (you3.life <= 0)
						{
							printf("\n");
							printf("%s は目の前が真っ暗になった...\n", you3.name);

							fp = fopen("result.txt", "a");
							if (fp == NULL) {
								printf("ファイルを開けませんでした\n");
								exit(1);
							}
							else {
								fputs("FINAL STAGE FAILED\n", fp);

								timer = time(NULL);
								local = localtime(&timer);

								year = local->tm_year + 1900;
								month = local->tm_mon + 1;
								day = local->tm_mday;
								hour = local->tm_hour;
								minute = local->tm_min;
								second = local->tm_sec;

								fprintf(fp, "%d年%d月%d日 %d時%d分%d秒保存\n", year, month, day, hour, minute, second);
								fputs("\n", fp);
								printf("戦闘結果を保存しました\n");
							}
							fclose(fp);

							return 0;
						}
					}
					return 0;
				}
				act(&enemy2, &you2, rand() % 3);
				if (you2.life <= 0)
				{
					printf("\n");
					printf("%s は目の前が真っ暗になった...\n", you2.name);

					fp = fopen("result.txt", "a");
					if (fp == NULL) {
						printf("ファイルを開けませんでした\n");
						exit(1);
					}
					else {
						fputs("STAGE2 FAILED\n", fp);

						timer = time(NULL);
						local = localtime(&timer);

						year = local->tm_year + 1900;
						month = local->tm_mon + 1;
						day = local->tm_mday;
						hour = local->tm_hour;
						minute = local->tm_min;
						second = local->tm_sec;

						fprintf(fp, "%d年%d月%d日 %d時%d分%d秒保存\n", year, month, day, hour, minute, second);
						fputs("\n", fp);
						printf("戦闘結果を保存しました\n");
					}
					fclose(fp);

					return 0;
				}
			}
			return 0;
		}
		act(&enemy1, &you1, rand() % 3);
		if (you1.life <= 0)
		{
			printf("\n");
			printf("%s は目の前が真っ暗になった...\n", you1.name);

			fp = fopen("result.txt", "a");
			if (fp == NULL) {
				printf("ファイルを開けませんでした\n");
				exit(1);
			}
			else {
				fputs("STAGE1 FAILED\n", fp);

				timer = time(NULL);
				local = localtime(&timer);

				year = local->tm_year + 1900;
				month = local->tm_mon + 1;
				day = local->tm_mday;
				hour = local->tm_hour;
				minute = local->tm_min;
				second = local->tm_sec;

				fprintf(fp, "%d年%d月%d日 %d時%d分%d秒保存\n", year, month, day, hour, minute, second);
				fputs("\n", fp);
				printf("戦闘結果を保存しました\n");
			}
			fclose(fp);

			return 0;
		}
	}
}
