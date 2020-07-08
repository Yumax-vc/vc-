// RPG.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "header.h"
#include "time.h"

//�L�����N�^�[�̍\���̐錾
struct param
{
	char name[8];
	int life, attack, defense;
};

//main�֐�
int main(void)
{
	struct param you1 = { "You", 100, 100, 100 };
	struct param you2 = { "You", 200, 100, 100 };
	struct param you3 = { "You", 300, 100, 100 };
	struct param enemy1 = { "Devil", 200, 100, 50 };
	struct param enemy2 = { "Demon", 500, 100, 50 };
	struct param enemy3 = { "Satan", 1000, 100, 50 };

	//STAGE1
	printf("%s �����ꂽ!\n", enemy1.name);
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
		printf("%s: ���C�t=%d, �U����=%d, �h���=%d\n", you1.name, you1.life, you1.attack, you1.defense);
		printf("%s: ���C�t=%d, �U����=%d, �h���=%d\n", enemy1.name, enemy1.life, enemy1.attack, enemy1.defense);
		printf("(0) �U��\n(1) �͂𗭂߂�\n(2) ��\n");
		printf("Command:");
		scanf("%d", &command);
		act(&you1, &enemy1, command);

		if (enemy1.life <= 0)
		{
			printf("\n");
			printf("%s �͓|�ꂽ!\n", enemy1.name);
			printf("%s �̃��C�t��100������!\n", you1.name);
			printf("\n");
			printf("--------------------------------------------------------\n");
			printf("\n");
			printf("STAGE1 CLEAR!!\n");
			printf("\n");
			printf("--------------------------------------------------------\n");

			fp = fopen("result.txt","a");
			if (fp == NULL) {
				printf("�t�@�C�����J���܂���ł���\n");
				exit(1);
			}
			else {
				fputs("STAGE1 CLEAR\n", fp);

				//���ݎ����̎擾
				timer = time(NULL);
				//���g�̎����ɕϊ�
				local = localtime(&timer);

				year = local->tm_year + 1900;
				month = local->tm_mon + 1;
				day = local->tm_mday;
				hour = local->tm_hour;
				minute = local->tm_min;
				second = local->tm_sec;

				fprintf(fp,"%d�N%d��%d�� %d��%d��%d�b�ۑ�\n", year, month, day, hour, minute, second);
				printf("�퓬���ʂ�ۑ����܂���\n");
			}
			fclose(fp);

			//STAGE2
			printf("%s �����ꂽ!\n", enemy2.name);
			for (; ; )
			{
				printf("\n");
				printf("%s: ���C�t=%d, �U����=%d, �h���=%d\n", you2.name, you2.life, you2.attack, you2.defense);
				printf("%s: ���C�t=%d, �U����=%d, �h���=%d\n", enemy2.name, enemy2.life, enemy2.attack, enemy2.defense);
				printf("(0) �U��\n(1) �͂𗭂߂�\n(2) ��\n");
				printf("Command:");
				scanf("%d", &command);
				act(&you2, &enemy2, command);
				if (enemy2.life <= 0)
				{
					printf("\n");
					printf("%s �͓|�ꂽ!\n", enemy2.name);
					printf("%s �̃��C�t��100������!\n", you2.name);
					printf("\n");
					printf("--------------------------------------------------------\n");
					printf("\n");
					printf("STAGE2 CLEAR!!\n");
					printf("\n");
					printf("--------------------------------------------------------\n");

					fp = fopen("result.txt", "a");
					if (fp == NULL) {
						printf("�t�@�C�����J���܂���ł���\n");
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

						fprintf(fp, "%d�N%d��%d�� %d��%d��%d�b�ۑ�\n", year, month, day, hour, minute, second);
						printf("�퓬���ʂ�ۑ����܂���\n");
					}
					fclose(fp);

					//FINAL STAGE
					printf("%s �����ꂽ!\n", enemy3.name);
					for (; ; )
					{
						printf("\n");
						printf("%s: ���C�t=%d, �U����=%d, �h���=%d\n", you3.name, you3.life, you3.attack, you3.defense);
						printf("%s: ���C�t=%d, �U����=%d, �h���=%d\n", enemy3.name, enemy3.life, enemy3.attack, enemy3.defense);
						printf("(0) �U��\n(1) �͂𗭂߂�\n(2) ��\n");
						printf("Command:");
						scanf("%d", &command);
						act(&you3, &enemy3, command);
						if (enemy3.life <= 0)
						{
							printf("\n");
							printf("%s �͓|�ꂽ!\n", enemy3.name);
							printf("\n");
							printf("--------------------------------------------------------\n");
							printf("\n");
							printf("FINAL STAGE CLEAR!!\n");
							printf("\n");
							printf("--------------------------------------------------------\n");

							fp = fopen("result.txt", "a");
							if (fp == NULL) {
								printf("�t�@�C�����J���܂���ł���\n");
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

								fprintf(fp, "%d�N%d��%d�� %d��%d��%d�b�ۑ�\n", year, month, day, hour, minute, second);
								fputs("\n", fp);
								printf("�퓬���ʂ�ۑ����܂���\n");
							}
							fclose(fp);

							return 0;
						}
						act(&enemy3, &you3, rand() % 3);
						if (you3.life <= 0)
						{
							printf("\n");
							printf("%s �͖ڂ̑O���^���ÂɂȂ���...\n", you3.name);

							fp = fopen("result.txt", "a");
							if (fp == NULL) {
								printf("�t�@�C�����J���܂���ł���\n");
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

								fprintf(fp, "%d�N%d��%d�� %d��%d��%d�b�ۑ�\n", year, month, day, hour, minute, second);
								fputs("\n", fp);
								printf("�퓬���ʂ�ۑ����܂���\n");
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
					printf("%s �͖ڂ̑O���^���ÂɂȂ���...\n", you2.name);

					fp = fopen("result.txt", "a");
					if (fp == NULL) {
						printf("�t�@�C�����J���܂���ł���\n");
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

						fprintf(fp, "%d�N%d��%d�� %d��%d��%d�b�ۑ�\n", year, month, day, hour, minute, second);
						fputs("\n", fp);
						printf("�퓬���ʂ�ۑ����܂���\n");
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
			printf("%s �͖ڂ̑O���^���ÂɂȂ���...\n", you1.name);

			fp = fopen("result.txt", "a");
			if (fp == NULL) {
				printf("�t�@�C�����J���܂���ł���\n");
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

				fprintf(fp, "%d�N%d��%d�� %d��%d��%d�b�ۑ�\n", year, month, day, hour, minute, second);
				fputs("\n", fp);
				printf("�퓬���ʂ�ۑ����܂���\n");
			}
			fclose(fp);

			return 0;
		}
	}
}
