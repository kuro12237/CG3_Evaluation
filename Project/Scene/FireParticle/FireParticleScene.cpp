#include"FireParticleScene.h"

void FireParticleScene::Initialize()
{
	particle_ = make_unique<FireParticle>();
	particle_->Initialize({0,0,0});
	MainCamera::Initiaize();
}

void FireParticleScene::Update(GameManager* Scene)
{
	if (Input::PushKeyPressed(DIK_N))
	{
		Scene->ChangeState(new PlaneParticleScene);
		return;
	}
	particle_->Update();
	MainCamera::Update();
	viewProjection_.UpdateMatrix();
	viewProjection_ = MainCamera::GetViewProjection();
}

void FireParticleScene::Back2dSpriteDraw()
{
}

void FireParticleScene::Object3dDraw()
{
	particle_->Draw(viewProjection_);
}

void FireParticleScene::Flont2dSpriteDraw()
{
}
