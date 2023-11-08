#pragma once
#include"IScene.h"
#include"GameObject/FireParticles/FireParticle.h"
#include"GameManager.h"

class FireParticleScene :public IScene
{
public:
	FireParticleScene() {};
	~FireParticleScene() {};

	void Initialize()override;

	void Update(GameManager* Scene)override;

	void Back2dSpriteDraw()override;
	void Object3dDraw()override;
	void Flont2dSpriteDraw()override;
private:

	unique_ptr<FireParticle>particle_ = nullptr;
	ViewProjection viewProjection_{};
};