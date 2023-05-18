#pragma once

#include <string>
#include <DirectXMath.h>
#include <vector>
#include <DirectXTex.h>

using namespace DirectX;

struct Node
{
	//���O
	std::string name;
	//���[�J���X�P�[��
	XMVECTOR scaling = { 1,1,1,0 };
	//���[�J����]�p
	XMVECTOR rotation = { 0,0,0,0 };
	//���[�J���ړ�
	XMVECTOR translation = { 0,0,0,1 };
	//���[�J���ό`�s��
	XMMATRIX transform;
	//�O���[�o���ό`�s��
	XMMATRIX gloabalTransform;
	//�e�m�[�h
	Node* parent = nullptr;
};

class Model
{
public:	//�T�u�N���X
	//���_�f�[�^�\����
	struct VertexPosNormalUv
	{
		XMFLOAT3 pos;		//xyz���W
		XMFLOAT3 normal;	//�@���x�N�g��
		XMFLOAT2 uv;		//uv���W
	};

public:
	//�t�����h�N���X
	friend class FbxLoader;

private:
	//���f����
	std::string name;
	//�m�[�h�z��
	std::vector<Node> nodes;
	//���b�V�������m�[�h
	Node* meshNode = nullptr;
	//���_�f�[�^�z��
	std::vector<VertexPosNormalUv> vertices;
	//���_�C���f�b�N�X�z��
	std::vector<unsigned short> indices;
	//�A���r�G���g�W��
	XMFLOAT3 ambient = { 1,1,1 };
	//�f�B�t���[�Y�W��
	XMFLOAT3 diffuse = { 1,1,1 };
	//�e�N�X�`�����^�f�[�^
	TexMetadata metadata = {};
	//�X�N���b�`�C���[�W
	ScratchImage scratchImg = {};
};

