#include "LevelChose.h"
// ����� ��������� ��������� �������� ������� �������� ����
void chose::LevelChose::setInitText(sf::Text& text, sf::String str, float xpos, float ypos)
{
	text.setFont(font);                 // �����
	text.setFillColor(levels_text_color); // ���� 
	text.setString(str);                // �����
	text.setCharacterSize(size_font);   // ������ ������
	text.setPosition(xpos, ypos);       // ���������� ���������� �������
	text.setOutlineThickness(3);        // ������� ������� ������� ������
	text.setOutlineColor(border_color); // ���� ������� ������� ������
}
// ������������ ������� ���� �� ������ �� ������� �� ������ 
void chose::LevelChose::AlignLevels(int posx)
{
	float nullx = 0;
	for (int i = 0; i < max_levels; i++) {
		switch (posx)
		{
		case 0:
			nullx = 0; // ������������ �� ������� ���� �� ������������� ���������
			break;
		case 1:
			nullx = mainLevel[i].getLocalBounds().width;  // �� ������ ����
			break;
		case 2:
			nullx = nullx = mainLevel[i].getLocalBounds().width / 2;  // �� ������
			break;
		}
		mainLevel[i].setPosition(mainLevel[i].getPosition().x - nullx, mainLevel[i].getPosition().y);
	}

}
// �����������
chose::LevelChose::LevelChose(sf::RenderWindow& window, float menux, float menuy,
	int index, sf::String name[], int sizeFont, int step)
	:mywindow(window), levels_X(menux), levels_Y(menuy), size_font(sizeFont), levels_Step(step)
{
	// �������� ������
	if (!font.loadFromFile("font/troika.otf")) exit(32);
	max_levels = index; // ���������� ��������� ���� 
	mainLevel = new sf::Text[max_levels];     // ������������ ������ ������� ����
	// ����������� �������� ����
	for (int i = 0, ypos = levels_Y; i < max_levels; i++, ypos += levels_Step) setInitText(mainLevel[i], name[i], levels_X, ypos);
	mainLevelSelected = 0; // ����� ��������� ��������� ��������� ������ ����
	// ���� ��������� ������ ����
	mainLevel[mainLevelSelected].setFillColor(chose_text_color);
}
// ����������� ������ ���� �����
void chose::LevelChose::MoveUp()
{
	mainLevelSelected--;
	// ������������ ��������� ����� ����
	if (mainLevelSelected >= 0) {
		mainLevel[mainLevelSelected].setFillColor(chose_text_color);
		mainLevel[mainLevelSelected + 1].setFillColor(levels_text_color);
	}
	else
	{
		mainLevel[0].setFillColor(levels_text_color);
		mainLevelSelected = max_levels - 1;
		mainLevel[mainLevelSelected].setFillColor(chose_text_color);
	}
}
// ����������� ������ ���� ����
void chose::LevelChose::MoveDown()
{
	mainLevelSelected++;
	// ������������ ��������� ����� ����
	if (mainLevelSelected < max_levels) {
		mainLevel[mainLevelSelected - 1].setFillColor(levels_text_color);
		mainLevel[mainLevelSelected].setFillColor(chose_text_color);
	}
	else
	{
		mainLevel[max_levels - 1].setFillColor(levels_text_color);
		mainLevelSelected = 0;
		mainLevel[mainLevelSelected].setFillColor(chose_text_color);
	}

}
// ������ �������� ���� � ����������� ����
void chose::LevelChose::draw()
{
	// ���������� ��� ��������� ������������ ��������� ������� ������� ���� 	
	for (int i = 0; i < max_levels; i++) mywindow.draw(mainLevel[i]);
}
// ���������� ����� ��������� ������� ����
void chose::LevelChose::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
	levels_text_color = menColor;   // ���� ������� ����
	chose_text_color = ChoColor; // ���� ��������� ������ ����
	border_color = BordColor;    // ���� ������� ������� ����

	for (int i = 0; i < max_levels; i++) {
		mainLevel[i].setFillColor(levels_text_color);
		mainLevel[i].setOutlineColor(border_color);
	}

	mainLevel[mainLevelSelected].setFillColor(chose_text_color);
}

