#include "Planeparticles.h"

void PlaneParticles::Initialize()
{
	particle_ = make_unique<Particle>();
	texHandle_ = TextureManager::LoadTexture("uvChecker.png");
	particle_->SetTexHandle(texHandle_);
	particle_->Initialize(new ParticlePlaneState,20);
	particle_->SetBlendMode(BlendNone);

	for (int i = 0; i < 15; i++)
	{
		Particle_param particle{};
		particle.worldTransform_.Initialize();
		particle.worldTransform_.translate.x = particle.worldTransform_.translate.x + i * 0.1f;
		particle.worldTransform_.translate.y = particle.worldTransform_.translate.y + 2;
		particle.worldTransform_.translate.y = particle.worldTransform_.translate.y + i * 0.1f;
		particle_->PushList(particle);
	}
}

void PlaneParticles::Update()
{
	particles_ = particle_->begin();
	for (Particle_param particle : particles_)
	{
		particle_->PushList(particle);

	}
}

void PlaneParticles::Draw(ViewProjection view)
{
	particle_->Draw(view);
}
