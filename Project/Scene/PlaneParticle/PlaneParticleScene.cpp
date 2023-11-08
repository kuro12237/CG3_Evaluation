#include "PlaneParticleScene.h"

void PlaneParticleScene::Initialize()
{
	Grid* debugGrid = new Grid();
	debugGrid->Initialize();
	DebugTools::addCommand(debugGrid, "DebugCamera");
	viewProjection.Initialize();
	MainCamera::Initiaize();
	particle_ = make_unique<PlaneParticles>();
	particle_->Initialize();


}

void PlaneParticleScene::Update(GameManager* Scene)
{
	Scene;
	if (Input::PushKeyPressed(DIK_N))
	{
		Scene->ChangeState(new FireParticleScene);
		return;
	}

	DebugTools::UpdateExecute(0);

	particle_->Update();

	viewProjection.UpdateMatrix();
	MainCamera::Update();
	viewProjection = MainCamera::GetViewProjection();

	viewProjection = DebugTools::ConvertViewProjection(viewProjection);
}

void PlaneParticleScene::Back2dSpriteDraw()
{
}

void PlaneParticleScene::Object3dDraw()
{
	DebugTools::DrawExecute(0);
	particle_->Draw(viewProjection);
}

void PlaneParticleScene::Flont2dSpriteDraw()
{
}
