#include "Ball.h"

int main() {

	srand(time(NULL));

	std::vector<Ball> balls;

	sf::RenderWindow window(sf::VideoMode(width, height), "KOTOK");

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
