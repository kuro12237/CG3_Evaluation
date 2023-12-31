#pragma once
#include"Cleyera.h"
#include"IScene.h"
#include"DebugScene.h"
#include"PlaneParticle/PlaneParticleScene.h"
#include"../DebugTools/Camera/DebugCamera.h"

class GameManager
{
public:

	GameManager();
	~GameManager();

    void Run();
    void ChangeState(IScene *newScene);

private:

	IScene* Scene_ = nullptr;

};

