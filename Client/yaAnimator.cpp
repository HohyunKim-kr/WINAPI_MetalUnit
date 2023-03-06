#include "yaAnimator.h"


namespace ya
{
	Animator::Animator()
		: Component(eComponentType::Animator)
		, mActiveAnimation(nullptr)
		, mSpriteSheet(nullptr)
		, mbLoop(false)
	{

	}
	Animator::~Animator()
	{
		for (auto animation : mAnimations)
		{
			delete animation.second;
			animation.second = nullptr;
		}
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mbLoop && mActiveAnimation->IsComplete())
			{
				mActiveAnimation->Reset();
			}
		}
	}
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(hdc);
		}
	}
	void Animator::Release()
	{
	}
	void Animator::CreateAnimation(const std::wstring& name
		, Image* sheet, Vector2 leftTop
		, UINT coulmn, UINT row, UINT spriteLength
		, Vector2 offset, float duration)
	{
		Animation* animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->Create(sheet, leftTop, coulmn, row, spriteLength, offset, duration);
		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}
	void Animator::CreateAnimations()
	{
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter
			= mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	void Animator::Play(const std::wstring& name, bool loop)
	{
		mActiveAnimation = FindAnimation(name);
		mbLoop = loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		return nullptr;
	}
	//std::function<void>& Animator::GetStartEvent(const std::wstring& name)
	//{
	//	// TODO: ���⿡ return ���� �����մϴ�.
	//}
	//std::function<void>& Animator::GetCompleteEvent(const std::wstring& name)
	//{
	//	// TODO: ���⿡ return ���� �����մϴ�.

	//	return ;
	//}
	//std::function<void>& Animator::GetEndEvent(const std::wstring& name)
	//{
	//	// TODO: ���⿡ return ���� �����մϴ�.
	//}
}