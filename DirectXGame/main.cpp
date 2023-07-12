﻿#include "WinApp.h"
#include "DirectXCommon.h"
#include "Audio.h"
#include "GameScene.h"
#include "LightGroup.h"
#include "ParticleManager.h"
//#include <fbxsdk.h>
#include "FbxLoader.h"
#include "PostEffect.h"
//#include "FPSControll.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 汎用機能
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	GameScene* gameScene = nullptr;
	PostEffect* postEffect = nullptr;
	//FPSControll* fpsControll = nullptr;
	//FbxManager* fbxManager = FbxManager::Create();

	// ゲームウィンドウの作成
	win = new WinApp();
	win->CreateGameWindow();

	//DirectX初期化処理
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(win);

#pragma region 汎用機能初期化
	// 入力の初期化
	input = Input::GetInstance();
	if (!input->Initialize(win->GetInstance(), win->GetHwnd())) {
		assert(0);
		return 1;
	}
	// オーディオの初期化
	audio = new Audio();
	if (!audio->Initialize()) {
		assert(0);
		return 1;
	}
	// スプライト静的初期化
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height)) {
		assert(0);
		return 1;
	}
	// ライト静的初期化
	LightGroup::StaticInitialize(dxCommon->GetDevice());
	// パーティクルマネージャ初期化
	ParticleManager::GetInstance()->Initialize(dxCommon->GetDevice());

	//FBXローダー初期化
	FbxLoader::GetInstance()->Initialize(dxCommon->GetDevice());

	//ポストエフェクトの初期化
	postEffect = new PostEffect(100, { 0,0 }, { 500.0f,500.0f }, { 1,1,1,1 }, { 0.0f,0.0f });
	postEffect->Initialize(dxCommon->GetDevice());

	//fpsControll = new FPSControll();

#pragma endregion

	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize(dxCommon, input, audio);

	// メインループ
	while (true)
	{
		// メッセージ処理
		if (win->ProcessMessage()) { break; }

		//fpsControll->PreFPSSet60();

		// 入力関連の毎フレーム処理
		input->Update();
		// ゲームシーンの毎フレーム処理
		gameScene->Update();

		//レンダーテクスチャの描画
		postEffect->PreDrawScene(dxCommon->GetCommandList());

		gameScene->Draw();

		postEffect->PostDrawScene(dxCommon->GetCommandList());

		// 描画開始
		dxCommon->PreDraw();

		//ポストエフェクトの描画
		postEffect->Draw(dxCommon->GetCommandList());

		// 描画終了
		dxCommon->PostDraw();

		//fpsControll->PostFPSSet60();
	}
	// 各種解放
	safe_delete(gameScene);
	safe_delete(audio);
	safe_delete(dxCommon);
	//safe_delete(fpsControll);
	FbxLoader::GetInstance()->Finalize();
	delete postEffect;

	// ゲームウィンドウの破棄
	win->TerminateGameWindow();
	safe_delete(win);

	return 0;
}