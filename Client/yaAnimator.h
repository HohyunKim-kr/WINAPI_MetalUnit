#pragma once
#include "yaComponent.h"
#include "yaAnimation.h"
#include "yaImage.h"

namespace ya
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			// void(*name)(int, int);
			std::function<void()>mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;

			//mStartEvent();
			//mStartEvent = test;
		};

		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void CreateAnimation();  // 파일이 합쳐져 있는 형식일 때 한줄씩 사용하도록
		void CreateAnimations(); // 파일별로 나누어진 것들

		Animation* FindAnimation(const std::wstring& name);
		void Play(const std::wstring& name, bool loop);
		
		Events* FindEvents(const std::wstring& name);
		std::function<void>& GetStartEvent(const std::wstring& name);
		std::function<void>& GetCompleteEvent(const std::wstring& name);
		std::function<void>& GetEndEvent(const std::wstring& name);


	private:
		std::map<std::wstring, Animation*> mAnimation;
		std::map<std::wstring, Events*> mEvents;
		Animation* mActiveAnimation;
		Image* mSpriteSheet;
	};
}


