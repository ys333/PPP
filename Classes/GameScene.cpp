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
		/*//�g�O���{�^��
		//OFF��Ԃ�����CCmMenuItemSprite���쐬
		//OFF�̏��
		CCSprite*itemOff = CCSprite::create("button_check_off.png");
		//ON�̏�Ԃ�����CCMenuItemSprite���쐬
		CCSprite*itemOn = CCSprite::create("button_check_on.png");
		//ON��OFF�̃R�[���o�b�N���w�肵��
		//CCMenuItemToggle���쐬
		CCMenuItemToggle*toggleItem =
			CCMenuItemToggle::createWithTarget(
			this,
			menu_selector(GameScene::changeMode),
			menuItemOff,
			menuItemOn, NULL);
		//�\���ʒu�̎w��
		toggleItem->setPosition(ccp(
			toggleItem->getActionByTag().width / 2,
			winSize.height - toggleItem->getContentSize().height / 2));
		//CCMenuItemToggle����CCMenu���쐬
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

//�����_���Ȑ��𐶐�
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
	
	// �摜�̎��ۂ̑傫��
	CCRect spriteRect = CCRectMake(0, 0, 80, 80);
	// 9�ɋ�؂鎞�̓����̑傫��
	CCRect cppInsents = CCRectMake(12, 12, 56, 56);
	CCScale9Sprite* backgroundSprite = CCScale9Sprite::create("button9.png", spriteRect, cppInsents);

	CCLabelTTF* label = CCLabelTTF::create(name, "Arial", 30);
	CCControlButton* button = CCControlButton::create(label, backgroundSprite);
	// �{�^���̑傫�����w��i�w�i�摜�͎����I�ɐL�k����j
	button->setPreferredSize(CCSizeMake(300, 50));
	button->setPosition(pos);
	this->addChild(button, 1, num);


	// �C�x���g�̃R�[���o�b�N���w��
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(GameScene::tapCallback), CCControlEventTouchUpInside);

}


