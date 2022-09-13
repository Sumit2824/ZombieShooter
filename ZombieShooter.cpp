#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!", Style::Fullscreen);
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    // Create texture to hold a graphic in GPU//

  


    // Set the sprite background to cover the screen//


    while (window.isOpen())
    {

        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }

        }

        window.clear();
       
        window.draw(shape);
        window.display();
    }

    return 0;
}
