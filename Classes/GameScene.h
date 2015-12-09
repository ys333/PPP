#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class GameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	void GameScene::MakeButton(char* name, int num, CCPoint pos);
	
    
	void GameScene::tapCallback(CCObject* pSender, CCControlEvent event);

	void GameScene::update(float dt);



    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
