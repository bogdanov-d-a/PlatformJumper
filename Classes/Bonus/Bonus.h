#pragma once

#include "cocos2d.h"
#include "ObjectKeeper.h"

class PhysicsEngine;
class BonusPuppeteer;

class Bonus : public cocos2d::Sprite
{
public:
	static Bonus* create(cocos2d::Texture2D *texture, cocos2d::Rect const& imageRect,
		cocos2d::Vec2 const& origin, PhysicsEngine *physEngine);

	bool init(cocos2d::Texture2D *texture, cocos2d::Rect const& imageRect,
		cocos2d::Vec2 const& origin, PhysicsEngine *physEngine);

private:
	ObjectKeeper<BonusPuppeteer> m_puppeteer;
};
