#pragma once

#include "stdio.h"
#include "stdafx.h"

//キャラクターの構造体宣言
struct param
{
	char name[8];
	int life, attack, defense;
};

//コマンドによるact関数
void act(struct param* actor, struct param* target, int command)
{
	int point;
	switch (command)
	{
	case 0:
		point = actor->attack - target->defense;
		target->life -= point;
		printf("\n");
		printf("%s の攻撃! %s は %d ダメージ受けた!\n", actor->name, target->name, point);
		printf("\n");
		break;
	case 1:
		point = 20;
		actor->attack += point;
		printf("\n");
		printf("%s は力を溜めた! %s の攻撃力が %d アップした!\n", actor->name, actor->name, point);
		printf("\n");
		break;
	case 2:
		point = 50;
		actor->life += point;
		printf("\n");
		printf("%s は回復した! %s のライフが %d 増えた!\n", actor->name, actor->name, point);
		printf("\n");
		break;
	}
}