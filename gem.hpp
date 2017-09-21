#pragma once

#include <SFML/Graphics.hpp>

class Gem
{
public:
	enum class Color : int
	{
		RED = 0, ORANGE = 1, YELLOW = 2, GREEN = 3, BLUE = 4, PURPLE = 5, WHITE = 6
	};

	enum class Status : int
	{
		NEW, NONE, SELECTED, MATCH, DELETED
	};

	Gem(int col, int row, Color color, sf::Texture& texture, Status status);
	~Gem();

	void draw(sf::RenderWindow& window, const sf::Vector2f& margin);
	bool checkHit(const sf::Vector2f& spos);
	void swapTargets(Gem& other);
	bool update();

	int getCol() const { return col; }
	int getRow() const { return row; }
	Color getColor() const { return color; }
	Status getStatus() const { return status; }
	void setStatus(Status status) 
	{
		if (this->status == Status::DELETED) return;
		this->status = status;
	}

	static const sf::Vector2f size;
	static constexpr int padding = 4;

private:
	int          col, row;
	sf::Vector2f pos;
	sf::Vector2f target;
	sf::Sprite   sprite;
	Color        color;
	Status       status;
	int          alpha;

};