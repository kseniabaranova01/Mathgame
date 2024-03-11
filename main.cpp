#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameMenu.h"
#include "LevelChose.h"
#include <ctime>
#include <cstdlib>


using namespace sf;

// ������� ��������� ������
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60, 
    Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);



class Level2 {
public:
    Level2(sf::RenderWindow& window) : window(window) {}

    void play() {
        srand(time(NULL)); // ������������� ���������� ��������� �����

        // ������ ��������� ��������
        int num1, num2, operation;
        int score = 0; // ���������� ��� �������� ������
        int attempts = 0; // ������� �������
        int answer = 0;
        int result = 0;
        bool timeStart = true;

        // �������� ������� ������ ������
        float width = sf::VideoMode::getDesktopMode().width;
        float height = sf::VideoMode::getDesktopMode().height;

        sf::RectangleShape background(sf::Vector2f(width, height));
        // ��������� � ������������� �������� � ������������ 
        sf::Texture texture_window;
        if (!texture_window.loadFromFile("image/Levels.jpg"));
        background.setTexture(&texture_window);

        sf::Font font;
        if (!font.loadFromFile("font/troika.otf")) exit(2);
        sf::Text Titul;
        Titul.setFont(font);

        sf::Text mathText("", font, 170);
        mathText.setFillColor(sf::Color(237, 147, 0));
        mathText.setOutlineColor(sf::Color::Black);
        mathText.setOutlineThickness(3.f);
        float mathTextWidth = mathText.getLocalBounds().width;

        sf::Text inputText("", font, 170);
        inputText.setFillColor(sf::Color::White);
        inputText.setOutlineColor(sf::Color::Black);
        inputText.setOutlineThickness(3.f);

        sf::Clock clock;
        sf::Time elapsedTime;

        while (window.isOpen() && attempts < 3) {
            sf::Event event;

            elapsedTime = clock.getElapsedTime();
            if (timeStart) { // ��������� ������� ������ 10 ������
                inputText.setString("");

                operation = rand() % 2;
                if (operation == 0) {
                    num1 = 1 + rand() % 9;
                    num2 = 1 + rand() % 9;
                    result = num1 * num2;
                    mathText.setString(std::to_string(num1) + " * " + std::to_string(num2) + " = ");

                }
                else {
                    do {
                        num1 = 1 + rand() % 9;
                        num2 = 1 + rand() % 9;
                    } while (num1 % num2 != 0);
                    result = num1 / num2;
                    mathText.setString(std::to_string(num1) + " / " + std::to_string(num2) + " = ");
                }
                timeStart = false;
            }
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) { //ASCII
                        char inputChar = static_cast<char>(event.text.unicode);
                        if (isdigit(inputChar) || inputChar == '-') {
                            inputText.setString(inputText.getString() + inputChar);
                        }
                        else if (inputChar == 13) { // Enter key
                            answer = std::stoi(inputText.getString().toAnsiString());
                            if (answer == result) {
                                score++;
                            }
                            //inputText.setString("");
                        }
                    }
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Num0 || event.key.code == sf::Keyboard::Numpad0) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num4 || event.key.code == sf::Keyboard::Numpad4) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num5 || event.key.code == sf::Keyboard::Numpad5) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num6 || event.key.code == sf::Keyboard::Numpad6) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num7 || event.key.code == sf::Keyboard::Numpad7) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num8 || event.key.code == sf::Keyboard::Numpad8) {
                        inputText.setString(inputText.getString());
                    }
                    else if (event.key.code == sf::Keyboard::Num9 || event.key.code == sf::Keyboard::Numpad9) {
                        inputText.setString(inputText.getString());
                    }

                }
            }

            // ������������� ������� ������ �� ������ ������
            mathText.setPosition(width / 2 - mathText.getLocalBounds().width / 2, height / 2 - mathText.getLocalBounds().height / 2);
            inputText.setPosition(width / 2 - mathText.getLocalBounds().left + 200.f, height / 2 - mathText.getLocalBounds().height / 2);

            window.clear();
            window.draw(background);
            window.draw(Titul);
            window.draw(mathText);
            window.draw(inputText);
            window.display();

            if (elapsedTime.asSeconds() > 10) { // ��������� ������� ������ 10 ������
              
                if (!inputText.getString().isEmpty()) {
                    answer = std::stoi(inputText.getString().toAnsiString());
                    if (answer == result) {
                        score++;
                    }
                }
                clock.restart();
                timeStart = true;
                attempts++; // ����������� ������� ������� ��� ��������� ������ �������
            }
        }

        // ����� ���������� ����� ������� ���������� ������
        sf::Text scoreText("Score: " + std::to_string(score), font, 170);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setOutlineColor(sf::Color::Black);
        scoreText.setOutlineThickness(3.f);
        scoreText.setPosition(width / 2 - scoreText.getLocalBounds().width / 2, height / 2 - scoreText.getLocalBounds().height / 2);
        window.clear();
        window.draw(background);
        window.draw(Titul);
        window.draw(scoreText);
        window.display();
        sf::sleep(sf::seconds(3));
    }

    private:
        sf::RenderWindow& window;

};



