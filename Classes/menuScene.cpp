#include "menuScene.h"
#include "GameScene.h"


USING_NS_CC;

CCScene* menuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    menuScene *layer = menuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool menuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	char* titleName[] =
	{
		"GameStart",
	
	};
	for (int i = 0; i < 1; i++)
	{
		MakeButton(titleName[i], i + 10, ccp(250 + 460 * (i / 10), 600 - 60 * (i % 10)));
	}
	
	
    return true;
}

void menuScene::tapCallback(CCObject* pSender, CCControlEvent event)
{
	CCSprite* spr = (CCSprite*)pSender;
	int tag = spr->getTag();
	CCScene* nextScene = NULL;
	switch (tag)
	{
	case	10:
		nextScene = GameScene::scene();
		break;
	
	default:
		return;
	}
	CCScene* pScene = CCTransitionFade::create(0.5f, nextScene);
	CCDirector::sharedDirector()->replaceScene(pScene);
	CCLOG("kita:%d", tag);
}

void menuScene::MakeButton(char* name, int num, CCPoint pos)
{
	// 画像の実際の大きさ
	CCRect spriteRect = CCRectMake(0, 0, 80, 80);
	// 9つに区切る時の内側の大きさ
	CCRect cppInsents = CCRectMake(12, 12, 56, 56);
	CCScale9Sprite* backgroundSprite = CCScale9Sprite::create("button9.png", spriteRect, cppInsents);

	CCLabelTTF* label = CCLabelTTF::create(name, "Arial", 30);
	CCControlButton* button = CCControlButton::create(label, backgroundSprite);
	// ボタンの大きさを指定（背景画像は自動的に伸縮する）
	button->setPreferredSize(CCSizeMake(300, 50));
	button->setPosition(pos);
	this->addChild(button, 1, num);

		
	// イベントのコールバックを指定
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(menuScene::tapCallback), CCControlEventTouchUpInside);
		
}


