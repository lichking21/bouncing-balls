#include "Ball.h"

int main() {

	srand(time(NULL));

	std::vector<Ball> balls;

	sf::RenderWindow window(sf::VideoMode(width, height), "KOTOK");

	// ================================= Screen bounds =================================
	//std::vector<sf::RectangleShape> bounds;

	//bounds.push_back(sf::RectangleShape(sf::Vector2f(width, 1)));
	//bounds.push_back(sf::RectangleShape(sf::Vector2f(width, 1)));
	//bounds.push_back(sf::RectangleShape(sf::Vector2f(1, height)));
	//bounds.push_back(sf::RectangleShape(sf::Vector2f(1, height)));

	//bounds[0].setPosition(0, 0);
	//bounds[1].setPosition(0, height - 1);
	//bounds[2].setPosition(0, 0);
	//bounds[3].setPosition(width - 1, 0);

	//for (auto& bound : bounds)	bound.setFillColor(sf::Color::Red);
	// ================================= ============= =================================

	while (window.isOpen()) {

		sf::Event e;

		while (window.pollEvent(e)) {

			if (e.type == sf::Event::Closed)
				window.close();

			if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {

				sf::Vector2i m_pos = sf::Mouse::getPosition(window);
				balls.emplace_back((float)m_pos.x, (float)m_pos.y);
			}
		}

		for (auto& ball : balls) {

			ball.move(window, balls);
		}

		window.clear();

		for (auto& b : balls)
			b.draw(window);

		window.display();
	}

	return 0;
}