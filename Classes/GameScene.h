#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
class GameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	void GameScene::MakeButton(char*name, int num, CCPoint pos);
	void GameScene::randNumber(int randNum);
	void GameScene::createTable(int i, char*tableNumber, int rand);
    
	void GameScene::tapCallback(CCObject* pSender, CCControlEvent event);
    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
