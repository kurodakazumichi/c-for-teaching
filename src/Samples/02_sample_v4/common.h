#pragma once
//-----------------------------------------------------------------------------
// �񋓌^�̒�`���܂Ƃ߂��t�@�C��
//-----------------------------------------------------------------------------

/// <summary>
/// TRUE�AFALSE���`
/// </summary>
typedef enum {
	FALSE = 0,
	TRUE  = 1,
} BOOL;

/// <summary>
/// ����񂯂�̎�(�O�[�A�`���L�A�p�[)���`(�萔���X�g)
/// </summary>
typedef enum {
	E_HAND_UNKNOWN = -1, // �s��(�񋓌^�̐擪)

	E_HAND_G, // �O�[
	E_HAND_T, // �`���L
	E_HAND_P, // �p�[

	E_HAND_COUNT,    // �񋓌^�̍Ō�̗v�f(�`�F�b�N�p)
} HAND;

/// <summary>
/// ���s�̃p�^�[�����`(�萔���X�g)
/// </summary>
typedef enum
{
	E_RESULT_UNKNOWN = -1, // �Ȃ�
	E_RESULT_WIN,          // ����
	E_RESULT_LOSE,         // ����
	E_RESULT_DRAW,         // ������
} RESULT;