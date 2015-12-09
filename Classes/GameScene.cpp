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

	
	for (int i = 0; i < 16; i++){
	
		
		//ランダムな数の生成
		int randNum = rand() % 32;
		//ランダムな数をchar型に
		char tablenum[100];
		sprintf(tablenum, "%d", randNum);
		
		//ボタンの生成
		if (i <= 8)
		{
			MakeButton(tablenum, i + 10, ccp(330 + 100 * (i / 4), 480 - 100 * (i % 4)));

		}
		else if (i >= 8)
		{
			MakeButton(tablenum, i + 10, ccp(330 + 100 * (i / 4), 480 - 100 * (i % 4)));
		}
		
		
	}

	//スプライトを作成
	CCSize s = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite* pBar = CCSprite::create("time.png");

	//タイマーにスプライトをセット
	CCProgressTimer* pTimer = CCProgressTimer::create(pBar);

	//最初は100パーセント
	pTimer->setPercentage(100);

	//タイマーの形（棒状に設定）
	pTimer->setType(kCCProgressTimerTypeBar);

	//バーの伸びる方向（x方向に設定）
	pTimer->setBarChangeRate(ccp(1, 0));

	//タイマーの基準点（左側に設定）
	pTimer->setMidpoint(ccp(0, 0));

	//タイマーを配置
	pTimer->setPosition(ccp(100, 20));
	pTimer->setTag(100);
	addChild(pTimer);

	//パーセント表示用テキスト
	CCLabelTTF* percentTxt = CCLabelTTF::create("100", "Arial", 35);
	percentTxt->setPosition(ccp(pTimer->getPositionX(), pTimer->getPositionY() + 50));
	percentTxt->setTag(200);
	addChild(percentTxt);

	this->schedule(schedule_selector(GameScene::update), 1.0f);

    return true;

}

//ランダムな数を生成
/*void GameScene::randNumber(int randNum)
{
	srand((unsigned int)time(NULL));

	int randNum = rand() % 16;
}*/

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

void GameScene::MakeButton(char* name, int num, CCPoint pos)
{
	
	// 画像の実際の大きさ
	CCRect spriteRect = CCRectMake(0, 0, 80, 80);
	// 9つに区切る時の内側の大きさ
	CCRect cppInsents = CCRectMake(12, 12, 56, 56);
	CCScale9Sprite* backgroundSprite = CCScale9Sprite::create("button9.png", spriteRect, cppInsents);

	CCLabelTTF* label = CCLabelTTF::create(name, "Helvetica", 30);
	CCControlButton* button = CCControlButton::create(label, backgroundSprite);
	// ボタンの大きさを指定（背景画像は自動的に伸縮する）
	button->setPreferredSize(CCSizeMake(100, 100));
	button->setPosition(pos);
	this->addChild(button, 1, num);


	// イベントのコールバックを指定
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(GameScene::tapCallback), CCControlEventTouchUpInside);

}

void GameScene::update(float dt)
{
	//1パーセントずつ追加
	CCProgressTimer* pTimer = (CCProgressTimer*)this->getChildByTag(100);
	int percent = pTimer->getPercentage();
	pTimer->setPercentage(percent - 1);

	//テキストの更新
	CCLabelTTF* percentTxt = (CCLabelTTF*)this->getChildByTag(200);
	percentTxt->setString(CCString::createWithFormat("%d", percent)->getCString());

	//100になったら停止
	if (percent <= 0){
		this->unscheduleUpdate();
		percentTxt->setString("GAME OVER");
	}
}