void startLevel2(sf::RenderWindow& Play) {
    Level2 level2(Play);
    level2.play();
}



// ������� �������� � ����
void Gam�Start(sf::RenderWindow& Play)
{
  

    // �������� ������� ������ ������
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background_ab(Vector2f(1920, 1080));
    RectangleShape background(Vector2f(width, height));
    // ��������� � ������������� �������� � ������������ 
    Texture texture_window;
    if (!texture_window.loadFromFile("image/MainMenu.jpg"));
    background.setTexture(&texture_window);

    Font font;
    if (!font.loadFromFile("font/troika.otf")) exit(2);
    Text Titul;
    Titul.setFont(font);

    String name_levels[]{ L"������� 1", L"������� 2",L"������� 3", L"������� 4", L"������� 5", L"�����"};
    chose::LevelChose myLevel(Play, 950, 270, 6, name_levels, 80, 80);
    // ��������� ����� ��������� ������� ����
    myLevel.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // ������������ �� ������ ������� ���� 
    myLevel.AlignLevels(2);

    while (Play.isOpen())
    {
        Event event;
        while (Play.pollEvent(event))
        {
            if (event.type == Event::KeyReleased)
            {
                // ������� ����� ������� ����
                // ������ �� ���������� ������� �����
                if (event.key.code == Keyboard::Up) { myLevel.MoveUp(); }
                // ������ �� ���������� ������� ����
                if (event.key.code == Keyboard::Down) { myLevel.MoveDown(); }
                // ������ �� ���������� ������� Enter
                if (event.key.code == Keyboard::Return)
                {
                    // ��������� �� ��������� ����� ����
                    switch (myLevel.getSelectedLevelNumber())
                    {
                        case 0:Gam�Start(Play); break;
                        case 1:startLevel2(Play); break;
                        case 2:Play.close(); break;
                        case 3:Play.close(); break;
                        case 4:Play.close(); break;
                        case 5:Play.close(); break;
                    }

                }
            }
        }

        Play.clear();
        Play.draw(background);
        Play.draw(Titul);
        myLevel.draw();
        Play.display();
    }

}



// ������� � ��������� ����
void About_Game()
{
    RenderWindow About(VideoMode::getDesktopMode(), L"�� ����", Style::Fullscreen);
    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("image/MainMenu.jpg")) exit(2);
    background_ab.setTexture(&texture_ab);
    

    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) About.close();
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) About.close();
            }
        }
        About.clear();
        About.draw(background_ab);
        About.display();
    }
}




int main()
{
    
    // ������ ���� windows
    RenderWindow window;
    // ���������: ������ ���� ���������� �������� �������� ���������� ������
    // �������� ��� ����, ���������� ����������� ���� �� ���� ������ ������
    window.create(VideoMode::getDesktopMode(), L"����������", Style::Fullscreen);

    //��������� ��������� �������
    window.setMouseCursorVisible(false); 

    // �������� ������� ������ ������
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    // ������������� ��� ��� ������������ ���� 
    // ������ �������������
    RectangleShape background(Vector2f(width, height));
    // ��������� � ������������� �������� � ������������ 
    Texture texture_window;
    if (!texture_window.loadFromFile("image/MainMenu.jpg")) return 4;
    background.setTexture(&texture_window);

    // ������������� ����� ��� �������� ����
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
    Text Titul;
    Titul.setFont(font);
     // ����� � ��������� ����
    InitText(Titul, 590, 250, L"����������", 130, Color(237, 147, 0), 3);

    // �������� ������� ����
    String name_menu[]{ L"�����", L"�� ����",L"�����"};
    
    // ������ ������� ����
    game::GameMenu mymenu(window, 950, 440, 3, name_menu, 100, 100);
    // ��������� ����� ��������� ������� ����
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // ������������ �� ������ ������� ���� 
    mymenu.AlignMenu(2);
            
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased)
            {
                // ������� ����� ������� ����
                // ������ �� ���������� ������� �����
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }   
                // ������ �� ���������� ������� ����
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }  
                // ������ �� ���������� ������� Enter
                if (event.key.code == Keyboard::Return)      //ASCII                
                {
                    // ��������� �� ��������� ����� ����
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:Gam�Start(window);   break;
                    case 1:About_Game();  break;
                    case 2:window.close(); break;
                        
                    }
                    
                }
            }
        }
        
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
    }
    
    return 0;
}

// ������� ��������� ������
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font, 
    Color menu_text_color, int bord, Color border_color)
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);
}
