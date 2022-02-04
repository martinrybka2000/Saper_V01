#pragma once
class Square
{
	sf::RectangleShape rec;

public:

	void SetPosiotion(sf::Vector2f pos) { rec.setPosition(pos); };
	void SetPosiotion(float x, float y) { rec.setPosition(x, y); };
	void SetTexture(sf::Texture* tex) { rec.setTexture(tex, true); };
	void SetTextureColor(sf::Color color) { rec.setFillColor(color); }

	void View(sf::RenderWindow* rw) { rw->draw(rec); };

	Square(sf::Vector2f position);
	Square(sf::Vector2f position, sf::Texture* texture, sf::Color texturecolor);
	~Square();
};

