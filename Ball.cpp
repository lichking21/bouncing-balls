#include "Ball.h"

Ball::Ball(float x, float y) : b_pos(x, y) { 
	
	int r = rand() % 256;
	int g = rand() % 256;
	int b = rand() % 256;
	b_color = sf::Color(r, g, b);
	
	b_size = rand() % 20 + 10;

	int r_dir = rand() % 4 + 1;
	switch (r_dir) {

	case 1:
		speed_x *= 1.f;
		speed_y *= 1.f;
		break;
	case 2:
		speed_x *= -1.f;
		speed_y *= 1.f;
		break;
	case 3:
		speed_x *= 1.f;
		speed_y *= -1.f;
		break;
	case 4:
		speed_x *= -1.f;
		speed_y *= -1.f;
		break;
	}
}

sf::Vector2f Ball::getPosition() { return b_pos; }
int Ball::getRadius() { return b_size; }

void Ball::draw(sf::RenderWindow& win) {

	ball.setRadius(b_size);
	ball.setFillColor(b_color);
	ball.setPosition(b_pos);

	ball.setPosition(b_pos.x, b_pos.y);
	win.draw(ball);
}

void Ball::move(sf::RenderWindow& win, std::vector<Ball>& balls) {

	b_pos.x += speed_x;
	b_pos.y += speed_y;

	if (b_pos.x < 0 + ball.getRadius() || win.getSize().x - ball.getRadius() < b_pos.x)
		speed_x *= -1;

	if (b_pos.y < 0 + ball.getRadius() || win.getSize().y - ball.getRadius() < b_pos.y)
		speed_y *= -1;

	for (auto& other : balls) {

		if (&other != this)
			collision(other);
	}
}

void Ball::collision(Ball& other) {

	float dx = other.getPosition().x - b_pos.x;
	float dy = other.getPosition().y - b_pos.y;
	float distance = std::sqrt(dx * dx + dy * dy);

	if (distance < b_size + other.getRadius()) {

		// Resolve collision by reflecting the velocities
		float angle = std::atan2(dy, dx);
		float totalSpeed = std::sqrt(speed_x * speed_x + speed_y * speed_y);
		speed_x = -totalSpeed * std::cos(angle);
		speed_y = -totalSpeed * std::sin(angle);

		// Adjust positions to avoid overlap
		float overlap = 0.5f * (b_size + other.getRadius() - distance);
		b_pos.x -= overlap * (dx / distance);
		b_pos.y -= overlap * (dy / distance);

		other.b_pos.x += overlap * (dx / distance);
		other.b_pos.y += overlap * (dy / distance);
	}
}