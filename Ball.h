#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define width 640
#define height 480

class Ball {

private:
	sf::CircleShape ball;
	sf::Color b_color;
	sf::Vector2f b_pos;
	int b_size = 0;

	float speed_x = 0.1f;
	float speed_y = 0.1f;

	int getRadius();
	sf::Vector2f getPosition();

public:
	Ball(float x, float y);

	void draw(sf::RenderWindow& win);
	void move(sf::RenderWindow& win, std::vector<Ball>& balls);
	void collision(Ball& other);
};



#endif // !BALL_H


