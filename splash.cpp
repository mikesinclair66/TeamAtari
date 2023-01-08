#include "splash.hpp"
#include "component.hpp"
#include "sprite_drawer.hpp"
#include "sprite_button.hpp"
#include "gradient.hpp"

using namespace coordinates;
using namespace interact;

Splash::Splash(int width, int height, string label)
	: ComponentWindow(width, height, label){
    Color pencil(25, 25, 25);

    //background
    Component* c1 = addComponent(width, 550, 0, 0);
    Component* c2 = addComponent(width, 150, 0, 550);
    Component* bgb = addComponent(width, 2, 0, 550);
    initColor(c1, Color(64, 64, 64));
    initColor(c2, Color::White);
    initColor(bgb, pencil);

    //arguments - 1
    TextBox* tb1 = new TextBox();
    tb1->setColor(Color::White);
    tb1->setSize(230, 55);
    tb1->setPosition(190, 80);
    tb1->setString("Shovel ID");
    addBoundary(tb1);

    arg1 = new Cell();
    initComponent(arg1, 230, 55, 75, 100);
    initColor(arg1, Color(218, 230, 90));
    arg1->setTextIndicatorColor(Color(64, 64, 64));
    arg1->textBox->setString("0");
    addMouseListener(arg1);
    addKeyListener(arg1);

    SpriteDrawer* sd = new SpriteDrawer("images/input_shadow.png");
    sd->setPosition(75, 100);
    addBoundary(sd);

    //argument 2
    TextBox* tb2 = new TextBox();
    tb2->setColor(Color::White);
    tb2->setSize(230, 55);
    tb2->setPosition(190, 240);
    tb2->setString("Truck ID");
    addBoundary(tb2);

    Cell* arg2 = new Cell();
    initComponent(arg2, 230, 55, 75, 260);
    initColor(arg2, Color(218, 230, 90));
    arg2->setTextIndicatorColor(Color(64, 64, 64));
    arg2->textBox->setString("1");
    addMouseListener(arg2);
    addKeyListener(arg2);

    SpriteDrawer* sd2 = new SpriteDrawer("images/input_shadow.png");
    sd2->setPosition(75, 260);
    addBoundary(sd2);

    //launch btn
    launchBtn = new Button();
    initComponent(launchBtn, 230, 55, 75, 400);
    launchBtn->setColor(Color::Black);
    launchBtn->setAlternateColor(Color(210, 210, 210));
    launchBtn->updateColor();
    addBoundary(launchBtn);
    addMouseListener(launchBtn);

    Gradient* g = new Gradient();
    g->setColor(Color(255, 255, 255, 75));
    g->setAlternateColor(Color(255, 255, 255, 50));
    g->setSize(230, 27);
    g->setPosition(75, 400);
    addBoundary(g);

    TextBox* tbtn = new TextBox();
    tbtn->setColor(Color(218, 230, 90));
    tbtn->setSize(230, 255);
    tbtn->setPosition(190, 428);
    tbtn->setString("Launch");
    addBoundary(tbtn);

    //check btn
    checkBtn.push_back(new SpriteButton("images/checked.png"));
    checkBtn.push_back(new SpriteButton("images/checked_black.png"));
    checkBtn.push_back(new SpriteButton("images/unchecked.png"));

    TextBox* checkLabel = new TextBox();
    checkLabel->setString("Print map");
    checkLabel->setColor(Color(64, 64, 64));
    checkLabel->setPosition(210, 630);
    addBoundary(checkLabel);

    for (SpriteButton* sb : checkBtn) {
        addMouseListener(sb);
        sb->setPosition(70, 595);
    }

    //shovel units
    for (int i = 0; i < 9; i++) {
        SpriteDrawer* sd = new SpriteDrawer("images/id_" + to_string(i) + ".jpg");
        sd->setPosition(475, 110);
        shovelUnits.push_back(sd);
    }

    SpriteDrawer* teck = new SpriteDrawer("images/teck_blue.png");
    teck->setPosition(width - 250, height - 120);
    addBoundary(teck);

    //exit btn
    exitBtn = new Button();
    initComponent(exitBtn, 75, 75, width - 75, 0);
    exitBtn->setColor(Color(127, 127, 127));
    exitBtn->setAlternateColor(Color(255, 40, 40));
    exitBtn->updateColor();
    addBoundary(exitBtn);
    addMouseListener(exitBtn);

    TextBox* exitText = new TextBox();
    exitText->setString("X");
    exitText->setSize(75, 75);
    exitText->setPosition(width - 37, 40);
    addBoundary(exitText);

    Component* exitBorder1 = addComponent(2, 75, width - 76, 0);
    initColor(exitBorder1, pencil);
    
    Component* exitBorder2 = addComponent(75, 2, width - 75, 74);
    initColor(exitBorder2, pencil);

    //border
    Component* bg1 = addComponent(width, 2, 0, 0);
    initColor(bg1, pencil);
    Component* bg2 = addComponent(2, height, width - 2, 0);
    initColor(bg2, pencil);
    Component* bg3 = addComponent(width, 2, 0, width - 2);
    initColor(bg3, pencil);
    Component* bg4 = addComponent(2, height - 2, 0, 2);
    initColor(bg4, pencil);
}

void Splash::drawElements() {
    ComponentWindow::drawElements();

    //check btn
    checkBtn[checkBtnState]->draw(*window);
    if (checkBtnState != 2) {
        if (hoverState == -1) {
            if (checkBtn[0]->isHovered()) {
                hoverState = checkBtnState;
                checkBtnState = 1;
            }
        }
        else {
            if (!checkBtn[0]->isHovered()) {
                checkBtnState = hoverState;
                hoverState = -1;
            }
        }
    }

    shovelUnits[shovelUnit]->draw(*window);

    //exit btn
    if (exitBtn->isToggled()) {
        window->close();
        exit(0);
    }
}

Component* Splash::addComponent(float width, float height, float x, float y) {
    Component* c = new Component();
    initComponent(c, width, height, x, y);
    return c;
}

void Splash::initComponent(Component* c, float width,
    float height, float x, float y) {
    c->setSize(width, height);
    c->setPosition(x, y);
    addBoundary(c);
}

void Splash::initColor(Component* c, Color color) {
    c->setColor(color);
    c->updateColor();
}

void Splash::pollEvent(Event e) {
    ComponentWindow::pollEvent(e);
    switch (e.type) {
    case Event::MouseButtonPressed:
        if (checkBtn[0]->isHovered()) {
            if (checkBtnState != 2)
                checkBtnState = 2;
            else
                checkBtnState = 1;
        }
        break;
    }

    if (launchBtn->isToggled()) {
        shovelUnit = stoi(arg1->textBox->getString());
    }
}