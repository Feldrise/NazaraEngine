// Copyright (C) 2014 Jérôme Leclercq
// This file is part of the "Nazara Engine - Graphics module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_SCENE_HPP
#define NAZARA_SCENE_HPP

#include <Nazara/Prerequesites.hpp>
#include <Nazara/Core/Color.hpp>
#include <Nazara/Core/Updatable.hpp>
#include <Nazara/Graphics/AbstractBackground.hpp>
#include <Nazara/Graphics/AbstractRenderTechnique.hpp>
#include <Nazara/Math/Frustum.hpp>

class NzAbstractRenderQueue;
class NzAbstractViewer;
class NzCamera;
class NzLight;
class NzModel;
class NzNode;
class NzRenderQueue;
class NzSceneNode;
struct NzSceneImpl;

class NAZARA_API NzScene
{
	friend NzCamera;

	public:
		NzScene();
		~NzScene();

		void AddToVisibilityList(NzUpdatable* object);

		void Cull();
		void Draw();

		void EnableBackground(bool enable);

		NzColor GetAmbientColor() const;
		NzAbstractBackground* GetBackground() const;
		NzVector3f GetBackward() const;
		NzVector3f GetDown() const;
		NzVector3f GetForward() const;
		NzVector3f GetLeft() const;
		NzAbstractRenderTechnique* GetRenderTechnique() const;
		NzVector3f GetRight() const;
		NzSceneNode& GetRoot() const;
		NzAbstractViewer* GetViewer() const;
		NzVector3f GetUp() const;
		float GetUpdateTime() const;
		unsigned int GetUpdatePerSecond() const;

		bool IsBackgroundEnabled() const;

		void RegisterForUpdate(NzUpdatable* object);

		void RenderFrame();

		void SetAmbientColor(const NzColor& color);
		void SetBackground(NzAbstractBackground* background);
		void SetRenderTechnique(NzAbstractRenderTechnique* renderTechnique);
		void SetViewer(NzAbstractViewer* viewer);
		void SetViewer(NzAbstractViewer& viewer);
		void SetUpdatePerSecond(unsigned int updatePerSecond);

		void UnregisterForUpdate(NzUpdatable* object);

		void Update();
		void UpdateVisible();

		operator const NzSceneNode&() const;

	private:
		void RecursiveFrustumCull(NzAbstractRenderQueue* renderQueue, const NzFrustumf& frustum, NzNode* node);

		NzSceneImpl* m_impl;
};

#endif // NAZARA_SCENE_HPP
