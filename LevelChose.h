#pragma once
#include <SFML/Graphics.hpp> 

namespace chose{

	class LevelChose
{
	float levels_X;                   // ���������� ���� �� X
	float levels_Y;				    // ���������� ���� �� Y
	int levels_Step;                  // ���������� ����� �������� ����
	int max_levels;                   // ������������ ���������� ������� ����
	int size_font;                  // ������ ������
	int mainLevelSelected;           // ����� �������� ������ ���� 
	sf::Font font;                  // ����� ���� 
	// ������������ ������ ��������� �������� �������� ������� ����
	sf::Text* mainLevel;
	sf::Color levels_text_color = sf::Color::White;    // ���� ������� ����
	sf::Color chose_text_color = sf::Color::Yellow;  // ���� ������ ������ ����
	sf::Color border_color = sf::Color::Black;       // ���� ������� ������ ������� ����

	// ��������� ������ ������� ����
	// ���������: ������ �� ��������� ������, �����, ���������� ������
	void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);
	// ������ �� ����������� ����
	sf::RenderWindow& mywindow;
public:
	// ����������� 
	// ���������: ������ �� ����������� ����, ���������� �������� ���� �� x � y
	// ���������� ������� ����, ������ �������� ������� ����, ������ ������, ��� ����� �������� ����
	LevelChose(sf::RenderWindow& window, float menux, float menuy,
		int index, sf::String name[], int sizeFont = 60, int step = 80);

	~LevelChose()
	{
		delete[] mainLevel;
	}

	void draw();        // ������ ����

	void MoveUp();     // ����������� ������ ���� �����

	void MoveDown();   // ����������� ������ ���� ����

	// ���� ��������� �������� ����
	void setColorTextMenu(sf::Color menColor, sf::Color ChoColor,
		sf::Color BordColor);

	void AlignLevels(int posx);   // ������������ ��������� ����

	int getSelectedLevelNumber() // ���������� ����� ���������� �������� ����
	{
		return mainLevelSelected;
		}
	};

}

