#include "GameScene.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
USING_NS_CC;

int tableNum[16];
int sumNum;
int randSum;
int clearCount ;
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

		return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//�N���A�񐔕\��
	
	//
	

	for (int i = 0; i < 16; i++){


		//�����_���Ȑ��̐���
		int randNum = rand() % 32;
	
		tableNum[i] = randNum;

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
	MakeButton("skip", 100,ccp(100,100));

	int randA, randB, randC;

	for (int j = 0; j < 3;j++)
	{
		int randTable = rand() % 15 + 1;

		switch (j)
		{
		case 0:
			randA = tableNum[randTable];
			break;
		case 1:
			randB = tableNum[randTable];
			break;
		case 2:
			randC = tableNum[randTable];
			break;

		}
	}
	//�������v�l�̕\��
	char sum[100];
	
	randSum = randA + randB + randC + sumNum;
	sprintf(sum, "%d", randSum);
	CCLabelTTF *text = CCLabelTTF::create(sum, "Arial",36);
	text->setPosition(CCPointMake(100, 400));
	this->addChild(text);
	


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
	pTimer->setPosition(ccp(400, 20));
	pTimer->setTag(100);
	addChild(pTimer);

	//�p�[�Z���g�\���p�e�L�X�g
	CCLabelTTF* percentTxt = CCLabelTTF::create("100", "Arial", 35);
	percentTxt->setPosition(ccp(pTimer->getPositionX(), pTimer->getPositionY() + 50));
	percentTxt->setTag(200);
	addChild(percentTxt);
	//���v�l�\���e�L�X�g
	CCLabelTTF* SumNumber = CCLabelTTF::create("0", "Arial", 35);
	SumNumber->setPosition(CCPointMake(100, 300));
	SumNumber->setTag(300);
	addChild(SumNumber);
	//�N���A�񐔕\��
	CCLabelTTF* clear = CCLabelTTF::create("0", "Arial", 35);
	clear->setPosition(CCPointMake(100, 350));
	clear->setTag(400);
	addChild(clear);

	this->schedule(schedule_selector(GameScene::update), 0.5f);

    return true;

}


void GameScene::tapCallback(CCObject* pSender, CCControlEvent event)
{	
	CCSprite* spr = (CCSprite*)pSender;
	int tag = spr->getTag();
	//CCScene* nextScene = NULL;
	switch (tag)
	{
	case	10:
		sumNum = sumNum + tableNum[0];
		
		break;
	case	11:
		sumNum = sumNum + tableNum[1];
		break;
	case	12:
		sumNum = sumNum + tableNum[2];
		break;
	case	13:
		sumNum = sumNum + tableNum[3];
		break;
	case	14:
		sumNum = sumNum + tableNum[4];
		break;
	case	15:
		sumNum = sumNum + tableNum[5];
		break;
	case	16:
		sumNum = sumNum + tableNum[6];
		break;
	case	17:
		sumNum = sumNum + tableNum[7];
		break;
	case	18:
		sumNum = sumNum + tableNum[8];
		break;
	case	19:
		sumNum = sumNum + tableNum[9];
		break;
	case	20:
		sumNum = sumNum + tableNum[10];
		break;
	case	21:
		sumNum = sumNum + tableNum[11];
		break;
	case	22:
		sumNum = sumNum + tableNum[12];
		break;
	case	23:
		sumNum = sumNum + tableNum[13];
		break;
	case	24:
		sumNum = sumNum + tableNum[14];
		break;
	case	25:
		sumNum = sumNum + tableNum[15];
		break;
	default:
		return;
	}
	
	inputResult(sumNum);
	
	//CCScene* pScene = CCTransitionFade::create(0.5f, nextScene);
	//CCDirector::sharedDirector()->replaceScene(pScene);
	char sumChar[100];
	sprintf(sumChar, "%d",sumNum);
	/*CCLabelTTF *text = CCLabelTTF::create(sumChar, "Arial", 36);
	text->setPosition(CCPointMake(400, 400));
	this->addChild(text);*/
	

	CCLOG("kita:%d", tag);
}
void GameScene::inputResult(int sumNum)
{
		if (randSum == sumNum){
			clearCount = clearCount + 1;
			static int sumNum = 0;
			CCDirector::sharedDirector()->replaceScene(GameScene::scene());
		}
		else if (sumNum >= randSum) {
		} 
	
	//CCLOG("kita:%d", tag);
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
	//�I�����v���X�V
	CCLabelTTF* SumNumber = (CCLabelTTF*)this->getChildByTag(300);
	SumNumber->setString(CCString::createWithFormat("%d", sumNum)->getCString());
	//�N���A�񐔍X�V
	CCLabelTTF* clear = (CCLabelTTF*)this->getChildByTag(400);
	clear->setString(CCString::createWithFormat("%d", clearCount)->getCString());
	//100�ɂȂ������~
	if (percent <= 0){
		this->unscheduleUpdate();
		percentTxt->setString("GAME OVER");
	}
}







