#pragma once

#include "stdio.h"
#include "stdafx.h"

//�L�����N�^�[�̍\���̐錾
struct param
{
	char name[8];
	int life, attack, defense;
};

//�R�}���h�ɂ��act�֐�
void act(struct param* actor, struct param* target, int command)
{
	int point;
	switch (command)
	{
	case 0:
		point = actor->attack - target->defense;
		target->life -= point;
		printf("\n");
		printf("%s �̍U��! %s �� %d �_���[�W�󂯂�!\n", actor->name, target->name, point);
		printf("\n");
		break;
	case 1:
		point = 20;
		actor->attack += point;
		printf("\n");
		printf("%s �͗͂𗭂߂�! %s �̍U���͂� %d �A�b�v����!\n", actor->name, actor->name, point);
		printf("\n");
		break;
	case 2:
		point = 50;
		actor->life += point;
		printf("\n");
		printf("%s �͉񕜂���! %s �̃��C�t�� %d ������!\n", actor->name, actor->name, point);
		printf("\n");
		break;
	}
}