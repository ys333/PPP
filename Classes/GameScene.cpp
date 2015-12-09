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

	
	for (int i = 0; i < 16; i++){
	
		
		//�����_���Ȑ��̐���
		int randNum = rand() % 32;
		//�����_���Ȑ���char�^��
		char tablenum[100];
		sprintf(tablenum, "%d", randNum);
		
		//�{�^���̐���
		if (i <= 8)
		{
			MakeButton(tablenum, i + 10, ccp(330 + 100 * (i / 4), 480 - 100 * (i % 4)));

		}
		else if (i >= 8)
		{
			MakeButton(tablenum, i + 10, ccp(330 + 100 * (i / 4), 480 - 100 * (i % 4)));
		}
		
		
	}

	//�X�v���C�g���쐬
	CCSize s = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite* pBar = CCSprite::create("time.png");

	//�^�C�}�[�ɃX�v���C�g���Z�b�g
	CCProgressTimer* pTimer = CCProgressTimer::create(pBar);

	//�ŏ���100�p�[�Z���g
	pTimer->setPercentage(100);

	//�^�C�}�[�̌`�i�_��ɐݒ�j
	pTimer->setType(kCCProgressTimerTypeBar);

	//�o�[�̐L�т�����ix�����ɐݒ�j
	pTimer->setBarChangeRate(ccp(1, 0));

	//�^�C�}�[�̊�_�i�����ɐݒ�j
	pTimer->setMidpoint(ccp(0, 0));

	//�^�C�}�[��z�u
	pTimer->setPosition(ccp(100, 20));
	pTimer->setTag(100);
	addChild(pTimer);

	//�p�[�Z���g�\���p�e�L�X�g
	CCLabelTTF* percentTxt = CCLabelTTF::create("100", "Arial", 35);
	percentTxt->setPosition(ccp(pTimer->getPositionX(), pTimer->getPositionY() + 50));
	percentTxt->setTag(200);
	addChild(percentTxt);

	this->schedule(schedule_selector(GameScene::update), 1.0f);

    return true;

}

//�����_���Ȑ��𐶐�
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
	
	// �摜�̎��ۂ̑傫��
	CCRect spriteRect = CCRectMake(0, 0, 80, 80);
	// 9�ɋ�؂鎞�̓����̑傫��
	CCRect cppInsents = CCRectMake(12, 12, 56, 56);
	CCScale9Sprite* backgroundSprite = CCScale9Sprite::create("button9.png", spriteRect, cppInsents);

	CCLabelTTF* label = CCLabelTTF::create(name, "Helvetica", 30);
	CCControlButton* button = CCControlButton::create(label, backgroundSprite);
	// �{�^���̑傫�����w��i�w�i�摜�͎����I�ɐL�k����j
	button->setPreferredSize(CCSizeMake(100, 100));
	button->setPosition(pos);
	this->addChild(button, 1, num);


	// �C�x���g�̃R�[���o�b�N���w��
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(GameScene::tapCallback), CCControlEventTouchUpInside);

}

void GameScene::update(float dt)
{
	//1�p�[�Z���g���ǉ�
	CCProgressTimer* pTimer = (CCProgressTimer*)this->getChildByTag(100);
	int percent = pTimer->getPercentage();
	pTimer->setPercentage(percent - 1);

	//�e�L�X�g�̍X�V
	CCLabelTTF* percentTxt = (CCLabelTTF*)this->getChildByTag(200);
	percentTxt->setString(CCString::createWithFormat("%d", percent)->getCString());

	//100�ɂȂ������~
	if (percent <= 0){
		this->unscheduleUpdate();
		percentTxt->setString("GAME OVER");
	}
}



