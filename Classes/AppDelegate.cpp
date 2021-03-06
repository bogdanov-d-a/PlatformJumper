#include "AppDelegate.h"
#include "GameScene.h"
#include "Json\JsonUtils.h"

USING_NS_CC;
using namespace json11;

AppDelegate::AppDelegate()
{}

AppDelegate::~AppDelegate() 
{}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

	GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
	return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
		glview = GLViewImpl::create("Platform Jumper");
		director->setOpenGLView(glview);
	}

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	// Set the design resolution
	cocos2d::Size windowSize(800, 480);
	glview->setDesignResolutionSize(windowSize.width, windowSize.height, ResolutionPolicy::NO_BORDER);
	glview->setFrameSize(windowSize.width, windowSize.height);

	register_all_packages();

	// create a scene. it's an autorelease object
	auto scene = GameScene::createScene(JsonUtils::LoadFromFile("start.json")["map"].string_value());
	if (!scene)
	{
		MessageBox("Can't create scene", "Fatal error");
		return false;
	}

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
