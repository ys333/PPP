#include "GameScene.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
USING_NS_CC;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
		/*//トグルボタン
		//OFF状態を示すCCmMenuItemSpriteを作成
		//OFFの状態
		CCSprite*itemOff = CCSprite::create("button_check_off.png");
		//ONの状態を示すCCMenuItemSpriteを作成
		CCSprite*itemOn = CCSprite::create("button_check_on.png");
		//ONとOFFのコールバックを指定して
		//CCMenuItemToggleを作成
		CCMenuItemToggle*toggleItem =
			CCMenuItemToggle::createWithTarget(
			this,
			menu_selector(GameScene::changeMode),
			menuItemOff,
			menuItemOn, NULL);
		//表示位置の指定
		toggleItem->setPosition(ccp(
			toggleItem->getActionByTag().width / 2,
			winSize.height - toggleItem->getContentSize().height / 2));
		//CCMenuItemToggleからCCMenuを作成
		CCMenu*toggleMenu = CCMenu::create(toggleItem, NULL);*/

		return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	char* tableNumber[] =
	{
		"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"
	};

	for (int i = 0; i < 1; i++)
	{
		srand((unsigned int)time(NULL));

		int randNum = rand() % 16;

		MakeButton(tableNumber[randNum], i + 10, ccp(250 + 460 * (i / 10), 600 - 60 * (i % 10)));
	}


    return true;

}

//ランダムな数を生成
void GameScene::randNumber(int randNum)
{
	srand((unsigned int)time(NULL));

	int randNum = rand() % 16;
}

void GameScene::tapCallback(CCObject* pSender, CCControlEvent event)
{
	/*CCSprite* spr = (CCSprite*)pSender;
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
	CCLOG("kita:%d", tag);*/
}

void GameScene::MakeButton(char*name, int num, CCPoint pos)
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
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(GameScene::tapCallback), CCControlEventTouchUpInside);

}


