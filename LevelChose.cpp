#include "LevelChose.h"
// метод настройки текстовых объектов пунктов игрового меню
void chose::LevelChose::setInitText(sf::Text& text, sf::String str, float xpos, float ypos)
{
	text.setFont(font);                 // шрифт
	text.setFillColor(levels_text_color); // цвет 
	text.setString(str);                // текст
	text.setCharacterSize(size_font);   // размер шрифта
	text.setPosition(xpos, ypos);       // координаты текстового объекта
	text.setOutlineThickness(3);        // толщина контура обводки текста
	text.setOutlineColor(border_color); // цвет контура обводки текста
}
// Выравнивание пунктов меню по левому по правому по центру 
void chose::LevelChose::AlignLevels(int posx)
{
	float nullx = 0;
	for (int i = 0; i < max_levels; i++) {
		switch (posx)
		{
		case 0:
			nullx = 0; // выравнивание по правому краю от установленных координат
			break;
		case 1:
			nullx = mainLevel[i].getLocalBounds().width;  // по левому краю
			break;
		case 2:
			nullx = nullx = mainLevel[i].getLocalBounds().width / 2;  // по центру
			break;
		}
		mainLevel[i].setPosition(mainLevel[i].getPosition().x - nullx, mainLevel[i].getPosition().y);
	}

}
// Конструктор
chose::LevelChose::LevelChose(sf::RenderWindow& window, float menux, float menuy,
	int index, sf::String name[], int sizeFont, int step)
	:mywindow(window), levels_X(menux), levels_Y(menuy), size_font(sizeFont), levels_Step(step)
{
	// Загрузка шрифта
	if (!font.loadFromFile("font/troika.otf")) exit(32);
	max_levels = index; // Количество єлементов меню 
	mainLevel = new sf::Text[max_levels];     // Динамический массив пунктов меню
	// Выстраиваем элементы меню
	for (int i = 0, ypos = levels_Y; i < max_levels; i++, ypos += levels_Step) setInitText(mainLevel[i], name[i], levels_X, ypos);
	mainLevelSelected = 0; // Задаём начальное положения выбраного пункта меню
	// цвет выбраного пункта меню
	mainLevel[mainLevelSelected].setFillColor(chose_text_color);
}
// перемещение выбора меню вверх
void chose::LevelChose::MoveUp()
{
	mainLevelSelected--;
	// подсвечиваем выбранный пункт меню
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
// перемещение выбора меню вниз
void chose::LevelChose::MoveDown()
{
	mainLevelSelected++;
	// подсвечиваем выбранный пункт меню
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
// рисуем элементы меню в графическом окне
void chose::LevelChose::draw()
{
	// перебираем для отрисовки существующие текстовые объекты пунктов меню 	
	for (int i = 0; i < max_levels; i++) mywindow.draw(mainLevel[i]);
}
// назначение цвета элементам пунктов меню
void chose::LevelChose::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
	levels_text_color = menColor;   // цвет пунктов меню
	chose_text_color = ChoColor; // цвет выбраного пункта меню
	border_color = BordColor;    // цвет контура пунктов меню

	for (int i = 0; i < max_levels; i++) {
		mainLevel[i].setFillColor(levels_text_color);
		mainLevel[i].setOutlineColor(border_color);
	}

	mainLevel[mainLevelSelected].setFillColor(chose_text_color);
}

