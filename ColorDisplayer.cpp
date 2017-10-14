//
//  ColorDisplayer.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#include "ColorDisplayer.hpp"
#include "ImageManager.hpp"
using namespace std;

ColorDisplayer::ColorDisplayer(Scene* ScenePlaying) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //Sets the current scene playing
    currentScene = ScenePlaying;
    //Add the text for the colors
    colorString = {"YELLOW", "ORANGE", "RED", "BLUE", "GREEN", "PURPLE", "BLACK", "GRAY"};
    
    //Add the color of the text of colorString
    visibleColor = {Color4B::YELLOW, Color4B::ORANGE, Color4B::RED, Color4B::BLUE, Color4B::GREEN, Color4B::MAGENTA, Color4B::MAGENTA, Color4B::BLACK, Color4B::GRAY};
    
    srand(time(NULL));
    int i = rand()%8;
    displayColor = Label::createWithTTF(colorString.at(rand()%8), "fonts/Marker Felt.ttf", 24);
    displayColor->setPosition(visibleSize.width/2 + origin.x, origin.y + visibleSize.height - displayColor->getContentSize().height);
    displayColor->setTextColor(visibleColor.at(i));
    setCorrectColor(i);
    currentScene->addChild(displayColor,6);
}

Label* ColorDisplayer::getDisplayColor() {
    return displayColor;
}

Color4B ColorDisplayer::getCorrectColor() {
    return correctColor;
}

vector<string> ColorDisplayer::getColorString() {
    return colorString;
}

vector<Color4B> ColorDisplayer::getVisibleColors() {
    return visibleColor;
}

void ColorDisplayer::setCorrectColor(int i) {
    
    switch (i) {
        case 0:
            correctColor = Color4B::YELLOW;
            break;
        case 1:
            correctColor = Color4B::ORANGE;
            break;
        case 2:
            correctColor = Color4B::RED;
            break;
        case 3:
            correctColor = Color4B::BLUE;
            break;
        case 4:
            correctColor = Color4B::GREEN;
            break;
        case 5:
            correctColor = Color4B::MAGENTA;
            break;
        case 6:
            correctColor = Color4B::BLACK;
            break;
        case 7:
            correctColor = Color4B::GRAY;
            break;
        default:
            correctColor = Color4B::GRAY;
            break;
    }
}

void ColorDisplayer::changeTextAndColor(Label* displayColor) {
    srand (time(NULL));
    displayColor->setString(colorString.at(rand()%8));
    displayColor->setTextColor(visibleColor.at(rand()%8));
}

