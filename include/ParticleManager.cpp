#include "ParticleManager.h"
#include "ParticleBase.h"
ParticleManager* ParticleManager::GetInstance() {
	static ParticleManager instance;
	return &instance;
}

void ParticleManager::Update()
{
	DeleteParticles();

	for (auto& it : m_particles) {
		it->Update();
	}
}

void ParticleManager::Draw()
{
	
	for (auto& it : m_particles) {
		it->Draw();
	}
}

void ParticleManager::AddParticle(ParticleBase* particle)
{
	m_particles.emplace_front(particle);
}

void ParticleManager::DeleteParticles()
{
	// 削除対象の要素番号が入る
	//std::vector<size_t> deleteIndexs;
	//// 削除する要素を探す
	//for (size_t i = 0; i < m_particles.; i++) {
	//	if (m_particles[i]->IsDelete() == true) {
	//		deleteIndexs.emplace_back(i);
	//	}
	//}

	auto iter = m_particles.begin();
	while (iter != m_particles.end())
	{
		if ((*iter)->IsDelete() == true) {
			iter = m_particles.erase(iter);
		}
		else {
			iter++;
		}
	}

	// 削除する要素がある場合
	//if (deleteIndexs.empty() == false) {
	//	if (m_particles.size() == deleteIndexs.size()) {
	//		// すべて削除する
	//		m_particles.clear();
	//	}
	//	else {
	//		for (const auto& it : deleteIndexs) {
	//			if (it != m_particles.size()) {
	//				// 削除する要素と最後尾の要素を入れ替えてから削除
	//				std::iter_swap(m_particles.begin() + it, m_particles.end() - 1);
	//			}
	//			m_particles.pop_back();
	//		}
	//	}
	//}
}
