#pragma once
#include <SFML/Graphics.hpp> 

namespace chose{

	class LevelChose
{
	float levels_X;                   // Координаты меню по X
	float levels_Y;				    // Координаты меню по Y
	int levels_Step;                  // Расстояние между пунктами меню
	int max_levels;                   // Максимальное количество пунктов меню
	int size_font;                  // Размер шрифта
	int mainLevelSelected;           // Номер текущего пункта меню 
	sf::Font font;                  // Шрифт меню 
	// Динамический массив текстовых объектов названий пунктов меню
	sf::Text* mainLevel;
	sf::Color levels_text_color = sf::Color::White;    // Цвет пунктов меню
	sf::Color chose_text_color = sf::Color::Yellow;  // Цвет выбора пункта меню
	sf::Color border_color = sf::Color::Black;       // Цвет обводки текста пунктов меню

	// Настройка текста пунктов меню
	// Параметры: ссылка на текстовый объект, текст, координаты текста
	void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);
	// Ссылка на графическое окно
	sf::RenderWindow& mywindow;
public:
	// Конструктор 
	// Параметры: ссылка на графическое окно, координаты игрового меню по x и y
	// количество пунктов меню, массив названий пунктов меню, размер шрифта, шаг между пунктами меню
	LevelChose(sf::RenderWindow& window, float menux, float menuy,
		int index, sf::String name[], int sizeFont = 60, int step = 80);

	~LevelChose()
	{
		delete[] mainLevel;
	}

	void draw();        // Рисуем меню

	void MoveUp();     // Перемещение выбора меню вверх

	void MoveDown();   // Перемещение выбора меню вниз

	// Цвет элементов игрового меню
	void setColorTextMenu(sf::Color menColor, sf::Color ChoColor,
		sf::Color BordColor);

	void AlignLevels(int posx);   // Выравнивание положения меню

	int getSelectedLevelNumber() // Возвращает номер выбранного элемента меню
	{
		return mainLevelSelected;
		}
	};

}

