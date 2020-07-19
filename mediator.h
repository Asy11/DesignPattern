#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>

class Widget;

class MusicPlayer{
public:
    MusicPlayer* getInstance(){
        if (instance == NULL) 
			instance = new MusicPlayer;
		else 
		    return instance;
    }
    void playMusic(){
        std::cout << "play music" << std::endl;
    }
    void stopMusic(){
        std::cout << "stop music" << std::endl;
    }
private:
    MusicPlayer* instance;
};

class Projector{
public:
    Projector* getInstance(){
        if (instance == NULL) 
			instance = new Projector;
		else 
		    return instance;
    }
    void on(){
        std::cout << "Projector On" << std::endl;
    }
    void off(){
        std::cout << "Projector Off" << std::endl;
    }
private:
    Projector* instance;
};

class DialogDirector{
public:
    virtual void showMenu() = 0;
    virtual void createWidget() = 0;
    virtual void widgetChanged(Widget*) = 0;
};

class Widget{
public:
    Widget(DialogDirector* dd) : _director(dd){};
    virtual void changed(){
        _director->widgetChanged(this);
    };

private:
    DialogDirector* _director;
};

class PlayMusicButton : public Widget{
public:
    PlayMusicButton(DialogDirector* dd, MusicPlayer* _mp) : Widget(dd), mp(_mp){};

    void setText(std::string s){ bName = s; }
    void play(){ mp->playMusic(); }
    std::string getText(){ return bName; }
private:
    std::string bName;
    MusicPlayer* mp;
};

class StopMusicButton : public Widget{
public:
    StopMusicButton(DialogDirector* dd, MusicPlayer* _mp) : Widget(dd), mp(_mp){};

    void setText(std::string s){ bName = s; }
    void play(){ mp->stopMusic(); }
    std::string getText(){ return bName; }
private:
    std::string bName;
    MusicPlayer* mp;
};

class ProjectorOnButton : public Widget{
public:
    ProjectorOnButton(DialogDirector* dd, Projector* _pj) : Widget(dd), pj(_pj){};

    void setText(std::string s){ bName = s; }
    void on(){ pj->on(); }
    std::string getText(){ return bName; }
private:
    std::string bName;
    Projector* pj;
};

class ProjectorOffButton : public Widget{
public:
    ProjectorOffButton(DialogDirector* dd, Projector* _pj) : Widget(dd), pj(_pj){};

    void setText(std::string s){ bName = s; }
    void off(){ pj->off(); }
    std::string getText(){ return bName; }
private:
    std::string bName;
    Projector* pj;
};

MusicPlayer mp;
Projector pj;

class ControlPanel : public DialogDirector{
public:
    void createWidget(){
        playMusic = new PlayMusicButton(this, mp.getInstance());
        playMusic->setText(std::string("Play"));
        stopMusic = new StopMusicButton(this, mp.getInstance());
        stopMusic->setText(std::string("Stop"));
        projectorOn = new ProjectorOnButton(this, pj.getInstance());
        projectorOn->setText(std::string("On"));
        projectorOff = new ProjectorOffButton(this, pj.getInstance());
        projectorOff->setText(std::string("Off"));
    }

    void showMenu(){
        std::cout<< playMusic->getText() << std::endl;
        std::cout<< stopMusic->getText() << std::endl;
        std::cout<< projectorOn->getText() << std::endl;
        std::cout<< projectorOff->getText() << std::endl;
    }

    void widgetChanged(Widget* w){
        if(playMusic == w){
            std::cout << "Active Stop music button" << std::endl;
        }
        else if(stopMusic == w){
            std::cout << "Active Play music button" << std::endl;
        }
        else if(projectorOn == w){
            std::cout << "Active Projector OFF button" << std::endl;
        }
        else if(projectorOff == w){
            std::cout << "Active Projector ON button" << std::endl;
        }
        else{
            std::cout << "Unknown Widget" << std::endl;
        }
    }

    void pMusic(){ 
        playMusic->play(); 
        playMusic->changed(); 
    }
    void sMusic(){ 
        stopMusic->play(); 
        stopMusic->changed();
    }
    void onProjector(){ 
        projectorOn->on(); 
        projectorOn->changed(); 
    }
    void offProjector(){ 
        projectorOff->off(); 
        projectorOff->changed(); 
    }

private:
    PlayMusicButton* playMusic;
    StopMusicButton* stopMusic;
    ProjectorOnButton* projectorOn;
    ProjectorOffButton* projectorOff;
};