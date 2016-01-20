#include "GameOverScene.h"

USING_NS_CC;

CCScene* GameOverScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameOverScene *layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//スコアの抽出
	int tempScore = CCUserDefault::sharedUserDefault()
		->getIntegerForKey("tempScore", 0);

	char GameScore[200];
	sprintf(GameScore, "%d", tempScore);

	CCLabelTTF *LastScore = CCLabelTTF::create(GameScore, "Arial", 100);
	LastScore->setPosition(CCPointMake(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(LastScore);

    return true;
}


