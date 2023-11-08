#pragma once
#include"IScene.h"
#include"Particle/Particle.h"
#include"DebugTools/DebugTools.h"
#include"DebugTools/Grid/Grid.h"
#include"GameObject/MainCamera/MainCamera.h"
#include"GameObject/PlaneParticles/Planeparticles.h"
#include"FireParticle/FireParticleScene.h"
#include"GameManager.h"

class PlaneParticleScene : public IScene
{
public:
	PlaneParticleScene() {};
	~PlaneParticleScene() {};

	void Initialize()override;

	void Update(GameManager* Scene)override;

	void Back2dSpriteDraw()override;
	void Object3dDraw()override;
	void Flont2dSpriteDraw()override;


private:

	ViewProjection viewProjection{};
	unique_ptr<PlaneParticles>particle_ = nullptr;
};

