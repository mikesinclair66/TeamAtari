#pragma once
#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include "button.hpp"
#include "component.hpp"

using namespace coordinates;

namespace interact {
	class Scrollbar : public Component, public MouseListener {

	protected:
		float ratio, offsetRatio;
		Button* scrollBtn;
		float getBarSize(float);
		float getBarOffset(float);

	public:
		Scrollbar();
		virtual void listen(float, float) override;
		bool requestClick() override;
		void requestRelease() override;
		void draw(RenderWindow&);
		void setScrollColors(Color, Color);
		void setRatio(float);
		void setOffsetRatio(float);
		virtual void updateOffsetRatio(float, float);
	};

	class ScrollbarVertical : public Scrollbar {
	public:
		ScrollbarVertical();
		void listen(float, float) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
		void updateOffsetRatio(float, float) override;
	};

	class ScrollbarHorizontal : public Scrollbar {
	public:
		ScrollbarHorizontal();
		void listen(float, float) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
		void updateOffsetRatio(float, float) override;
	};
}

#endif