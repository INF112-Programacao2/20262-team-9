#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Teste SFML 3.1.0");
    sf::CircleShape circulo(100.f);
    circulo.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.draw(circulo);
        window.display();
    }
    return 0;
}