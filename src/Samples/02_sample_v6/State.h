#pragma once
//-----------------------------------------------------------------------------
// State.h
//
// �Q�[���̏�Ԃ�ێ����Ă���State�\���̂Ɋւ���錾
//-----------------------------------------------------------------------------
#include "common.h"

// �w�b�_�ł�_State�Ƃ����\���̂������Ƃ��������`����̂݁B
// ���g�Ɋւ�������`���Ă��Ȃ��̂ŁA���ۂɎg���Ƃ���
// struct _State* state;�̂悤�Ƀ|�C���^�Ŏg�����ƂɂȂ�B
struct _State;

// struct�̒�`���ƕϐ���`����ۂɂ�������
// struct _State* state; �Ə����Ȃ��Ƃ����Ȃ���
// struct _State �� State �Ƃ������O�Œ�`���Ă���(�ʖ���`�Ƃ�����)��
// State* state; �Ə�����悤�ɂȂ�̂�typedef���Ă���B
typedef struct _State State;

//-----------------------------------------------------------------------------
// State���������߂̊֐��v���g�^�C�v�錾

// State�\���̂̃C���X�^���X�𐶐����ĕԂ�
State* State_makeInstance(void);

// State�\���̃C���X�^���X���������
void State_freeInstance(State* this);

// State�\���̂̃����o�����Z�b�g����
void State_reset(State* this);

// State.inGame�̃A�N�Z�b�T
BOOL State_getInGame(State* this);
void State_setInGame(State* this, BOOL value);

// State.player�̃A�N�Z�b�T
HAND State_getPlayer(State* this);
void State_setPlayer(State* this, HAND value);

// State.cpu�̃A�N�Z�b�T
HAND State_getCpu(State* this);
void State_setCpu(State* this, HAND value);

// State.result�̃A�N�Z�b�T
RESULT State_getResult(State* this);
void State_setResult(State* this, HAND value);