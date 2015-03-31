
#include "GameScreen.hpp"
#include "Engine.hpp"
#include <iostream>

Engine::Engine(){
	_currentScreen = new GameScreen();
	_currentScreen->init();
}

Engine::~Engine(){

}

void Engine::update(double currentTime){
	double dt = currentTime - _prevTime;
	_prevTime = currentTime;

	if (_nextScreen != 0) {
		_currentScreen = _nextScreen;
		_nextScreen = 0;
		_currentScreen->init();
	}

	_currentScreen->update(dt);
}

void Engine::draw(){
	_currentScreen->draw();
}

void Engine::setNextScreen(Screen *next){
	_nextScreen = next;
}