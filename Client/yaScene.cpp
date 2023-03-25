#include "yaScene.h"
#include "yaSceneManager.h"

namespace ya
{
	Scene::Scene()
	{
		mLayers.reserve(5);
		mLayers.resize((UINT)eLayerType::End);
	}
	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{
		SceneManager::SetActiveScene(this);
		//*(lyaer)
		// for (Layer& layer : mLayers)
		// {
		// 	layer.Initialize();
		// }
	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		std::vector<GameObject*> deleteGameObject = {};
		for (Layer& layer : mLayers)
		{
			std::vector<GameObject*>& gameObjects = 
				layer.GetGameObjects();

			for (std::vector<GameObject*>::iterator iter = gameObjects.begin()
				; iter != gameObjects.end()
				; )
			{
				if ((*iter)->GetState() == GameObject::eState::Death)
				{
					deleteGameObject.push_back((*iter));
					iter = gameObjects.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}
		
		for (GameObject* deathObj : deleteGameObject)
		{
			delete deathObj;
			deathObj = nullptr;
		}
	}
	void Scene::Release()
	{

	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
	void Scene::AddGameObeject(GameObject* obj, eLayerType layer)
	{
		mLayers[(UINT)layer].AddGameObject(obj);
	}
	std::vector<GameObject*>& Scene::GetGameObjects(eLayerType layer)
	{
		return mLayers[(UINT)layer].GetGameObjects();
	}
}
